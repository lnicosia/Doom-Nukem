/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_button_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:44:49 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 19:04:55 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	object_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_object.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_object.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_object.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_object.gravity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_object.health, env))
			return (-1);
	}
	return (0);
}

int	wall_sprite_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_wall_sprite.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall_sprite.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall_sprite.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall_sprite.gravity, env))
			return (-1);
	}
	if (env->editor.sprite_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.sp_wall_sprite.pos_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.sp_wall_sprite.pos_y, env))
			return (-1);
		if (button_keys(&env->editor.hud.sp_wall_sprite.scale_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.sp_wall_sprite.scale_y, env))
			return (-1);
	}
	return (0);
}

int	ceiling_sprite_buttons(t_env *env)
{
	if (button_keys(&env->editor.hud.sp_ceiling_sprite.pos_x, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_ceiling_sprite.pos_y, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_ceiling_sprite.scale_x, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_ceiling_sprite.scale_y, env))
		return (-1);
	return (0);
}

int	floor_sprite_buttons(t_env *env)
{
	if (button_keys(&env->editor.hud.sp_floor_sprite.pos_x, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_floor_sprite.pos_y, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_floor_sprite.scale_x, env))
		return (-1);
	if (button_keys(&env->editor.hud.sp_floor_sprite.scale_y, env))
		return (-1);
	return (0);
}

int	wall_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_wall.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_wall.gravity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.next_wall, env))
			return (-1);
		if (button_keys(&env->editor.previous_wall, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_wall.texture_scale_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_wall.texture_scale_y, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_wall.texture_align_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_wall.texture_align_y, env))
			return (-1);
	}
	return (0);
}

int	floor_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_floor.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_floor.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_floor.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_floor.gravity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_floor.height, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_floor.slope, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_floor.texture_scale_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_floor.texture_scale_y, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_floor.texture_align_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_floor.texture_align_y, env))
			return (-1);
		if (button_keys(&env->editor.previous_slope_swap, env))
			return (-1);
		if (button_keys(&env->editor.next_slope_swap, env))
			return (-1);
	}
	return (0);
}

int	ceiling_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.s_ceilling.brightness, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_ceilling.color, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_ceilling.intensity, env))
			return (-1);
		if (button_keys(&env->editor.hud.s_ceilling.gravity, env))
			return (-1);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		if (button_keys(&env->editor.hud.g_ceilling.height, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_ceilling.slope, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_ceilling.texture_scale_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_ceilling.texture_scale_y, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_ceilling.texture_align_x, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_ceilling.texture_align_y, env))
			return (-1);
		if (button_keys(&env->editor.previous_slope_swap, env))
			return (-1);
		if (button_keys(&env->editor.next_slope_swap, env))
			return (-1);
	}
	return (0);
}
