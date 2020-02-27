/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_resources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:37:30 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/27 18:32:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int		parse_texture(t_env *env, t_map_parser *parser)
{
	int		fd;
	int		size;
	char	*name;
	char	*tmp;
	int		ret;

	(void)env;
	ret = 0;
	fd = 0;
	size = 0;
	if ((parser->ret = get_next_line(parser->fd, &tmp)) <= 0)
		return (ft_printf("Missing texture name\n"));
	if (!(name = ft_strjoin_free(tmp, "1")))
		return (-1);
	if ((parser->ret = get_next_line(parser->fd, &tmp)) <= 0)
	{
		free(name);
		return (ft_printf("Missing texture size\n"));
	}
	if (valid_int(tmp, parser))
	{
		free(name);
		return (ft_printf("Invalid size for tetxure\n"));
	}
	size = ft_atoi(tmp);
	if (size < 54)
		return (ft_printf("Ivalid size for texture, size is too small\n"));
	ft_strdel(&tmp);
	if (!(tmp = (char*)ft_memalloc(sizeof(char) * size)))
	{
		free(name);
		return (-1);
	}
	if ((ret = read(parser->fd, tmp, size)) <= 0)
	{
		free(name);
		free(tmp);
		return (-1);	
	}
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
	{
		free(name);
		free(tmp);
		return (ft_printf("Could not open %s\n", name));
	}
	free(name);
	write(fd, tmp, size);
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
	if ((parser->ret = get_next_line(parser->fd, &tmp)) <= 0)
		return (ft_printf("Missing resource type\n"));
	line = tmp;
	if (*line && *line != 'T')
		return (ft_printf("Expected letter: T\n"));
	line++;
	if (valid_int(line, parser))
		return (ft_printf("Invalid int for textures number\n"));
	env->resource.nb_textures = atoi(line);
	while (i < env->resource.nb_textures)
	{
		if (parse_texture(env, parser))
			return (-1);
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