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
	source_array->nb_launch_conditions++;
	return (0);
}
