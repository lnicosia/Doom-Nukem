/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:07:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:07:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int		double_incr_event(t_event *curr, double *target)
{
	double	new_total;

	new_total = curr->total + (SDL_GetTicks() - curr->last_tick)
	* fabs(curr->incr);
	if (new_total < fabs(curr->start_incr))
	{
		if (curr->start_incr > 0)
			*target += new_total - curr->total;
		else
			*target -= new_total - curr->total;
		curr->total = new_total;
		curr->last_tick = SDL_GetTicks();
	}
	else
		return (1);
	return (0);
}

int		double_fixed_event(t_event *curr, double *target, Uint32 time)
{
	*target = curr->start_value + time * curr->incr;
	if ((curr->incr > 0 && *target >= curr->goal)
		|| (curr->incr < 0 && *target <= curr->goal))
	{
		*target = curr->goal;
		return (1);
	}
	return (0);
}

int		double_event(t_event *curr)
{
	Uint32	time;
	double	*target;

	target = (double*)curr->target;
	if (!curr->speed)
	{
		*target = curr->goal;
		curr->end_time = SDL_GetTicks();
		return (1);
	}
	time = SDL_GetTicks() - curr->start_time;
	time = time == 0 ? 1 : time;
	if (curr->mod_type == FIXED)
	{
		if (double_fixed_event(curr, target, time))
			return (1);
	}
	else
	{
		if (double_incr_event(curr, target))
			return (1);
	}
	return (0);
}
