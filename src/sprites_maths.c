/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/21 15:30:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void	get_translated_object_pos(t_render_object *orender, t_object object, t_env *env)
{
	orender->translated_left_bottom.x = (object.pos.x - object.width / 2.0)
		- env->player.pos.x;
	orender->translated_left_bottom.z = object.pos.y - env->player.pos.y;
	orender->translated_left_bottom.y = (object.pos.z - env->player.pos.z);
	orender->translated_right_bottom.x = (object.pos.x + object.width / 2.0)
		- env->player.pos.x;
	orender->translated_right_bottom.z = orender->translated_left_bottom.z;
	orender->translated_right_bottom.y = orender->translated_left_bottom.y;
	orender->translated_left_top.x = orender->translated_left_top.x;
	orender->translated_left_top.z = orender->translated_left_top.z;
	orender->translated_left_top.y = (object.pos.z + object.height)
		- env->player.pos.z;
	orender->translated_right_top.x = orender->translated_right_top.x;
	orender->translated_right_top.z = orender->translated_right_top.z;
	orender->translated_right_top.y = orender->translated_left_top.y;
	orender->translated_pos.x = object.pos.x - env->player.pos.x;
	orender->translated_pos.z = object.pos.y - env->player.pos.y;
	orender->translated_pos.y = object.pos.z - env->player.pos.z;
}

void	get_rotated_object_pos(t_render_object *orender, t_env *env)
{
	orender->rotated_left_bottom.x = orender->translated_left_bottom.x
		* env->player.angle_sin - orender->translated_left_bottom.z
		* env->player.angle_cos;
	orender->rotated_left_bottom.z = orender->translated_left_bottom.x
		* env->player.angle_cos + orender->translated_left_bottom.z
		* env->player.angle_sin;
	orender->rotated_left_bottom.y = orender->translated_left_bottom.y
		+ orender->rotated_left_bottom.z * env->player.angle_z;
	orender->rotated_right_bottom.x = orender->translated_right_bottom.x
		* env->player.angle_sin - orender->translated_right_bottom.z
		* env->player.angle_cos;
	orender->rotated_right_bottom.z = orender->rotated_left_bottom.z;
	orender->rotated_right_bottom.y = orender->rotated_left_bottom.y;
	orender->rotated_left_top.x = orender->rotated_left_bottom.x;
	orender->rotated_left_top.z = orender->rotated_left_bottom.z;
	orender->rotated_left_top.y = orender->translated_left_top.y
		+ orender->rotated_left_bottom.z * env->player.angle_z;
	orender->rotated_right_top.x = orender->rotated_right_bottom.x;
	orender->rotated_right_top.z = orender->rotated_right_bottom.z;
	orender->rotated_right_top.y = orender->rotated_left_top.y;
	orender->rotated_pos.x = orender->translated_pos.x
		* env->player.angle_sin - orender->translated_pos.z * env->player.angle_cos;
	orender->rotated_pos.z = orender->translated_pos.x
		* env->player.angle_cos + orender->translated_pos.z * env->player.angle_sin;
	orender->rotated_pos.y = orender->translated_pos.y
		+ orender->rotated_pos.z * env->player.angle_z;
}

void	project_object(t_render_object *orender, t_object object, t_env *env)
{
	double	scale;

	scale = env->camera.scale;
	orender->screen_pos.y = env->h / 2
		+ (orender->rotated_pos.y * scale / -orender->rotated_pos.z);
	orender->screen_pos.x = env->w / 2 + (orender->rotated_pos.x * (scale / -orender->rotated_pos.z));
	(void)object;
}
