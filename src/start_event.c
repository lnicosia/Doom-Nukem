/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:17:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:24:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_conditions.h"

int		is_queued(t_list *queued_values, void *target)
{
	while (queued_values)
	{
		if (*(long*)queued_values->content == (long)target)
			return (1);
		queued_values = queued_values->next;
	}
	return (0);
}

int		update_queued_events_list(t_event **events, size_t *i, t_env *env)
{
	t_list		*new_value;

	if (!(new_value =
		ft_lstnew(&(*events)[*i].target, sizeof((*events)[*i].target))))
		return (ft_perror("Could not malloc new event"));
	ft_lstpushback(&env->queued_values, new_value);
	return (0);
}

int		update_events_list(t_event **events, size_t *i, size_t *size,
t_env *env)
{
	t_list		*new;

	if (!(new = ft_lstnew(&(*events)[*i], sizeof(t_event))))
		return (ft_perror("Could not malloc new event"));
	ft_lstpushback(&env->events, new);
	if (update_queued_events_list(events, i, env))
		return (-1);
	(*events)[*i].uses++;
	(*events)[*i].happened = 1;
	if ((*events)[*i].max_uses > 0)
	{
		if ((*events)[*i].uses >= (*events)[*i].max_uses)
		{
			*events = (t_event*)ft_delindex((*events),
			sizeof(t_event) * (*size), sizeof(t_event), sizeof(t_event) * *i);
			(*size)--;
			if (*size > 0 && !(*events))
				return (-1);
		}
		else
			(*i)++;
	}
	return (0);
}

int		start_event(t_event **events, size_t *size, t_env *env)
{
	size_t		i;

	i = 0;
	while (i < *size)
	{
		if (event_target_exists(&(*events)[i], env)
			&& (!(*events)[i].target
			|| !is_queued(env->queued_values, (*events)[i].target))
			&& (!(*events)[i].launch_conditions
			|| check_launch_conditions(&(*events)[i],
			(*events)[i].launch_conditions,
			(*events)[i].nb_launch_conditions, env))
			&& update_event(&(*events)[i]))
		{
			if (update_events_list(events, &i, size, env))
				return (-1);
			else
				i++;
		}
		else
			i++;
	}
	return (0);
}

int		start_event_free(t_event **events, size_t *size, t_env *env)
{
	size_t		i;

	i = 0;
	while (i < *size)
	{
		if (event_target_exists(&(*events)[i], env)
			&& (!(*events)[i].launch_conditions
					|| check_launch_conditions(&(*events)[i],
					(*events)[i].launch_conditions,
					(*events)[i].nb_launch_conditions, env))
				&& update_event(&(*events)[i]))
		{
			if (update_events_list(events, &i, size, env))
				return (-1);
		}
		else
			i++;
	}
	return (0);
}
