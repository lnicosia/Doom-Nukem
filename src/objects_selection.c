/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/29 12:02:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	objects_selection(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 180
			&& env->sdl.my < 220
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_enemy == -1
			&& !env->teleport.create)
	{
		env->editor.dragged_object = env->nb_objects;
	}
	if (!env->inputs.left_click && env->editor.dragged_object != -1)
	{
		if (env->sdl.mx > 200)
		{
			if (env->editor.dragged_object == env->nb_objects)
			{
				add_object(env);
				env->nb_objects++;
			}
			else
			{
				env->objects[env->editor.dragged_object].pos.x =	(env->sdl.mx - env->editor.center.x) / env->editor.scale;
				env->objects[env->editor.dragged_object].pos.y =	(env->sdl.my - env->editor.center.y) / env->editor.scale;
			}
		}
		else
			delete_object(env, env->editor.dragged_object);
		env->editor.dragged_object = -1;
	}
}
