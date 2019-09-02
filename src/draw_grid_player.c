/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:40:49 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/30 15:38:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_player(t_env *env)
{
	t_circle	circle;
	double		scale;

	circle.color = 0xFFFF0000;
	circle.line_color = 0xFFFF0000;
	scale = 0;
	if (env->editor.dragged_player == 1)
	{
		circle.center.x = env->sdl.mx;
		circle.center.y = env->sdl.my;
		circle.radius = env->editor.scale;
	}
	else
	{
		circle.center.x = (env->player.pos.x * env->editor.scale) + env->editor.center.x;
		circle.center.y = (env->player.pos.y * env->editor.scale) + env->editor.center.y;
		if (env->sdl.mx > circle.center.x - env->editor.scale / 2
				&& env->sdl.mx < circle.center.x + env->editor.scale / 2
				&& env->sdl.my > circle.center.y - env->editor.scale / 2
				&& env->sdl.my < circle.center.y + env->editor.scale / 2)
		{
			circle.radius = env->editor.scale;
			if (env->inputs.left_click
					&& env->editor.start_vertex == -1
					&& env->editor.dragged_player == -1
					&& env->editor.dragged_object == -1
					&& env->editor.dragged_vertex == -1)
			{
				env->editor.dragged_player = 1;
				env->editor.selected_player = 1;
				env->editor.selected_object = -1;
				env->editor.selected_vertex = -1;
				env->editor.selected_sector = -1;
			}
		}
		else
			circle.radius = env->editor.scale / 2;
	}
	draw_circle(circle, env);
	if (env->editor.selected_player == 1)
	{
		circle.radius *= 0.75;
		circle.color = 0xFF00FF00;
		draw_circle(circle, env);
	}
}
