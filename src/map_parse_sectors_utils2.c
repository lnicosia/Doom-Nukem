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