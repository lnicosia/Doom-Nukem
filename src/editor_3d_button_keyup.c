/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_button_keyup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:44:31 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 17:57:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	wall_buttons_up(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.hud.s_wall.brightness, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_wall.color, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_wall.intensity, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_wall.gravity, env))
			return (-1);
	}
	else if (env->editor.general_tab.state == DOWN)
	{
		if (wall_general_tab_keyup(env))
			return (-1);
	}
	return (0);
}

int	floor_general_tab_keyup(t_env *env)
{
	if (button_keyup(&env->editor.hud.g_floor.height, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.slope, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.texture_scale_x, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.texture_scale_y, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.texture_align_x, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.texture_align_y, env))
		return (-1);
	if (button_keyup(&env->editor.previous_slope_swap, env))
		return (-1);
	if (button_keyup(&env->editor.next_slope_swap, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_floor.add_sprite, env))
		return (-1);
	return (0);
}

int	floor_buttons_up(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.hud.s_floor.brightness, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_floor.color, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_floor.intensity, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_floor.gravity, env))
			return (-1);
	}
	else if (env->editor.general_tab.state == DOWN)
	{
		if (floor_general_tab_keyup(env))
			return (-1);
	}
	return (0);
}

int	ceiling_general_tab_keyup(t_env *env)
{
	if (button_keyup(&env->editor.hud.g_ceiling.height, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.slope, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.texture_scale_x, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.texture_scale_y, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.texture_align_x, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.texture_align_y, env))
		return (-1);
	if (button_keyup(&env->editor.previous_slope_swap, env))
		return (-1);
	if (button_keyup(&env->editor.next_slope_swap, env))
		return (-1);
	if (button_keyup(&env->editor.hud.g_ceiling.add_sprite, env))
		return (-1);
	return (0);
}

int	ceiling_buttons_up(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.hud.s_ceiling.brightness, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_ceiling.color, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_ceiling.intensity, env))
			return (-1);
		if (button_keyup(&env->editor.hud.s_ceiling.gravity, env))
			return (-1);
	}
	else if (env->editor.general_tab.state == DOWN)
	{
		if (ceiling_general_tab_keyup(env))
			return (-1);
	}
	return (0);
}
