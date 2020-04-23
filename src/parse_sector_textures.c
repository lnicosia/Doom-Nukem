#include "map_parser.h"
#include "env.h"

int		parse_current_texture3(t_env *env, char **line, t_map_parser *parser,
int i)
{
	*line = skip_number(*line);
	if (set_sector_wall_map_array(&env->sectors[parser->sectors_count], 
		&env->wall_textures[env->sectors[parser->sectors_count].textures[i]],
		i, env))
		return (-1);
	(*line)++;
	return (0);
}

int		parse_current_texture2(t_env *env, char **line, t_map_parser *parser,
int i)
{
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for wall %d texture align.y\n", i));
	env->sectors[parser->sectors_count].align[i].y = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for wall %d texture scale.x\n", i));
	env->sectors[parser->sectors_count].scale[i].x = ft_atof(*line);
	if (env->sectors[parser->sectors_count].scale[i].x < 1
		|| env->sectors[parser->sectors_count].scale[i].x > 100)
		return (custom_error_with_line("Wall scale must be"
		"between 1 and 100", parser));
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for wall %d texture scale.y\n", i));
	env->sectors[parser->sectors_count].scale[i].y = ft_atof(*line);
	if (env->sectors[parser->sectors_count].scale[i].y < 1
		|| env->sectors[parser->sectors_count].scale[i].y > 100)
		return (custom_error_with_line("Wall scale must be"
		"between 1 and 100", parser));
	return (parse_current_texture3(env, line, parser, i));
}

int		parse_current_texture(t_env *env, char **line, t_map_parser *parser,
int i)
{
	(*line)++;
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for wall %d texture\n", i));
	env->sectors[parser->sectors_count].textures[i] = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].textures[i] < -MAX_SKYBOX
	|| env->sectors[parser->sectors_count].textures[i] >= MAX_WALL_TEXTURE)
	{
		ft_dprintf(STDERR_FILENO,
				"[Line %d] Texture \'%d\' in sector %d does not exist\n",
				parser->line_count,
				env->sectors[parser->sectors_count].textures[i],
				parser->sectors_count);
		return (-1);
	}
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double wall %d texture align.x\n", i));
	env->sectors[parser->sectors_count].align[i].x = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	return (parse_current_texture2(env, line, parser, i));
}

int		parse_sector_textures2(char **line, t_map_parser *parser)
{
	(*line)++;
	if (!**line)
		return (missing_data("sprite and light", parser));
	if (**line != ' ')
		return (invalid_char("after textures data", "space(s)", **line,
		parser));
	*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_textures(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("textures, sprite and light", parser));
	if (**line != '(')
		return (invalid_char("before sector textures", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_textures_count = count_textures(*line, parser)) == -1)
		return (custom_error("Error while counting textures"));
	if (parser->sector_textures_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more textures",
		parser->sectors_count, parser));
	if (parser->sector_textures_count > parser->sector_vertices_count)
		return (sector_error("has too much textures", parser->sectors_count,
		parser));
	i = 0;
	while (i < parser->sector_textures_count)
	{
	  	if (parse_current_texture(env, line, parser, i))
		  	return (-1);
		i++;
	}
	return (parse_sector_textures2(line, parser));
}
