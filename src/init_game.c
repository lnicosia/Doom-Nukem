/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 14:58:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include "wall_sprite_modifier.h"
#include "events_conditions.h"

void	save_init_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].enemies_init_data.pos = env->enemies[i].pos;
		env->enemies[i].enemies_init_data.health = env->enemies[i].health;
		env->enemies[i].enemies_init_data.sector = env->enemies[i].sector;
		env->enemies[i].enemies_init_data.angle = env->enemies[i].angle;
		env->enemies[i].enemies_init_data.main_sprite = env->enemies[i].main_sprite;
		i++;
	}
	env->player.player_init_data.pos = env->player.pos;
	env->player.player_init_data.health = env->player.health;
	env->player.player_init_data.sector = env->player.sector;
	env->player.player_init_data.camera = env->player.camera;
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].object_init_data.main_sprite = env->objects[i].main_sprite;
		env->objects[i].object_init_data.pos = env->objects[i].pos;
		env->objects[i].object_init_data.sector = env->objects[i].sector;
		env->objects[i].object_init_data.angle = env->objects[i].angle;
		i++;
	}
}

void	set_enemies_hp(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].exists)
			env->enemies[i].health = env->enemies[i].map_hp *
				env->difficulty;
		i++;
	}
}

int		init_game(int ac, char **av)
{
	t_env	env;
	int		i;

	i = 0;
	if (ac < 2)
		return (ft_printf("No map file.\n"));
	ft_bzero(&env, sizeof(t_env));
	env.difficulty = 1;
	if (ac == 3)
	{
		env.menu = 1;
		env.in_game = 0;
	}
	else if (ac == 2)
		env.in_game = 1;
	env.option = 0;
	env.menu_select = 1;
	env.running = 1;
	env.editor.player_exist = 1;
	env.playing = 1;
	init_player(&env);
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	init_selection_data(&env);
	if (!(env.snprintf = ft_strnew(SNPRINTF_SIZE)))
		return (crash("Could not malloc snprintf char *\n", &env));
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (init_object_sprites(&env))
		return (crash("Could not load object sprites\n", &env));
	if (init_enemy_sprites(&env))
		return (crash("Could not load enemy sprites\n", &env));
	if (generate_mipmaps(&env))
		return (crash("Could not generate mipmaps\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parse_map(av[1], &env))
		return (crash("{red}Error while parsing the map{reset}\n", &env));
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (!(env.sector_list = (int *)ft_memalloc(sizeof(int) * env.nb_sectors)))
		return (crash("Could not allocate sector list\n", &env));
	while (i < env.nb_objects)
	{
		env.objects[i].exists = 1;
		i++;
	}
	i = 0;
	while (i < env.nb_enemies)
	{
		env.enemies[i].exists = 1;
		i++;
	}
	set_enemies_hp(&env);
	view(&env);
	update_camera_position(&env.player.camera);
	SDL_SetRelativeMouseMode(1);
	init_animations(&env);
	init_weapons(&env);
	ft_printf("Starting music..\n");
	play_music(&env, &env.sound.music_chan, env.sound.musics[0].music, env.sound.music_vol);
	ft_printf("Launching game loop..\n");
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init fixed camera\n", &env));
	if (init_camera(&env.fixed_camera, &env))
		return (crash("Could not init fixed camera\n", &env));
	if (init_skybox(&env))
		return (crash("Could not init skybox\n", &env));
	env.fixed_camera.pos = new_v3(3, 3, 7);
	env.fixed_camera.angle = 45 * CONVERT_RADIANS;
	env.fixed_camera.angle_cos = cos(env.fixed_camera.angle);
	env.fixed_camera.angle_sin = sin(env.fixed_camera.angle);
	env.fixed_camera.angle_z = 10 * CONVERT_RADIANS;
	env.fixed_camera.angle_z_cos = cos(env.fixed_camera.angle_z);
	env.fixed_camera.angle_z_sin = sin(env.fixed_camera.angle_z);
	update_camera_position(&env.fixed_camera);
	save_init_data(&env);
	env.confirmation_box.font = env.sdl.fonts.lato20;
	env.player.highest_sect = find_highest_sector(&env, new_movement(env.player.sector, env.player.size_2d,
		env.player.eyesight, env.player.pos));
	start_game_button(&env);
	next_difficulty_button(&env);
	prev_difficulty_button(&env);
	option_menu_button(&env);
	return_button(&env);
	exit_button(&env);
	music_vol_down_button(&env);
	music_vol_up_button(&env);
	sounds_vol_up_button(&env);
	sounds_vol_down_button(&env);
	if (ft_strequ(av[1], "maps/events.map"))
	{
		ft_printf("{green}Custom events{reset}\n");
		env.sectors[18].walk_in_events = (t_event*)ft_memalloc(sizeof(t_event));
		env.sectors[18].nb_walk_in_events = 1;
		env.sectors[18].walk_in_events[0] = new_func_event(&win, NULL);
	}
	return (doom(&env));
}
