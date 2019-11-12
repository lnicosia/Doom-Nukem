/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:53:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/12 20:25:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_event	new_event(int type, void *target, double goal, Uint32 duration)
{
	t_event	new;

	new.target = target;
	if (duration)
		new.duration = duration;
	else
		new.duration = 1;
	new.type = type;
	new.goal = goal;
	new.start_time = 0;
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
	//ft_printf("type = %d\n", type);
	//ft_printf("goal is %f\n", curr->goal);
	//ft_printf("actual value = %f\n", *target);
	*target = curr->start_value + (time - curr->start_time) * curr->incr;
	//ft_printf("new value = %f\n", *target);
	if ((!type && *target >= curr->goal)
		|| (type && *target <= curr->goal))
	{
		*target = curr->goal;
		//ft_printf("{green}Goal reached: target = %f{reset}\n", *target);
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
		//ft_printf("{green}Goal reached: target = %d{reset}\n", *target);
		return (1);
	}
	return (0);
}

//	TODO
//	Protection

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
