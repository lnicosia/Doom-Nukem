/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_walk_out_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:19:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 17:05:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		new_walk_out_event(t_env *env, t_event_trigger trigger, t_event event)
{
	if (!(env->sectors[trigger.sector].walk_out_events =
		(t_event*)ft_realloc(env->sectors[trigger.sector].
		walk_out_events, sizeof(t_event)
		* env->sectors[trigger.sector].nb_walk_out_events,
		sizeof(t_event)
		* (env->sectors[trigger.sector].nb_walk_out_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->sectors[trigger.sector].walk_out_events[env->
	sectors[trigger.sector].nb_walk_out_events] = event;
	env->sectors[trigger.sector].nb_walk_out_events++;
	return (0);
}
int		new_parser_walk_out_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)parser;
	(void)line;
	if (!(env->sectors[eparser->trigger_sector].walk_out_events =
		(t_event*)ft_realloc(env->sectors[eparser->trigger_sector].
		walk_out_events, sizeof(t_event)
		* env->sectors[eparser->trigger_sector].nb_walk_out_events,
		sizeof(t_event)
		* (env->sectors[eparser->trigger_sector].nb_walk_out_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->sectors[eparser->trigger_sector].walk_out_events[env->
	sectors[eparser->trigger_sector].nb_walk_out_events] = eparser->event;
	env->sectors[eparser->trigger_sector].nb_walk_out_events++;
	return (0);
}
