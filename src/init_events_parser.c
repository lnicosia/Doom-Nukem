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
