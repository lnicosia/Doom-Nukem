/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_walls_keyup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:45:30 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/09 13:56:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_textures_scales_keyup(t_env *env)
{
	if (env->editor.keyup_allowed)
	{
		if (env->sdl.event.key.keysym.sym == SDLK_MINUS)
		{
			if (reduce_walls_texture_scale(env))
				return (-1);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_EQUALS)
		{
			if (increase_walls_texture_scale(env))
				return (-1);
		}
	}
	return (0);
}

int		change_walls_texture_keyup(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->editor.keyup_allowed)
	{
		if (env->selected_floor != -1)
			sector = &env->sectors[env->selected_floor];
		if (env->editor.selected_wall != -1)
			sector = &env->sectors[env->editor.selected_sector];
		if (env->selected_ceiling != -1)
			sector = &env->sectors[env->selected_ceiling];
		if (env->sdl.event.key.keysym.sym == SDLK_PAGEDOWN)
		{
			if (decrease_wall_texture_number(env, sector))
				return (-1);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_PAGEUP)
		{
			if (increase_wall_texture_number(env, sector))
				return (-1);
		}
	}
	return (0);
}

int		change_texture_alignement_keyup(t_env *env)
{
	if (env->editor.keyup_allowed)
	{
		if (env->sdl.event.key.keysym.sym == SDLK_COMMA
		&& env->selected_floor_sprite == -1
		&& env->selected_ceiling_sprite == -1
		&& env->selected_wall_sprite_sprite == -1)
		{
			if (left_walls_texture_align(env))
				return (-1);
		}
		if (env->sdl.event.key.keysym.sym == SDLK_PERIOD
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

int		slopes_keyup(t_env *env)
{
	if (env->editor.key_delay > INPUT_DELAY
	|| env->editor.keyup_allowed)
	{
		if (env->inputs.ctrl
		&& (env->sdl.event.key.keysym.sym == SDLK_KP_PLUS
		|| env->sdl.event.key.keysym.sym == SDLK_KP_MINUS))
		{
			if (change_slopes(env))
				return (-1);
		}
		if (env->inputs.ctrl
		&& (env->sdl.event.key.keysym.sym == SDLK_RIGHT
		|| env->sdl.event.key.keysym.sym == SDLK_LEFT)
		&& (env->selected_ceiling != -1 || env->selected_floor !=-1))
		{
			if (change_slope_start(env))
				return (-1);
		}
	}
	return (0);
}
