/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/08 15:30:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void	get_translated_object_pos(t_object *object, t_env *env)
{
	/*object->translated_left_bottom.x = (object.pos.x - object.width / 2.0)
		- env->player.pos.x;
	object->translated_left_bottom.z = object.pos.y - env->player.pos.y;
	object->translated_left_bottom.y = (object.pos.z - env->player.pos.z);
	object->translated_right_bottom.x = (object.pos.x + object.width / 2.0)
		- env->player.pos.x;
	object->translated_right_bottom.z = object->translated_left_bottom.z;
	object->translated_right_bottom.y = object->translated_left_bottom.y;
	object->translated_left_top.x = object->translated_left_top.x;
	object->translated_left_top.z = object->translated_left_top.z;
	object->translated_left_top.y = (object.pos.z + object.height)
		- env->player.pos.z;
	object->translated_right_top.x = object->translated_right_top.x;
	object->translated_right_top.z = object->translated_right_top.z;
	object->translated_right_top.y = object->translated_left_top.y;*/
	object->translated_pos.x = object->pos.x - env->player.pos.x;
	object->translated_pos.z = object->pos.y - env->player.pos.y;
	object->translated_pos.y = object->pos.z - env->player.pos.z;
}

void	get_rotated_object_pos(t_object *object, t_env *env)
{
	/*object->rotated_left_bottom.x = object->translated_left_bottom.x
		* env->player.angle_sin - object->translated_left_bottom.z
		* env->player.angle_cos;
	object->rotated_left_bottom.z = object->translated_left_bottom.x
		* env->player.angle_cos + object->translated_left_bottom.z
		* env->player.angle_sin;
	object->rotated_left_bottom.y = object->translated_left_bottom.y
		+ object->rotated_left_bottom.z * env->player.angle_z;
	object->rotated_right_bottom.x = object->translated_right_bottom.x
		* env->player.angle_sin - object->translated_right_bottom.z
		* env->player.angle_cos;
	object->rotated_right_bottom.z = object->rotated_left_bottom.z;
	object->rotated_right_bottom.y = object->rotated_left_bottom.y;
	object->rotated_left_top.x = object->rotated_left_bottom.x;
	object->rotated_left_top.z = object->rotated_left_bottom.z;
	object->rotated_left_top.y = object->translated_left_top.y
		+ object->rotated_left_bottom.z * env->player.angle_z;
	object->rotated_right_top.x = object->rotated_right_bottom.x;
	object->rotated_right_top.z = object->rotated_right_bottom.z;
	object->rotated_right_top.y = object->rotated_left_top.y;*/
	object->rotated_pos.x = object->translated_pos.x
		* env->player.angle_sin - object->translated_pos.z * env->player.angle_cos;
	object->rotated_pos.z = object->translated_pos.x
		* env->player.angle_cos + object->translated_pos.z * env->player.angle_sin;
	object->rotated_pos.y = object->translated_pos.y
		+ object->rotated_pos.z * env->player.angle_z;
}

void	project_object(t_render_object *orender, t_object object, t_env *env)
{
	double	scale;

	scale = env->camera.scale;
	orender->screen_pos.y = env->h_h
		+ (object.rotated_pos.y * scale / -object.rotated_pos.z);
	orender->screen_pos.x = env->h_w + (object.rotated_pos.x * (scale / -object.rotated_pos.z));
	orender->dist = sqrt(pow(object.pos.x - env->player.pos.x, 2)
		+ pow(object.pos.y - env->player.pos.y, 2));
}
