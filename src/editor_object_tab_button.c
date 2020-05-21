/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_object_tab_button.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:54:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 12:19:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_object_sector_buttons(t_env *env)
{
	env->editor.hud.s_object.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_object.t_brightness, env);
	env->editor.hud.s_object.brightness.pos = new_point(170, 520);
	env->editor.hud.s_object.t_brightness.pos = new_point(170, 520);
	env->editor.hud.s_object.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.s_object.t_color, env);
	env->editor.hud.s_object.color.pos = new_point(170, 560);
	env->editor.hud.s_object.t_color.pos = new_point(170, 560);
	env->editor.hud.s_object.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_object.t_intensity, env);
	env->editor.hud.s_object.intensity.pos = new_point(170, 600);
	env->editor.hud.s_object.t_intensity.pos = new_point(170, 600);
	env->editor.hud.s_object.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.s_object.t_gravity, env);
	env->editor.hud.s_object.gravity.pos = new_point(170, 640);
	env->editor.hud.s_object.t_gravity.pos = new_point(170, 640);
}

void	init_object_general_buttons2(t_env *env)
{
	env->editor.hud.g_object.damage.pos = new_point(170, 720);
	env->editor.hud.g_object.t_damage.pos = new_point(170, 720);
	env->editor.hud.g_object.angle = new_hud_button(ON_RELEASE,
	&change_angle, &env->editor.hud.g_object.t_angle, env);
	env->editor.hud.g_object.angle.pos = new_point(170, 760);
	env->editor.hud.g_object.t_angle.pos = new_point(170, 760);
}

void	init_object_general_buttons(t_env *env)
{
	env->editor.hud.g_object.pos_x = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_object.t_pos_x, env);
	env->editor.hud.g_object.pos_x.pos = new_point(170, 520);
	env->editor.hud.g_object.t_pos_x.pos = new_point(170, 520);
	env->editor.hud.g_object.pos_y = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_object.t_pos_y, env);
	env->editor.hud.g_object.pos_y.pos = new_point(170, 560);
	env->editor.hud.g_object.t_pos_y.pos = new_point(170, 560);
	env->editor.hud.g_object.pos_z = new_hud_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_object.t_pos_z, env);
	env->editor.hud.g_object.pos_z.pos = new_point(170, 600);
	env->editor.hud.g_object.t_pos_z.pos = new_point(170, 600);
	env->editor.hud.g_object.health = new_hud_button(ON_RELEASE,
	&change_health, &env->editor.hud.g_object.t_health, env);
	env->editor.hud.g_object.health.pos = new_point(170, 640);
	env->editor.hud.g_object.t_health.pos = new_point(170, 640);
	env->editor.hud.g_object.scale = new_hud_button(ON_RELEASE,
	&change_object_scale, &env->editor.hud.g_object.t_scale, env);
	env->editor.hud.g_object.scale.pos = new_point(170, 680);
	env->editor.hud.g_object.t_scale.pos = new_point(170, 680);
	env->editor.hud.g_object.damage = new_hud_button(ON_RELEASE,
	&change_object_damage, &env->editor.hud.g_object.t_damage, env);
	init_object_general_buttons2(env);
}
