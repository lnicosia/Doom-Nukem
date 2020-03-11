/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_music.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:12:59 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/04 18:59:20 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_ambient_music(t_env *env, t_map_parser *parser)
{
	while ((parser->ret = get_next_line(parser->fd, &(parser->tmp))))
	{
		parser->line_count++;
		parser->line = parser->tmp;
		if (*(parser->line) && *(parser->line) != '#')
		{
			if (*(parser->line) != 'A')
				return (invalid_char("ambient music", "'A'", *(parser->line), parser));
			parser->line++;
			if (!(*(parser->line)))
				return (missing_data("music number", parser));
			if (*(parser->line) != ' ')
				return (invalid_char("music number",
							"space or a digit", *(parser->line), parser));
			parser->line = skip_spaces(parser->line);
			if (!(*(parser->line)))
				return (missing_data("music number", parser));
			if (valid_int(parser->line, parser))
				return (ft_printf("Invalid int for music num\n"));
			env->sound.ambient_music = ft_atoi(parser->line);
			parser->line = skip_number(parser->line);
			if (*(parser->line) && *(parser->line) == ' ')
				return (extra_data("ambient music number declaration", parser));
			if (*(parser->line))
				return (invalid_char("music number",
							"a digit", *(parser->line), parser));
			if (env->sound.ambient_music < 0
				|| env->sound.ambient_music >= NB_MUSICS)
				return (custom_error("Music number is invalid"));
			ft_strdel(&(parser->tmp));
			return (0);
		}
		else if (*(parser->line) != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&(parser->tmp));
	}
	return (0);
}

int		parse_fight_music(t_env *env, t_map_parser *parser)
{
	while ((parser->ret = get_next_line(parser->fd, &(parser->tmp))))
	{
		parser->line_count++;
		parser->line = parser->tmp;
		if (*(parser->line) && *(parser->line) != '#')
		{
			if (*(parser->line) != 'F')
				return (invalid_char("fight music", "'F'", *(parser->line), parser));
			parser->line++;
			if (!*(parser->line))
				return (missing_data("music number", parser));
			if (*(parser->line) != ' ')
				return (invalid_char("music number",
							"space or a digit", *(parser->line), parser));
			parser->line = skip_spaces(parser->line);
			if (!*(parser->line))
				return (missing_data("music number", parser));
			if (valid_int(parser->line, parser))
				return (ft_printf("Invalid int for music num\n"));
			env->sound.fight_music = ft_atoi(parser->line);
			parser->line = skip_number(parser->line);
			if (*(parser->line) && *(parser->line) == ' ')
				return (extra_data("fight music number declaration", parser));
			if (*(parser->line))
				return (invalid_char("music number",
							"a digit", *(parser->line), parser));
			if (env->sound.fight_music < 0
				|| env->sound.fight_music >= NB_MUSICS)
				return (custom_error("Music number is invalid"));
			ft_strdel(&(parser->tmp));
			return (0);
		}
		else if (*(parser->line) != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&(parser->tmp));
	}
	return (0);
}