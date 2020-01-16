/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_exec_conditions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 16:50:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

static int	parse_condition2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event exec condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event exec condition target", "a space",
		**line, parser));
	(*line)++;
		if (valid_number(*line, parser))
		return (invalid_char("before exec condition target", "a digit", **line,
		parser));
		eparser->condition_index = ft_atof(*line);
	if (eparser->condition_index < 0
			|| eparser->condition_index >= MAX_TARGET_TYPES)
		return (custom_error_with_line("Invalid exec condition target",
		parser));
	*line = skip_number(*line);
	if (eparser->target_parsers[eparser->condition_index](env, parser,
		line, eparser))
		return (-1);
	eparser->condition_sector = eparser->current_sector;
	eparser->condition_wall = eparser->current_wall;
	eparser->condition_vertex = eparser->current_vertex;
	eparser->condition_sprite = eparser->current_sprite;
	eparser->condition_enemy = eparser->current_enemy;
	eparser->condition_weapon = eparser->current_weapon;
	eparser->condition_object = eparser->current_object;
	eparser->event.exec_conditions[eparser->condition_count].target =
	set_condition_target(env, eparser);
	eparser->event.exec_conditions[eparser->condition_count].target_type =
	eparser->target_types[eparser->condition_index];
	if (**line != '}')
		return (invalid_char("after exec condition declarartion", "'}'",
		**line, parser));
	return (0);
}

static int	parse_condition(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (**line != '{')
		return (invalid_char("before event exec condition", "'{'",
		**line, parser));
	(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before exec condition type", "a digit", **line,
		parser));
		eparser->event.exec_conditions[eparser->condition_count].type =
	ft_atoi(*line);
	if (eparser->event.exec_conditions[eparser->condition_count].type < 0
		|| eparser->event.exec_conditions[eparser->condition_count].type >=
		MAX_CONDITION_TYPES)
		return (custom_error_with_line("Invalid condition type", parser));
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("exec condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event exec condition type", "a space",
		**line, parser));
		(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before exec condition value", "a digit", **line,
		parser));
		eparser->event.exec_conditions[eparser->condition_count].value =
		ft_atof(*line);
	if (parse_condition2(env, parser, line, eparser))
		return (-1);
	return (0);
}

int				parse_event_exec_conditions(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	(*line)++;
	if (!**line)
		return (missing_data("event exec conditions", parser));
	if (**line != '[')
		return (invalid_char("before event exec conditions", "'['",
		**line, parser));
	if ((eparser->nb_conditions = count_conditions(*line, parser)) == -1)
		return (-1);
	if (!(eparser->event.exec_conditions =
			(t_condition*)ft_memalloc(sizeof(t_condition)
			* eparser->nb_conditions)))
		return (ft_perror("Could not malloc exec conditions"));
	while (eparser->condition_count < eparser->nb_conditions)
	{
		if (parse_condition(env, parser, line, eparser))
			return (-1);
		eparser->condition_count++;
	}
	(*line)++;
	if (**line != ']')
		return (invalid_char("after event exec conditions", "']'",
		**line, parser));
	return (0);
}
