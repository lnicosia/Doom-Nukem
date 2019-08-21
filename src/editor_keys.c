/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/21 12:35:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	handle_player(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 180
			&& env->sdl.my < 220
			&& !env->editor.new_sector
			&& env->editor.selected_player == -1
			&& env->editor.selected_vertex == -1
			&& env->editor.selected_object == -1)
		env->editor.selected_player = 1;
	if (!env->inputs.left_click && env->editor.selected_player == 1)
	{
		env->editor.selected_player = -1;
		if (env->sdl.mx > 200)
		{
			add_player(env);
			env->editor.new_player = 1;
		}
		else
			env->editor.new_player = 0;
	}
}
void	handle_objects(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 280
			&& env->sdl.my < 320
			&& !env->editor.new_sector
			&& env->editor.selected_player == -1
			&& env->editor.selected_vertex == -1
			&& env->editor.selected_object == -1)
	{
		env->editor.selected_object = env->nb_objects;
	}
	if (!env->inputs.left_click && env->editor.selected_object != -1)
	{
		if (env->sdl.mx > 200)
		{
			if (env->editor.selected_object == env->nb_objects)
			{
				add_object(env);
				env->nb_objects++;
			}
			else
			{
				env->objects[env->editor.selected_object].pos.x =	(env->sdl.mx - env->editor.center.x) / env->editor.scale;
				env->objects[env->editor.selected_object].pos.y =	(env->sdl.my - env->editor.center.y) / env->editor.scale;
			}
		}
		else
			delete_object(env);
		env->editor.selected_object = -1;
	}
}

void	check_sector_order(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->editor.selected_vertex == env->sectors[i].vertices[j])
			{
				env->editor.reverted = get_clockwise_order_sector(env, i) ? 0 : 1;
				revert_sector(&env->sectors[i], env);
			}
			j++;
		}
		i++;
	}
}

void		handle_vertices(t_env *env)
{
	if (!env->inputs.left_click && env->editor.selected_vertex != -1)
	{
		env->vertices[env->editor.selected_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
		env->vertices[env->editor.selected_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
		check_sector_order(env);
		env->editor.selected_vertex = -1;
	}
}

int			editor_keys(t_env *env)
{
	int		clicked_vertex;

	if (env->inputs.space)
	{
		clicked_vertex = get_existing_vertex(env);
		if (clicked_vertex == -1)
		{
			if (add_vertex(env))
				return (ft_printf("Could not add new vertex\n"));
			if (!env->editor.new_sector) //Nouveau secteur
				env->editor.new_sector = 1;
			add_vertex_to_current_sector(env, env->nb_vertices - 1);
		}
		else
		{
			if (!env->editor.new_sector)
			{
				env->editor.new_sector = 1;
				add_vertex_to_current_sector(env, clicked_vertex);
			}
			else
			{
				if (clicked_vertex == ((t_vertex*)env->editor.current_vertices->content)->num)
				{
					env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
					env->editor.new_sector = 0;
					if (add_sector(env))
						return (ft_printf("Error while creating new sector\n"));
					free_current_vertices(env);
				}
				else
					add_vertex_to_current_sector(env, clicked_vertex);
			}
		}
		env->inputs.space = 0;
	}
	handle_player(env);
	handle_objects(env);
	handle_vertices(env);
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
