/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:44:36 by marvin            #+#    #+#             */
/*   Updated: 2020/04/22 18:44:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int     check_ui_format(t_map_parser *parser, t_env *env)
{
	char *line;

	line = parser->line;
    if (*(parser->tmp) != '\n')
		return (custom_error("Expected a '\\n' at the end of file name\n"));
	if (*line && *line != 'U')
		return (custom_error("Expected letter: U\n"));
	line++;
	if (*line && *line != ' ')
		return (custom_error("Expected a space\n"));
	line++;
    if (valid_int(line, parser))
		return (custom_error("Invalid int for ui images number\n"));
    env->resource.nb_ui_files = ft_atoi(line);
	if (env->resource.nb_ui_files > NB_UI_FILES
	|| env->resource.nb_ui_files < 1)
		return (custom_error("Wrong number of ui\n"));
    return (0);
}

int		map_parse_ui(t_env *env, t_map_parser *parser)
{
	int	i;

	i = 0;
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Could not malloc line\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
    if (check_ui_format(parser, env))
        return (custom_error("Error while parsing ui file data\n"));
	ft_strdel(&parser->line);
	ft_strdel(&parser->tmp);
	while (i <  env->resource.nb_ui_files)
	{
		if (parse_bmp_file(env, parser))
			return (custom_error("Error while parsing ui images\n"));
		i++;
	}
	return (0);
}
