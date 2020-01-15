/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tab_button.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/15 17:14:14 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_wall_sprite_buttons(t_env *env)
{
	(void)env;
}

void	init_wall_sector_buttons(t_env *env)
{
	env->editor.hud.s_wall.brightness = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_wall.brightness, env);
	env->editor.hud.s_wall.brightness.pos = new_point(500, 230);
	env->editor.hud.s_wall.color = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_wall.color, env);
	env->editor.hud.s_wall.color.pos = new_point(540, 230);
	env->editor.hud.s_wall.intensity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_wall.intensity, env);
	env->editor.hud.s_wall.intensty.pos = new_point(540, 280);
	env->editor.hud.s_wall.gravity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_wall.gravity, env);
	env->editor.hud.s_wall.gravity.pos = new_point(560, 230);
}

void	init_wall_general_buttons(t_env *env)
{
	env->editor.hud.g_wall.texture = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_wall.texture, env);
	env->editor.hud.g_wall.texture.pos = new_point(500, 230);
	env->editor.hud.g_wall.texture_scale_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_wall.texture_scale_x, env);
	env->editor.hud.g_wall.texture_scale_x.pos = new_point(540, 230);
	env->editor.hud.g_wall.texture_scale_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_wall.texture_scale_y, env);
	env->editor.hud.g_wall.texture_scale_y.pos = new_point(540, 280);
	env->editor.hud.g_wall.texture_align_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_wall.texture_align_x, env);
	env->editor.hud.g_wall.texture_align_x.pos = new_point(560, 230);
	env->editor.hud.g_wall.texture_align_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_wall.texture_align_y, env);
	env->editor.hud.g_wall.texture_align_y.pos = new_point(560, 280);
}