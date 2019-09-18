/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/17 19:28:40 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
 **	Update camera's position (save some computings)
 */

void	update_camera_position(t_env *env)
{
	env->player.camera_x = env->player.pos.x + env->player.angle_cos * env->camera.near_z;
	env->player.camera_y = env->player.pos.y + env->player.angle_sin * env->camera.near_z;
	env->player.near_left.x = env->player.pos.x + (env->player.angle_cos * env->camera.near_z - env->player.angle_sin * env->camera.near_left);
	env->player.near_left.y = env->player.pos.y + (env->player.angle_sin * env->camera.near_z + env->player.angle_cos * env->camera.near_left);
	env->player.near_right.x = env->player.pos.x + (env->player.angle_cos * env->camera.near_z - env->player.angle_sin * env->camera.near_right);
	env->player.near_right.y = env->player.pos.y + (env->player.angle_sin * env->camera.near_z + env->player.angle_cos * env->camera.near_right);
}

void	animations(t_env *env)
{
	update_floor(env);
	if (env->gravity.on_going)
		gravity(env);
	if (((env->inputs.space && !env->player.state) || env->jump.on_going))
		jump(env);
	if (((env->inputs.ctrl && !env->player.state && env->player.eyesight == 6) || env->crouch.on_going) && !env->jump.on_going)
		crouch(env);
}

/*
 **	Handles player movements
 **	TODO Protection / return values??
 */

void	check_blocage(t_env *env, t_movement motion, int index)
{
	int nb;
	t_v2 move;
	static int a = 0;

	nb = 0;
	if (index != 1)
	{
		move = check_collision(env, new_v2(env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 2)
	{
		move = check_collision(env, new_v2(env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 3)
	{
		move = check_collision(env, new_v2(env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 4)
	{
		move = check_collision(env, new_v2(env->player.angle_sin * -env->player.speed, env->player.angle_cos * env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (nb == 3)
		ft_printf("I'm stuck .... . .-.. .--.   ... --- ...%d\n", a++);
}

void	move_player(t_env *env)
{
	int			movement;
	t_movement	motion;
	t_v2		move;

	movement = 0;
	env->time.end = env->time.milli_s / 10;
	if (env->time.end - env->time.start >= 1)
	{
		env->time.start = env->time.end;
		motion = new_movement(env->player.sector, env->player.size_2d, env->player.eyesight, env->player.pos);
		if (env->inputs.forward && !env->inputs.backward)
		{
			move = check_collision(env, new_v2(env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
				check_blocage(env, motion, 1);
		}
		else if (env->inputs.backward && !env->inputs.forward)
		{
			move = check_collision(env, new_v2(env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed), motion, 0);
				env->player.pos.x += move.x;
				env->player.pos.y += move.y;
				if (move.x != 0 || move.y != 0)
					movement = 1;
				if (move.x == 0 && move.y == 0)
					check_blocage(env, motion, 2);
		}
		if (env->inputs.left && !env->inputs.right)
		{
			move = check_collision(env, new_v2(env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed), motion, 0);
				env->player.pos.x += move.x;
				env->player.pos.y += move.y;
				if (move.x != 0 || move.y != 0)
					movement = 1;
				if (move.x == 0 && move.y == 0)
					check_blocage(env, motion, 3);
		}
		else if (env->inputs.right && !env->inputs.left)
		{
			move = check_collision(env, new_v2(env->player.angle_sin * -env->player.speed, env->player.angle_cos * env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
					check_blocage(env, motion, 4);
		}
		if (movement)
		{
			env->player.sector = get_sector_no_z_origin(env, env->player.pos, env->player.sector);
			env->player.highest_sect = find_highest_sector(env, motion);
			update_camera_position(env);
		}
	}
}
