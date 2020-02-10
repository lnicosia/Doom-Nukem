/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:39:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	draw_grid_enemies(t_env *env)
{
	t_point		center;
	double		scale;
	int			i;
	Uint32		color;

	i = 0;
	if (env->editor.dragged_enemy != -1)
	{
		color = 0xFF0000FF;
		scale = env->editor.scale / 2.0;
		center.x = env->sdl.mx;
		center.y = env->sdl.my;
		draw_circle(new_circle(color, color, center, scale), env);
	}
	while (i < env->nb_enemies)
	{
		center.x = env->enemies[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y = env->enemies[i].pos.y * env->editor.scale + env->editor.center.y;
		if (env->sdl.mx > center.x - env->editor.scale / 2.0
				&& env->sdl.mx < center.x + env->editor.scale / 2.0
				&& env->sdl.my > center.y - env->editor.scale / 2.0
				&& env->sdl.my < center.y + env->editor.scale / 2.0)
		{
			scale = env->editor.scale;
			color = 0xFF0000FF;
			if (env->inputs.left_click
					&& !env->confirmation_box.state
					&& !env->input_box.state
					&& env->editor.event_panel_dragged == -1
					&& env->editor.start_vertex == -1
					&& env->editor.dragged_player == -1
					&& env->editor.dragged_enemy == -1
					&& env->editor.dragged_vertex == -1
					&& env->editor.dragged_object == -1
					&& env->sdl.mx > 400)
			{
				reset_selection(env);
				env->editor.dragged_enemy = i;
				env->selected_enemy = i;
				env->editor.general_tab.state = DOWN;
				env->editor.general_tab.anim_state = PRESSED;
				new_tabs_position(env);
				check_event_creation(env);
			}
		}
		else
		{
			color = 0xFF0000FF;
			scale = env->editor.scale / 2.0;
		}
		if (env->selected_enemy == i)
			color = 0xFF0000FF;
		if (env->editor.dragged_enemy != i)
			draw_circle(new_circle(color, color, center, scale), env);
		i++;
	}
}
