/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:23:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/28 15:50:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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
	t_sector	current;

	i = 0;
	while (i < num)
	{
		current = env->sectors[i];
		if (sector_eq(sector, env->sectors[i]))
			return (ft_printf("Sectors %d and %d are identical\n", sector.num, i));
		i++;
	}
	return (0);
}

int		count_numbers(char *line)
{
	int i;

	i = 0;
	while (*line && *line != ')')
	{
		while (*line && (*line < '0' || *line > '9') && *line != '\t')
			line++;
		if (*line && *line <= '9' && *line >= '0')
		{
			i++;
			while (*line && *line <= '9' && *line >= '0')
				line++;
		}
	}
	return (i);
}
