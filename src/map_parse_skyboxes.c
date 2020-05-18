/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_skyboxes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:58:51 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 20:02:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int	check_skyboxes_number_validity(t_map_parser *parser, t_env *env)
{
	char	*line;

	line = NULL;
	if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name\n"));
	line = parser->line;
	if (*line && *line != 'S')
		return (custom_error("Expected letter: S\n"));
	line++;
	if (*line && *line != 'K')
		return (custom_error("Expected letter: 'K'\n"));
	line++;
	if (*line && *line != 'Y')
		return (custom_error("Expected letter: 'Y'\n"));
	line++;
	if (*line && *line != ' ')
		return (custom_error("Expected a space\n"));
	line++;
	if (valid_int(line, parser))
		return (custom_error("Invalid int for skybox images number\n"));
	env->resource.nb_skyboxes = atoi(line);
	if (env->resource.nb_skyboxes > MAX_SKYBOX * 6
	|| env->resource.nb_skyboxes < 1)
		return (custom_error("Wrong number of sprites\n"));
	return (0);
}

int	parse_skyboxes_number(t_map_parser *parser)
{
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Could not malloc line\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break ;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
	return (0);
}

int	map_parse_skyboxes(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	if (parse_skyboxes_number(parser))
		return (custom_error("Error while parsing skyboxes number\n"));
	if (check_skyboxes_number_validity(parser, env))
		return (custom_error("Skyboxes number is invalid\n"));
	ft_strdel(&parser->tmp);
	ft_strdel(&parser->line);
	while (i < env->resource.nb_skyboxes)
	{
		if (parse_bmp_file(env, parser))
			return (custom_error("Error while parsing skybox %d\n", i));
		i++;
	}
	return (0);
}
