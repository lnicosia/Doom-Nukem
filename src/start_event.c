/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 19:19:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_conditions.h"

int		update_event(t_event *event)
{
	if (SDL_GetTicks() - event->start_time < event->delay)
		return (0);
	event->incr = (event->speed / 1000);
	if (event->type == DOUBLE)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(double*)(event->target))
			return (0);
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
			return (0);
		else if (event->mod_type == INCR)
			event->goal = *(int*)event->target + event->start_incr;
		event->start_value = *(int*)(event->target);
		if (event->goal < *(int*)event->target)
			event->incr = -event->incr;
	}
	else if (event->type == UINT32)
	{
		if (event->mod_type == FIXED
				&& event->goal == *(Uint32*)(event->target))
			return (0);
		else if (event->mod_type == INCR)
			event->goal = *(Uint32*)event->target + event->start_incr;
		event->start_value = *(Uint32*)(event->target);
		if (event->goal < *(Uint32*)event->target)
			event->incr = -event->incr;
	}
	event->start_time = SDL_GetTicks();
	event->last_tick = event->start_time;
	event->total = 0;
	if (event->speed)
		event->end_time = event->start_time + fabs(event->goal - event->start_value)
		/ event->speed;
	else
		event->end_time = event->start_time;
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

int		check_launch_conditions(t_event *event, t_condition *tab, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		if (tab[i].type == EQUALS
				&& equals_condition(tab[i]))
			return (0);
		else if (tab[i].type == DIFFERENT
				&& different_condition(tab[i]))
			return (0);
		else if (tab[i].type == LESS
				&& less_condition(tab[i]))
			return (0);
		else if (tab[i].type == GREATER
				&& greater_condition(tab[i]))
			return (0);
		else if (tab[i].type == LESS_OR_EQUALS
				&& less_or_equals_condition(tab[i]))
			return (0);
		else if (tab[i].type == GREATER_OR_EQUALS
				&& greater_or_equals_condition(tab[i]))
			return (0);
		else if (tab[i].type == EVENT_ENDED
				&& event_ended_condition(tab[i], event))
			return (0);
		else if (tab[i].type == EVENT_ENDED_START
				&& event_ended_start_condition(tab[i], event))
			return (0);
		/*else if (tab[i].type == FUNCTION
				&& event_func_condition(tab[i], event))
			return (0);*/
		i++;
	}
	return (1);
}

int		set_target_to_condition(t_event *event, t_condition condition)
{
	if (event->target == condition.target)
	{
		if (event->type == DOUBLE)
			*(double*)event->target = condition.value;
		else if (event->type == INT)
			*(int*)event->target = condition.value;
		else if (event->type == UINT32)
			*(Uint32*)event->target = condition.value;
	}
	return (0);
}

int		check_exec_conditions(t_event *event, t_condition *tab, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		if (tab[i].type == EQUALS
				&& equals_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == DIFFERENT
				&& different_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == LESS
				&& less_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == GREATER
				&& greater_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == LESS_OR_EQUALS
				&& less_or_equals_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == GREATER_OR_EQUALS
				&& greater_or_equals_condition(tab[i]))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == EVENT_ENDED
				&& event_ended_condition(tab[i], event))
			return (set_target_to_condition(event, tab[i]));
		else if (tab[i].type == EVENT_ENDED_START
				&& event_ended_start_condition(tab[i], event))
			return (set_target_to_condition(event, tab[i]));
		/*else if (tab[i].type == FUNCTION
				&& event_func_condition(tab[i], event))
			return (set_target_to_condition(event, tab[i]);*/
		i++;
	}
	return (1);
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
				&& (!(*events)[i].launch_conditions
					|| check_launch_conditions(&(*events)[i],
					(*events)[i].launch_conditions,
					(*events)[i].nb_launch_conditions))
				&& update_event(&(*events)[i]))
		{
			if (!(new = ft_lstnew(&(*events)[i], sizeof(t_event))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->events, new);
			if (!(new_value = ft_lstnew(&(*events)[i].target,
							sizeof((*events)[i].target))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->queued_values, new_value);
			(*events)[i].uses++;
			(*events)[i].happened = 1;
			if ((*events)[i].max_uses > 0)
			{
				if ((*events)[i].uses >= (*events)[i].max_uses)
				{
					//free_event(&(*events)[i]);
					*events = ft_delindex((*events),
							sizeof(t_event) * (*size),
							sizeof(t_event),
							sizeof(t_event) * i);
					(*size)--;
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

int		start_event_free(t_event **events, size_t *size, t_env *env)
{
	size_t		i;
	t_list		*new;
	t_list		*new_value;

	i = 0;
	while (i < *size)
	{
		if ((!(*events)[i].launch_conditions
					|| check_launch_conditions(&(*events)[i],
					(*events)[i].launch_conditions,
					(*events)[i].nb_launch_conditions))
				&& update_event(&(*events)[i]))
		{
			if (!(new = ft_lstnew(&(*events)[i], sizeof(t_event))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->events, new);
			if (!(new_value = ft_lstnew(&(*events)[i].target,
							sizeof((*events)[i].target))))
				return (ft_perror("Could not malloc new event"));
			ft_lstpushback(&env->queued_values, new_value);
			(*events)[i].uses++;
			(*events)[i].happened = 1;
			if ((*events)[i].max_uses > 0)
			{
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
