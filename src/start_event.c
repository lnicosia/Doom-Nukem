/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 14:18:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_event(t_event *event)
{
	if (event->type == DOUBLE)
	{
		event->incr = (event->goal - *(double*)(event->target))
		/ event->duration;
		event->start_value = *(double*)(event->target);
	}
	else if (event->type == INT)
	{
		event->incr = (event->goal - *(int*)(event->target))
		/ event->duration;
		event->start_value = *(int*)(event->target);
	}
	event->start_time = SDL_GetTicks();
	event->running = 1;
	ft_printf("incr = %f\n", event->incr);
}

void	start_event(t_event *events, size_t size, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (events[i].running == 0)
		{
			update_event(&events[i]);
			ft_lstpushback(&env->events,
				ft_lstnew(&events[i],
				sizeof(t_event)));
		}
		i++;

	}
}
