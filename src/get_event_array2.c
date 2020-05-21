/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_event_array2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:19:16 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:37:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

t_event	*get_walk_in_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			walk_in_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector].
			walk_in_events[eparser->target_index]);
}

t_event	*get_walk_out_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->sectors[eparser->source_sector].
			walk_out_events[eparser->source_index]);
	else
		return (&env->sectors[eparser->target_sector].
			walk_out_events[eparser->target_index]);
}

t_event	*get_enemy_collision_event(t_env *env, t_events_parser *eparser,
int mode)
{
	if (!mode)
		return (&env->enemies[eparser->source_enemy].
			collision_events[eparser->source_index]);
	else
		return (&env->enemies[eparser->target_enemy].
			collision_events[eparser->target_index]);
			return (0);
}

t_event	*get_object_collision_event(t_env *env, t_events_parser *eparser,
int mode)
{
	if (!mode)
		return (&env->objects[eparser->source_object].
			collision_events[eparser->source_index]);
	else
		return (&env->objects[eparser->target_object].
			collision_events[eparser->target_index]);
			return (0);
}

t_event	*get_death_event(t_env *env, t_events_parser *eparser, int mode)
{
	if (!mode)
		return (&env->enemies[eparser->source_enemy].
			death_events[eparser->source_index]);
	else
		return (&env->enemies[eparser->target_enemy].
			death_events[eparser->target_index]);
			return (0);
}
