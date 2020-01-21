/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertex_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:16:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/21 11:46:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

static int	check_all_angles(t_v2 p[3], int res, int straight)
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

int			is_sector_convex(t_env *env, t_sector sector)
{
	int		i;
	t_v2	p[3];
	int		res;
	int		straight;
	
	i = 0;
	res = 0;
	straight = 0;
	while (i < sector.nb_vertices - 1)
	{
		p[0] = new_v2(env->vertices[sector.vertices[i]].x,
		env->vertices[sector.vertices[i]].y);
		p[1] = new_v2(env->vertices[sector.vertices[i + 1]].x,
		env->vertices[sector.vertices[i + 1]].y);
		p[2] = new_v2(env->vertices[sector.vertices[i + 2]].x,
		env->vertices[sector.vertices[i + 2]].y);
		res = check_all_angles(p, res, straight);
		if (!res)
			straight++;
		else
			straight = 0;
		i++;
	}
	p[0] = new_v2(env->vertices[sector.vertices[i]].x,
	env->vertices[sector.vertices[i]].y);
	p[1] = new_v2(env->vertices[sector.vertices[0]].x,
	env->vertices[sector.vertices[0]].y);
	p[2] = new_v2(env->vertices[sector.vertices[1]].x,
	env->vertices[sector.vertices[1]].y);
	res = check_all_angles(p, res, straight);
	if (!res)
		straight++;
	else
		straight = 0;
	if (res && res != -(sector.nb_vertices)
		&& res != sector.nb_vertices)
		return (0);
	return (1);
}

int		check_vertex_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;
	int		j;

	env = (t_env*)penv;
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == event->check_param.vertex)
			{
				if (!is_sector_convex(env, env->sectors[i]))
					return (1);
				if (!get_clockwise_order_sector(env, i))
					return (1);
				break;
			}
			j++;
		}
		i++;
	}
	return (0);
}
