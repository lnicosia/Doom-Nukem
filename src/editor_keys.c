/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 16:23:52 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		editor_keys(t_env *env)
{
	if (env->inputs.right_click)
	{
		if (env->sdl.mx < env->w && env->sdl.mx > 0
		&& env->sdl.my < env->h && env->sdl.my > 0)
		{
			printf("mx = %d my = %d\n", env->sdl.mx, env->sdl.my);
			env->edit.center.x += env->sdl.mouse_x;
			env->edit.center.y += env->sdl.mouse_y;
		}
	}
}
