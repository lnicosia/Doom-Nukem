/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 11:50:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

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
	if (valid_number(*line, parser))
		return (invalid_char("before object number", "a digit", **line,
		parser));
	eparser->target_object = ft_atoi(*line);
	if (eparser->target_object < 0
		|| eparser->target_object >= env->nb_objects)
		return (custom_error_with_line("Invalid object index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after object number", "')'", **line, parser));
	(*line)++;
	return (0);
}
