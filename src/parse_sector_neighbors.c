/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector_neighbors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:16:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:16:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "parser.h"

int		parse_current_neighbor(t_env *env, char **line, t_map_parser *parser,
int i)
{
	env->sectors[parser->sectors_count].neighbors[i] = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].neighbors[i] < -1 || env->
			sectors[parser->sectors_count].neighbors[i] >= env->nb_sectors)
		return (custom_error(
			"[Line %d] Neighbor \'%d\' in sector %d does not exist\n",
			parser->line_count,
			env->sectors[parser->sectors_count].neighbors[i],
			parser->sectors_count));
	if (env->sectors[parser->sectors_count].neighbors[i] == parser->
		sectors_count)
		return (sector_error("can not contain a portal to itself",
		parser->sectors_count, parser));
		*line = skip_number(*line);
	*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_neighbors2(char **line, t_map_parser *parser)
{
	(*line)++;
	if (!**line)
		return (missing_data("portals, textures and light", parser));
	if (**line != ' ')
		return (invalid_char("after neighbors data", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_neighbors(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("neighbors, portals, textures and light", parser));
	if (**line != '(')
		return (invalid_char("before sector neighbors", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_neighbors_count = count_neighbors(*line, parser)) == -1)
		return (custom_error("Error while counting neighbors\n"));
	if (parser->sector_neighbors_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more neighbors",
			parser->sectors_count, parser));
		if (parser->sector_neighbors_count > parser->sector_vertices_count)
		return (sector_error("has too much neighbors",
			parser->sectors_count, parser));
		i = 0;
	while (i < parser->sector_neighbors_count)
	{
		if (parse_current_neighbor(env, line, parser, i))
			return (-1);
		i++;
	}
	return (parse_sector_neighbors2(line, parser));
}
