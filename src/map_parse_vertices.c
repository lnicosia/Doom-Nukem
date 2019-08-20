/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:07:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/20 11:06:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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
			return (ft_dprintf(STDERR_FILENO,
						"Vertices %d and %d are identical\n", vertex.num, i));
			i++;
	}
	return (0);
}

static int	parse_vertex(t_env *env, t_map_parser *parser, char *line)
{
	env->vertices[parser->vertices_count].num = parser->vertices_count;
	if (valid_number(line, parser))
		return (invalid_char("before vertex y", "a digit", *line, parser));
	env->vertices[parser->vertices_count].y = ft_atof(line);
	line = skip_number(line);
	if (*line && *line != ' ')
		return (invalid_char("after vertex y", "a digit or space(s)",
					*line, parser));
	if (!*line)
		return (missing_data("vertex x", parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("vertex x", parser));
	if (valid_number(line, parser))
		return (invalid_char("before vertex x", "a digit or space(s)",
					*line, parser));
	env->vertices[parser->vertices_count].x = ft_atof(line);
	line = skip_number(line);
	if (*line && *line == ' ')
		return (extra_data("after vertex x", parser));
	if (*line)
		return (invalid_char("after vertex x",
					"a digit or the end of the line", *line, parser));
	if (check_vertex_duplicate(env, env->vertices[parser->vertices_count],
				parser->vertices_count))
	{
		ft_dprintf(STDERR_FILENO,
				"[Line %d] Vertex %d already exists\n",
				parser->line_count, parser->vertices_count);
		return (-1);
	}
	parser->vertices_count++;
	return (0);
}

int			parse_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;

	line = NULL;
	while (parser->vertices_count < env->nb_vertices
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (*line)
		{
			if (parse_vertex(env, parser, line))
			{
				ft_dprintf(STDERR_FILENO,
						"[Line %d] Vertex %d had an error\n",
						parser->line_count,
						parser->vertices_count);
				return (-1);
			}
		}
		else
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] You must still declare %d vertices\n",
					parser->line_count,
					env->nb_vertices - parser->vertices_count);
			return (-1);
		}
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (*line)
			return (custom_error_with_line("Must be an empty line "
						 "(every vertex has been declared)\n",
						parser));
		ft_strdel(&line);
	}
	else
		return (missing_data("sectors, objects and player declaration",
					parser));
	return (0);
}
