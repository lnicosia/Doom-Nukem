/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:11:44 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 20:01:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int	parse_textures(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (i < env->resource.nb_textures)
	{
		if (parse_bmp_file(env, parser))
			return (custom_error("Error while parsing texture %d\n", i));
		i++;
	}
	return (0);
}

int	check_textures_number_validity(t_map_parser *parser, t_env *env)
{
	char	*line;

	line = NULL;
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name\n"));
	line = parser->line;
	if (*line && *line != 'T')
		return (custom_error("Expected letter: T\n"));
	line++;
	if (*line && *line != ' ')
		return (custom_error("Expected a space\n"));
	line++;
	if (valid_int(line, parser))
		return (custom_error("Invalid int for textures number\n"));
	env->resource.nb_textures = ft_atoi(line);
	if (env->resource.nb_textures > MAX_WALL_TEXTURE
		|| env->resource.nb_textures < 1)
		return (custom_error("Wrong number of textures\n"));
	return (0);
}

int	parse_textures_number(t_map_parser *parser, t_env *env)
{
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break ;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
	if (check_textures_number_validity(parser, env))
		return (custom_error("Error while parsing textures number\n"));
	return (0);
}

int	map_parse_textures(t_env *env, t_map_parser *parser)
{
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Could not malloc line\n"));
	if (parse_textures_number(parser, env))
		return (custom_error("Error while parsing textures number\n"));
	ft_strdel(&(parser->line));
	ft_strdel(&(parser->tmp));
	if (parse_textures(env, parser))
		return (custom_error("Error while parsing textures\n"));
	return (0);
}
