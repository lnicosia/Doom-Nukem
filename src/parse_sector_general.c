/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector_general.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:15:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:15:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "env.h"

int		parse_sector_general4(char **line, t_map_parser *parser)
{
	if (**line != ']')
		return (invalid_char("after sector gravity", "']'", **line, parser));
	(*line)++;
	if (**line != '\0')
		return (extra_data(*line, parser));
	return (0);
}

int		parse_sector_general3(t_env *env, char **line, t_map_parser *parser)
{
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("sector gravity", parser));
	if (**line && **line != ' ')
		return (invalid_char("after sector light color intensity",
		"a digit or space(s)", **line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("sector gravity", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for gravity\n"));
	env->sectors[parser->sectors_count].gravity = ft_atof(*line);
	if (env->sectors[parser->sectors_count].gravity
		&& (env->sectors[parser->sectors_count].gravity < -10 ||
		env->sectors[parser->sectors_count].gravity > -1))
		return (custom_error_with_line("Gravity must be 0 or"
		" between -1 and -10", parser));
		*line = skip_number(*line);
	if (!**line)
		return (missing_data("closing ']' brace after sector gravity", parser));
	return (parse_sector_general4(line, parser));
}

int		parse_sector_general2(t_env *env, char **line, t_map_parser *parser)
{
	if (valid_hexa(*line, parser))
		return (invalid_char("before light color hue",
			"an hexa digit or space(s)", **line, parser));
		env->sectors[parser->sectors_count].light_color = ft_atoi_base(*line,
	"0123456789ABCDEF");
	*line = skip_hexa(*line);
	if (!**line || **line == ']')
		return (missing_data("light color intensity and sector gravity",
		parser));
		if (**line && **line != ' ')
		return (invalid_char("after light color hue", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("light color intensity and sector gravity",
		parser));
		if (valid_int(*line, parser))
		return (ft_printf("Invalid int for light intensity\n"));
	env->sectors[parser->sectors_count].intensity = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].intensity < -255
		|| env->sectors[parser->sectors_count].intensity > 255)
		return (custom_error("Light color intensity must be between -255"
		" and 255"));
	return (parse_sector_general3(env, line, parser));
}

int		parse_sector_general(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before sector light data", "'['", **line,
		parser));
		(*line)++;
	if (!**line)
		return (missing_data("sector general data", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for brightness\n"));
	env->sectors[parser->sectors_count].brightness = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].brightness < -255 ||
			env->sectors[parser->sectors_count].brightness > 255)
		return (custom_error("Light brightness must be between -255 and 255"));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("light color hue, light color intensity and "
		"sector gravity", parser));
		if (**line && **line != ' ')
		return (invalid_char("after light brightness", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("light color hue, light color intensity and "
		"sector gravity", parser));
		return (parse_sector_general2(env, line, parser));
}
