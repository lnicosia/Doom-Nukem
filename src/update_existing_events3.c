#include "update_existing_events.h"
#include "events_parser.h"

int		check_event_conditions_targets(t_env *env, t_event *event,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	while (i < event->nb_launch_conditions)
	{
		if (check_condition_targets(env, &event->launch_conditions[i],
			target, trigger))
			return (-1);
		i++;
	}
	i = 0;
	while (i < event->nb_exec_conditions)
	{
		if (check_condition_targets(env, &event->exec_conditions[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_event_targets(t_env *env, t_event *event,
t_event_target target, t_event_trigger *trigger)
{
	if (event->nb_launch_conditions > 0 || event->nb_exec_conditions > 0)
	{
		if (check_event_conditions_targets(env, event, target, trigger))
			return (-1);
	}
	return (0);
}

int		check_stand_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = STAND;
	trigger->sector = sector->num;
	while (i < sector->nb_stand_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->stand_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_walk_in_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = WALK_IN;
	trigger->sector = sector->num;
	while (i < sector->nb_walk_in_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->walk_in_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_walk_out_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = WALK_OUT;
	trigger->sector = sector->num;
	while (i < sector->nb_walk_out_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->walk_out_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}
