/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tab_button.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 17:09:07 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_floor_sprite_buttons(t_env *env)
{
	(void)env;
}

void	init_floor_sector_buttons(t_env *env)
{
	env->editor.hud.s_floor.brightness = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.brightness, env);
	env->editor.hud.s_floor.brightness.pos = new_point(500, 230);
	env->editor.hud.s_floor.color = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.color, env);
	env->editor.hud.s_floor.color.pos = new_point(540, 230);
	env->editor.hud.s_floor.intensity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.intensity, env);
	env->editor.hud.s_floor.intensty.pos = new_point(540, 280);
	env->editor.hud.s_floor.gravity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.gravity, env);
	env->editor.hud.s_floor.gravity.pos = new_point(560, 230);
}

void	init_floor_general_buttons(t_env *env)
{
	env->editor.hud.g_floor.texture = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.texture, env);
	env->editor.hud.g_floor.texture.pos = new_point(500, 230);
	env->editor.hud.g_floor.texture_scale_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.texture_scale_x, env);
	env->editor.hud.g_floor.texture_scale_x.pos = new_point(540, 230);
	env->editor.hud.g_floor.texture_scale_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.texture_scale_y, env);
	env->editor.hud.g_floor.texture_scale_y.pos = new_point(540, 280);
	env->editor.hud.g_floor.texture_align_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.texture_align_x, env);
	env->editor.hud.g_floor.texture_align_x.pos = new_point(560, 230);
	env->editor.hud.g_floor.texture_align_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.texture_align_y, env);
	env->editor.hud.g_floor.texture_align_y.pos = new_point(560, 280);
}