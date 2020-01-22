/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:42:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 14:06:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_value(t_env *env, t_map_parser *parser, char **line,
		t_events_parser *eparser)
{
	double		value;

	(void)env;
	if (eparser->event.target_type == INT)
	{
		if (valid_number(*line, parser))
			return (invalid_char("before event value", "a digit", **line,
						parser));
			value = ft_atoi(*line);
	}
	if (eparser->event.target_type == DOUBLE)
	{
		if (valid_number(*line, parser))
			return (invalid_char("before event value", "a digit", **line,
						parser));
			value = ft_atof(*line);
	}
	if (eparser->event.target_type == UINT32)
	{
		if (valid_hexa(*line, parser))
			return (invalid_char("before event value", "a digit", **line,
						parser));
			value = ft_atoi_base(*line, "0123456789ABCDEF");
	}
	*line = skip_number(*line);
	if (eparser->event.mod_type == FIXED)
		eparser->event.goal = value;
	else if (eparser->event.mod_type == INCR)
		eparser->event.start_incr = value;
	return (0);
}

int		parse_event_type(t_env *env, t_map_parser *parser, char **line,
		t_events_parser *eparser)
{
	(*line)++;
	if (!**line)
		return (missing_data("event type, value and duration", parser));
	if (**line != '[')
		return (invalid_char("before event type", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event type, value and duration", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before event type", "a digit", **line, parser));
	eparser->event.mod_type = ft_atoi(*line);
	if (eparser->event.mod_type < 0 || eparser->event.mod_type >= 3)
		return (custom_error_with_line("Invalid event type", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("event value and duration", parser));
	if (**line != ' ')
		return (invalid_char("after event type", "a space", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event value and duration", parser));
	if (parse_value(env, parser, line, eparser))
		return (-1);
	if (!**line || **line == ']')
		return (missing_data("event duration", parser));
	if (**line != ' ')
		return (invalid_char("after event value", "a space", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event duration", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before event duration", "a digit", **line,
		parser));
	eparser->event.duration = ft_atoi(*line);
	if (eparser->event.duration < 0)
		return (custom_error_with_line("Invalid event duration", parser));
	if (eparser->event.duration == 0)
		eparser->event.duration = 1;
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after event type", parser));
	if (**line != ']')
		return (invalid_char("after event type declaration", "']'",
					**line, parser));
		return (0);
}
