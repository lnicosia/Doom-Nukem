/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/15 20:42:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

void	game_time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.speed = ((env->time.milli_s - new_time) / 1000) * 15;
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000) * 0.2;
	env->time.tenth_s = env->time.milli_s / 100;
	//env->time.tick = 1000 / env->fps;
}

void	jump(t_env *env)
{
	double	x;
	double	new_time;
	double	res;
	int		i;
	int		j;

	x = 0.6;
	res = 0;
	j = 0;
	i = 0;
	env->jump.on_going = 1;
	env->gravity.on_going = 0;
	new_time = env->time.milli_s;
	if (!env->jump.start)
	{
		//Mix_PlayChannel(1, env->sound.jump, 0);
		env->jump.start = env->time.milli_s;
		env->jump.height = env->player.pos.z + 3;
	}
	if (env->player.pos.z <= env->jump.height)
	{
		env->player.pos.z = env->jump.height - 3;
		env->player.head_z = env->player.pos.z + env->player.eyesight;
		env->jump.tick = env->jump.end / env->jump.nb_frame;
		j = (new_time - env->jump.start) / env->jump.tick;
		while (i < j)
		{
			res += x - env->gravity.weight;
			env->gravity.weight += 0.05;
			i++;
		}
		env->gravity.weight = 0;	
		env->player.pos.z += res;
		env->player.head_z = env->player.pos.z + env->player.eyesight;
		if (env->gravity.weight < 0)
			env->gravity.weight = 0;
	}
	if (new_time - env->jump.start >= env->jump.end)
	{
		env->gravity.weight = 0;
		env->gravity.on_going = 1;
		env->jump.start = 0;
		env->jump.on_going = 0;
	}
}

void	climb(t_env *env)
{
	double	x;

	x = 0.5;
	if (env->player.pos.z < env->gravity.floor)
	{
		if (env->player.pos.z + x > env->gravity.floor)
		{
			x = env->gravity.floor - env->player.pos.z;
			env->player.pos.z += x;
		}
		if (env->player.pos.z < env->gravity.floor)
		{
			env->player.pos.z += (x);
		}
		if (env->player.pos.z + (x) > env->gravity.floor)
		{
			x = env->gravity.floor - env->player.pos.z;
			env->player.pos.z += x;
		}
		env->player.head_z = env->player.pos.z + env->player.eyesight;
	}
	else if (env->player.eyesight < 6)
		env->player.eyesight += 0.5;
}

void	fall(t_env *env)
{
	double	x;

	x = 0.4;
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
			x = 0.4;
			env->gravity.weight = 1;
			env->player.state = 0;
		}
		if (env->player.pos.z > env->gravity.floor)
		{
			env->player.pos.z -= (x * env->gravity.weight);
			env->gravity.weight += 0.2;
		}
		if ((env->player.pos.z > env->gravity.floor && env->player.pos.z -
					(x * env->gravity.weight) < env->gravity.floor) || env->player.pos.z == env->gravity.floor)
		{
			x = env->player.pos.z - env->gravity.floor;
			env->player.pos.z -= x;
			env->gravity.weight = 1;
			env->player.state = 0;
		}
		env->player.head_z = env->player.pos.z + env->player.eyesight;
	}
}

void	crouch(t_env *env)
{
	double	new_time;
	double	x;
	int	i;

	x = 0.5;
	i = 0;
	new_time = env->time.milli_s;
	env->crouch.on_going = 1;
	if (!env->crouch.start)
		env->crouch.start = env->time.milli_s;
	if (env->player.eyesight > 3)
	{
		i = (new_time - env->crouch.start) / env->crouch.tick;
		if (i > env->crouch.nb_frame)
			i = env->crouch.nb_frame;
		env->player.eyesight = (6 - (x * i));
	}
	if (env->player.eyesight == 3)
	{
		update_floor(env);
		env->player.state = 0;
		env->crouch.start = 0;
		env->crouch.on_going = 0;
	}
	env->player.head_z = env->player.pos.z + env->player.eyesight;
}

void	gravity(t_env *env)
{
	double	p_z = env->player.pos.z;

	if (p_z != env->gravity.floor || env->player.eyesight != 6)
	{
		if (p_z > env->gravity.floor && !env->jump.on_going)
		{
			env->flag = 1;
			fall(env);
		}
		if ((env->player.pos.z < env->gravity.floor && !env->jump.on_going && !env->player.state)
			|| ((env->player.eyesight < 6) && !env->inputs.ctrl))
			climb(env);
	}
}
