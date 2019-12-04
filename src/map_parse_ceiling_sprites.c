/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_ceiling_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/04 11:03:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_ceiling_sprites(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("ceiling sprites", parser));
	if (**line != '(')
		return (invalid_char("before ceiling sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_ceiling_sprites_count = count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting ceiling sprites"));
	env->sectors[parser->sectors_count].ceiling_sprites.nb_sprites = parser->sector_ceiling_sprites_count;
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.sprite = (short*)
		malloc(sizeof(short) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite indexes"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite scales"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites.pos = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector ceiling sprite pos"));
	if (!(env->sectors[parser->sectors_count].ceiling_sprites_scale = (t_v2*)
		malloc(sizeof(t_v2) * parser->sector_ceiling_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	i = 0;
	while (i < parser->sector_ceiling_sprites_count)
	{
		(*line)++;
		env->sectors[parser->sectors_count].ceiling_sprites.sprite[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].ceiling_sprites.sprite[i] < 0
				|| env->sectors[parser->sectors_count].ceiling_sprites.sprite[i] > MAX_WALL_SPRITES)
			return (custom_error_with_line("Invalid ceiling sprite texture", parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].ceiling_sprites.pos[i].x = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].ceiling_sprites.pos[i].y = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].ceiling_sprites.scale[i].x = ft_atof(*line);
		if (env->sectors[parser->sectors_count].ceiling_sprites.scale[i].x <= 0)
			return (custom_error_with_line("Floor sprite scale must be positive", parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].ceiling_sprites.scale[i].y = ft_atof(*line);
		if (env->sectors[parser->sectors_count].ceiling_sprites.scale[i].y <= 0)
			return (custom_error_with_line("Floor sprite scale must be positive", parser));
		env->sectors[parser->sectors_count].ceiling_sprites_scale[i].x
		= env->wall_sprites[env->sectors[parser->sectors_count]
		.ceiling_sprites.sprite[i]].size[0].x
		/ env->sectors[parser->sectors_count].ceiling_sprites.scale[i].x;
		env->sectors[parser->sectors_count].ceiling_sprites_scale[i].y
		= env->wall_sprites[env->sectors[parser->sectors_count]
		.ceiling_sprites.sprite[i]].size[0].y
		/ env->sectors[parser->sectors_count].ceiling_sprites.scale[i].y;
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
