/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rendered_sectors_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:22:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:22:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	get_rendered_neighbors(t_camera *camera, t_sector sector,
t_env *env)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.neighbors[i] != -1
			&& !camera->sector_computed[sector.neighbors[i]])
		{
			camera->sector_computed[sector.neighbors[i]] = 1;
			env->visible_sectors++;
			get_rendered_neighbors(camera, env->sectors[sector.neighbors[i]],
			env);
		}
		i++;
	}
}

void	get_rendered_sectors_list(int screen_sectors, t_camera *camera,
		t_env *env)
{
	int			i;
	t_sector	sector;

	i = 0;
	while (i < screen_sectors)
	{
		sector = env->sectors[camera->screen_sectors[i]];
		if (!camera->sector_computed[sector.num])
		{
			camera->sector_computed[sector.num] = 1;
			env->visible_sectors++;
			get_rendered_neighbors(camera, sector, env);
		}
		i++;
	}
}
