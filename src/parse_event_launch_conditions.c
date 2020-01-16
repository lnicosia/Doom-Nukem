/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_launch_conditions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 15:04:37 by lnicosia         ###   ########.fr       */
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

int		parse_condition2(int count, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	int		target_type;

	(void)count;
	(void)eparser;
	target_type = -1;
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event condition type", "a space", **line,
		parser));
		if (valid_number(*line, parser))
		return (invalid_char("before condition value", "a digit", **line,
		parser));
		target_type = ft_atof(*line);
		if (target_type < 0 || target_type >= MAX_TARGET_TYPES)
			return (custom_error_with_line("Invalid condition target", parser));
	return (0);
}

int		parse_condition(int count, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (**line != '{')
		return (invalid_char("before event condition", "'{'", **line, parser));
	(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before condition type", "a digit", **line,
		parser));
		eparser->event.launch_conditions[count].type = ft_atoi(*line);
	if (eparser->event.launch_conditions[count].type < 0
		|| eparser->event.launch_conditions[count].type >= MAX_CONDITION_TYPES)
		return (custom_error_with_line("Invalid condition type", parser));
	*line = skip_number(*line);
	if (**line == '}')
		return (missing_data("event condition value", parser));
	if (**line != ' ')
		return (invalid_char("after event condition type", "a space", **line,
		parser));
		if (valid_number(*line, parser))
		return (invalid_char("before condition value", "a digit", **line,
		parser));
		eparser->event.launch_conditions[count].value = ft_atof(*line);
	if (parse_condition2(count, parser, line, eparser))
		return (-1);
	return (0);
}

int		parse_event_launch_conditions(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	int	count;
	int	i;

	(void)env;
	(*line)++;
	if (!**line)
		return (missing_data("event conditions", parser));
	if (**line != '[')
		return (invalid_char("before event conditions", "'['", **line, parser));
	if ((count = count_conditions(*line, parser)) == -1)
		return (-1);
	if (!(eparser->event.launch_conditions =
			(t_condition*)ft_memalloc(sizeof(t_condition) * count)))
		return (ft_perror("Could not malloc conditions"));
	i = 0;
	while (i < count)
	{
		if (parse_condition(count, parser, line, eparser))
			return (-1);
		i++;
	}
	return (0);
}
