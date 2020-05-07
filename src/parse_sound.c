/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:50:56 by marvin            #+#    #+#             */
/*   Updated: 2020/05/06 14:50:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		create_new_sound_file(t_map_parser *parser, int size)
{
	int	fd;

	fd = 0;
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (ft_printf("Could not open sound file\n"));
	ft_strdel(&(parser->resource_name));
	if (!(parser->tmp = ft_strnew(size)))
		return (ft_printf("Memalloc failed\n"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (ft_printf("Read for sound failed\n"));
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_printf("Memalloc failed\n"));
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0) || *(parser->tmp) != '\n')
		return (ft_printf("Invalid sound file\n"));
	ft_strdel(&(parser->tmp));
	ft_strdel(&(parser->line));
	if (close(fd))
		return (ft_printf("Could not close fd\n"));
	return (0);
}

int		check_sound_format_validity(t_map_parser *parser)
{
	int	size;

	size = 0;
	if (valid_int(parser->line, parser))
		return (ft_printf("Invalid size for sound\n"));
	size = ft_atoi(parser->line);
	if (size < 44)
		return (ft_printf("Invalid size for sound, size is too small\n"));
	ft_strdel(&(parser->tmp));
	size += 8;
	if (create_new_sound_file(parser, size))
			return(ft_printf("Error while creating the new file\n"));
	return (0);
}

int		parse_sound_name(t_map_parser *parser)
{
	ft_strdel(&parser->tmp);
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_printf("Memalloc failed\n"));
	if (!(parser->resource_name = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name,
		  	parser->tmp)))
			return (ft_printf("Could not realloc name in parse sound\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of sound file name\n"));
	ft_strdel(&(parser->tmp));
	return (0);
}

int		parse_sound(t_env *env, t_map_parser *parser)
{
	if (parse_sound_name(parser))
		return (ft_printf("Error while pârsing sound name\n"));
	if (check_existing_sounds(env, parser->resource_name))
	{
		if (!(parser->tmp = ft_strnew(1)))
			return (ft_printf("Memalloc failed\n"));
		if (!(parser->line = ft_strnew(0)))
			return (ft_printf("Coud not malloc\n"));
		while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
		&& ft_strlen(parser->line) < 100)
		{
			if (*(parser->tmp) == '\n')
				break;
			if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
				return (ft_printf("Could not malloc line in parse sound file\n"));
		}
		if (*(parser->tmp) != '\n')
			return (ft_printf("Expected a '\\n' at the end of sound file\n"));
		if (check_sound_format_validity(parser))
			return (custom_error("Error while parsing sound format validity\n"));
	}
	else
	{
		if (skip_file(parser))
			return (ft_printf("Error while skipping the audio file\n"));
	}
	return (0);
}