/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:36:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:36:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_conditions.h"
#include "events.h"

int		set_event_type2(t_event *event)
{
	if (event->mod_type == FIXED
			&& event->goal == *(Uint32*)(event->target))
		return (1);
	else if (event->mod_type == INCR)
		event->goal = *(Uint32*)event->target + event->start_incr;
	event->start_value = *(Uint32*)(event->target);
	if (event->goal < *(Uint32*)event->target)
		event->incr = -event->incr;
	return (0);
}

int		set_event_type(t_event *event)
{
	if (event->type == DOUBLE)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(double*)(event->target))
			return (1);
		else if (event->mod_type == INCR)
			event->goal = *(double*)event->target + event->start_incr;
		event->start_value = *(double*)(event->target);
		if (event->goal < *(double*)event->target)
			event->incr = -event->incr;
	}
	else if (event->type == INT)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(int*)(event->target))
			return (1);
		else if (event->mod_type == INCR)
			event->goal = *(int*)event->target + event->start_incr;
		event->start_value = *(int*)(event->target);
		if (event->goal < *(int*)event->target)
			event->incr = -event->incr;
	}
	else if (event->type == UINT32)
		return (set_event_type2(event));
	return (0);
}

int		update_event(t_event *event)
{
	if (SDL_GetTicks() - event->start_time < event->delay)
		return (0);
	event->incr = (event->speed / 1000);
	if (set_event_type(event))
		return (0);
	event->start_time = SDL_GetTicks();
	event->last_tick = event->start_time;
	event->total = 0;
	if (event->speed)
		event->end_time = event->start_time
		+ fabs(event->goal - event->start_value) / event->speed;
	else
		event->end_time = event->start_time;
	return (1);
}
