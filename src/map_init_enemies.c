/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:19:25 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/22 11:41:33 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		init_enemies(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (*line != 'E')
				return (invalid_char("at enemies number", "'E'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("at enemies number", parser));
			if (*line != ' ')
				return (invalid_char("at enemies number", "space of a digit",
							*line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("before enemies number", parser));
			if (valid_number(line,parser) == WRONG_CHAR)
				return (invalid_char("before enemies number", "space of a digit",
							*line, parser));
			env->nb_enemies = ft_atoi(line);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("enemies number", parser));
			if (*line)
				return (invalid_char("after enemies number",
							"a digit or the end of the line",
							*line, parser));
			if (env->nb_enemies < 0)
				return (custom_error("You can not declare less than 0 enemies"));
			if (env->nb_enemies
					&& !(env->enemies = (t_enemies*)malloc(sizeof(t_enemies)
							* (env->nb_enemies))))
				return (ft_perror("Could not malloc enemies:"));
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("enemies number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}
