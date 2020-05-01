/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projectiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:44 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 17:10:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "draw.h"

static int	get_sprite_direction_projectile2(t_projectile *proj, double angle)
{
	if (angle >= proj->angle + 337.5)
		return (4);
	else if (angle < proj->angle - 22.5 && angle >= proj->angle - 67.5)
		return (3);
	else if (angle < proj->angle - 67.5 && angle >= proj->angle - 112.5)
		return (2);
	else if (angle < proj->angle - 112.5 && angle >= proj->angle - 157.5)
		return (1);
	else if (angle < proj->angle - 157.5 && angle >= proj->angle - 202.5)
		return (0);
	else if (angle < proj->angle - 202.5 && angle >= proj->angle - 247.5)
		return (7);
	else if (angle < proj->angle - 247.5 && angle >= proj->angle - 292.5)
		return (6);
	else if (angle < proj->angle - 292.5 && angle >= proj->angle - 337.5)
		return (5);
	else if (angle < proj->angle - 337.5)
		return (4);
	else
		return (0);
}

int			get_sprite_direction_projectile(t_projectile *proj)
{
	double	angle;

	angle = (int)((atan2(proj->translated_pos.z,
	proj->translated_pos.x)) * CONVERT_DEGREES) % 360;
	if (angle < 0)
		angle += 360;
	if (angle >= proj->angle - 22.5 && angle < proj->angle + 22.5)
		return (4);
	else if (angle >= proj->angle + 22.5 && angle < proj->angle + 67.5)
		return (5);
	else if (angle >= proj->angle + 67.5 && angle < proj->angle + 112.5)
		return (6);
	else if (angle >= proj->angle + 112.5 && angle < proj->angle + 157.5)
		return (7);
	else if (angle >= proj->angle + 157.5 && angle < proj->angle + 202.5)
		return (0);
	else if (angle >= proj->angle + 202.5 && angle < proj->angle + 247.5)
		return (1);
	else if (angle >= proj->angle + 247.5 && angle < proj->angle + 292.5)
		return (2);
	else if (angle >= proj->angle + 292.5 && angle < proj->angle + 337.5)
		return (3);
	return (get_sprite_direction_projectile2(proj, angle));
}

int			draw_current_projectile(t_camera *camera, t_projectile *projectile,
t_env *env)
{
	if (projectile->rotated_pos.z > 1 && projectile->exists)
	{
		if (!env->options.lighting
				|| (!projectile->brightness && !projectile->intensity))
		{
			if (draw_projectile_no_light(camera, projectile, env))
				return (-1);
		}
		else if (!projectile->brightness)
		{
			if (draw_projectile_color(camera, projectile, env))
				return (-1);
		}
		else if (!projectile->intensity)
		{
			if (draw_projectile_brightness(camera, projectile, env))
				return (-1);
		}
		else
		{
			if (draw_projectile_both(camera, projectile, env))
				return (-1);
		}
	}
	return (0);
}

int			draw_projectiles(t_camera *camera, t_env *env)
{
	t_list			*tmp;

	get_projectile_relative_pos(camera, env);
	tmp = env->projectiles;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (draw_current_projectile(camera, (t_projectile*)tmp->content, env))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
