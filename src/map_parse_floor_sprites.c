/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_floor_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:10:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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
		return (ft_printf("Invalid double floor sprite %d scale.x\n", i));
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
		return (ft_printf("Invalid double floor sprite %d scale.y\n", i));
	return (parse_current_floor_sprite3(env, line, parser, i));
}

int		parse_current_floor_sprite(t_env *env, char **line,
t_map_parser *parser, int i)
{
	int	parse;

	(*line)++;
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int	for floor sprites count\n"));
	parse = ft_atoi(*line);
	if (parse < 0 || parse >= MAX_OBJECTS)
		return (custom_error_with_line("Invalid floor sprite texture",
		parser));
		env->sectors[parser->sectors_count].floor_sprites.sprite[i] =
	env->objects_main_sprites[parse];
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double floor sprite %d pos.x\n", i));
	env->sectors[parser->sectors_count].floor_sprites.pos[i].x =
	ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double floor sprite %d pos.y\n", i));
	env->sectors[parser->sectors_count].floor_sprites.pos[i].y =
	ft_atof(*line);
	return (parse_current_floor_sprite2(env, line, parser, i));
}

int		parse_floor_sprites2(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (i < parser->sector_floor_sprites_count)
	{
		if (parse_current_floor_sprite(env, line, parser, i))
			return (-1);
		i++;
	}
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector floor sprites", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_floor_sprites(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (missing_data("floor sprites", parser));
	if (**line != '(')
		return (invalid_char("before floor sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_floor_sprites_count =
		count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting floor sprites"));
	env->sectors[parser->sectors_count].floor_sprites.nb_sprites =
	parser->sector_floor_sprites_count;
	if (!(env->sectors[parser->sectors_count].floor_sprites.sprite = (int*)
		malloc(sizeof(int) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite indexes"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite scales"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.pos = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	if (!(env->sectors[parser->sectors_count].floor_sprites_scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	return (parse_floor_sprites2(env, line, parser));
}
