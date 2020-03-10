/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:05:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 14:27:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "env.h"

int		parse_player(t_env *env, t_map_parser *parser)
{
	while ((parser->ret = get_next_line(parser->fd, &(parser->tmp))))
	{
		parser->line_count++;
		parser->line = parser->tmp;
		if (*(parser->line) && *(parser->line) != '#')
		{
			if (valid_double(parser->line, parser))
				return (ft_printf("Invalid double for player pos.y\n"));
			env->player.pos.y = ft_atof(parser->line);
			env->player.starting_pos.y = ft_atof(parser->line);
			parser->line = skip_number(parser->line);
			if (*(parser->line) && *(parser->line) != ' ')
				return (invalid_char("player y",
							"space or a digit", *(parser->line), parser));
			if (!*(parser->line))
				return (missing_data("player x and angle", parser));
			parser->line = skip_spaces(parser->line);
			if (!*(parser->line))
				return (missing_data("player x and angle", parser));
			if (valid_double(parser->line, parser))
				return (ft_printf("Invalid double for player pos.x\n"));
			env->player.pos.x = ft_atof(parser->line);
			env->player.starting_pos.x = ft_atof(parser->line);
			parser->line = skip_number(parser->line);
			if (*(parser->line) && *(parser->line) != ' ')
				return (invalid_char("player x",
							"space or a digit", *(parser->line), parser));
			if (!*(parser->line))
				return (missing_data("player angle", parser));

			parser->line = skip_spaces(parser->line);
			if (!*(parser->line))
				return (missing_data("player angle", parser));
			if (valid_double(parser->line, parser))
				return (ft_printf("Invalid double for player angle\n"));
			env->player.init_data.camera.angle = ft_atof(parser->line);
			//* CONVERT_RADIANS;
			env->player.camera.angle = env->player.init_data.camera.angle
			* CONVERT_RADIANS;
			env->player.camera.angle_cos =
			cos(env->player.camera.angle);
			env->player.camera.angle_sin =
			sin(env->player.camera.angle);
			env->player.camera.perp_cos =
			cos(env->player.camera.angle - M_PI / 2);
			env->player.camera.perp_sin =
			sin(env->player.camera.angle - M_PI / 2);
			env->editor.player_exist = 1;
			parser->line = skip_number(parser->line);
			if (*(parser->line) && *(parser->line) == ' ')
				return (extra_data("player declaration", parser));
			if (*(parser->line))
				return (invalid_char("player angle",
							"a digit", *(parser->line), parser));
			parser->line = skip_spaces(parser->line);
			if ((env->player.sector = get_sector_no_z(env,
							env->player.pos)) == -1)
				return (custom_error_with_line("Player is not in any sector",
							parser));
			if (!env->sectors[env->player.sector].gravity)
				env->player.state.fly = 1;
			env->player.highest_sect = env->player.sector;
			env->player.camera.pos = env->player.pos;
			env->player.camera.pos.z = env->player.pos.z + 8;
		}
		else if (parser->line[0] != '#')
			return (missing_data("player data", parser));
		ft_strdel(&(parser->tmp));
		parser->line = NULL;
	}
	return (0);
}
