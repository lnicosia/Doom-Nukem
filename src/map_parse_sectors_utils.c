/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:23:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:14:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_sprite(char *line, t_map_parser *parser, int *open, int *count)
{
	if (!*line)
		return (missing_data("')' after sector sprites", parser));
	if (*line == '{')
	{
		if (*open)
			return (sector_error("Unbalanced \'{\' and \'}\'",
			parser->sectors_count, parser));
			(*open)++;
		(*count)++;
		if (*count > parser->sector_vertices_count)
			return (sector_error("can't exceed %d sprites",
			parser->sector_vertices_count, parser));
	}
	if (*line == '}')
	{
		if (!*open)
			return (sector_error("Unbalanced \'{\' and \'}\'",
			parser->sectors_count, parser));
			(*open)--;
	}
	return (0);
}

/*
**	Counts the numbers of sprites in between two parenthesis
*/

int		count_sprites(char *line, t_map_parser *parser)
{
	int	open;
	int	count;

	open = 0;
	count = 0;
	while (*line != ')')
	{
		if (parse_sprite(line, parser, &open, &count))
			return (-1);
		line++;
	}
	return (count);
}
