/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:47:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:30:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

double	get_start_pos(t_v2 pos, int sector, int i, t_env *env)
{
	double	res;

	res = (pos.x - env->vertices[env->sectors[sector].vertices[i]].x)
	* (env->vertices[env->sectors[sector].vertices[i + 1]].y
	- env->vertices[env->sectors[sector].vertices[i]].y)
	- (pos.y - env->vertices[env->sectors[sector].vertices[i]].y)
	* (env->vertices[env->sectors[sector].vertices[i + 1]].x
	- env->vertices[env->sectors[sector].vertices[i]].x);
	return (res);
}

double	get_end_pos(t_v2 pos, int sector, int i, t_env *env)
{
	double	res;

	res = (env->sectors[sector].x_max + 1
	- env->vertices[env->sectors[sector].vertices[i]].x)
	* (env->vertices[env->sectors[sector].vertices[i + 1]].y
	- env->vertices[env->sectors[sector].vertices[i]].y)
	- (pos.y - env->vertices[env->sectors[sector].vertices[i]].y)
	* (env->vertices[env->sectors[sector].vertices[i + 1]].x
	- env->vertices[env->sectors[sector].vertices[i]].x);
	return (res);
}

/*
**	Returns if a pos is in a certain sector
*/

int		is_in_sector(t_env *env, int sector, t_v3 pos)
{
	int		count;
	int		i;
	double	start_pos;
	double	end_pos;

	i = -1;
	count = 0;
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	if (pos.z < get_floor_at_pos(&env->sectors[sector], new_v3(pos.x, pos.y, 0),
		env) || pos.z > get_ceiling_at_pos(&env->sectors[sector],
		new_v3(pos.x, pos.y, 0), env))
		return (0);
	while (++i < env->sectors[sector].nb_vertices)
	{
		start_pos = get_start_pos(new_v2(pos.x, pos.y), sector, i, env);
		end_pos = get_end_pos(new_v2(pos.x, pos.y), sector, i, env);
		if (diff_sign(start_pos, end_pos)
			&& in_range(pos.y,
			env->vertices[env->sectors[sector].vertices[i]].y,
			env->vertices[env->sectors[sector].vertices[i + 1]].y))
			count++;
	}
	return (count % 2 == 0 ? 0 : 1);
}

int		inside_tmp_sect(t_vertex v1, t_vertex *tmp_sect, int size)
{
	int i;
	int j;
	int is_inside;

	i = 0;
	j = size - 1;
	is_inside = 0;
	while (i < size)
	{
		if (((tmp_sect[i].y < v1.y && tmp_sect[j].y > v1.y)
		|| (tmp_sect[j].y < v1.y && tmp_sect[i].y > v1.y))
		&& (tmp_sect[i].x < v1.x || tmp_sect[j].x < v1.x))
		{
			if (tmp_sect[i].x + (v1.y - tmp_sect[i].y) /
				(tmp_sect[j].y - tmp_sect[i].y) *
				(tmp_sect[j].x - tmp_sect[i].x) < v1.x)
				is_inside = (is_inside) ? 0 : 1;
		}
		j = i;
		i++;
	}
	return (is_inside);
}

/*
**	Returns if a pos is in a certain sector
**	without checking z
*/

int		is_in_sector_no_z(t_env *env, int sector, t_v2 pos)
{
	int		count;
	int		i;
	double	start_pos;
	double	end_pos;

	i = 0;
	count = 0;
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		start_pos = get_start_pos(pos, sector, i, env);
		end_pos = get_end_pos(pos, sector, i, env);
		if (diff_sign(start_pos, end_pos)
			&& in_range(pos.y,
			env->vertices[env->sectors[sector].vertices[i]].y,
			env->vertices[env->sectors[sector].vertices[i + 1]].y))
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}
