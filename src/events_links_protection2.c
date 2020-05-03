/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_links_protection2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:52:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:52:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		global_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->nb_global_events)
		return (0);
	return (1);
}

int		press_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->sectors[eparser->current_sector].
		wall_sprites[eparser->current_wall].
		nb_press_events[eparser->current_sprite])
		return (0);
	return (1);
}

int		shoot_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->sectors[eparser->current_sector].
		wall_sprites[eparser->current_wall].
		nb_shoot_events[eparser->current_sprite])
		return (0);
	return (1);
}

int		stand_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->sectors[eparser->current_sector].
		nb_stand_events)
		return (0);
	return (1);
}

int		walk_in_event_exists(t_env *env, t_events_parser *eparser)
{
	if (eparser->current_index >= (int)env->sectors[eparser->current_sector].
		nb_walk_in_events)
		return (0);
	return (1);
}
