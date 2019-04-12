/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/04/12 17:27:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	player_pos(t_env *env, char *line)
{
	while (*line > '9' || *line < '0')
		line++;
	env->player.pos.x = ft_atoi(line);
	while (*line <= '9' && *line >= '0')
		line++;
	line++;
	env->player.pos.y = ft_atoi(line);
	while (*line > '9' || *line < '0')
		line++;
	line++;
	env->player.angle = ft_atoi(line);
	while (*line <= '9' && *line >= '0')
		line++;
	line++;
	env->player.sector = ft_atoi(line);
	env->player.pos.z = 6;
	return (1);
}

int	vertices(t_env *env, char *line, int num)
{
	env->vertices[num].num = num;
	while (*line < '0' || *line > '9')
		line++;
	env->vertices[num].x = ft_atoi(line);
	while (*line >= '0' && *line <= '9')
		line++;
	line++;
	env->vertices[num].y = ft_atoi(line);
	return (1);
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

	env->sector[num].num = num;
	while (*line > '9' || *line < '0')
		line++;
	env->sector[num].floor = ft_atoi(line);
	while (*line <= '9' && *line >= '0')
		line++;
	line++;
	env->sector[num].ceiling = ft_atoi(line);
	while (*line <= '9' && *line >= '0')
		line++;
	line++;
	iter_max = calc_vertices(line);
	env->sector[num].nb_vertices = iter_max;
	env->sector[num].vertices = (short*)malloc(sizeof(short) * (iter_max + 1));
	iter = iter_max - 1;
	while (iter >= 0)
	{
		while (*line > '9' || *line < '0')
			line++;
		env->sector[num].vertices[iter] = ft_atoi(line);
		while (*line <= '9' && *line >= '0')
			line++;
		line++;
		iter--;
	}
	env->sector[num].vertices[iter_max] = env->sector[num].vertices[0];
	while ((*line > '9' || *line < '0') && *line != '-')
		line++;
	iter_max = calc_neighbors(line);
	iter = iter_max - 1;
	env->sector[num].neighbors = (short*)malloc(sizeof(short) * (iter_max));
	while (iter >= 0)
	{
		while ((*line > '9' || *line < '0') && *line != '-')
			line++;
		env->sector[num].neighbors[iter] = ft_atoi(line);
		while ((*line <= '9' && *line >= '0')|| *line == '-')
			line++;
		line++;
		iter--;
	}
	return (1);
}

int	init_vertex(t_env *env, char *line)
{
	int	nb_vertex;

	while (*line < '0' || *line > '9')
		line++;
	nb_vertex = ft_atoi(line);
	env->vertices = (t_vertex *)malloc(sizeof(t_vertex) * (nb_vertex));
	return (1);
}

int	init_sectors(t_env *env, char *line)
{
	int	nb_sector;

	while (*line < '0' || *line > '9')
		line++;
	nb_sector = atoi(line);
	env->sector = (t_sector *)malloc(sizeof(t_sector) * (nb_sector));
	return (nb_sector);
}

int	parsing(int fd, t_env *env)
{
	char		*line;
	short		nb_vertices;
	short		nb_sectors;

	nb_vertices = 0;
	nb_sectors = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'p')
			player_pos(env, line);
		else if (line[0] == 'v')
		{
			vertices(env, line, nb_vertices);
			nb_vertices++;
		}
		else if (line[0] == 's')
		{
			sectors(env, line, nb_sectors);
			nb_sectors++;
		}
		else if (line[0] == 'V')
			init_vertex(env, line);
		else if (line [0] == 'S')
			env->nb_sectors = init_sectors(env, line);
	}
	env->nb_vertices = nb_vertices;
	return (1);
}
/*
int	main(int ac, char **av)
{
	int		fd;
	t_env	env;
	int		i;

	i = 0;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	parsing(fd, &env);	
	while (i < env.nb_vertices)
	{
		printf("vertex[%d] x = %f y = %f\n", i, env.vertices[i].x, env.vertices[i].y);
		i++;
	}
}*/
