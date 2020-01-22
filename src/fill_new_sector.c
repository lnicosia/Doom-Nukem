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

//	PROTECTION!!

void	revert_sector(t_sector *sector, t_env *env)
{
	int			i;
	int			index;
	int			j;
	short		*tmp;

	i = 1;
	j = 1;
	if (!(tmp = (short *)ft_memalloc(sizeof(short) * (sector->nb_vertices + 1))))
		return ;
	tmp[0] = sector->vertices[0];
	while (i < sector->nb_vertices)
	{
		if (env->editor.reverted)
			index = sector->nb_vertices - j;
		else
			index = j;
		tmp[i] = sector->vertices[index];
		i++;
		j++;
	}
	tmp[sector->nb_vertices] = tmp[0];
	free(sector->vertices);
	sector->vertices = tmp;
}

//	PROTECTION!!

int		fill_new_sector(t_sector *sector, t_env *env)
{
	int			i;
	size_t		j;
	int			index;
	t_list		*tmp;
	t_vertex	*vertex;

	tmp = env->editor.current_vertices;
	i = 0;
	while (tmp)
	{
		vertex = (t_vertex*)tmp->content;
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
		set_sector_wall_map_array(sector,
		env->wall_textures[sector->textures[index]], index, env);
		tmp = tmp->next;
		i++;
	}
	if (!env->editor.reverted)
    {
		sector->portals[sector->nb_vertices] = 1;
        sector->vertices[sector->nb_vertices] = sector->vertices[0];
        sector->neighbors[sector->nb_vertices] = sector->neighbors[0];
        sector->textures[sector->nb_vertices] = sector->textures[0];
        sector->wall_sprites[sector->nb_vertices] = sector->wall_sprites[0];
        sector->align[sector->nb_vertices] = sector->align[0];
        sector->scale[sector->nb_vertices] = sector->scale[0];
        sector->wall_sprites[sector->nb_vertices].nb_sprites = 0;
		if (!(sector->walls_map_lvl[sector->nb_vertices]
			= (double*)ft_memalloc(sizeof(double)
			* env->wall_textures[sector->textures[sector->nb_vertices]].nb_maps)))
			return (ft_perror("Could not malloc sector walls map lvl"));
		set_sector_wall_map_array(sector,
		env->wall_textures[sector->textures[sector->nb_vertices]],
		sector->nb_vertices, env);
    }
    else
    {
		sector->portals[0] = 1;
        sector->vertices[0] = sector->vertices[sector->nb_vertices];
        sector->neighbors[0] = sector->neighbors[sector->nb_vertices];
        sector->textures[0] = sector->textures[sector->nb_vertices];
        sector->wall_sprites[0] = sector->wall_sprites[sector->nb_vertices];
        sector->align[0] = sector->align[sector->nb_vertices];
        sector->scale[0] = sector->scale[sector->nb_vertices];
        sector->wall_sprites[0].nb_sprites = 0;
		if (!(sector->walls_map_lvl[0] = (double*)ft_memalloc(sizeof(double)
			* env->wall_textures[sector->textures[0]].nb_maps)))
			return (ft_perror("Could not malloc sector walls map lvl"));
		set_sector_wall_map_array(sector,
		env->wall_textures[sector->textures[0]],
		0, env);
    }
	j = 0;
	while (j < env->wall_textures[sector->ceiling_texture].nb_maps)
	{
		sector->ceiling_scale[j].x = (env->wall_textures[sector->ceiling_texture].surface->w / sector->ceiling_map_scale.x)
		/ pow(2, env->wall_textures[sector->ceiling_texture].nb_maps - 1 - j);
		sector->ceiling_scale[j].y = (env->wall_textures[sector->ceiling_texture].surface->h / sector->ceiling_map_scale.y)
		/ pow(2, env->wall_textures[sector->ceiling_texture].nb_maps - 1 - j);
		j++;
	}
	j = 0;
	while (j < env->wall_textures[sector->floor_texture].nb_maps)
	{
		sector->floor_scale[j].x = (env->wall_textures[sector->floor_texture].surface->w / sector->floor_map_scale.x)
		/ pow(2, env->wall_textures[sector->floor_texture].nb_maps - 1 - j);
		sector->floor_scale[j].y = (env->wall_textures[sector->floor_texture].surface->h / sector->floor_map_scale.y)
		/ pow(2, env->wall_textures[sector->floor_texture].nb_maps - 1 - j);
		j++;
	}
	return (0);
}
