/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprites_keyup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:02:27 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/19 17:48:03 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_texture_scale(t_env *env, t_v2 *scale)
{
	if ((scale->x >= 0.1 && scale->x <= 100.0)
		&& (scale->y >= 0.1 && scale->y <= 100.0))
	{
		if ((env->inputs.minus1 && scale->x / 1.1 < 0.1)
		|| (env->sdl.event.key.keysym.sym == SDLK_MINUS
			&& scale->x / 1.1 < 0.1)
		|| (env->sdl.event.key.keysym.sym == SDLK_EQUALS
			&& scale->x * 1.1 > 100)
		|| (env->inputs.equals && scale->x * 1.1 > 100.0))
			return (0);
		if ((env->inputs.minus1 && scale->y / 1.1 < 0.1)
		|| (env->inputs.equals && scale->y * 1.1 > 100.0))
			return (0);
	}
	return (1);
}

int		check_sprite_pos(t_v2 *pos)
{
	if ((pos->x >= -1000 && pos->x <= 1000)
	&& (pos->y >= -1000 && pos->y <= 1000))
		return (1);
	return (0);
}

void	wall_sprites_keyup3(t_env *env, t_v2 *scale)
{
	if (env->sdl.event.key.keysym.sym == SDLK_MINUS
		&& check_texture_scale(env, scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			scale->x /= 1.1;
			scale->y /= 1.1;
		}
		else if (env->inputs.ctrl)
			scale->y /= 1.1;
		else
			scale->x /= 1.1;
	}
}

void	wall_sprites_keyup2(t_env *env, t_v2 *pos, t_v2 *scale)
{
	if (env->sdl.event.key.keysym.sym == SDLK_PERIOD && check_sprite_pos(pos))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			pos->x++;
			pos->y++;
		}
		else if (env->inputs.ctrl)
			pos->y++;
		else
			pos->x++;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_EQUALS
		&& check_texture_scale(env, scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			scale->x *= 1.1;
			scale->y *= 1.1;
		}
		else if (env->inputs.ctrl)
			scale->y *= 1.1;
		else
			scale->x *= 1.1;
	}
	wall_sprites_keyup3(env, scale);
}

void	wall_sprites_keyup(t_env *env, t_v2 *pos, t_v2 *scale)
{
	if (!env->editor.keyup_allowed)
	  	return ;
	if (env->sdl.event.key.keysym.sym == SDLK_COMMA
		&& check_sprite_pos(pos))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			pos->y--;
			pos->x--;
		}
		else if (env->inputs.ctrl)
			pos->y--;
		else
			pos->x--;
	}
	wall_sprites_keyup2(env, pos, scale);
}
