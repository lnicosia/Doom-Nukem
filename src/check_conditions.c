#include "events_conditions.h"

int		check_launch_condition(t_event *event, t_condition *tab, size_t i,
t_env *env)
{
	if (tab[i].type < EVENT_ENDED && !condition_target_exists(&tab[i], env))
		return (1);
	if (tab[i].type == EQUALS && equals_condition(&tab[i]))
		return (0);
	else if (tab[i].type == DIFFERENT && different_condition(&tab[i]))
		return (0);
	else if (tab[i].type == LESS && less_condition(&tab[i]))
		return (0);
	else if (tab[i].type == GREATER && greater_condition(&tab[i]))
		return (0);
	else if (tab[i].type == LESS_OR_EQUALS
			&& less_or_equals_condition(&tab[i]))
		return (0);
	else if (tab[i].type == GREATER_OR_EQUALS
			&& greater_or_equals_condition(&tab[i]))
		return (0);
	else if (tab[i].type == EVENT_ENDED
			&& event_ended_condition(&tab[i], event))
		return (0);
	else if (tab[i].type == EVENT_ENDED_START
			&& event_ended_start_condition(&tab[i], event))
		return (0);
	return (2);
}

int		check_launch_conditions(t_event *event, t_condition *tab, size_t nb,
t_env *env)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < nb)
	{
	  	if ((ret = check_launch_condition(event, tab, i, env)) != 2)
		  	return (ret);
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

int		check_exec_condition(t_event *event, t_condition *tab, size_t i,
t_env *env)
{
	if (!condition_target_exists(&tab[i], env))
	{
		ft_printf("target does not exist\n");
		return (1);
	}
	if (tab[i].type == EQUALS && equals_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == DIFFERENT && different_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == LESS && less_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == GREATER && greater_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == LESS_OR_EQUALS && less_or_equals_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == GREATER_OR_EQUALS
			&& greater_or_equals_condition(&tab[i]))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == EVENT_ENDED
			&& event_ended_condition(&tab[i], event))
		return (set_target_to_condition(event, tab[i]));
	else if (tab[i].type == EVENT_ENDED_START
			&& event_ended_start_condition(&tab[i], event))
		return (set_target_to_condition(event, tab[i]));
	return (2);
}

int		check_exec_conditions(t_event *event, t_condition *tab, size_t nb,
t_env *env)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < nb)
	{
	  	if ((ret = check_exec_condition(event, tab, i, env)) != 2)
		  	return (ret);
		i++;
	}
	return (1);
}
