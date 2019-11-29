/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 19:18:45 by lnicosia         ###   ########.fr       */
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

char	*skip_hexa(char *line)
{
	while (*line && ((*line <= '9' && *line >= '0')
		|| (*line >= 'A' && *line <= 'F')
		|| (*line >= 'a' && *line <= 'f')))
		line++;
	return (line);
}

char	*skip_spaces(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

/*
** Checks if a character is a valid number
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
** Checks if a character is a valid hexa number
*/

int		valid_hexa(char *line, t_map_parser *parser)
{
	(void)parser;
	if (!*line)
		return (MISSING_CHAR);
	if (*line && ((*line <= '9' && *line >= '0')
		|| (*line >= 'A' && *line <= 'F')
		|| (*line >= 'a' && *line <= 'f')))
		return (0);
	return (WRONG_CHAR);
}
