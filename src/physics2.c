/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:21:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/13 14:34:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	reset_state(t_env *env)
{
	env->player.state.fly = 0;
	env->player.state.climb = 0;
	env->player.state.drop = 0;
	env->player.state.jump = 0;
	env->player.state.fall = 0;
}

void	init_fall(t_env *env)
{
	env->player.state.fall = 1;
	env->player.state.walk = 0;
	env->player.state.climb= 0;
	env->player.state.drop = 0;
	env->player.state.jump = 0;
	env->time.last_fall = SDL_GetTicks() / 1000.0;
	env->player.start_pos = env->player.pos.z;
	env->player.velocity_start = env->gravity.velocity;
}

void	game_time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000.0)
	* 0.2;
	env->time.tenth_s = env->time.milli_s / 100.0;
}

void	adjust_player_z_after_climb(double slope, t_env *env)
{
	ft_printf("z: %f slope: %f\n", env->player.pos.z, slope);
	if (env->player.pos.z > slope + 2)
		init_fall(env);
	else
		env->player.pos.z = slope;
	env->player.state.climb = 0;
	env->player.velocity = 0;
	env->time.d_time = 0;
}

void	climb(t_env *env)
{
	double	time;
	double	slope;
	t_v3	pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(&env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 100.0;
	if (!env->player.state.climb)
	{
		env->climb_sect = env->player.sector;
		env->player.state.climb = 1;
		env->time.last_climb = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.4;
	}
	if (env->player.state.climb)
	{
		env->time.d_time = time - env->time.last_climb;
		env->player.pos.z += env->time.d_time * env->player.velocity;
	}
	ft_printf("sector: %d high: %d\n", env->player.sector,
	env->player.highest_sect);
	if (env->player.pos.z >= slope && (env->player.pos.z <= slope + 1
	|| env->climb_sect != env->player.sector))
		adjust_player_z_after_climb(slope, env);
}
