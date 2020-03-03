/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_music.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:12:59 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 14:51:12 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_ambient_music(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (*line != 'A')
				return (invalid_char("ambient music", "'A'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("music number", parser));
			if (*line != ' ')
				return (invalid_char("music number",
							"space or a digit", *line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("music number", parser));
			if (valid_int(line, parser))
				return (ft_printf("Invalid int for music num\n"));
			env->sound.ambient_music = ft_atoi(line);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("ambient music number declaration", parser));
			if (*line)
				return (invalid_char("music number",
							"a digit", *line, parser));
			if (env->sound.ambient_music < 0
				|| env->sound.ambient_music >= NB_MUSICS)
				return (custom_error("Music number is invalid"));
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}

int		parse_fight_music(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (*line != 'F')
				return (invalid_char("fight music", "'F'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("music number", parser));
			if (*line != ' ')
				return (invalid_char("music number",
							"space or a digit", *line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("music number", parser));
			if (valid_int(line, parser))
				return (ft_printf("Invalid int for music num\n"));
			env->sound.fight_music = ft_atoi(line);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("fight music number declaration", parser));
			if (*line)
				return (invalid_char("music number",
							"a digit", *line, parser));
			if (env->sound.fight_music < 0
				|| env->sound.fight_music >= NB_MUSICS)
				return (custom_error("Music number is invalid"));
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}