/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:48:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:54:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		valid_texture3(char *line, t_map_parser *parser)
{
	if (!*line)
		return (missing_data("texture y scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture x scale", "space(s)",
		*line, parser));
		line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture y scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture y scale", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("']' after texture y scale", parser));
	if (*line != ']')
		return (invalid_char("after texture y scale", "']'",
			*line, parser));
		return (0);
}

int		valid_texture2(char *line, t_map_parser *parser)
{
	if (*line != ' ')
		return (invalid_char("after texture x pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture y pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture y pos", "a digit", *line, parser));
	line = skip_number(line);
	if (!*line)
		return (missing_data("texture scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture y pos", "space(s)", *line, parser));
	line = skip_spaces(line);
	if (!*line)
		return (missing_data("texture scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture x scale", "a digit",
			*line, parser));
		line = skip_number(line);
	return (valid_texture3(line, parser));
}

/*
**	Checks if a texture is valid
*/

int		valid_texture(char *line, t_map_parser *parser)
{
	if (*line != '[')
		return (invalid_char("in sector texture", "'['", *line, parser));
	line++;
	if (!*line)
		return (missing_data("texture number", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture number", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("texture pos and scale", parser));
	if (*line != ' ')
		return (invalid_char("after texture number", "space(s)",
		*line, parser));
		line = skip_spaces(line);
	if (!*line)
		return (missing_data("textures pos and scale", parser));
	if (valid_number(line, parser))
		return (invalid_char("before texture x pos", "a digit",
			*line, parser));
		line = skip_number(line);
	if (!*line)
		return (missing_data("texture y pos and scale", parser));
	return (valid_texture2(line, parser));
}
