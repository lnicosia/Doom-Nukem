/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/05/24 16:15:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

void	set_sectors_xmax(t_env *env)
{
	int i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].x_max < env->vertices[env->sectors[i].vertices[j]].x)
				env->sectors[i].x_max = env->vertices[env->sectors[i].vertices[j]].x;
			j++;
		}
		i++;
	}
}
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

int		parse_player(t_env *env, char *line, t_map_parser *parser)
{
	line = skip_spaces(line);
	env->player.pos.y = ft_atof(line);
	line = skip_number(line);
	env->player.pos.x = ft_atof(line);
	line = skip_number(line);
	env->player.angle = ft_atof(line) * M_PI / 180.0;
	env->player.angle_z = 0;
	line = skip_number(line);
	env->player.sector = ft_atoi(line);
	if (env->player.sector < 0 || env->player.sector >= env->nb_sectors)
		return (ft_printf("Invalid player sector (line %d)\n", parser->line_count));
	line = skip_number(line);
	if (*line != '\0')
		return (ft_printf("Too much data at player declaration (line %d)\n", parser->line_count));
	return (0);
}

int		count_vertices(char *line)
{
	int i;

	i = 0;
	while (*line && *line != '\t')
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

int		count_neighbors(char *line)
{
	int	i;

	i = 0;
	while (*line != '\n' && *line != '\0')
	{
		while (*line && (*line < '0' || *line > '9'))
			line++;
		if (*line && (*line <= '9' && *line >= '0'))
		{
			i++;
			while (*line && (*line <= '9' && *line >= '0'))
				line++;
		}
	}
	return (i);
}

int		parse_sector(t_env *env, char *line, t_map_parser *parser)
{
	short	i;
	short	vertices_count;
	short	neighbors_count;

	env->sectors[parser->vertices_count].num = parser->vertices_count;
	line = skip_spaces(line);
	env->sectors[parser->vertices_count].floor = ft_atof(line);
	env->sectors[parser->vertices_count].floor_min = ft_atof(line);
	env->sectors[parser->vertices_count].floor_max = ft_atof(line);
	line = skip_number(line);
	env->sectors[parser->vertices_count].floor_slope = ft_atof(line);
	if (env->sectors[parser->vertices_count].floor_slope > 45 || env->sectors[parser->vertices_count].floor_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", parser->line_count));
	env->sectors[parser->vertices_count].floor_slope = tan(env->sectors[parser->vertices_count].floor_slope * M_PI / 180.0);
	line = skip_number(line);
	env->sectors[parser->vertices_count].ceiling = ft_atof(line);
	env->sectors[parser->vertices_count].ceiling_max = ft_atof(line);
	env->sectors[parser->vertices_count].ceiling_min = ft_atof(line);
	line = skip_number(line);
	env->sectors[parser->vertices_count].ceiling_slope = ft_atof(line);
	if (env->sectors[parser->vertices_count].ceiling_slope > 45 || env->sectors[parser->vertices_count].ceiling_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", parser->line_count));
	env->sectors[parser->vertices_count].ceiling_slope = tan(env->sectors[parser->vertices_count].ceiling_slope * M_PI / 180.0);
	if (env->sectors[parser->vertices_count].ceiling - env->sectors[parser->vertices_count].floor <= 0)
		return (ft_printf("Sector %d must have a positive ceiling-floor difference (line %d)\n", parser->vertices_count, parser->line_count));
	line = skip_number(line);
	vertices_count = count_vertices(line);
	if (vertices_count < 3)
		return (ft_printf("Sector %d must contain at least 3 vertices (line %d)\n", parser->vertices_count, parser->line_count));
	env->sectors[parser->vertices_count].nb_vertices = vertices_count;
	if (!(env->sectors[parser->vertices_count].vertices = (short*)malloc(sizeof(short) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[parser->vertices_count].vertices_textures = (short*)malloc(sizeof(short) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[parser->vertices_count].ceilings = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector ceilings!\n", env));
	if (!(env->sectors[parser->vertices_count].floors = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector floors!\n", env));
	if (!(env->sectors[parser->vertices_count].clipped_ceilings1 = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings1!\n", env));
	if (!(env->sectors[parser->vertices_count].clipped_floors1 = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_floors1!\n", env));
	if (!(env->sectors[parser->vertices_count].clipped_ceilings2 = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings2!\n", env));
	if (!(env->sectors[parser->vertices_count].clipped_floors2 = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector clipped_floors2!\n", env));
	if (!(env->sectors[parser->vertices_count].wall_width = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector wall_size!\n", env));
	i = 0;
	while (i < vertices_count)
	{
		line = skip_spaces(line);
		env->sectors[parser->vertices_count].vertices[i] = ft_atoi(line);
		if (env->sectors[parser->vertices_count].vertices[i] < 0 || env->sectors[parser->vertices_count].vertices[i] >= env->nb_vertices)
			return (ft_printf("Vertex \'%d\' in sector %d does not exist (line %d)\n", env->sectors[parser->vertices_count].vertices[i], parser->vertices_count, parser->line_count));
		line = skip_number(line);
		i++;
	}
	env->sectors[parser->vertices_count].vertices[vertices_count] = env->sectors[parser->vertices_count].vertices[0];
	if (check_vertices_uniqueness(env->sectors[parser->vertices_count]))
		return (ft_printf("Sector %d has duplicate vertices (line %d)\n", parser->vertices_count, parser->line_count));
	if (check_sector_duplicate(env, env->sectors[parser->vertices_count], parser->vertices_count))
		return (ft_printf("Sector %d already exists (line %d)\n", parser->vertices_count, parser->line_count));
	line = skip_spaces(line);
	neighbors_count = count_neighbors(line);
	if (neighbors_count < vertices_count)
		return (ft_printf("Missing neighbors in sector %d (line %d)\n", parser->vertices_count, parser->line_count));
	if (neighbors_count > vertices_count)
		return (ft_printf("Too much neighbors in sector %d (line %d)\n", parser->vertices_count, parser->line_count));
	i = 0;
	if (!(env->sectors[parser->vertices_count].neighbors = (short*)malloc(sizeof(short) * (neighbors_count))))
		return (ft_printf("Could not malloc sector neighbors!\n", env));
	while (i < neighbors_count)
	{
		line = skip_spaces(line);
		env->sectors[parser->vertices_count].neighbors[i] = ft_atoi(line);
		if (env->sectors[parser->vertices_count].neighbors[i] < -1 || env->sectors[parser->vertices_count].neighbors[i] >= env->nb_sectors)
			return (ft_printf("Neighbor \'%d\' in sector %d does not exist (line %d)\n", env->sectors[parser->vertices_count].neighbors[i], parser->vertices_count, parser->line_count));
		if (env->sectors[parser->vertices_count].neighbors[i] == parser->vertices_count)
			return (ft_printf("Sector %d can not contain a portal to itself\n", parser->vertices_count, parser->line_count));
		line = skip_number(line);
		i++;
	}
	return (0);
}

int		init_sectors(t_env *env, t_map_parser *parser, char *line)
{
	int	nb_sectors;
	int	i;

	(void)parser;
	i = 0;
	line = skip_spaces(line);
	if (!*line)
	{
		ft_printf("Please declare how many sectors there are\n");
		return (-1);
	}
	nb_sectors = atoi(line);
	if (nb_sectors < 1)
	{
		ft_printf("You need to declare at least one sector.\n");
		return (-1);
	}
	if (!(env->sectors = (t_sector *)malloc(sizeof(t_sector) * (nb_sectors))))
	{
		ft_printf("Could not malloc sectors!\n", env);
		return (-1);
	}
	env->screen_sectors_size = ft_min(nb_sectors, env->w);
	if (!(env->xmin = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
	{
		ft_printf("Could not malloc xmins!\n", env);
		return (-1);
	}
	if (!(env->xmax = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
	{
		ft_printf("Could not malloc xmaxs!\n", env);
		return (-1);
	}
	if (!(env->screen_sectors = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
	{
		ft_printf("Could not malloc screen sectors!\n", env);
		return (-1);
	}
	if (!(env->rendered_sectors = (short*)malloc(sizeof(short) * (env->screen_sectors_size))))
	{
		ft_printf("Could not malloc rendered sectors!\n", env);
		return (-1);
	}
	i = 0;
	while (i < nb_sectors)
	{
		env->sectors[i].vertices = NULL;
		env->sectors[i].ceilings = NULL;
		env->sectors[i].floors = NULL;
		env->sectors[i].clipped_ceilings1 = NULL;
		env->sectors[i].clipped_floors1 = NULL;
		env->sectors[i].clipped_ceilings2 = NULL;
		env->sectors[i].clipped_floors2 = NULL;
		env->sectors[i].neighbors = NULL;
		env->sectors[i].x_max = -2147483648;
		env->sectors[i].wall_width = NULL;
		env->sectors[i].vertices_textures = NULL;
		i++;
	}
	return (nb_sectors);
}

int		parse_map(char *file, t_env *env)
{
	t_map_parser	parser;
	char			*line;

	env->nb_sectors = 0;
	env->nb_vertices = 0;
	parser.sectors_count = 0;
	parser.vertices_count = 0;
	env->player.sector = -1;
	parser.line_count = 1;
	line = NULL;
	ft_printf("{red}");
	if ((parser.fd = open(file, O_RDONLY)) < 0)
		return (ft_printf("Could not open %s\n", file));
	if (parse_vertices(env, &parser))
		return (ft_printf("Error while parsing vertices\n"));
	if (parse_sectors(env, &parser))
		return (ft_printf("Error while parsing vertices\n"));
	while ((parser.ret = get_next_line(parser.fd, &line)))
	{
		if (parser.ret == -1)
			return (ft_printf("Invalid file!\n", env));
		if (line[0] == 'p')
		{
			if (parser.sectors_count == 0 || env->nb_sectors == 0)
				return (ft_printf("You must declare sectors before you declare the player\n"));
			if (parser.sectors_count < env->nb_sectors)
				return (ft_printf("You gave less sectors than you declared.\n"));
			if (parse_player(env, line, &parser))
				return (ft_printf("Error while parsing player!\n"));
		}
		/*else if (line[0] == 'v')
		{
			if (env->nb_vertices <= 0)
				return (ft_printf("Please say how many vertices there are before declaring them\n(line starting with \'V\' followed by the parser->vertices_countber of vertices)\n"));
			if (parser.vertices_count >= env->nb_vertices)
				return (ft_printf("You gave more vertices than you declared\n"));
			if (parse_vertex(env, line, &parser))
				return (ft_printf("Error while parsing vertices!\n"));
			parser.vertices_count++;
		}*/
		else if (line[0] == 's')
		{
			if (env->nb_sectors <= 0)
				return (ft_printf("Please declare how many sectors there are.\n"));
			if (parser.sectors_count >= env->nb_sectors)
				return (ft_printf("You gave more sectors than you declared.\n"));
			if (parse_sector(env, line, &parser))
				return (ft_printf("Error while parsing sectors!\n"));
			parser.sectors_count++;
		}
	/*	else if (line[0] == 'V')
		{
			if (env->nb_vertices != 0)
				return (ft_printf("Redeclaration of vertices parser->vertices_countbers (line %d)\n", parser.line_count));
			if ((env->nb_vertices = init_vertices(env, &parser, line)) == -1)
				return (ft_printf("Could not init vertices!\n"));
		}*/
		else if (line[0] == 'S')
		{
			if (env->nb_sectors != 0)
				return (ft_printf("Redeclaration of sectors parser->vertices_countbers (line %d)\n", parser.line_count));
			if (parser.vertices_count == 0 || env->nb_vertices == 0)
				return (ft_printf("You must declare vertices before you declare sectors\n"));
			if (parser.vertices_count < env->nb_vertices)
				return (ft_printf("You gave less vertices than you declared.\n"));
			if ((env->nb_sectors = init_sectors(env, &parser, line)) == -1)
				return (ft_printf("Could not init sectors!\n"));
		}
		parser.line_count++;
		ft_strdel(&line);
	}
	if (env->player.sector == -1)
		return (ft_printf("You need to give player data\n"));
	ft_strdel(&line);
	set_sectors_xmax(env);
	if (close(parser.fd))
		return (ft_printf("Could not close the file\n"));
	return (0);
}
