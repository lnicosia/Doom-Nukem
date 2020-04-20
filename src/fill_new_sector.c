/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_sector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:05:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/13 13:39:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		fill_sector_with_current_vertex(t_vertex *vertex, t_sector *sector,
int i, t_env *env)
{
  	int	index;

	if (env->editor.reverted)
		index = sector->nb_vertices - i;
	else
		index = i;
	sector->vertices[index] = vertex->num;
	sector->neighbors[index] = -1;
	sector->portals[index] = 1;
	sector->textures[index] = env->editor.current_texture;
	sector->wall_sprites[index].nb_sprites = 0;
	sector->align[index] = new_v2(0, 0);
	sector->scale[index] = new_v2(10, 10);
	ft_bzero(&sector->wall_sprites[index], sizeof(t_wall_sprites));
	if (!(sector->walls_map_lvl[index] = (double*)ft_memalloc(sizeof(double)
		* env->wall_textures[sector->textures[index]].nb_maps)))
		return (ft_perror("Could not malloc sector walls map lvl"));
	if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[index]], index, env))
	  	return (-1);
	return (0);
}

int		fill_sector_extremities(t_sector *sector, t_env *env)
{
	if (!env->editor.reverted)
    {
		if (fill_sector_last_vertex(sector, env))
		  	return (-1);
    }
    else
    {
		if (fill_sector_last_vertex(sector, env))
		  	return (-1);
    }
	return (0);
}

void	precompute_ceiling_scales(t_sector *sector, t_env *env)
{
	size_t		j;

	j = 0;
	while (j < env->wall_textures[sector->ceiling_texture].nb_maps)
	{
		sector->ceiling_scale[j].x =
		(env->wall_textures[sector->ceiling_texture].surface->w
		/ sector->ceiling_map_scale.x)
		/ pow(2, env->wall_textures[sector->ceiling_texture].nb_maps - 1 - j);
		sector->ceiling_scale[j].y =
		(env->wall_textures[sector->ceiling_texture].surface->h
		/ sector->ceiling_map_scale.y)
		/ pow(2, env->wall_textures[sector->ceiling_texture].nb_maps - 1 - j);
		j++;
	}
}

void	precompute_floor_scales(t_sector *sector, t_env *env)
{
	size_t		j;

	j = 0;
	while (j < env->wall_textures[sector->floor_texture].nb_maps)
	{
		sector->floor_scale[j].x =
		(env->wall_textures[sector->floor_texture].surface->w
		/ sector->floor_map_scale.x)
		/ pow(2, env->wall_textures[sector->floor_texture].nb_maps - 1 - j);
		sector->floor_scale[j].y =
		(env->wall_textures[sector->floor_texture].surface->h
		/ sector->floor_map_scale.y)
		/ pow(2, env->wall_textures[sector->floor_texture].nb_maps - 1 - j);
		j++;
	}
}

int		fill_new_sector(t_sector *sector, t_env *env)
{
	int			i;
	t_list		*tmp;

	tmp = env->editor.current_vertices;
	i = 0;
	while (tmp)
	{
		if (fill_sector_with_current_vertex((t_vertex*)tmp->content, sector, i,
		  	env))
		  	return (-1);
		tmp = tmp->next;
		i++;
	}
	if (fill_sector_extremities(sector, env))
	  	return (-1);
	precompute_floor_scales(sector, env);
	precompute_ceiling_scales(sector, env);
	return (0);
}
