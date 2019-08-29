/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:52:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/27 13:54:09 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_vertices(t_env *env)
{
	int			i;
	t_vertex	vertex;
	t_point		center;
	double		scale;
	Uint32		color;

	i = 0;
	if (env->editor.selected_vertex != -1)
	{
		color = 0xFF00FF00;
		scale = env->editor.scale / 5.0;
		env->vertices[env->editor.selected_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
		env->vertices[env->editor.selected_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
		center.x = env->vertices[env->editor.selected_vertex].x * env->editor.scale + env->editor.center.x;
		center.y = env->vertices[env->editor.selected_vertex].y * env->editor.scale + env->editor.center.y;
	}
	while (i < env->nb_vertices)
	{
		vertex = env->vertices[i];
		center = new_point(env->editor.center.x + vertex.x * env->editor.scale,
				env->editor.center.y + vertex.y * env->editor.scale);
		if (env->sdl.mx > center.x - env->editor.scale / 3.0
				&& env->sdl.mx < center.x + env->editor.scale / 3.0
				&& env->sdl.my > center.y - env->editor.scale / 3.0
				&& env->sdl.my < center.y + env->editor.scale / 3.0)
		{
			scale = env->editor.scale / 3.0;
			color = 0xFF00FF00;
			if (env->inputs.left_click
					&& env->editor.start_vertex == -1
					&& env->editor.selected_vertex == -1
					&& env->editor.selected_player == -1
					&& env->editor.selected_object == -1)
			{
				env->editor.selected_vertex = i;
				env->editor.start_pos.x = env->vertices[env->editor.selected_vertex].x;
				env->editor.start_pos.y = env->vertices[env->editor.selected_vertex].y;

			}
			if (env->inputs.del && !current_vertices_contains(env, i))
			{
				env->editor.selected_vertex = i;
				delete_vertex(env, i);
				delete_invalid_sectors(env);
				delete_invalid_vertices(env);
			}
		}
		else
		{
			color = 0xFFFF0000;
			scale = env->editor.scale / 5.0;
		}
		if (env->editor.selected_vertex == i)
			color = 0xFF00FF00;
		draw_circle(new_circle(color, color, center, scale), env);
		i++;
	}
}
