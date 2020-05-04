/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:05:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:11:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <math.h>

int		parse_player_line3(t_env *env, t_map_parser *parser)
{
	if ((env->player.sector = get_sector_no_z(env, env->player.pos)) == -1)
		return (custom_error_with_line("Player is not in any sector", parser));
	update_player_z(env);
	env->player.starting_pos.z = env->player.pos.z;
	if (!env->sectors[env->player.sector].gravity)
		env->player.state.fly = 1;
	env->player.highest_sect = env->player.sector;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = env->player.pos.z + 8;
	return (0);
}

int		parse_player_line2(t_env *env, t_map_parser *parser, char *line)
{
	line = skip_spaces(line);
	if (!*(line))
		return (missing_data("player angle", parser));
	if (valid_double(line, parser))
		return (custom_error("Invalid double for player angle\n"));
	env->player.init_data.camera.angle = ft_atof(line);
	env->player.camera.angle = env->player.init_data.camera.angle
	* CONVERT_RADIANS;
	env->player.camera.angle_cos = cos(env->player.camera.angle);
	env->player.camera.angle_sin = sin(env->player.camera.angle);
	env->player.camera.perp_cos = cos(env->player.camera.angle - M_PI / 2);
	env->player.camera.perp_sin = sin(env->player.camera.angle - M_PI / 2);
	env->editor.player_exist = 1;
	line = skip_number(line);
	if (*(line) && *(line) == ' ')
		return (extra_data("player declaration", parser));
	if (*(line))
		return (invalid_char("player angle", "a digit", *(line), parser));
	line = skip_spaces(line);
	return (parse_player_line3(env, parser));
}

int		parse_player_line(t_env *env, t_map_parser *parser, char *line)
{
	if (valid_double(line, parser))
		return (custom_error("Invalid double for player pos.y\n"));
	env->player.pos.y = ft_atof(line);
	env->player.starting_pos.y = ft_atof(line);
	line = skip_number(line);
	if (*(line) && *(line) != ' ')
		return (invalid_char("player y", "space or a digit", *(line), parser));
	if (!*(line))
		return (missing_data("player x and angle", parser));
	line = skip_spaces(line);
	if (!*(line))
		return (missing_data("player x and angle", parser));
	if (valid_double(line, parser))
		return (custom_error("Invalid double for player pos.x\n"));
	env->player.pos.x = ft_atof(line);
	env->player.starting_pos.x = ft_atof(line);
	line = skip_number(line);
	if (*(line) && *(line) != ' ')
		return (invalid_char("player x", "space or a digit", *(line), parser));
	if (!*(line))
		return (missing_data("player angle", parser));
	return (parse_player_line2(env, parser, line));
}

int		parse_player(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &(parser->tmp))))
	{
		parser->line_count++;
		line = parser->tmp;
		if (*(line) && *(line) != '#')
		{
			if (parse_player_line(env, parser, line))
				return (-1);
		}
		else if (line[0] != '#')
			return (missing_data("player data", parser));
		ft_strdel(&(parser->tmp));
	}
	return (0);
}
