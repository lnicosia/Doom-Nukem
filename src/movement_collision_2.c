/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:54:00 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/28 18:35:59 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
** This function returns 0 if the floor is too high and 1 if it isn't
*/

static int	check_floor(t_env *env, t_motion motion, int sector_dest)
{
	double	floor;

	floor = get_floor_at_pos(env->sectors[sector_dest], motion.future, env);
	if (floor > motion.future.z + 2 && sector_dest != motion.sector)
		return (0);
	else if ((floor > motion.future.z + 0.5 && sector_dest == motion.sector &&
		!motion.flight) ||
		(floor > motion.future.z && sector_dest == motion.sector &&
		motion.flight))
		return (0);
	if (env->player.state.jump && motion.future.z < floor)
		return (0);
	return (1);
}

/*
** This function returns 1 if the ceiling is high enough and 0 if it is too low
*/

int		check_ceiling(t_env *env, t_motion motion, int sector_dest)
{
	if (motion.future.z + motion.eyesight >
		get_ceiling_at_pos(env->sectors[sector_dest], motion.future, env) - 1)
		return (0);
	return (1);
}

/*
** Returns 1 if the entity movement vector cross a portal in a given sector
** or if the entity hitbox intersects with the portal
** s being the sector
** v being the first vertex of the tested portal, v + 1 is the second vertex
** motion contains the different stats of the entity which is moving
*/

int		cross_portal(t_env *env, t_motion motion, int s, int v)
{
	if (env->sector_list[env->sectors[s].neighbors[v]])
		return (0);
	if ((intersection_check(new_v2(env->vertices[env->sectors[s].vertices[v]].x,
		env->vertices[env->sectors[s].vertices[v]].y),
		new_v2(env->vertices[env->sectors[s].vertices[v + 1]].x,
		env->vertices[env->sectors[s].vertices[v + 1]].y),
		new_v2(motion.pos.x, motion.pos.y),
		new_v2(motion.future.x, motion.future.y))
		|| hitbox_collision(new_v2(env->vertices[env->sectors[s].vertices[v]].x,
		env->vertices[env->sectors[s].vertices[v]].y),
		new_v2(env->vertices[env->sectors[s].vertices[v + 1]].x,
		env->vertices[env->sectors[s].vertices[v + 1]].y),
		new_v2(motion.future.x, motion.future.y), motion.size_2d))
		&& (env->sectors[s].neighbors[v] >= 0 && env->sectors[s].portals[v]))
		return (1);
	return (0);
}

/*
** Returns 1 if the entity movement vector cross a wall in a given sector
** or if the entity hitbox intersects with the wall
** s being the sector
** v being the first vertex of the tested wall, v + 1 is the second vertex
** motion contains the different stats of the entity which is moving
*/

