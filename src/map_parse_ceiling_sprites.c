/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_ceiling_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/24 14:05:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_ceiling_sprites(t_env *env, char **line, t_map_parser *parser)
{
	int	i;
	int	parse;

	if (!**line)
		return (missing_data("ceiling sprites", parser));
	if (**line != '(')
		return (invalid_char("before ceiling sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_ceiling_sprites_count =
		count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting ceiling sprites"));
	env->sectors[parser->sectors_count].ceiling_sprites.nb_sprites =
	parser->sector_ceiling_sprites_count;
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.sprite = (int*)
		malloc(sizeof(int) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite indexes"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite scales"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.pos = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite pos"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites_scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite pos"));
	i = 0;
	while (i < parser->sector_ceiling_sprites_count)
	{
		(*line)++;
		if (valid_int(*line, parser))
				return (ft_printf("Invalid int for ceiling sprite %d texture\n", i));
		parse = ft_atoi(*line);
		if (parse < 0 || parse> MAX_OBJECTS)
			return (custom_error_with_line("Invalid ceiling sprite texture",
			parser));
		env->sectors[parser->sectors_count].ceiling_sprites.sprite[i] =
		env->objects_main_sprites[parse];
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		if (valid_double(*line, parser))
				return (ft_printf("Invalid double for ceiling sprite %d pos.x\n", i));
		env->sectors[parser->sectors_count].ceiling_sprites.pos[i].x =
		ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		if (valid_double(*line, parser))
				return (ft_printf("Invalid double for ceiling sprite %d pos.y\n", i));
		env->sectors[parser->sectors_count].ceiling_sprites.pos[i].y =
		ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		if (valid_double(*line, parser))
				return (ft_printf("Invalid double for ceiling sprite %d scale.x\n", i));
		env->sectors[parser->sectors_count].ceiling_sprites.scale[i].x =
		ft_atof(*line);
		if ((env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].x < 0.1
			&& env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].x > -0.1)
			|| env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].x > 100
			|| env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].x < -100)
			return (custom_error_with_line("Ceiling sprite scale must be"
			"betweem 0.1 and 100", parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		if (valid_double(*line, parser))
				return (ft_printf("Invalid double for ceiling sprite %d scale.y\n", i));
		env->sectors[parser->sectors_count].ceiling_sprites.scale[i].y =
		ft_atof(*line);
		if ((env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].y < 0.1
			&& env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].y > -0.1)
			|| env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].y > 100
			|| env->sectors[parser->sectors_count].
			ceiling_sprites.scale[i].y < -100)
			return (custom_error_with_line("Ceiling sprite scale must be"
			"betweem 0.1 and 100", parser));
		precompute_ceiling_sprite_scales(parser->sectors_count, i, env);
		*line = skip_number(*line);
		(*line)++;
		i++;
	}
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector ceiling sprites", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}
