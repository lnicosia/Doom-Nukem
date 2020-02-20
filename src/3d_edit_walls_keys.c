/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_walls_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:02:17 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 14:25:11 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_walls_texture(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->editor.key_delay > INPUT_DELAY)
	{
		if (env->selected_floor != -1)
			sector = &env->sectors[env->selected_floor];
		if (env->editor.selected_wall != -1)
			sector = &env->sectors[env->editor.selected_sector];
		if (env->selected_ceiling != -1)
			sector = &env->sectors[env->selected_ceiling];
		if (env->inputs.down)
		{
			if (decrease_wall_texture_number(env, sector))
				return (-1);
		}
		if (env->inputs.up)
		{
			if (increase_wall_texture_number(env, sector))
				return (-1);
		}
	}
	return (0);
}


int		change_slopes(t_env *env)
{
	if (env->editor.key_delay >INPUT_DELAY
	|| env->editor.keyup_allowed)
	{
		if (env->inputs.plus
		|| env->sdl.event.key.keysym.sym == SDLK_KP_PLUS)
		{
			if (increase_slope(env))
				return (-1);
		}
		else if (env->inputs.minus
		|| env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
		{
			if (decrease_slope(env))
				return (-1);
		}
	}
	return (0);
}

int		slope_keys(t_env *env)
{
	if (env->editor.key_delay > INPUT_DELAY)
	{
		if (env->inputs.ctrl && (env->inputs.plus || env->inputs.minus))
		{
			if (change_slopes(env))
				return (-1);
		}
		if (env->inputs.ctrl &&
		(env->inputs.left || env->inputs.right)
		&& (env->selected_ceiling != -1 || env->selected_floor !=-1))
			if(change_slope_start(env))
				return (-1);
	}
	return (0);
}

int		change_texture_alignement(t_env *env)
{
	if (env->editor.in_game && (env->editor.selected_wall != -1
	|| env->selected_floor != -1 || env->selected_ceiling != -1)
	&& env->editor.key_delay > INPUT_DELAY)
	{
		if (env->inputs.comma
		&& env->selected_floor_sprite == -1
		&& env->selected_ceiling_sprite == -1
		&& env->selected_wall_sprite_sprite == -1)
		{
			if (left_walls_texture_align(env))
				return (-1);
		}
		if (env->inputs.period
		&& env->selected_floor_sprite == -1
		&& env->selected_ceiling_sprite == -1
		&& env->selected_wall_sprite_sprite == -1)
		{
			if (right_walls_texture_align(env))
				return (-1);
		}
	}
	return (0);
}

int		wall_edit_keys(t_env *env)
{
	if (change_texture_alignement(env))
		return (-1);
	if (change_textures_scales(env))
		return (-1);
	if (env->editor.in_game && (env->selected_wall_sprite_sprite != -1
	|| env->selected_ceiling_sprite != -1 || env->selected_floor_sprite != -1))
		editor_wall_sprites_keys(env);
	if ((env->inputs.plus || env->inputs.minus)
	&& (env->selected_ceiling || env->selected_floor))
	{
		change_ceiling_floor_height(env);
		if (env->selected_floor != -1)
			update_sector_entities_z(env, env->selected_floor);
	}
	if (change_walls_texture(env))
		return (-1);
	if (slope_keys(env))
		return (-1);
	return (0);
}