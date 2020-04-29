/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_button_keys2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:56:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:56:46 by lnicosia         ###   ########.fr       */
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
		if (button_keys(&env->editor.hud.g_object.pos_z, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_object.health, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_object.scale, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_object.damage, env))
			return (-1);
		if (button_keys(&env->editor.hud.g_object.angle, env))
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
		if (button_keys(&env->editor.hud.sp_wall_sprite.add_sprite, env))
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

int	wall_general_tab_keys(t_env *env)
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
	if (button_keys(&env->editor.hud.g_wall.portal, env))
		return (-1);
	if (button_keys(&env->editor.hud.g_wall.add_sprite, env))
		return (-1);
	return (0);
}
