/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:51:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 10:51:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "env.h"
#include "parser.h"

int		parse_ceiling6(t_env *env, char **line, t_map_parser *parser)
{
	if (env->sectors[parser->sectors_count].ceiling_map_scale.y < 1
		|| env->sectors[parser->sectors_count].ceiling_map_scale.y > 100)
		return (custom_error_with_line("Ceiling scale value: 1/100", parser));
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after ceiling texture", parser));
	if (**line != ']')
		return (invalid_char("after ceiling texture", "a digit or ']'",
			**line, parser));
		(*line)++;
	if (!**line)
		return (missing_data("vertices, neighbors, textures and light",
			parser));
		if (**line != ' ')
		return (invalid_char("after ceiling data", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}
