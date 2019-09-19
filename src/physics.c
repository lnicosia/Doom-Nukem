/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/19 18:14:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	game_time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.speed = ((env->time.milli_s - new_time) / 1000) * 15;
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000) * 0.2;
	env->time.tenth_s = env->time.milli_s / 100;
}

void	climb(t_env *env)
{
	if (!env->player.state.fall)
	{
		env->gravity.velocity = 25.0;
		env->player.start_pos = env->player.pos.z;
		ft_printf("start climb\n");
	}
/*	if (env->player.pos.z >= env->sectors[env->player.highest_sect].floor)
	{
		env->gravity.velocity = 0;
		env->player.state.climb = 0;
		env->player.pos.z = env->sectors[env->player.highest_sect].floor;
		ft_printf("end climb\n");
	}*/

}

void	drop(t_env *env)
{
	double	time;
	double	new_pos;
	double	new_velocity;

	time = SDL_GetTicks() / 10;
	if (env->player.pos.z > env->sectors[env->player.lowest_sect].floor)
	{
		if (!env->player.state.climb && !env->player.state.fall)
		{
			env->time.last_fall = SDL_GetTicks() / 10;
			env->player.state.drop = 1;
		}
		ft_printf("drop\n");
		env->time.d_time = time - env->time.last_fall;
		new_pos = env->player.pos.z +  (env->player.velocity * env->time.d_time)
			+ (env->time.d_time * env->time.d_time * 0.5);
		env->player.pos.z += apply_climb(env->player.velocity);
		new_velocity = env->player.velocity * (env->time.d_time * 0.5);
		if (env->player.pos.z > env->sectors[env->player.highest_sect].floor)
		{
			env->player.pos.z = env->sectors[env->player.lowest_sect].floor;
			env->time.d_time = 0;
			env->player.velocity = 0;
			env->player.state.drop = 0;
		}
		env->player.head_z = env->player.pos.z + env->player.eyesight;
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
}

void	crouch(t_env *env)
{
	(void)env;
}
