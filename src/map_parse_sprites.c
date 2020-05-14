/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpa_parse_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:53:17 by marvin            #+#    #+#             */
/*   Updated: 2020/05/06 14:53:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		check_sprites_number_validity(t_map_parser *parser, t_env *env)
{
	char	*line;

	line = NULL;
	if (*(parser->tmp) != '\n')
		return (ft_perror("Expected a '\\n' at the end of file name\n"));
	line = parser->line;
	if (*(parser->line) && *(parser->line) != 'S')
		return (ft_perror("Expected letter: S\n"));
	line++;
	if (*line && *line != 'P')
		return (ft_perror("Expected letter: 'P'\n"));
	line++;
	if (*line && *line != ' ')
		return (ft_perror("Expected a space\n"));
	line++;
	env->resource.nb_sprites = atoi(line);
	if (env->resource.nb_sprites > NB_BMP_SPRITES
	|| env->resource.nb_sprites < 1)
		return (ft_perror("Wrong number of sprites\n"));
	return (0);
}

int     parse_sprites_number(t_map_parser *parser, t_env *env)
{
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(1)))
		return (ft_perror("Could not malloc line\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
	if (check_sprites_number_validity(parser, env))
		return (custom_error("Error while checking sprites number validity\n"));
    return (0);
}

int		map_parse_sprites(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	ft_strdel(&parser->line);
	ft_strdel(&parser->tmp);
    if (parse_sprites_number(parser, env))
        return (custom_error("Error while parsing the sprites number\n"));
	if (valid_int(parser->line, parser))
		return (ft_perror("Invalid int for sprites number\n"));
	ft_strdel(&(parser->tmp));
	ft_strdel(&(parser->line));
	while (i <  env->resource.nb_sprites)
	{
		if (parse_bmp_file(env, parser))
			return (ft_perror("Error while parsing sprites\n"));
		i++;
	}
	return (0);
}