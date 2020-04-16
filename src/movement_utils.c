/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:09:06 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/28 18:25:38 by gaerhard         ###   ########.fr       */
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

t_coll_addr			new_coll_addr(t_motion *motion, int *sector, int *vertex)
{
	t_coll_addr		addr;

	addr.motion = motion;
	addr.s = sector;
	addr.v = vertex;
	return (addr);
}

t_coll				new_c(int sect, int vertex, t_motion motion)
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
		(env->sectors[sector_dest].floor_normal.x
		* (motion.pos.x - FUTURE_V0X) - env->sectors[sector_dest].floor_normal.y
		* (motion.pos.y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
	return (height);
}

void		iter_sectors_rec(t_env *env, t_v3 pos, t_wall wall, double size_2d)
{
    int       i;

	i = 0;
	env->sector_list[wall.sector_dest] = 1;
	while (i < env->sectors[wall.sector_dest].nb_vertices)
	{
		if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R),
			new_v2(pos.x, pos.y), size_2d) && env->sectors[wall.sector_dest].neighbors[i] >= 0 &&
			env->sector_list[env->sectors[wall.sector_dest].neighbors[i]] == 0)
		{
			wall.sector_or = wall.sector_dest;
			wall.sector_dest = env->sectors[wall.sector_dest].neighbors[i];
			iter_sectors_rec(env, pos, wall, size_2d);
		}
		i++;
	}
	return ;
}

void		iter_sectors(t_env *env, t_motion motion)
{
    int		i;
	int		j;

	i = 0;
	if (motion.sector < 0)
		return ;
	init_sector_list(env, motion.sector);
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if ((hitbox_collision(new_v2(env->vertices[env->sectors[i].vertices[j]].x,
				env->vertices[env->sectors[i].vertices[j]].y),
				new_v2(env->vertices[env->sectors[i].vertices[j + 1]].x,
				env->vertices[env->sectors[i].vertices[j + 1]].y),
				new_v2(motion.pos.x, motion.pos.y), motion.size_2d))
				&& (env->sectors[i].neighbors[j] > 0 && env->sectors[i].portals[j]))
			{
				env->sector_list[i] = 1;
				break;
			}
			j++;
		}
		i++;
	}
}

int			find_highest_sector(t_env *env, t_motion motion)
{
	int		i;
	double	height;
	double	s_height;
	int		tmp;

	i = 0;
	if (motion.sector < 0)
		return (0);
	iter_sectors(env, motion);
	tmp = motion.sector;
	height = get_floor_at_pos(&env->sectors[motion.sector], motion.pos, env);
	while (i < env->nb_sectors)
	{
		if (env->sector_list[i])
		{
			s_height = get_floor_at_pos(&env->sectors[i], motion.pos, env);
			if (height < s_height)
			{
				height = s_height;
				tmp = i;
			}
		}
		i++;
	}
	return (tmp);
}

int			find_lowest_ceiling(t_env *env, t_motion motion)
{
	int		i;
	double	height;
	double	s_height;
	int		tmp;

	i = 0;
	if (motion.sector < 0)
		return (0);
	iter_sectors(env, motion);
	tmp = motion.sector;
	height = get_ceiling_at_pos(&env->sectors[motion.sector], motion.pos, env);
	while (i < env->nb_sectors)
	{
		if (env->sector_list[i])
		{
			s_height = get_ceiling_at_pos(&env->sectors[i], motion.pos, env);
			if (height > s_height)
			{
				height = s_height;
				tmp = i;
			}
		}
		i++;
	}
	return (tmp);
}
