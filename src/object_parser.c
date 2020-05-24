/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:43:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		object_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("object data", parser));
	if (**line != ' ')
		return (invalid_char("before object number", "a space",
		**line, parser));
		(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("object data", parser));
	if (**line != '(')
		return (invalid_char("before object number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("object number", parser));
	if (valid_int(*line, parser))
		return (invalid_char("before object number", "a digit", **line,
		parser));
		eparser->current_object = ft_atoi(*line);
	if (eparser->current_object < 0
		|| eparser->current_object >= env->nb_objects)
		return (custom_error_with_line("Invalid object index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after object number", "')'", **line, parser));
	(*line)++;
	return (0);
}
