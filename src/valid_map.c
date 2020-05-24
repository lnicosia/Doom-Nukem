/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:57:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/20 13:36:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_vertices(t_sector sector, t_env *env)
{
	int			i;
	int			j;
	t_vertex	v1;
	t_vertex	v2;
	int			res;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1 = env->vertices[sector.vertices[i]];
		v2 = env->vertices[sector.vertices[i + 1]];
		j = 0;
		while (j < env->nb_sectors)
		{
			if (env->sectors[j].num != sector.num
				&& check_intersection_with_sector(env->sectors[j], env, v1, v2))
				return (-1);
			j++;
		}
		i++;
	}
	res = is_sector_concave(sector, env);
	if (res == -1)
		return (custom_error("Concave check had a system error"));
	else if (res)
		return (custom_invalid("Sector %d is concave\n", sector.num));
	if (check_neighbor_validity(sector, env))
		return (custom_error("Sector %d has a invalid neighbor\n", sector.num));
	return (0);
}

int			check_slopes_start(t_sector sector)
{
	if (sector.start_ceiling_slope > sector.nb_vertices
		|| sector.start_ceiling_slope < 0)
		return (custom_error("Ceiling start slope is invalid"));
	if (sector.start_floor_slope > sector.nb_vertices
		|| sector.start_floor_slope < 0)
		return (custom_error("Floor start slope is invalid"));
	return (0);
}

int			distance_bewteen_ceiling_and_floor(t_sector sector)
{
	if (sector.ceiling - sector.floor > 1000)
		return (-1);
	return (0);
}

/*
**	Check sector validity
*/

int			check_sector(t_sector sector, t_env *env)
{
	int		res;

	if (is_inside(sector, env))
		return (custom_invalid("Sector %d is inside or contains a sector\n",
		sector.num));
		res = check_vertices(sector, env);
	if (res == -1)
		return (custom_error("Vertices check had a system error\n"));
	else if (res)
		return (custom_invalid("Vertices are invalid for some reasons\n"));
	if (check_slopes_start(sector))
		return (custom_invalid("slope direction isn't valid\n"));
	if (distance_bewteen_ceiling_and_floor(sector))
		return (custom_invalid("Distance between floor and ceiling"
		"cannot exceed 1000\n"));
	if (env->sector_is_straight)
		return (custom_invalid("Sector %d is on a staight line\n", sector.num));
	if (check_entities_height_in_sector(&sector, env))
		return (custom_invalid("Sector %d entities do not fit\n"));
	return (0);
}

int			valid_map(t_env *env)
{
	int	i;
	int	res;

	ft_printf("{reset}Checking map validity..{red}\n");
	i = 0;
	env->player.sector = get_sector_no_z(env, env->player.pos);
	env->player.starting_sector =
	get_sector_no_z(env, env->player.starting_pos);
	if (check_valid_map_start_data(env))
		return (1);
	while (i < env->nb_sectors)
	{
		if ((res = check_sector(env->sectors[i], env)))
			return (res);
		i++;
	}
	ft_printf("{reset}");
	return (0);
}
