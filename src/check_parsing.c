/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:27:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/16 11:07:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	check_parsing(t_env *env)
{
	int	i;
	int	j;

	ft_printf("Vertex %d\n", env->nb_vertices);
	i = 0;
	while (i < env->nb_vertices)
	{
		ft_printf("vertex	%f %f\n", env->vertices[i].x, env->vertices[i].y);
		i++;
	}
	ft_printf("\nSector %d\n", env->nb_sectors);
	i = 0;
	while (i < env->nb_sectors)
	{
		ft_printf("sector	%f %f	", env->sectors[i].floor,
				env->sectors[i].ceiling);
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			ft_printf("%d ", env->sectors[i].vertices[j]);
			j++;
		}
		ft_printf("	");
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			ft_printf("%d ", env->sectors[i].neighbors[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\nplayer	%f %f	%f %d\n", env->player.pos.x,
			env->player.pos.y, env->player.angle, env->player.sector);
}
