/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_enemy_tab_button.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:58:23 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 11:18:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_enemy_sprite_buttons(t_env *env)
{
	(void)env;
}

void	init_enemy_sector_buttons(t_env *env)
{
	env->editor.hud.s_enemy.brightness = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_enemy.t_brightness, env);
	env->editor.hud.s_enemy.brightness.pos = new_point(250, 520);
	env->editor.hud.s_enemy.t_brightness.pos = new_point(250, 520);
	env->editor.hud.s_enemy.color = new_hud_button(ON_RELEASE,
	&change_color, &env->editor.hud.s_enemy.t_color, env);
	env->editor.hud.s_enemy.color.pos = new_point(250, 560);
	env->editor.hud.s_enemy.t_color.pos = new_point(250, 560);
	env->editor.hud.s_enemy.intensity = new_hud_button(ON_RELEASE,
	&change_brightness_or_intensity,
	&env->editor.hud.s_enemy.t_intensity, env);
	env->editor.hud.s_enemy.intensity.pos = new_point(250, 600);
	env->editor.hud.s_enemy.t_intensity.pos = new_point(250, 600);
	env->editor.hud.s_enemy.gravity = new_hud_button(ON_RELEASE,
	&change_gravity, &env->editor.hud.s_enemy.t_gravity, env);
	env->editor.hud.s_enemy.gravity.pos = new_point(250, 640);
	env->editor.hud.s_enemy.t_gravity.pos = new_point(250, 640);
}

void	init_enemy_general_buttons(t_env *env)
{
	env->editor.hud.g_enemy.pos_x = new_hud_pos_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_enemy.t_pos_x, env);
	env->editor.hud.g_enemy.pos_x.pos = new_point(170, 520);
	env->editor.hud.g_enemy.t_pos_x.pos = new_point(170, 520);
	env->editor.hud.g_enemy.pos_y = new_hud_pos_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_enemy.t_pos_y, env);
	env->editor.hud.g_enemy.pos_y.pos = new_point(250, 520);
	env->editor.hud.g_enemy.t_pos_y.pos = new_point(250, 520);
	env->editor.hud.g_enemy.pos_z = new_hud_pos_button(ON_RELEASE,
	&change_var, &env->editor.hud.g_enemy.t_pos_z, env);
	env->editor.hud.g_enemy.pos_z.pos = new_point(330, 520);
	env->editor.hud.g_enemy.t_pos_z.pos = new_point(330, 520);
	env->editor.hud.g_enemy.health = new_hud_button(ON_RELEASE,
	&change_health, &env->editor.hud.g_enemy.t_health, env);
	env->editor.hud.g_enemy.health.pos = new_point(250, 560);
	env->editor.hud.g_enemy.t_health.pos = new_point(250, 560);
	env->editor.hud.g_enemy.speed = new_hud_button(ON_RELEASE,
	&change_speed, &env->editor.hud.g_enemy.t_speed, env);
	env->editor.hud.g_enemy.speed.pos = new_point(250, 600);
	env->editor.hud.g_enemy.t_speed.pos = new_point(250, 600);
	env->editor.hud.g_enemy.scale = new_hud_button(ON_RELEASE,
	&change_enemy_scale, &env->editor.hud.g_enemy.t_scale, env);
	env->editor.hud.g_enemy.scale.pos = new_point(250, 640);
	env->editor.hud.g_enemy.t_scale.pos = new_point(250, 640);
	env->editor.hud.g_enemy.damage = new_hud_button(ON_RELEASE,
	&change_enemy_damage, &env->editor.hud.g_enemy.t_damage, env);
	env->editor.hud.g_enemy.damage.pos = new_point(250, 680);
	env->editor.hud.g_enemy.t_damage.pos = new_point(250, 680);
	env->editor.hud.g_enemy.angle = new_hud_button(ON_RELEASE,
	&change_angle, &env->editor.hud.g_enemy.t_angle, env);
	env->editor.hud.g_enemy.angle.pos = new_point(250, 720);
	env->editor.hud.g_enemy.t_angle.pos = new_point(250, 720);
}
