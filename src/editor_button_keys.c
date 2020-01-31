/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_button_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:55:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 18:22:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	enemy_buttons(t_env *env)
{
	if (button_keys(&env->editor.current_enemy_selection, env))
		return (-1);
	if (button_keys(&env->editor.enemy_background, env))
		return (-1);
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_enemy.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_enemy.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_enemy.intensity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_enemy.pos_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_enemy.pos_y, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_enemy.pos_z, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_enemy.health, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_enemy.speed, env))
			return (-1);
	}
	return (0);
}

int	player_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_player.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_player.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_player.intensity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_player.health, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_player.armor, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_player.speed, env))
			return (-1);
	}
	return (0);
}

int	sector_buttons(t_env *env)
{
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_sector.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.floor, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.ceiling, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.floor_slope, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_sector.ceiling_slope, env))
			return (-1);
	}
	return (0);
}
