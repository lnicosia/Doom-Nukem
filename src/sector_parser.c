/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 15:31:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		sector_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != ' ')
		return (invalid_char("before sector number", "a space",
		**line, parser));
		(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("sector data", parser));
	if (**line != '(')
		return (invalid_char("before sector number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sector number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector number", "a digit", **line,
		parser));
		eparser->current_sector = ft_atoi(*line);
	if (eparser->current_sector < 0
		|| eparser->current_sector >= env->nb_sectors)
		return (custom_error_with_line("Invalid sector index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after sector number", "')'", **line, parser));
	(*line)++;
	return (0);
}
