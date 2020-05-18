/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:10:27 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/15 20:01:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		creating_new_file(t_map_parser *parser, int size)
{
	int	fd;

	fd = 0;
	if (!(parser->tmp = ft_strnew(size)))
		return (ft_perror("Memalloc failed\n"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (ft_perror("Read for bmp file failed\n"));
	if ((fd = open(parser->resource_name,
	O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (ft_perror("Could not open bmp file\n"));
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->resource_name));
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0)
	|| *(parser->tmp) != '\n')
		return (ft_perror("Invalid file\n"));
	ft_strdel(&(parser->tmp));
	if (close(fd))
		return (ft_perror("Could not close fd\n"));
	return (0);
}

int		check_file_validity(t_map_parser *parser)
{
	int	size;

	size = 0;
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of the size\n"));
	if (valid_int(parser->line, parser))
		return (custom_error("Invalid size for bmp file\n"));
	size = ft_atoi(parser->line);
	ft_strdel(&(parser->line));
	ft_strdel(&(parser->tmp));
	if (size < 54)
		return (custom_error("Invalid size for bmp file, size is too small\n"));
	if (creating_new_file(parser, size))
		return (custom_error("Error while creating the new file\n"));
	return (0);
}

int		parse_file_name(t_map_parser *parser)
{
	ft_strdel(&parser->tmp);
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed"));
	if (!(parser->resource_name = ft_strnew(0)))
		return (ft_perror("Coud not malloc"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break ;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name,
		parser->tmp)))
			return (ft_perror("Could not realloc name in parse bmp"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name\n"));
	ft_strdel(&(parser->tmp));
	return (0);
}

int		parse_bmp_file(t_env *env, t_map_parser *parser)
{
	if (parse_file_name(parser))
		return (custom_error("Error while parsing the file name\n"));
	if (check_existing_files(env, parser->resource_name))
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
				return (ft_perror("Could not malloc line in parse bmp\n"));
		}
		if (check_file_validity(parser))
			return (custom_error("Error while checking and creating file\n"));
	}
	else
	{
		if (skip_file(parser))
			return (custom_error("Error while skipping the resource\n"));
	}
	return (0);
}
