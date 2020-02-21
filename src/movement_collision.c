/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/21 10:33:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		check_ceiling(t_env *env, t_movement motion, int sector_dest)
{
	if (motion.future.z + motion.eyesight >
		get_ceiling_at_pos(env->sectors[sector_dest], motion.future, env) - 1)
		return (0);
	return (1);
}

int		check_floor(t_env *env, t_movement motion, int sector_dest)
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
**	1 == collision
*/

int     hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p, double size)
{
	t_circle_vars	eq;
	double			delta;
	double			sqrt_delta;
	double			t1;
	double			t2;

	v1.x -= p.x;
	v1.y -= p.y;
	v2.x -= p.x;
	v2.y -= p.y;
	eq.c = v1.x * v1.x + v1.y * v1.y - size * size;
	eq.b = 2 * (v1.x * (v2.x - v1.x) + v1.y * (v2.y - v1.y));
	eq.a = (v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y);
	delta = eq.b * eq.b - 4 * eq.a * eq.c;
	if (delta <= 0)
		return (0);
	sqrt_delta = sqrt(delta);
	t1 = (-eq.b + sqrt_delta) / (2 * eq.a);
	t2 = (-eq.b - sqrt_delta) / (2 * eq.a);
	if ((0 < t1 && t1 < 1) || (0 < t2 && t2 < 1))
		return (1);
	return (0);
}

int		check_objects(t_env *env, t_v3 move, t_movement motion)
{
	int		i;
	t_v3	futur;
	double	eyesight;

	i = 0;
	futur.x = move.x + motion.pos.x;
	futur.y = move.y + motion.pos.y;
	futur.z = move.z + motion.pos.z;
	eyesight = motion.eyesight;
	while (i < env->nb_objects)
	{
		if (env->objects[i].exists)// && env->objects[i].solid)
		{
			if (distance_two_points_2d(env->objects[i].pos.x,
				env->objects[i].pos.y, futur.x, futur.y) < env->objects[i].size_2d + motion.size_2d &&
				((motion.pos.z <= env->objects[i].pos.z + env->objects[i].height && motion.pos.z >= env->objects[i].pos.z) ||
				(motion.pos.z + eyesight + 1 <= env->objects[i].pos.z + env->objects[i].height && motion.pos.z + eyesight + 1 >= env->objects[i].pos.z)))
			{
				if (!env->player.colliding_objects[i]
					&& env->objects[i].nb_collision_events > 0
					&& env->objects[i].collision_events)
				{
				}
				env->player.colliding_objects[i] = 1;
				if (env->objects[i].solid)
					return (0);
			}
		}
		i++;
	}
	return (1);
}

t_v3	collision_rec(t_env *env, t_v3 move, t_movement motion, int recu)
{
    int       i;
    t_wall      wall;
    double      scalar;
    double      norme_mov;
    double      norme_wall;

	i = 0;
	wall = motion.wall;
	motion.future.x = move.x + motion.pos.x;
	motion.future.y = move.y + motion.pos.y;
	motion.future.z = move.z + motion.pos.z;
	env->sector_list[wall.sector_dest] = 1;
	norme_mov = sqrt(move.x * move.x + move.y * move.y);
	if ((!check_ceiling(env, motion, wall.sector_dest) ||
		!check_floor(env, motion, wall.sector_dest)) && !recu)
	{
		scalar = wall.x / wall.norme * move.x / norme_mov +
			wall.y / wall.norme * move.y / norme_mov;
		if (scalar != 0 && !recu)
		{
			move.x = norme_mov * wall.x / wall.norme * scalar;
			move.y = norme_mov * wall.y / wall.norme * scalar;
			return (collision_rec(env, move, motion, 1));
		}
		return (new_v3(0, 0, 0));
	}
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if ((hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R),
			new_v2(motion.future.x, motion.future.y), motion.size_2d) ||
			intersection_check(new_v2(X1R, Y1R), new_v2(X2R, Y2R),
			new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y))) &&
			(RNEIGHBOR < 0 || (env->sectors[wall.sector_dest].portals[i] == 0 &&
			env->sectors[wall.sector_dest].portals[i] != wall.sector_or)))
		{
			norme_wall = sqrt((X2R - X1R) * (X2R - X1R) + (Y2R - Y1R) * (Y2R - Y1R));
			scalar = (X2R - X1R) / norme_wall * move.x / norme_mov +
				(Y2R - Y1R) / norme_wall * move.y / norme_mov;
			if (scalar != 0 && !recu)
			{
				move.x = norme_mov * (X2R - X1R) / norme_wall * scalar;
				move.y = norme_mov * (Y2R - Y1R) / norme_wall * scalar;
				return (collision_rec(env, move, motion, 1));
			}
			return (new_v3(0, 0, 0));
		}
		i++;
	}
	i = 0;
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(motion.future.x, motion.future.y), motion.size_2d) && RNEIGHBOR >= 0 &&
			env->sector_list[RNEIGHBOR] == 0 && env->sectors[wall.sector_dest].portals[i] == 1)
		{
			if ((!check_ceiling(env, motion, wall.sector_dest) || !check_floor(env, motion, RNEIGHBOR)))
				return (new_v3(0, 0, 0));
			motion.wall.sector_or = wall.sector_dest;
			motion.wall.sector_dest = RNEIGHBOR;
			return (collision_rec(env, move, motion, 0));
		}
		i++;
	}
	return (move);
}

