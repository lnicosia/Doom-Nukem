/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_events_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 13:39:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_link_source2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (valid_number(*line, parser))
		return (invalid_char("before source index", "a digit", **line, parser));
		eparser->current_index = ft_atoi(*line);
	if (eparser->current_index < 0
		|| !eparser->event_exists[eparser->source_type](env, eparser))
		return (custom_error_with_line("Invalid source event", parser));
		eparser->source_index = eparser->current_index;
		*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after link source", parser));
	if (**line != ']')
		return (invalid_char("after source index", "']'", **line, parser));
	(*line)++;
	return (0);
}

int		parse_link_source(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (valid_number(*line, parser))
		return (invalid_char("before source type", "a digit", **line, parser));
		eparser->source_type = ft_atoi(*line);
	if (eparser->source_type < 0 || eparser->source_type > MAX_TRIGGER_TYPES)
		return (custom_error_with_line("Invalid source event type", parser));
		*line = skip_number(*line);
	init_events_parser_var(eparser);
	if (eparser->trigger_parsers[eparser->source_type](env, parser, line,
		eparser))
		return (-1);
	eparser->source_sector = eparser->current_sector;
	eparser->source_wall = eparser->current_wall;
	eparser->source_sprite = eparser->current_sprite;
	eparser->source_enemy = eparser->current_enemy;
	eparser->source_object = eparser->current_object;
	if (!**line)
		return (missing_data("source index", parser));
	if (**line != ' ')
		return (invalid_char("before source index", "a space", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("source index", parser));
	return (parse_link_source2(env, parser, line, eparser));
}

int		parse_link(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (parse_link_source(env, parser, line, eparser))
		return (-1);
	if (parse_link_target(env, parser, line, eparser))
		return (-1);
	if (!**line || **line == ']')
		return (missing_data("link type", parser));
	if (**line != '[')
		return (invalid_char("before link type", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("link type", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before link type", "a digit", **line, parser));
		eparser->link_type = ft_atoi(*line);
	if (eparser->link_type != 0 && eparser->link_type != 1)
		return (custom_error_with_line("Invalid link type", parser));
		*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after link type", parser));
	if (**line != ']')
		return (invalid_char("after link type", "']'", **line, parser));
	if (set_event_link(env, eparser))
		return (-1);
	return (0);
}

int		parse_events_links2(t_env *env, t_map_parser *parser,
t_events_parser *eparser)
{
	char			*line;

	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		line = parser->line;
		parser->line_count++;
		if (*line == '[')
		{
			if (parse_link(env, parser, &line, eparser))
				return (-1);
		}
		else if (!*line)
		{
			ft_strdel(&parser->line);
			break ;
		}
		else if (*line != '#')
			return (invalid_char("at link declaration", "[", *line, parser));
		ft_strdel(&parser->line);
	}
	return (0);
}

int		parse_events_links(t_env *env, t_map_parser *parser)
{
	t_events_parser	eparser;

	ft_bzero(&eparser, sizeof(eparser));
	init_events_parser(&eparser);
	init_events_parser_links_protection(&eparser);
	return (parse_events_links2(env, parser, &eparser));
}
