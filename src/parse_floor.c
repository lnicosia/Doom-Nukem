/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:09:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 11:39:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "parser.h"

int		parse_floor5(t_env *env, char **line, t_map_parser *parser)
{
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.x", parser));
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for floor_map_scale.x\n"));
	env->sectors[parser->sectors_count].floor_map_scale.x = ft_atof(*line);
	if (env->sectors[parser->sectors_count].floor_map_scale.x < 1
		|| env->sectors[parser->sectors_count].floor_map_scale.x > 100)
		return (custom_error_with_line("Floor scale must be"
		"between 1 and 100", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor scale.x", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.y", parser));
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for floor_map_scale.y\n"));
	return (parse_floor6(env, line, parser));
}

int		parse_floor4(t_env *env, char **line, t_map_parser *parser)
{
	env->sectors[parser->sectors_count].floor_map_align.x = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor align.x", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.y", parser));
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for floor_map_align.y\n"));
	env->sectors[parser->sectors_count].floor_map_align.y = ft_atof(*line);
	if (env->sectors[parser->sectors_count].floor_texture < 0)
		env->contains_skybox = 1;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor align.y", "a digit or space",
			**line, parser));
	return (parse_floor5(env, line, parser));
}

int		parse_floor3(t_env *env, char **line, t_map_parser *parser)
{
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor texture", parser));
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for floor texture\n"));
	env->sectors[parser->sectors_count].floor_texture = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].floor_texture < -MAX_SKYBOX
	|| env->sectors[parser->sectors_count].floor_texture >= MAX_WALL_TEXTURE)
		return (custom_error_with_line("Invalid floor texture", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor texture", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.x", parser));
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for floor_map_align.x\n"));
	return (parse_floor4(env, line, parser));
}

int		parse_floor2(t_env *env, char **line, t_map_parser *parser)
{
	if (valid_double(*line, parser))
		return (custom_error("invalid double for floor_slope\n"));
	env->sectors[parser->sectors_count].floor_slope = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope direction and texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor slope", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope direction and texture", parser));
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for floor slope start\n"));
	env->sectors[parser->sectors_count].start_floor_slope = ft_atoi(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor slope", "a digit or space(s)",
			**line, parser));
	return (parse_floor3(env, line, parser));
}

int		parse_floor(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before floor data", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("floor height, slope and texture", parser));
	if (valid_double(*line, parser))
		return (custom_error("invalid double for floor height\n"));
	env->sectors[parser->sectors_count].floor = ft_atof(*line);
	env->sectors[parser->sectors_count].floor_min = env->sectors[parser->
		sectors_count].floor;
	env->sectors[parser->sectors_count].floor_max = env->sectors[parser->
		sectors_count].floor;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope and texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor height", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope, direction and texture", parser));
	return (parse_floor2(env, line, parser));
}
