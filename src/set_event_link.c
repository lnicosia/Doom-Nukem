#include "events_parser.h"
#include "events_conditions.h"

int		set_event_link(t_env *env, t_events_parser *eparser)
{
	t_event	*source_array;

	source_array = eparser->get_event_array[eparser->source_type](env,
	eparser, 0);
	if (!(source_array->launch_conditions =
		(t_condition*)ft_realloc(source_array->launch_conditions,
		sizeof(t_condition) * source_array->nb_launch_conditions,
		sizeof(t_condition) * (source_array->nb_launch_conditions + 1))))
		return (-1);
	source_array->launch_conditions[source_array->nb_launch_conditions].target =
	eparser->get_event_array[eparser->target_type](env, eparser, 1);
	source_array->launch_conditions[source_array->nb_launch_conditions].type =
	eparser->link_type == 0 ? EVENT_ENDED : EVENT_ENDED_START;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.type = eparser->source_type;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.sector = eparser->source_sector;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.wall = eparser->source_wall;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.sprite = eparser->source_sprite;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.enemy = eparser->source_enemy;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.source_trigger.index = eparser->source_index;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.type = eparser->target_type;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.sector = eparser->target_sector;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.wall = eparser->target_wall;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.sprite = eparser->target_sprite;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.enemy = eparser->target_enemy;
	source_array->launch_conditions[source_array->nb_launch_conditions]
	.target_trigger.index = eparser->target_index;
	source_array->nb_launch_conditions++;
	return (0);
}
