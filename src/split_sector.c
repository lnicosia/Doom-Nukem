/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:17:28 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 15:49:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_sector_data(t_env *env, int start, int end, t_sector *sector)
{
	int	i;

	i = end - 1;	
	while (i > start)
	{
	  	if (update_current_wall(env, i, sector))
		  	return (-1);
		i--;
	}
	clear_portals(env);
	i = 0;
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}
	return (0);
}

int		copying_original_sector_data(t_env *env)
{
	int	origin;
	int	new;
	int	i;

	i = 0;
	origin = env->editor.split.sector;
	new = env->nb_sectors - 1;
	while (i < env->sectors[new].nb_vertices)
	{
		env->sectors[new].textures[i] = env->sectors[origin].textures[0];
		i++;
	}
	env->sectors[new].ceiling_texture = env->sectors[origin].ceiling_texture;
	env->sectors[new].floor_texture = env->sectors[origin].floor_texture;
	env->sectors[new].floor = env->sectors[origin].floor;
	env->sectors[new].floor_slope = env->sectors[origin].floor_slope;
	env->sectors[new].ceiling = env->sectors[origin].ceiling;
	env->sectors[new].ceiling_slope = env->sectors[origin].ceiling_slope;
	return (0);
}

int		create_new_sector(t_env *env, int start, int end, t_sector *sector)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (add_vertex_to_current_sector(env, (int)sector->vertices[i]))
			return (-1);
		i++;
	}
	env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
	env->editor.start_vertex = -1;
	if (add_sector(env))
		return (ft_printf("Error while creating new sector\n"));
	if (copying_original_sector_data(env))
		return (-1);
	return (0);
}

int		split_sector2(int start, int end, t_env *env)
{
	t_sector	*sector;

	sector = &env->sectors[env->editor.split.sector];
	free_current_vertices(env);
	if (update_sector_data(env, start, end , sector))
		return (-1);
	if (set_sector_floor_map_array(&env->sectors[env->nb_sectors - 1], 
		&env->wall_textures[env->sectors[env->nb_sectors - 1].floor_texture],
		env))
		return (-1);
	if (set_sector_ceiling_map_array(&env->sectors[env->nb_sectors - 1], 
		&env->wall_textures[env->sectors[env->nb_sectors - 1].ceiling_texture],
		env))
		return (-1);
	update_sector_slope(env, &env->sectors[env->nb_sectors - 1]);
	env->editor.split.sector = -1;
	env->editor.split.v1 = -1;
	env->editor.split.v2 = -1;
	env->editor.divide_sector = 0;
	env->editor.split_sector = 0;
	return (0);
}

int		split_sector(t_env *env)
{
	int			i;
	int			start;
	int			end;
	t_sector	*sector;

	i = 0;
	start = -1;
	end = -1;
	sector = &env->sectors[env->editor.split.sector];
	while (i < sector->nb_vertices)
	{
		if (start == -1 && (sector->vertices[i] == env->editor.split.v1
		|| sector->vertices[i] == env->editor.split.v2))
			start = i;
		else if (start != -1 && (sector->vertices[i] == env->editor.split.v1
		|| sector->vertices[i] == env->editor.split.v2))
			end = i;
		i++;
	}
	free_current_vertices(env);
	if (create_new_sector(env, start, end, sector))
		return (-1);
	return (split_sector2(start, end, env));
}
