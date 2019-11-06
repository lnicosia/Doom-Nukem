/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/06 14:51:10 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	animations(t_env *env)
{
	double	slope;
	t_v2	pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env);
	if ((env->player.pos.z > slope || env->player.state.fall || env->player.state.jump)
	&& !env->player.state.climb && !env->player.state.drop)
		gravity(env);
	if ((env->inputs.space || env->player.state.jump)
			&& !env->player.state.climb && !env->player.state.drop)
		jump(env);
	if (!env->player.state.jump && !env->player.state.fall
			&& !env->player.state.climb && !env->player.state.drop)
		update_player_z(env);
	if (((env->inputs.ctrl&& env->player.eyesight > 3)
	|| env->player.state.crouch) && !env->editor.in_game)
		crouch(env);
	env->player.camera.pos.z = env->player.head_z;
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
		move = check_collision(env, new_v2(env->player.camera.angle_cos * env->player.speed, env->player.camera.angle_sin * env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 2)
	{
		move = check_collision(env, new_v2(env->player.camera.angle_cos * -env->player.speed, env->player.camera.angle_sin * -env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 3)
	{
		move = check_collision(env, new_v2(env->player.camera.angle_sin * env->player.speed, env->player.camera.angle_cos * -env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 4)
	{
		move = check_collision(env, new_v2(env->player.camera.angle_sin * -env->player.speed, env->player.camera.angle_cos * env->player.speed), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	(void)a;
	if (nb == 3)
	{
		ft_printf("stuck\n");
		env->player.stuck = 1;
	}
}

void	move_player(t_env *env)
{
	int			movement;
	t_movement	motion;
	t_v2		move;
	t_v2		pos;
	int			prev_sector;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	if (env->player.sector >= 0)
	{
		env->player.old_pos.x = pos.x;
		env->player.old_pos.y = pos.y;
	}
	prev_sector = env->player.sector;
	movement = 0;
	env->time.end = env->time.milli_s / 10;
	if (env->time.end - env->time.start >= 1)
	{
		env->time.start = env->time.end;
		motion = new_movement(env->player.sector, env->player.size_2d, env->player.eyesight, env->player.pos);
		if (env->inputs.forward && !env->inputs.backward)
		{
			move = check_collision(env, new_v2(env->player.camera.angle_cos * env->player.speed, env->player.camera.angle_sin * env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
				check_blocage(env, motion, 1);
		}
		else if (env->inputs.backward && !env->inputs.forward)
		{
			move = check_collision(env, new_v2(env->player.camera.angle_cos * -env->player.speed, env->player.camera.angle_sin * -env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
				check_blocage(env, motion, 2);
		}
		if (env->inputs.left && !env->inputs.right)
		{
			move = check_collision(env, new_v2(env->player.camera.angle_sin * env->player.speed, env->player.camera.angle_cos * -env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
				check_blocage(env, motion, 3);
		}
		else if (env->inputs.right && !env->inputs.left)
		{
			move = check_collision(env, new_v2(env->player.camera.angle_sin * -env->player.speed, env->player.camera.angle_cos * env->player.speed), motion, 0);
			env->player.pos.x += move.x;
			env->player.pos.y += move.y;
			if (move.x != 0 || move.y != 0)
				movement = 1;
			if (move.x == 0 && move.y == 0)
				check_blocage(env, motion, 4);
		}
		if (env->player.stuck || get_sector_no_z_origin(env, env->player.pos, env->player.sector) == -1)
		{
			env->player.stuck = 0;
			env->player.pos.x = env->player.old_pos.x;
			env->player.pos.y = env->player.old_pos.y;
			env->player.sector = get_sector_no_z_origin(env, env->player.pos, prev_sector);
		}
		if (!movement && (env->player.state.climb || env->player.state.drop))
			movement = 1;
		if (movement)
		{
			env->player.sector = get_sector_no_z_origin(env, env->player.pos, env->player.sector);
			if (find_highest_sector(env, motion) != env->player.highest_sect
					&& get_floor_at_pos(env->sectors[find_highest_sector(env, motion)], pos, env) < get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env))
				env->player.drop_flag = 1;
			env->player.highest_sect = find_highest_sector(env, motion);
			env->player.lowest_sect = find_lowest_sector(env, motion);
			env->player.camera.pos = env->player.pos;
			env->player.camera.pos.z = env->player.head_z;
			if (((get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env) > env->player.pos.z
				&& get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env) - env->player.pos.z <= 2)
				|| (env->player.state.climb))
				&& !env->player.state.drop && !env->player.state.jump)
				climb(env);
			else if ((((get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env) < env->player.pos.z
					&& env->player.pos.z - get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env) <= 2)
					|| env->player.state.drop)
					&& !env->player.state.jump && !env->player.state.fall && !env->player.state.climb)
					&& env->player.drop_flag)
				drop(env);
			env->player.head_z = env->player.pos.z + env->player.eyesight;
			update_camera_position(&env->player.camera);
		}
	}
}
