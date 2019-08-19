/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/19 18:37:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	create_player(t_env *env)
{
	if (env->inputs.left_click
			&& (env->sdl.mx > 80
					&& env->sdl.mx < 120
					&& env->sdl.my > 180
					&& env->sdl.my < 220)
			&& !env->editor.new_sector)
	{
		env->editor.drag_player = 1;
		env->editor.select_player = 1;
		env->editor.new_player = 1;
	}
	if (!env->inputs.left_click && env->editor.drag_player)
	{
		env->editor.drag_player = 0;
		add_player(env);
	}
}
void	create_object(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 280
			&& env->sdl.my < 320
			&& !env->editor.new_sector && env->nb_sectors > 0)
	{
		env->editor.objects = 1;
		env->editor.drag_object = 2;
	}
	if (!env->inputs.left_click && env->editor.drag_object == 2)
	{
		env->editor.drag_object = 0;
		add_object(env);
		env->nb_objects++;
	}
}

void	drag_element(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (env->editor.select_object != -1 && env->editor.select_player == -1 && env->editor.select_vertex == -1 && env->editor.drag_object != 2)
	{	
		if (env->inputs.left_click)
		{
			env->flag = 1;
			env->editor.drag_object = 1;
			env->objects[env->editor.select_object].pos.x =	env->sdl.mx;
			env->objects[env->editor.select_object].pos.y =	env->sdl.my;
		}
		else if (env->editor.drag_object)
		{
			env->objects[env->editor.select_object].pos.x =	round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
			env->objects[env->editor.select_object].pos.y =	round((env->sdl.my - env->editor.center.y) / env->editor.scale);
			if (env->sdl.mx > 200)
				env->editor.select_object = -1;
			env->editor.drag_object = 0;
			if (env->sdl.mx > 200)
				env->flag = 0;
		}
	}
	else if (env->editor.select_player != -1 && env->editor.select_object == -1 && env->editor.select_vertex == -1)
	{
		if (env->inputs.left_click)
		{
			env->editor.drag_player = 1;
			env->player.pos.x = env->sdl.mx;
			env->player.pos.y = env->sdl.my;
		}
		else if (env->editor.drag_player)
		{	
			env->player.pos.x =	round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
			env->player.pos.y =	round((env->sdl.my - env->editor.center.y) / env->editor.scale);
			env->editor.select_player = -1;
			env->editor.drag_player = 0;
		}

	}
	else if (env->editor.select_vertex != -1 && env->editor.select_player == -1 && env->editor.select_object == -1
			&& env->editor.drag_object != 2)
	{
		if (env->inputs.left_click)
		{
			if (!env->editor.drag_object)
				env->editor.drag_vertex = 1;
			env->vertices[env->editor.select_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
			env->vertices[env->editor.select_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
		}
		else if (env->editor.drag_vertex)
		{
			env->vertices[env->editor.select_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
			env->vertices[env->editor.select_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
			while (i < env->nb_sectors)
			{
				j = 0;
				while (j < env->sectors[i].nb_vertices)
				{
					if (env->editor.select_vertex == env->sectors[i].vertices[j])
					{
						env->editor.reverted = get_clockwise_order_sector(env, i) ? 0 : 1;
						revert_sector(&env->sectors[i], env);
					}
					j++;
				}
				i++;
			}
			env->editor.select_vertex = -1;
			env->editor.drag_vertex = 0;
		}
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
				ft_printf("\n");
			}
		}
		env->inputs.space = 0;
	}
	create_player(env);
	create_object(env);
	drag_element(env);
	delete_object(env);
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
