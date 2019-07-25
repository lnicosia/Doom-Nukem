/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 17:44:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		editor_keys(t_env *env)
{
	int		clicked_vertex;

	if (env->inputs.left_click)
	{
		if (env->drawing)
		{
			clicked_vertex = get_existing_vertex(env);
			if (clicked_vertex == -1)
			{
				if (!env->edit.sector_done)
					env->edit.sector_done = 1;
				add_vertex(env);
			}
			else
			{
				env->edit.sector_done = env->edit.sector_done ? 0 : 1;
				if (env->edit.sector_done)
					env->edit.current_vertices = NULL;
			}
		}
		env->inputs.left_click = 0;
	}
	if (env->inputs.right_click)
	{
		env->edit.center.x += env->sdl.mouse_x;
		env->edit.center.y += env->sdl.mouse_y;
	}
}
