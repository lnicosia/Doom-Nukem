/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/05/13 15:57:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

/*
**	Chek if the current vertex already exists
*/

int		check_vertex_duplicate(t_env *env, t_vertex vertex, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (vertex.x == env->vertices[i].x && vertex.y == env->vertices[i].y)
			return (ft_printf("Vertices %d and %d are identical\n", vertex.num, i));
		i++;
	}
	return (0);
}

char	*skip_number(char *line)
{
	while (*line && ((*line <= '9' && *line >= '0') || *line == '.' || *line == '-'))
		line++;
	if (*line)
		line++;
	return (line);
}

char	*skip_spaces(char *line)
{
	while (*line && (*line > '9' || *line < '0') && *line != '-')
		line++;
	return (line);
}

int		parse_player(t_env *env, char *line, int line_count)
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
		return (ft_printf("Invalid player sector (line %d)\n", line_count));
	line = skip_number(line);
	if (*line != '\0')
		return (ft_printf("Too much data at player declaration (line %d)\n", line_count));
	return (0);
}

int		parse_vertex(t_env *env, char *line, int num, int line_count)
{
	env->vertices[num].num = num;
	line = skip_spaces(line);
	if (!*line)
		return (ft_printf("Wrong number of coordinates at vertex %d (line %d)\n", num, line_count));
	env->vertices[num].y = ft_atof(line);
	line = skip_number(line);
	if (!*line)
		return (ft_printf("Wrong number of coordinates at vertex %d (line %d)\n", num, line_count));
	env->vertices[num].x = ft_atof(line);
	line = skip_number(line);
	if (*line != '\0')
		return (ft_printf("Too much data at vertex %d (line %d)\n", num, line_count));
	if (check_vertex_duplicate(env, env->vertices[num], num))
		return (ft_printf("Vertex %d already exists (line %d)\n", num, line_count));
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

int		parse_sector(t_env *env, char *line, short num, int line_count)
{
	short	i;
	short	vertices_count;
	short	neighbors_count;

	env->sectors[num].num = num;
	line = skip_spaces(line);
	env->sectors[num].floor = ft_atof(line);
	env->sectors[num].floor_min = ft_atof(line);
	line = skip_number(line);
	env->sectors[num].floor_slope = ft_atof(line);
	if (env->sectors[num].floor_slope > 45 || env->sectors[num].floor_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", line_count));
	env->sectors[num].floor_slope = tan(env->sectors[num].floor_slope * M_PI / 180.0);
	line = skip_number(line);
	env->sectors[num].ceiling = ft_atof(line);
	env->sectors[num].ceiling_max = ft_atof(line);
	line = skip_number(line);
	env->sectors[num].ceiling_slope = ft_atof(line);
	if (env->sectors[num].ceiling_slope > 45 || env->sectors[num].ceiling_slope < -45)
		return (ft_printf("Slopes must be between -45 and 45 degrees (line %d)\n", line_count));
	env->sectors[num].ceiling_slope = tan(env->sectors[num].ceiling_slope * M_PI / 180.0);
	if (env->sectors[num].ceiling - env->sectors[num].floor <= 0)
		return (ft_printf("Sector %d must have a positive ceiling-floor difference (line %d)\n", num, line_count));
	line = skip_number(line);
	vertices_count = count_vertices(line);
	if (vertices_count < 3)
		return (ft_printf("Sector %d must contain at least 3 vertices (line %d)\n", num, line_count));
	env->sectors[num].nb_vertices = vertices_count;
	if (!(env->sectors[num].vertices = (short*)malloc(sizeof(short) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[num].ceilings = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector ceilings!\n", env));
	if (!(env->sectors[num].floors = (double*)malloc(sizeof(double) * (vertices_count + 1))))
		return (ft_printf("Could not malloc sector floors!\n", env));
	i = 0;
	while (i < vertices_count)
	{
		line = skip_spaces(line);
		env->sectors[num].vertices[i] = ft_atoi(line);
		if (env->sectors[num].vertices[i] < 0 || env->sectors[num].vertices[i] >= env->nb_vertices)
			return (ft_printf("Vertex \'%d\' in sector %d does not exist (line %d)\n", env->sectors[num].vertices[i], num, line_count));
		line = skip_number(line);
		i++;
	}
	env->sectors[num].vertices[vertices_count] = env->sectors[num].vertices[0];
	if (check_vertices_uniqueness(env->sectors[num]))
		return (ft_printf("Sector %d has duplicate vertices (line %d)\n", num, line_count));
	if (check_sector_duplicate(env, env->sectors[num], num))
		return (ft_printf("Sector %d already exists (line %d)\n", num, line_count));
	line = skip_spaces(line);
	neighbors_count = count_neighbors(line);
	if (neighbors_count < vertices_count)
		return (ft_printf("Missing neighbors in sector %d (line %d)\n", num, line_count));
	if (neighbors_count > vertices_count)
		return (ft_printf("Too much neighbors in sector %d (line %d)\n", num, line_count));
	i = 0;
	if (!(env->sectors[num].neighbors = (short*)malloc(sizeof(short) * (neighbors_count))))
		return (ft_printf("Could not malloc sector neighbors!\n", env));
	while (i < neighbors_count)
	{
		line = skip_spaces(line);
		env->sectors[num].neighbors[i] = ft_atoi(line);
		if (env->sectors[num].neighbors[i] < -1 || env->sectors[num].neighbors[i] >= env->nb_sectors)
			return (ft_printf("Neighbor \'%d\' in sector %d does not exist (line %d)\n", env->sectors[num].neighbors[i], num, line_count));
		if (env->sectors[num].neighbors[i] == num)
			return (ft_printf("Sector %d can not contain a portal to itself\n", num, line_count));
		line = skip_number(line);
		i++;
	}
	return (0);
}

int		init_vertices(t_env *env, char *line)
{
	int	nb_vertices;

	line = skip_spaces(line);
	if (!*line)
	{
		ft_printf("Please declare how many vertices there are\n");
		return (-1);
	}
	nb_vertices = ft_atoi(line);
	if (nb_vertices < 3)
	{
		ft_printf("You can not declare less than 3 walls.\n");
		return (-1);
	}
	if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex) * (nb_vertices))))
	{
		ft_printf("Could not malloc vertices!\n", env);
		return (-1);
	}
	if (!(env->clipped_vertices = (t_vertex *)malloc(sizeof(t_vertex) * (nb_vertices))))
	{
		ft_printf("Could not malloc clipped_vertices!\n", env);
		return (-1);
	}
	return (nb_vertices);
}

int		init_sectors(t_env *env, char *line)
{
	int	nb_sector;
	int	i;

	i = 0;
	line = skip_spaces(line);
	if (!*line)
	{
		ft_printf("Please declare how many sectors there are\n");
		return (-1);
	}
	nb_sector = atoi(line);
	if (nb_sector < 1)
	{
		ft_printf("You need to declare at least one sector.\n");
		return (-1);
	}
	if (!(env->sectors = (t_sector *)malloc(sizeof(t_sector) * (nb_sector))))
	{
		ft_printf("Could not malloc sectors!\n", env);
		return (-1);
	}
	i = 0;
	while (i < nb_sector)
	{
		env->sectors[i].vertices = NULL;
		env->sectors[i].ceilings = NULL;
		env->sectors[i].floors = NULL;
		env->sectors[i].neighbors = NULL;
		env->sectors[i].x_max = -2147483648;
		i++;
	}
	return (nb_sector);
}

int		parsing(int fd, t_env *env)
{
	char		*line;
	short		count_sectors;
	short		count_vertices;
	int			ret;
	int			line_count;

	env->nb_sectors = 0;
	env->nb_vertices = 0;
	count_sectors = 0;
	count_vertices = 0;
	env->player.sector = -1;
	line_count = 1;
	ft_printf("{red}");
	if (fd == -1)
		return (ft_printf("Could not open the file\n"));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (ft_printf("Invalid file!\n", env));
		if (line[0] == 'p')
		{
			if (count_sectors == 0 || env->nb_sectors == 0)
				return (ft_printf("You must declare sectors before you declare the player\n"));
			if (count_sectors < env->nb_sectors)
				return (ft_printf("You gave less sectors than you declared.\n"));
			if (parse_player(env, line, line_count))
				return (ft_printf("Error while parsing player!\n"));
		}
		else if (line[0] == 'v')
		{
			if (env->nb_vertices <= 0)
				return (ft_printf("Please say how many vertices there are before declaring them\n(line starting with \'V\' followed by the number of vertices)\n"));
			if (count_vertices >= env->nb_vertices)
				return (ft_printf("You gave more vertices than you declared\n"));
			if (parse_vertex(env, line, count_vertices, line_count))
				return (ft_printf("Error while parsing vertices!\n"));
			count_vertices++;
		}
		else if (line[0] == 's')
		{
			if (env->nb_sectors <= 0)
				return (ft_printf("Please declare how many sectors there are.\n"));
			if (count_sectors >= env->nb_sectors)
				return (ft_printf("You gave more sectors than you declared.\n"));
			if (parse_sector(env, line, count_sectors, line_count))
				return (ft_printf("Error while parsing sectors!\n"));
			count_sectors++;
		}
		else if (line[0] == 'V')
		{
			if (env->nb_vertices != 0)
				return (ft_printf("Redeclaration of vertices numbers (line %d)\n", line_count));
			if ((env->nb_vertices = init_vertices(env, line)) == -1)
				return (ft_printf("Could not init vertices!\n"));
		}
		else if (line [0] == 'S')
		{
			if (env->nb_sectors != 0)
				return (ft_printf("Redeclaration of sectors numbers (line %d)\n", line_count));
			if (count_vertices == 0 || env->nb_vertices == 0)
				return (ft_printf("You must declare vertices before you declare sectors\n"));
			if (count_vertices < env->nb_vertices)
				return (ft_printf("You gave less vertices than you declared.\n"));
			if ((env->nb_sectors = init_sectors(env, line)) == -1)
				return (ft_printf("Could not init sectors!\n"));
		}
		line_count++;
		ft_strdel(&line);
	}
	if (env->player.sector == -1)
		return (ft_printf("You need to give player data\n"));
	ft_strdel(&line);
	set_sectors_xmax(env);
	if (close(fd))
		return (ft_printf("Could not close the file\n"));
	return (0);
}
