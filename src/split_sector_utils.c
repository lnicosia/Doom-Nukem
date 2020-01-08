/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:12:07 by sipatry           #+#    #+#             */
/*   Updated: 2019/12/02 12:11:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_neighbors(t_env *env, int index, int num, t_sector *sector)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (index != -1)
	{
		while (i < sector->nb_vertices)
		{
			if (sector->neighbors[index] != -1)
			{
				j = 0;
				while(j < env->sectors[sector->neighbors[index]].nb_vertices)
				{
					if (env->sectors[sector->neighbors[index]].neighbors[j] == num)
						env->sectors[sector->neighbors[index]].neighbors[j] = env->nb_sectors - 1;
					j++;
				}
			}
			i++;
		}
		i = 0;
		while (i < sector->nb_vertices)
		{
			if (sector->neighbors[i] == num)
			{
					sector->neighbors = ft_delindex(sector->neighbors,
							sizeof(short) * (sector->nb_vertices + 1),
							sizeof(short),
							sizeof(short) * i);
			}
			i++;
		}
	}
}

void	update_double_tab(int index, double size, double **tab)
{
	*tab = ft_delindex(*tab,
		sizeof(double) * (size),
		sizeof(double),
		sizeof(double) * index);
}

void	update_short_tab(int index, short size, short **tab)
{
	*tab = ft_delindex(*tab,
		sizeof(short) * (size),
		sizeof(short),
		sizeof(short) * index);
}
/*
void	update_short_tab(int index, short size, short **tab)
{
	*tab = ft_delindex(*tab,
		sizeof(short) * (size),
		sizeof(short),
		sizeof(short) * index);
}*/