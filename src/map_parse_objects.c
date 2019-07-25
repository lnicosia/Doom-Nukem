/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 15:02:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

static int	parse_object_sprite(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (ft_printf("Invalid character before sprite declaration (line %d)\n",
					parser->line_count));
	(*line)++;
	if (valid_number(*line, parser))
		return (ft_printf("Missing sprite value (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].sprite = ft_atoi(*line);
	if (env->objects[parser->objects_count].sprite < 0
			|| env->objects[parser->objects_count].sprite >= MAX_SPRITES)
		return (ft_printf("Invalid sprite texture (line %d)\n", parser->line_count));
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_number(*line, parser))
		return (ft_printf("Missing scale value (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].scale = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (**line != ']' &&  **(line + 1) != ' ')
		return (ft_printf("Invalid character after sprite declaration (line %d)\n",
					parser->line_count));
	*line += 2;
	return (0);
}

static int	parse_object_pos(t_env *env, char **line, t_map_parser *parser)
{
	if (valid_number(*line, parser))
		return (ft_printf("Missing x value (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].pos.x = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_number(*line, parser))
		return (ft_printf("Missing y value (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].pos.y = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_number(*line, parser))
		return (ft_printf("Missing z value (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].pos.z = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (valid_number(*line, parser))
		return (ft_printf("Missing angle (line %d)\n", parser->line_count));
	env->objects[parser->objects_count].angle = ft_atof(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	env->objects[parser->objects_count].sector = get_sector_global(env,
			new_v2(env->objects[parser->objects_count].pos.x,
				env->objects[parser->objects_count].pos.y));
	env->objects[parser->objects_count].light =
		env->sectors[env->objects[parser->objects_count].sector].light;
	if (**line != ']' &&  **(line + 1) != ' ')
		return (ft_printf("Invalid character after pos declaration (line %d)\n",
					parser->line_count));
	*line += 2;
	return (0);
}

static int	parse_object(t_env *env, char *line, t_map_parser *parser)
{
	if (parse_object_pos(env, &line, parser))
		return (ft_printf("Error while parsing object pos\n"));
	if (parse_object_sprite(env, &line, parser))
		return (ft_printf("Error while parsing object pos\n"));
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
		if (tmp[0] == '[')
		{
			tmp++;
			if (parse_object(env, tmp, parser))
				return (ft_printf("Error while parsing object %d (line %d)\n",
							parser->objects_count, parser->line_count));
			parser->objects_count++;
		}
		else if (tmp[0] == '\0' && parser->objects_count < env->nb_objects)
			return (ft_printf("You must still declare %d objects (line %d)\n",
						env->nb_objects - parser->objects_count,
						parser->line_count));
		else if (tmp[0] != '#')
			return (ft_printf("Invalid character at line %d\n",
						parser->line_count));
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (line[0] != '\0')
			return (ft_printf("Line %d must be an empty line "
						"(every object has been declared)\n",
						parser->line_count));
		ft_strdel(&line);
	}
	else
		return (ft_printf("File ended at objects declaration\n"));
	return (0);
	/*env->objects[0].sprite = 0;
	env->objects[0].pickable = 0;
	env->objects[0].solid = 0;
	env->objects[0].pos.x = 5;
	env->objects[0].pos.y = 5;
	env->objects[0].pos.z = 0;
	env->objects[0].scale = 60;
	env->objects[0].sector = 0;

	env->objects[1].sprite = 1;
	env->objects[1].pickable = 0;
	env->objects[1].solid = 0;
	env->objects[1].pos.x = 20;
	env->objects[1].pos.y = 10;
	env->objects[1].pos.z = 6;
	env->objects[1].scale = 60;
	env->objects[1].sector = 0;
	env->objects[1].angle = 90;

	env->objects[2].sprite = 1;
	env->objects[2].pickable = 0;
	env->objects[2].solid = 0;
	env->objects[2].pos.x = 10;
	env->objects[2].pos.y = 20;
	env->objects[2].pos.z = 6;
	env->objects[2].scale = 60;
	env->objects[2].sector = 0;
	env->objects[2].angle = -90;*/
	return (0);
}
