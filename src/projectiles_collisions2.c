/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles_collisions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:46:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:46:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		projectiles_ceil(t_env *env, t_motion motion, int sector_dest)
{
	if (motion.future.z > get_ceiling_at_pos(&env->sectors[sector_dest],
		motion.future, env) - 1)
		return (0);
	return (1);
}

int		projectiles_floor(t_env *env, t_motion motion, int sector_dest)
{
	double	floor;

	floor = get_floor_at_pos(&env->sectors[sector_dest], motion.future, env);
	if (floor > motion.pos.z)
		return (0);
	return (1);
}

int		collision_projectiles_rec2(t_env *env, t_v3 move, t_motion motion,
t_wall wall)
{
	int		i;

	i = -1;
	while (++i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if (hitbox_collision(new_v2(env->vertices[env->sectors[wall.
			sector_dest].vertices[i]].x, env->vertices[env->sectors[wall.
			sector_dest].vertices[i]].y), new_v2(env->vertices[env->sectors[
			wall.sector_dest].vertices[i + 1]].x,
			env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y),
			new_v2(motion.future.x, motion.future.y), motion.size_2d)
			&& env->sectors[wall.sector_dest].neighbors[i] >= 0 &&
			env->sector_list[env->sectors[wall.sector_dest].neighbors[i]] == 0)
		{
			if ((!projectiles_ceil(env, motion, wall.sector_dest)
				|| !projectiles_floor(env, motion,
				env->sectors[wall.sector_dest].neighbors[i])))
				return (0);
			motion.wall.sector_or = wall.sector_dest;
			motion.wall.sector_dest =
			env->sectors[wall.sector_dest].neighbors[i];
			return (collision_projectiles_rec(env, move, motion));
		}
	}
	return (1);
}

int		collision_projectiles_rec(t_env *env, t_v3 move, t_motion motion)
{
	int		i;
	t_wall	wall;

	i = 0;
	wall = motion.wall;
	motion.future.x = move.x + motion.pos.x;
	motion.future.y = move.y + motion.pos.y;
	motion.future.z = motion.pos.z + move.z;
	env->sector_list[wall.sector_dest] = 1;
	if ((!projectiles_ceil(env, motion, wall.sector_dest)
		|| !projectiles_floor(env, motion, wall.sector_dest)))
		return (0);
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if (hitbox_collision(new_v2(env->vertices[env->sectors[wall.
			sector_dest].vertices[i]].x, env->vertices[env->sectors[wall.
			sector_dest].vertices[i]].y), new_v2(env->vertices[env->sectors[
			wall.sector_dest].vertices[i + 1]].x, env->vertices[env->sectors[
			wall.sector_dest].vertices[i + 1]].y),
			new_v2(motion.future.x, motion.future.y), motion.size_2d)
			&& env->sectors[wall.sector_dest].neighbors[i] < 0)
			return (0);
		i++;
	}
	return (collision_projectiles_rec2(env, move, motion, wall));
}
