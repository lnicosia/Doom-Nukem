/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_portals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:04:50 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/08 15:04:54 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "create_portals.h"

void	clear_portals(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			env->sectors[i].neighbors[j] = -1;
			j++;
		}
		i++;
	}
}

/*
**	Checks if a given sector contains the given vertex
*/
/*
void	print_sectors(t_env *env, t_sector sector, t_portal_data data)
{
	int	i;

	i = 0;
	ft_printf("sector: %d\n": sector.num);
	while (i < env->sectors[sector.num].nb_vertices)
	{
		ft_printf("-->vertex: %d\n", );
		i++;
	}
}
*/
int		find_common_wall(t_env *env, t_sector sector, t_portal_data data)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == data.v1)
		{
			if (i > 0 && sector.vertices[i - 1] == data.v2
					&& sector.neighbors[i - 1] == -1)
			{
				env->sectors[sector.num].neighbors[i - 1] = data.father;
				env->sectors[data.father].neighbors[data.index] = sector.num;
				/*ft_printf("1: wall from %d to %d in sector %d", data.v1, data.v2, data.father);
				ft_printf(" is wall from %d to %d in sector %d\n",
						sector.vertices[i - 1], sector.vertices[i], sector.num);*/
				return (1);
			}
			else if (!i && sector.vertices[sector.nb_vertices - 1] == data.v2
					&& sector.neighbors[sector.nb_vertices -1] == -1)
			{
				env->sectors[sector.num].neighbors[sector.nb_vertices - 1] = data.father;
				env->sectors[data.father].neighbors[data.index] = sector.num;
				/*ft_printf("2: wall from %d to %d in sector %d", data.v1, data.v2, data.father);
				ft_printf(" is wall from %d to %d in sector %d\n",
						sector.vertices[sector.nb_vertices], sector.vertices[0], sector.num);*/
				return (2);
			}
			else if (sector.vertices[i + 1] == data.v2
					&& sector.neighbors[i + 1] == -1)
			{
				env->sectors[sector.num].neighbors[i] = data.father;
				env->sectors[data.father].neighbors[data.index] = sector.num;
				/*ft_printf("3: wall from %d to %d in sector %d", data.v1, data.v2, data.father);
				ft_printf(" is wall from %d to %d in sector %d\n",
						sector.vertices[i], sector.vertices[i + 1], sector.num);*/
				return (3);
			}
		}
		i++;
	}
	return (0);
}

/*
**	Find every sector containing the given vertex
*/

int		find_neighbors(t_env *env, t_portal_data data)
{
	int			i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != data.father)
			find_common_wall(env, env->sectors[i], data);
		i++;
	}
	return (0);
}

/*
**	For a given sector, finds every neighbor sector
**	and creates portals between them if possible
*/

void	create_portals(t_env *env, t_sector new_sector)
{
	int				i;
	t_portal_data	data;

	i = 0;
	while (i < new_sector.nb_vertices)
	{
		data.v1 = new_sector.vertices[i];
		data.v2 = new_sector.vertices[i + 1];
		data.index = i;
		data.father = new_sector.num;
		find_neighbors(env, data);
		i++;
	}
}
