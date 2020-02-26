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
	t_sprite	sprite;
	double		scale;
	int			i;

	i = 0;
	while (i < env->nb_objects)
	{
		center.x =
		env->objects[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y =
		env->objects[i].pos.y * env->editor.scale + env->editor.center.y;
		sprite = env->object_sprites[env->objects[i].sprite];
		if (env->sdl.mx > center.x - env->editor.scale
				&& env->sdl.mx < center.x + env->editor.scale
				&& env->sdl.my > center.y - env->editor.scale
				&& env->sdl.my < center.y + env->editor.scale)
		{
			scale = env->editor.scale * 2.5;
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
			scale = env->editor.scale * 2.0;
		size = new_point(scale,
		scale / (sprite.size[0].x / (double)sprite.size[0].y));
		center = new_point(center.y - size.y / 2, center.x - size.x / 2);
		if (env->selected_object == i)
			apply_sprite_selected(env->object_sprites[env->objects[i].sprite],
			center, size, env);
		else
			apply_sprite(env->object_sprites[env->objects[i].sprite],
			center, size, env);
		i++;
	}
}
