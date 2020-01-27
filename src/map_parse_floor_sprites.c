/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_floor_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 18:43:02 by lnicosia         ###   ########.fr       */
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
	if ((parser->sector_floor_sprites_count = count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting floor sprites"));
	env->sectors[parser->sectors_count].floor_sprites.nb_sprites = parser->sector_floor_sprites_count;
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
			return (custom_error_with_line("Invalid floor sprite texture", parser));
		env->sectors[parser->sectors_count].floor_sprites.sprite[i] =
		env->object_main_sprite[parse];
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.pos[i].x = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.pos[i].y = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.scale[i].x = ft_atof(*line);
		if (env->sectors[parser->sectors_count].floor_sprites.scale[i].x <= 0)
			return (custom_error_with_line("Floor sprite scale must be positive", parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].floor_sprites.scale[i].y = ft_atof(*line);
		if (env->sectors[parser->sectors_count].floor_sprites.scale[i].y <= 0)
			return (custom_error_with_line("Floor sprite scale must be positive", parser));
		env->sectors[parser->sectors_count].floor_sprites_scale[i].x
		= env->object_sprites[env->sectors[parser->sectors_count]
		.floor_sprites.sprite[i]].size[0].x
		/ env->sectors[parser->sectors_count].floor_sprites.scale[i].x;
		env->sectors[parser->sectors_count].floor_sprites_scale[i].y
		= env->object_sprites[env->sectors[parser->sectors_count]
		.floor_sprites.sprite[i]].size[0].y
		/ env->sectors[parser->sectors_count].floor_sprites.scale[i].y;
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
