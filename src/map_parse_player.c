/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:05:08 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/19 14:54:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int		parse_player(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (valid_number(line, parser) == WRONG_CHAR)
				return (invalid_char("player y",
							"a digit", *line, parser));
			env->player.pos.y = ft_atof(line);
			line = skip_number(line);
			if (*line && *line != ' ')
				return (invalid_char("player y",
							"space or a digit", *line, parser));
			if (!*line)
				return (missing_data("player x and angle", parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("player x and angle", parser));
			if (valid_number(line, parser) == WRONG_CHAR)
				return (invalid_char("player x",
							"space or a digit", *line, parser));
			env->player.pos.x = ft_atof(line);
			line = skip_number(line);
			if (*line && *line != ' ')
				return (invalid_char("player x",
							"space or a digit", *line, parser));
			if (!*line)
				return (missing_data("player angle", parser));

			line = skip_spaces(line);
			if (!*line)
				return (missing_data("player angle", parser));
			if (valid_number(line, parser) == WRONG_CHAR)
				return (invalid_char("player angle",
							"a digit", *line, parser));
			env->player.camera.angle = (ft_atof(line) + 0.00001) * CONVERT_RADIANS;
			env->player.camera.angle_cos = cos(env->player.camera.angle);
			env->player.camera.angle_sin = sin(env->player.camera.angle);
			env->player.camera.perp_cos = cos(env->player.camera.angle - M_PI / 2);
			env->player.camera.perp_sin = sin(env->player.camera.angle - M_PI / 2);
			env->editor.new_player = 1;
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("player declaration", parser));
			if (*line)
				return (invalid_char("player angle",
							"a digit", *line, parser));
			line = skip_spaces(line);
			if ((env->player.sector = get_sector_no_z(env,
							env->player.pos)) == -1)
				return (custom_error_with_line("Player is not in any sector",
							parser));
			env->player.camera.pos = env->player.pos;
			env->player.camera.pos.z = env->player.pos.z + 8;
		}
		else if (line[0] != '#')
			return (missing_data("player data", parser));
		ft_strdel(&tmp);
	}
	return (0);
}
