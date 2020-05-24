/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sound_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:22:17 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 18:51:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		checking_new_file(int fd, t_map_parser *parser)
{
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

int		create_new_sound_file2(t_map_parser *parser, int fd)
{
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
	if (checking_new_file(fd, parser))
		return (-1);
	return (0);
}

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
	return (create_new_sound_file2(parser, fd));
}
