#include "env.h"
#include "update_existing_events.h"
#include "events_parser.h"

int		check_condition_targets(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list	*new;

	env->confirmation_box.yes_action = &delete_sector;
	env->confirmation_box.yes_target = env;
	if (target.type == SECTOR_DELETED && (condition->sector == target.sector
		|| condition->target_trigger.sector == target.sector))
	{
		ft_printf("{green}Condition sector link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
	}
	else if (target.type == VERTEX_DELETED
		&& condition->vertex == target.vertex)
	{
		ft_printf("{green}Condition vertex link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
	}
	else if (target.type == ENEMY_DELETED && condition->enemy == target.enemy)
	{
		ft_printf("{green}Condition enemy link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
	}
	else if (target.type == OBJECT_DELETED
		&& condition->object == target.object)
	{
		ft_printf("{green}Condition object link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
	}
	return (0);
}

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
		if (sector->stand_events[i].nb_launch_conditions > 0
			|| sector->stand_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->stand_events[i],
				target, trigger))
				return (-1);
		}
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
		if (sector->walk_in_events[i].nb_launch_conditions > 0
			|| sector->walk_in_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->walk_in_events[i],
				target, trigger))
				return (-1);
		}
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
		if (sector->walk_out_events[i].nb_launch_conditions > 0
			|| sector->walk_out_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &sector->walk_out_events[i],
				target, trigger))
				return (-1);
		}
		i++;
	}
	return (0);
}

int		check_sectors_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		ft_printf("checking sector %d\n", i);
		if (i != target.sector)
		{
			if (env->sectors[i].nb_stand_events > 0)
			{
				if (check_stand_events_targets(env, &env->sectors[i],
				target, trigger))
					return (-1);
			}
			if (env->sectors[i].nb_walk_in_events > 0)
			{
				if (check_walk_in_events_targets(env, &env->sectors[i],
				target, trigger))
					return (-1);
			}
			if (env->sectors[i].nb_walk_out_events > 0)
			{
				if (check_walk_out_events_targets(env, &env->sectors[i],
					target, trigger))
					return (-1);
			}
		}
		i++;
	}
	return (0);
}

int		check_global_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = GLOBAL;
	while (i < env->nb_global_events)
	{
		trigger->index = i;
		ft_printf("checking global event %d\n", i);
		if (env->global_events[i].nb_launch_conditions > 0
			|| env->global_events[i].nb_exec_conditions > 0)
		{
			if (check_event_conditions_targets(env, &env->global_events[i],
				target, trigger))
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
	t_event_trigger		trigger;

	if (check_sectors_events_targets(env, target, &trigger))
		return (-1);
	if (env->nb_global_events > 0 && check_global_events_targets(env, target,
		&trigger))
		return (-1);
	return (0);
}

/*int		update_existing_events(t_env *env, int mode)
{
	if (mode == SECTOR_DELETED)
		return (update_sector_existing_events(env));
	return (0);
}*/
