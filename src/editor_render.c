/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/11 17:54:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		editor_render2(t_env *env)
{
	draw_crosshair(env);
	if (env->options.show_fps)
	{
		if (fps(env))
			return (-1);
	}
	game_time(env);
	if (env->options.show_minimap)
	{
		if (editor_minimap(env))
			return (-1);
	}
	if (!env->input_box.state && !env->editor.tab)
		view(env);
	if ((env->editor.selecting_target || env->editor.selecting_condition_target)
		&& (env->editor.select || env->editor.select_portal))
		check_event_creation(env);
	env->editor.select = 0;
	env->editor.select_portal = 0;
	return (0);
}

int		editor_render(t_env *env)
{
	reset_clipped(env);
	if (!env->input_box.state)
	{
		if (editor_3d_keys(env))
			return (custom_error("Crash from editor 3d keys\n"));
	}
	if (env->player.changed_sector)
	{
		env->player.changed_sector = 0;
		env->player.old_sector = -1;
		if (env->sectors[env->player.sector].gravity == 0)
			env->player.state.fly = 1;
	}
	animations(env);
	if (draw_walls(&env->player.camera, env))
		return (-1);
	ft_printf("\n");
	if (draw_objects(&env->player.camera, env))
		return (custom_error("Failed to draw objects\n"));
	if (draw_enemies(&env->player.camera, env))
		return (custom_error("Failed to draw enemies\n"));
	if (draw_player(&env->player.camera, env->player.starting_pos, env))
		return (custom_error("failed to draw player\n"));
	return (editor_render2(env));
}
