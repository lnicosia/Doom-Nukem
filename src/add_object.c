/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:24:50 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 15:00:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_objects(t_env *env)
{
	t_circle	circle;
	double		scale;
	int			i;

	i = 0;
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
		while (i < env->nb_objects)
		{
			circle.center.x = (env->objects[i].pos.x * env->editor.scale) + env->editor.center.x;
			circle.center.y = (env->objects[i].pos.y * env->editor.scale) + env->editor.center.y;
			draw_circle(circle, env);
			i++;
		}
	}
	if (circle.center.x - scale >= 0 && circle.center.x + scale < env->w
			&& circle.center.y - scale >= 0 && circle.center.y + scale < env->h)
		draw_circle(circle, env);
}

int	add_object(t_env *env)
{
	t_object	object;

	env->editor.objects = 1;
	object.num = env->nb_objects;
	object.pos.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	object.pos.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	object.pos.z = 6;
	object.sprite = 1;
	object.scale = 50;
	object.angle = 0;
	object.sector = get_sector_global(env, new_v3(object.pos.x, object.pos.y, object.pos.z));
	object.light = env->sectors[object.sector]. light;
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	return (0);
}
