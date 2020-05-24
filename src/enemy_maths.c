/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:39:22 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 10:48:29 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include "enemies.h"
#include <math.h>

/*
** Checks if a segment cross a sector and if it cross only portals and no walls
** Returns 1 if it crosses the sector properly and 0 otherwise
*/

int		check_segment_in_sector(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
	int			i;
	int			count;
	t_segment	ray;
	t_segment	wall;

	i = -1;
	count = 0;
	ray.p1.x = enemy.x;
	ray.p1.y = enemy.y;
	ray.p2.x = player.x;
	ray.p2.y = player.y;
	while (++i < env->sectors[sector].nb_vertices)
	{
		wall = new_wall_segment(env, sector, i);
		if (intersection_check(ray.p1, ray.p2, wall.p1, wall.p2))
		{
			if (env->sectors[sector].neighbors[i] < 0)
				return (-1);
			else
				count++;
		}
		if (count == 2)
			return (1);
	}
	return (0);
}

int		direction_of_point(t_v2 a, t_v2 b, t_v2 p)
{
	int cross_product;

	b.x -= a.x;
	b.y -= a.y;
	p.x -= a.x;
	p.y -= a.y;
	cross_product = b.x * p.y - b.y * p.x;
	if (cross_product > 0)
		return (1);
	if (cross_product < 0)
		return (-1);
	return (0);
}

/*
** the function computes the coordinates of the two extremites of an enemy fov
** nb is the number of the enemy
*/

void	enemy_far_left_right(t_env *env, int nb)
{
	double angle_left;
	double angle_right;

	angle_left = env->enemies[nb].angle + 65;
	angle_right = env->enemies[nb].angle - 65;
	angle_left -= (angle_left > 360) ? 360 : 0;
	angle_right += (angle_right < 360) ? 360 : 0;
	env->enemies[nb].far_left.x = 1000 * cos(angle_left * CONVERT_RADIANS)
		+ env->enemies[nb].pos.x;
	env->enemies[nb].far_left.y = 1000 * sin(angle_left * CONVERT_RADIANS)
		+ env->enemies[nb].pos.y;
	env->enemies[nb].far_right.x = 1000 * cos(angle_right * CONVERT_RADIANS)
		+ env->enemies[nb].pos.x;
	env->enemies[nb].far_right.y = 1000 * sin(angle_right * CONVERT_RADIANS)
		+ env->enemies[nb].pos.y;
}

/*
** Increments left or right if a point is on the left or right side of a line
*/

void	relative_pos(int direction, int *left, int *right)
{
	if (direction < 0)
		(*left)++;
	else if (direction > 0)
		(*right)++;
	else
	{
		(*left)++;
		(*right)++;
	}
}

/*
** Computes the z angle of the enemy
*/

double	enemy_angle_z(t_env *env, int i)
{
	double	dist_enemy_player;
	double	diff_z;
	double	angle_z;

	dist_enemy_player = distance_two_points_2d(env->enemies[i].pos.x,
		env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
	diff_z = (env->enemies[i].pos.z + env->enemies[i].eyesight)
		- (env->player.pos.z + env->player.eyesight);
	if (dist_enemy_player != 0)
		angle_z = diff_z / dist_enemy_player;
	else
		angle_z = 0;
	return (angle_z);
}
