/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:42:42 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/28 16:12:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_object_sector(t_object *object, t_env *env)
{
	object->sector = get_sector_no_z(env, new_v3(object->pos.x,
	object->pos.y, 0));
	if (object->sector != -1)
	{
		object->light_color = env->sectors[object->sector].light_color;
		object->brightness = env->sectors[object->sector].brightness;
		object->intensity = env->sectors[object->sector].intensity;
		object->pos.z = get_floor_at_pos(&env->sectors[object->sector],
		object->pos, env);
	}
	else
	{
		object->light_color = 0xFFFFFFFF;
		object->brightness = 0;
		object->intensity = 0;
		object->pos.z = 0;
	}
}

int		add_object(t_env *env)
{
	t_object	object;

	ft_bzero(&object, sizeof(t_object));
	object.num = env->nb_objects;
	object.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	object.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	object.sprite = env->editor.current_object;
	object.scale = 2;
	object.angle = 0;
	object.exists = 1;
	object.damage = 0;
	set_object_sector(&object, env);
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object)
		* env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	if (!(env->player.colliding_objects =
		(int*)ft_realloc(env->player.colliding_objects,
		sizeof(int) * env->nb_objects, sizeof(int) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	env->editor.create_object = 0;
	env->editor.add_object.state = UP;
	env->nb_objects++;
	init_objects_data(env);
	return (0);
}
