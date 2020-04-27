#include "update_existing_events.h"
#include "events_parser.h"

int		events_to_delete_contains(t_env *env, t_event_trigger *trigger)
{
	t_event_trigger	*tmp;

	while (env->editor.events_to_delete)
	{
		tmp = (t_event_trigger*)env->editor.events_to_delete->content;
		if (tmp->type == trigger->type
			&& tmp->index == trigger->index
			&& tmp->sector == trigger->sector
			&& tmp->wall == trigger->wall
			&& tmp->enemy == trigger->enemy
			&& tmp->object == trigger->object
			&& tmp->sprite == trigger->sprite)
			return (1);
		env->editor.events_to_delete = env->editor.events_to_delete->next;
	}
	return (0);
}

int		delete_events_to_delete_list(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	ft_lstdelfront(&env->editor.events_to_delete);
	return (0);
}
