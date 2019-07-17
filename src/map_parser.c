/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/17 18:11:36 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

static int	init_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (parser->ret == -1)
			return (ft_printf("Invalid file\n"));
		if (line[0] == 'V' && line[1] == ' '
				&& line[2] >= '0' && line[2] <= '9')
		{
			line++;
			line = skip_spaces(line);
			if (!*line)
				return (ft_printf("Please declare how many vertices "
							"there are\n"));
			env->nb_vertices = ft_atoi(line);
			line = skip_number(line);
			if (*line)
				return (ft_printf("Too much data in vertices number "
							"declaration (line %d)\n", parser->line_count));
			if (env->nb_vertices < 3)
				return (ft_printf("You can not declare less than 3 walls.\n"));
			if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex)
							* (env->nb_vertices))))
				return (ft_printf("Could not malloc vertices!\n", env));
			ft_strdel(&tmp);
			return (0);
		}
		else if (line[0] != '#')
			return (ft_printf("Wrong format of vertices number "
						"declaration (line %d)\nEx: \"V 127\" (> 2)\n",
						parser->line_count));
		ft_strdel(&tmp);
	}
	return (0);
}

static int	init_sectors(t_env *env, t_map_parser *parser)
{
	int		i;
	char	*line;
	char	*tmp;

	line = NULL;
	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (line[0] == 'S' && line[1] == ' '
				&& line[2] >= '0' && line[2] <= '9')
		{
			line++;
			line = skip_spaces(line);
			if (!*line)
				return (ft_printf("Please declare how many sectors there are\n"));
			env->nb_sectors = atoi(line);
			line = skip_number(line);
			if (*line)
				return (ft_printf("Too much data in sectors number "
							"declaration (line %d)\n", parser->line_count));
			if (env->nb_sectors < 1)
				return (ft_printf("You need to declare at least one sector.\n"));
			if (!(env->sectors = (t_sector *)malloc(sizeof(t_sector) * (env->nb_sectors))))
				return (ft_printf("Could not malloc sectors!\n", env));
			i = 0;
			while (i < env->nb_sectors)
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
				env->sectors[i].textures = NULL;
				i++;
			}
			ft_strdel(&tmp);
			return (0);
		}
		else if (line[0] != '#')
			return (ft_printf("Wrong format of sectors number "
						"declaration (line %d)\nEx: \"S 35\" (> 0)\n",
						parser->line_count));
		ft_strdel(&tmp);
	}
	return (0);
}

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

int		parse_player(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (line[0] >= '0' && line[0] <= '9')
		{
			env->player.pos.y = ft_atof(line);
			line = skip_number(line);
			line = skip_spaces(line);
			env->player.pos.x = ft_atof(line);
			line = skip_number(line);
			line = skip_spaces(line);
			env->player.angle = (ft_atof(line) + 0.00001)* CONVERT_RADIANS;
			env->player.angle_z = 0;
			env->player.angle_cos = cos(env->player.angle);
			env->player.angle_sin = sin(env->player.angle);
			env->player.perp_cos = cos(env->player.angle - M_PI / 2);
			env->player.perp_sin = sin(env->player.angle - M_PI / 2);
			line = skip_number(line);
			line = skip_spaces(line);
			env->player.sector = ft_atoi(line);
			if (env->player.sector < 0 || env->player.sector >= env->nb_sectors)
				return (ft_printf("Invalid player sector (line %d)\n", parser->line_count));
			line = skip_number(line);
			line = skip_spaces(line);
			if (*line != '\0')
				return (ft_printf("Invalid character after player declaration (line %d)\n", parser->line_count));
		}
		else if (line[0] != '#')
			return (ft_printf("Invalid character at line %d\n",
						parser->line_count));
		ft_strdel(&tmp);
	}
	return (0);
}

int		parse_map(char *file, t_env *env)
{
	t_map_parser	parser;

	env->nb_sectors = 0;
	env->nb_vertices = 0;
	parser.sectors_count = 0;
	parser.vertices_count = 0;
	parser.objects_count = 0;
	env->player.sector = -1;
	parser.line_count = 0;
	ft_printf("{red}");
	if ((parser.fd = open(file, O_RDONLY)) < 0)
		return (ft_printf("Could not open %s\n", file));
	if (init_vertices(env, &parser))
		return (ft_printf("Could not init vertices\n"));
	if (parse_vertices(env, &parser))
		return (ft_printf("Error while parsing vertices\n"));
	if (init_sectors(env, &parser))
		return (ft_printf("Could not init sectors\n"));
	if (parse_sectors(env, &parser))
		return (ft_printf("Error while parsing sectors\n"));
	if (init_objects(env, &parser))
		return (ft_printf("Could not init objects\n"));
	if (parse_objects(env, &parser))
		return (ft_printf("Error while parsing objects\n"));
	if (parse_player(env, &parser))
		return (ft_printf("Error while parsing player\n"));
	if (env->player.sector == -1)
		return (ft_printf("You need to give player data\n"));
	set_sectors_xmax(env);
	if (close(parser.fd))
		return (ft_printf("Could not close the file\n"));
	return (0);
}
