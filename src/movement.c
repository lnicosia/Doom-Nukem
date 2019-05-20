/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/20 15:45:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

/*
**	Returns camera sector according to the last player movement
*/

int		get_camera_sector(t_env *env)
{
	int		i;

	if (is_in_sector(env, env->player.sector, env->player.camera_x, env->player.camera_y))
		return (env->player.sector);
	i = 0;
	while (i < env->sectors[env->player.sector].nb_vertices)
	{
		if (env->sectors[env->player.sector].neighbors[i] >= 0)
		{
			if (is_in_sector(env, env->sectors[env->player.sector].neighbors[i], env->player.camera_x, env->player.camera_y))
				return (env->sectors[env->player.sector].neighbors[i]);
		}
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector(env, i, env->player.camera_x, env->player.camera_y) && env->player.pos.z > env->sectors[i].floor_min)
			return (i);
		i++;
	}
	return (env->player.sector);
}

/*
**	Update camera's position (save some computings)
*/

void	update_camera_position(t_env *env)
{
	env->player.camera_x = env->player.pos.x + env->player.angle_cos * env->camera.near_z;
	env->player.camera_y = env->player.pos.y + env->player.angle_sin * env->camera.near_z;
}

/*
** Contains calculs to allow a jump
*/
void	jump(t_env *env, t_sector sector, t_vertex v0)
{
	double	x;

	x = 2;
	env->jump.on_going = 1;
	if (env->jump.start == 0)
		env->jump.start = SDL_GetTicks();
	env->jump.end = SDL_GetTicks();
	if (env->jump.end < env->jump.start + 150 && env->flag == 0)
	{
		env->player.gravity
		env->z += x;
	}
	if (env->jump.end > env->jump.start + 150 && env->flag == 0)
		env->flag = 1;
	if (env->z > env->player.z && env->flag == 1)
		env->z -= x * env->player.gravity;
	if (env->jump.end > env->jump.start + 500)
	{
		env->flag = 0;
		env->jump.start = 0;
		env->jump.on_going = 0;
	}
	env->player.pos.z = env->z + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
}

void	squat(t_env *env, t_sector sector, t_vertex v0)
{
	env->squat.on_going = 1;
	if (env->squat.start == 0)
		env->squat.start = SDL_GetTicks() / 5;
	env->squat.end = SDL_GetTicks() / 5;
	if (env->flag == 0)
	{
		if (env->squat.end < env->squat.start + 30 && env->z > 2)
			env->z -= 1;
		if (env->z == 2)
			env->flag = 1;
	}		
	else if (env->flag == 1)
	{
		if (env->squat.end < env->squat.start + 30 && env->z < env->player.z)
			env->z += 1;
		if (env->z == env->player.z)
			env->flag = 0;
	}
	if (env->squat.end > env->squat.start + 30 )
	{
		env->squat.start = 0;
		env->squat.on_going = 0;
	}
	env->player.pos.z = env->z + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
}

/*
**	Handles player movements
**	TODO Protection / return values??
*/


void	move_player(t_env *env)
{
	t_sector	sector;
	t_vertex	v0;
	double		tmp_speed;
	int			movement;

	tmp_speed = env->player.speed;
	sector = env->sectors[env->player.sector];
	movement = 0;
	if (env->inputs.forward)
	{	
		if (check_collision(env, env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_cos * env->player.speed;
			env->player.pos.y += env->player.angle_sin * env->player.speed;
			movement = 1;
		}
	}
	if (env->inputs.backward)
	{
		if (check_collision(env, env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_cos * env->player.speed;
			env->player.pos.y -= env->player.angle_sin * env->player.speed;
			movement = 1;
		}
	}
	if (env->inputs.left)
	{
		if (check_collision(env, env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_sin * env->player.speed;
			env->player.pos.y -= env->player.angle_cos * env->player.speed;
			movement = 1;
		}
	}
	if (env->inputs.right)
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
		update_camera_position(env);
		env->player.camera_sector = get_camera_sector(env);
	}
	if (env->inputs.space || env->jump.on_going == 1)
	{
		v0 = env->vertices[sector.vertices[0]];
		jump(env, sector, v0);
	}
	if (env->inputs.ctrl || env->squat.on_going == 1)
	{
		v0 = env->vertices[sector.vertices[0]];
		squat(env, sector, v0);
	}
	else
		env->player.pos.z = env->z + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
	env->player.speed = tmp_speed;
	sector = env->sectors[env->player.sector];
	v0 = env->vertices[sector.vertices[0]];
}
