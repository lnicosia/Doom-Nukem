/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:50:56 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 18:29:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		check_sound_format_validity(t_map_parser *parser)
{
	int	size;

	size = 0;
	if (valid_int(parser->line, parser))
		return (custom_error("Invalid size for sound\n"));
	size = ft_atoi(parser->line);
	if (size < 44)
		return (custom_error("Invalid size for sound, size is too small\n"));
	ft_strdel(&(parser->tmp));
	if (create_new_sound_file(parser, size))
		return (custom_error("Error while creating the new file\n"));
	return (0);
}

int		parse_sound_name(t_map_parser *parser)
{
	ft_strdel(&parser->tmp);
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	ft_strdel(&(parser->resource_name));
	if (!(parser->resource_name = ft_strnew(0)))
		return (ft_perror("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break ;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name,
		  	parser->tmp)))
			return (custom_error("Could not realloc name in parse sound\n"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of sound file"
		" name\n"));
	ft_strdel(&(parser->tmp));
	return (0);
}

int		create_file_from_map(t_map_parser *parser)
{
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break ;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line in parse sound\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_perror("Expected a '\\n' at the end of sound file\n"));
	if (check_sound_format_validity(parser))
		return (custom_error("Error while parsing sound validity\n"));
	return (0);
}

int		parse_sound(t_env *env, t_map_parser *parser)
{
	if (parse_sound_name(parser))
		return (ft_perror("Error while parsing sound name\n"));
	if (check_existing_sounds(env, parser->resource_name))
	{
		if (create_file_from_map(parser))
			return (custom_error("Failed to create sound file from map\n"));
	}
	else
	{
		if (skip_file(parser))
			return (ft_perror("Error while skipping the audio file\n"));
	}
	return (0);
}
