/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_music.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:12:59 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/18 22:32:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int	parse_ambiant_data(char *line, t_map_parser *parser, t_env *env)
{
	if (*(line) != 'A')
		return (invalid_char("ambient music", "'A'", *(line), parser));
	line++;
	if (!(*(line)))
		return (missing_data("music number", parser));
	if (*(line) != ' ')
		return (invalid_char("music number", "space/digit", *(line), parser));
	line = skip_spaces(line);
	if (!(*(line)))
		return (missing_data("music number", parser));
	if (valid_int(line, parser))
		return (custom_error("Invalid int for music num\n"));
	env->sound.ambient_music = ft_atoi(line);
	line = skip_number(line);
	if (*(line) && *(line) == ' ')
		return (extra_data("ambient music number declaration", parser));
	if (*(line))
		return (invalid_char("music number", "a digit", *(line), parser));
	if (env->sound.ambient_music < 0 || env->sound.ambient_music >= NB_MUSICS)
		return (custom_error("Music number is invalid"));
	return (0);
}

int	parse_ambient_music(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		parser->line_count++;
		line = parser->line;
		if (*(line) && *(line) != '#')
		{
			if (parse_ambiant_data(line, parser, env))
				return (-1);
			ft_strdel(&(parser->line));
			return (0);
		}
		else if (*(line) != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&(parser->line));
	}
	return (0);
}

int	parse_fight_data(char *line, t_map_parser *parser, t_env *env)
{
	if (*(line) != 'F')
		return (invalid_char("fight music", "'F'", *(line), parser));
	line++;
	if (!*(line))
		return (missing_data("music number", parser));
	if (*(line) != ' ')
		return (invalid_char("music number", "space/digit", *(line), parser));
	line = skip_spaces(line);
	if (!*(line))
		return (missing_data("music number", parser));
	if (valid_int(line, parser))
		return (custom_error("Invalid int for music num\n"));
	env->sound.fight_music = ft_atoi(line);
	line = skip_number(line);
	if (*(line) && *(line) == ' ')
		return (extra_data("fight music number declaration", parser));
	if (*(line))
		return (invalid_char("music number", "a digit", *(line), parser));
	if (env->sound.fight_music < 0 || env->sound.fight_music >= NB_MUSICS)
		return (custom_error("Music number is invalid"));
	return (0);
}

int	parse_fight_music(t_env *env, t_map_parser *parser)
{
	char	*line;

	while ((parser->ret = get_next_line(parser->fd, &parser->line)))
	{
		parser->line_count++;
		line = parser->line;
		if (*(line) && *(line) != '#')
		{
			if (parse_fight_data(line, parser, env))
				return (-1);
			ft_strdel(&(parser->line));
			return (0);
		}
		else if (*(line) != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&(parser->line));
	}
	return (0);
}
