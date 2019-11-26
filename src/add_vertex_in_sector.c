/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:43:33 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/26 13:12:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "add_vertex.h"

int		*get_sectors_list(t_env *env, int v1, int v2)
{
	int	*sectors;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	if (!(sectors = (int *)malloc(sizeof(int) * 2)))
		return (0);
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (((j > 0 && env->sectors[i].vertices[j] == v1 && (env->sectors[i].vertices[j - 1] == v2
			|| env->sectors[i].vertices[j + 1] == v2)))
			|| (env->sectors[i].vertices[j] == v1 && j == 0
			&& (env->sectors[i].vertices[env->sectors[i].nb_vertices - 1] == v2
			|| env->sectors[i].vertices[j + 1] == v2)))
			{
				if (!(sectors = (int *)ft_realloc(sectors, sizeof(int) * k, sizeof(int) * (k + 1))))
					return (0);
				sectors[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	sectors[0] = k - 1;
    if (k)
	    return (sectors);
    return (NULL);
}

int		select_vertices(t_env *env)
{
	if (env->editor.select_vertex_on_going)
	{
		if (env->editor.add.v1 == -1)
	        env->editor.add.v1 = env->editor.selected_vertex;
	    else if(env->editor.selected_vertex != env->editor.add.v1 && env->editor.add.v2 == -1)
		{
	        env->editor.add.v2 = env->editor.selected_vertex;
			env->editor.select_vertex_on_going = 0;
		}
	}
	else if (env->editor.add.v1 != -1 && env->editor.add.v2 != -1)
    	return (1);
	return (0);
}

int		modify_vertices_in_sector(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].vertices = (short *)ft_realloc(env->sectors[sector].vertices, sizeof(short)
	* (env->sectors[sector].nb_vertices + 1), sizeof(short) * (env->sectors[sector].nb_vertices + 2))))
		return (ft_perror("Could not realloc vertices"));
	env->sectors[sector].nb_vertices++;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].vertices[i] = 	env->sectors[sector].vertices[i - 1];
		i--;
	}
	env->sectors[sector].vertices[i] = env->vertices[env->nb_vertices - 1].num;
	env->sectors[sector].vertices[env->sectors[sector].nb_vertices] = env->sectors[sector].vertices[0];
	int	j = 0;
	while (j <= env->sectors[0].nb_vertices)
	{
		ft_printf("IN vertices[%d]: %d\n", j, env->sectors[sector].vertices[j]);
		j++;
	}
	return (0);
}

int		modify_textures(t_env *env, int index, int sector)
{
	int	i;

	i = 0;
	if (!(env->sectors[sector].textures = (short *)ft_realloc(env->sectors[sector].textures, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc textures"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
		i--;
	}
	env->sectors[sector].textures[i] = env->sectors[sector].textures[i + 1];
	return (0);
}

int		modify_double_tab_in_sector(t_env *env, int index, int sector, double **tab)
{
	int	i;

	if (!(*tab = (double *)ft_realloc(*tab, sizeof(double)
	* env->sectors[sector].nb_vertices, sizeof(double) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc double tab"));
	i = 0;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i + 1];
	return (0);
}

int		modify_wall_map_level(t_env *env, int index, int sector, double **tab)
{

}

int		modify_neighbors(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].neighbors = (short *)ft_realloc(env->sectors[sector].neighbors, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc neighbors"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
		i--;
	}
	env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i + 1];
	return (0);
}

int     modify_sector(t_env *env, int sector)
{
    int j;
	int	i;

	i = 0;
    j = 0;
    while (j < env->sectors[sector].nb_vertices)
    {
        if (env->sectors[sector].vertices[j] == env->editor.add.v1 || env->sectors[sector].vertices[j] == env->editor.add.v2)
		{
			if ((env->editor.add.v1 == env->sectors[sector].vertices[0]
			&& env->editor.add.v2 == env->sectors[sector].vertices[env->sectors[sector].nb_vertices - 1])
			|| (env->editor.add.v2 == env->sectors[sector].vertices[0]
			&& env->editor.add.v1 == env->sectors[sector].vertices[env->sectors[sector].nb_vertices - 1]))
				j = env->sectors[sector].nb_vertices - 1;
			if (modify_vertices_in_sector(env, j, sector))
				return (-1);
			if (modify_textures(env, j, sector))
				return (-1);
			if (modify_neighbors(env, j, sector))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].floors))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].ceilings))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors1))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings1))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings2))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors2))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].wall_width))
				return (-1);
			if (modify_wall_map_lvl(env, j, &env->sectors[sector].walls_map_lvl))
				return (-1);
			break;
		}
        j++;
    }
	return (0);
}

int		modify_vertices(t_env *env)
{
	double min;
	double max;

	if (!(env->vertices = (t_vertex *)ft_realloc(env->vertices, sizeof(t_vertex)
			* env->nb_vertices, sizeof(t_vertex) * (env->nb_vertices + 1))))
		return (ft_perror("Could not realloc env vertices"));
	env->nb_vertices++;
	min = env->vertices[env->editor.add.v1].x < env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].x : env->vertices[env->editor.add.v2].x;
	max = env->vertices[env->editor.add.v1].x > env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].x : env->vertices[env->editor.add.v2].x;
	env->vertices[env->nb_vertices - 1].num = env->nb_vertices - 1;
	env->vertices[env->nb_vertices - 1].x =	min + ((max - min) / 2);
	min = env->vertices[env->editor.add.v1].x < env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].y : env->vertices[env->editor.add.v2].y;
	max = env->vertices[env->editor.add.v1].x > env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].y : env->vertices[env->editor.add.v2].y;
	env->vertices[env->nb_vertices - 1].y = min + ((max - min) / 2);
	return (0);
}

int     add_vertex_in_sector(t_env *env)
{
    int             i;

	i = 1;
    if ((select_vertices(env)))
    {
        if (!(env->editor.add.sector_list = get_sectors_list(env, env->editor.add.v1, env->editor.add.v2)))
            return (printf("selected vertices aren't in the same sector or not next to each others\n"));
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
    }
    return (0);
}