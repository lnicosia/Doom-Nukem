/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_object_tab_button.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:54:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 12:31:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_object_sector_buttons(t_env *env)
{
	env->editor.hud.s_object.brightness = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.s_object.t_brightness, env);
	env->editor.hud.s_object.brightness.pos = new_point(250, 520);
	env->editor.hud.s_object.t_brightness.pos = new_point(250, 520);
	env->editor.hud.s_object.color = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.s_object.t_color, env);
	env->editor.hud.s_object.color.pos = new_point(250, 560);
	env->editor.hud.s_object.t_color.pos = new_point(250, 560);
	env->editor.hud.s_object.intensity = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.s_object.t_intensity, env);
	env->editor.hud.s_object.intensity.pos = new_point(250, 600);
	env->editor.hud.s_object.t_intensity.pos = new_point(250, 600);
	env->editor.hud.s_object.gravity = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.s_object.t_gravity, env);
	env->editor.hud.s_object.gravity.pos = new_point(250, 640);
	env->editor.hud.s_object.t_gravity.pos = new_point(250, 640);
}

void	init_object_general_buttons(t_env *env)
{
	env->editor.hud.g_object.pos_x = new_hud_pos_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.g_object.t_pos_x, env);
	env->editor.hud.g_object.pos_x.pos = new_point(170, 520);
	env->editor.hud.g_object.t_pos_x.pos = new_point(170, 520);
	env->editor.hud.g_object.pos_y = new_hud_pos_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.g_object.t_pos_y, env);
	env->editor.hud.g_object.pos_y.pos = new_point(250, 520);
	env->editor.hud.g_object.t_pos_y.pos = new_point(250, 520);
	env->editor.hud.g_object.pos_z = new_hud_pos_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.g_object.t_pos_z, env);
	env->editor.hud.g_object.pos_z.pos = new_point(330, 520);
	env->editor.hud.g_object.t_pos_z.pos = new_point(330, 520);
	env->editor.hud.g_object.health = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.g_object.t_health, env);
	env->editor.hud.g_object.health.pos = new_point(250, 560);
	env->editor.hud.g_object.t_health.pos = new_point(250, 560);
	env->editor.hud.g_object.speed = new_hud_button(ON_RELEASE
	, &change_var,
	&env->editor.hud.g_object.t_speed, env);
	env->editor.hud.g_object.speed.pos = new_point(250, 600);
	env->editor.hud.g_object.t_speed.pos = new_point(250, 600);
}