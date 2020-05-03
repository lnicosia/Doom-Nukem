/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:12:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 09:42:23 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		check_int_overflow_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0
				&& event->start_value + time * event->incr >= 2147483646)
			|| (event->incr < 0
				&& event->start_value + time * event->incr <= -2147483648)
			|| (!event->speed && (event->goal >= 2147483646
					|| event->goal <= -2147483648)))
		return (1);
	return (0);
}

int		check_double_overflow_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0
				&& event->start_value + time * event->incr >= 99999999999999)
			|| (event->incr < 0
				&& event->start_value + time * event->incr <= -99999999999999)
			|| (!event->speed && (event->goal >= 99999999999999
					|| event->goal <= -99999999999999)))
		return (1);
	return (0);
}

int		check_gravity_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr > 10)
		|| (event->incr < 0 && event->start_value + time * event->incr < -10)
		|| (!event->speed && ((int)event->goal > 10 || (int)event->goal < -10)))
		return (1);
	return (0);
}

int		check_true_false_event(t_event *event, void *penv)
{
	(void)penv;
	if ((event->incr > 0 && *(int*)event->target == 1)
			|| (event->incr < 0 && *(int*)event->target == 0)
			|| (!event->speed && (int)event->goal != 1
				&& (int)event->goal != 0))
		return (1);
	return (0);
}

int		check_portal_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if ((event->incr > 0 && *(int*)event->target == 1)
			|| (event->incr < 0 && *(int*)event->target == 0)
			|| (!event->speed && (int)event->goal != 1
				&& (int)event->goal != 0))
		return (1);
	if (intersects_with_wall_no_portal_check(&env->sectors[event->
		check_param.sector], env->player.pos, event->check_param.wall, env))
		return (1);
	return (0);
}
