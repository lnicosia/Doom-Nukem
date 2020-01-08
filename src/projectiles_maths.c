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

void	*get_projectile_relative_pos(t_camera camera, t_env *env)
{
	t_list		*tmp;

	tmp = env->projectiles;
	if (tmp)
	{
		get_translated_projectile_pos(camera, ((t_projectile*)tmp->content));
		get_rotated_projectile_pos(camera, ((t_projectile*)tmp->content));
		while (tmp->next)
		{
			//ft_printf("i = %d\n", i);
			tmp = tmp->next;
			get_translated_projectile_pos(camera, ((t_projectile*)tmp->content));
			get_rotated_projectile_pos(camera, ((t_projectile*)tmp->content));
		}
	}
	return (NULL);
}

void	get_translated_projectile_pos(t_camera camera, t_projectile *projectile)
{
	/*object->translated_left_bottom.x = (object.pos.x - object.width / 2.0)
		- camera.pos.x;
	object->translated_left_bottom.z = object.pos.y - camera.pos.y;
	object->translated_left_bottom.y = (object.pos.z - camera.pos.z);
	object->translated_right_bottom.x = (object.pos.x + object.width / 2.0)
		- camera.pos.x;
	object->translated_right_bottom.z = object->translated_left_bottom.z;
	object->translated_right_bottom.y = object->translated_left_bottom.y;
	object->translated_left_top.x = object->translated_left_top.x;
	object->translated_left_top.z = object->translated_left_top.z;
	object->translated_left_top.y = (object.pos.z + object.height)
		- camera.pos.z;
	object->translated_right_top.x = object->translated_right_top.x;
	object->translated_right_top.z = object->translated_right_top.z;
	object->translated_right_top.y = object->translated_left_top.y;*/
	projectile->translated_pos.x = projectile->pos.x - camera.pos.x;
	projectile->translated_pos.z = projectile->pos.y - camera.pos.y;
	projectile->translated_pos.y = projectile->pos.z - camera.pos.z;
}

void	get_rotated_projectile_pos(t_camera camera, t_projectile *projectile)
{
	/*object->rotated_left_bottom.x = object->translated_left_bottom.x
		* camera.angle_sin - object->translated_left_bottom.z
		* camera.angle_cos;
	object->rotated_left_bottom.z = object->translated_left_bottom.x
		* camera.angle_cos + object->translated_left_bottom.z
		* camera.angle_sin;
	object->rotated_left_bottom.y = object->translated_left_bottom.y
		+ object->rotated_left_bottom.z * camera.angle_z;
	object->rotated_right_bottom.x = object->translated_right_bottom.x
		* camera.angle_sin - object->translated_right_bottom.z
		* camera.angle_cos;
	object->rotated_right_bottom.z = object->rotated_left_bottom.z;
	object->rotated_right_bottom.y = object->rotated_left_bottom.y;
	object->rotated_left_top.x = object->rotated_left_bottom.x;
	object->rotated_left_top.z = object->rotated_left_bottom.z;
	object->rotated_left_top.y = object->translated_left_top.y
		+ object->rotated_left_bottom.z * camera.angle_z;
	object->rotated_right_top.x = object->rotated_right_bottom.x;
	object->rotated_right_top.z = object->rotated_right_bottom.z;
	object->rotated_right_top.y = object->rotated_left_top.y;*/
	projectile->rotated_pos.x = projectile->translated_pos.x
		* camera.angle_sin - projectile->translated_pos.z * camera.angle_cos;
	projectile->rotated_pos.z = projectile->translated_pos.x
		* camera.angle_cos + projectile->translated_pos.z * camera.angle_sin;
	projectile->rotated_pos.y = projectile->translated_pos.y
		+ projectile->rotated_pos.z * camera.angle_z;
}

void	project_projectile(t_render_projectile *prender, t_projectile projectile, t_env *env)
{
	double	scale;

	scale = prender->camera.scale;
	prender->screen_pos.y = env->h_h
		+ (projectile.rotated_pos.y * scale / -projectile.rotated_pos.z);
	prender->screen_pos.x = env->h_w
		+ (projectile.rotated_pos.x * scale / -projectile.rotated_pos.z);
}