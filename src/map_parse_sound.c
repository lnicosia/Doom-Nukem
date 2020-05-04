/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sound.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:12:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/09 10:37:28 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		parse_sound(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;

	(void)env;
	fd = 0;
	size = 0;
	
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed"));
	if (!(parser->resource_name = ft_strnew(0)))
		return (ft_perror("Coud not malloc"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name,
		  	parser->tmp)))
			return (ft_perror("Could not realloc name in parse sound\n"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of sound file name\n"));
	if (!(parser->resource_name = ft_strjoin_free(parser->resource_name, "2")))
		return (ft_perror("Could not malloc name in parse sound"));
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_perror("Memalloc failed"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Coud not malloc"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (custom_error("Could not malloc"
			" line in parse sound file\n"));
	}
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of sound file\n"));
	if (valid_int(parser->line, parser))
		return (custom_error("Invalid size for sound\n"));
	size = ft_atoi(parser->line);
	if (size < 44)
		return (custom_error("Invalid size for sound, size is too small\n"));
	ft_strdel(&(parser->tmp));
	size += 8;
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT | O_TRUNC,
	  	0000700)) < 0)
		return (custom_error("Could not open sound file\n"));
	ft_strdel(&(parser->resource_name));
	parser->resource_name = NULL;
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char) * size)))
		return (ft_perror("Memalloc failed"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (ft_perror("Read for sound failed"));
	write(fd, parser->tmp, size);
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_perror("Memalloc failed"));
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0)
	  	|| *(parser->tmp) != '\n')
		return (custom_error("Invalid sound file\n"));
	ft_strdel(&(parser->tmp));
	ft_strdel(&(parser->line));
	if (close(fd))
		return (custom_error("Could not close fd\n"));
	return (0);
}
