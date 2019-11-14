/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:57:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 11:50:10 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Check if the current sector is inside another sector
*/

static int	is_inside(t_sector sector, t_env *env)
{
	short	*duplicates;
	int		i;

	if (!(duplicates = ft_memalloc(sector.nb_vertices)))
		return (ft_printf("Could not malloc duplicates array\n"));
	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != sector.num)
		{
		}
		i++;
	}
	ft_memdel((void**)&duplicates);
	return (0);
}


/*
**	Check sector validity
*/

static int	check_sector(t_sector sector, t_env *env)
{
	int			i;
	t_vertex	vertex;

	(void)vertex;
	if (is_inside(sector, env))
		return (ft_printf("Sector %d has a duplicate\n", sector.num));
	if (sector.floor_max > sector.ceiling_min)
		return (ft_printf("Sector %d slopes are too strong (floor and ceiling intersect)\n", sector.num));
	i = 0;
	vertex = env->vertices[0];
	while (i < sector.nb_vertices)
	{
		vertex = env->vertices[sector.vertices[i]];
		i++;
	}
	return (0);
}

int			valid_map(t_env *env)
{
	int	i;

	ft_printf("{reset}Checking map validity..{red}\n");
	i = 0;
	env->player.sector = get_sector_no_z(env, env->player.pos);
	if (!env->nb_sectors)
		return (ft_printf("You need at least one sector to go in 3d mode{reset}\n"));
	if (!env->editor.player_exist)
		return (ft_printf("You need to place the player\n"));
	if (env->player.sector == -1)
		return (ft_printf("Player position is not valid{reset}\n"));
	while (i < env->nb_sectors)
	{
		if (check_sector(env->sectors[i], env))
			return (ft_printf("Sector %d was not valid\n", i));
		i++;
	}
	i = 0;
	while (i < env->nb_vertices)
	{
		i++;
	}
	ft_printf("{reset}");
	return (0);
}
