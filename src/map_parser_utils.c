/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/24 15:28:05 by sipatry          ###   ########.fr       */
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
** Checks if a string is a valid number
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
** Checks if a string is a valid integer
*/

int		valid_int(char *line, t_map_parser *parser)
{
	(void)parser;
	int	nb_digits;

	nb_digits = 0;
	while(*line >= '0' && *line <= '9')
	{
		if (nb_digits > 8)
			return (ft_printf("Too many digits\n"));
		nb_digits++;
		line++;
	}
	return (0);
}

/*
** Checks if a string is a valid double
*/

int		valid_double(char *line, t_map_parser *parser)
{
	int	point;
	int	pre_point;
	int	after_point;

	point = 0;
	pre_point = 0;
	after_point = 0;
	(void)parser;
	while((*line >= '0' && *line <= '9')
	|| (*line == '.'))
	{
		if (*line == '.' && !point)
			point = 1;
		else if (*line == '.' && point)
			return (ft_printf("excessive number of points\n"));
		if (pre_point > 8 || after_point > 5)
			return (ft_printf("Too many digits\n"));
		if (!point)
			pre_point++;
		if (point)
			after_point++;
		line++;
	}
	return (0);
}

/*
** Checks if a string is a valid hexa number
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
