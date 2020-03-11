/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tab_button.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:32:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 12:27:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


void	init_wall_sprite_sector_buttons(t_env *env)
{
	env->editor.hud.s_wall_sprite.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_wall_sprite.t_brightness, env);
	env->editor.hud.s_wall_sprite.brightness.pos = new_point(170, 520);
	env->editor.hud.s_wall_sprite.t_brightness.pos = new_point(170, 520);
	env->editor.hud.s_wall_sprite.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.s_wall_sprite.t_color, env);
	env->editor.hud.s_wall_sprite.color.pos = new_point(170, 560);
	env->editor.hud.s_wall_sprite.t_color.pos = new_point(170, 560);
	env->editor.hud.s_wall_sprite.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_wall_sprite.t_intensity, env);
	env->editor.hud.s_wall_sprite.intensity.pos = new_point(170, 600);
	env->editor.hud.s_wall_sprite.t_intensity.pos = new_point(170, 600);
	env->editor.hud.s_wall_sprite.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.s_wall_sprite.t_gravity, env);
	env->editor.hud.s_wall_sprite.gravity.pos = new_point(170, 640);
	env->editor.hud.s_wall_sprite.t_gravity.pos = new_point(170, 640);
}

void	init_wall_sprite_buttons(t_env *env)
{
	env->editor.hud.sp_wall_sprite.pos_x = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.sp_wall_sprite.t_pos_x, env);
	env->editor.hud.sp_wall_sprite.pos_x.pos = new_point(170, 560);
	env->editor.hud.sp_wall_sprite.t_pos_x.pos = new_point(170, 560);
	env->editor.hud.sp_wall_sprite.pos_y = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.sp_wall_sprite.t_pos_y, env);
	env->editor.hud.sp_wall_sprite.pos_y.pos = new_point(170, 600);
	env->editor.hud.sp_wall_sprite.t_pos_y.pos = new_point(170, 600);
	env->editor.hud.sp_wall_sprite.scale_x = new_hud_button(ON_RELEASE,
	&change_wall_sprite_scale, &env->editor.hud.sp_wall_sprite.t_scale_x, env);
	env->editor.hud.sp_wall_sprite.scale_x.pos = new_point(170, 640);
	env->editor.hud.sp_wall_sprite.t_scale_x.pos = new_point(170, 640);
	env->editor.hud.sp_wall_sprite.scale_y = new_hud_button(ON_RELEASE,
	&change_wall_sprite_scale, &env->editor.hud.sp_wall_sprite.t_scale_y, env);
	env->editor.hud.sp_wall_sprite.scale_y.pos = new_point(170, 680);
	env->editor.hud.sp_wall_sprite.t_scale_y.pos = new_point(170, 680);
	env->editor.hud.sp_wall_sprite.add_sprite = new_image_button(ON_RELEASE,
	&add_sprite, env, env);
	env->editor.hud.sp_wall_sprite.add_sprite.str = "ADD SPRITE";
	env->editor.hud.sp_wall_sprite.add_sprite.pos = new_point(230, 820);
	env->editor.hud.sp_wall_sprite.t_add_sprite.pos = new_point(230, 820);
}

void	init_wall_sector_buttons(t_env *env)
{
	env->editor.hud.s_wall.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_wall.t_brightness, env);
	env->editor.hud.s_wall.brightness.pos = new_point(170, 520);
	env->editor.hud.s_wall.t_brightness.pos = new_point(170, 520);
	env->editor.hud.s_wall.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.s_wall.t_color, env);
	env->editor.hud.s_wall.color.pos = new_point(170, 560);
	env->editor.hud.s_wall.t_color.pos = new_point(170, 560);
	env->editor.hud.s_wall.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_wall.t_intensity, env);
	env->editor.hud.s_wall.intensity.pos = new_point(170, 600);
	env->editor.hud.s_wall.t_intensity.pos = new_point(170, 600);
	env->editor.hud.s_wall.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.s_wall.t_gravity, env);
	env->editor.hud.s_wall.gravity.pos = new_point(170, 640);
	env->editor.hud.s_wall.t_gravity.pos = new_point(170, 640);
}

void	init_wall_general_buttons(t_env *env)
{
	env->editor.hud.g_wall.texture_scale_x = new_hud_button(ON_RELEASE,
	&change_texture_scale, &env->editor.hud.g_wall.t_texture_scale_x, env);
	env->editor.hud.g_wall.texture_scale_x.pos = new_point(170, 560);
	env->editor.hud.g_wall.t_texture_scale_x.pos = new_point(170, 560);
	env->editor.hud.g_wall.texture_scale_y = new_hud_button(ON_RELEASE,
	&change_texture_scale, &env->editor.hud.g_wall.t_texture_scale_y, env);
	env->editor.hud.g_wall.texture_scale_y.pos = new_point(170, 600);
	env->editor.hud.g_wall.t_texture_scale_y.pos = new_point(170, 600);
	env->editor.hud.g_wall.texture_align_x = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_wall.t_texture_align_x, env);
	env->editor.hud.g_wall.texture_align_x.pos = new_point(170, 640);
	env->editor.hud.g_wall.t_texture_align_x.pos = new_point(170, 640);
	env->editor.hud.g_wall.texture_align_y = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_wall.t_texture_align_y, env);
	env->editor.hud.g_wall.texture_align_y.pos = new_point(170, 680);
	env->editor.hud.g_wall.t_texture_align_y.pos = new_point(170, 680);
	env->editor.hud.g_wall.portal = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_wall.t_portal, env);
	env->editor.hud.g_wall.portal.pos = new_point(170, 720);
	env->editor.hud.g_wall.t_portal.pos = new_point(170, 720);
	env->editor.hud.g_wall.add_sprite = new_image_button(ON_RELEASE,
	&add_sprite, env, env);
	env->editor.hud.g_wall.add_sprite.str = "ADD SPRITE";
	env->editor.hud.g_wall.add_sprite.pos = new_point(230, 820);
	env->editor.hud.g_wall.t_add_sprite.pos = new_point(230, 820);
}
