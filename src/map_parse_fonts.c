/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_fonts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:19:36 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 13:16:42 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		parse_font_file(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;

	(void)env;
	fd = 0;
	size = 0;
	
	if (parser->tmp)
	ft_strdel(&(parser->tmp));
	if (parser->line)
	ft_strdel(&(parser->line));
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
			return (ft_printf("Could not realloc name in parse font\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (!(parser->resource_name = ft_strjoin_free(parser->resource_name, "2")))
		return (ft_printf("Could not malloc name in parse font\n"));
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_printf("Could not malloc line in parse font file\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of the size"
		" of the file\n"));
	if (valid_int(parser->line, parser))
		return (ft_printf("Invalid size for font file\n"));
	size = ft_atoi(parser->line);
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char) * size)))
		return (ft_printf("Memalloc failed\n"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (ft_printf("Read for bmp file failed\n"));	
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT | O_TRUNC,
	  	0000700)) < 0)
		return (ft_printf("Could not open bmp file\n"));
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->resource_name));
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0)
	  	|| *(parser->tmp) != '\n')
		return (ft_printf("Invalid file\n"));
	ft_strdel(&(parser->tmp));
	return (0);
}
