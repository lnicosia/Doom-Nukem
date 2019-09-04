/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/30 14:59:34 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

static int	parse_object_sprite(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before object sprite", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("object sprite and scale", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before object sprite", "a digit",
					**line, parser));
	env->objects[parser->objects_count].sprite = ft_atoi(*line);
	if (env->objects[parser->objects_count].sprite < 0
			|| env->objects[parser->objects_count].sprite >= MAX_SPRITES)
		return (custom_error_with_line("Invalid sprite texture", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object scale", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object sprite", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("object scale", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before object scale", "a digit or space(s)",
					**line, parser));
	env->objects[parser->objects_count].scale = ft_atof(*line);
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

static int	parse_object_pos(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before object y", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("object y, x, z and angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before object y", "a digit", **line, parser));
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
	if (valid_number(*line, parser))
		return (invalid_char("before object x", "a digit", **line, parser));
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
	if (valid_number(*line, parser))
		return (invalid_char("before object z", "a digit or space(s)",
					**line, parser));
	env->objects[parser->objects_count].pos.z = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("object angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after object z", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("object angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before object angle", "a digit or space(s)",
					**line, parser));
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
	env->objects[parser->objects_count].sector = get_sector_global(env,
			new_v3(env->objects[parser->objects_count].pos.x,
				env->objects[parser->objects_count].pos.y,
				env->objects[parser->objects_count].pos.z));
	env->objects[parser->objects_count].light =
		env->sectors[env->objects[parser->objects_count].sector].light;
	return (0);
}

static int	parse_object(t_env *env, char *line, t_map_parser *parser)
{
	if (parse_object_pos(env, &line, parser))
		return (-1);
		//return (custom_error("Error while parsing object pos"));
	if (parse_object_sprite(env, &line, parser))
		return (-1);
		//return (custom_error("Error while parsing object pos"));
	return (0);
}

int			parse_objects(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while (parser->objects_count < env->nb_objects
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		tmp = line;
		if (*tmp)
		{
			if (parse_object(env, tmp, parser))
				return (-1);
			parser->objects_count++;
		}
		else
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] You must still declare %d objects\n",
					parser->line_count,
					env->nb_objects - parser->objects_count);
			return (-1);
		}
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (*line)
			return (custom_error_with_line("Must be an empty line "
						"(every object has been declared)\n",
						parser));
		ft_strdel(&line);
	}
	else
		return (missing_data("enemies and player data", parser));
	return (0);
}
