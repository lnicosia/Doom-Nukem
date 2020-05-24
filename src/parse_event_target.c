/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_target.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:42:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:05:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		parse_event_target3(t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	eparser->event.check_param.weapon = eparser->current_weapon;
	eparser->event.type = eparser->target_types[eparser->target_index];
	if (!**line)
		return (missing_data("closing ']' brace after event target", parser));
	if (**line != ']')
		return (invalid_char("after target declaration", "']'",
		**line, parser));
		return (0);
}

int		parse_event_target2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	eparser->target_sector = eparser->current_sector;
	eparser->target_wall = eparser->current_wall;
	eparser->target_sprite = eparser->current_sprite;
	eparser->target_enemy = eparser->current_enemy;
	eparser->target_vertex = eparser->current_vertex;
	eparser->target_weapon = eparser->current_weapon;
	eparser->target_object = eparser->current_object;
	eparser->target_str = eparser->current_str;
	eparser->event.target = set_event_target(env, eparser);
	eparser->event.update_param.sector = eparser->target_sector;
	eparser->event.update_param.wall = eparser->target_wall;
	eparser->event.update_param.sprite = eparser->target_sprite;
	eparser->event.update_param.object = eparser->target_object;
	eparser->event.update_param.enemy = eparser->target_enemy;
	eparser->event.update_param.vertex = eparser->current_vertex;
	eparser->event.update_param.weapon = eparser->current_weapon;
	eparser->event.check_param.sector = eparser->target_sector;
	eparser->event.check_param.wall = eparser->target_wall;
	eparser->event.check_param.sprite = eparser->target_sprite;
	eparser->event.check_param.object = eparser->target_object;
	eparser->event.check_param.enemy = eparser->target_enemy;
	eparser->event.check_param.vertex = eparser->current_vertex;
	return (parse_event_target3(parser, line, eparser));
}

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
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for target index\n"));
	eparser->target_index = ft_atoi(*line);
	if (eparser->target_index < 0 || eparser->target_index == PLAYER_SECTOR
		|| eparser->target_index >= MAX_TARGET_TYPES)
		return (custom_error_with_line("Invalid target type", parser));
	if (eparser->target_index == PLAYER_SECTOR)
		return (custom_error_with_line("You can not modifiy the player sector",
		parser));
		eparser->event.target_index = eparser->target_index;
	*line = skip_number(*line);
	init_events_parser_var(eparser);
	if (eparser->target_parsers[eparser->target_index](env, parser, line,
		eparser))
		return (-1);
	return (parse_event_target2(env, parser, line, eparser));
}
