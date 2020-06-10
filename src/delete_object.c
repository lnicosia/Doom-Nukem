/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:45:16 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:47:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	update_objects(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].num = i;
		i++;
	}
}

int		delete_object(void *param)
{
	t_env	*env;
	int		object;

	env = (t_env*)param;
	object = env->selected_object;
	free_events(&env->objects[object].collision_events,
	&env->objects[object].nb_collision_events);
	env->objects = (t_object*)ft_delindex(env->objects,
			sizeof(t_object) * env->nb_objects, sizeof(t_object),
			sizeof(t_object) * object);
	env->player.colliding_objects = (int*)ft_delindex(
			env->player.colliding_objects,
			sizeof(int) * env->nb_objects, sizeof(int),
			sizeof(int) * object);
	env->nb_objects--;
	if (env->nb_objects > 0 && (!env->objects
		|| !env->player.colliding_objects))
		return (-1);
	env->selected_object = -1;
	ft_memdel((void**)&env->rendered_objects);
	if (env->nb_objects > 0 && !(env->rendered_objects =
		(int*)ft_memalloc(sizeof(int) * env->nb_objects)))
		return (custom_error("Could not realloc rendered objects\n"));
	update_objects(env);
	return (0);
}
