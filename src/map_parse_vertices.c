/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:07:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/20 11:47:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

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
		return (ft_printf("Line %d is incomplete\n", parser->line_count));
	env->vertices[parser->vertices_count].y = ft_atof(line);
	line = skip_number(line);
	if (!*line)
		return (ft_printf("Line %d is incomplete\n", parser->line_count));
	line = skip_spaces(line);
	if (*line < '0' || *line > '9')
		return (ft_printf("Invalid character after vertex y at line %d\n",
		parser->line_count));
	//line++;
	env->vertices[parser->vertices_count].x = ft_atof(line);
	line = skip_number(line);
	if (*line != '\0')
		return (ft_printf("Invalid character at vertex %d (line %d)\n",
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

	while (parser->vertices_count < env->nb_vertices
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if ((line[0] >= '0' && line[0] <= '9') || line[0] == '-')
		{
			if (parse_vertex(env, parser, line))
				return (ft_printf("Error while parsing vertex %d (line %d)\n",
							parser->vertices_count, parser->line_count));
		}
		else if (line[0] == '\0' && parser->vertices_count < env->nb_vertices)
			return (ft_printf("You must still declare %d vertices (line %d)\n",
						env->nb_vertices - parser->vertices_count,
						parser->line_count));
		else if (line[0] != '#')
			return (ft_printf("Invalid character at line %d\n",
						parser->line_count));
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (line[0] != '\0')
			return (ft_printf("Line %d must be an empty line "
						 "(every vertex has been declared)\n",
						parser->line_count));
		ft_strdel(&line);
	}
	else
		return (ft_printf("File ended at vertices declaration\n"));
	return (0);
}
