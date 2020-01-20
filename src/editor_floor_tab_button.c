/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tab_button.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/17 15:45:07 by sipatry          ###   ########.fr       */
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
	&env->editor.hud.s_floor.t_brightness, env);
	env->editor.hud.s_floor.brightness.pos = new_point(250, 520);
	env->editor.hud.s_floor.t_brightness.pos = new_point(250, 520);
	env->editor.hud.s_floor.color = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.t_color, env);
	env->editor.hud.s_floor.color.pos = new_point(250, 560);
	env->editor.hud.s_floor.t_color.pos = new_point(250, 560);
	env->editor.hud.s_floor.intensity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.t_intensity, env);
	env->editor.hud.s_floor.intensity.pos = new_point(250, 600);
	env->editor.hud.s_floor.t_intensity.pos = new_point(250, 600);
	env->editor.hud.s_floor.gravity = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.s_floor.t_gravity, env);
	env->editor.hud.s_floor.gravity.pos = new_point(250, 640);
	env->editor.hud.s_floor.t_gravity.pos = new_point(250, 640);
}

void	init_floor_general_buttons(t_env *env)
{
	env->editor.hud.g_floor.height = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_height, env);
	env->editor.hud.g_floor.height.pos = new_point(250, 520);
	env->editor.hud.g_floor.t_height.pos = new_point(250, 520);
	env->editor.hud.g_floor.slope = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_slope, env);
	env->editor.hud.g_floor.slope.pos = new_point(250, 560);
	env->editor.hud.g_floor.t_slope.pos = new_point(250, 560);
	env->editor.hud.g_floor.texture = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_texture, env);
	env->editor.hud.g_floor.texture.pos = new_point(250, 600);
	env->editor.hud.g_floor.t_texture.pos = new_point(250, 600);
	env->editor.hud.g_floor.texture_scale_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_texture_scale_x, env);
	env->editor.hud.g_floor.texture_scale_x.pos = new_point(250, 640);
	env->editor.hud.g_floor.t_texture_scale_x.pos = new_point(250, 640);
	env->editor.hud.g_floor.texture_scale_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_texture_scale_y, env);
	env->editor.hud.g_floor.texture_scale_y.pos = new_point(250, 680);
	env->editor.hud.g_floor.t_texture_scale_y.pos = new_point(250, 680);
	env->editor.hud.g_floor.texture_align_x = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_texture_align_x, env);
	env->editor.hud.g_floor.texture_align_x.pos = new_point(250, 720);
	env->editor.hud.g_floor.t_texture_align_x.pos = new_point(250, 720);
	env->editor.hud.g_floor.texture_align_y = new_hud_button(WHEN_DOWN, &change_var,
	&env->editor.hud.g_floor.t_texture_align_y, env);
	env->editor.hud.g_floor.texture_align_y.pos = new_point(250, 760);
	env->editor.hud.g_floor.t_texture_align_y.pos = new_point(250, 760);
}