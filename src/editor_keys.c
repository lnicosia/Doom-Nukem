/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/29 17:09:26 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor_keys(t_env *env)
{
	if (env->inputs.left_click)
	{
		if (env->drawing && get_existing_vertex(env) == -1)
		{
			add_vertex(env);
			env->edit.nb_vertex++;
		}
		if (env->inputs.left_click
				&& ((env->sdl.mx > 130
				&& env->sdl.mx < 170
				&& env->sdl.my > 280
				&& env->sdl.my < 320) 
				|| ()) && !env->drawing)
		{
			env->edit.new_player = 1;
			env->edit.drag = 1;
		}
	}	
	if (!env->inputs.left_click && env->edit.drag)
	{
		ft_printf("ousp\n");
		env->edit.drag = 0;
		add_player(env);
	}

	if (env->inputs.right_click)
	{
		env->edit.center.x += env->sdl.mouse_x;
		env->edit.center.y += env->sdl.mouse_y;
	}
}
