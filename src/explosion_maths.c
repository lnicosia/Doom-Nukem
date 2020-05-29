/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosion_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:42:48 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/13 14:42:48 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int		get_explosion_relative_pos(t_camera *camera, t_env *env)
{
	t_list		*tmp;

	tmp = env->explosions;
	while (tmp)
	{
		get_translated_explosion_pos(camera, ((t_explosion*)tmp->content));
		get_rotated_explosion_pos(camera, ((t_explosion*)tmp->content));
		tmp = tmp->next;
	}
	return (0);
}

void	get_translated_explosion_pos(t_camera *camera, t_explosion *explosion)
{
	explosion->translated_pos.x = explosion->pos.x - camera->pos.x;
	explosion->translated_pos.z = explosion->pos.y - camera->pos.y;
	explosion->translated_pos.y = explosion->pos.z - camera->pos.z;
}

void	get_rotated_explosion_pos(t_camera *camera, t_explosion *explosion)
{
	explosion->rotated_pos.x = explosion->translated_pos.x
		* camera->angle_sin - explosion->translated_pos.z * camera->angle_cos;
	explosion->rotated_pos.z = explosion->translated_pos.x
		* camera->angle_cos + explosion->translated_pos.z * camera->angle_sin;
	explosion->rotated_pos.y = explosion->translated_pos.y
		+ explosion->rotated_pos.z * camera->angle_z;
}

void	project_explosion(t_render_explosion *erender, t_explosion *explosion,
t_env *env)
{
	double	scale;

	scale = erender->camera->scale;
	erender->screen_pos.y = env->h_h
		+ (explosion->rotated_pos.y * scale / -explosion->rotated_pos.z);
	erender->screen_pos.x = env->h_w
		+ (explosion->rotated_pos.x * scale / -explosion->rotated_pos.z);
}
