/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_current_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:53:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:53:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "parser.h"

int		parse_current_sprite3(t_env *env, char **line,
t_map_parser *parser, t_point index)
{
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for wall %d sprite %d scale.y\n",
		index.x, index.y));
		env->sectors[parser->sectors_count].wall_sprites[index.x].
	scale[index.y].y = ft_atof(*line);
	if ((env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].y < 0.1
		&& env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].y > -0.1)
		|| env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].y > 100
		|| env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].y < -100)
		return (custom_error_with_line("Sprite scale must be positive"
		"between 0.1 and 100", parser));
		*line = skip_number(*line);
	(*line)++;
	return (0);
}

int		parse_current_sprite2(t_env *env, char **line,
t_map_parser *parser, t_point index)
{
	env->sectors[parser->sectors_count].wall_sprites[index.x].pos[index.y].y =
	ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for wall %d sprite %d scale.x\n",
		index.x, index.y));
		env->sectors[parser->sectors_count].wall_sprites[index.x].
	scale[index.y].x = ft_atof(*line);
	if ((env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].x < 0.1
		&& env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].x > -0.1)
		|| env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].x > 100
		|| env->sectors[parser->sectors_count].
		wall_sprites[index.x].scale[index.y].x < -100)
		return (custom_error_with_line("Sprite scale must be"
		"between 0.1 and 100", parser));
		*line = skip_number(*line);
	*line = skip_spaces(*line);
	return (parse_current_sprite3(env, line, parser, index));
}

int		parse_current_sprite(t_env *env, char **line,
t_map_parser *parser, t_point index)
{
	int		parse;

	(*line)++;
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for wall %d sprite texture\n",
		index.x));
	parse = ft_atoi(*line);
	if (parse < 0 || parse >= MAX_OBJECTS)
		return (custom_error_with_line("Invalid sprite texture",
		parser));
		env->sectors[parser->sectors_count].wall_sprites[index.x].
		sprite[index.y] = env->objects_main_sprites[parse];
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for wall %d sprite %d pos.x\n",
		index.x, index.y));
		env->sectors[parser->sectors_count].wall_sprites[index.x].pos[index.y].
		x = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (custom_error("Invalid double for wall %d sprite %d pos.y\n",
		index.x, index.y));
		return (parse_current_sprite2(env, line, parser, index));
}
