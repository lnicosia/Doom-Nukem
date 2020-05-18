/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 21:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		parse_object(t_env *env, char *line, t_map_parser *parser)
{
	env->objects[parser->objects_count].num = parser->objects_count;
	if (parse_object_pos(env, &line, parser))
		return (-1);
	if (parse_object_sprite(env, &line, parser))
		return (-1);
	return (0);
}

int		parse_objects2(t_env *env, t_map_parser *parser)
{
	if ((parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		if (*(parser->line))
			return (custom_error_with_line("Must be an empty line "
				"(every object has been declared)\n", parser));
			ft_strdel(&(parser->line));
	}
	else
		return (missing_data("enemies, events and player data", parser));
	if (!(env->player.colliding_objects = (int*)ft_memalloc(sizeof(int)
		* env->nb_objects)))
		return (ft_perror("Could not malloc player colliding objects"));
	return (0);
}

int		parse_objects(t_env *env, t_map_parser *parser)
{
	char	*line;

	while (parser->objects_count < env->nb_objects
			&& (parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		line = parser->line;
		if (*line)
		{
			if (parse_object(env, line, parser))
				return (-1);
			parser->objects_count++;
		}
		else
			return (custom_error("[Line %d] still %d objects needed\n",
				parser->line_count, env->nb_objects - parser->objects_count));
		ft_strdel(&(parser->line));
	}
	return (parse_objects2(env, parser));
}
