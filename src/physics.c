/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:29:39 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/12 13:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	adjust_player_z_after_drop(double slope, t_env *env)
{
	env->player.pos.z = slope;
	env->player.state.drop = 0;
	env->player.velocity = 0;
	env->time.d_time = 0;
	env->player.drop_flag = 0;
}

void	drop(t_env *env)
{
	double	time;
	double	slope;
	t_v3	pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(&env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 100.0;
	if (!env->player.state.drop)
	{
		env->player.state.drop = 1;
		env->time.last_drop = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.4;
	}
	if (env->player.state.drop)
	{
		env->time.d_time = time - env->time.last_drop;
		env->player.pos.z -= env->time.d_time * env->player.velocity;
	}
	if (env->player.pos.z < slope)
		adjust_player_z_after_drop(slope, env);
}

void	jump(t_env *env)
{
	if (!env->player.state.fall && !env->player.state.jump
		&& !env->player.state.fly)
	{
		env->gravity.velocity = 25.0;
		env->player.state.jump = 1;
		env->player.start_pos = env->player.pos.z;
		env->player.pos.z += 0.00001;
	}
}

void	crouch2(int lowest_ceil, t_v3 pos, t_env *env)
{
	if ((env->player.eyesight <= 3 && env->inputs.ctrl)
		|| (env->player.eyesight >= 6 && !env->inputs.ctrl)
		|| ((env->player.pos.z + env->player.eyesight >
		get_ceiling_at_pos(&env->sectors[lowest_ceil], pos, env) - 1)
		&& env->player.eyesight < 6))
	{
		if (env->inputs.ctrl)
			env->player.eyesight = 3;
		else
		{
			if (env->player.pos.z + env->player.eyesight >
			get_ceiling_at_pos(&env->sectors[lowest_ceil], pos, env) - 1)
				env->player.eyesight = get_ceiling_at_pos(
				&env->sectors[lowest_ceil], pos, env) - 1 - env->player.pos.z;
			if (env->player.eyesight > 6)
			{
				env->player.state.crouch = 0;
				env->player.eyesight = 6;
			}
		}
		env->time.d_time = 0;
	}
	update_player_z(env);
}

void	crouch(t_env *env)
{
	double	time;
	t_v3	pos;
	int		lowest_ceil;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	lowest_ceil = find_lowest_ceiling(env, new_motion(env->player.sector,
		env->player.size_2d, env->player.eyesight, env->player.pos));
	time = SDL_GetTicks() / 100.0;
	if (!env->player.state.crouch)
	{
		env->player.state.crouch = 1;
		env->time.last_crouch = time;
	}
	if (env->player.state.crouch && env->inputs.ctrl)
	{
		env->time.d_time = time - env->time.last_crouch;
		env->player.eyesight -= env->time.d_time * 0.3;
	}
	if (env->player.state.crouch && !env->inputs.ctrl)
	{
		env->time.d_time = time - env->time.last_crouch;
		env->player.eyesight += env->time.d_time * 0.2;
	}
	crouch2(lowest_ceil, pos, env);
}
