/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 09:27:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		enemy_parser0(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("enemy data", parser));
	if (**line != ' ')
		return (invalid_char("before enemy number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("enemy data", parser));
	if (**line != '(')
		return (invalid_char("before enemy number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("enemy number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy number", "a digit", **line,
		parser));
	eparser->trigger_enemy = ft_atoi(*line);
	if (eparser->trigger_enemy < 0
		|| eparser->trigger_enemy >= env->nb_enemies)
		return (custom_error_with_line("Invalid enemy index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after enemy number", "')'", **line, parser));
	(*line)++;
	return (0);
}

int		enemy_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("enemy data", parser));
	if (**line != ' ')
		return (invalid_char("before enemy number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("enemy data", parser));
	if (**line != '(')
		return (invalid_char("before enemy number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("enemy number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy number", "a digit", **line,
		parser));
	eparser->target_enemy = ft_atoi(*line);
	if (eparser->target_enemy < 0
		|| eparser->target_enemy >= env->nb_enemies)
		return (custom_error_with_line("Invalid enemy index", parser));
	*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after enemy number", "')'", **line, parser));
	(*line)++;
	return (0);
}
