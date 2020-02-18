#include "events_parser.h"

/*
**	Mode == source or target
*/

t_event	*get_event_array(t_env *env, t_event_trigger trigger)
{
	if (trigger.index == GLOBAL)
		return (&env->global_events[trigger.index]);
	else if (trigger.index == PRESS)
		return (&env->sectors[trigger.sector]
				.wall_sprites[trigger.wall]
				.press_events[trigger.sprite][trigger.index]);
	else if (trigger.index == SHOOT)
		return (&env->sectors[trigger.sector]
				.wall_sprites[trigger.wall]
				.shoot_events[trigger.sprite][trigger.index]);
	else if (trigger.index == STAND)
		return (&env->sectors[trigger.sector]
				.stand_events[trigger.index]);
	else if (trigger.index == WALK_IN)
		return (&env->sectors[trigger.sector]
				.walk_in_events[trigger.index]);
	else if (trigger.index == STAND)
		return (&env->sectors[trigger.sector]
				.walk_out_events[trigger.index]);
	/*else if (trigger.index == DEATH)
		return (&env->sectors[trigger.sector]
				.stand_events[trigger.index]);*/
	return (0);
}

t_event	*get_global_event(t_env *env, t_events_parser *eparser, int mode)
{
	(void)eparser;
	if (!mode)
		return (&env->global_events[eparser->source_index]);
	else
		return (&env->global_events[eparser->target_index]);
}

t_event	*get_press_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector]
				.wall_sprites[eparser->source_wall]
				.press_events[eparser->source_sprite][eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector]
				.wall_sprites[eparser->target_wall]
				.press_events[eparser->target_sprite][eparser->target_index]);
}

t_event	*get_shoot_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector]
				.wall_sprites[eparser->source_wall]
				.shoot_events[eparser->source_sprite][eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector]
				.wall_sprites[eparser->target_wall]
				.shoot_events[eparser->target_sprite][eparser->target_index]);
}

t_event	*get_stand_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector]
				.stand_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector]
				.stand_events[eparser->target_index]);
}

t_event	*get_walk_in_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector]
				.walk_in_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector]
				.walk_in_events[eparser->target_index]);
}

t_event	*get_walk_out_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector]
				.walk_out_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector]
				.walk_out_events[eparser->target_index]);
}

t_event	*get_death_event(t_env *env, t_events_parser *eparser, int mode)
{
	(void)env;
	(void)eparser;
	(void)mode;
	return (0);
}
