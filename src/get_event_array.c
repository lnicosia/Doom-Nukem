/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:03:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:20:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

t_event	*get_event_array2(t_env *env, t_event_trigger trigger)
{
	if (trigger.type == ENEMY_COLLISION)
		return (&env->enemies[trigger.enemy]
				.collision_events[trigger.index]);
	else if (trigger.type == OBJECT_COLLISION)
		return (&env->objects[trigger.object]
				.collision_events[trigger.index]);
		return (0);
}

/*
**	Mode == source or target
*/

t_event	*get_event_array(t_env *env, t_event_trigger trigger)
{
	if (trigger.type == GLOBAL)
		return (&env->global_events[trigger.index]);
	else if (trigger.type == PRESS)
		return (&env->sectors[trigger.sector]
				.wall_sprites[trigger.wall]
				.press_events[trigger.sprite][trigger.index]);
	else if (trigger.type == SHOOT)
		return (&env->sectors[trigger.sector]
				.wall_sprites[trigger.wall]
				.shoot_events[trigger.sprite][trigger.index]);
	else if (trigger.type == STAND)
		return (&env->sectors[trigger.sector]
				.stand_events[trigger.index]);
	else if (trigger.type == WALK_IN)
		return (&env->sectors[trigger.sector]
				.walk_in_events[trigger.index]);
	else if (trigger.type == STAND)
		return (&env->sectors[trigger.sector]
				.walk_out_events[trigger.index]);
	else if (trigger.type == DEATH)
		return (&env->enemies[trigger.enemy]
				.death_events[trigger.index]);
		return (get_event_array2(env, trigger));
}
