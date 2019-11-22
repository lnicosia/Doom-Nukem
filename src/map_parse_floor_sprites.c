/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_floor_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 18:47:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_floor_sprites(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("floor sprites", parser));
	if (**line != '(')
		return (invalid_char("before floor sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_floor_sprites_count = count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting floor sprites"));
	env->sectors[parser->sectors_count].nb_floor_sprites = parser->sector_floor_sprites_count;
	if (!(env->sectors[parser->sectors_count].floor_sprites.sprite = (short*)
		malloc(sizeof(short) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite indexes"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite scales"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.pos = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	i = 0;
	while (i < parser->sector_floor_sprites_count)
	{
		(*line)++;
		env->sectors[parser->sectors_count].floor_sprites.sprite[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].floor_sprites.sprite[i] < 0
				|| env->sectors[parser->sectors_count].floor_sprites.sprite[i] > MAX_WALL_SPRITES)
			return (custom_error_with_line("Invalid floor sprite texture", parser));
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
