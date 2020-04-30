/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:10:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:10:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_link_target2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line)
		return (missing_data("target index", parser));
	if (**line != ' ')
		return (invalid_char("before target index", "a space", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("target index", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before target index", "a digit", **line, parser));
	eparser->current_index = ft_atoi(*line);
	if (eparser->current_index < 0
		|| !eparser->event_exists[eparser->target_type](env, eparser))
		return (custom_error_with_line("Invalid target event", parser));
	eparser->target_index = eparser->current_index;
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after link target", parser));
	if (**line != ']')
		return (invalid_char("after target index", "']'", **line, parser));
	(*line)++;
	return (0);
}

int		parse_link_target(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line)
		return (missing_data("link target", parser));
	if (**line != '[')
		return (invalid_char("before target type", "'['", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("target type", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before target type", "a digit", **line, parser));
	eparser->target_type = ft_atoi(*line);
	if (eparser->target_type < 0 || eparser->target_type > MAX_TRIGGER_TYPES)
		return (custom_error_with_line("Invalid target event type", parser));
	*line = skip_number(*line);
	init_events_parser_var(eparser);
	if (eparser->trigger_parsers[eparser->target_type](env, parser, line,
		eparser))
		return (-1);
	eparser->target_sector = eparser->current_sector;
	eparser->target_wall = eparser->current_wall;
	eparser->target_sprite = eparser->current_sprite;
	eparser->target_enemy = eparser->current_enemy;
	eparser->target_object = eparser->current_object;
	return (parse_link_target2(env, parser, line, eparser));
}
