/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:48:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map_parser.h"

int		valid_sprite3(char *line, t_map_parser *parser)
{
	if (*line != ' ')
		return (invalid_char("after sprite x scale", "space(s)",
		*line, parser));
		line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite y scale", parser));
	if (valid_double(line, parser))
		return (invalid_char("before sprite y scale", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("']' after sprite y scale", parser));
	if (*line != ']')
		return (invalid_char("after sprite y scale", "']'",
			*line, parser));
		return (0);
}

int		valid_sprite2(char *line, t_map_parser *parser)
{
	if (*line != ' ')
		return (invalid_char("after sprite x pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite y pos and scale", parser));
	if (valid_double(line, parser))
		return (invalid_char("before sprite y pos", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("sprite scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite y pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprite scale", parser));
	if (valid_double(line, parser))
		return (invalid_char("before sprite x scale", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("sprite y scale", parser));
	return (valid_sprite3(line, parser));
}

/*
**	Checks if a sprite is valid
*/

int		valid_sprite(char *line, t_map_parser *parser)
{
	if (*line != '[')
		return (invalid_char("in sector sprites", "'['", *line, parser));
	line++;
	if (!*line)
		return (missing_data("sprite number", parser));
	if (valid_int(line, parser))
		return (invalid_char("before sprite number", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("sprite pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after sprite number", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("sprites pos and scale", parser));
	if (valid_double(line, parser))
		return (invalid_char("before sprite x pos", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("sprite y pos and scale", parser));
	return (valid_sprite2(line, parser));
}
