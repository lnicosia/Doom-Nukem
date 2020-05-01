/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:46:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:09:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		parse_event_trigger(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("event trigger", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for trigger_index\n"));
	eparser->trigger_index = ft_atoi(*line);
	if (eparser->trigger_index < 0 || eparser->trigger_index
		> MAX_TRIGGER_TYPES)
		return (custom_error_with_line("Invalid trigger type", parser));
	*line = skip_number(*line);
	init_events_parser_var(eparser);
	if (eparser->trigger_parsers[eparser->trigger_index](env, parser, line,
		eparser))
		return (-1);
	eparser->trigger_sector = eparser->current_sector;
	eparser->trigger_wall = eparser->current_wall;
	eparser->trigger_sprite = eparser->current_sprite;
	eparser->trigger_enemy = eparser->current_enemy;
	eparser->trigger_object = eparser->current_object;
	if (!**line)
		return (missing_data("closing ']' brace after event trigger", parser));
	if (**line != ']')
		return (invalid_char("after trigger declaration", "']'",
		**line, parser));
		return (0);
}

int		parse_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	ft_bzero(eparser, sizeof(*eparser));
	init_events_parser(eparser);
	if (parse_event_trigger(env, parser, line, eparser))
		return (-1);
	if (parse_event_target(env, parser, line, eparser))
		return (-1);
	if (parse_event_type(env, parser, line, eparser))
		return (-1);
	if (parse_event_launch_conditions(env, parser, line, eparser))
		return (-1);
	if (parse_event_exec_conditions(env, parser, line, eparser))
		return (-1);
	if (parse_event_various_data(env, parser, line, eparser))
		return (-1);
	eparser->event.check_func = eparser->checkers[eparser->target_index];
	eparser->event.update_func = eparser->updaters[eparser->target_index];
	if (eparser->new_events[eparser->trigger_index](env, parser, line, eparser))
		return (-1);
	return (0);
}

int		parse_current_event_line(t_env *env, t_map_parser *parser,
t_events_parser *eparser)
{
	char	*line;

	line = parser->line;
	parser->line_count++;
	if (*parser->line == '[')
	{
		if (parse_event(env, parser, &line, eparser))
			return (-1);
	}
	else if (ft_strlen(parser->line) == 5 && ft_strequ(parser->line, "Links"))
	{
		if (parse_events_links(env, parser))
			return (-1);
		ft_strdel(&parser->line);
		return (1);
	}
	else if (!*(parser->line))
	{
		ft_strdel(&parser->line);
		return (1);
	}
	else if (*parser->line != '#')
		return (invalid_char("at event", "[", *parser->line, parser));
	ft_strdel(&parser->line);
	return (0);
}

int		parse_events(t_env *env, t_map_parser *parser)
{
	t_events_parser	eparser;
	int				ret;

	ft_bzero(&eparser, sizeof(eparser));
	init_events_parser(&eparser);
	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		ret = parse_current_event_line(env, parser, &eparser);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			break ;
	}
	return (0);
}
