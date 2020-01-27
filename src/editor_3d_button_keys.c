/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_button_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:44:49 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/24 17:05:41 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	wall_sprite_buttons(t_env *env)
{
	button_keys(&env->editor.hud.sp_wall_sprite.num, env);
	button_keys(&env->editor.hud.sp_wall_sprite.pos_x, env);
	button_keys(&env->editor.hud.sp_wall_sprite.pos_y, env);
	button_keys(&env->editor.hud.sp_wall_sprite.scale_x, env);
	button_keys(&env->editor.hud.sp_wall_sprite.scale_y, env);
}

void	ceiling_sprite_buttons(t_env *env)
{
	button_keys(&env->editor.hud.sp_ceiling_sprite.num, env);
	button_keys(&env->editor.hud.sp_ceiling_sprite.pos_x, env);
	button_keys(&env->editor.hud.sp_ceiling_sprite.pos_y, env);
	button_keys(&env->editor.hud.sp_ceiling_sprite.scale_x, env);
	button_keys(&env->editor.hud.sp_ceiling_sprite.scale_y, env);
}

void	floor_sprite_buttons(t_env *env)
{
	button_keys(&env->editor.hud.sp_floor_sprite.num, env);
	button_keys(&env->editor.hud.sp_floor_sprite.pos_x, env);
	button_keys(&env->editor.hud.sp_floor_sprite.pos_y, env);
	button_keys(&env->editor.hud.sp_floor_sprite.scale_x, env);
	button_keys(&env->editor.hud.sp_floor_sprite.scale_y, env);
}

void	wall_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.s_wall.brightness, env);
		button_keys(&env->editor.hud.s_wall.color, env);
		button_keys(&env->editor.hud.s_wall.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_wall.texture, env);
		button_keys(&env->editor.hud.g_wall.texture_scale_x, env);
		button_keys(&env->editor.hud.g_wall.texture_scale_y, env);
		button_keys(&env->editor.hud.g_wall.texture_align_x, env);
		button_keys(&env->editor.hud.g_wall.texture_align_y, env);
	}
}

void	floor_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.s_floor.brightness, env);
		button_keys(&env->editor.hud.s_floor.color, env);
		button_keys(&env->editor.hud.s_floor.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_floor.height, env);
		button_keys(&env->editor.hud.g_floor.slope, env);
		button_keys(&env->editor.hud.g_floor.texture, env);
		button_keys(&env->editor.hud.g_floor.texture_scale_x, env);
		button_keys(&env->editor.hud.g_floor.texture_scale_y, env);
		button_keys(&env->editor.hud.g_floor.texture_align_x, env);
		button_keys(&env->editor.hud.g_floor.texture_align_y, env);
	}
}

void	ceiling_buttons(t_env *env)
{
	if (env->editor.sector_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.s_ceilling.brightness, env);
		button_keys(&env->editor.hud.s_ceilling.color, env);
		button_keys(&env->editor.hud.s_ceilling.intensity, env);
	}
	if (env->editor.general_tab.state == DOWN)
	{
		button_keys(&env->editor.hud.g_ceilling.height, env);
		button_keys(&env->editor.hud.g_ceilling.slope, env);
		button_keys(&env->editor.hud.g_ceilling.texture, env);
		button_keys(&env->editor.hud.g_ceilling.texture_scale_x, env);
		button_keys(&env->editor.hud.g_ceilling.texture_scale_y, env);
		button_keys(&env->editor.hud.g_ceilling.texture_align_x, env);
		button_keys(&env->editor.hud.g_ceilling.texture_align_y, env);
	}
}