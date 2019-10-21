/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/21 17:39:17 by sipatry          ###   ########.fr       */
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
	double	slope;
	t_v2		pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 100.0;
	ft_printf("here climb !\n");
	if (!env->player.state.climb)
	{
		ft_printf("climb\n");
		env->player.state.climb = 1;
		env->time.last_climb = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.2;
	}
	if (env->player.state.climb)
	{
		ft_printf("climbing\n");
		env->time.d_time = time - env->time.last_climb;
		env->player.pos.z += env->time.d_time * env->player.velocity;	
	}
	if (env->player.pos.z > slope)
	{
		ft_printf("adjustement\n");
		env->player.pos.z = slope;
		env->player.state.climb = 0;
		env->player.velocity = 0;
		env->time.d_time = 0;
	}
}

void	drop(t_env *env)
{
	double	time;
	double	slope;
	t_v2		pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 100.0;
	ft_printf("here drop !\n");
	if (!env->player.state.drop)
	{
		ft_printf("drop\n");
		env->player.state.drop = 1;
		env->time.last_drop = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.2;
	}
	if (env->player.state.drop)
	{
		ft_printf("dropping\n");
		env->time.d_time = time - env->time.last_drop;
		env->player.pos.z -= env->time.d_time * env->player.velocity;	
	}
	if (env->player.pos.z < slope)
	{
		ft_printf("adjustement\n");
		env->player.pos.z = slope;
		env->player.state.drop = 0;
		env->player.velocity = 0;
		env->time.d_time = 0;
		env->player.drop_flag = 0;
	}
}

void	jump(t_env *env)
{
	if (!env->player.state.fall && !env->player.state.jump)
	{
		ft_printf("jump\n");
		env->gravity.velocity = 25.0;
		env->player.state.jump = 1;
		env->player.start_pos = env->player.pos.z;
		env->player.pos.z += 0.00001;
	}
}

void	crouch(t_env *env)
{
	double	time;

	time = SDL_GetTicks() / 100.0;
	if (!env->player.state.crouch)
	{
		ft_printf("drop\n");
		env->player.state.crouch = 1;
		env->time.last_crouch = time;
	}
	if (env->player.state.crouch && env->inputs.ctrl)
	{
		ft_printf("down\n");
		env->time.d_time = time - env->time.last_crouch;
		env->player.eyesight -= env->time.d_time * 0.3;	
	}
	if (env->player.state.crouch && !env->inputs.ctrl)
	{
		ft_printf("up\n");
		env->time.d_time = time - env->time.last_crouch;
		env->player.eyesight += env->time.d_time * 0.3;	
	}
	if ((env->player.eyesight <= 3 && env->inputs.ctrl)
	|| (env->player.eyesight >= 6 && !env->inputs.ctrl))
	{
		ft_printf("adjustement\n");
		if (env->inputs.ctrl)
			env->player.eyesight = 3;
		else
		{
			env->player.state.crouch = 0;	
			env->player.eyesight = 6;
		}
		env->time.d_time = 0;
	}
}
