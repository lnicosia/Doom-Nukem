/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:17:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/21 18:11:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	sort_tab(int **tab, int size)
{
	int i;
	int	j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab [j])
			{
				tmp = *tab[i];
				*tab[i] = *tab[j];
				*tab[j] = tmp;
			}
			else
				j++;
		}
		i++;
	}
}

int		get_nb_floors(t_env *env, t_sector *sector)
{
	int		i;
	int		floors;

	i = 0;
	floors = 0;;
	while (i < sector->nb_vertices)
	{
		if (sector->neighbors[i] != -1)
		{
			if (sector->floor != env->sectors[sector->neighbors[i]].floor)
				floors++;
		}
		i++;
	}
	if (!(sector->levels = (int *)malloc(sizeof(int) * (floors + 1))))
		return (0);
	create_levels(env, floors + 1);
	return (1);
}

int		create_levels(t_env *env, int nb_floors)
{
	int		i;
	int		j;
	t_sector	sector;

	i = 0;
	j = 0;
	sector = env->sectors[env->player.sector];
	while (i < sector.nb_vertices)
	{
		if (sector.neighbors[i] != -1)
		{
			if (sector.floor != env->sectors[sector.neighbors[i]].floor)
				sector.levels[j] = env->sectors[sector.neighbors[i]].floor;
			j++;
		}
		i++;
	}
	sector.levels[j] = env->sectors[sector.neighbors[i]].floor;
	sort_tab(&sector.levels, nb_floors);
	env->sectors[env->player.sector] = sector;
	return (0);
}
