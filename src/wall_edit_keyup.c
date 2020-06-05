/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_edit_keyup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:00:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:00:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		wall_edit_keyup3(t_env *env)
{
	if (((env->sdl.event.key.keysym.sym == SDLK_MINUS
		|| env->sdl.event.key.keysym.sym == SDLK_EQUALS)
		&& env->sdl.event.type == SDL_KEYUP)
		&& (env->editor.selected_wall != -1 || env->selected_ceiling != -1
		|| env->selected_floor != -1)
		&& env->editor.selected_wall_sprite == -1
		&& env->selected_floor_sprite == -1
		&& env->selected_ceiling_sprite == -1)
	{
		if (change_textures_scales_keyup(env))
			return (-1);
	}
	if (slopes_keyup(env))
		return (-1);
	return (0);
}

int		wall_edit_keyup2(t_env *env)
{
	if (((env->sdl.event.key.keysym.sym == SDLK_PAGEUP
		|| env->sdl.event.key.keysym.sym == SDLK_PAGEDOWN)
		&& env->sdl.event.type == SDL_KEYUP)
		&& (env->editor.selected_wall != -1 || env->selected_ceiling != -1
		|| env->selected_floor != -1))
	{
		if (change_walls_texture_keyup(env))
			return (-1);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_t
		&& env->sdl.event.type == SDL_KEYUP
		&& (env->editor.selected_wall != -1 || env->selected_ceiling != -1
		|| env->selected_floor != -1))
	{
		if (change_target_texture(env))
			return (-1);
	}
	if (env->editor.in_game && (env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1
		|| env->selected_floor_sprite != -1))
		editor_wall_sprites_keyup(env);
	return (wall_edit_keyup3(env));
}

int		wall_edit_keyup(t_env *env)
{
	if (env->options.editor_options)
		return (0);
	if ((env->selected_ceiling != -1 || env->selected_floor != -1)
		&& ((env->sdl.event.key.keysym.sym == SDLK_KP_PLUS
		|| env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
		&& env->sdl.event.type == SDL_KEYUP)
		&& !env->inputs.shift)
		change_ceiling_floor_height_keyup(env);
	if (((env->sdl.event.key.keysym.sym == SDLK_PERIOD
		|| env->sdl.event.key.keysym.sym == SDLK_COMMA)
		&& env->sdl.event.type == SDL_KEYUP)
		&& (env->editor.selected_wall != -1 || env->selected_ceiling != -1
		|| env->selected_floor != -1))
	{
		if (change_texture_alignement_keyup(env))
			return (-1);
	}
	return (wall_edit_keyup2(env));
}
