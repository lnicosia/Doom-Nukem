/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/14 15:39:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	animations(t_env *env)
{
	double	slope;
	t_v3	pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(env->sectors[env->player.highest_sect], pos, env);
	if ((env->player.pos.z > slope || env->player.state.fall || env->player.state.jump)
			&& !env->player.state.climb && !env->player.state.drop && !env->player.state.fly)
		gravity(env);
	if ((env->inputs.space || env->player.state.jump)
			&& !env->player.state.climb && !env->player.state.drop)
		jump(env);
	if (!env->player.state.jump && !env->player.state.fall
			&& !env->player.state.climb && !env->player.state.drop
			&& !env->player.state.fall && !env->player.state.fly)
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

void	check_blocage(t_env *env, t_movement motion, double speed, int index)
{
	int nb;
	t_v3 move;
	static int a = 0;

	nb = 0;
	if (index != 1)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * speed,
					env->player.camera.angle_sin * speed, 0), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 2)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * speed,
					env->player.camera.angle_sin * -speed, 0), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 3)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * -speed,
					env->player.camera.angle_sin * -speed, 0), motion, 0);
		if (move.x == 0 && move.y == 0)
			nb++;
	}
	if (index != 4)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * -speed,
					env->player.camera.angle_sin * -speed, 0), motion, 0);
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

void	update_player_pos(t_env *env)
{
		int		new_sector;
		t_movement	motion;

		motion = new_movement(env->player.sector, env->player.size_2d, env->player.eyesight, env->player.pos);
		//ft_printf("move.x = %f, move.y = %f\n", move.x, move.y);
		new_sector = get_sector_no_z_origin(env,
				env->player.pos, env->player.sector);
		if (new_sector != env->player.sector)
		{
			env->player.old_sector = env->player.sector;
			env->player.changed_sector = 1;
		}
		if (find_highest_sector(env, motion) != env->player.highest_sect
				&& get_floor_at_pos(env->sectors[find_highest_sector(env, motion)], env->player.pos, env)
				< get_floor_at_pos(env->sectors[env->player.highest_sect], env->player.pos, env) && !env->player.state.fly)
			env->player.drop_flag = 1;
		env->player.highest_sect = find_highest_sector(env, motion);
		env->player.camera.pos = env->player.pos;
		env->player.camera.pos.z = env->player.head_z;
		if (((get_floor_at_pos(env->sectors[env->player.highest_sect], env->player.pos, env) > env->player.pos.z
			&& get_floor_at_pos(env->sectors[env->player.highest_sect], env->player.pos, env) - env->player.pos.z <= 2
			&& env->player.highest_sect != new_sector && !env->player.state.fly)
			|| (env->player.state.climb))
			&& !env->player.state.drop && !env->player.state.jump && !env->player.state.fly)
				climb(env);
		else if ((((get_floor_at_pos(env->sectors[env->player.highest_sect], env->player.pos, env) < env->player.pos.z
		&& env->player.pos.z - get_floor_at_pos(env->sectors[env->player.highest_sect], env->player.pos, env) <= 2)
						|| env->player.state.drop)
					&& !env->player.state.jump && !env->player.state.fall && !env->player.state.climb)
				&& env->player.drop_flag && !env->player.state.fly)
			drop(env);
		env->player.sector = new_sector;
		env->player.camera.pos = env->player.pos;
		env->player.camera.pos.z = env->player.head_z;
		env->player.head_z = env->player.pos.z + env->player.eyesight;
		env->player.camera.pos = env->player.pos;
		env->player.camera.pos.z = env->player.head_z;
		update_camera_position(&env->player.camera);
}

void	move_player(t_env *env)
{
	int			movement;
	t_movement	motion;
	t_v3		move;
	int			prev_sector;
	Uint32		time;
	double		speed;

	time = SDL_GetTicks() - env->time.milli_s;
	if (env->player.sector >= 0)
	{
		env->player.old_pos = env->player.pos;
	}
	if (env->inputs.shift && !env->inputs.ctrl)
		speed = env->player.speed * 1.5;
	else if (env->inputs.ctrl)
		speed = env->player.speed / 1.5;
	else 
		speed = env->player.speed;
	speed *= time;
	prev_sector = env->player.sector;
	movement = 0;
	motion = new_movement(env->player.sector, env->player.size_2d, env->player.eyesight, env->player.pos);
	motion.lowest_ceiling = find_lowest_ceiling(env, motion);
	if (env->player.state.fly && env->inputs.space)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * speed,
		env->player.camera.angle_sin * speed, -env->player.camera.angle_z * speed), motion, 0);
		env->player.pos.z += move.z;
		if (move.x != 0 || move.y != 0)
			movement = 1;
		if (move.x == 0 && move.y == 0)
			check_blocage(env, motion, time, 1);
	}
	if (env->inputs.forward && !env->inputs.backward)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * speed,
					env->player.camera.angle_sin * speed, -env->player.camera.angle_z * speed), motion, 0);
		env->player.pos.x += move.x;
		env->player.pos.y += move.y;
		if (env->player.state.fly)
			env->player.pos.z += move.z;
		if (move.x != 0 || move.y != 0)
			movement = 1;
		if (move.x == 0 && move.y == 0)
			check_blocage(env, motion, time, 1);
	}
	else if (env->inputs.backward && !env->inputs.forward)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_cos * -speed,
					env->player.camera.angle_sin * -speed, env->player.camera.angle_z * speed), motion, 0);
		env->player.pos.x += move.x;
		env->player.pos.y += move.y;
		if (env->player.state.fly)
			env->player.pos.z += move.z;
		if (move.x != 0 || move.y != 0)
			movement = 1;
		if (move.x == 0 && move.y == 0)
			check_blocage(env, motion, time, 2);
	}
	if (env->inputs.left && !env->inputs.right)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_sin * speed,
					env->player.camera.angle_cos * -speed, 0), motion, 0);
		env->player.pos.x += move.x;
		env->player.pos.y += move.y;
		if (move.x != 0 || move.y != 0)
			movement = 1;
		if (move.x == 0 && move.y == 0)
			check_blocage(env, motion, time, 3);
	}
	else if (env->inputs.right && !env->inputs.left)
	{
		move = check_collision(env, new_v3(env->player.camera.angle_sin * -speed,
					env->player.camera.angle_cos * speed, 0), motion, 0);
		env->player.pos.x += move.x;
		env->player.pos.y += move.y;
		if (move.x != 0 || move.y != 0)
			movement = 1;
		if (move.x == 0 && move.y == 0)
			check_blocage(env, motion, time, 4);
	}
	if (env->player.stuck || get_sector_no_z_origin(env, env->player.pos, env->player.sector) == -1)
	{
		env->player.stuck = 0;
		env->player.pos = env->player.old_pos;
		env->player.sector = get_sector_no_z_origin(env, env->player.pos, prev_sector);
	}
	if (!movement && (env->player.state.climb || env->player.state.drop))
		movement = 1;
	if (movement)
			update_player_pos(env);
}
