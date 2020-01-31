/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_env_enemy_buttons.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:59:25 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/22 15:27:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_enemy_sprite_env(t_env *env)
{
	(void)env;
}

void	init_enemy_sector_env(t_env *env)
{
	env->editor.hud.s_enemy.t_brightness.env = env;
	env->editor.hud.s_enemy.t_brightness.pos = new_point(0, 0);
	env->editor.hud.s_enemy.t_brightness.type = INT;
	env->editor.hud.s_enemy.t_color.env = env;
	env->editor.hud.s_enemy.t_color.pos = new_point(0, 0);
	env->editor.hud.s_enemy.t_color.type = INT;
	env->editor.hud.s_enemy.t_intensity.env = env;
	env->editor.hud.s_enemy.t_intensity.pos = new_point(0, 0);
	env->editor.hud.s_enemy.t_intensity.type = INT;
	env->editor.hud.s_enemy.t_gravity.env = env;
	env->editor.hud.s_enemy.t_gravity.pos = new_point(0, 0);
	env->editor.hud.s_enemy.t_gravity.type = INT;
}

void	init_enemy_general_env(t_env *env)
{
	env->editor.hud.g_enemy.t_pos_x.env = env;
	env->editor.hud.g_enemy.t_pos_x.pos = new_point(0, 0);
	env->editor.hud.g_enemy.t_pos_x.type = DOUBLE;
	env->editor.hud.g_enemy.t_pos_y.env = env;
	env->editor.hud.g_enemy.t_pos_y.pos = new_point(0, 0);
	env->editor.hud.g_enemy.t_pos_y.type = DOUBLE;
	env->editor.hud.g_enemy.t_pos_z.env = env;
	env->editor.hud.g_enemy.t_pos_z.pos = new_point(0, 0);
	env->editor.hud.g_enemy.t_pos_z.type = INT;
	env->editor.hud.g_enemy.t_health.env = env;
	env->editor.hud.g_enemy.t_health.pos = new_point(0, 0);
	env->editor.hud.g_enemy.t_health.type = DOUBLE;
	env->editor.hud.g_enemy.t_speed.env = env;
	env->editor.hud.g_enemy.t_speed.pos = new_point(0, 0);
	env->editor.hud.g_enemy.t_speed.type = DOUBLE;
}