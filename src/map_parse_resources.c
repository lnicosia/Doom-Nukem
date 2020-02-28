/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:37:30 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/28 12:04:49 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_texture(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;
	char	*name;
	char	*line;
	char	*tmp;
	int		ret;

	(void)env;
	ret = 0;
	fd = 0;
	size = 0;
	
	if (!(tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(name = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, tmp, 1)) > 0
	&& ft_strlen(name) < 100)
	{
		if (*tmp == '\n')
			break;
		if (!(name = ft_strjoin_free(name, tmp)))
			return (-1);
	}
	if (*tmp != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (!(name = ft_strjoin_free(name, "1")))
		return (-1);
	if (!(tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(line = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, tmp, 1)) > 0
	&& ft_strlen(line) < 100)
	{
		if (*tmp == '\n')
			break;
		if (!(line = ft_strjoin_free(line, tmp)))
			return (-1);
	}
	if (*tmp != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (valid_int(line, parser))
	{
		free(name);
		return (ft_printf("Invalid size for tetxure\n"));
	}
	size = ft_atoi(line);
	ft_strdel(&line);
	if (size < 54)
		return (ft_printf("Ivalid size for texture, size is too small\n"));
	ft_strdel(&tmp);
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * size)))
	{
		free(name);
		return (ft_printf("Memalloc failed\n"));
	}
	if ((ret = read(parser->fd, tmp, size)) <= 0)
	{
		free(name);
		free(tmp);
		return (ft_printf("Read for texture failed\n"));	
	}
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
	{
		free(name);
		free(tmp);
		return (ft_printf("Could not open file\n"));
	}
	free(name);
	write(fd, tmp, size);
	if (((ret = read(parser->fd, tmp, 1)) <= 0) || *tmp != '\n')
		return (ft_printf("Invalid file\n"));
	ft_strdel(&tmp);
	if (close(fd))
		return (ft_printf("Could not close fd\n"));
	return (0);
}

int		map_parse_textures(t_env *env, t_map_parser *parser)
{
	int	i;
	char	*line;
	char	*tmp;
	i = 0;
	
	(void)env;
	if (!(tmp = (char*)ft_memalloc(sizeof(char))))
		return (ft_printf("Memalloc failed\n"));
	if (!(line = ft_strnew(0)))
		return (ft_printf("Could not malloc line\n"));
	while ((parser->ret = read(parser->fd, tmp, 1)) > 0
	&& ft_strlen(line) < 100)
	{
		if (*tmp == '\n')
			break;
		if (!(line = ft_strjoin_free(line, tmp)))
			return (ft_printf("Could not malloc line\n"));
	}
	if (*tmp != '\n')
		return (ft_printf("Expected a '\\n' at the end of file name\n"));
	if (*line && *line != 'T')
		return (ft_printf("Expected letter: T\n"));
	line++;
	if (*line && *line != ' ')
		return (ft_printf("Expected a space\n"));
	line++;
	if (valid_int(line, parser))
		return (ft_printf("Invalid int for textures number\n"));
	env->resource.nb_textures = atoi(line);
	while (i < 5 /*env->resource.nb_textures*/)
	{
		if (parse_texture(env, parser))
			return (ft_printf("Error while parsing resources\n"));
		i++;
	}
	return (0);
}

int		parse_resources(t_env *env, t_map_parser *parser)
{

	if (map_parse_textures(env, parser))
		return (-1);
	return (0);
}