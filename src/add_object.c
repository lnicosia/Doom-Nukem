/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:42:42 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/24 14:33:56 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	add_object(t_env *env)
{
	t_object	object;

	ft_bzero(&object, sizeof(t_object));
	object.num = env->nb_objects;
	object.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	object.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	object.sprite = env->objects_main_sprites[0];
	object.scale = 2;
	object.angle = 0;
	object.exists = 1;
	object.damage = 0;
	object.sector = get_sector_no_z(env, new_v3(object.pos.x, object.pos.y, 0));
	if (object.sector != -1)
	{
		object.light_color = env->sectors[object.sector].light_color;
		object.brightness = env->sectors[object.sector].brightness;
		object.intensity = env->sectors[object.sector].intensity;
		object.pos.z = get_floor_at_pos(env->sectors[object.sector],
		object.pos, env);
	}
	else
	{
		object.light_color = 0xFFFFFFFF;
		object.brightness = 0;
		object.intensity = 0;
		object.pos.z = 0;
	}
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	env->editor.create_object = 0;
	env->editor.add_object.state = UP;
	env->nb_objects++;
	return (0);
}
