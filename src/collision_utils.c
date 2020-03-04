/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:05:45 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 17:54:47 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** Resets check_collision loops so that the function tests
** every single wall and portal
*/

void	reset_loop(int *i, int *sector, t_motion motion)
{
	*i = 0;
	*sector = motion.sector;
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
** Returns 1 if the entity movement vector cross a portal in a given sector
** or if the entity hitbox intersects with the portal
** s being the sector
** v being the first vertex of the tested portal, v + 1 is the second vertex
** motion contains the different stats of the entity which is moving
*/

int		cross_portal(t_env *env, t_motion motion, int s, int v)
{
	if (env->sectors[s].neighbors[v] < 0)
		return (0);
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
