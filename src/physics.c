/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/06/14 14:35:45 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

void	time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.speed = ((env->time.milli_s - new_time) / 1000) * 10;
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000) * 0.2;
	env->time.tenth_s = env->time.milli_s / 100;
}

void	jump(t_env *env)
{
	double	x;

	x = 0.4;
	env->player.state = 1;
	env->gravity.on_going = 0;
	if (!env->jump.on_going)
	{
		Mix_PlayChannel(1, env->sound.jump, 0);
		env->jump.on_going = env->time.tenth_s;
	}
	env->jump.start = env->time.tenth_s;
	if (env->jump.start - env->jump.end >= 0.1)
	{
		env->jump.end = env->jump.start;
		env->player.pos.z += (x * env->gravity.weight);
		env->gravity.weight -= 0.05;
		if (env->gravity.weight < 0)
			env->gravity.weight = 0;
	}
	if (env->jump.end >= env->jump.on_going + 4)
	{
		env->gravity.weight = 1;
		env->gravity.on_going = 1;
		env->jump.on_going = 0;
	}
}

void	climb(t_env *env)
{
	double	x;

	x = 0.5;
	if (env->player.pos.z + x > env->gravity.floor)
	{
		x = env->gravity.floor - env->player.pos.z;
		env->player.pos.z += x;
	}
	if (env->player.pos.z < env->gravity.floor)
		env->player.pos.z += (x);
	if (env->player.pos.z + (x) > env->gravity.floor)
	{
		x = env->gravity.floor - env->player.pos.z;
		env->player.pos.z += x;
	}
}

void	fall(t_env *env)
{
	double	x;

	x = 0.3;
	env->gravity.start = env->time.tenth_s;
	env->player.state = 1;
	if (env->gravity.start - env->gravity.end >= 0.1)
	{
		env->gravity.end = env->gravity.start;
		if (env->player.pos.z > env->gravity.floor && env->player.pos.z -
				(x * env->gravity.weight) < env->gravity.floor)
		{
			x = env->player.pos.z - env->gravity.floor;
			env->player.pos.z -= x;
			x = 0.3;
			env->gravity.weight = 1;
			env->player.state = 0;
		}
		if (env->player.pos.z > env->gravity.floor)
		{
			env->player.pos.z -= (x * env->gravity.weight);
			env->gravity.weight += 0.1;
		}
		if (env->player.pos.z > env->gravity.floor && env->player.pos.z -
				(x * env->gravity.weight) < env->gravity.floor)
		{
			x = env->player.pos.z - env->gravity.floor;
			env->player.pos.z -= x;
			env->gravity.weight = 1;
			env->player.state = 0;
			ft_printf("\n");
		}
	}
}

void	squat(t_env *env)
{
	env->squat.on_going = 1;
	if (env->squat.end != env->time.tenth_s)
		env->squat.start = env->squat.end;
	env->squat.end = env->time.tenth_s;
	{
		if (env->player.eyesight > 3)
		{
			env->player.pos.z -= 0.5;
			env->player.eyesight -= 0.5;
			update_player_z(env);
		}
		if (env->player.eyesight == 3 && !env->inputs.ctrl)
		{
			env->player.eyesight = 6;
			update_floor(env);
			env->player.state = 0;
			env->squat.on_going = 0;
		}
	}
}

void	gravity(t_env *env)
{
	double	p_z = env->player.pos.z;

	if (p_z != env->gravity.floor)
	{
		if (p_z > env->gravity.floor && !env->jump.on_going)
		{
			env->flag = 1;
			fall(env);
		}
		if (env->player.pos.z < env->gravity.floor && !env->jump.on_going)
			climb(env);
	}
}
