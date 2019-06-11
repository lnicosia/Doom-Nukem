/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/11 11:08:21 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

/*
 **	Returns camera sector according to the last player movement
 */

int		get_sector(t_env *env, t_v2 p)
{
	int		i;

	if (is_in_sector(env, env->player.sector, p.x, p.y))
		return (env->player.sector);
	i = 0;
	while (i < env->sectors[env->player.sector].nb_vertices)
	{
		if (env->sectors[env->player.sector].neighbors[i] >= 0)
		{
			if (is_in_sector(env, env->sectors[env->player.sector].neighbors[i], p.x, p.y))
				return (env->sectors[env->player.sector].neighbors[i]);
		}
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector(env, i, p.x, p.y) && env->player.pos.z > env->sectors[i].floor_min)
			return (i);
		i++;
	}
	return (-1);
}

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
	if (((env->inputs.ctrl && !env->player.state) || env->squat.on_going) && !env->jump.on_going)
		squat(env);
}

/*
 **	Handles player movements
 **	TODO Protection / return values??
 */

void	move_player(t_env *env)
{
	t_v3		origin_pos;
	short		origin_camera_sect;
	short		origin_left_sect;
	short		origin_right_sect;
	short		origin_sect;
	double		tmp_speed;
	int			movement;

	tmp_speed = env->player.speed;
	movement = 0;
	origin_pos = env->player.pos;
	origin_sect = env->player.sector;
	origin_camera_sect = env->player.camera_sector;
	origin_right_sect = env->player.near_left_sector;
	origin_left_sect = env->player.near_right_sector;
	if (env->inputs.forward && !env->inputs.backward)
	{	
		if (check_collision(env, env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_cos * env->player.speed;
			env->player.pos.y += env->player.angle_sin * env->player.speed;
			movement = 1;
		}
	}
	else if (env->inputs.backward && !env->inputs.forward)
	{
		if (check_collision(env, env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_cos * env->player.speed;
			env->player.pos.y -= env->player.angle_sin * env->player.speed;
			movement = 1;
		}
	}
	if (env->inputs.left && !env->inputs.right)
	{
		if (check_collision(env, env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_sin * env->player.speed;
			env->player.pos.y -= env->player.angle_cos * env->player.speed;
			movement = 1;
		}
	}
	else if (env->inputs.right && !env->inputs.left)
	{
		if (check_collision(env, env->player.angle_sin * -env->player.speed, env->player.angle_cos * env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_sin * env->player.speed;
			env->player.pos.y += env->player.angle_cos * env->player.speed;
			movement = 1;
		}
	}
	if (movement)
	{
		//Mix_PlayChannel(0, env->sound.footstep, 0);
		update_camera_position(env);
		/*env->player.camera_sector = get_sector(env, new_v2(env->player.camera_x, env->player.camera_y));
		  env->player.near_left_sector = get_sector(env, new_v2(env->player.near_left.x, env->player.near_left.y));
		  env->player.near_right_sector = get_sector(env, new_v2(env->player.near_right.x, env->player.near_right.y));
		  if (env->player.near_left_sector == -1 || env->player.near_right_sector == -1)
		  {
		  env->player.pos = origin_pos; 
		  env->player.sector = origin_sect;
		  env->player.camera_sector = origin_camera_sect;
		  env->player.near_left_sector = origin_left_sect;
		  env->player.near_right_sector = origin_right_sect;
		  }*/
	}
	env->player.speed = tmp_speed;
}
