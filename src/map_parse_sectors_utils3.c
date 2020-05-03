/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors_utils3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:14:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:14:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map_parser.h"

/*
** Counts the number of portals in bewteen two parenthesis
*/

int		count_portals(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector portals", parser));
		if (valid_number(line, parser))
			return (invalid_char("in sector portals", "a digit, a ')'"
				"or space(s)", *line, parser));
			line = skip_number(line);
		line = skip_spaces(line);
		i++;
	}
	return (i);
}

/*
**	Counts the numbers of sprites in between two parenthesis
*/

int		count_textures(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector textures", parser));
		if (valid_texture(line, parser))
			return (-1);
		while (*line != ']')
			line++;
		line++;
		i++;
	}
	return (i);
}

/*
**	Counts the numbers of sprites in between one wall
*/

int		count_wall_sprites(char *line, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (*line != '}')
	{
		if (!*line)
			return (missing_data("'}' after sector sprites", parser));
		if (valid_sprite(line, parser))
			return (-1);
		while (*line != ']')
			line++;
		line++;
		i++;
	}
	if (i > 5)
		return (sector_error("wall can't exceed 30 sprites",
		parser->sectors_count, parser));
		return (i);
}

int		count_floor_sprites(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector sprites", parser));
		if (valid_sprite(line, parser))
			return (-1);
		while (*line != ']')
			line++;
		line++;
		i++;
	}
	if (i > 5)
		return (sector_error("can't exceed 5 floor or ceiling sprites",
		parser->sectors_count, parser));
		return (i);
}

/*
**	Prints an error message with sector and line number and your message
*/

int		sector_error(const char *message, int sector, t_map_parser *parser)
{
	ft_dprintf(STDERR_FILENO, "[Line %d] ", parser->line_count);
	ft_dprintf(STDERR_FILENO, "Sector %d %s\n", sector, message);
	return (-1);
}
