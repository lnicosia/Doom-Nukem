/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/26 12:08:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			editor_keys(t_env *env)
{
	int		clicked_vertex;

	if (env->inputs.space
			&& env->editor.selected_player == -1
			&& env->editor.selected_object == -1
			&& env->editor.selected_vertex == -1)
	{
		clicked_vertex = get_existing_vertex(env);
		if (clicked_vertex == -1 && is_new_vertex_valid(env, clicked_vertex))
		{
			if (add_vertex(env))
				return (ft_printf("Could not add new vertex\n"));
			add_vertex_to_current_sector(env, env->nb_vertices - 1);
			if (env->editor.start_vertex == -1) //Nouveau secteur
				env->editor.start_vertex = env->nb_vertices - 1;
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
				}
				else if (is_new_vertex_valid(env, clicked_vertex))
					add_vertex_to_current_sector(env, clicked_vertex);
			}
		}
		env->inputs.space = 0;
	}
	if (env->inputs.backspace)
	{
		del_last_vertex(env);
		env->inputs.backspace = 0;
	}
	player_selection(env);
	objects_selection(env);
	vertices_selection(env);
	if (env->inputs.left_click
			&& env->editor.start_vertex == -1
			&& env->editor.selected_player == -1
			&& env->editor.selected_object == -1
			&& env->editor.selected_vertex == -1)
	{
		env->editor.selected_sector = get_sector_no_z(env,
				new_v3((env->sdl.mx - env->editor.center.x) / env->editor.scale,
					(env->sdl.my - env->editor.center.y) / env->editor.scale,
					0));
	}
	if (env->inputs.right_click)
	{
		env->editor.center.x += env->sdl.mouse_x;
		env->editor.center.y += env->sdl.mouse_y;
	}
	if (env->inputs.enter)
	{
		if (!valid_map(env))
		{
			env->editor.in_game = 1;
			env->inputs.enter = 0;
			free_screen_sectors(env);
			if (init_screen_pos(env))
				return (ft_printf("Could not init screen pos\n"));
			if (env->sector_list)
				ft_memdel((void**)&env->sector_list);
			if (!(env->sector_list = (int*)malloc(sizeof(int) * env->nb_sectors)))
				return (ft_printf("Could not allocate sector list\n", env));
			update_camera_position(env);
			update_player_z(env);
			update_floor(env);
			env->sdl.mx = env->w / 2;
			env->sdl.my = env->h / 2;
			SDL_SetRelativeMouseMode(1);
		}
		env->inputs.enter = 0;
	}
	if (env->inputs.s && env->inputs.ctrl && !valid_map(env))
	{
		if (save_map("maps/test.map", env))
			return (ft_printf("Could not save the map\n"));
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
	}
	return (0);
}
