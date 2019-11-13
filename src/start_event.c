/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/13 10:35:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_event(t_event *event)
{
	if (event->type == DOUBLE)
	{
		if (event->goal == *(double*)(event->target))
				return (0);
		event->incr = (event->goal - *(double*)(event->target))
		/ event->duration;
		event->start_value = *(double*)(event->target);
	}
	else if (event->type == INT)
	{
		if (event->goal == *(int*)(event->target))
				return (0);
		event->incr = (event->goal - *(int*)(event->target))
		/ event->duration;
		event->start_value = *(int*)(event->target);
	}
	event->start_time = SDL_GetTicks();
	return (1);
}

int		is_queued(t_list *queued_values, void *target)
{
		//ft_printf("Checking if contains %p\n", target);
		while (queued_values)
		{
				//ft_printf("curr content = %p\n", *(long*)queued_values->content);
				if (*(long*)queued_values->content == (long)target)
						return (1);
				queued_values = queued_values->next;
		}
		return (0);
}

//	TODO
//	Protection

void	start_event(t_event *events, size_t size, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
			if (update_event(&events[i])
					&& !is_queued(env->queued_values, events[i].target))
			{
				ft_lstpushback(&env->events, ft_lstnew(&events[i],
					sizeof(t_event)));
				//ft_printf("adding %p to queued_values\n", events[i].target);
				ft_lstpushback(&env->queued_values, ft_lstnew(&events[i].target,
				sizeof(events[i].target)));
				//ft_printf("{yellow}starting event{reset}\n");
			}
		i++;
	}
	//ft_printf("\n");
}
