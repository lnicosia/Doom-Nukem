/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:53:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 14:04:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_event	new_event(int type, void *target, double goal, Uint32 duration)
{
	t_event	new;

	new.target = target;
	new.duration = duration;
	new.type = type;
	new.goal = goal;
	new.start_time = 0;
	new.running = 0;
	return (new);
}

int	double_event(t_event *curr)
{
	Uint32	time;
	double	*target;
	int	type;

	time = SDL_GetTicks();
	target = (double*)curr->target;
	//ft_printf("goal is %f\n", curr->goal);
	//ft_printf("actual value = %f\n", *target);
	if (*target < curr->goal)
		type = 0;
	else
		type = 1;
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	//ft_printf("new value = %f\n", *target);
	if ((!type && *target >= curr->goal)
		|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		curr->running = 0;
		//ft_printf("target = %f\n", *target);
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
	//ft_printf("goal is %d\n", curr->goal);
	//ft_printf("actual value = %d\n", *target);
	if (*target < curr->goal)
		type = 0;
	else
		type = 1;
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	//ft_printf("new value = %d\n", *target);
	if ((!type && *target >= curr->goal)
		|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		curr->running = 0;
		//ft_printf("target = %d\n", *target);
		return (1);
	}
	return (0);
}

void	pop_events(t_env *env)
{
	t_event	*curr;
	t_list	*tmp;
	int	res;
	
	tmp = env->events;
	while (tmp)
	{
		curr = (t_event*)tmp->content;
		if (curr->type == DOUBLE)
			res = double_event(curr);
		else if (curr->type == INT)
			res = int_event(curr);
		tmp = tmp->next;
		if (res)
			ft_lstpopfront(&env->events);
	}
	precompute_slopes(env);
}
