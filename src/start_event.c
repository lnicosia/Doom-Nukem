/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/06 15:39:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_event(t_event *event)
{
	if (SDL_GetTicks() - event->start_time < event->delay)
		return (0);
	if (event->type == DOUBLE)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(double*)(event->target))
			return (0);
		else if (event->mod_type == INCR)
			event->goal = *(double*)event->target + event->start_incr;
		event->incr = (event->goal - *(double*)(event->target))
			/ event->duration;
		event->start_value = *(double*)(event->target);
	}
	else if (event->type == INT)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(int*)(event->target))
			return (0);
		else if (event->mod_type == INCR)
			event->goal = *(int*)event->target + event->start_incr;
		event->incr = (event->goal - *(int*)(event->target))
			/ event->duration;
		event->start_value = *(int*)(event->target);
	}
	event->start_time = SDL_GetTicks();
	event->end_time = event->start_time + event->duration;
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

int		start_event(t_event **events, size_t *size, t_env *env)
{
	size_t		i;
	t_list		*new;
	t_list		*new_value;

	i = 0;
	while (i < *size)
	{
		if ((!(*events)[i].target
					|| !is_queued(env->queued_values, (*events)[i].target))
				&& (!(*events)[i].launch_func
					|| (*events)[i].launch_func(&(*events)[i], env))
				&& update_event(&(*events)[i]))
			//&& (!(*events)[i].max_uses
			//|| (*events)[i].uses < (*events)[i].max_uses)
		{
			if (!(new = ft_lstnew(&(*events)[i], sizeof(t_event))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->events, new);
			if (!(new_value = ft_lstnew(&(*events)[i].target,
							sizeof((*events)[i].target))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->queued_values, new_value);
			if ((*events)[i].max_uses > 0)
			{
				(*events)[i].uses++;
				//ft_printf("Events use %d time out of %d\n",
				//(*events)[i].uses, (*events)[i].max_uses);
				//ft_printf("Size = %d\n", *size);
				if ((*events)[i].uses >= (*events)[i].max_uses)
				{
					//free_event(&(*events)[i]);
					*events = ft_delindex((*events),
							sizeof(t_event) * (*size),
							sizeof(t_event),
							sizeof(t_event) * i);
					(*size)--;
					//ft_printf("events max used. size = %d\n", *size);
				}
				else
					i++;
			}
			else
				i++;
			//ft_printf("{yellow}starting event{reset}\n");
		}
		else
			i++;
	}
	return (0);
}
