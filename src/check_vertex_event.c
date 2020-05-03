/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertex_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:16:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:20:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_protection.h"

int		check_sectors_containing_moving_vertex_x(double prec, t_event *event,
t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] != event->check_param.vertex)
				continue;
			if (!is_sector_convex(env, &env->sectors[i])
			|| !get_clockwise_order_sector(env, i)
			|| intersects_with_wall(&env->sectors[i], env->player.pos, j, env))
			{
				env->vertices[event->check_param.vertex].x = prec;
				update_sectors_slope(event->check_param.vertex, env);
				return (1);
			}
			break ;
		}
	}
	env->vertices[event->check_param.vertex].x = prec;
	update_sectors_slope(event->check_param.vertex, env);
	return (0);
}

int		check_vertex_x_event(t_event *event, void *penv)
{
	t_env	*env;
	double	prec;
	Uint32	time;

	env = (t_env*)penv;
	prec = env->vertices[event->check_param.vertex].x;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env->vertices[event->check_param.vertex].x = event->start_value
	+ time * event->incr;
	if (!event->speed)
		env->vertices[event->check_param.vertex].x = event->goal;
	return (check_sectors_containing_moving_vertex_x(prec, event, env));
}

int		check_sectors_containing_moving_vertex_y(double prec, t_event *event,
t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] != event->check_param.vertex)
				continue;
			if (!is_sector_convex(env, &env->sectors[i])
			|| !get_clockwise_order_sector(env, i)
			|| intersects_with_wall(&env->sectors[i], env->player.pos, j, env))
			{
				env->vertices[event->check_param.vertex].y = prec;
				update_sectors_slope(event->check_param.vertex, env);
				return (1);
			}
			break ;
		}
	}
	env->vertices[event->check_param.vertex].y = prec;
	update_sectors_slope(event->check_param.vertex, env);
	return (0);
}

int		check_vertex_y_event(t_event *event, void *penv)
{
	t_env	*env;
	double	prec;
	Uint32	time;

	env = (t_env*)penv;
	prec = env->vertices[event->check_param.vertex].y;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	env->vertices[event->check_param.vertex].y = event->start_value
	+ time * event->incr;
	if (!event->speed)
		env->vertices[event->check_param.vertex].y = event->goal;
	return (check_sectors_containing_moving_vertex_y(prec, event, env));
}
