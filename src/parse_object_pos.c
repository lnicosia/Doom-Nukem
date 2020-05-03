/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:11:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:46:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		parse_object_pos4(t_env *env, t_map_parser *parser)
{
	if (env->objects[parser->objects_count].sector >= 0)
	{
		env->objects[parser->objects_count].brightness =
			env->sectors[env->objects[parser->objects_count].sector].brightness;
		env->objects[parser->objects_count].light_color =
			env->sectors[env->objects[parser->objects_count].sector].
			light_color;
		env->objects[parser->objects_count].intensity =
			env->sectors[env->objects[parser->objects_count].sector].intensity;
	}
	else
	{
		env->objects[parser->objects_count].brightness = 0;
		env->objects[parser->objects_count].light_color = 0;
		env->objects[parser->objects_count].intensity = 0;
	}
	return (0);
}

int		parse_object_pos3(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line || **line == ']')
		return (missing_data("object angle", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for object %d angle\n",
		parser->objects_count));
		env->objects[parser->objects_count].angle = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after object angle", parser));
	if (**line != ']')
		return (invalid_char("after object angle", "a digit or ']'",
			**line, parser));
		(*line)++;
	if (!**line)
		return (missing_data("object sprite and scale", parser));
	if (**line != ' ')
		return (invalid_char("after object angle", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	env->objects[parser->objects_count].sector = get_sector_no_z(env,
			new_v3(env->objects[parser->objects_count].pos.x,
				env->objects[parser->objects_count].pos.y,
				env->objects[parser->objects_count].pos.z));
	return (parse_object_pos4(env, parser));
}

int		parse_object_pos2(t_env *env, char **line, t_map_parser *parser)
{
	env->objects[parser->objects_count].pos.x = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object z and angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object x", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("object z and angle", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for object %d pos.z\n",
			parser->objects_count));
		env->objects[parser->objects_count].pos.z = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object z", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (parse_object_pos3(env, line, parser));
}

int		parse_object_pos(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before object y", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("object y, x, z and angle", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for object %d pos.y\n",
		parser->objects_count));
		env->objects[parser->objects_count].pos.y = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object x, z and angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object y", "a digit or space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("object x, z and angle", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for object %d pos.x\n",
		parser->objects_count));
		return (parse_object_pos2(env, line, parser));
}
