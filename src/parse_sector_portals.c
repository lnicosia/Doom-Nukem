/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector_portals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:16:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:16:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "env.h"

int		parse_current_portal(t_env *env, char **line, t_map_parser *parser,
int i)
{
	env->sectors[parser->sectors_count].portals[i] = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].portals[i] < 0 || env->
			sectors[parser->sectors_count].portals[i] > 1)
	{
		ft_dprintf(STDERR_FILENO,
			"[Line %d] Portal value should be 1 or 0 instead of"
			" \'%d\' in sector %d\n", parser->line_count,
			env->sectors[parser->sectors_count].portals[i],
			parser->sectors_count);
		return (-1);
	}
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_portals2(char **line, t_map_parser *parser)
{
	(*line)++;
	if (!**line)
		return (missing_data("texures and light", parser));
	if (**line != ' ')
		return (invalid_char("after portals data", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_portals(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("neighors, portals, textures and light", parser));
	if (**line != '(')
		return (invalid_char("before sector portals", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_portals_count = count_portals(*line, parser)) == -1)
		return (custom_error("Error while counting portals"));
	if (parser->sector_portals_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more portals",
			parser->sectors_count, parser));
		if (parser->sector_portals_count > parser->sector_vertices_count)
		return (sector_error("has too much portals",
			parser->sectors_count, parser));
		i = 0;
	while (i < parser->sector_portals_count)
	{
		if (parse_current_portal(env, line, parser, i))
			return (-1);
		i++;
	}
	return (parse_sector_portals2(line, parser));
}
