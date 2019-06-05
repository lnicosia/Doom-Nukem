/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/06/05 11:03:12 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

void	speed(t_env *env)
{
	double	new_time;

	new_time = env->time;
	env->time = SDL_GetTicks();
	env->player.speed = ((env->time - new_time) / 1000) * 10;
	env->player.rotation_speed = ((env->time - new_time) / 1000) * 0.3;
	env->time_tick = env->time / 100;
}

void	jump(t_env *env)
{
	double	x;

	x = 0.55;
	ft_printf("jump\n");
	env->player.state = 1;
	if (!env->jump.on_going)
		env->jump.on_going = SDL_GetTicks() / 100;
	env->gravity.on_going = 0;
	if (env->jump.end != env->time_tick)
		env->jump.start = env->jump.end;
	env->jump.end = env->time_tick;
	if (env->jump.end - env->jump.start >= 1 && env->jump.end <= env->jump.on_going + 4)
	{
		env->player.pos.z += (x * env->gravity.weight);
		env->gravity.weight -= 0.1;
		if (env->gravity.weight < 0)
			env->gravity.weight = 0;
	}
	if (env->jump.end >= env->jump.on_going + 5)
	{
		env->jump.start = 0;
		env->gravity.weight = 1;
	}
	if (env->jump.end >= env->jump.on_going + 4)
	{
		env->jump.on_going = 0;
		env->gravity.on_going = 1;
	}
}

void	climb(t_env *env)
{
	double	x;

	x = 0.5;
	ft_printf("climb\n");
	if (env->player.pos.z + x > env->gravity.floor)
	{
		ft_printf("adjustement\n");
		x = env->gravity.floor - env->player.pos.z;
		env->player.pos.z += x;
	}
	if (env->player.pos.z < env->gravity.floor)
	{
		ft_printf("normal\n");
		env->player.pos.z += (x * env->gravity.weight);
	}
	if (env->player.pos.z + (x * env->gravity.weight) > env->gravity.floor)
	{
		ft_printf("adjustement\n");
		x = env->gravity.floor - env->player.pos.z;
		env->player.pos.z += x;
	}
	ft_printf("\n");
}

void	fall(t_env *env)
{
	double	x;

	x = 0.3;
	ft_printf("fall\n");
	if (env->gravity.end != env->time_tick)
		env->gravity.start = env->gravity.end;
	env->gravity.end = env->time_tick;
	if (env->gravity.end - env->gravity.start >= 1)
	{
		if (env->player.pos.z > env->gravity.floor)
		{
			env->player.pos.z -= (x * env->gravity.weight);
			env->gravity.weight += 0.7;
		}
		if (env->player.pos.z > env->gravity.floor && env->player.pos.z -
				(x * env->gravity.weight) < env->gravity.floor)
		{
			x = env->player.pos.z - env->gravity.floor;
			env->player.pos.z -= x;
			x = 0.3;
			env->gravity.weight = 1;
			env->player.state = 0;
		}
	}
}

void	squat(t_env *env)
{
	env->squat.on_going = 1;
	if (env->player.eyesight > 3 )
	{
		env->player.state = 1;
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
		if (env->player.pos.z < env->gravity.floor)
			climb(env);
	}
}
