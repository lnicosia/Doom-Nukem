/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:14:16 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/24 16:33:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "utils.h"

static int	init_sectors(t_env *env, t_map_parser *parser)
{
	int		nb_sectors;
	int		i;
	char	*line;

	line = NULL;
	while ((parser->ret = get_next_line(parser->fd, &line)))
	{
		if (line[0] == 'S' && line[1] == ' '
				&& line[2] >= '0' && line[2] <= '9')
		{
			line = skip_spaces(line);
			if (!*line)
			{
				ft_printf("Please declare how many sectors there are\n");
				return (-1);
			}
			nb_sectors = atoi(line);
			if (nb_sectors < 1)
			{
				ft_printf("You need to declare at least one sector.\n");
				return (-1);
			}
			if (!(env->sectors = (t_sector *)malloc(sizeof(t_sector) * (nb_sectors))))
			{
				ft_printf("Could not malloc sectors!\n", env);
				return (-1);
			}
			env->screen_sectors_size = ft_min(nb_sectors, env->w);
			if (!(env->xmin = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
			{
				ft_printf("Could not malloc xmins!\n", env);
				return (-1);
			}
			if (!(env->xmax = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
			{
				ft_printf("Could not malloc xmaxs!\n", env);
				return (-1);
			}
			if (!(env->screen_sectors = (int*)malloc(sizeof(int) * (env->screen_sectors_size))))
			{
				ft_printf("Could not malloc screen sectors!\n", env);
				return (-1);
			}
			if (!(env->rendered_sectors = (short*)malloc(sizeof(short) * (env->screen_sectors_size))))
			{
				ft_printf("Could not malloc rendered sectors!\n", env);
				return (-1);
			}
			i = 0;
			while (i < nb_sectors)
			{
				env->sectors[i].vertices = NULL;
				env->sectors[i].ceilings = NULL;
				env->sectors[i].floors = NULL;
				env->sectors[i].clipped_ceilings1 = NULL;
				env->sectors[i].clipped_floors1 = NULL;
				env->sectors[i].clipped_ceilings2 = NULL;
				env->sectors[i].clipped_floors2 = NULL;
				env->sectors[i].neighbors = NULL;
				env->sectors[i].x_max = -2147483648;
				env->sectors[i].wall_width = NULL;
				env->sectors[i].vertices_textures = NULL;
				i++;
			}
		}
		else if (line[0] != '#')
			return (ft_printf("Wrong format of vertices number "
			"declaration%d\nEx: \"S sectors_count\"\n",
			parser->line_count));
		ft_strdel(&line);
		parser->line_count++;
	}
	return (nb_sectors);
}

int			parse_sectors(t_env *env, t_map_parser *parser)
{
	if (init_sectors(env, parser))
		return (ft_printf("Could not init sectors\n"));
	return (0);
}
