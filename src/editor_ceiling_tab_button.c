/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tab_button.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 11:57:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_ceiling_sprite_buttons(t_env *env)
{
	env->editor.hud.sp_ceiling_sprite.pos_x = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.sp_ceiling_sprite.t_pos_x, env);
	env->editor.hud.sp_ceiling_sprite.pos_x.pos = new_point(170, 560);
	env->editor.hud.sp_ceiling_sprite.t_pos_x.pos = new_point(170, 560);
	env->editor.hud.sp_ceiling_sprite.pos_y = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.sp_ceiling_sprite.t_pos_y, env);
	env->editor.hud.sp_ceiling_sprite.pos_y.pos = new_point(170, 600);
	env->editor.hud.sp_ceiling_sprite.t_pos_y.pos = new_point(170, 600);
	env->editor.hud.sp_ceiling_sprite.scale_x = new_hud_button(ON_RELEASE,
	&change_var,
	&env->editor.hud.sp_ceiling_sprite.t_scale_x, env);
	env->editor.hud.sp_ceiling_sprite.scale_x.pos = new_point(170, 640);
	env->editor.hud.sp_ceiling_sprite.t_scale_x.pos = new_point(170, 640);
	env->editor.hud.sp_ceiling_sprite.scale_y = new_hud_button(ON_RELEASE,
	&change_var,
	&env->editor.hud.sp_ceiling_sprite.t_scale_y, env);
	env->editor.hud.sp_ceiling_sprite.scale_y.pos = new_point(170, 680);
	env->editor.hud.sp_ceiling_sprite.t_scale_y.pos = new_point(170, 680);
}

void	init_ceiling_sector_buttons(t_env *env)
{
	env->editor.hud.s_ceiling.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_ceiling.t_brightness, env);
	env->editor.hud.s_ceiling.brightness.pos = new_point(170, 520);
	env->editor.hud.s_ceiling.t_brightness.pos = new_point(170, 520);
	env->editor.hud.s_ceiling.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.s_ceiling.t_color, env);
	env->editor.hud.s_ceiling.color.pos = new_point(170, 560);
	env->editor.hud.s_ceiling.t_color.pos = new_point(170, 560);
	env->editor.hud.s_ceiling.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_ceiling.t_intensity, env);
	env->editor.hud.s_ceiling.intensity.pos = new_point(170, 600);
	env->editor.hud.s_ceiling.t_intensity.pos = new_point(170, 600);
	env->editor.hud.s_ceiling.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.s_ceiling.t_gravity, env);
	env->editor.hud.s_ceiling.gravity.pos = new_point(170, 640);
	env->editor.hud.s_ceiling.t_gravity.pos = new_point(170, 640);
}

void	init_ceiling_general_buttons2(t_env *env)
{
	env->editor.hud.g_ceiling.texture_align_x.pos = new_point(170, 720);
	env->editor.hud.g_ceiling.t_texture_align_x.pos = new_point(170, 720);
	env->editor.hud.g_ceiling.texture_align_y = new_hud_button(ON_RELEASE,
	&change_ceiling_texture_align,
	&env->editor.hud.g_ceiling.t_texture_align_y, env);
	env->editor.hud.g_ceiling.texture_align_y.pos = new_point(170, 760);
	env->editor.hud.g_ceiling.t_texture_align_y.pos = new_point(170, 760);
	env->editor.hud.g_ceiling.add_sprite = new_image_button(ON_RELEASE,
	&add_sprite, env, env);
	env->editor.hud.g_ceiling.add_sprite.str = "ADD SPRITE";
	env->editor.hud.g_ceiling.add_sprite.pos = new_point(230, 820);
	env->editor.hud.g_ceiling.t_add_sprite.pos = new_point(230, 820);
}

void	init_ceiling_general_buttons(t_env *env)
{
	env->editor.hud.g_ceiling.height = new_hud_button(ON_RELEASE,
	&change_ceiling_height, &env->editor.hud.g_ceiling.t_height, env);
	env->editor.hud.g_ceiling.height.pos = new_point(170, 520);
	env->editor.hud.g_ceiling.t_height.pos = new_point(170, 520);
	env->editor.hud.g_ceiling.slope = new_hud_button(ON_RELEASE,
	&change_ceiling_slope, &env->editor.hud.g_ceiling.t_slope, env);
	env->editor.hud.g_ceiling.slope.pos = new_point(170, 560);
	env->editor.hud.g_ceiling.t_slope.pos = new_point(170, 560);
	env->editor.hud.g_ceiling.texture_scale_x = new_hud_button(ON_RELEASE,
	&change_ceiling_texture_scale,
	&env->editor.hud.g_ceiling.t_texture_scale_x, env);
	env->editor.hud.g_ceiling.texture_scale_x.pos = new_point(170, 640);
	env->editor.hud.g_ceiling.t_texture_scale_x.pos = new_point(170, 640);
	env->editor.hud.g_ceiling.texture_scale_y = new_hud_button(ON_RELEASE,
	&change_ceiling_texture_scale,
	&env->editor.hud.g_ceiling.t_texture_scale_y, env);
	env->editor.hud.g_ceiling.texture_scale_y.pos = new_point(170, 680);
	env->editor.hud.g_ceiling.t_texture_scale_y.pos = new_point(170, 680);
	env->editor.hud.g_ceiling.texture_align_x = new_hud_button(ON_RELEASE,
	&change_ceiling_texture_align,
	&env->editor.hud.g_ceiling.t_texture_align_x, env);
	init_ceiling_general_buttons2(env);
}
