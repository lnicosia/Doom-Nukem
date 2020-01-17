/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:42:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/17 15:02:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_event_target(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
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
	if (eparser->target_index < 0 || eparser->target_index == PLAYER_SECTOR
		|| eparser->target_index >= MAX_TARGET_TYPES)
		return (custom_error_with_line("Invalid target type", parser));
	*line = skip_number(*line);
	if (eparser->target_parsers[eparser->target_index](env, parser, line,
		eparser))
		return (-1);
	eparser->target_sector = eparser->current_sector;
	eparser->target_wall = eparser->current_wall;
	eparser->target_sprite = eparser->current_sprite;
	eparser->target_enemy = eparser->current_enemy;
	eparser->target_vertex = eparser->current_vertex;
	eparser->target_weapon = eparser->current_weapon;
	eparser->target_object = eparser->current_object;
	eparser->event.target = set_event_target(env, eparser);
	eparser->event.update_param.sector = eparser->target_sector;
	eparser->event.update_param.wall = eparser->target_wall;
	eparser->event.update_param.sprite = eparser->target_sprite;
	eparser->event.check_param.sector = eparser->target_sector;
	eparser->event.check_param.wall = eparser->target_wall;
	eparser->event.check_param.sprite = eparser->target_sprite;
	eparser->event.type = eparser->target_types[eparser->target_index];
	if (!**line)
		return (missing_data("closing ']' brace after event target", parser));
	if (**line != ']')
		return (invalid_char("after target declaration", "']'",
		**line, parser));
		return (0);
}
