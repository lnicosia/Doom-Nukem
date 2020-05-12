/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:14:16 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/12 11:19:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "init.h"
#include "parser.h"

int		parse_sector2(t_env *env, char *line, t_map_parser *parser)
{
	if (parse_sector_vertices(env, &line, parser))
		return (-1);
	if (parse_sector_neighbors(env, &line, parser))
		return (-1);
	if (parse_sector_portals(env, &line, parser))
		return (-1);
	if (parse_sector_textures(env, &line, parser))
		return (-1);
	if (parse_sector_wall_sprites(env, &line, parser))
		return (-1);
	if (parse_sector_general(env, &line, parser))
		return (-1);
	return (0);
}

int		parse_sector(t_env *env, char *line, t_map_parser *parser)
{
	parser->sector_vertices_count = 0;
	parser->sector_neighbors_count = 0;
	parser->sector_textures_count = 0;
	parser->sector_sprites_count = 0;
	env->sectors[parser->sectors_count].num = parser->sectors_count;
	env->sectors[parser->sectors_count].gravity = -9.81;
	if (parse_floor(env, &line, parser))
		return (-1);
	if (parse_floor_sprites(env, &line, parser))
		return (-1);
	if (parse_ceiling(env, &line, parser))
		return (-1);
	if (parse_ceiling_sprites(env, &line, parser))
		return (-1);
	if (env->sectors[parser->sectors_count].ceiling
			< env->sectors[parser->sectors_count].floor)
		return (-1);
	if (init_sector_data(env, line, parser))
		return (-1);
	line++;
	return (parse_sector2(env, line, parser));
}

int		parse_sectors2(t_map_parser *parser)
{
	if ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		parser->line_count++;
		if (*parser->line)
			return (custom_error_with_line("Must be an empty line "
				"(every sector has been declared)", parser));
			ft_strdel(&parser->line);
	}
	else
		return (missing_data("objects, enemies, events and player data",
			parser));
			return (0);
}

int		parse_sectors(t_env *env, t_map_parser *parser)
{
	char	*line;

	while (parser->sectors_count < env->nb_sectors
			&& (parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		line = parser->line;
		parser->line_count++;
		if (*line)
		{
			if (parse_sector(env, line, parser))
				return (-1);
			parser->sectors_count++;
		}
		else
		{
			return (custom_error(
				"[Line %d] You must still declare %d sector(s)\n",
				parser->line_count, env->nb_sectors - parser->sectors_count));
			return (-1);
		}
		ft_strdel(&parser->line);
	}
	return (parse_sectors2(parser));
}
