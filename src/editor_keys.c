/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 15:20:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		editor_keys(t_env *env)
{
	if (env->inputs.left_click)
	{
		if (env->drawing && get_existing_vertex(env) == -1)
		{
			add_vertex(env);
			env->edit.nb_vertex++;
		}
		env->inputs.left_click = 0;
	}
	if (env->inputs.right_click)
	{
		env->edit.center.x += env->sdl.mouse_x;
		env->edit.center.y += env->sdl.mouse_y;
	}
}
