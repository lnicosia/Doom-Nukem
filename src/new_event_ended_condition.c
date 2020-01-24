/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_event_ended_condition.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:25:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/23 12:27:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		new_event_ended_condition(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	t_list			*new;
	t_event_link	link;

	if (**line == '}')
		return (missing_data("condition trigger type", parser));
	if (**line != ' ')
		return (invalid_char("after condition type", "a space", **line,
		parser));
		(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before launch condition value", "a digit", **line,
		parser));
		link.source_trigger = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("condition target event data", parser));
	if (**line != ' ')
		return (invalid_char("after condition trigger type", "a space", **line,
		parser));
		(*line)++;
		if (eparser->trigger_parsers[link.source_trigger](env, parser, line,
			eparser))
			return (-1);
	(void)env;
	(void)parser;
	(void)line;
	(void)eparser;
	(void)new;
	return (0);
}
