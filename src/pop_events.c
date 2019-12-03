/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:53:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/02 17:35:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_event	new_fixed_event(int type, void *target, double goal, Uint32 duration)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = FIXED;
	if (duration)
		new.duration = duration;
	else
		new.duration = 1;
	new.type = type;
	new.goal = goal;
	update_event(&new);
	return (new);
}

t_event	new_incr_event(int type, void *target, double incr, Uint32 duration)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.target = target;
	new.mod_type = INCR;
	if (duration)
		new.duration = duration;
	else
		new.duration = 1;
	new.type = type;
	new.incr = incr;
	update_event(&new);
	return (new);
}

t_event	new_func_event(int (*func)(void *), void *param)
{
	t_event	new;

	ft_bzero(&new, sizeof(new));
	new.type = FUNC;
	new.exec_func = func;
	new.exec_param = param;
	update_event(&new);
	return (new);
}

int	double_event(t_event *curr)
{
	Uint32	time;
	double	*target;
	int	type;

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
	int	*target;
	int	type;

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

int	func_event(t_event *curr)
{
	if (curr->exec_func)
		return (curr->exec_func(curr->exec_param));
	return (1);
}

int		execute_event(t_event *event, t_env *env)
{
	int	res;

	res = 1;
	if (event->check_func)
		if (!event->check_func(event, env))
				return (1);
	if (event->type == DOUBLE)
		res = double_event(event);
	else if (event->type == INT)
		res = int_event(event);
	else if (event->type == FUNC)
		res = func_event(event);
	if (event->update_func)
		event->update_func(event, env);
	return (res);
}

//	TODO
//	Protection

/*
**	This function executes every event as a queue
**	and sets a new queue for the next frame
*/

void	pop_events(t_env *env)
{
	t_event	*curr;
	t_list	*next_events;
	t_list	*next_values;
	int	res;
	
	next_events = NULL;
	next_values = NULL;
	while (env->events)
	{
		curr = (t_event*)env->events->content;
		if (curr->type == DOUBLE)
			res = double_event(curr);
		else if (curr->type == INT)
			res = int_event(curr);
		if (!res)
		{
				ft_lstpushback(&next_events, ft_lstnew(curr,
				sizeof(*curr)));
				ft_lstpushback(&next_values, ft_lstnew(&curr->target,
				sizeof(curr->target)));
		}
		ft_lstpopfront(&env->events);
		ft_lstpopfront(&env->queued_values);
	}
	precompute_slopes(env);
	env->events = next_events;
	env->queued_values = next_values;
}

//	TODO
//	Protection

/*
**	This one executes every event in the list
**	and delete a node when the event is done
*/

void	pop_events2(t_env *env)
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
			if (res)
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
			else
			{
				prec = tmp;
				tmp = tmp->next;
				prec_values = tmp_values;
				tmp_values = tmp_values->next;
			}
		}
}
