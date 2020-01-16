/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_event_various_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:52:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 17:00:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		parse_event_various_data(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser)
{
	(void)env;
	(void)eparser;
	(*line)++;
	if (!**line)
		return (missing_data("event various data", parser));
	if (**line != '[')
		return (invalid_char("before event various data", "'['",
		**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("event delay and maximum uses", parser));
	if (**line != '[')
		return (invalid_char("before event various data", "'['",
		**line, parser));
	return (0);
}
