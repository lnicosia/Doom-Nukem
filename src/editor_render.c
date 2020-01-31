/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 15:38:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_render(t_env *env)
{
	reset_clipped(env);
	if (!env->input_box.state)
	{
		if (editor_3d_keys(env))
			return (-1);
	}
	animations(env);
	if (draw_walls(&env->player.camera, env))
		return (crash("Failed to draw walls\n", env));
	if (draw_objects(env->player.camera, env))
		return (-1);
	if (draw_enemies(env->player.camera, env))
		return (-1);
	draw_crosshair(env);
	if (env->options.show_fps)
		fps(env);
	game_time(env);
	minimap(env);
	if (!env->input_box.state && !env->editor.tab)
		view(env);
	env->editor.select = 0;
	return (0);
}
