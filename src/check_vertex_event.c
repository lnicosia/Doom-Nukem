/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertex_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:16:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/21 18:03:14 by lnicosia         ###   ########.fr       */
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

int		update_sectors_slope(int vertex, t_env *env)
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

int		check_vertex_x_event(t_event *event, void *penv)
{
	t_env	*env;
	double	prec;
	Uint32	time;
	int		i;
	int		j;

	env = (t_env*)penv;
	prec = env->vertices[event->check_param.vertex].x;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env->vertices[event->check_param.vertex].x = event->start_value
	+ time * event->incr;
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == event->check_param.vertex)
			{
				if (!is_sector_convex(env, env->sectors[i])
					// A test
					|| !get_clockwise_order_sector(env, i))
				{
					env->vertices[event->check_param.vertex].x = prec;
					update_sectors_slope(event->check_param.vertex, env);
					return (1);
				}
				if (intersects_with_player(&env->sectors[i], j, env))
				{
					env->vertices[event->check_param.vertex].x = prec;
					update_sectors_slope(event->check_param.vertex, env);
					return (1);
				}
				break;
			}
			j++;
		}
		i++;
	}
	env->vertices[event->check_param.vertex].x = prec;
	update_sectors_slope(event->check_param.vertex, env);
	return (0);
}

int		check_vertex_y_event(t_event *event, void *penv)
{
	t_env	*env;
	double	prec;
	Uint32	time;
	int		i;
	int		j;

	env = (t_env*)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	prec = env->vertices[event->check_param.vertex].y;
	env->vertices[event->check_param.vertex].y = event->start_value
	+ time * event->incr;
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == event->check_param.vertex)
			{
				if (!is_sector_convex(env, env->sectors[i])
					// A test
					|| !get_clockwise_order_sector(env, i))
				{
					env->vertices[event->check_param.vertex].y = prec;
					update_sectors_slope(event->check_param.vertex, env);
					return (1);
				}
				if (intersects_with_player(&env->sectors[i], j, env))
				{
					env->vertices[event->check_param.vertex].y = prec;
					update_sectors_slope(event->check_param.vertex, env);
					return (1);
				}
				break;
			}
			j++;
		}
		i++;
	}
	env->vertices[event->check_param.vertex].y = prec;
	update_sectors_slope(event->check_param.vertex, env);
	return (0);
}
