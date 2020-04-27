#include "env.h"
#include "update_existing_events.h"
#include "events_parser.h"

int		check_condition_targets4(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list			*new;

	if (target.type == OBJECT_DELETED && target.object >= 0
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

int		check_condition_targets3(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list			*new;

	if (target.type == ENEMY_DELETED && target.enemy >= 0
		&& condition->enemy == target.enemy)
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
	return (check_condition_targets4(env, condition, target, trigger));
}

int		check_condition_targets2(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list			*new;

	if (target.type == VERTEX_DELETED && target.vertex >= 0
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
	return (check_condition_targets3(env, condition, target, trigger));
}

int		check_condition_targets(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list			*new;
	t_event_target	new_target;

	init_target(&new_target);
	if (events_to_delete_contains(env, trigger))
		return (0);
	if (target.type == SECTOR_DELETED && target.sector >= 0
		&& (condition->sector == target.sector
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
	return (check_condition_targets2(env, condition, target, trigger));
}
