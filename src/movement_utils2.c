/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:20:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:22:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

t_motion	new_motion(int sector, double size_2d, double eyesight, t_v3 pos)
{
	t_motion motion;

	motion.sector = sector;
	motion.size_2d = size_2d;
	motion.eyesight = eyesight;
	motion.pos = pos;
	return (motion);
}

t_coll_addr	new_coll_addr(t_motion *motion, int *sector, int *vertex)
{
	t_coll_addr		addr;

	addr.motion = motion;
	addr.s = sector;
	addr.v = vertex;
	return (addr);
}

t_coll		new_c(int sect, int vertex, t_motion motion)
{
	t_coll coll;

	coll.sector = sect;
	coll.vertex = vertex;
	coll.motion = motion;
	return (coll);
}

t_v3		calculate_motion_future(t_motion motion, t_v3 move)
{
	motion.future.x = move.x + motion.pos.x;
	motion.future.y = move.y + motion.pos.y;
	motion.future.z = move.z + motion.pos.z;
	return (motion.future);
}

double		floor_height(t_env *env, t_motion motion, int sector_dest)
{
	double	height;

	height = motion.eyesight + env->sectors[sector_dest].floor +
		(env->sectors[sector_dest].floor_normal.x * (motion.pos.x
		- env->vertices[env->sectors[sector_dest].vertices[0]].x)
		- env->sectors[sector_dest].floor_normal.y * (motion.pos.y
		- env->vertices[env->sectors[sector_dest].vertices[0]].y))
		* env->sectors[sector_dest].floor_slope;
	return (height);
}
