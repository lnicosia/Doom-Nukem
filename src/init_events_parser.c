/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:23:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:06:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		no_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)env;
	(void)line;
	(void)eparser;
	(void)parser;
	return (0);
}

void	no_writer(int fd, t_event event)
{
	(void)fd;
	(void)event;
}

void	init_events_parser_trigger_parsers(t_events_parser *eparser)
{
	eparser->trigger_parsers[GLOBAL] = &no_parser;
	eparser->trigger_parsers[PRESS] = &wall_sprite_parser;
	eparser->trigger_parsers[SHOOT] = &wall_sprite_parser;
	eparser->trigger_parsers[STAND] = &sector_parser;
	eparser->trigger_parsers[WALK_IN] = &sector_parser;
	eparser->trigger_parsers[WALK_OUT] = &sector_parser;
	eparser->trigger_parsers[DEATH] = &enemy_parser;
}

void	init_events_parser(t_events_parser *eparser)
{
	init_events_parser_trigger_parsers(eparser);
	eparser->new_events[GLOBAL] = &new_global_event;
	eparser->new_events[PRESS] = &new_press_event;
	eparser->new_events[SHOOT] = &new_shoot_event;
	eparser->new_events[STAND] = &new_stand_event;
	eparser->new_events[WALK_IN] = &new_walk_in_event;
	eparser->new_events[WALK_OUT] = &new_walk_out_event;
	eparser->new_events[DEATH] = &new_death_event;
	init_events_parser_target_parsers(eparser);
	init_events_parser_target_types(eparser);
	init_events_parser_updaters(eparser);
	init_events_parser_checkers(eparser);
}

void	init_events_parser_links_protection(t_events_parser *eparser)
{
	eparser->event_exists[GLOBAL] = &global_event_exists;
	eparser->event_exists[PRESS] = &press_event_exists;
	eparser->event_exists[SHOOT] = &shoot_event_exists;
	eparser->event_exists[STAND] = &stand_event_exists;
	eparser->event_exists[WALK_IN] = &walk_in_event_exists;
	eparser->event_exists[WALK_OUT] = &walk_out_event_exists;
	eparser->event_exists[DEATH] = &death_event_exists;
	eparser->get_event_array[GLOBAL] = &get_global_event;
	eparser->get_event_array[PRESS] = &get_press_event;
	eparser->get_event_array[SHOOT] = &get_shoot_event;
	eparser->get_event_array[STAND] = &get_stand_event;
	eparser->get_event_array[WALK_IN] = &get_walk_in_event;
	eparser->get_event_array[WALK_OUT] = &get_walk_out_event;
	eparser->get_event_array[DEATH] = &get_death_event;
}
