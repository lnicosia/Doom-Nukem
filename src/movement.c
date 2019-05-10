/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:19:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/10 14:13:27 by lnicosia         ###   ########.fr       */
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

	if (is_in_sector(env, env->player.sector, env->player.pos.x + (env->player.angle_cos * env->camera.near_z), env->player.pos.y + (env->player.angle_sin * env->camera.near_z)))
		return (env->player.sector);
	i = 0;
	return (-1);
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

	tmp_speed = env->player.speed;
	sector = env->sectors[env->player.sector];
	if (env->inputs.forward)
	{	
		if (check_collision(env, env->player.angle_cos * env->player.speed, env->player.angle_sin * env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_cos * env->player.speed;
			env->player.pos.y += env->player.angle_sin * env->player.speed;
		}
	}
	if (env->inputs.backward)
	{
		if (check_collision(env, env->player.angle_cos * -env->player.speed, env->player.angle_sin * -env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_cos * env->player.speed;
			env->player.pos.y -= env->player.angle_sin * env->player.speed;
		}
	}
	if (env->inputs.left)
	{
		if (check_collision(env, env->player.angle_sin * env->player.speed, env->player.angle_cos * -env->player.speed) == 1)
		{
			env->player.pos.x += env->player.angle_sin * env->player.speed;
			env->player.pos.y -= env->player.angle_cos * env->player.speed;
		}
	}
	if (env->inputs.right)
	{
		if (check_collision(env, env->player.angle_sin * -env->player.speed, env->player.angle_cos * env->player.speed) == 1)
		{
			env->player.pos.x -= env->player.angle_sin * env->player.speed;
			env->player.pos.y += env->player.angle_cos * env->player.speed;
		}
	}
	env->player.speed = tmp_speed;
	env->player.camera_sector = get_camera_sector(env);
	sector = env->sectors[env->player.sector];
	v0 = env->vertices[sector.vertices[0]];
	env->player.pos.z = 6 + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
}
