/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:07:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/24 16:32:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

static int	init_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &line)))
	{
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
				"declaration (line %d)\n",
				parser->line_count));
			if (env->nb_vertices < 3)
				return (ft_printf("You can not declare less than 3 walls.\n"));
			if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex)
							* (env->nb_vertices))))
				return (ft_printf("Could not malloc vertices!\n", env));
			parser->line_count++;
			return (0);
		}
		else if (line[0] != '#')
			return (ft_printf("Wrong format of vertices number "
			"declaration%d\nEx: \"V vertices_count\"\n",
			parser->line_count));
		ft_strdel(&line);
		parser->line_count++;
	}
	return (0);
}

/*
**	Chek if the current vertex already exists
*/

static int	check_vertex_duplicate(t_env *env, t_vertex vertex, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (vertex.x == env->vertices[i].x && vertex.y == env->vertices[i].y)
			return (ft_printf("Vertices %d and %d are identical\n",
			vertex.num, i));
			i++;
	}
	return (0);
}

static int	parse_vertex(t_env *env, t_map_parser *parser, char *line)
{
	env->vertices[parser->vertices_count].num = parser->vertices_count;
	if (!*line)
		return (ft_printf("Wrong number of coordinates at "
		"vertex %d (line %d)\n", parser->vertices_count, parser->line_count));
	env->vertices[parser->vertices_count].y = ft_atof(line);
	line = skip_number(line);
	if (!*line)
		return (ft_printf("Wrong number of coordinates at "
		"vertex %d (line %d)\n", parser->vertices_count, parser->line_count));
	line = skip_spaces(line);
	if (*line < '0' || *line > '9')
		return (ft_printf("Wrong character after vertex y at line %d\n",
		parser->line_count));
	//line++;
	env->vertices[parser->vertices_count].x = ft_atof(line);
	line = skip_number(line);
	if (*line != '\0')
		return (ft_printf("Too much data at vertex %d (line %d)\n",
		parser->vertices_count, parser->line_count));
	if (check_vertex_duplicate(env, env->vertices[parser->vertices_count],
				parser->vertices_count))
		return (ft_printf("Vertex %d already exists (line %d)\n",
		parser->vertices_count, parser->line_count));
	parser->vertices_count++;
	return (0);
}

int			parse_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;

	if (init_vertices(env, parser))
		return (ft_printf("Could not init vertices\n"));
	if (parser->vertices_count >= env->nb_vertices)
		return (ft_printf("You gave more vertices than you declared\n"));
	while (parser->vertices_count < env->nb_vertices
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		if (line[0] >= '0' && line[0] <= '9')
		{
			if (parse_vertex(env, parser, line))
				return (ft_printf("Error while parsing vertex %d (line %d)\n",
							parser->vertices_count, parser->line_count));
		}
		else if (line[0] != '#')
			return (ft_printf("Line %d should be a vertex declaration "
						"(you must still declare %d vertice(s))\n",
						parser->line_count,
						env->nb_vertices - parser->vertices_count));
		parser->line_count++;
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		if (line[0] != '\0')
			return (ft_printf("Line %d should be empty\n",
						parser->line_count));
	}
	else
		return (ft_printf("File ended at vertices declaration\n"));
	return (0);
}
