/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 12:07:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		wall_sprite_parser0(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != ' ')
		return (invalid_char("before sector number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != '(')
		return (invalid_char("before sector number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sector, wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector number", "a digit", **line,
		parser));
	eparser->trigger_sector = ft_atoi(*line);
	if (eparser->trigger_sector < 0
		|| eparser->trigger_sector >= env->nb_sectors)
		return (custom_error_with_line("Invalid sector index", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall and sprite", parser));
	if (**line != ' ')
		return (invalid_char("after sector number", "a space", **line,
		parser));
		(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before wall number", "a digit", **line,
		parser));
	eparser->trigger_wall = ft_atoi(*line);
	if (eparser->trigger_wall < 0
		|| eparser->trigger_wall >= env->sectors[eparser->trigger_sector].nb_vertices)
		return (custom_error_with_line("Invalid wall index", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sprite number", parser));
	if (**line != ' ')
		return (invalid_char("after sprite number", "a space", **line,
		parser));
		(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sprite number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sprite number", "a digit", **line,
		parser));
	eparser->trigger_sprite = ft_atoi(*line);
	if (eparser->trigger_sprite < 0
		|| eparser->trigger_sprite >= env->sectors[eparser->trigger_sector]
		.wall_sprites[eparser->trigger_wall].nb_sprites)
		return (custom_error_with_line("Invalid sprite index", parser));
		*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after sprite index", "')'", **line, parser));
	(*line)++;
	return (0);
}

int		wall_sprite_parser(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != ' ')
		return (invalid_char("before sector number", "a space",
		**line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("sector data", parser));
	if (**line != '(')
		return (invalid_char("before sector number", "'('", **line, parser));
	(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sector, wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector number", "a digit", **line,
		parser));
	eparser->target_sector = ft_atoi(*line);
	if (eparser->target_sector < 0
		|| eparser->target_sector >= env->nb_sectors)
		return (custom_error_with_line("Invalid sector index", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall and sprite", parser));
	if (**line != ' ')
		return (invalid_char("after sector number", "a space", **line,
		parser));
		(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("wall and sprite", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before wall number", "a digit", **line,
		parser));
	eparser->target_wall = ft_atoi(*line);
	if (eparser->target_wall < 0
		|| eparser->target_wall >= env->sectors[eparser->target_sector].nb_vertices)
		return (custom_error_with_line("Invalid wall index", parser));
		*line = skip_number(*line);
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sprite number", parser));
	if (**line != ' ')
		return (invalid_char("after sprite number", "a space", **line,
		parser));
		(*line)++;
	if (!**line || **line == ']' || **line == ')')
		return (missing_data("sprite number", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sprite number", "a digit", **line,
		parser));
	eparser->target_sprite = ft_atoi(*line);
	if (eparser->target_sprite < 0
		|| eparser->target_sprite >= env->sectors[eparser->target_sector]
		.wall_sprites[eparser->target_wall].nb_sprites)
		return (custom_error_with_line("Invalid sprite index", parser));
		*line = skip_number(*line);
	if (!**line || **line != ')')
		return (invalid_char("after sprite index", "')'", **line, parser));
	(*line)++;
	return (0);
}
