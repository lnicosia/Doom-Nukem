/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_ended_start_condition.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:45:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 18:13:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_conditions.h"

int		event_ended_start_condition(t_condition *condition, t_event *event)
{
	t_event	*target;

	target = (t_event*)condition->target;
	if ((SDL_GetTicks() >= target->end_time + event->delay && target->happened)
		|| !event->uses)
	{
		target->happened = 0;
		return (0);
	}
	return (1);
}