t_v3	check_collision(t_env *env, t_v3 move, t_movement motion, int rec)
{
    int		i;
    double      scalar;
    double      norme_mov;
    double      norme_wall;

	motion.future.x = motion.pos.x + move.x;
	motion.future.y = motion.pos.y + move.y;
	motion.future.z = motion.pos.z + move.z;
	i = 0;
	init_sector_list(env, motion.sector);
	if (motion.sector == -1)
		return (new_v3(0, 0, 0));
	if (get_ceiling_at_pos(env->sectors[motion.lowest_ceiling], motion.future, env) -
		get_floor_at_pos(env->sectors[motion.sector], motion.future, env) < motion.eyesight + 1)
	return (new_v3(0, 0, 0));
	if (!check_ceiling(env, motion, motion.lowest_ceiling))
		move.z = get_ceiling_at_pos(env->sectors[motion.lowest_ceiling], motion.pos, env) - 1 - (motion.pos.z + motion.eyesight);
	if (!check_floor(env, motion, motion.sector) && motion.flight)
		move.z = get_floor_at_pos(env->sectors[motion.sector], motion.pos, env) - motion.pos.z;
	else if (!(check_floor(env, motion, motion.sector)))
		return (new_v3(0, 0, 0));
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if (((hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(motion.future.x, motion.future.y), motion.size_2d)) ||
			intersection_check(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y))) &&
			(NEIGHBOR < 0 || env->sectors[motion.sector].portals[i] == 0))
		{
			norme_mov = sqrt(move.x * move.x + move.y * move.y);
			norme_wall = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
			scalar = (X2 - X1) / norme_wall * move.x / norme_mov + (Y2 - Y1) / norme_wall * move.y / norme_mov;
			if (scalar != 0 && !rec)
			{
				move.x = norme_mov * (X2 - X1) / norme_wall * scalar;
				move.y = norme_mov * (Y2 - Y1) / norme_wall * scalar;
				return (check_collision(env, move, motion, 1));
			}
			return (new_v3(0, 0, 0));
		}
		i++;
	}
	i = 0;
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if (((hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(motion.future.x, motion.future.y), motion.size_2d) ||
			intersection_check(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y)))) &&
			NEIGHBOR >= 0 && env->sectors[motion.sector].portals[i] == 1)
		{
			motion.wall.sector_or = motion.sector;
			motion.wall.sector_dest = NEIGHBOR;
			motion.wall.norme = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
			motion.wall.x = (X2 - X1);
			motion.wall.y = (Y2 - Y1);
			move = collision_rec(env, move, motion, 0);
			if (move.x == 0 && move.y == 0)
				return (new_v3(0, 0, 0));
		}
		i++;
	}
	if (check_objects(env, move, motion))
		return (move);
	return (new_v3(0, 0, 0));
}
