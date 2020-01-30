/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_keyup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:59:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/30 12:26:09 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	enemy_buttons_up(t_env *env)
{
	button_keyup(&env->editor.current_enemy_selection, env);
	button_keyup(&env->editor.enemy_background, env);
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.s_enemy.brightness, env);
		button_keyup(&env->editor.hud.s_enemy.color, env);
		button_keyup(&env->editor.hud.s_enemy.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.g_enemy.pos_x, env);
		button_keyup(&env->editor.hud.g_enemy.pos_y, env);
		button_keyup(&env->editor.hud.g_enemy.pos_z, env);
		button_keyup(&env->editor.hud.g_enemy.health, env);
		button_keyup(&env->editor.hud.g_enemy.speed, env);
	}
}

void	player_buttons_up(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.s_player.brightness, env);
		button_keyup(&env->editor.hud.s_player.color, env);
		button_keyup(&env->editor.hud.s_player.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.g_player.pos_x, env);
		button_keyup(&env->editor.hud.g_player.pos_y, env);
		button_keyup(&env->editor.hud.g_player.pos_z, env);
		button_keyup(&env->editor.hud.g_player.health, env);
		button_keyup(&env->editor.hud.g_player.armor, env);
		button_keyup(&env->editor.hud.g_player.speed, env);
	}
}

void	sector_buttons_up(t_env *env)
{
	if (env->editor.general_tab.state == DOWN)
	{
		button_keyup(&env->editor.hud.g_sector.brightness, env);
		button_keyup(&env->editor.hud.g_sector.color, env);
		button_keyup(&env->editor.hud.g_sector.intensity, env);
		button_keyup(&env->editor.hud.g_sector.floor, env);
		button_keyup(&env->editor.hud.g_sector.ceiling, env);
		button_keyup(&env->editor.hud.g_sector.floor_slope, env);
		button_keyup(&env->editor.hud.g_sector.ceiling_slope, env);
	}
}