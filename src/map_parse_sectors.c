/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:14:16 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/28 13:51:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "utils.h"

int			parse_floor(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (ft_printf("Missing floor value (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].floor = ft_atof(*line);
	env->sectors[parser->sectors_count].floor_min = env->sectors[parser->sectors_count].floor;
	env->sectors[parser->sectors_count].floor_max = env->sectors[parser->sectors_count].floor;
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (!**line)
		return (ft_printf("Missing floor slope (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].floor_slope = ft_atof(*line);
	if (env->sectors[parser->sectors_count].floor_slope > 45 || env->sectors[parser->sectors_count].floor_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].floor_slope = tan(env->sectors[parser->sectors_count].floor_slope * M_PI / 180.0);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (!**line)
		return (ft_printf("Missing floor texture (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].floor_texture = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ']' && **(line + 1) != ' ')
		return (ft_printf("Invalid character after floor declaration at line %d\n", parser->line_count));
	*line += 2;
	return (0);
}

int			parse_ceiling(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (ft_printf("Invalid character before ceiling declaration at line %d\n", parser->line_count));
	(*line)++;
	if (!**line)
		return (ft_printf("Missing ceiling value (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].ceiling = ft_atof(*line);
	env->sectors[parser->sectors_count].ceiling_min = env->sectors[parser->sectors_count].ceiling;
	env->sectors[parser->sectors_count].ceiling_max = env->sectors[parser->sectors_count].ceiling;
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (!**line)
		return (ft_printf("Missing ceiling slope (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].ceiling_slope = ft_atof(*line);
	if (env->sectors[parser->sectors_count].ceiling_slope > 45 || env->sectors[parser->sectors_count].ceiling_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].ceiling_slope = tan(env->sectors[parser->sectors_count].ceiling_slope * M_PI / 180.0);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (!**line)
		return (ft_printf("Missing floor texture (line %d)\n", parser->line_count));
	env->sectors[parser->sectors_count].ceiling_texture = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ']' && **(line + 1) != ' ')
		return (ft_printf("Invalid character after ceiling declaration at line %d\n", parser->line_count));
	*line += 2;
	return (0);
}

static int	parse_sector(t_env *env, char *line, t_map_parser *parser)
{
	int	i;

	parser->sector_vertices_count = 0;
	parser->sector_neighbors_count = 0;
	env->sectors[parser->sectors_count].num = parser->sectors_count;
	if (parse_floor(env, &line, parser))
		return (ft_printf("Error while parsing floor\n"));
	if (parse_ceiling(env, &line, parser))
		return (ft_printf("Error while parsing ceiling\n"));
	if (env->sectors[parser->sectors_count].ceiling <= env->sectors[parser->sectors_count].floor)
		return (ft_printf("Sector %d ceiling must be higher than his floor (line %d)\n", parser->sectors_count, parser->line_count));
	line = skip_number(line);
	parser->sector_vertices_count = count_vertices(line);
	if (parser->sector_vertices_count < 3)
		return (ft_printf("Sector %d must contain at least 3 vertices (line %d)\n", parser->sectors_count, parser->line_count));
	env->sectors[parser->sectors_count].nb_vertices = parser->sector_vertices_count;
	if (!(env->sectors[parser->sectors_count].vertices = (short*)malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[parser->sectors_count].vertices_textures = (short*)malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[parser->sectors_count].ceilings = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector ceilings!\n", env));
	if (!(env->sectors[parser->sectors_count].floors = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector floors!\n", env));
	if (!(env->sectors[parser->sectors_count].clipped_ceilings1 = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings1!\n", env));
	if (!(env->sectors[parser->sectors_count].clipped_floors1 = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_floors1!\n", env));
	if (!(env->sectors[parser->sectors_count].clipped_ceilings2 = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings2!\n", env));
	if (!(env->sectors[parser->sectors_count].clipped_floors2 = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_floors2!\n", env));
	if (!(env->sectors[parser->sectors_count].wall_width = (double*)malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_printf("Could not malloc sector wall_size!\n", env));
	i = 0;
	while (i < parser->sector_vertices_count)
	{
		line = skip_spaces(line);
		env->sectors[parser->sectors_count].vertices[i] = ft_atoi(line);
		if (env->sectors[parser->sectors_count].vertices[i] < 0 || env->sectors[parser->sectors_count].vertices[i] >= env->nb_vertices)
			return (ft_printf("Vertex \'%d\' in sector %d does not exist (line %d)\n", env->sectors[parser->sectors_count].vertices[i], parser->sectors_count, parser->line_count));
		line = skip_number(line);
		i++;
	}
	env->sectors[parser->sectors_count].vertices[parser->sector_vertices_count] = env->sectors[parser->sectors_count].vertices[0];
	if (check_vertices_uniqueness(env->sectors[parser->sectors_count]))
		return (ft_printf("Sector %d has duplicate vertices (line %d)\n", parser->sectors_count, parser->line_count));
	if (check_sector_duplicate(env, env->sectors[parser->sectors_count], parser->sectors_count))
		return (ft_printf("Sector %d already exists (line %d)\n", parser->sectors_count, parser->line_count));
	line = skip_spaces(line);
	parser->sector_neighbors_count = count_neighbors(line);
	if (parser->sector_neighbors_count < parser->sector_vertices_count)
		return (ft_printf("Missing neighbors in sector %d (line %d)\n", parser->sectors_count, parser->line_count));
	if (parser->sector_neighbors_count > parser->sector_vertices_count)
		return (ft_printf("Too much neighbors in sector %d (line %d)\n", parser->sectors_count, parser->line_count));
	i = 0;
	if (!(env->sectors[parser->sectors_count].neighbors = (short*)malloc(sizeof(short) * (parser->sector_neighbors_count))))
		return (ft_printf("Could not malloc sector neighbors!\n", env));
	while (i < parser->sector_neighbors_count)
	{
		line = skip_spaces(line);
		env->sectors[parser->sectors_count].neighbors[i] = ft_atoi(line);
		if (env->sectors[parser->sectors_count].neighbors[i] < -1 || env->sectors[parser->sectors_count].neighbors[i] >= env->nb_sectors)
			return (ft_printf("Neighbor \'%d\' in sector %d does not exist (line %d)\n", env->sectors[parser->sectors_count].neighbors[i], parser->sectors_count, parser->line_count));
		if (env->sectors[parser->sectors_count].neighbors[i] == parser->sectors_count)
			return (ft_printf("Sector %d can not contain a portal to itself\n", parser->sectors_count, parser->line_count));
		line = skip_number(line);
		i++;
	}
	return (0);
}

int			parse_sectors(t_env *env, t_map_parser *parser)
{
	char	*line;

	while (parser->sectors_count < env->nb_sectors
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (line[0] == '[')
		{
			line++;
			if (parse_sector(env, line, parser))
				return (ft_printf("Error while parsing sector %d (line %d)\n",
							parser->sectors_count, parser->line_count));
		}
		else if (line[0] == '\0' && parser->sectors_count < env->nb_sectors)
			return (ft_printf("You must still declare %d sectors (line %d)\n",
						env->nb_sectors - parser->sectors_count,
						parser->line_count));
		else if (line[0] != '#')
			return (ft_printf("Invalid character before floor declaratino at line %d\n"
						, parser->line_count));
		ft_strdel(&line);
	}
	return (0);
}
