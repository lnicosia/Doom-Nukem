/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:52 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/19 14:20:54 by lnicosia         ###   ########.fr       */
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
	ft_memdel((void**)&env->sectors[sector].xmin);
	ft_memdel((void**)&env->sectors[sector].xmax);
	ft_memdel((void**)&env->sectors[sector].scale);
	ft_memdel((void**)&env->sectors[sector].align);
	ft_memdel((void**)&env->sectors[sector].nb_sprites);
	ft_memdel((void**)&env->sectors[sector].floor_map_lvl);
	ft_memdel((void**)&env->sectors[sector].ceiling_map_lvl);
	i = 0;
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_memdel((void**)&env->sectors[sector].walls_map_lvl[i]);
		if (env->sectors[sector].sprites[i].sprite)
			ft_memdel((void**)&env->sectors[sector].sprites[i].sprite);
		if (env->sectors[sector].sprites[i].pos)
			ft_memdel((void**)&env->sectors[sector].sprites[i].pos);
		if (env->sectors[sector].sprites[i].scale)
			ft_memdel((void**)&env->sectors[sector].sprites[i].scale);
		i++;
	}
	ft_memdel((void**)&env->sectors[sector].walls_map_lvl);
	ft_memdel((void**)&env->sectors[sector].sprites);
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
	//modify_sector_neighbors(env, sector);
/*	clear_portals(env);
	i = 0;
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}*/
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
