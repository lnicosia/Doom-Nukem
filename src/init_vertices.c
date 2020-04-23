#include "env.h"

int		parse_vertices_init2(t_env *env, t_map_parser *parser)
{
	if (env->nb_vertices < 3)
		return (custom_error("You can not declare less than 3 walls."));
	if (!(env->vertices = (t_vertex *)ft_memalloc(sizeof(t_vertex)
		* (env->nb_vertices))))
		return (ft_perror("Could not malloc vertices:"));
	ft_strdel(&parser->line);
	return (0);
}

int		parse_vertices_init(t_env *env, t_map_parser *parser, char *line)
{
	if (*line != 'V')
		return (invalid_char("at vertices number", "'V'", *line,
		parser));
	line++;
	if (!*line)
		return (missing_data("at vertices number", parser));
	if (*line != ' ')
		return (invalid_char("at vertices number", "space or a digit",
			*line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("before vertices number", parser));
	if (valid_int(line, parser) == WRONG_CHAR)
		return (ft_printf("Invalid int for nb_vertices\n"));
	env->nb_vertices = ft_atoi(line);
	if (env->nb_vertices > 100000)
		return (ft_printf("vertices can't exceed 100 000\n"));
	line = skip_number(line);
	if (*line && *line == ' ')
		return (extra_data("vertices number", parser));
	if (*line)
		return (invalid_char("after vertices number",
			"a digit or the end of the line", *line, parser));
	return (parse_vertices_init2(env, parser));
}

int		init_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		parser->line_count++;
		line = parser->line;
		if (parser->ret == -1)
			return (custom_error("Invalid file"));
		if (*line && *line != '#')
		{
		  	return (parse_vertices_init(env, parser, line));
		}
		else if (*line != '#')
			return (missing_data("vertices number declaration", parser));
		ft_strdel(&parser->line);
	}
	return (0);
}
