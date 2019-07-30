/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:24:50 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 14:12:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_objects(t_env *env)
{
	t_circle	circle;
	double		scale;

	circle.color = 0xFFFFFF00;
	circle.line_color = 0xFFFFFF00;
	circle.radius = env->editor.scale;
	scale = env->editor.scale / 2;
	if (env->editor.drag_object)
	{
		circle.center.x = env->sdl.mx;
		circle.center.y = env->sdl.my;
	}
	else
	{
		circle.center.x = (env->objects[env->nb_objects].pos.x * env->editor.scale) + env->editor.center.x;
		circle.center.y = (env->objects[env->nb_objects].pos.y * env->editor.scale) + env->editor.center.y;
	}
	if (circle.center.x - scale >= 0 && circle.center.x + scale < env->w
			&& circle.center.y - scale >= 0 && circle.center.y + scale < env->h)
		draw_circle(circle, env);
}

int	add_object(t_env *env)
{
	t_object	object;

	object.num = env->nb_objects;
	object.pos.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	object.pos.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	object.pos.z = 6;
	object.sprite = 1;
	object.scale = 3;
	object.angle = 0;
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	env->nb_objects++;
	return (0);
}
