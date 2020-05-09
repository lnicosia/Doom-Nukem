/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resources_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 15:46:35 by marvin            #+#    #+#             */
/*   Updated: 2020/04/22 15:46:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int     new_parsed_hud_file(char *name, t_env *env) 
{
    int i;

    i = env->hud_start;
    while (i < NB_HUD_FILES)
    {
        if ( env->init.hud[i]
		&& (!(ft_strcmp(name, env->init.hud_names[i]))))
		{
			if (parse_bmp(name, i + env->hud_start, env))
			    return (ft_printf("Invalid bmp file\n"));
		}
		i++;
    }
    return (0);
}

int     new_parsed_textures(char *name, t_env *env)
{
    int i;

    i = 0;
    while (i < MAX_WALL_TEXTURE)
    {
        if (!(ft_strcmp(name, env->init.text_name[i]))
        && env->init.textures[i] == 1)
        {
            if (parse_bmp_wall_textures(name, i, env))
		        return (-1);
            env->init.textures[i] = 0;
        }
        i++;
    }
    return (0);
}

int		skip_file(t_map_parser *parser)
{
	int	size;
	int	ret;

	ret = 0;
	size = 0;
	if (!(parser->line = ft_strnew(0)))
		return (ft_printf("Coud not malloc\n"));
	if (!(parser->tmp = ft_strnew(1)))
		return (ft_printf("Coud not malloc\n"));
	while ((parser->ret = read(parser->fd, parser->tmp, 1)) > 0
	&& ft_strlen(parser->line) < 100)
	{
		ret += parser->ret;
		if (*(parser->tmp) == '\n')
			break;
		if (!(parser->line = ft_strjoin_free(parser->line, parser->tmp)))
			return (ft_printf("Could not malloc line in parse bmp\n"));
	}
	ft_printf("line: %s\n", parser->line);
	ft_printf("tmp: %s\n", parser->tmp);
	if (*(parser->tmp) != '\n')
		return (ft_printf("Expected a '\\n' at the end of the size\n"));
	if (valid_int(parser->line, parser))
		return (ft_printf("Invalid size for bmp file\n"));
	size = ft_atoi(parser->line);
	ft_strdel(&(parser->line));
	ft_strdel(&(parser->tmp));
	if (!(parser->tmp = ft_strnew(size + 1)))
		return (ft_printf("Coud not malloc\n"));
	if ((ret = read(parser->fd, parser->tmp, size + 1)) < size + 1)
		return (ft_printf("Written file is smaller than the given size file\n"));
	ft_strdel(&(parser->tmp));
	return(0);
}