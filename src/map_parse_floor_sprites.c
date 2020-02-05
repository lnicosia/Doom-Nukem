/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_floor_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 11:00:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_floor_sprites(t_env *env, char **line, t_map_parser *parser)
{
	int	i;
	int	parse;

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
	i = 0;
	while (i < parser->sector_floor_sprites_count)
	{
		(*line)++;
		parse = ft_atoi(*line);
		if (parse < 0 || parse >= MAX_OBJECTS)
			return (custom_error_with_line("Invalid floor sprite texture",
			parser));
		env->sectors[parser->sectors_count].floor_sprites.sprite[i] =
		env->objects_main_sprites[parse];
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.pos[i].x =
		ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.pos[i].y =
		ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
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
		i++;
	}
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector floor sprites", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}
