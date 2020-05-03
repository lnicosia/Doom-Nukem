/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sectors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:07:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:07:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_sectors_init2(t_env *env, t_map_parser *parser)
{
	int		i;

	if (env->nb_sectors > 100000)
		return (ft_printf("nb_sectors can't exceed 100 000\n"));
	if (!(env->sectors = (t_sector *)ft_memalloc(sizeof(t_sector)
					* env->nb_sectors)))
		return (custom_error("Could not malloc sectors!"));
	i = 0;
	while (i < env->nb_sectors)
	{
		ft_bzero(&env->sectors[i], sizeof(t_sector));
		env->sectors[i].x_max = -2147483648;
		i++;
	}
	ft_strdel(&parser->line);
	return (0);
}

int		parse_sectors_init(t_env *env, t_map_parser *parser, char *line)
{
	if (*line != 'S')
		return (invalid_char("sectors number", "'S'", *line, parser));
	line++;
	if (!*line)
		return (missing_data("sectors number", parser));
	if (*line != ' ')
		return (invalid_char("sectors number",
					"space or a digit", *line, parser));
		line = skip_spaces(line);
	if (!*line)
		return (missing_data("sectors number", parser));
	if (valid_int(line, parser))
		return (ft_printf("Invalid int for nb_sectors\n"));
	env->nb_sectors = ft_atoi(line);
	env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
	line = skip_number(line);
	if (*line && *line == ' ')
		return (extra_data("sectors number declaration", parser));
	if (*line)
		return (invalid_char("sectors number", "a digit", *line, parser));
	if (env->nb_sectors < 1)
		return (custom_error("You need at least one sector"));
	return (parse_sectors_init2(env, parser));
}

int		init_sectors(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		parser->line_count++;
		line = parser->line;
		if (*line && *line != '#')
		{
			return (parse_sectors_init(env, parser, line));
		}
		else if (*line != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&parser->line);
	}
	return (0);
}
