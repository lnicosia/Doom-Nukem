/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:46:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 17:52:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_event_trigger(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event trigger", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before event trigger", "a digit",
		**line, parser));
	eparser->trigger = ft_atoi(*line);
	if (eparser->trigger < 0 || eparser->trigger > MAX_TRIGGER_TYPES)
		return (custom_error_with_line("Invalid trigger type", parser));
	*line = skip_number(*line);
	if (eparser->trigger_parsers[eparser->trigger](env, parser, line, eparser))
		return (-1);
	eparser->trigger_sector = eparser->current_sector;
	eparser->trigger_wall = eparser->current_wall;
	eparser->trigger_sprite = eparser->current_sprite;
	eparser->trigger_enemy = eparser->current_enemy;
	if (!**line)
		return (missing_data("closing ']' brace after event trigger", parser));
	if (**line != ']')
		return (invalid_char("after trigger declaration", "']'",
		**line, parser));
	return (0);
}

int		parse_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (parse_event_trigger(env, parser, line, eparser))
		return (-1);
	if (parse_event_target(env, parser, line, eparser))
		return (-1);
	if (parse_event_type(env, parser, line, eparser))
		return (-1);
	if (parse_event_launch_conditions(env, parser, line, eparser))
		return (-1);
	if (parse_event_exec_conditions(env, parser, line, eparser))
		return (-1);
	if (parse_event_various_data(env, parser, line, eparser))
		return (-1);
	eparser->event.exec_func = eparser->checkers[eparser->target_index];
	eparser->event.update_func = eparser->updaters[eparser->target_index];
	if (eparser->new_events[eparser->trigger](env, parser, line, eparser))
		return (-1);
	return (0);
}

int		parse_events(t_env *env, t_map_parser *parser)
{
	t_events_parser	eparser;
	char			*line;
	char			*tmp;

	line = NULL;
	ft_bzero(&eparser, sizeof(eparser));
	init_events_parser(&eparser);
	while ((parser->ret = get_next_line(parser->fd, &line)))
	{
		tmp = line;
		parser->line_count++;
		if (*line == '[')
		{
			if (parse_event(env, parser, &line, &eparser))
			{
				ft_strdel(&tmp);
				return (-1);
			}
		}
		else if (!*line)
		{
			ft_strdel(&tmp);
			break ;
		}
		else if (*line != '#')
			return (invalid_char("event declaration", "[", *line, parser));
		ft_strdel(&tmp);
	}
	return (0);
}
