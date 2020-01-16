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

void	*get_explosion_relative_pos(t_camera camera, t_env *env)
{
	t_list		*tmp;

	tmp = env->explosions;
	while (tmp)
	{
		get_translated_explosion_pos(camera, ((t_explosion*)tmp->content));
		get_rotated_explosion_pos(camera, ((t_explosion*)tmp->content));
		tmp = tmp->next;
	}
	return (NULL);
}

void	get_translated_explosion_pos(t_camera camera, t_explosion *explosion)
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
	explosion->translated_pos.x = explosion->pos.x - camera.pos.x;
	explosion->translated_pos.z = explosion->pos.y - camera.pos.y;
	explosion->translated_pos.y = explosion->pos.z - camera.pos.z;
}

void	get_rotated_explosion_pos(t_camera camera, t_explosion *explosion)
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
	explosion->rotated_pos.x = explosion->translated_pos.x
		* camera.angle_sin - explosion->translated_pos.z * camera.angle_cos;
	explosion->rotated_pos.z = explosion->translated_pos.x
		* camera.angle_cos + explosion->translated_pos.z * camera.angle_sin;
	explosion->rotated_pos.y = explosion->translated_pos.y
		+ explosion->rotated_pos.z * camera.angle_z;
}

void	project_explosion(t_render_explosion *erender, t_explosion explosion, t_env *env)
{
	double	scale;

	scale = erender->camera.scale;
	erender->screen_pos.y = env->h_h
		+ (explosion.rotated_pos.y * scale / -explosion.rotated_pos.z);
	erender->screen_pos.x = env->h_w
		+ (explosion.rotated_pos.x * scale / -explosion.rotated_pos.z);
}