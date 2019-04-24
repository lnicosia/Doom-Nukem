/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/24 11:33:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
**	Handles player movements
**	TODO Protection / return values??
*/

void	move_player(t_env *env)
{
	t_sector	sector;
	t_vertex	v0;

	if (env->sdl.event.key.keysym.sym == SDLK_w ||
			env->sdl.event.key.keysym.sym == SDLK_UP)
	{	
		if (check_collision(env, env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_cos * env->player.speed;
			env->player.pos.y += env->player.angle_sin * env->player.speed;
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_s ||
			env->sdl.event.key.keysym.sym == SDLK_DOWN)
	{
		if (check_collision(env, env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_cos * env->player.speed;
			env->player.pos.y -= env->player.angle_sin * env->player.speed;
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_a ||
			env->sdl.event.key.keysym.sym == SDLK_LEFT)
	{
		if (check_collision(env, env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_sin * env->player.speed;
			env->player.pos.y -= env->player.angle_cos * env->player.speed;
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_d ||
			env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	{
		if (check_collision(env, env->player.angle_sin * -env->player.speed, env->player.angle_cos * env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_sin * env->player.speed;
			env->player.pos.y += env->player.angle_cos * env->player.speed;
		}
	}
	sector = env->sectors[env->player.sector];
	v0 = env->vertices[sector.vertices[0]];
	env->player.pos.z = 6 + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
}
