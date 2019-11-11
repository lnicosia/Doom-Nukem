/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:29:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 11:21:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_keyup(t_env *env)
{
	int	clicked_vertex;

	if (env->editor.in_game
		&& env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->editor.select = 1;
	if (env->sdl.event.key.keysym.sym == SDLK_c)
		env->options.contouring = env->options.contouring ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_r)
		ft_printf("will reload one day\n");
	if (env->sdl.event.key.keysym.sym == SDLK_l)
		env->options.lighting = env->options.lighting ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_m)
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_f)
		env->options.show_fps = env->options.show_fps ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_x)
		env->options.wall_lover = env->options.wall_lover ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_j)
		env->options.color_clipping = env->options.color_clipping ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_g)
		env->options.wall_color = env->options.wall_color ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_t)
		env->options.test = env->options.test ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_i)
		env->options.clipping = env->options.clipping ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_n)
		env->drawing = env->drawing ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_f)
		env->player.state.fly = env->player.state.fly ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->editor.tab = env->editor.tab ? 0 : 1;
	if (env->editor.in_game && env->sdl.event.key.keysym.sym == SDLK_z)
		env->options.zbuffer = env->options.zbuffer ? 0 : 1;
	if (env->editor.in_game && env->sdl.event.key.keysym.sym == SDLK_g)
		env->editor.game = env->editor.game ? 0 : 1;
	if (env->confirmation_box.state)
		confirmation_box_keyup(&env->confirmation_box, env);
	if (env->sdl.mx > 200 && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& !env->confirmation_box.state
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_enemy == -1)
	{
		env->editor.selected_sector = get_sector_no_z(env,
				new_v3((env->sdl.mx - env->editor.center.x) / env->editor.scale,
					(env->sdl.my - env->editor.center.y) / env->editor.scale,
					0));
		env->editor.selected_vertex = -1;
		env->editor.selected_object = -1;
		env->editor.selected_player = -1;
		env->selected_enemy = -1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !env->editor.in_game)
	{
		clicked_vertex = get_existing_vertex(env);
		if (clicked_vertex == -1 && is_new_vertex_valid(env, clicked_vertex))
		{
			if (add_vertex(env))
				return (ft_printf("Could not add new vertex\n"));
			add_vertex_to_current_sector(env, env->nb_vertices - 1);
			if (env->editor.start_vertex == -1) //Nouveau secteur
			{
				env->editor.start_vertex = env->nb_vertices - 1;
			}
		}
		else if (clicked_vertex >= 0)
		{
			if (env->editor.start_vertex == -1)
			{
				env->editor.start_vertex = clicked_vertex;
				add_vertex_to_current_sector(env, clicked_vertex);
			}
			else
			{
				if (clicked_vertex == ((t_vertex*)env->editor.current_vertices->content)->num
						&& ft_lstlen(env->editor.current_vertices) > 2
						&& is_new_vertex_valid(env, clicked_vertex))
				{
					env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
					env->editor.start_vertex = -1;
					if (add_sector(env))
						return (ft_printf("Error while creating new sector\n"));
					free_current_vertices(env);
					get_new_floor_and_ceiling(env);
					update_sector_slope(env, &env->sectors[env->nb_sectors - 1]);
				}
				else if (is_new_vertex_valid(env, clicked_vertex))
					add_vertex_to_current_sector(env, clicked_vertex);
			}
		}
		env->inputs.space = 0;
	}
	return (0);
}
