/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/19 10:50:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*get_object_relative_pos(void *param)
{
	t_env		*env;
	t_camera	camera;
	int			i;
	int			max;

	env = ((t_object_thread*)param)->env;
	i = ((t_object_thread*)param)->xstart;
	max = ((t_object_thread*)param)->xend;
	camera = ((t_object_thread*)param)->camera;
	while (i < max)
	{
		//ft_printf("i = %d\n", i);
		get_translated_object_pos(camera, &env->objects[i]);
		get_rotated_object_pos(camera, &env->objects[i]);
		i++;
	}
	return (NULL);
}

void	get_translated_object_pos(t_camera camera, t_object *object)
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
	object->translated_pos.x = object->pos.x - camera.pos.x;
	object->translated_pos.z = object->pos.y - camera.pos.y;
	object->translated_pos.y = object->pos.z - camera.pos.z;
}

void	get_rotated_object_pos(t_camera camera, t_object *object)
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
	object->rotated_pos.x = object->translated_pos.x
		* camera.angle_sin - object->translated_pos.z * camera.angle_cos;
	object->rotated_pos.z = object->translated_pos.x
		* camera.angle_cos + object->translated_pos.z * camera.angle_sin;
	object->rotated_pos.y = object->translated_pos.y
		+ object->rotated_pos.z * camera.angle_z;
}

void	project_object(t_render_object *orender, t_object object, t_env *env)
{
	double	scale;

	scale = orender->camera.scale;
	orender->screen_pos.y = env->h_h
		+ (object.rotated_pos.y * scale / -object.rotated_pos.z);
	orender->screen_pos.x = env->h_w
		+ (object.rotated_pos.x * scale / -object.rotated_pos.z);
}
