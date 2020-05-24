/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:38:46 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/28 18:44:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include <math.h>

/*
** Checks if the point p is on the segment v1 v2
*/

int		point_on_segment(t_v2 v1, t_v2 v2, t_v2 p)
{
	double d1;
	double d2;
	double linelen;
	double buffer;

	d1 = distance_two_points_2d(p.x, p.y, v1.x, v1.y);
	d2 = distance_two_points_2d(p.x, p.y, v2.x, v2.y);
	linelen = distance_two_points_2d(v1.x, v1.y, v2.x, v2.y);
	buffer = 0.1;
	if (d1 + d2 >= linelen - buffer && d1 + d2 <= linelen + buffer)
		return (1);
	return (0);
}

/*
**	Checks if there's an intersection between a circle and a segment
**	v1 and v2 being the two extremities of the circle
**	p being the center of the circle, size being the radius of the circle
** The function returns 1 if there's an intersection
*/

int		hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p, double radius)
{
	double	len;
	double	dot;
	double	closestx;
	double	closesty;
	double	distance;

	if (distance_two_points_2d(v1.x, v1.y, p.x, p.y) <= radius ||
		distance_two_points_2d(v2.x, v2.y, p.x, p.y) <= radius)
		return (1);
	len = distance_two_points_2d(v1.x, v1.y, v2.x, v2.y);
	dot = (((p.x - v1.x) * (v2.x - v1.x))
		+ ((p.y - v1.y) * (v2.y - v1.y))) / (len * len);
	closestx = v1.x + (dot * (v2.x - v1.x));
	closesty = v1.y + (dot * (v2.y - v1.y));
	if (!point_on_segment(v1, v2, new_v2(closestx, closesty)))
		return (0);
	distance = distance_two_points_2d(closestx, closesty, p.x, p.y);
	if (distance <= radius)
		return (1);
	return (0);
}

/*
** Returns the distance between two points in two dimensions
** x1 y1 are the coordinates of the first point
** x2 y2 are the coordinates of the second point
*/

double	distance_two_points_2d(double x1, double y1, double x2, double y2)
{
	double	d;
	double	x_sub;
	double	y_sub;

	x_sub = x2 - x1;
	y_sub = y2 - y1;
	d = sqrt(x_sub * x_sub + y_sub * y_sub);
	return (d);
}

/*
** Returns the norm of a vector
*/

double	norm_vector(double x, double y)
{
	return (sqrt(x * x + y * y));
}

/*
** Rotates a vector so that it becomes parallel to another
*/

t_v3	parallel_movement(t_env *env, t_v3 move, int sect, int i)
{
	double	norm_move;
	double	norm_wall;
	double	scalar;
	double	wall_x;
	double	wall_y;

	wall_x =
		env->vertices[env->sectors[sect].vertices[i + 1]].x
		- env->vertices[env->sectors[sect].vertices[i]].x;
	wall_y =
		env->vertices[env->sectors[sect].vertices[i + 1]].y
		- env->vertices[env->sectors[sect].vertices[i]].y;
	norm_move = norm_vector(move.x, move.y);
	norm_wall = norm_vector(wall_x, wall_y);
	scalar = wall_x / norm_wall * move.x / norm_move +
		wall_y / norm_wall * move.y / norm_move;
	if (scalar != 0)
	{
		move.x = norm_move * wall_x / norm_wall * scalar;
		move.y = norm_move * wall_y / norm_wall * scalar;
	}
	else
		return (new_v3(0, 0, 0));
	return (move);
}
