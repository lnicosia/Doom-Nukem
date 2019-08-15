/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/15 15:06:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "bmp_parser.h"
#include "env.h"

char	*skip_number(char *line)
{
	if (*line && *line == '-')
		line++;
	while (*line && (*line <= '9' && *line >= '0'))
		line++;
	if (*line && *line == '.')
	{
		line++;
		while (*line && (*line <= '9' && *line >= '0'))
			line++;
	}
	return (line);
}

char	*skip_spaces(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

/*
** Checks if a charcter is a valid number
*/

int		valid_number(char *line, t_map_parser *parser)
{
	(void)parser;
	if (!*line)
		return (MISSING_CHAR);
	if ((*line < '0' || *line > '9') && *line != '-')
		return (WRONG_CHAR);
	return (0);
}

/*
**
*/

int		end_of_section(char *line, char end_char, const char *log)
{
	(void)line;
	(void)end_char;
	(void)log;
	return (0);
}
