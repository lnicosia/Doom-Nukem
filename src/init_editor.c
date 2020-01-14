/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/14 17:49:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Interaction test function
*/

int	hola(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("Hola\n");
	return (1);
}

int	hit_player(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("Aie\n");
	return (1);
}

int	init_editor(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env.running = 1;
	env.drawing = 1;
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_editor_data(&env);
	init_inputs(&env);
	init_player(&env);
	init_animations(&env);
	if (init_sdl(&env))
		return (crash("Could not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	if (init_input_box(&env.input_box, &env))
		return (crash("Could not init input box\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (generate_mipmaps(&env))
		return (crash("Could not generate mipmaps\n", &env));
	if (init_wall_sprites(&env))
		return (crash("Could not load wall sprites\n", &env));
	if (init_object_sprites(&env))
		return (crash("Could not load object sprites\n", &env));
	if (init_enemy_sprites(&env))
		return (crash("Could not load enemy sprites\n", &env));
	if (!(init_editor_hud(&env)))
		return (crash("Could not init hud\n", &env));
	if (ac == 1)
	{
		ft_printf("Creating a new map\n");
		env.save_file = ft_strdup("maps/test.map");
	}
	else if (ac == 2)
	{
		ft_printf("Opening \"%s\"\n", av[1]);
		if (parse_map(av[1], &env))
			return (crash("Error while parsing the map\n", &env));
		env.save_file = ft_strdup(av[1]);
		precompute_slopes(&env);
		ft_printf("{reset}");
		if (ft_strequ(av[1], "maps/triple_piece.map"))
		{
			env.sectors[1].nb_stand_events = 3;
			env.sectors[1].stand_event = (t_event*)ft_memalloc(sizeof(t_event) * env.sectors[1].nb_stand_events);
			env.sectors[1].stand_event[0] =
			new_func_event(&hola, 0);
			env.sectors[1].stand_event[1] =
			new_func_event(&hit_player, 0);
			env.sectors[1].stand_event[1].max_uses = 1;
			env.sectors[1].stand_event[2] =
			new_func_event(&hola, 0);
			//env.sectors[1].stand_event[1].update_param->num = 1;
			//env.sectors[1].stand_event[1].max_uses = 0;
			/*env.sectors[1].stand_event[0] =
			new_fixed_event(DOUBLE, &env.sectors[2].floor, 8.5, 800);
			env.sectors[1].stand_event[0].update_func = &update_sector_event;
			env.sectors[1].stand_event[0].update_param = new_event_param(
			2, 0, 0, new_v3(0, 0, 0)); 
			env.sectors[1].stand_event[1] =
			new_fixed_event(INT, &env.player.health, 1, 0);*/
			//new_event(DOUBLE, &env.player.pos.y, 50, 1000);
			//env.sectors[1].stand_event[1].check_func = &check_collision_event;
			//env.sectors[1].stand_event[1].check_param = new_event_param(
			//0, new_v3(0, env.sectors[1].stand_event[1].incr, 0)); 
			//env.sectors[1].stand_event[1].update_func = &update_player_event;
			/*if (env.sectors[2].brightness < 0)
				env.sectors[2].light_color = blend_alpha(0, 0xFFFF9329, (255 + env.sectors[2].brightness + 16) / 2);*/
			//env.sectors[2].light_color = blend_alpha(0, 0xFFFFFFFF, 16);
		}
	}
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init camera\n", &env));
	if (init_skybox(&env))
		return (crash("Could not init skybox\n", &env));
	env.confirmation_box.font = env.sdl.fonts.lato20;
	env.player.health = 100;
	env.editor.center.x = -env.player.pos.x * env.editor.scale + env.h_w;
	env.editor.center.y = -env.player.pos.y * env.editor.scale + env.h_h;
	return (editor(&env));
}
