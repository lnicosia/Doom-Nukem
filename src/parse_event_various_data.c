/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_various_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:52:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:45:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_event_various_data2(t_map_parser *parser,
		char **line, t_events_parser *eparser)
{
	if (**line != ' ')
		return (invalid_char("after event delay", "a space", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("even maximum uses", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for event max uses\n"));
	eparser->event.max_uses = ft_atoi(*line);
	if (eparser->event.max_uses < 0)
		return (custom_error_with_line("Invalid number of uses", parser));
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after event maximum uses",
			parser));
		if (**line != ']')
		return (invalid_char("after event maximum uses", "']'",
		**line, parser));
		(*line)++;
	if (**line)
		return (extra_data("event various data", parser));
	return (0);
}

int		parse_event_various_data(t_env *env, t_map_parser *parser,
		char **line, t_events_parser *eparser)
{
	int		delay;

	(void)env;
	(*line)++;
	if (!**line)
		return (missing_data("event various data", parser));
	if (**line != '[')
		return (invalid_char("before event various data", "'['",
			**line, parser));
		(*line)++;
	if (!**line)
		return (missing_data("event delay and maximum uses", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for event delay\n"));
	delay = ft_atoi(*line);
	if (delay < 0)
		return (custom_error_with_line("Invalid delay", parser));
	eparser->event.delay = delay;
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("event maximum uses", parser));
	return (parse_event_various_data2(parser, line, eparser));
}
