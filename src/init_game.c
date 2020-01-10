/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/10 16:41:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include "wall_sprite_modifier.h"

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

int	hola(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("Hola\n");
	return (1);
}

int	cc(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("cc\n");
	return (1);
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
	env.nb_explosions = 0;
	view(&env);
	update_camera_position(&env.player.camera);
	SDL_SetRelativeMouseMode(1);
	init_animations(&env);
	init_weapons(&env);
	ft_printf("Starting music..\n");
	Mix_PlayMusic(env.sound.background, -1);
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
	env.player.highest_sect = find_highest_sector(&env, new_movement(env.player.sector, env.player.size_2d, env.player.eyesight, env.player.pos));
	if (ft_strequ(av[1], "maps/events.map"))
	{
		env.nb_global_events = 5;
		env.global_events =
		(t_event*)ft_memalloc(sizeof(t_event) * env.nb_global_events);

		env.global_events[0] =
		new_fixed_event(INT, &env.sectors[2].intensity, 50, 0);
		env.global_events[0].delay = 1000;

		env.global_events[1] =
		new_fixed_event(UINT32, &env.sectors[2].light_color, 0xFFFF0000, 0);
		env.global_events[1].delay = 1000;
		env.global_events[1].launch_func =
		&launch_prec_event_ended_starter;
		env.global_events[1].launch_param.target =
		&env.global_events[4];

		env.global_events[2] =
		new_fixed_event(UINT32, &env.sectors[2].light_color, 0xFF0000FF, 0);
		env.global_events[2].delay = 1000;
		env.global_events[2].launch_func =
		&launch_prec_event_ended;
		env.global_events[2].launch_param.target =
		&env.global_events[1];

		env.global_events[3] =
		new_fixed_event(UINT32, &env.sectors[2].light_color, 0xFF00FF00, 0);
		env.global_events[3].delay = 1000;
		env.global_events[3].launch_func =
		&launch_prec_event_ended;
		env.global_events[3].launch_param.target =
		&env.global_events[2];

		env.global_events[4] =
		new_fixed_event(UINT32, &env.sectors[2].light_color, 0xFFFFFF00, 0);
		env.global_events[4].delay = 1000;
		env.global_events[4].launch_func =
		&launch_prec_event_ended;
		env.global_events[4].launch_param.target =
		&env.global_events[3];

		env.sectors[1].nb_walk_events = 2;
		env.sectors[1].walk_on_me_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env.sectors[1].nb_walk_events);

		env.sectors[1].walk_on_me_event[0] = new_fixed_event(DOUBLE,
		&env.sectors[1].floor, 10, 500);
		env.sectors[1].walk_on_me_event[0].update_func = &update_sector_event;
		env.sectors[1].walk_on_me_event[0].update_param.num = 1;

		env.sectors[1].walk_on_me_event[1] = new_fixed_event(DOUBLE,
		&env.sectors[1].floor, 0, 500);
		env.sectors[1].walk_on_me_event[1].update_func = &update_sector_event;
		env.sectors[1].walk_on_me_event[1].update_param.num = 1;

		env.sectors[4].nb_stand_events = 1;
		env.sectors[4].stand_on_me_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env.sectors[4].nb_stand_events);
		env.sectors[4].stand_on_me_event[0] = new_fixed_event(DOUBLE,
		&env.sectors[4].floor, 10.0, 500);
		env.sectors[4].stand_on_me_event[0].check_func = &check_equ_value_event;
		env.sectors[4].stand_on_me_event[0].check_param.target = &env.player.sector;
		env.sectors[4].stand_on_me_event[0].check_param.target_type = INT;
		env.sectors[4].stand_on_me_event[0].check_param.equ_value = 4;

		env.sectors[4].stand_on_me_event[0].update_func = &update_sector_event;
		env.sectors[4].stand_on_me_event[0].update_param.num = 4;

		env.sectors[4].nb_walk_out_events = 1;
		env.sectors[4].walk_out_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env.sectors[4].nb_walk_out_events);
		env.sectors[4].walk_out_event[0] = new_fixed_event(DOUBLE,
		&env.sectors[4].floor, 10.45, 500);
		env.sectors[4].walk_out_event[0].update_func = &update_sector_event;
		env.sectors[4].walk_out_event[0].update_param.num = 4;
	}
	t_wall_sprite_modifier	*p2;
	t_wall_sprite_modifier	*p;
	if (ft_strequ(av[1], "maps/piece.map"))
	{
		env.sectors[0].wall_sprites[1].nb_press_events[0] = 3;
		env.sectors[0].wall_sprites[1].press_events[0] = 
		(t_event*)ft_memalloc(sizeof(t_event)
		* env.sectors[0].wall_sprites[1].nb_press_events[0]);
		env.sectors[0].wall_sprites[1].press_events[0][0] =
		new_func_event(&hola, NULL);
		env.sectors[0].wall_sprites[1].press_events[0][0].max_uses = 10;
		env.sectors[0].wall_sprites[1].press_events[0][1] =
		new_func_event(&cc, NULL);
		env.sectors[0].wall_sprites[1].press_events[0][1].max_uses = 2;
		env.sectors[0].wall_sprites[1].press_events[0][2] =
		new_fixed_event(INT, env.sectors[0].wall_sprites[1].sprite, 1, 0);
		env.sectors[0].wall_sprites[1].press_events[0][2].launch_func =
		&launch_equ_value_event;
		env.sectors[0].wall_sprites[1]
		.press_events[0][2].launch_param.equ_value = 1;
		env.sectors[0].wall_sprites[1]
		.press_events[0][2].launch_param.target
		= &env.sectors[0].wall_sprites[1].nb_press_events[0];
		env.sectors[0].wall_sprites[1].press_events[0][2].max_uses = 1;

		env.sectors[0].wall_sprites[1].nb_press_events[1] = 4;
		env.sectors[0].wall_sprites[1].press_events[1] = 
		(t_event*)ft_memalloc(sizeof(t_event)
		* env.sectors[0].wall_sprites[1].nb_press_events[1]);

		env.sectors[0].wall_sprites[1].press_events[1][0] =
		new_fixed_event(INT, &env.sectors[0].brightness, 64, 0);
		env.sectors[0].wall_sprites[1].press_events[1][0].launch_func =
		&launch_equ_value_event;
		env.sectors[0].wall_sprites[1].
		press_events[1][0].launch_param.equ_value = -64;
		env.sectors[0].wall_sprites[1].
		press_events[1][0].launch_param.target = &env.sectors[0].brightness;

		env.sectors[0].wall_sprites[1].press_events[1][1] =
		new_fixed_event(INT, &env.sectors[0].brightness, -64, 0);
		env.sectors[0].wall_sprites[1].press_events[1][1].launch_func =
		&launch_equ_value_event;
		env.sectors[0].wall_sprites[1].
		press_events[1][1].launch_param.equ_value = 64;
		env.sectors[0].wall_sprites[1].
		press_events[1][1].launch_param.target = &env.sectors[0].brightness;


		p = (t_wall_sprite_modifier*)ft_memalloc(sizeof(*p));
		p->sector = 0;
		p->type = SPRITE;
		p->wall = 1;
		p->sprite = 1;
		p->value = 2;
		env.sectors[0].wall_sprites[1].press_events[1][2] =
		new_func_event(&modify_wall_sprite, p);
		env.sectors[0].wall_sprites[1].press_events[1][2].launch_func =
		&launch_equ_value_event;
		env.sectors[0].wall_sprites[1].
		press_events[1][2].launch_param.equ_value = -64;
		env.sectors[0].wall_sprites[1].
		press_events[1][2].launch_param.target = &env.sectors[0].brightness;
		env.sectors[0].wall_sprites[1].
		press_events[1][2].launch_param.target_type = INT;


		p2 = (t_wall_sprite_modifier*)ft_memalloc(sizeof(*p));
		p2->sector = 0;
		p2->type = SPRITE;
		p2->wall = 1;
		p2->sprite = 1;
		p2->value = 1;
		env.sectors[0].wall_sprites[1].press_events[1][3] =
		new_func_event(&modify_wall_sprite, p2);
		env.sectors[0].wall_sprites[1].press_events[1][3].launch_func =
		&launch_equ_value_event;
		env.sectors[0].wall_sprites[1].
		press_events[1][3].launch_param.equ_value = 64;
		env.sectors[0].wall_sprites[1].
		press_events[1][3].launch_param.target = &env.sectors[0].brightness;
		env.sectors[0].wall_sprites[1].
		press_events[1][3].launch_param.target_type = INT;

		env.nb_global_events = 1;
		env.global_events =
		(t_event*)ft_memalloc(sizeof(t_event) * env.nb_global_events);
		env.global_events[0] =
		new_fixed_event(INT, &env.enemies[0].sprite,
		7, 0);
		env.global_events[0].max_uses = 1;
		env.global_events[0].delay = 1000;
		//env.global_events[0].check_func = &check_equ_value_event;
		//env.global_events[0].check_param = new_event_param(0, 0, 0,
				//new_v3(0, 0, 0));
	}
	return (doom(&env));
}
