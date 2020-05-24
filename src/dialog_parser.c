/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:35:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:03:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

int		dialog_parser2(size_t len, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!(*line)[len])
		return (missing_data("end of the event", parser));
	if ((*line)[len] != ')')
		return (invalid_char("after dialog text or text is too long", "')'",
		**line, parser));
		if (!(eparser->current_str = ft_strsub(*line, 0, len)))
		return (-1);
	if (ft_strchr(eparser->current_str, '\n'))
		return (invalid_char("in dialog text", "no special characters",
		**line, parser));
		(*line) += len + 1;
	return (0);
}

int		dialog_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	size_t		len;

	(void)env;
	if (!**line || **line == ']')
		return (missing_data("dialog data", parser));
	if (**line != ' ')
		return (invalid_char("before dialog text", "a space", **line, parser));
	(*line)++;
	if (!**line || **line == ' ')
		return (missing_data("dialog text", parser));
	if (**line != '(')
		return (invalid_char("before dialog text", "a space", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("dialog data", parser));
	len = 0;
	while ((*line)[len] && (*line)[len] != ')' && len < 1024)
		len++;
	return (dialog_parser2(len, parser, line, eparser));
}
