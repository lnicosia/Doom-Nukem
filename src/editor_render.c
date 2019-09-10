/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 11:36:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_render(t_env *env)
{
	if (env->inputs.enter)
	{
		env->editor.in_game = 0;
		env->selected_floor = -1;
		env->selected_ceiling = -1;
		env->selected_object = -1;
		env->selected_enemy = -1;
		env->selected_wall1 = -1;
		env->selected_wall2 = -1;
		env->inputs.enter = 0;
		SDL_SetRelativeMouseMode(0);
		return (0);
	}
	reset_clipped(env);
	keys(env);
	if (draw_walls(env))
		return (crash("Failed to draw walls\n", env));
	draw_objects(env);
	draw_enemies(env);
	draw_crosshair(env);
	if (env->options.show_fps)
		fps(env);
	game_time(env);
	update_player_z(env);
	view(env);
	env->editor.select = 0;
	return (0);
}
