/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:55:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 14:43:18 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	enemy_buttons(t_env *env)
{
	button_keys(&env->editor.current_enemy_selection, env);
	button_keys(&env->editor.enemy_background, env);
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.s_enemy.brightness, env);
		button_keys(&env->editor.hud.s_enemy.color, env);
		button_keys(&env->editor.hud.s_enemy.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_enemy.pos_x, env);
		button_keys(&env->editor.hud.g_enemy.pos_y, env);
		button_keys(&env->editor.hud.g_enemy.pos_z, env);
		button_keys(&env->editor.hud.g_enemy.health, env);
		button_keys(&env->editor.hud.g_enemy.speed, env);
	}
}

void	player_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.s_player.brightness, env);
		button_keys(&env->editor.hud.s_player.color, env);
		button_keys(&env->editor.hud.s_player.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_player.health, env);
		button_keys(&env->editor.hud.g_player.armor, env);
		button_keys(&env->editor.hud.g_player.speed, env);
	}
}

void	sector_buttons(t_env *env)
{
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_sector.brightness, env);
		button_keys(&env->editor.hud.g_sector.color, env);
		button_keys(&env->editor.hud.g_sector.intensity, env);
		button_keys(&env->editor.hud.g_sector.floor, env);
		button_keys(&env->editor.hud.g_sector.ceiling, env);
		button_keys(&env->editor.hud.g_sector.floor_slope, env);
		button_keys(&env->editor.hud.g_sector.ceiling_slope, env);
	}
}