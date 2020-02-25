#include "events_parser.h"

void	init_trigger(t_event_trigger *trigger)
{
	trigger->type = -1;
	trigger->index = -1;
	trigger->sector = -1;
	trigger->wall = -1;
	trigger->sprite = -1;
	trigger->object = -1;
	trigger->enemy = -1;
}

void	init_condition(t_condition *condition)
{
	condition->type = -1;
	condition->target_index = -1;
	condition->target_type = -1;
	condition->sector = -1;
	condition->wall = -1;
	condition->sprite = -1;
	condition->size = -1;
	condition->enemy = -1;
	condition->object = -1;
	condition->vertex = -1;
	condition->weapon = -1;
	condition->target = 0;
	init_trigger(&condition->source_trigger);
	init_trigger(&condition->target_trigger);
}

void	init_target(t_event_target *target)
{
	ft_bzero(target, sizeof(*target));
	target->type = -1;
	target->sector = -1;
	target->wall = -1;
	target->sprite = -1;
	target->enemy = -1;
	target->object = -1;
	target->vertex = -1;
	target->weapon = -1;
}
