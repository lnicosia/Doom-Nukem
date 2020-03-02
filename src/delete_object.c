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

#include "env.h"

int	delete_object(void *param)
{
	t_env	*env;
	int		object;

	env = (t_env*)param;
	object = env->selected_object;
	free_events(env->objects[object].collision_events,
	env->objects[object].nb_collision_events);
	env->objects = (t_object*)ft_delindex(env->objects,
			sizeof(t_object) * env->nb_objects,
			sizeof(t_object),
			sizeof(t_object) * object);
	env->nb_objects--;
	if (env->nb_objects > 0 && !env->objects)
		return (-1);
	env->selected_object = -1;
	return (0);
}
