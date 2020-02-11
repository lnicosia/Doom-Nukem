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
** Returns -1 if the vertex is inside a sector
** returns 1 otherwise
*/

int		check_vertex_inside_sector(t_env *env, t_v2 vertex)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (vertex.x == env->vertices[env->sectors[i].vertices[j]].x
			&& vertex.y == env->vertices[env->sectors[i].vertices[j]].y)
				return (1);
			j++;
		}
		if (is_in_sector_no_z(env, i, vertex))
			return (custom_error("Vertex is inside a sector"));
		i++;
	}
	return (1);
}

/*
**	Check if the current sector is inside another sector
*/

static int	is_inside(t_sector sector, t_env *env)
{
	int		i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (check_vertex_inside_sector(env,
			new_v2(env->vertices[sector.vertices[i]].x,
			env->vertices[sector.vertices[i]].y)) != 1)
			return (1);
		i++;
	}
	return (0);
}


/*
**	Check sector validity
*/

static int	check_sector(t_sector sector, t_env *env)
{
	int			i;
	t_vertex	vertex;

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
