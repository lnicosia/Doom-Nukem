/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:37:30 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/03 15:07:16 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_texture(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;

	(void)env;
	fd = 0;
	size = 0;
	
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(parser->resource_name = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->resource_name) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->resource_name = ft_strjoin_free(parser->resource_name, parser->tmp)))
			return (ft_printf("Could not realloc name in parse texture\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (!(parser->resource_name = ft_strjoin_free(parser->resource_name, "2")))
		return (ft_printf("Could not malloc name in parse texture\n"));
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
			return (ft_printf("Could not malloc line in parse texture\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of texture name\n"));
	if (valid_int(parser->line, parser))
		return (ft_printf("Invalid size for tetxure\n"));
	size = ft_atoi(parser->line);
	ft_strdel(&(parser->line));
	if (size < 54)
		return (ft_printf("Invalid size for texture, size is too small\n"));
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char) * size)))
		return (ft_printf("Memalloc failed\n"));
	if ((parser->ret = read(parser->fd, parser->tmp, size)) <= 0)
		return (ft_printf("Read for texture failed\n"));	
	if ((fd = open(parser->resource_name, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (ft_printf("Could not open texture image\n"));
	ft_strdel(&(parser->resource_name));
	parser->resource_name = NULL;
	write(fd, parser->tmp, size);
	if (((parser->ret = read(parser->fd, parser->tmp, 1)) <= 0) || *(parser->tmp) != '\n')
		return (ft_printf("Invalid file\n"));
	ft_strdel(&(parser->tmp));
	if (close(fd))
		return (ft_printf("Could not close fd\n"));
	return (0);
}

int		map_parse_textures(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	if (!(parser->tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_printf("Could not malloc line\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_printf("Could not malloc line\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (*(parser->line) && *(parser->line) != 'T')
		return (ft_printf("Expected letter: T\n"));
	parser->line++;
	if (*(parser->line) && *(parser->line) != ' ')
		return (ft_printf("Expected a space\n"));
	parser->line++;
	if (valid_int(parser->line, parser))
		return (ft_printf("Invalid int for textures number\n"));
	env->resource.nb_textures = atoi(parser->line);
	parser->line -= 2;
	ft_strdel(&(parser->line));
	ft_strdel(&(parser->tmp));
	while (i <  env->resource.nb_textures)
	{
		if (parse_texture(env, parser))
			return (ft_printf("Error while parsing texture %d\n", i));
		i++;
	}
	return (0);
}

int		parse_resources(t_env *env, t_map_parser *parser)
{
	if (map_parse_textures(env, parser))
		return (ft_printf("Error while parsing resources\n"));
	return (0);
}