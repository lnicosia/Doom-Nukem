/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:23:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 18:24:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

/*
 **	Check if a sector has duplicate vertices
 */

int		check_vertices_uniqueness(t_sector sector)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < sector.nb_vertices)
	{
		nb = sector.vertices[i];
		j = i + 1;
		while (j < sector.nb_vertices)
		{
			if (nb == sector.vertices[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
 **	Check if 2 sectors have exactly the same vertices
 */

int		sector_eq(t_sector s1, t_sector s2)
{
	int	i;

	if (s1.nb_vertices != s2.nb_vertices)
		return (0);
	i = 0;
	while (i < s1.nb_vertices)
	{
		if (s1.vertices[i] != s2.vertices[i])
			return (0);
		i++;
	}
	return (1);
}

/*
 **	Check if the current sector already exists
 */

int		check_sector_duplicate(t_env *env, t_sector sector, int num)
{
	int			i;

	i = 0;
	while (i < num)
	{
		if (sector_eq(sector, env->sectors[i]))
			return (ft_dprintf(STDERR_FILENO,
						"Sectors %d and %d are identical\n", sector.num, i));
		i++;
	}
	return (0);
}

/*
 **	Counts the numbers of vertices in between two parenthesis
 */

int		count_vertices(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector vertices", parser));
		if (valid_number(line, parser))
			return (invalid_char("in sector vertices", "a digit, a ')'"
						"or space(s)", *line, parser));
		line = skip_number(line);
		line = skip_spaces(line);
		i++;
	}
	return (i);
}

/*
 **	Counts the numbers of neighbors in between two parenthesis
 */

int		count_neighbors(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector neighbors", parser));
		if (valid_number(line, parser))
			return (invalid_char("in sector neighbors", "a digit, a ')'"
						"or space(s)", *line, parser));
		line = skip_number(line);
		line = skip_spaces(line);
		i++;
	}
	return (i);
}

//	Old version

/*
 **	Counts the numbers of textures in between two parenthesis
 **	OLD VERSION
 */

/*int		count_textures(char *line, t_map_parser *parser)
{
	int i;

	i = 0;
	while (*line != ')')
	{
		if (!*line)
			return (missing_data("')' after sector textures", parser));
		if (valid_number(line, parser))
			return (invalid_char("in sector textures", "a digit, a ')'"
						"or space(s)", *line, parser));
		line = skip_number(line);
		line = skip_spaces(line);
		i++;
	}
	return (i);
}*/

//	New version

/*
 **	Checks if a texture is valid
 */

int		valid_texture(char *line, t_map_parser *parser)
{
	if (*line != '[')
		return (invalid_char("in sector texture", "'['", *line, parser));
	line++;
	if (!*line)
		return (missing_data("texture number", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture number", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("texture pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture number", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("textures pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture x pos", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("texture y pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture x pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture y pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture y pos", "a digit",
					*line, parser));
	line = skip_number(line);

	if (!*line)
		return (missing_data("texture scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture y pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture x scale", "a digit",
					*line, parser));
	line = skip_number(line);

	if (!*line)
		return (missing_data("texture y scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture x scale", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture y scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture y scale", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("']' after texture y scale", parser));
	if (*line != ']')
		return (invalid_char("after texture y scale", "']'",
					*line, parser));
	return (0);
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
 **	Checks if a sprite is valid
 */

int		valid_sprite(char *line, t_map_parser *parser)
{
	if (*line != '[')
		return (invalid_char("in sector sprites", "'['", *line, parser));
	line++;
	if (!*line)
		return (missing_data("sprite number", parser));
	if (valid_number(line, parser))
		return (invalid_char("before sprite number", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("sprite pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite number", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprites pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before sprite x pos", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("sprite y pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite x pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite y pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before sprite y pos", "a digit",
					*line, parser));
	line = skip_number(line);

	if (!*line)
		return (missing_data("sprite scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite y pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before sprite x scale", "a digit",
					*line, parser));
	line = skip_number(line);

	if (!*line)
		return (missing_data("sprite y scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite x scale", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite y scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before sprite y scale", "a digit",
					*line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("']' after sprite y scale", parser));
	if (*line != ']')
		return (invalid_char("after sprite y scale", "']'",
					*line, parser));
	return (0);
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
	return (i);
}

//	NEW VERSION

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
		if (!*line)
			return (missing_data("')' after sector sprites", parser));
		if (*line == '{')
		{
			if (open)
				return (sector_error("Unbalanced \'{\' and \'}\'",
				parser->sectors_count, parser));
			open++;
			count++;
		}
		if (*line == '}')
		{
			if (!open)
				return (sector_error("Unbalanced \'{\' and \'}\'",
				parser->sectors_count, parser));
			open--;
		}
		line++;
	}
	return (count);
}

//	OLD VERSION

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