int		cross_wall(t_env *env, t_motion motion, int s, int v)
{
	if ((intersection_check(new_v2(env->vertices[env->sectors[s].vertices[v]].x,
		env->vertices[env->sectors[s].vertices[v]].y),
		new_v2(env->vertices[env->sectors[s].vertices[v + 1]].x,
		env->vertices[env->sectors[s].vertices[v + 1]].y),
		new_v2(motion.pos.x, motion.pos.y),
		new_v2(motion.future.x, motion.future.y))
		|| hitbox_collision(new_v2(env->vertices[env->sectors[s].vertices[v]].x,
		env->vertices[env->sectors[s].vertices[v]].y),
		new_v2(env->vertices[env->sectors[s].vertices[v + 1]].x,
		env->vertices[env->sectors[s].vertices[v + 1]].y),
		new_v2(motion.future.x, motion.future.y), motion.size_2d))
		&& (env->sectors[s].neighbors[v] < 0
		|| env->sectors[s].portals[v] == 0))
		return (1);
	return (0);
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

/*
** CHecks both the ceiling and the floor
*/

int		check_floor_ceil(t_env *env, t_motion motion, int sector_dest)
{
	if (!check_floor(env, motion, sector_dest)
		|| !check_ceiling(env, motion, sector_dest))
		return (0);
	return (1);
}

/*
** sets the values of sect and i by receiving their address
** Returns 0 if the floor or the ceiling is too high/low for the entity
** returns 1 if the movement is possible
*/

int		testing_portal_slide(t_env *env, t_motion motion, int *sect, int *i)
{
	if (!check_floor_ceil(env, motion, env->sectors[*sect].neighbors[*i]))
		return (0);
	env->sector_list[env->sectors[*sect].neighbors[*i]] = 1;
	*sect = env->sectors[*sect].neighbors[*i];
	*i = -1;
	return (1);
}

/*
** Returns movement vector of an entity after checking if the entity collides
** with somithing in the map
** move is the initial movemement vector
** motion contains the stats of the moving entity (hitbox_size, sector, etc...)
*/

t_v3	check_collision_slide(t_env *env, t_v3 move, t_motion motion, int sect)
{
	int		i;
	int		o_sect;

	o_sect = sect;
	motion.future = calculate_motion_future(motion, move);
	i = 0;
	while (i < env->sectors[sect].nb_vertices)
	{
		if (cross_wall(env, motion, sect, i))
			return (new_v3(0, 0, 0));
		if (cross_portal(env, motion, sect, i))
			if (!testing_portal_slide(env, motion, &sect, &i))
				return (new_v3(0, 0, 0));
		if (++i >= env->sectors[sect].nb_vertices && sect != o_sect)
		{
			i = 0;
			sect = o_sect;
		}
	}
	return (move);
}

/*
** Returns the movomement along the z axis by checking if the entity is
** flying, following a slope.
*/

t_v3	collisions_z_axis(t_env *env, t_motion motion, t_v3 move)
{
	if (get_ceiling_at_pos(env->sectors[motion.lowest_ceiling],
		motion.future, env) - get_floor_at_pos(env->sectors[motion.sector],
		motion.future, env) < motion.eyesight + 1)
		return (new_v3(0, 0, 0));
	if (!check_ceiling(env, motion, motion.lowest_ceiling))
		move.z =
			get_ceiling_at_pos(env->sectors[motion.lowest_ceiling],
			motion.pos, env) - 1 - (motion.pos.z + motion.eyesight);
	if (!check_floor(env, motion, motion.sector) && motion.flight)
		move.z = get_floor_at_pos(env->sectors[motion.sector], motion.pos, env)
		- motion.pos.z;
	else if (!(check_floor(env, motion, motion.sector)))
		return (new_v3(0, 0, 0));
	return (move);
}

/*
** Update_move returns the future pos of the entity after sliding alongside
** a wall and checking if the movement is possible
*/

t_v3	update_move(t_env *env, t_coll coll, t_v3 *move)
{
	*move = parallel_movement(env, *move, coll.sector, coll.vertex);
	*move = check_collision_slide(env, *move, coll.motion, coll.sector);
	return (calculate_motion_future(coll.motion, *move));
}

/*
** addr.s is the number of the sector being checked
** addr.v is the number of the vertex being checked
** Thank you norminette for this horrendous code
*/

void	testing_portal(t_env *env, t_v3 *move, t_coll_addr addr)
{
	if (!check_floor_ceil(env, *(addr.motion),
		env->sectors[*(addr.s)].neighbors[*(addr.v)]))
		addr.motion->future = update_move(env, new_c(*(addr.s),
		*(addr.v), *(addr.motion)), move);
	else
	{
		env->sector_list[env->sectors[*(addr.s)].neighbors[(*addr.v)]] = 1;
		*(addr.s) = env->sectors[*(addr.s)].neighbors[*(addr.v)];
		*(addr.v) = -1;
	}
}

void	reset_loop(int *i, int *sector, t_motion motion)
{
	*i = 0;
	*sector = motion.sector;
}

/*
** Returns movement vector of an entity after checking if the entity collides
** with somithing in the map
** move is the initial movemement vector
** motion contains the stats of the moving entity (hitbox_size, sector, etc...)
*/

t_v3	check_collision(t_env *env, t_v3 move, t_motion motion)
{
	int		sect;
	int		i;

	if ((sect = motion.sector) < 0)
		return (new_v3(0, 0, 0));
	motion.future = calculate_motion_future(motion, move);
	init_sector_list(env, sect);
	move = collisions_z_axis(env, motion, move);
	if (move.x == 0 && move.y == 0 && move.z == 0)
		return (move);
	i = 0;
	while (i < env->sectors[sect].nb_vertices)
	{
		if (cross_wall(env, motion, sect, i))
			motion.future = update_move(env, new_c(sect, i, motion), &move);
		if (cross_portal(env, motion, sect, i))
			testing_portal(env, &move, new_coll_addr(&motion, &sect, &i));
		if (++i >= env->sectors[sect].nb_vertices && sect != motion.sector)
			reset_loop(&i, &sect, motion);
		if (move.x == 0 && move.y == 0)
			return (move);
	}
	return ((check_objects(env, move, motion)) ? move : new_v3(0, 0, 0));
}

int		check_objects(t_env *env, t_v3 move, t_motion motion)
{
	int		i;
	t_v3	futur;
	double	eyesight;

	i = 0;
	futur = calculate_motion_future(motion, move);
	eyesight = motion.eyesight;
	while (i < env->nb_objects)
	{
		if (env->objects[i].exists && env->objects[i].solid)
		{
			if (distance_two_points_2d(env->objects[i].pos.x,
				env->objects[i].pos.y, futur.x, futur.y) <
				env->objects[i].size_2d + motion.size_2d &&
				((motion.pos.z <= env->objects[i].pos.z +
				env->objects[i].height && motion.pos.z >=
				env->objects[i].pos.z) || (motion.pos.z + eyesight + 1 <=
				env->objects[i].pos.z + env->objects[i].height && motion.pos.z +
				eyesight + 1 >= env->objects[i].pos.z)))
				return (0);
		}
		i++;
	}
	return (1);
}
