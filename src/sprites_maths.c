/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:58:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include <math.h>

/*
** Returns the movement a sprite should do to go from the point origin
** to the point destination with the given speed
*/

t_v3	sprite_movement(t_env *env, double speed, t_v3 origin, t_v3 destination)
{
	Uint32	time;
	t_v3	direction;
	double	distance;

	time = SDL_GetTicks() - env->time.milli_s;
	speed *= time / 3;
	direction.x = destination.x - origin.x;
	direction.y = destination.y - origin.y;
	direction.z = destination.z - origin.z;
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
		return (direction);
	distance = sqrt(direction.x * direction.x + direction.y * direction.y
		+ direction.z * direction.z);
	direction.x = direction.x * speed / distance;
	direction.y = direction.y * speed / distance;
	direction.z = direction.z * speed / distance;
	return (direction);
}

int		get_object_relative_pos(void *param)
{
	t_env		*env;
	t_camera	*camera;
	int			i;
	int			max;

	env = ((t_object_thread*)param)->env;
	i = ((t_object_thread*)param)->xstart;
	max = ((t_object_thread*)param)->xend;
	camera = ((t_object_thread*)param)->camera;
	while (i < max)
	{
		get_translated_object_pos(camera, &env->objects[i]);
		get_rotated_object_pos(camera, &env->objects[i]);
		i++;
	}
	return (0);
}

void	get_translated_object_pos(t_camera *camera, t_object *object)
{
	object->translated_pos.x = object->pos.x - camera->pos.x;
	object->translated_pos.z = object->pos.y - camera->pos.y;
	object->translated_pos.y = object->pos.z - camera->pos.z;
}

void	get_rotated_object_pos(t_camera *camera, t_object *object)
{
	object->rotated_pos.x = object->translated_pos.x
		* camera->angle_sin - object->translated_pos.z * camera->angle_cos;
	object->rotated_pos.z = object->translated_pos.x
		* camera->angle_cos + object->translated_pos.z * camera->angle_sin;
	object->rotated_pos.y = object->translated_pos.y
		+ object->rotated_pos.z * camera->angle_z;
}

void	project_object(t_render_object *orender, t_object *object, t_env *env)
{
	double	scale;

	scale = orender->camera->scale;
	orender->screen_pos.y = env->h_h
		+ (object->rotated_pos.y * scale / -object->rotated_pos.z);
	orender->screen_pos.x = env->h_w
		+ (object->rotated_pos.x * scale / -object->rotated_pos.z);
}
