/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_env_object_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:55:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 15:55:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_object_sprite_env(t_env *env)
{
	(void)env;
}

void	init_object_sector_env(t_env *env)
{
	env->editor.hud.s_object.t_brightness.env = env;
	env->editor.hud.s_object.t_brightness.pos = new_point(0, 0);
	env->editor.hud.s_object.t_brightness.type = INT;
	env->editor.hud.s_object.t_color.env = env;
	env->editor.hud.s_object.t_color.pos = new_point(0, 0);
	env->editor.hud.s_object.t_color.type = INT;
	env->editor.hud.s_object.t_intensity.env = env;
	env->editor.hud.s_object.t_intensity.pos = new_point(0, 0);
	env->editor.hud.s_object.t_intensity.type = INT;
	env->editor.hud.s_object.t_gravity.env = env;
	env->editor.hud.s_object.t_gravity.pos = new_point(0, 0);
	env->editor.hud.s_object.t_gravity.type = INT;
}

void	init_object_general_env(t_env *env)
{
	env->editor.hud.g_object.t_pos_x.env = env;
	env->editor.hud.g_object.t_pos_x.pos = new_point(0, 0);
	env->editor.hud.g_object.t_pos_x.type = DOUBLE;
	env->editor.hud.g_object.t_pos_y.env = env;
	env->editor.hud.g_object.t_pos_y.pos = new_point(0, 0);
	env->editor.hud.g_object.t_pos_y.type = DOUBLE;
	env->editor.hud.g_object.t_pos_z.env = env;
	env->editor.hud.g_object.t_pos_z.pos = new_point(0, 0);
	env->editor.hud.g_object.t_pos_z.type = INT;
	env->editor.hud.g_object.t_health.env = env;
	env->editor.hud.g_object.t_health.pos = new_point(0, 0);
	env->editor.hud.g_object.t_health.type = DOUBLE;
	env->editor.hud.g_object.t_speed.env = env;
	env->editor.hud.g_object.t_speed.pos = new_point(0, 0);
	env->editor.hud.g_object.t_speed.type = DOUBLE;
}