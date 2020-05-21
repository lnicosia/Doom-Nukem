/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sector_slope.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:39:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:39:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

void	compute_current_wall_slope2(int i, t_sector *sector, t_env *env)
{
	if (sector->floors[i] < sector->floor_min)
		sector->floor_min = sector->floors[i];
	if (sector->floors[i] > sector->floor_max)
		sector->floor_max = sector->floors[i];
	if (sector->ceilings[i] > sector->ceiling_max)
		sector->ceiling_max = sector->ceilings[i];
	if (sector->ceilings[i] < sector->ceiling_min)
		sector->ceiling_min = sector->ceilings[i];
	sector->wall_width[i] = sqrt(
		pow(env->vertices[sector->vertices[i + 1]].x
		- env->vertices[sector->vertices[i]].x, 2)
		+ pow(env->vertices[sector->vertices[i + 1]].y
		- env->vertices[sector->vertices[i]].y, 2));
}

void	compute_current_wall_slope(int i, t_sector *sector, t_env *env)
{
	t_vertex	v1;

	v1 = env->vertices[sector->vertices[i]];
	if (sector->floor_slope != 0)
		sector->floors[i] = get_floor_at_pos(sector,
			new_v3(v1.x, v1.y, 0), env);
	else
		sector->floors[i] = sector->floor;
	if (sector->ceiling_slope != 0)
		sector->ceilings[i] = get_ceiling_at_pos(sector,
			new_v3(v1.x, v1.y, 0), env);
	else
		sector->ceilings[i] = sector->ceiling;
	compute_current_wall_slope2(i, sector, env);
}

void	update_sector_slope(t_env *env, t_sector *sector)
{
	int			i;

	sector->floor_max = sector->floor;
	sector->floor_min = sector->floor;
	sector->ceiling_max = sector->ceiling;
	sector->ceiling_min = sector->ceiling;
	i = 0;
	while (i < sector->nb_vertices)
	{
		compute_current_wall_slope(i, sector, env);
		i++;
	}
	sector->floors[i] = sector->floors[0];
	sector->ceilings[i] = sector->ceilings[0];
	set_sector_xmax(env, sector);
}
