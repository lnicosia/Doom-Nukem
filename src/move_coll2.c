/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/26 18:01:21 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		check_floor(t_env *env, t_motion motion, int sector_dest)
{
	double	floor;

	floor = get_floor_at_pos(&env->sectors[sector_dest], motion.future, env);
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
/*
t_coll		check_walls_collisions_rec(t_env *env, t_motion motion, t_v3 move, int recu)
{
	int i;
	double	norme_wall;
	double	scalar;
	double	norme_mov;
	t_wall	wall;

	i = 0;
	wall = motion.wall;
	norme_mov = sqrt(move.x * move.x + move.y * move.y);
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if ((hitbox_collision(new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i]].x, env->vertices[env->sectors[wall.sector_dest].vertices[i]].y), new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x, env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y),
			new_v2(motion.future.x, motion.future.y), motion.size_2d) ||
			intersection_check(new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i]].x, env->vertices[env->sectors[wall.sector_dest].vertices[i]].y), new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x, env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y),
			new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y))) &&
			(env->sectors[wall.sector_dest].neighbors[i] < 0 || (env->sectors[wall.sector_dest].portals[i] == 0 &&
			env->sectors[wall.sector_dest].portals[i] != wall.sector_or)))
		{
			norme_wall = sqrt((env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x -
			env->vertices[env->sectors[wall.sector_dest].vertices[i]].x) *
			(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x -
			env->vertices[env->sectors[wall.sector_dest].vertices[i]].x) +
			(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y - env->vertices[env->sectors[wall.sector_dest].vertices[i]].y) *
			( env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y - env->vertices[env->sectors[wall.sector_dest].vertices[i]].y));
			scalar = (env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x - env->vertices[env->sectors[wall.sector_dest].vertices[i]].x) / norme_wall * move.x / norme_mov +
				(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y - env->vertices[env->sectors[wall.sector_dest].vertices[i]].y) / norme_wall * move.y / norme_mov;
			if (scalar != 0 && !recu)
			{
				move.x = norme_mov * (env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x - env->vertices[env->sectors[wall.sector_dest].vertices[i]].x) / norme_wall * scalar;
				move.y = norme_mov * (env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y - env->vertices[env->sectors[wall.sector_dest].vertices[i]].y) / norme_wall * scalar;
				return (new_coll(1, collision_rec(env, move, motion, 1)));
			}
			return (new_coll(1, new_v3(0, 0, 0)));
		}
		i++;
	}
	return (new_coll(0, new_v3(0, 0, 0)));
}

t_coll		check_portals_collisions_rec(t_env *env, t_motion motion, t_v3 move)
{
	int i;
	t_wall	wall;

	i = 0;
	wall = motion.wall;
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if (hitbox_collision(new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i]].x,
			env->vertices[env->sectors[wall.sector_dest].vertices[i]].y),
			new_v2(env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x, env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y),
			new_v2(motion.future.x, motion.future.y), motion.size_2d) &&
			env->sectors[wall.sector_dest].neighbors[i] >= 0 &&
			env->sector_list[env->sectors[wall.sector_dest].neighbors[i]] == 0 &&
			env->sectors[wall.sector_dest].portals[i] == 1)
		{
			if ((!check_ceiling(env, motion, wall.sector_dest) ||
			!check_floor(env, motion, env->sectors[wall.sector_dest].neighbors[i])))
				return (new_coll(1, new_v3(0, 0, 0)));
			motion.wall.sector_or = wall.sector_dest;
			motion.wall.sector_dest = env->sectors[wall.sector_dest].neighbors[i];
			return (new_coll(1, collision_rec(env, move, motion, 0)));
		}
		i++;
	}
	return (new_coll(0, new_v3(0, 0, 0)));
}*/

/*
t_v3	collision_rec(t_env *env, t_v3 move, t_motion motion, int recu)
{
    t_coll      coll;
    double      scalar;
    double      norme_mov;

	motion.future = calculate_motion_future(motion, move);
	env->sector_list[motion.wall.sector_dest] = 1;
	norme_mov = sqrt(move.x * move.x + move.y * move.y);
	if ((!check_ceiling(env, motion, motion.wall.sector_dest) ||
		!check_floor(env, motion, motion.wall.sector_dest)) && !recu)
	{
		scalar = motion.wall.x / motion.wall.norme * move.x / norme_mov +
			motion.wall.y / motion.wall.norme * move.y / norme_mov;
		if (scalar != 0 && !recu)
		{
			move.x = norme_mov * motion.wall.x / motion.wall.norme * scalar;
			move.y = norme_mov * motion.wall.y / motion.wall.norme * scalar;
			return (collision_rec(env, move, motion, 1));
		}
		return (new_v3(0, 0, 0));
	}
	coll = check_walls_collisions_rec(env, motion, move, recu);
	if (coll.use)
		return (coll.move);
	coll = check_portals_collisions_rec(env, motion, move);
	return ((coll.use) ? coll.move : move);
	return (move);
}
*/

/*
t_coll	check_walls_collisions(t_env *env, t_motion motion, t_v3 move, int rec)
{
	int		i;
	double	norme_mov;
	double	norme_wall;
	double	scalar;

	i = 0;
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if (((hitbox_collision(new_v2(env->vertices[env->sectors[motion.sector].vertices[i]].x, env->vertices[env->sectors[motion.sector].vertices[i]].y), new_v2(env->vertices[env->sectors[motion.sector].vertices[i + 1]].x, env->vertices[env->sectors[motion.sector].vertices[i + 1]].y), new_v2(motion.future.x, motion.future.y), motion.size_2d)) ||
			intersection_check(new_v2(env->vertices[env->sectors[motion.sector].vertices[i]].x, env->vertices[env->sectors[motion.sector].vertices[i]].y), new_v2(env->vertices[env->sectors[motion.sector].vertices[i + 1]].x, env->vertices[env->sectors[motion.sector].vertices[i + 1]].y), new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y))) &&
			(NEIGHBOR < 0 || env->sectors[motion.sector].portals[i] == 0))
		{
			norme_mov = sqrt(move.x * move.x + move.y * move.y);
			norme_wall = sqrt((env->vertices[env->sectors[motion.sector].vertices[i + 1]].x - env->vertices[env->sectors[motion.sector].vertices[i]].x) * (env->vertices[env->sectors[motion.sector].vertices[i + 1]].x - env->vertices[env->sectors[motion.sector].vertices[i]].x) + (env->vertices[env->sectors[motion.sector].vertices[i + 1]].y - env->vertices[env->sectors[motion.sector].vertices[i]].y) * (env->vertices[env->sectors[motion.sector].vertices[i + 1]].y - env->vertices[env->sectors[motion.sector].vertices[i]].y));
			scalar = (env->vertices[env->sectors[motion.sector].vertices[i + 1]].x - env->vertices[env->sectors[motion.sector].vertices[i]].x) / norme_wall * move.x / norme_mov + (env->vertices[env->sectors[motion.sector].vertices[i + 1]].y - env->vertices[env->sectors[motion.sector].vertices[i]].y) / norme_wall * move.y / norme_mov;
			if (scalar != 0 && !rec)
			{
				move.x = norme_mov * (env->vertices[env->sectors[motion.sector].vertices[i + 1]].x - env->vertices[env->sectors[motion.sector].vertices[i]].x) / norme_wall * scalar;
				move.y = norme_mov * (env->vertices[env->sectors[motion.sector].vertices[i + 1]].y - env->vertices[env->sectors[motion.sector].vertices[i]].y) / norme_wall * scalar;
				return (new_coll(1, check_collision(env, move, motion)));
			}
			return (new_coll(1, new_v3(0, 0, 0)));
		}
		i++;
	}
	return (new_coll(0, new_v3(0, 0, 0)));
}

t_coll	check_portals_collisions(t_env *env, t_motion motion, t_v3 move)
{
	int i;

	i = 0;
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if (((hitbox_collision(new_v2(env->vertices[env->sectors[motion.sector].vertices[i]].x, env->vertices[env->sectors[motion.sector].vertices[i]].y), new_v2(env->vertices[env->sectors[motion.sector].vertices[i + 1]].x, env->vertices[env->sectors[motion.sector].vertices[i + 1]].y), new_v2(motion.future.x, motion.future.y), motion.size_2d) ||
			intersection_check(new_v2(env->vertices[env->sectors[motion.sector].vertices[i]].x, env->vertices[env->sectors[motion.sector].vertices[i]].y), new_v2(env->vertices[env->sectors[motion.sector].vertices[i + 1]].x, env->vertices[env->sectors[motion.sector].vertices[i + 1]].y), new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x, motion.future.y)))) &&
			NEIGHBOR >= 0 && env->sectors[motion.sector].portals[i] == 1)
		{
			motion.wall.sector_or = motion.sector;
			motion.wall.sector_dest = NEIGHBOR;
			motion.wall.x = (env->vertices[env->sectors[motion.sector].vertices[i + 1]].x - env->vertices[env->sectors[motion.sector].vertices[i]].x);
			motion.wall.y = (env->vertices[env->sectors[motion.sector].vertices[i + 1]].y - env->vertices[env->sectors[motion.sector].vertices[i]].y);
			motion.wall.norme = sqrt(motion.wall.x * motion.wall.x + motion.wall.y * motion.wall.y);
			move = collision_rec(env, move, motion, 0);
			if (move.x == 0 && move.y == 0)
				return (new_coll(1, new_v3(0, 0, 0)));
		}
		i++;
	}
	return (new_coll(1, move));
}*/

/*
t_v3	check_collision(t_env *env, t_v3 move, t_motion motion, int rec)
{
    t_coll		coll;

	motion.future = calculate_motion_future(motion, move);
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
	coll = check_walls_collisions(env, motion, move, rec);
	if (coll.use)
		return (coll.move);
	coll = check_portals_collisions(env, motion, move);
	if (coll.use)
		return (coll.move);
	if (check_objects(env, move, motion))
		return (move);
	return (new_v3(0, 0, 0));
}*/
