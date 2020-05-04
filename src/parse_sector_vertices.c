/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:18:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:18:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "parser.h"

int		parse_sector_vertices2(t_env *env, char **line, t_map_parser *parser)
{
	env->sectors[parser->sectors_count].
	vertices[parser->sector_vertices_count] =
	env->sectors[parser->sectors_count].vertices[0];
	if (check_vertices_uniqueness(env->sectors[parser->sectors_count]))
		return (sector_error("has duplicate vertices", parser->sectors_count,
			parser));
		if (check_sector_duplicate(env, env->sectors[parser->sectors_count],
				parser->sectors_count))
		return (sector_error("already exists", parser->sectors_count, parser));
	(*line)++;
	if (!**line)
		return (missing_data("neighbors, textures and light", parser));
	if (**line != ' ')
		return (invalid_char("after vertices data", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_vertices(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (i < parser->sector_vertices_count)
	{
		env->sectors[parser->sectors_count].vertices[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].vertices[i] < 0 || env->
				sectors[parser->sectors_count].vertices[i] >= env->nb_vertices)
			return (custom_error(
				"[Line %d] Vertex \'%d\' in sector %d does not exist\n",
				parser->line_count,
				env->sectors[parser->sectors_count].vertices[i],
				parser->sectors_count));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		i++;
	}
	return (parse_sector_vertices2(env, line, parser));
}
