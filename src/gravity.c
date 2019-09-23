/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:06:14 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/23 18:56:05 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

double	apply_climb(double vel)
{
	double	move_acc;
	double	drag_force;
	double	drag_acc;
	double	mass;

	mass = 1;
	move_acc = 0.3;
	drag_force = 0.5 * 0.1 * (vel * fabs(vel));
	drag_acc = drag_force / mass;
	return (move_acc - drag_acc);
}

double	apply_drop(double vel)
{
	double	move_acc;
	double	drag_force;
	double	drag_acc;
	double	mass;

	mass = 1;
	move_acc = -0.3;
	drag_force = 0.5 * 0.1 * (vel * fabs(vel));
	drag_acc = drag_force / mass;
	return (move_acc - drag_acc);
}

void	gravity(t_env *env)
{
	double	time;
	double	new_pos;
	double	new_velocity;
	t_v2	pos;
	double	slope;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 1000.0;
	if ((!env->player.state.fall
	&& env->player.pos.z > slope + 2)
	|| (env->player.state.jump && !env->player.state.fall))
	{
		env->player.state.walk = 0;
		env->time.last_fall = SDL_GetTicks() / 1000.0;
		env->player.state.fall = 1;
		env->player.start_pos = env->player.pos.z;
		env->player.velocity_start = env->gravity.velocity;
	}
	if (env->player.state.fall)
	{
		env->time.d_time = time - env->time.last_fall;
		env->gravity.acceleration = -9.81 * 3.3;
		new_pos = env->player.start_pos +  (env->gravity.velocity * env->time.d_time)
			+ env->gravity.acceleration * env->time.d_time * env->time.d_time * 0.5;
		new_velocity = env->player.velocity_start + env->gravity.acceleration * env->time.d_time;
		env->player.pos.z = new_pos;
		env->gravity.velocity = new_velocity;
	}
	if (env->player.pos.z < env->sectors[env->player.highest_sect].floor && env->player.state.fall)
	{
		env->player.pos.z = env->sectors[env->player.highest_sect].floor;
		env->gravity.velocity = 0;
		env->gravity.acceleration = 0;
		env->player.state.jump = 0;
		env->time.d_time = 0;
		env->player.state.fall = 0;
	}
	else if (env->player.pos.z > env->sectors[env->player.sector].floor && env->player.state.jump
			&& env->player.pos.z < env->sectors[env->player.highest_sect].floor)
	{
		env->player.pos.z = env->sectors[env->player.sector].floor;
		env->gravity.velocity = 0;
		env->gravity.acceleration = 0;
		env->player.state.jump = 0;
		env->time.d_time = 0;
		env->player.state.fall = 0;
	}

	env->player.head_z = env->player.pos.z + env->player.eyesight;
}
