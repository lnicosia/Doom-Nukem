/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/25 13:58:31 by sipatry          ###   ########.fr       */
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
	env.menu_select = 1;
	env.running = 1;
	env.editor.new_player = 1;
	env.playing = 1;
	init_player(&env);
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
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parse_map(av[1], &env))
		return (crash("Error while parsing the map\n", &env));
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init camera\n", &env));
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (init_sprites(&env))
		return (crash("Could not load sprites\n", &env));
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
	env.flag = 0;
	env.player.stuck = 0;
	ft_printf("Starting music..\n");
	Mix_PlayMusic(env.sound.background, -1);
	ft_printf("Launching game loop..\n");
	if (init_camera(&env.fixed_camera, &env))
		return (crash("Could not init fixed camera\n", &env));
	env.fixed_camera.pos = new_v3(3, 3, 7);
	env.fixed_camera.angle = 45 * CONVERT_RADIANS;
	env.fixed_camera.angle_cos = cos(env.fixed_camera.angle);
	env.fixed_camera.angle_sin = sin(env.fixed_camera.angle);
	env.fixed_camera.angle_z = 10 * CONVERT_RADIANS;
	env.fixed_camera.angle_z_cos = cos(env.fixed_camera.angle_z);
	env.fixed_camera.angle_z_sin = sin(env.fixed_camera.angle_z);
	update_camera_position(&env.fixed_camera);
	save_init_data(&env);
	env.confirmation_box.font = env.sdl.fonts.alice30;
	env.confirmation_box.state = 0;
	env.player.highest_sect = find_highest_sector(&env, new_movement(env.player.sector, env.player.size_2d, env.player.eyesight, env.player.pos));
	return (doom(&env));
}
