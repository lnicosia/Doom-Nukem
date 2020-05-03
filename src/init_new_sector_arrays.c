/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_sector_arrays.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:04:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:04:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			init_new_sector_arrays3(t_sector *sector)
{
	if (!(sector->wall_bullet_holes = (t_list**)ft_memalloc(sizeof(t_list*)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector wall bullet holes"));
	if (!(sector->portals = (int*)ft_memalloc(sizeof(int)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector portals"));
	return (0);
}

int			init_new_sector_arrays2(t_sector *sector)
{
	if (!(sector->ceilings = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector ceiling"));
	if (!(sector->floors = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector floors"));
	if (!(sector->clipped_ceilings1 = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings1"));
	if (!(sector->clipped_ceilings2 = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings2"));
	if (!(sector->clipped_floors1 = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_floors1"));
	if (!(sector->clipped_floors2 = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_floors2"));
	if (!(sector->wall_width = (double*)ft_memalloc(sizeof(double)
		* (sector->nb_vertices + 1))))
		return (ft_perror("could not malloc sector vertices"));
	if (!(sector->walls_map_lvl = (double**)
				ft_memalloc(sizeof(double*) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	return (init_new_sector_arrays3(sector));
}

int			init_new_sector_arrays(t_sector *sector)
{
	if (!(sector->vertices = (int*)ft_memalloc(sizeof(int)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	if (!(sector->neighbors = (int*)ft_memalloc(sizeof(int)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector neighbors"));
	if (!(sector->textures = (int*)ft_memalloc(sizeof(int)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->wall_sprites =
		(t_wall_sprites*)ft_memalloc(sizeof(t_wall_sprites)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->align = (t_v2*)ft_memalloc(sizeof(t_v2)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector align"));
	if (!(sector->scale = (t_v2*)ft_memalloc(sizeof(t_v2)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector scale"));
	if (!(sector->selected = (int*)ft_memalloc(sizeof(int)
		* (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	return (init_new_sector_arrays2(sector));
}
