/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:13:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/17 10:22:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int		init_objects(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (line[0] == 'O' && line[1] == ' '
				&& line[2] >= '0' && line[2] <= '9')
		{
			line++;
			line = skip_spaces(line);
			if (!*line)
				return (ft_printf("Please declare how many objects "
							"there are\n"));
			env->nb_objects = ft_atoi(line);
			line = skip_number(line);
			if (*line)
				return (ft_printf("Too much data in objects number "
							"declaration (line %d)\n", parser->line_count));
			if (env->nb_objects < 0)
				return (ft_printf("You can not declare less than 0 objects\n"));
			if (env->nb_objects
					&& !(env->objects = (t_object*)malloc(sizeof(t_object)
							* (env->nb_objects))))
				return (ft_printf("Could not malloc objectss!\n", env));
			ft_strdel(&tmp);
			return (0);
		}
		else if (line[0] != '#')
			return (ft_printf("Wrong format of objects number "
						"declaration (line %d)\nEx: \"O 127\" (> 2)\n",
						parser->line_count));
		ft_strdel(&tmp);
	}
	return (0);
}
