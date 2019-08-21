/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:41:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/21 13:43:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	draw_grid_objects(t_env *env)
{
	t_point		center;
	double		scale;
	int			i;
	Uint32		color;

	i = 0;
	if (env->editor.selected_object != -1)
	{
		color = 0xFF00FF00;
		scale = env->editor.scale / 2.0;
		center.x = env->sdl.mx;
		center.y = env->sdl.my;
		draw_circle(new_circle(color, color, center, scale), env);
	}
	while (i < env->nb_objects)
	{
		center.x = env->objects[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y = env->objects[i].pos.y * env->editor.scale + env->editor.center.y;
		if (env->sdl.mx > center.x - env->editor.scale / 2.0
				&& env->sdl.mx < center.x + env->editor.scale / 2.0
				&& env->sdl.my > center.y - env->editor.scale / 2.0
				&& env->sdl.my < center.y + env->editor.scale / 2.0)
		{
			scale = env->editor.scale;
			color = 0xFF00FF00;
			if (env->inputs.left_click
					&& !env->editor.new_sector
					&& env->editor.selected_player == -1
					&& env->editor.selected_object == -1
					&& env->editor.selected_vertex == -1)
				env->editor.selected_object = i;
		}
		else
		{
			color = 0xFFFFFF00;
			scale = env->editor.scale / 2.0;
		}
		if (env->editor.selected_object != i)
			draw_circle(new_circle(color, color, center, scale), env);
		i++;
	}
}
