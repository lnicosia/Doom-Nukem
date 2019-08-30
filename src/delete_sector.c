/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:56:17 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/30 14:48:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	modify_sector_neighbors(t_env *env, int sector)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].neighbors[j] >= sector)
				env->sectors[i].neighbors[j]--;
			j++;
		}
		i++;
	}
}

int		delete_sector(t_env *env, int sector)
{
	int	i;

	i = 0;
	ft_memdel((void**)&env->sectors[sector].vertices);
	ft_memdel((void**)&env->sectors[sector].neighbors);
	ft_memdel((void**)&env->sectors[sector].textures);
	ft_memdel((void**)&env->sectors[sector].floors);
	ft_memdel((void**)&env->sectors[sector].ceilings);
	ft_memdel((void**)&env->sectors[sector].clipped_ceilings1);
	ft_memdel((void**)&env->sectors[sector].clipped_ceilings2);
	ft_memdel((void**)&env->sectors[sector].clipped_floors1);
	ft_memdel((void**)&env->sectors[sector].clipped_floors2);
	ft_memdel((void**)&env->sectors[sector].wall_width);
	env->sectors = ft_delindex(env->sectors,
			 sizeof(t_sector) * env->nb_sectors,
			 sizeof(t_sector),
			 sizeof(t_sector) * sector);
	env->nb_sectors--;
	i = sector;
	while (i < env->nb_sectors)
	{
		env->sectors[i].num--;
		i++;
	}
	modify_sector_neighbors(env, sector);
	return (0);
}

int		delete_invalid_sectors(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (env->sectors[i].nb_vertices < 3)
		{
			if (delete_sector(env, i))
				return (-1);
			i--;
		}
		i++;
	}
	return (0);
}
