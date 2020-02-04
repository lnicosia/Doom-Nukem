/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/03 14:08:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	objects_selection(t_env *env)
{
	if (env->inputs.left_click && env->editor.dragged_object != -1)
	{
		env->objects[env->editor.dragged_object].pos.x =
		(env->sdl.mx - env->editor.center.x) / env->editor.scale;
		env->objects[env->editor.dragged_object].pos.y =
		(env->sdl.my - env->editor.center.y) / env->editor.scale;
		update_object_light(env, env->editor.dragged_object);
	}
	else
		env->editor.dragged_object = -1;
}
