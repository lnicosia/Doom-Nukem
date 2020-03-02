/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:54:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/02 10:50:23 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
** This function returns 0 if the floor is too high and 1 if it isn't
*/

int		check_floor(t_env *env, t_motion motion, int sector_dest)
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
** Checks if the entity which is moving collides with any solid object
*/

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
		if (env->objects[i].exists)
		{
			if (distance_two_points_2d(env->objects[i].pos.x,
				env->objects[i].pos.y, futur.x, futur.y) <
				env->objects[i].size_2d + motion.size_2d &&
				((motion.pos.z <= env->objects[i].pos.z +
				env->objects[i].height && motion.pos.z >=
				env->objects[i].pos.z) || (motion.pos.z + eyesight + 1 <=
				env->objects[i].pos.z + env->objects[i].height && motion.pos.z +
				eyesight + 1 >= env->objects[i].pos.z)))
			{
				if (env->checking_collisions_with_player
					&& env->in_game && !env->player.colliding_objects[i]
					&& env->objects[i].nb_collision_events > 0
					&& env->objects[i].collision_events)
				{
					if (start_event(&env->objects[i].collision_events,
						&env->objects[i].nb_collision_events, env))
					{
						env->fatal_error = 1;
						return (-1);
					}
				}
				if (env->checking_collisions_with_player)
					env->player.colliding_objects[i] = 1;
				if (env->objects[i].solid)
					return (0);
			}
			else if (env->checking_collisions_with_player)
				env->player.colliding_objects[i] = 0;
		}
		i++;
	}
	return (1);
}
				
