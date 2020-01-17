/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:53:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/17 14:20:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	double_event(t_event *curr)
{
	Uint32	time;
	double	*target;
	int		type;

	time = SDL_GetTicks();
	target = (double*)curr->target;
	if (*target < curr->goal)
		type = 0;
	else
		type = 1;
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	if ((!type && *target >= curr->goal)
			|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		return (1);
	}
	return (0);
}

int	int_event(t_event *curr)
{
	Uint32	time;
	int		*target;
	int		type;

	time = SDL_GetTicks();
	target = (int*)curr->target;
	if (*target < curr->goal)
		type = 0;
	else
		type = 1;
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	if ((!type && *target >= curr->goal)
			|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		return (1);
	}
	return (0);
}

int	uint32_event(t_event *curr)
{
	Uint32	time;
	Uint32	*target;
	int		type;

	time = SDL_GetTicks();
	target = (Uint32*)curr->target;
	if (*target < curr->goal)
		type = 0;
	else
		type = 1;
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	if ((!type && *target >= curr->goal)
			|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		return (1);
	}
	return (0);
}

int	func_event(t_event *curr, t_env *env)
{
	if (curr->exec_func)
		return (curr->exec_func(curr->exec_param, env));
	return (1);
}

int		execute_event(t_event *event, t_env *env)
{
	int	res;
	int	check;

	res = 1;
	check = 0;
	if (event->exec_conditions
		&& !check_conditions(*event, event->exec_conditions,
		event->nb_exec_conditions))
		return (1);
	if (event->check_func)
	{
		check = event->check_func(event, env);
		if (check == -1)
			return (-1);
		else if (check)
			return (1);
	}
	if (event->type == DOUBLE)
		res = double_event(event);
	else if (event->type == INT)
		res = int_event(event);
	else if (event->type == UINT32)
		res = uint32_event(event);
	else if (event->type == FUNC)
		res = func_event(event, env);
	if (event->update_func)
	{
		if (event->update_func(event, env))
			return (-1);
	}
	return (res);
}

//	TODO
//	Protection

/*
 **	This one executes every event in the list
 **	and delete a node only when the event is done
 */

int		pop_events(t_env *env)
{
	t_list	*prec;
	t_list	*tmp;
	t_list	*prec_values;
	t_list	*tmp_values;
	int		res;

	tmp = env->events;
	tmp_values = env->queued_values;
	prec_values = NULL;
	prec = NULL;
	while (tmp)
	{
		res = execute_event((t_event*)tmp->content, env);
		if (res == 1)
		{
			ft_lstpopfront(&tmp);
			if (prec)
				prec->next = tmp;
			else
				env->events = tmp;
			ft_lstpopfront(&tmp_values);
			if (prec_values)
				prec_values->next = tmp_values;
			else
				env->queued_values = tmp_values;
		}
		else if (res == 0)
		{
			prec = tmp;
			tmp = tmp->next;
			prec_values = tmp_values;
			tmp_values = tmp_values->next;
		}
		else if (res == -1)
			return (-1);
	}
	return (0);
}
