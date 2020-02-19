/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:52 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/14 13:41:48 by lnicosia         ###   ########.fr       */
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
	free_sector(&env->sectors[sector]);
	//ft_printf("del sector\n");
	env->sectors = (t_sector*)ft_delindex(env->sectors,
			 sizeof(t_sector) * env->nb_sectors,
			 sizeof(t_sector),
			 sizeof(t_sector) * sector);
	env->nb_sectors--;
	free(env->sector_list);
	if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (ft_perror("Could not allocate sector list\n"));
	i = sector;
	while (i < env->nb_sectors)
	{
		env->sectors[i].num--;
		i++;
	}
	env->editor.selected_sector = -1;
	tabs_gestion(env);
	update_entities_sectors(env);
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
