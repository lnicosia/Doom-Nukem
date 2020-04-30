/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_exec_conditions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:00:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "events_conditions.h"

int		parse_exec_condition3(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	eparser->condition_object = eparser->current_object;
	eparser->event.exec_conditions[eparser->condition_count].target_index =
	eparser->condition_index;
	eparser->event.exec_conditions[eparser->condition_count].target =
	set_condition_target(env, eparser);
	eparser->event.exec_conditions[eparser->condition_count].target_type =
	eparser->target_types[eparser->condition_index];
	eparser->event.exec_conditions[eparser->condition_count].sector =
	eparser->condition_sector;
	eparser->event.exec_conditions[eparser->condition_count].wall =
	eparser->condition_wall;
	eparser->event.exec_conditions[eparser->condition_count].sprite =
	eparser->condition_sprite;
	eparser->event.exec_conditions[eparser->condition_count].enemy =
	eparser->condition_enemy;
	eparser->event.exec_conditions[eparser->condition_count].weapon =
	eparser->condition_weapon;
	eparser->event.exec_conditions[eparser->condition_count].vertex =
	eparser->condition_vertex;
	eparser->event.exec_conditions[eparser->condition_count].object =
	eparser->condition_object;
	if (**line != '}')
		return (invalid_char("after exec condition declarartion", "'}'",
		**line, parser));
		return (0);
}

int		parse_exec_condition2(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event exec condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event exec condition target", "a space",
		**line, parser));
		(*line)++;
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for exec condition target\n\n"));
	eparser->condition_index = ft_atof(*line);
	if (eparser->condition_index < 0
			|| eparser->condition_index >= MAX_REAL_TARGET_TYPES)
		return (custom_error_with_line("Invalid condition target", parser));
	*line = skip_number(*line);
	init_events_parser_var(eparser);
	if (eparser->target_parsers[eparser->condition_index](env, parser,
		line, eparser))
		return (-1);
	eparser->condition_sector = eparser->current_sector;
	eparser->condition_wall = eparser->current_wall;
	eparser->condition_vertex = eparser->current_vertex;
	eparser->condition_sprite = eparser->current_sprite;
	eparser->condition_enemy = eparser->current_enemy;
	eparser->condition_weapon = eparser->current_weapon;
	return (parse_exec_condition3(env, parser, line, eparser));
}

int		parse_exec_condition(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (**line != '{')
		return (invalid_char("before event exec condition", "'{'",
		**line, parser));
		(*line)++;
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for exec condition type\n"));
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
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for exec condition value\n"));
	eparser->event.exec_conditions[eparser->condition_count].value =
	ft_atof(*line);
	return (parse_exec_condition2(env, parser, line, eparser));
}

int		parse_event_exec_conditions2(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	while (eparser->condition_count < eparser->nb_conditions)
	{
		if (parse_exec_condition(env, parser, line, eparser))
			return (-1);
		eparser->condition_count++;
	}
	(*line)++;
	if (**line != ']')
		return (invalid_char("after event exec conditions", "']'",
		**line, parser));
		return (0);
}

int		parse_event_exec_conditions(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	int	i;

	(*line)++;
	if (!**line)
		return (missing_data("event exec conditions", parser));
	if (**line != '[')
		return (invalid_char("before event exec conditions", "'['",
		**line, parser));
		if ((eparser->nb_conditions = count_conditions(*line, parser)) == -1)
		return (-1);
	eparser->event.nb_exec_conditions = eparser->nb_conditions;
	if (!(eparser->event.exec_conditions =
			(t_condition*)ft_memalloc(sizeof(t_condition)
			* eparser->nb_conditions)))
		return (ft_perror("Could not malloc exec conditions"));
	i = 0;
	while (i < eparser->nb_conditions)
	{
		init_condition(&eparser->event.exec_conditions[i]);
		i++;
	}
	return (parse_event_exec_conditions2(env, parser, line, eparser));
}
