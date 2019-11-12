/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/11 18:00:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_editor_data(t_env *env)
{
	env->editor.in_game = 0;
	env->editor.center.x = env->h_w;
	env->editor.center.y = env->h_h;
	env->editor.scale = 20;
	env->editor.current_vertices = NULL;
	env->editor.start_vertex = -1;
	env->editor.reverted = 0;
	env->editor.new_player = 0;
	env->nb_vertices = 0;
	env->nb_sectors = 0;
	env->nb_objects = 0;
	env->player.sector = -1;
	env->editor.select = 0;

	env->editor.start_pos.x = 0;
	env->editor.start_pos.y = 0;
	env->editor.selected_sector = -1;
	env->editor.selected_object = -1;
	env->editor.selected_vertex = -1;
	env->editor.selected_player = -1;
	env->editor.selected_wall = -1;
	env->editor.selected_wall_sprite = -1;
	env->editor.dragged_object = -1;
	env->editor.dragged_vertex = -1;
	env->editor.dragged_player = -1;
	env->editor.dragged_enemy = -1;
	env->editor.tab = 0;
	env->selected_wall1 = -1;
	env->selected_wall2 = -1;
	env->selected_floor = -1;
	env->selected_ceiling = -1;
	env->selected_wall_sprite_sprite = -1;
	env->selected_wall_sprite_wall = -1;
	env->selected_enemy = -1;
	env->selected_object = -1;
	env->selected_stat = 0;
	env->time.scroll_tick = 0;
	env->time.tick = 0;
	env->time.tick2 = 0;
	env->time.tick3 = 0;
	
	env->save_file = ft_strdup("maps/test.map");
}

/*
**	Interaction test function
*/

void	move_sector(void *param)
{
	(void)param;
	ft_printf("Hola\n");
}

void	hit_player(void *param)
{
	(void)param;
	ft_printf("Aie\n");
}

int	init_editor(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env.running = 1;
	env.drawing = 1;
	env.min_fps = 300;
	env.avrg_fps = 0;
	env.max_fps = 0;
	env.min_fps2 = 300;
	env.avrg_fps2 = 0;
	env.max_fps2 = 0;
	env.playing = 0;
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
	if (init_sprites(&env))
		return (crash("Could not load sprites\n", &env));
	if (ac == 1)
		ft_printf("Creating a new map\n");
	else if (ac == 2)
	{
		ft_printf("Opening \"%s\"\n", av[1]);
		if (parse_map(av[1], &env))
			return (crash("Error while parsing the map\n", &env));
		precompute_slopes(&env);
		ft_printf("{reset}");
		if (ft_strequ(av[1], "maps/triple_piece.map"))
		{
			env.sectors[1].nb_walk_events = 2;
			env.sectors[1].walk_on_me_event = (t_event*)malloc(sizeof(t_event) * env.sectors[1].nb_walk_events);
			env.sectors[1].walk_on_me_event[0] =
			new_event(DOUBLE, &env.sectors[2].floor, 8.5, 10000);
			env.sectors[1].walk_on_me_event[1] =
			new_event(INT, &env.player.health, 50, 1000);
		}
	}
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init camera\n", &env));
	env.confirmation_box.font = env.sdl.fonts.lato20;
	env.player.health = 100;
	return (editor(&env));
}
