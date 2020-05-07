/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:45:03 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:45:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_intersection_with_sector(t_sector sector, t_env *env,
t_vertex vt1, t_vertex vt2)
{
	int	i;

	i = -1;
	while (++i < sector.nb_vertices)
	{
		if (segments_intersect(new_v2(vt1.x, vt1.y), new_v2(vt2.x, vt2.y),
			new_v2(env->vertices[sector.vertices[i]].x,
			env->vertices[sector.vertices[i]].y),
			new_v2(env->vertices[sector.vertices[i + 1]].x,
			env->vertices[sector.vertices[i + 1]].y)))
		{
			if ((env->vertices[sector.vertices[i]].num == vt1.num
			&& env->vertices[sector.vertices[i + 1]].num != vt2.num)
			|| (env->vertices[sector.vertices[i]].num == vt2.num
			&& env->vertices[sector.vertices[i + 1]].num != vt1.num)
			|| (env->vertices[sector.vertices[i]].num != vt1.num
			&& env->vertices[sector.vertices[i + 1]].num == vt2.num)
			|| (env->vertices[sector.vertices[i]].num != vt2.num
			&& env->vertices[sector.vertices[i + 1]].num == vt1.num)
			|| ((env->vertices[sector.vertices[i]].num == vt2.num
			&& env->vertices[sector.vertices[i + 1]].num == vt1.num)
			|| (env->vertices[sector.vertices[i]].num == vt2.num
			&& env->vertices[sector.vertices[i + 1]].num == vt2.num)))
				i = i - 0;
			else
				return (-1);
		}
	}
	return (0);
}

void		check_current_vertex(int i, t_sector sector, t_v2 *p, t_env *env)
{
	t_vertex	current;

	if (i >= sector.nb_vertices)
	{
		if (i == sector.nb_vertices)
		{
			p[i].x = p[0].x;
			p[i].y = p[0].y;
		}
		else if (i == sector.nb_vertices + 1)
		{
			p[i].x = p[1].x;
			p[i].y = p[1].y;
		}
	}
	else
	{
		current = env->vertices[env->sectors[sector.num].vertices[i]];
		p[i].x = current.x;
		p[i].y = current.y;
	}
}

int			is_sector_concave2(t_sector sector, int res, t_env *env)
{
	if (res != -(sector.nb_vertices) && res != sector.nb_vertices && res)
		return (-1);
	if (!res)
		env->sector_is_straight = 1;
	else
		env->sector_is_straight = 0;
	return (0);
}

int			is_sector_concave(t_sector sector, t_env *env)
{
	int			i;
	t_v2		*p;
	int			straight;
	int			res;

	straight = 0;
	if (!(p = (t_v2*)ft_memalloc(sizeof(t_v2) * (sector.nb_vertices + 2))))
		return (ft_perror("Could not malloc p from is_sector_concave"));
	i = -1;
	while (++i < sector.nb_vertices + 2)
		check_current_vertex(i, sector, p, env);
	i = -1;
	res = 0;
	while (++i < sector.nb_vertices)
	{
		res = check_all_angles(p, res, i, straight);
		if (!res)
			straight++;
		else
			straight = 0;
	}
	free(p);
	return (is_sector_concave2(sector, res, env));
}
