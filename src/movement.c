/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 16:20:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

double	get_speed(t_env *env)
{
	Uint32	time;
	double	speed;

	time = SDL_GetTicks() - env->speed_time;
	if (env->inputs.shift && !env->inputs.ctrl)
		speed = env->player.speed * 1.5;
	else if (env->inputs.ctrl && env->in_game)
		speed = env->player.speed / 1.5;
	else
		speed = env->player.speed;
	speed *= time;
	return (speed);
}

t_v3	get_move2(t_v3 move, double speed, t_env *env)
{
	if (env->inputs.left && !env->inputs.right)
	{
		move.x += env->player.camera.angle_sin * speed;
		move.y += env->player.camera.angle_cos * -speed;
		move.z += 0;
	}
	else if (env->inputs.right && !env->inputs.left)
	{
		move.x += env->player.camera.angle_sin * -speed;
		move.y += env->player.camera.angle_cos * speed;
		move.z += 0;
	}
	return (move);
}

t_v3	get_move(double speed, t_env *env)
{
	t_v3		move;

	move = new_v3(0, 0, 0);
	if (env->player.state.fly && env->inputs.space)
		move.z += 0.5 * speed;
	if (env->player.state.fly && env->inputs.lgui)
		move.z -= 0.5 * speed;
	if (env->inputs.forward && !env->inputs.backward)
	{
		move.x += env->player.camera.angle_cos * speed;
		move.y += env->player.camera.angle_sin * speed;
		move.z += (env->player.state.fly) ? -env->player.camera.angle_z
		* speed : 0;
	}
	else if (env->inputs.backward && !env->inputs.forward)
	{
		move.x += env->player.camera.angle_cos * -speed;
		move.y += env->player.camera.angle_sin * -speed;
		move.z += (env->player.state.fly) ? env->player.camera.angle_z
		* speed : 0;
	}
	return (get_move2(move, speed, env));
}

int		move_player2(t_v3 move, int prev_sector, t_env *env)
{
	int		movement;

	movement = 0;
	if (move.x != 0 || move.y != 0 || move.z != 0)
		movement = 1;
	env->player.pos.x += move.x;
	env->player.pos.y += move.y;
	env->player.pos.z += move.z;
	if (env->player.stuck || get_sector_no_z_origin(env, env->player.pos,
		env->player.sector) == -1)
	{
		env->player.stuck = 0;
		env->player.pos = env->player.old_pos;
		env->player.sector = get_sector_no_z_origin(env, env->player.pos,
		prev_sector);
	}
	if (!movement && (env->player.state.climb || env->player.state.drop))
		movement = 1;
	if (movement)
	{
		update_player_pos(env);
		animations(env);
	}
	return (0);
}

int		move_player(t_env *env)
{
	t_motion	motion;
	t_v3		move;
	int			prev_sector;
	double		speed;

	speed = get_speed(env);
	if (env->player.sector >= 0)
		env->player.old_pos = env->player.pos;
	prev_sector = env->player.sector;
	motion = new_motion(env->player.sector, env->player.size_2d,
	env->player.eyesight, env->player.pos);
	motion.flight = env->player.state.fly;
	motion.lowest_ceiling = find_lowest_ceiling(env, motion);
	move = get_move(speed, env);
	env->checking_collisions_with_player = 1;
	move = check_collision(env, move, motion);
	if (env->fatal_error)
		return (-1);
	env->checking_collisions_with_player = 0;
	return (move_player2(move, prev_sector, env));
}
