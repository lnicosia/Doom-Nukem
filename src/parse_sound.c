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
	ft_printf("'%s' was missing in current directory. Extracting..\n",
	parser->resource_name);
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT
		| O_TRUNC, 0000700)) < 0)
		return (ft_perror("Could not open sound file\n"));
	ft_strdel(&(parser->resource_name));
	if (!(parser->tmp = ft_strnew(size)))
	{
		if (close(fd))
			return (ft_perror("Memalloc failed and could not close the"
			" sound file\n"));
		return (ft_perror("Memalloc failed\n"));
	}
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
	{
		if (close(fd))
			return (ft_perror("Read failed and could not close the"
			" sound file\n"));
		return (ft_perror("Read for sound failed\n"));
	}
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = ft_strnew(1)))
	{
		if (close(fd))
			return (ft_perror("Memalloc failed and could not close the"
			" sound file\n"));
		return (ft_perror("Memalloc failed\n"));
	}
	if ((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0)
	{
		if (close(fd))
			return (ft_perror("read failed and could not close the"
			" sound file\n"));
		return (ft_perror("Invalid sound file\n"));
	}
	if (*(parser->tmp) != '\n')
	{
		if (close(fd))
			return (ft_perror("Missing '\\n' and could not close the"
			" sound file\n"));
		return (custom_error("Missing '\\n' in sound file\n"));
	}
	ft_strdel(&(parser->tmp));
	ft_strdel(&(parser->line));
	if (close(fd))
		return (ft_perror("Could not close fd\n"));
	return (0);
}

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
			return(custom_error("Error while creating the new file\n"));
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
			break;
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

int		parse_sound(t_env *env, t_map_parser *parser)
{
	if (parse_sound_name(parser))
		return (ft_perror("Error while parsing sound name\n"));
	if (check_existing_sounds(env, parser->resource_name))
	{
		if (!(parser->tmp = ft_strnew(1)))
			return (ft_perror("Memalloc failed\n"));
		if (!(parser->line = ft_strnew(0)))
			return (ft_perror("Coud not malloc\n"));
		while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
		&& ft_strlen(parser->line) < 100)
		{
			if (*(parser->tmp) == '\n')
				break;
			if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
				return (ft_perror("Could not malloc line in parse sound file\n"));
		}
		if (*(parser->tmp) != '\n')
			return (ft_perror("Expected a '\\n' at the end of sound file\n"));
		if (check_sound_format_validity(parser))
			return (custom_error("Error while parsing sound format validity\n"));
	}
	else
	{
		if (skip_file(parser))
			return (ft_perror("Error while skipping the audio file\n"));
	}
	return (0);
}
