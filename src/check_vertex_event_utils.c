/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertex_event_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:20:56 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:20:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

static int	check_all_angle(t_v2 p[3], int res, int straight)
{
	double		angle;

	angle = (p[1].x - p[0].x) * (p[2].y - p[1].y) -
	(p[1].y - p[0].y) * (p[2].x - p[1].x);
	if (angle > 0)
	{
		if (!res)
			res += straight;
		res++;
	}
	else if (angle < 0)
	{
		if (!res)
			res -= straight;
		res--;
	}
	else if (angle == 0 && res)
	{
		res += res > 0 ? 1 : -1;
	}
	return (res);
}

void		get_current_vertices(t_v2 p[3], t_sector *sector, int i,
t_env *env)
{
	p[0] = new_v2(env->vertices[sector->vertices[i]].x,
	env->vertices[sector->vertices[i]].y);
	p[1] = new_v2(env->vertices[sector->vertices[i + 1]].x,
	env->vertices[sector->vertices[i + 1]].y);
	p[2] = new_v2(env->vertices[sector->vertices[i + 2]].x,
	env->vertices[sector->vertices[i + 2]].y);
}

int			is_sector_convex(t_env *env, t_sector *sector)
{
	int		i;
	t_v2	p[3];
	int		res;
	int		straight;

	i = -1;
	res = 0;
	straight = 0;
	while (++i < sector->nb_vertices - 1)
	{
		get_current_vertices(p, sector, i, env);
		res = check_all_angle(p, res, straight);
		straight = res == 0 ? straight + 1 : 0;
	}
	p[0] = new_v2(env->vertices[sector->vertices[i]].x,
	env->vertices[sector->vertices[i]].y);
	p[1] = new_v2(env->vertices[sector->vertices[0]].x,
	env->vertices[sector->vertices[0]].y);
	p[2] = new_v2(env->vertices[sector->vertices[1]].x,
	env->vertices[sector->vertices[1]].y);
	res = check_all_angle(p, res, straight);
	straight = res == 0 ? straight + 1 : 0;
	if (res && res != -(sector->nb_vertices) && res != sector->nb_vertices)
		return (0);
	return (1);
}

int			update_sectors_slope(int vertex, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == vertex)
				update_sector_slope(env, &env->sectors[i]);
			j++;
		}
		i++;
	}
	return (0);
}
