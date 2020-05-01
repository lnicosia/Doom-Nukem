/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sector_with_deleted_vertex.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:39:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_sector3(t_sector *sector, int vertex)
{
	sector->wall_sprites = (t_wall_sprites*)ft_delindex(sector->wall_sprites,
		sizeof(t_wall_sprites) * (sector->nb_vertices + 1),
		sizeof(t_wall_sprites), sizeof(t_wall_sprites) * vertex);
	sector->nb_vertices--;
	if (sector->nb_vertices > 0 && (!sector->vertices))
		return (-1);
	if (sector->start_floor_slope >= sector->nb_vertices)
		sector->start_floor_slope--;
	if (sector->start_ceiling_slope >= sector->nb_vertices)
		sector->start_ceiling_slope--;
	return (0);
}

int		update_sector2(t_sector *sector, int vertex)
{
	sector->clipped_ceilings1 = (double*)ft_delindex(sector->clipped_ceilings1,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	sector->clipped_ceilings2 = (double*)ft_delindex(sector->clipped_ceilings2,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	sector->wall_width = (double*)ft_delindex(sector->wall_width,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	ft_memdel((void**)&sector->walls_map_lvl[vertex]);
	sector->walls_map_lvl = (double**)ft_delindex(sector->walls_map_lvl,
		sizeof(double*) * (sector->nb_vertices + 1), sizeof(double*),
		sizeof(double*) * vertex);
	sector->scale = (t_v2*)ft_delindex(sector->scale,
		sizeof(t_v2) * (sector->nb_vertices + 1), sizeof(t_v2),
		sizeof(t_v2) * vertex);
	sector->align = (t_v2*)ft_delindex(sector->align,
		sizeof(t_v2) * (sector->nb_vertices + 1), sizeof(t_v2),
		sizeof(t_v2) * vertex);
	sector->wall_bullet_holes = (t_list**)ft_delindex(sector->wall_bullet_holes,
		sizeof(t_list*) * (sector->nb_vertices + 1), sizeof(t_list*),
		sizeof(t_list*) * vertex);
	free_wall_sprites(&sector->wall_sprites[vertex]);
	return (update_sector3(sector, vertex));
}

int		update_sector(t_sector *sector, int vertex)
{
	sector->vertices = (int*)ft_delindex(sector->vertices,
		sizeof(int) * (sector->nb_vertices + 1), sizeof(int),
		sizeof(int) * vertex);
	sector->textures = (int*)ft_delindex(sector->textures,
		sizeof(int) * (sector->nb_vertices + 1), sizeof(int),
		sizeof(int) * vertex);
	sector->neighbors = (int*)ft_delindex(sector->neighbors,
		sizeof(int) * (sector->nb_vertices + 1), sizeof(int),
		sizeof(int) * vertex);
	sector->portals = (int*)ft_delindex(sector->portals,
		sizeof(int) * (sector->nb_vertices + 1), sizeof(int),
		sizeof(int) * vertex);
	sector->floors = (double*)ft_delindex(sector->floors,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	sector->ceilings = (double*)ft_delindex(sector->ceilings,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	sector->clipped_floors1 = (double*)ft_delindex(sector->clipped_floors1,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	sector->clipped_floors2 = (double*)ft_delindex(sector->clipped_floors2,
		sizeof(double) * (sector->nb_vertices + 1), sizeof(double),
		sizeof(double) * vertex);
	return (update_sector2(sector, vertex));
}
