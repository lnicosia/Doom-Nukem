/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_links_protection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:04:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 13:41:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		walk_out_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->sectors[eparser->current_sector].
		nb_walk_out_events)
		return (0);
	return (1);
}

int		death_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->enemies[eparser->current_enemy].
		nb_death_events)
		return (0);
	return (1);
}

int		enemy_collision_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->enemies[eparser->current_enemy].
		nb_collision_events)
		return (0);
	return (1);
}

int		object_collision_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->objects[eparser->current_object].
		nb_collision_events)
		return (0);
	return (1);
}
