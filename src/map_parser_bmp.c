/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:10:27 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 19:02:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_bmp_file(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;

	(void)env;
	fd = 0;
	size = 0;
	ft_strdel(&parser->tmp);
	if (!(parser->tmp = ft_strnew(1)))
		return (custom_error("Memalloc failed\n"));
	if (!(parser->resource_name = ft_strnew(0)))
		return (custom_error("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name,
		  	parser->tmp)))
			return (custom_error("Could not realloc name in parse bmp\n"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name"
		" in the map\n"));
	if (!(parser->resource_name = ft_strjoin_free(parser->resource_name, "2")))
		return (custom_error("Could not malloc name in parse bmp\n"));
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = ft_strnew(1)))
		return (custom_error("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (custom_error("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (custom_error("Could not malloc line in parse bmp\n"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of the size\n"));
	if (valid_int(parser->line, parser))
		return (custom_error("Invalid size for bmp file\n"));
	size = ft_atoi(parser->line);
	ft_strdel(&(parser->line));
	ft_strdel(&(parser->tmp));
	if (size < 54)
		return (custom_error("Invalid size for bmp file, size is too small\n"));
	if (!(parser->tmp = ft_strnew(size)))
		return (custom_error("Memalloc failed\n"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (custom_error("Read for bmp file failed\n"));	
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT | O_TRUNC,
	  	0000700)) < 0)
		return (custom_error("Could not open bmp file\n"));
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->resource_name));
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0)
	  	|| *(parser->tmp) != '\n')
		return (custom_error("Invalid file\n"));
	ft_strdel(&(parser->tmp));
	if (close(fd))
		return (custom_error("Could not close fd\n"));
	return (0);
}
