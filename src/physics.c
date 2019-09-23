/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/23 14:30:30 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	game_time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.speed = ((env->time.milli_s - new_time) / 1000.0) * 15;
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000.0) * 0.2;
	env->time.tenth_s = env->time.milli_s / 100.0;
}

void	climb(t_env *env)
{
	double	time;

	time = SDL_GetTicks() / 100.0;
	ft_printf("climb\n");
	if (!env->player.state.climb)
	{
		env->player.state.climb = 1;
		env->time.last_climb = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.2;
	}
	env->time.d_time = time - env->time.last_climb;
	env->player.pos.z += env->time.d_time * env->player.velocity;	
	if (env->player.pos.z > env->sectors[env->player.highest_sect].floor)
	{
		env->player.pos.z = env->sectors[env->player.highest_sect].floor;
		env->player.state.climb = 0;
		env->player.velocity = 0;
		env->time.d_time = 0;
	}
}

void	drop(t_env *env)
{
	double	time;

	time = SDL_GetTicks() / 100.0;
	ft_printf("drop\n");
	if (!env->player.state.drop)
	{
		env->player.state.drop = 1;
		env->time.last_drop = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.02;
	}
	env->time.d_time = time - env->time.last_climb;
	env->player.pos.z -= env->time.d_time * env->player.velocity;	
	if (env->player.pos.z < env->sectors[env->player.highest_sect].floor)
	{
		env->player.pos.z = env->sectors[env->player.highest_sect].floor;
		env->player.state.drop = 0;
		env->player.velocity = 0;
		env->time.d_time = 0;
	}

}

void	jump(t_env *env)
{
	if (!env->player.state.fall)
	{
		env->gravity.velocity = 25.0;
		env->player.state.jump = 1;
		env->player.start_pos = env->player.pos.z;
		env->player.pos.z += 0.00001;
		ft_printf("start jump\n");
	}
	ft_printf("jump\n");
}

void	crouch(t_env *env)
{
	(void)env;
}
