/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 09:26:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		vertex_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("vertex data", parser));
	if (**line != ' ')
		return (invalid_char("before vertex number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("vertex data", parser));
	if (**line != '(')
		return (invalid_char("before vertex number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("vertex number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before vertex number", "a digit", **line,
		parser));
	eparser->target_vertex = ft_atoi(*line);
	if (eparser->target_vertex < 0
		|| eparser->target_vertex >= env->nb_vertices)
		return (custom_error_with_line("Invalid vertex index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after vertex number", "')'", **line, parser));
	(*line)++;
	return (0);
}
