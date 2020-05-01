/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles_collisions3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:46:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:46:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "collision.h"

int		projectile_collision_line_with_current_wall(t_env *env,
t_motion motion, int i)
{
	if (env->sectors[motion.sector].neighbors[i] < 0
		&& (intersection_check(new_v2(env->vertices[env->sectors[motion.
		sector].vertices[i]].x,
		env->vertices[env->sectors[motion.sector].vertices[i]].y),
		new_v2(env->vertices[env->sectors[motion.sector].vertices[i + 1]].x,
		env->vertices[env->sectors[motion.sector].vertices[i + 1]].y),
		new_v2(motion.pos.x, motion.pos.y), new_v2(motion.future.x,
		motion.future.y))
		|| hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2),
		new_v2(motion.future.x, motion.future.y), motion.size_2d)))
		return (i);
	return (-1);
}

int		collision_projectiles2(t_env *env, t_v3 move, t_motion motion)
{
	int	i;

	i = 0;
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if ((hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2),
			new_v2(motion.future.x, motion.future.y), motion.size_2d))
			&& NEIGHBOR >= 0)
		{
			motion.wall.sector_or = motion.sector;
			motion.wall.sector_dest = NEIGHBOR;
			if (!collision_projectiles_rec(env, move, motion))
				return (i);
		}
		i++;
	}
	return (-1);
}

int		collision_projectiles(t_env *env, t_v3 move, t_motion motion)
{
	int		i;
	int		ret;

	motion.future.x = motion.pos.x + move.x;
	motion.future.y = motion.pos.y + move.y;
	motion.future.z = motion.pos.z + move.z;
	i = 0;
	init_sector_list(env, motion.sector);
	if (motion.sector == -1)
		return (-4);
	if (!projectiles_ceil(env, motion, motion.sector))
		return (-2);
	else if (!projectiles_floor(env, motion, motion.sector))
		return (-3);
	while (i < env->sectors[motion.sector].nb_vertices)
	{
		if ((ret = projectile_collision_line_with_current_wall(
			env, motion, i)) >= 0)
			return (ret);
		i++;
	}
	return (collision_projectiles2(env, move, motion));
}
