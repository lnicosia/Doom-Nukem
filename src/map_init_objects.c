/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:13:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/20 14:34:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		init_objects(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (*line != 'O')
				return (invalid_char("at objects number", "'O'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("at objects number", parser));
			if (*line != ' ')
				return (invalid_char("at objects number", "space of a digit",
							*line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("before objects number", parser));
			if (valid_number(line,parser) == WRONG_CHAR)
				return (invalid_char("before objects number", "space of a digit",
							*line, parser));
			env->nb_objects = ft_atoi(line);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("objects number", parser));
			if (*line)
				return (invalid_char("adter objects number",
							"a digit or the end of the line",
							*line, parser));
			if (env->nb_objects < 0)
				return (custom_error("You can not declare less than 0 objects"));
			if (env->nb_objects
					&& !(env->objects = (t_object*)malloc(sizeof(t_object)
							* (env->nb_objects))))
				return (ft_perror("Could not malloc objects:"));
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("objects number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}
