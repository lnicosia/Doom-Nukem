/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_launch_conditions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 16:13:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

int		count_conditions(char *line, t_map_parser *parser)
{
	int	count;
	int	open;

	count = 0;
	open = 0;
	while (*line != ']')
	{
		if (!*line)
			return (missing_data("']' after event conditions", parser));
		if (*line == '{')
		{
			if (open)
				return (custom_error_with_line("Unbalanced \'{\' and \'}\'",
				parser));
				open++;
			count++;
			if (count > 2147483646)
				return (custom_error_with_line("Too much conditions",
				parser));
		}
		if (*line == '}')
		{
			if (!open)
				return (custom_error_with_line("Unbalanced \'{\' and \'}\'",
				parser));
				open--;
		}
		line++;
	}
	return (count);
}

int		parse_condition2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event condition target", "a space", **line,
		parser));
	(*line)++;
		if (valid_number(*line, parser))
		return (invalid_char("before condition target", "a digit", **line,
		parser));
		eparser->condition_index = ft_atof(*line);
	if (eparser->condition_index < 0
			|| eparser->condition_index >= MAX_TARGET_TYPES)
		return (custom_error_with_line("Invalid condition target", parser));
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
	eparser->event.launch_conditions[eparser->condition_count].target =
	set_condition_target(env, eparser);
	eparser->event.launch_conditions[eparser->condition_count].target_type =
	eparser->target_types[eparser->condition_index];
	return (0);
}

int		parse_condition(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (**line != '{')
		return (invalid_char("before event condition", "'{'", **line, parser));
	(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before condition type", "a digit", **line,
		parser));
		eparser->event.launch_conditions[eparser->condition_count].type =
	ft_atoi(*line);
	if (eparser->event.launch_conditions[eparser->condition_count].type < 0
		|| eparser->event.launch_conditions[eparser->condition_count].type >=
		MAX_CONDITION_TYPES)
		return (custom_error_with_line("Invalid condition type", parser));
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event condition type", "a space", **line,
		parser));
		(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before condition value", "a digit", **line,
		parser));
		eparser->event.launch_conditions[eparser->condition_count].value =
		ft_atof(*line);
	if (parse_condition2(env, parser, line, eparser))
		return (-1);
	return (0);
}

int		parse_event_launch_conditions(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	(*line)++;
	if (!**line)
		return (missing_data("event conditions", parser));
	if (**line != '[')
		return (invalid_char("before event conditions", "'['", **line, parser));
	if ((eparser->nb_conditions = count_conditions(*line, parser)) == -1)
		return (-1);
	if (!(eparser->event.launch_conditions =
			(t_condition*)ft_memalloc(sizeof(t_condition)
			* eparser->nb_conditions)))
		return (ft_perror("Could not malloc conditions"));
	while (eparser->condition_count < eparser->nb_conditions)
	{
		if (parse_condition(env, parser, line, eparser))
			return (-1);
		eparser->condition_count++;
	}
	return (0);
}
