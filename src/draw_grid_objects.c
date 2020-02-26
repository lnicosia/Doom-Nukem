/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 10:49:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	draw_grid_objects(t_env *env)
{
	t_point		center;
	t_point		size;
	double		scale;
	int			i;
	Uint32		color;
	t_texture	texture;
//	t_v3		v[3];

	i = 0;
	if (env->editor.dragged_object != -1)
	{
		color = 0xFF00FF00;
		scale = env->editor.scale / 2.0;
		center.x = env->sdl.mx;
		center.y = env->sdl.my;
		draw_circle(new_circle(color, color, center, scale), env);
	}
	while (i < env->nb_objects)
	{
		center.x = env->objects[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y = env->objects[i].pos.y * env->editor.scale + env->editor.center.y;
		if (env->sdl.mx > center.x - env->editor.scale / 2.0
				&& env->sdl.mx < center.x + env->editor.scale / 2.0
				&& env->sdl.my > center.y - env->editor.scale / 2.0
				&& env->sdl.my < center.y + env->editor.scale / 2.0)
		{
			scale = env->editor.scale;
			color = 0xFF00FF00;
			if (env->inputs.left_click
					&& !env->confirmation_box.state
					&& !env->input_box.state
					&& env->editor.event_panel_dragged == -1
					&& env->editor.start_vertex == -1
					&& env->editor.dragged_player == -1
					&& env->editor.dragged_object == -1
					&& env->editor.dragged_vertex == -1
					&& env->editor.dragged_enemy == -1)
			{
				reset_selection(env);
				env->editor.dragged_object = i;
				env->selected_object = i;
				tabs_gestion(env);
				check_event_creation(env);
			}
		}
		else
		{
			color = 0xFFFFFF00;
			scale = env->editor.scale / 2.0;
		}
		texture = env->mini_objects_textures[0];
		size = new_point(env->editor.scale * 2, env->editor.scale * 2);
		center = new_point(center.y - size.y / 2, center.x - size.x / 2);
		if (env->editor.dragged_object != i)
		{
			//draw_circle(new_circle(color, color, center, scale), env);
			size.x /= 1.3;
			size.y /= 1.3;
		}
		if (env->selected_object == i)
			apply_image_selected(texture, center, size, env);
		else
			apply_image(texture, center, size, env);
		i++;
	/*	v[0] = new_v3(center.x + cos(env->objects[i].angle - M_PI / 2) * scale / 2,
				center.y + sin(env->objects[i].angle - M_PI / 2) * scale / 2,
				0);
		v[2] = new_v3(center.x - cos(env->objects[i].angle - M_PI / 2) * scale / 2,
				center.y - sin(env->objects[i].angle - M_PI / 2) * scale / 2,
				0);
		v[1] = new_v3(center.x + cos(env->objects[i].angle) * scale * 2,
				center.y + sin(env->objects[i].angle) * scale * 2,
				0);
		fill_triangle(v, 0xFFFFFF00, env);*/
	}
}
