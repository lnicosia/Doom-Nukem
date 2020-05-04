/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:12:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Checks if a string is a valid integer
*/

int		valid_int(char *line, t_map_parser *parser)
{
	int	nb_digits;
	int	neg;

	(void)parser;
	nb_digits = 0;
	neg = 0;
	while ((*line >= '0' && *line <= '9') || *line == '-')
	{
		if (*line == '-' && !nb_digits)
			neg = 1;
		else if (*line == '-' && nb_digits)
			break ;
		if (nb_digits > 9 + neg)
			return (ft_printf("Too many digits\n"));
		nb_digits++;
		line++;
	}
	return (0);
}

void	incr_counts(int *pre_point, int *after_point, int point)
{
	if (!point)
		(*pre_point)++;
	if (point)
		(*after_point)++;
}

/*
** Checks if a string is a valid double
*/

int		valid_double(char *line, t_map_parser *parser)
{
	int	point;
	int	pre_point;
	int	after_point;
	int	neg;

	point = 0;
	pre_point = 0;
	after_point = 0;
	neg = 0;
	(void)parser;
	while ((*line >= '0' && *line <= '9') || (*line == '.' || *line == '-'))
	{
		if (*line == '-' && !pre_point && !after_point)
			neg = 1;
		if (*line == '.' && !point)
			point = 1;
		else if (*line == '.' && point)
			return (ft_printf("excessive number of points\n"));
		if (pre_point > 8 + neg || after_point > 5)
			return (ft_printf("Too many digits\n"));
		incr_counts(&pre_point, &after_point, point);
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
