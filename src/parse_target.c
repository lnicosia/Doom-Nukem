/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:42:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 17:56:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_target(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)env;
	(void)parser;
	(void)eparser;
	(void)line;
	(*line)++;
	if (!**line)
		return (missing_data("event target", parser));
	if (**line != '[')
		return (invalid_char("before event target", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event target", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before event target", "'['", **line, parser));
	eparser->target_index = ft_atoi(*line);
	if (eparser->target_index < 0
		|| eparser->target_index >= MAX_TARGET_TYPES)
		return (custom_error_with_line("Invalid target type", parser));
	return (0);
}
