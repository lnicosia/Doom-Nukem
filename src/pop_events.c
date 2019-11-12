/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:53:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 17:37:55 by lnicosia         ###   ########.fr       */
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
		curr->running = 0;
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
		curr->running = 0;
		//ft_printf("target = %d\n", *target);
		return (1);
	}
	return (0);
}

void	pop_current(t_list **list, t_list *curr)
{
	while (*list)
	{
		if (*list == curr)
		{
			((t_event*)(*list)->content)->running = 0;
			ft_lstpopfront(list);
			return ; 
		}
		else
			*list = (*list)->next;
	}
}

void	pop_events(t_env *env)
{
	t_event	*curr;
	t_list	*tmp;
	t_list	*start;
	t_list	*del;
	int	res;
	
	tmp = env->events;
	start = env->events;
	//ft_printf("new call\n");
	while (tmp)
	{
		//ft_printf("curr node = %p\n", tmp);
		curr = (t_event*)tmp->content;
		if (curr->type == DOUBLE)
			res = double_event(curr);
		else if (curr->type == INT)
			res = int_event(curr);
		if (res)
		{
			del = tmp;
			tmp = tmp->next;
			//ft_printf("{red}poping node %p{reset}\n", tmp);
			pop_current(&env->events, del);
			//ft_lstpopfront(&tmp);
		}
		else
		{
			tmp = tmp->next;
		}
		//ft_printf("node after = %p\n", tmp);
	}
	precompute_slopes(env);
}
