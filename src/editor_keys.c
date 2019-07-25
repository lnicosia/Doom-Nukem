/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 13:39:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		editor_keys(t_env *env)
{
	if (env->inputs.left_click)
	{
		if (env->drawing)
		{
			add_vertex(env);
			env->edit.nb_vertex++;
			env->inputs.left_click = 0;
		}
	}
	if (env->inputs.right_click)
	{
		if (env->sdl.mx < env->w && env->sdl.mx > 0
		&& env->sdl.my < env->h && env->sdl.my > 0)
		{
			env->edit.center.x += env->sdl.mouse_x;
			env->edit.center.y += env->sdl.mouse_y;
		}
	}
}
