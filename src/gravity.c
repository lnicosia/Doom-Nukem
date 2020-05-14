/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:06:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/13 15:09:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

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

void	player_fall(t_v3 pos, double time, t_env *env)
{
	double	new_velocity;
	double	new_pos;

	env->time.d_time = time - env->time.last_fall;
	env->gravity.acceleration = env->gravity.force * 3.3;
	new_pos = env->player.start_pos + (env->gravity.velocity
	* env->time.d_time) + env->gravity.acceleration * env->time.d_time
	* env->time.d_time * 0.5;
	new_velocity = env->player.velocity_start + env->gravity.acceleration
	* env->time.d_time;
	env->gravity.velocity = new_velocity;
	if (new_pos + env->player.eyesight > get_ceiling_at_pos(
		&env->sectors[env->player.sector], pos, env) - 1)
	{
		new_pos = get_ceiling_at_pos(&env->sectors[env->player.sector],
		pos, env) - 1 - env->player.eyesight;
		env->time.d_time = 0;
		env->gravity.velocity = 0;
		env->player.velocity_start = 0;
		env->gravity.acceleration = 0;
		env->player.state.jump = 0;
		env->player.start_pos = env->player.pos.z;
		env->time.last_fall = SDL_GetTicks() / 1000.0;
	}
	env->player.pos.z = new_pos;
}

void	correct_player_fall(double slope, t_env *env)
{
	env->player.pos.z = slope;
	env->gravity.velocity = 0;
	env->gravity.acceleration = 0;
	env->player.state.jump = 0;
	env->time.d_time = 0;
	env->player.state.fall = 0;
}

void	gravity(t_env *env)
{
	double	time;
	t_v3	pos;
	double	slope;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(&env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 1000.0;
	env->gravity.force = env->sectors[env->player.highest_sect].gravity;
	if ((!env->player.state.fall && env->player.pos.z > slope + 2)
		|| (env->player.state.jump && !env->player.state.fall
		&& !env->player.state.fly))
	{
		reset_state(env);
		init_fall(env);
	}
	if (env->player.state.fall)
		player_fall(pos, time, env);
	if (env->player.pos.z < slope && env->player.state.fall && env->time.d_time
	&& !env->events)
		correct_player_fall(slope, env);
	env->player.head_z = env->player.pos.z + env->player.eyesight;
}
