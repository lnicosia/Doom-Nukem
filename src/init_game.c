/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/29 12:44:11 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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

int		init_game(int ac, char **av)
{
	t_env	env;
	int		i;

	i = 0;
	if (ac != 2)
		return (ft_printf("No map file.\n"));
	ft_bzero(&env, sizeof(t_env));
	env.min_fps = 300;
	env.min_fps2 = 300;
	env.menu_select = 1;
	env.running = 1;
	env.editor.player_exist = 1;
	env.playing = 1;
	env.first_frame = 0; //flag value = 1 once the first frame is shown
	init_player(&env);
	init_editor_data(&env);
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (init_wall_sprites(&env))
		return (crash("Could not load wall sprites\n", &env));
	if (init_object_sprites(&env))
		return (crash("Could not load object sprites\n", &env));
	if (init_enemy_sprites(&env))
		return (crash("Could not load enemy sprites\n", &env));
	if (generate_mipmaps(&env))
		return (crash("Could not generate mipmaps\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parse_map(av[1], &env))
		return (crash("Error while parsing the map\n", &env));
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init camera\n", &env));
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (!(env.sector_list = (int *)malloc(sizeof(int) * env.nb_sectors)))
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
	view(&env);
	update_camera_position(&env.player.camera);
	SDL_SetRelativeMouseMode(1);
	init_animations(&env);
	init_weapons(&env);
	ft_printf("Starting music..\n");
	Mix_PlayMusic(env.sound.background, -1);
	ft_printf("Launching game loop..\n");
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
	env.player.highest_sect = find_highest_sector(&env, new_movement(env.player.sector, env.player.size_2d, env.player.eyesight, env.player.pos));
		if (ft_strequ(av[1], "maps/triple_piece.map"))
		{
			env.sectors[1].nb_walk_events = 2;
			env.sectors[1].walk_on_me_event = (t_event*)malloc(sizeof(t_event) * env.sectors[1].nb_walk_events);
			env.sectors[1].walk_on_me_event[0] =
			new_fixed_event(DOUBLE, &env.sectors[2].floor, 8.5, 800);
			env.sectors[1].walk_on_me_event[0].update_func = &update_sector_event;
			env.sectors[1].walk_on_me_event[0].update_param = new_event_param(
			2, 0, 0, new_v3(0, 0, 0)); 
			env.sectors[1].walk_on_me_event[1] =
			new_fixed_event(INT, &env.player.health, 50, 1000);
			//new_event(DOUBLE, &env.player.pos.y, 50, 1000);
			//env.sectors[1].walk_on_me_event[1].check_func = &check_collision_event;
			//env.sectors[1].walk_on_me_event[1].check_param = new_event_param(
			//0, new_v3(0, env.sectors[1].walk_on_me_event[1].incr, 0)); 
			//env.sectors[1].walk_on_me_event[1].update_func = &update_player_event;
			/*env.sectors[1].walk_on_me_event[2] =
			new_incr_event(INT, &env.sectors[2].brightness, -50, 0);
			env.sectors[1].walk_on_me_event[2].delay = 1000;*/

			env.nb_global_events = 1;
			env.global_events = (t_event*)malloc(sizeof(t_event)
			* env.nb_global_events);
			env.global_events[0] =
			new_fixed_event(INT, &env.sectors[2].brightness, -128, 0);
			env.global_events[0].delay = 1000;
			env.global_events[0].check_func = &check_equ_value_event;
			env.global_events[0].check_param = new_event_param(0, 0, 0,
			new_v3(0, 0, 0));
			/*env.global_events[1] =
			new_fixed_event(INT, &env.sectors[2].brightness, 0, 0);
			env.global_events[1].delay = 2000;
			env.global_events[1].check_func = &check_equ_value_event;
			env.global_events[1].check_param = new_event_param(0, -128, 0,
			new_v3(0, 0, 0));*/
		}
	return (doom(&env));
}
