/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 15:02:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_object_angle(t_object *object, t_point pos, t_env *env)
{
	t_point	p;

	p = new_point(
		pos.x + cos(object->angle * CONVERT_RADIANS)
		* env->editor.scale * 2,
		pos.y + sin(object->angle * CONVERT_RADIANS)
		* env->editor.scale * 2);
	draw_line(pos, p, *env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(object->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale,
		p.y + sin(object->angle * CONVERT_RADIANS
			- M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, *env, 0xFFFFFF00);
	pos = new_point(
		p.x + cos(object->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale,
		p.y + sin(object->angle * CONVERT_RADIANS
			+ M_PI / 1.3) * env->editor.scale);
	draw_line(pos, p, *env, 0xFFFFFF00);
}

int		click_on_grid_object(t_env *env)
{
	if (env->inputs.left_click
		&& !env->confirmation_box.state
		&& !env->input_box.state
		&& env->editor.event_panel_dragged == -1
		&& env->editor.start_vertex == -1
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_start_player == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !is_mouse_on_any_selection_tab(env)
		&& env->editor.dragged_object == -1)
		return (1);
  	return (0);
}

void	draw_object_sprite(int i, double scale, t_point center, t_env *env)
{
	t_point		size;
	t_sprite	*sprite;

	sprite = &env->object_sprites[env->objects[i].sprite];
	size = new_point(scale,
	scale / (sprite->size[0].x / (double)sprite->size[0].y));
	draw_object_angle(&env->objects[i], center, env);
	center = new_point(center.y - size.y / 2, center.x - size.x / 2);
	if (env->selected_object == i)
		apply_sprite_selected(env->object_sprites[env->objects[i].sprite],
		center, size, env);
	else
		apply_sprite(env->object_sprites[env->objects[i].sprite],
		center, size, env);
}

void	draw_grid_object(int i, t_env *env)
{
	t_point		center;
	double		scale;

	center.x =
	env->objects[i].pos.x * env->editor.scale + env->editor.center.x;
	center.y =
	env->objects[i].pos.y * env->editor.scale + env->editor.center.y;
	if (env->sdl.mx > center.x - env->editor.scale
			&& env->sdl.mx < center.x + env->editor.scale
			&& env->sdl.my > center.y - env->editor.scale
			&& env->sdl.my < center.y + env->editor.scale)
	{
		scale = env->editor.scale * 2.5;
		if (click_on_grid_object(env))
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
	draw_object_sprite(i, scale, center, env);
}

void	draw_grid_objects(t_env *env)
{
	int			i;

	i = 0;
	while (i < env->nb_objects)
	{
	  	draw_grid_object(i, env);
		i++;
	}
}
