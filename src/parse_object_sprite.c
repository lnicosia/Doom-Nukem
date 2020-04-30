/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:12:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:12:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		parse_object_sprite2(t_env *env, char **line, t_map_parser *parser)
{
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("object scale", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for object scale\n"));
	env->objects[parser->objects_count].scale = ft_atof(*line);
	if (env->objects[parser->objects_count].scale < 0.1
	|| env->objects[parser->objects_count].scale > 100)
		return (custom_error_with_line(
			"Object scale must be between 0.1 and 100", parser));
		*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after object scale", parser));
	if (**line != ']')
		return (invalid_char("after object scale", "a digit or ']'",
			**line, parser));
		(*line)++;
	if (**line)
		return (extra_data("object scale", parser));
	return (0);
}

int		parse_object_sprite(t_env *env, char **line, t_map_parser *parser)
{
	int		parse;

	if (**line != '[')
		return (invalid_char("before object sprite", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("object sprite and scale", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for object texture\n"));
	parse = ft_atoi(*line);
	if (parse < 0 || parse >= MAX_OBJECTS)
		return (custom_error_with_line("Invalid object sprite texture",
		parser));
		env->objects[parser->objects_count].sprite =
	env->objects_main_sprites[parse];
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object scale", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object sprite", "a digit or space(s)",
			**line, parser));
		return (parse_object_sprite2(env, line, parser));
}
