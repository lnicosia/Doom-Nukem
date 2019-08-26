/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/26 14:31:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	objects_selection(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 280
			&& env->sdl.my < 320
			&& env->editor.start_vertex == -1
			&& env->editor.selected_player == -1
			&& env->editor.selected_vertex == -1
			&& env->editor.selected_object == -1)
	{
		env->editor.selected_object = env->nb_objects;
	}
	if (!env->inputs.left_click && env->editor.selected_object != -1)
	{
		if (env->sdl.mx > 200)
		{
			if (env->editor.selected_object == env->nb_objects)
			{
				add_object(env);
				env->nb_objects++;
			}
			else
			{
				env->objects[env->editor.selected_object].pos.x =	(env->sdl.mx - env->editor.center.x) / env->editor.scale;
				env->objects[env->editor.selected_object].pos.y =	(env->sdl.my - env->editor.center.y) / env->editor.scale;
			}
		}
		else
			delete_object(env, env->editor.selected_object);
		env->editor.selected_object = -1;
	}
}
