/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:19:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 12:09:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		new_object_collision_event(t_env *env, t_event_trigger trigger,
t_event event)
{
	(void)env;
	(void)trigger;
	(void)event;
	if (!(env->objects[trigger.object].collision_events =
		(t_event*)ft_realloc(env->objects[trigger.object].collision_events,
		sizeof(t_event) * env->objects[trigger.object].nb_collision_events,
		sizeof(t_event) * (env->objects[trigger.object].nb_collision_events
		+ 1))))
		return (ft_perror("Could not realloc global events"));
	env->objects[trigger.object].collision_events[env->
	objects[trigger.object].nb_collision_events] = event;
	env->objects[trigger.object].nb_collision_events++;
	return (0);
}

int		new_parser_object_collision_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	(void)env;
	(void)parser;
	(void)eparser;
	(void)line;
	if (!(env->objects[eparser->trigger_object].collision_events =
		(t_event*)ft_realloc(env->objects[eparser->trigger_object].
		collision_events,
		sizeof(t_event) * env->objects[eparser->trigger_object].
		nb_collision_events,
		sizeof(t_event) * (env->objects[eparser->trigger_object].
		nb_collision_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->objects[eparser->trigger_object].collision_events[env->
	objects[eparser->trigger_object].nb_collision_events] = eparser->event;
	env->objects[eparser->trigger_object].nb_collision_events++;
	return (0);
}
