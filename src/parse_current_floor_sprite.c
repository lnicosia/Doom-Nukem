/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_current_floor_sprite.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:08:51 by marvin            #+#    #+#             */
/*   Updated: 2020/05/19 11:08:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map_parser.h"

int		parse_current_floor_sprite3(t_env *env, char **line,
t_map_parser *parser, int i)
{
	env->sectors[parser->sectors_count].floor_sprites.scale[i].y =
	ft_atof(*line);
	if ((env->sectors[parser->sectors_count].floor_sprites.scale[i].y < 0.1
		&& env->sectors[parser->sectors_count].
		floor_sprites.scale[i].y > -0.1)
		|| env->sectors[parser->sectors_count].
		floor_sprites.scale[i].y > 100
		|| env->sectors[parser->sectors_count].
		floor_sprites.scale[i].y < -100)
		return (custom_error_with_line("Floor sprite scale must be"
		"betweem 0.1 and 100", parser));
		precompute_floor_sprite_scales(parser->sectors_count, i, env);
	*line = skip_number(*line);
	(*line)++;
	return (0);
}

int		parse_current_floor_sprite2(t_env *env, char **line,
t_map_parser *parser, int i)
{
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double floor sprite %d scale.x\n", i));
	env->sectors[parser->sectors_count].floor_sprites.scale[i].x =
	ft_atof(*line);
	if ((env->sectors[parser->sectors_count].floor_sprites.scale[i].x < 0.1
		&& env->sectors[parser->sectors_count].
		floor_sprites.scale[i].x > -0.1)
		|| env->sectors[parser->sectors_count].
		floor_sprites.scale[i].x > 100
		|| env->sectors[parser->sectors_count].
		floor_sprites.scale[i].x < -100)
		return (custom_error_with_line("Floor sprite scale must be"
		"betweem 0.1 and 100", parser));
		*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double floor sprite %d scale.y\n", i));
	return (parse_current_floor_sprite3(env, line, parser, i));
}

int		parse_current_floor_sprite(t_env *env, char **line,
t_map_parser *parser, int i)
{
	int	parse;

	(*line)++;
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for floor sprites count\n"));
	parse = ft_atoi(*line);
	if (parse < 0 || parse >= MAX_OBJECTS)
		return (custom_error_with_line("Invalid floor sprite texture",
		parser));
		env->sectors[parser->sectors_count].floor_sprites.sprite[i] =
	env->objects_main_sprites[parse];
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double floor sprite %d pos.x\n", i));
	env->sectors[parser->sectors_count].floor_sprites.pos[i].x =
	ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double floor sprite %d pos.y\n", i));
	env->sectors[parser->sectors_count].floor_sprites.pos[i].y =
	ft_atof(*line);
	return (parse_current_floor_sprite2(env, line, parser, i));
}
