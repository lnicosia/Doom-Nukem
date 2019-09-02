/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:24:50 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/02 17:44:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	add_object(t_env *env)
{
	t_object	object;

	object.num = env->nb_objects;
	object.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	object.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	object.pos.z = 6;
	object.sprite = 1;
	object.scale = 50;
	object.angle = 0;
	object.exists = 1;
	object.sector = get_sector_no_z(env, new_v3(object.pos.x, object.pos.y, object.pos.z));
	if (object.sector != -1)
		object.light = env->sectors[object.sector].light;
	else
		object.light = 1;
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	return (0);
}
