/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_protection_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:09:34 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/22 11:29:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int		invalid_char(const char *location, const char *expected,
		char c, t_map_parser *parser)
{
	ft_dprintf(STDERR_FILENO, "[Line %d] ", parser->line_count);
	ft_dprintf(STDERR_FILENO, "Invalid character %s: ", location);
	ft_dprintf(STDERR_FILENO, "'%c' ", c);
	ft_dprintf(STDERR_FILENO, "(expected %s)\n", expected);
	return (-1);
}

int		extra_data(const char *location, t_map_parser *parser)
{
	ft_dprintf(STDERR_FILENO, "[Line %d] ", parser->line_count);
	ft_dprintf(STDERR_FILENO, "Extra data after %s\n", location);
	return (-1);
}

int		missing_data(const char *missing_data, t_map_parser *parser)
{
	ft_dprintf(STDERR_FILENO, "[Line %d] ", parser->line_count);
	ft_dprintf(STDERR_FILENO, "Missing %s\n", missing_data);
	return (-1);
}

int		custom_error_with_line(const char *message, t_map_parser *parser)
{
	ft_dprintf(STDERR_FILENO, "[Line %d] %s\n", parser->line_count, message);
	return (-1);
}
