#include "env.h"
#include "update_existing_events.h"

int		check_condition_targets(t_env *env, t_condition *condition,
t_event_target target)
{
	env->confirmation_box.no_action = 0;
	/*ft_printf("type = %d\n", target.type);
	ft_printf("condition sector = %d\n", condition->sector);
	ft_printf("condition link sector = %d\n", condition->target_trigger.sector);
	ft_printf("target sector = %d\n", target.sector);*/
	if (target.type == SECTOR_DELETED && (condition->sector == target.sector
		|| condition->target_trigger.sector == target.sector))
	{
		ft_printf("{green}Condition sector link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete events. Are you sure?", YESNO,
			env))
			return (-1);
		env->confirmation_box.yes_action = &delete_sector;
		env->confirmation_box.yes_target = env;
	}
	else if (target.type == VERTEX_DELETED
		&& condition->vertex == target.vertex)
	{
		ft_printf("{green}Condition vertex link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete events. Are you sure?", YESNO,
			env))
			return (-1);
		env->confirmation_box.yes_action = &delete_sector;
		env->confirmation_box.yes_target = env;
	}
	return (0);
}

int		check_event_conditions_targets(t_env *env, t_event *event,
t_event_target target)
{
	size_t	i;

	i = 0;
	while (i < event->nb_launch_conditions)
	{
		if (check_condition_targets(env, &event->launch_conditions[i],
			target))
			return (-1);
		i++;
	}
	i = 0;
	while (i < event->nb_exec_conditions)
	{
		if (check_condition_targets(env, &event->exec_conditions[i],
			target))
			return (-1);
		i++;
	}
	return (0);
}

int		check_stand_events_targets(t_env *env, t_sector *sector,
t_event_target target)
{
	size_t	i;

	i = 0;
	while (i < sector->nb_stand_events)
	{
		if (sector->stand_events[i].nb_launch_conditions > 0
			|| sector->stand_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->stand_events[i],
				target))
				return (-1);
		}
		i++;
	}
	return (0);
}

int		check_walk_in_events_targets(t_env *env, t_sector *sector,
t_event_target target)
{
	size_t	i;

	i = 0;
	while (i < sector->nb_walk_in_events)
	{
		if (sector->walk_in_events[i].nb_launch_conditions > 0
			|| sector->walk_in_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->walk_in_events[i],
				target))
				return (-1);
		}
		i++;
	}
	return (0);
}

int		check_walk_out_events_targets(t_env *env, t_sector *sector,
t_event_target target)
{
	size_t	i;

	i = 0;
	while (i < sector->nb_walk_out_events)
	{
		if (sector->walk_out_events[i].nb_launch_conditions > 0
			|| sector->walk_out_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->walk_out_events[i],
				target))
				return (-1);
		}
		i++;
	}
	return (0);
}

int		check_sectors_events_targets(t_env *env, t_event_target target)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		ft_printf("checking sector %d\n", i);
		if (i != target.sector)
		{
			if (env->sectors[i].nb_stand_events > 0)
				check_stand_events_targets(env, &env->sectors[i], target);
			if (env->sectors[i].nb_walk_in_events > 0)
				check_walk_in_events_targets(env, &env->sectors[i], target);
			if (env->sectors[i].nb_walk_out_events > 0)
				check_walk_out_events_targets(env, &env->sectors[i], target);
		}
		i++;

	}
	return (0);
}

int		check_global_events_targets(t_env *env, t_event_target target)
{
	size_t	i;

	i = 0;
	while (i < env->nb_global_events)
	{
		ft_printf("checking global event %d\n", i);
		if (env->global_events[i].nb_launch_conditions > 0
			|| env->global_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &env->global_events[i],
				target))
				return (-1);
		}
		i++;
	}
	return (0);
}

/*
**	Check if any existing events had the deleted sector as a target
**	Things to check:
**	Every trigger (enemies, objects, wall sprites, global, sector)
*/

int		update_sector_existing_events(t_env *env, t_event_target target)
{
	if (check_sectors_events_targets(env, target))
		return (-1);
	if (env->nb_global_events > 0 && check_global_events_targets(env, target))
		return (-1);
	return (0);
}

/*int		update_existing_events(t_env *env, int mode)
{
	if (mode == SECTOR_DELETED)
		return (update_sector_existing_events(env));
	return (0);
}*/
