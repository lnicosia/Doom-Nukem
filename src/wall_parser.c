/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 09:14:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		wall_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)env;
	(void)parser;
	(void)eparser;
	(void)line;
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != ' ')
		return (invalid_char("before sector number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != '(')
		return (invalid_char("before sector number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sector, wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector number", "a digit", **line,
		parser));
	eparser->trigger_sector = ft_atoi(*line);
	if (eparser->trigger_sector < 0
		|| eparser->trigger_sector >= env->nb_sectors)
		return (custom_error_with_line("Invalid sector index", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall number", parser));
	if (**line != ' ')
		return (invalid_char("after sector number", "a space", **line,
		parser));
		(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before wall number", "a digit", **line,
		parser));
	eparser->trigger_wall = ft_atoi(*line);
	if (eparser->trigger_wall < 0
		|| eparser->trigger_wall >= env->sectors[eparser->trigger_sector].nb_vertices)
		return (custom_error_with_line("Invalid wall index", parser));
		*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after sprite index", "')'", **line, parser));
	(*line)++;
	return (0);
}
