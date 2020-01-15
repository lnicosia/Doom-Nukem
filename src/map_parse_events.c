/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:46:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 17:43:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_trigger(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event trigger", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before event trigger", "a digit",
		**line, parser));
	eparser->trigger = ft_atoi(*line);
	*line = skip_number(*line);
	if (eparser->trigger < 0 || eparser->trigger > MAX_TRIGGER_TYPES)
		return (custom_error_with_line("Invalid trigger type", parser));
	if (eparser->trigger_types[eparser->trigger](env, parser, line, eparser))
		return (-1);
	if (**line != ']')
		return (invalid_char("after trigger declaration", "]",
		**line, parser));
	return (0);
}

int		parse_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (parse_trigger(env, parser, line, eparser))
		return (-1);
	if (parse_target(env, parser, line, eparser))
		return (-1);
	return (0);
}

int		parse_events(t_env *env, t_map_parser *parser)
{
	t_events_parser	eparser;
	char			*line;
	char			*tmp;

	line = NULL;
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
