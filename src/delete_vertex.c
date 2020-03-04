/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:10:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 16:00:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_sector(t_sector *sector, int vertex, t_env *env)
{
	(void)env;
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
	sector->wall_sprites = (t_wall_sprites*)ft_delindex(sector->wall_sprites,
		sizeof(t_wall_sprites) * (sector->nb_vertices + 1),
		sizeof(t_wall_sprites), sizeof(t_wall_sprites) * vertex);
	sector->nb_vertices--;
	if (sector->nb_vertices > 0 && (!sector->vertices))
		return (-1);
	return (0);
}

int		modify_sectors(t_env *env, int vertex)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == vertex)
			{
				if (update_sector(&env->sectors[i], j, env))
					return (-1);
			}
			if (env->sectors[i].vertices[j] > vertex)
				env->sectors[i].vertices[j]--;
			j++;
		}
		env->sectors[i].vertices[env->sectors[i].nb_vertices] =
		env->sectors[i].vertices[0];
		i++;
	}
	return (0);
}

int		delete_vertex(void *param)
{
	t_env		*env;
	int			i;
	int			vertex;

	env = (t_env*)param;
	vertex = env->editor.selected_vertex;
	env->vertices = (t_vertex*)ft_delindex(env->vertices,
			sizeof(t_vertex) * env->nb_vertices,
			sizeof(t_vertex),
			sizeof(t_vertex) * vertex);
	env->nb_vertices--;
	if (env->nb_vertices > 0 && !env->vertices)
		return (-1);
	i = vertex;
	while (i < env->nb_vertices)
	{
		env->vertices[i].num--;
		i++;
	}
	if (env->editor.current_vertices)
	{
		env->editor.selected_vertex = -1;
		return (0);
	}
	if (env->nb_sectors)
	{
		if (modify_sectors(env, vertex))
			return (-1);
	}
	if (delete_invalid_sectors(env))
		return (-1);
	if (delete_invalid_vertices(env))
		return (-1);
	clear_portals(env);
	i = 0;
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}
	if (delete_linked_events(env))
		return (-1);
	env->editor.selected_vertex = -1;
	return (0);
}

int		delete_invalid_vertices(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_vertices)
	{
		if (!is_vertex_used(env, i))
		{
			env->editor.selected_vertex = i;
			if (delete_vertex(env))
				return (-1);
			i--;
		}
		i++;
	}
	return (0);
}
