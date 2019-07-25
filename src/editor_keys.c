/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 17:28:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		editor_keys(t_env *env)
{
	if (env->inputs.left_click && env->drawing
		&& env->sdl.mx < 200 && env->sdl.mx > 100
		&& env->sdl.my < 200 && env->sdl.my > 100
		&& env->edit.new_player != 2)
	{
		ft_printf("new player request\n");
		env->edit.new_player = 1;
	}
	if (env->inputs.left_click && !env->drawing && env->edit.new_player == 1)
		add_player(env);
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
		if (env->sdl.mx < env->w && env->sdl.mx > 0
		&& env->sdl.my < env->h && env->sdl.my > 0)
		{
			env->edit.center.x += env->sdl.mouse_x;
			env->edit.center.y += env->sdl.mouse_y;
		}
	}
}
