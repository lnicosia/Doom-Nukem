/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles_maths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:10:22 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/05 18:58:51 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int		get_projectile_relative_pos(t_camera *camera, t_env *env)
{
	t_list		*tmp;

	tmp = env->projectiles;
	if (tmp)
	{
		get_translated_projectile_pos(camera, ((t_projectile*)tmp->content));
		get_rotated_projectile_pos(camera, ((t_projectile*)tmp->content));
		while (tmp->next)
		{
			tmp = tmp->next;
			get_translated_projectile_pos(camera,
			((t_projectile*)tmp->content));
			get_rotated_projectile_pos(camera, ((t_projectile*)tmp->content));
		}
	}
	return (0);
}

void	get_translated_projectile_pos(t_camera *camera,
t_projectile *projectile)
{
	projectile->translated_pos.x = projectile->pos.x - camera->pos.x;
	projectile->translated_pos.z = projectile->pos.y - camera->pos.y;
	projectile->translated_pos.y = projectile->pos.z - camera->pos.z;
}

void	get_rotated_projectile_pos(t_camera *camera, t_projectile *projectile)
{
	projectile->rotated_pos.x = projectile->translated_pos.x
		* camera->angle_sin - projectile->translated_pos.z * camera->angle_cos;
	projectile->rotated_pos.z = projectile->translated_pos.x
		* camera->angle_cos + projectile->translated_pos.z * camera->angle_sin;
	projectile->rotated_pos.y = projectile->translated_pos.y
		+ projectile->rotated_pos.z * camera->angle_z;
}

void	project_projectile(t_render_projectile *prender,
t_projectile *projectile, t_env *env)
{
	double	scale;

	scale = prender->camera->scale;
	prender->screen_pos.y = env->h_h
		+ (projectile->rotated_pos.y * scale / -projectile->rotated_pos.z);
	prender->screen_pos.x = env->h_w
		+ (projectile->rotated_pos.x * scale / -projectile->rotated_pos.z);
}
