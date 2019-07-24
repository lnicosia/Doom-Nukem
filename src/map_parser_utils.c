/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 13:39:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "bmp_parser.h"
#include "utils.h"

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

int		valid_number(char *line, t_map_parser *parser)
{
	if (!*line)
		return (ft_printf("Missing data at line %d\n",
					parser->line_count));
	if ((*line < '0' || *line > '9') && *line != '-')
		return (ft_printf("Invalid character at line %d\n",
					parser->line_count));
	return (0);
}
