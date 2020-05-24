/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_enemy_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:19:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 12:09:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		new_enemy_collision_event(t_env *env, t_event_trigger trigger,
t_event event)
{
	(void)env;
	(void)trigger;
	(void)event;
	if (!(env->enemies[trigger.enemy].collision_events =
		(t_event*)ft_realloc(env->enemies[trigger.enemy].collision_events,
		sizeof(t_event) * env->enemies[trigger.enemy].nb_collision_events,
		sizeof(t_event) * (env->enemies[trigger.enemy].nb_collision_events
		+ 1))))
		return (ft_perror("Could not realloc global events"));
	env->enemies[trigger.enemy].collision_events[env->
	enemies[trigger.enemy].nb_collision_events] = event;
	env->enemies[trigger.enemy].nb_collision_events++;
	return (0);
}

int		new_parser_enemy_collision_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	(void)env;
	(void)parser;
	(void)eparser;
	(void)line;
	if (!(env->enemies[eparser->trigger_enemy].collision_events =
		(t_event*)ft_realloc(env->enemies[eparser->trigger_enemy].
		collision_events,
		sizeof(t_event) * env->enemies[eparser->trigger_enemy].
		nb_collision_events,
		sizeof(t_event) * (env->enemies[eparser->trigger_enemy].
		nb_collision_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->enemies[eparser->trigger_enemy].collision_events[env->
	enemies[eparser->trigger_enemy].nb_collision_events] = eparser->event;
	env->enemies[eparser->trigger_enemy].nb_collision_events++;
	return (0);
}

int		new_death_event(t_env *env, t_event_trigger trigger, t_event event)
{
	(void)env;
	(void)trigger;
	(void)event;
	if (!(env->enemies[trigger.enemy].death_events = (t_event*)ft_realloc(
		env->enemies[trigger.enemy].death_events,
		sizeof(t_event) * env->enemies[trigger.enemy].nb_death_events,
		sizeof(t_event) * (env->enemies[trigger.enemy].nb_death_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->enemies[trigger.enemy].death_events[env->enemies[trigger.enemy].
	nb_death_events] = event;
	env->enemies[trigger.enemy].nb_death_events++;
	return (0);
}

int		new_parser_death_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)env;
	(void)parser;
	(void)eparser;
	(void)line;
	if (!(env->enemies[eparser->trigger_enemy].death_events =
		(t_event*)ft_realloc(env->enemies[eparser->trigger_enemy].death_events,
		sizeof(t_event) * env->enemies[eparser->trigger_enemy].nb_death_events,
		sizeof(t_event)
		* (env->enemies[eparser->trigger_enemy].nb_death_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->enemies[eparser->trigger_enemy].
	death_events[env->enemies[eparser->trigger_enemy].nb_death_events] =
	eparser->event;
	env->enemies[eparser->trigger_enemy].nb_death_events++;
	return (0);
}
