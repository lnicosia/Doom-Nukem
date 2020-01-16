/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 11:51:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		weapon_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)env;
	if (!**line || **line == ']')
		return (missing_data("weapon data", parser));
	if (**line != ' ')
		return (invalid_char("before weapon number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("weapon data", parser));
	if (**line != '(')
		return (invalid_char("before weapon number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("weapon number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before weapon number", "a digit", **line,
		parser));
	eparser->target_weapon = ft_atoi(*line);
	if (eparser->target_weapon < 0
		|| eparser->target_weapon >= NB_WEAPONS)
		return (custom_error_with_line("Invalid weapon index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after weapon number", "')'", **line, parser));
	(*line)++;
	return (0);
}
