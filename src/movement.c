/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/16 11:24:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
**	Handles player movements
**	TODO Protection / return values??
*/

void	move_player(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_w ||
			env->sdl.event.key.keysym.sym == SDLK_UP)
	{
		env->player.pos.x += env->player.angle_cos * env->player.speed;
		env->player.pos.y += env->player.angle_sin * env->player.speed;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_s ||
			env->sdl.event.key.keysym.sym == SDLK_DOWN)
	{
		env->player.pos.x -= env->player.angle_cos * env->player.speed;
		env->player.pos.y -= env->player.angle_sin * env->player.speed;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_a ||
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		env->player.pos.x += env->player.angle_sin * env->player.speed;
		env->player.pos.y -= env->player.angle_cos * env->player.speed;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_d ||
			env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		env->player.pos.x -= env->player.angle_sin * env->player.speed;
		env->player.pos.y += env->player.angle_cos * env->player.speed;
	}
}
