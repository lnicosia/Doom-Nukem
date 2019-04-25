/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/04/25 17:03:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*skip_number(char *line)
{
	while ((*line <= '9' && *line >= '0') || *line == '.' || *line == '-')
		line++;
	line++;
	return (line);
}

char	*skip_spaces(char *line)
{
	while ((*line > '9' || *line < '0') && *line != '-')
		line++;
	return (line);
}

int	player_pos(t_env *env, char *line)
{
	line = skip_spaces(line);
	env->player.pos.y = ft_atof(line);
	line = skip_number(line);
	env->player.pos.x = ft_atof(line);
	line = skip_number(line);
	env->player.angle = ft_atof(line);
	line = skip_number(line);
	env->player.sector = ft_atoi(line);
	return (0);
}

int	vertices(t_env *env, char *line, int num)
{
	env->vertices[num].num = num;
	line = skip_spaces(line);
	env->vertices[num].y = ft_atof(line);
	//ft_printf("s = %s\nx = %f\n", line, ft_atof(line));
	line = skip_number(line);
	env->vertices[num].x = ft_atof(line);
	//ft_printf(" y= %f\n", line, ft_atof(line));
	return (0);
}

int	calc_vertices(char *line)
{
	int i;

	i = 0;
	while (*line != '	')
	{
		while ((*line < '0' || *line > '9') && *line != '	')
			line++;
		if (*line <= '9' && *line >= '0')
		{
			i++;
			while (*line <= '9' && *line >= '0')
				line++;
		}
	}
	return (i);
}

int	calc_neighbors(char *line)
{
	int	i;

	i = 0;
	while (*line != '\n' && *line != '\0')
	{
		while ((*line < '0' || *line > '9'))
			line++;
		if ((*line <= '9' && *line >= '0'))
		{
			i++;
			while ((*line <= '9' && *line >= '0'))
				line++;
		}
	}
	return (i);
}

int	sectors(t_env *env, char *line, short num)
{
	short	iter;
	short	iter_max;

	env->sectors[num].num = num;
	line = skip_spaces(line);
	env->sectors[num].floor = ft_atof(line);
	line = skip_number(line);
	env->sectors[num].floor_slope = tan(ft_atof(line) * M_PI / 180.0);
	line = skip_number(line);
	env->sectors[num].ceiling = ft_atof(line);
	line = skip_number(line);
	env->sectors[num].ceiling_slope = tan(ft_atof(line) * M_PI / 180.0);
	line = skip_number(line);
	iter_max = calc_vertices(line);
	env->sectors[num].nb_vertices = iter_max;
	if (!(env->sectors[num].vertices = (short*)malloc(sizeof(short) * (iter_max + 1))))
		return (ft_printf("Could not malloc sector vertices!\n", env));
	if (!(env->sectors[num].ceilings = (double*)malloc(sizeof(double) * (iter_max + 1))))
		return (ft_printf("Could not malloc sector ceilings!\n", env));
	if (!(env->sectors[num].floors = (double*)malloc(sizeof(double) * (iter_max + 1))))
		return (ft_printf("Could not malloc sector floors!\n", env));
	iter = 0;
	while (iter < iter_max)
	{
		line = skip_spaces(line);
		env->sectors[num].vertices[iter] = ft_atoi(line);
		while (*line <= '9' && *line >= '0')
			line++;
		line++;
		iter++;
	}
	env->sectors[num].vertices[iter_max] = env->sectors[num].vertices[0];
	line = skip_spaces(line);
	iter_max = calc_neighbors(line);
	iter = 0;
	if (!(env->sectors[num].neighbors = (short*)malloc(sizeof(short) * (iter_max))))
		return (ft_printf("Could not malloc sector neighbors!\n", env));
	while (iter < iter_max)
	{
		line = skip_spaces(line);
		env->sectors[num].neighbors[iter] = ft_atoi(line);
		line = skip_number(line);
		iter++;
	}
	return (0);
}

int	init_vertex(t_env *env, char *line)
{
	int	nb_vertex;

	line = skip_spaces(line);
	nb_vertex = ft_atoi(line);
	if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex) * (nb_vertex))))
		return (ft_printf("Could not malloc vertices!\n", env));
	return (0);
}

int	init_sectors(t_env *env, char *line)
{
	int	nb_sector;
	int	i;

	line = skip_spaces(line);
	nb_sector = atoi(line);
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
		i++;
	}
	return (nb_sector);
}

int	parsing(int fd, t_env *env)
{
	char		*line;
	short		nb_vertices;
	short		nb_sectors;
	int			ret;

	nb_vertices = 0;
	nb_sectors = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (ft_printf("Invalid file!\n", env));
		if (line[0] == 'p')
			player_pos(env, line);
		else if (line[0] == 'v')
		{
			vertices(env, line, nb_vertices);
			nb_vertices++;
		}
		else if (line[0] == 's')
		{
			if (sectors(env, line, nb_sectors))
				return (ft_printf("Error while parsing sectors!\n"));
			nb_sectors++;
		}
		else if (line[0] == 'V')
		{
			if (init_vertex(env, line))
				return (ft_printf("Could not init vertices!\n"));
		}
		else if (line [0] == 'S')
		{
			if ((env->nb_sectors = init_sectors(env, line)) == -1)
				return (ft_printf("Could not init sectors!\n"));
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	env->nb_vertices = nb_vertices;
	return (0);
}
