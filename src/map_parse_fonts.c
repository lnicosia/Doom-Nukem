/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_fonts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:40:02 by marvin            #+#    #+#             */
/*   Updated: 2020/05/06 15:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"
#include "parser.h"

int		parse_font_number(t_map_parser *parser, char *line, t_env *env)
{
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_perror("Could not malloc line\n"));
	}
	if (*(parser->tmp) != '\n')
		return (ft_perror("Expected a '\\n' at the end of file name\n"));
	line = parser->line;
	if (*line && *line != 'F')
		return (ft_perror("Expected letter: 'F'\n"));
	line++;
	if (*line && *line != ' ')
		return (ft_perror("Expected a space\n"));
	line++;
	if (valid_int(line, parser))
		return (ft_perror("Invalid int for fonts number\n"));
	env->resource.nb_fonts = ft_atoi(line);
	if (env->resource.nb_fonts > NB_FONTS_FILE
	|| env->resource.nb_fonts < 1)
		return (ft_perror("Wrong number of fonts\n"));
	return (0);
}

int		map_parse_fonts(t_env *env, t_map_parser *parser)
{
	int	i;
	char	*line;

	i = 0;
	line = NULL;
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_perror("Memalloc failed\n"));
	if (!(parser->line = ft_strnew(0)))
		return (ft_perror("Could not malloc line\n"));
	if (parse_font_number(parser, line, env))
		return (custom_error("Error while parsing fonts numbers\n"));
	ft_strdel(&(parser->tmp));
	i = 0;
	while (i < env->resource.nb_fonts)
	{
		if (parse_font_file(env, parser))
			return (ft_perror("Error while parsing fonts files\n"));
		i++;
	}
	return (0);
}
