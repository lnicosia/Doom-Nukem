/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projectiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:44 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/06 12:18:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int		get_sprite_direction_projectile(t_projectile projectile)
{
	double	angle;

	angle = (int)((atan2(projectile.translated_pos.z, projectile.translated_pos.x)) * CONVERT_DEGREES) % 360;
	if (angle < 0)
		angle += 360;
	if (angle >= projectile.angle - 22.5 && angle < projectile.angle + 22.5)
		return (4);
	else if (angle >= projectile.angle + 22.5 && angle < projectile.angle + 67.5)
		return (5);
	else if (angle >= projectile.angle + 67.5 && angle < projectile.angle + 112.5)
		return (6);
	else if (angle >= projectile.angle + 112.5 && angle < projectile.angle + 157.5)
		return (7);
	else if (angle >= projectile.angle + 157.5 && angle < projectile.angle + 202.5)
		return (0);
	else if (angle >= projectile.angle + 202.5 && angle < projectile.angle + 247.5)
		return (1);
	else if (angle >= projectile.angle + 247.5 && angle < projectile.angle + 292.5)
		return (2);
	else if (angle >= projectile.angle + 292.5 && angle < projectile.angle + 337.5)
		return (3);
	else if (angle >= projectile.angle + 337.5)
		return (4);
	else if (angle < projectile.angle - 22.5 && angle >= projectile.angle - 67.5)
		return (3);
	else if (angle < projectile.angle - 67.5 && angle >= projectile.angle - 112.5)
		return (2);
	else if (angle < projectile.angle - 112.5 && angle >= projectile.angle - 157.5)
		return (1);
	else if (angle < projectile.angle - 157.5 && angle >= projectile.angle - 202.5)
		return (0);
	else if (angle < projectile.angle - 202.5 && angle >= projectile.angle - 247.5)
		return (7);
	else if (angle < projectile.angle - 247.5 && angle >= projectile.angle - 292.5)
		return (6);
	else if (angle < projectile.angle - 292.5 && angle >= projectile.angle - 337.5)
		return (5);
	else if (angle < projectile.angle - 337.5)
		return (4);
	else
		return (0);
}

void		draw_projectiles(t_camera camera, t_env *env)
{
	t_list			*tmp;
	t_projectile	*projectile;

	get_projectile_relative_pos(camera, env);
	tmp = env->projectiles;
	if (tmp)
	{
		projectile = (t_projectile*)tmp->content;
		if (projectile->rotated_pos.z > 1 && projectile->exists)
		{
			if (!env->options.lighting
					|| (!projectile->brightness && !projectile->intensity))
				draw_projectile_no_light(camera, projectile, env);
			else if (!projectile->brightness)
				draw_projectile_color(camera, projectile, env);
			else if (!projectile->intensity)
				draw_projectile_brightness(camera, projectile, env);
			else
				draw_projectile_both(camera, projectile, env);
		}
		while (tmp->next)
		{
			tmp = tmp->next;
			projectile = (t_projectile*)tmp->content;
			if (projectile->rotated_pos.z > 1 && projectile->exists)
			{
				if (!env->options.lighting
						|| (!projectile->brightness && !projectile->intensity))
					draw_projectile_no_light(camera, projectile, env);
				else if (!projectile->brightness)
					draw_projectile_color(camera, projectile, env);
				else if (!projectile->intensity)
					draw_projectile_brightness(camera, projectile, env);
				else
					draw_projectile_both(camera, projectile, env);
			}
		}
	}
}
