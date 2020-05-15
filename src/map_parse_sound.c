/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sound.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:33:00 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 20:02:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		check_sound_number_validity(t_map_parser *parser, t_env *env)
{
	char	*line;

	line = NULL;
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name\n"));
	line = parser->line;
	if (*line && *line != 'S')
		return (custom_error("Expected letter: S\n"));
	line++;
	if (*line && *line != ' ')
		return (custom_error("Expected a space\n"));
	line++;
	if (valid_int(line, parser))
		return (custom_error("Invalid int for sounds number\n"));
	env->resource.nb_sound = atoi(line);
	ft_printf("nb sounds: %d\n", env->resource.nb_sound);
	if (env->resource.nb_sound > NB_MUSICS + NB_SOUNDS
	|| env->resource.nb_sound < 0)
		return (custom_error("Wrong number of sounds\n"));
	return (0);
}

int		parse_sounds_number(t_map_parser *parser, t_env *env)
{
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
	if (check_sound_number_validity(parser,env))
		return (custom_error("Error while parsing sounds number validity\n"));
	return (0);
}

int		map_parse_sounds(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Could not malloc line\n"));
	if (parse_sounds_number(parser, env))
		return (custom_error("Error while parsing number of sounds\n"));
	ft_strdel(&(parser->tmp));
	ft_strdel(&(parser->line));
	while (i < env->resource.nb_sound)
	{
		if (parse_sound(env, parser))
			return (custom_error("Error while parsing a sound\n"));
		i++;
	}
	return (0);
}
