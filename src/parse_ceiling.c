#include "map_parser.h"
#include "env.h"

int		parse_ceiling5(t_env *env, char **line, t_map_parser *parser)
{
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.x", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for ceiling_map_scale.x"));
	env->sectors[parser->sectors_count].ceiling_map_scale.x = ft_atof(*line);
	if (env->sectors[parser->sectors_count].ceiling_map_scale.x < 1
		|| env->sectors[parser->sectors_count].ceiling_map_scale.x > 100)
		return (custom_error_with_line("Ceiling scale must be"
		"between 1 and 100", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling scale.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.y", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double ceiling_map_scale.y\n"));
	env->sectors[parser->sectors_count].ceiling_map_scale.y = ft_atof(*line);
	return (parse_ceiling6(env, line, parser));
}

int		parse_ceiling4(t_env *env, char **line, t_map_parser *parser)
{
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for ceiling_map_align.x\n"));
	env->sectors[parser->sectors_count].ceiling_map_align.x = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling align.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling.y", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for ceiling_map_align.y\n"));
	env->sectors[parser->sectors_count].ceiling_map_align.y = ft_atof(*line);
	if (env->sectors[parser->sectors_count].ceiling_texture < 0)
		env->contains_skybox = 1;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling align.y", "a digit or space(s)",
					**line, parser));
	return (parse_ceiling5(env, line, parser));
}

int		parse_ceiling3(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line || **line == ']')
		return (missing_data("ceiling texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling slope", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling texture", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for ceiling texture\n"));
	env->sectors[parser->sectors_count].ceiling_texture = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].ceiling_texture < -MAX_SKYBOX || env->
			sectors[parser->sectors_count].ceiling_texture >= MAX_WALL_TEXTURE)
		return (custom_error_with_line("Invalid ceiling texture", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling texture", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.x", parser));
	return (parse_ceiling4(env, line, parser));
}

int		parse_ceiling2(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line || **line == ']')
		return (missing_data("ceiling slope", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for ceiling slope\n"));
	env->sectors[parser->sectors_count].ceiling_slope = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling slope direction", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling slope", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling slope direction", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for ceiling slope start\n"));
	env->sectors[parser->sectors_count].start_ceiling_slope = ft_atoi(*line);
	*line = skip_number(*line);
	return (parse_ceiling3(env, line, parser));
}

int		parse_ceiling(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (missing_data("ceiling, vertices, neighbors, textures and light",
					parser));
	if (**line != '[')
		return (invalid_char("before ceiling data", "'['",
					**line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("ceiling height", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for ceiling height\n"));
	env->sectors[parser->sectors_count].ceiling = ft_atof(*line);
	env->sectors[parser->sectors_count].ceiling_min =
	env->sectors[parser->sectors_count].ceiling;
	env->sectors[parser->sectors_count].ceiling_max =
	env->sectors[parser->sectors_count].ceiling;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling slope", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling height", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (parse_ceiling2(env, line, parser));
}
