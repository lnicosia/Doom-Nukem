/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:43:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 19:10:49 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_vertex.h"

int		update_sector_textures(t_env *env, int sect)
{
	int	i;
	t_sector *sector;

	i = 0;
	sector = &env->sectors[sect];
	while (i < sector->nb_vertices)
	{
		if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[i]],
		i, env))
			return (-1);
		i++;
	}
	if (set_sector_ceiling_map_array(sector,
	&env->wall_textures[sector->ceiling_texture], env))
		return (-1);
	if (set_sector_floor_map_array(sector,
	&env->wall_textures[sector->floor_texture], env))
		return (-1);
	return (0);
}

int     modify_sector(t_env *env, int sector)
{
    int j;

    j = 0;
    while (j < env->sectors[sector].nb_vertices)
    {
        if (env->sectors[sector].vertices[j] == env->editor.add.v1
		  	|| env->sectors[sector].vertices[j] == env->editor.add.v2)
		{
		  	if (realloc_sector_arrays(env, sector, j))
			 	return (-1);
			break;
		}
        j++;
    }
	if (update_sector_textures(env, sector))
		return (-1);
	update_sector_slope(env, &env->sectors[sector]);
	update_sector_entities_z(env, sector);
	return (0);
}

int		modify_vertices(t_env *env)
{
	if (!(env->vertices = (t_vertex *)ft_realloc(env->vertices,
		sizeof(t_vertex) * env->nb_vertices,
		sizeof(t_vertex) * (env->nb_vertices + 1))))
		return (ft_perror("Could not realloc env vertices"));
	env->nb_vertices++;
	env->vertices[env->nb_vertices - 1].x =
	round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	env->vertices[env->nb_vertices - 1].y =
	round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	env->vertices[env->nb_vertices - 1].num = env->nb_vertices - 1;
	return (0);
}

int     add_vertex_in_sector(t_env *env)
{
    int             i;

	i = 1;
    if (!(env->editor.add.sector_list = get_sectors_list(env,
		env->editor.add.v1, env->editor.add.v2)))
    	return (1);
	if (modify_vertices(env))
		return (-1);
	i = 1;
	while (i <= env->editor.add.sector_list[0])
	{
    	if (modify_sector(env, env->editor.add.sector_list[i]))
			return (-1);
		i++;
	}
	env->editor.add.v1 = -1;
	env->editor.add.v2 = -1;
    return (0);
}
