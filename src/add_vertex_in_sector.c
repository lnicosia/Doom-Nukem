/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:43:33 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/25 19:00:54 by sipatry          ###   ########.fr       */
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

void	modify_vertices_in_sector(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].vertices = (short *)ft_realloc(env->sectors[sector].vertices, sizeof(short)
	* env->sectors[sector].nb_vertices + 1, sizeof(short) * (env->sectors[sector].nb_vertices + 2))))
		return ;
	env->sectors[sector].nb_vertices++;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].vertices[i] = 	env->sectors[sector].vertices[i - 1];
		i--;
	}
	env->sectors[sector].vertices[i] = env->vertices[env->nb_vertices - 1].num;
	env->sectors[sector].vertices[env->nb_vertices] = env->sectors[sector].vertices[0];
	int	j = 0;
	while (j < env->sectors[0].nb_vertices)
	{
		ft_printf("IN vertices[%d]: %d\n", j, env->sectors[sector].vertices[j]);
		j++;
	}
}

void	modify_textures(t_env *env, int index, int sector)
{
	int	i;

	i = 0;
	if (!(env->sectors[sector].textures = (short *)ft_realloc(env->sectors[sector].textures, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return ;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
		i--;
	}
	env->sectors[sector].textures[i] = env->sectors[sector].textures[i + 1];
}

void	modify_double_tab_in_sector(t_env *env, int index, int sector, double **tab)
{
	int	i;

	if (!(*tab = (double *)ft_realloc(*tab, sizeof(double)
	* env->sectors[sector].nb_vertices, sizeof(double) * (env->sectors[sector].nb_vertices + 1))))
		return ;
	i = 0;
	ft_printf("sector: %d | nb_vertices: %d\n", sector, env->sectors[sector].nb_vertices);
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("IN floor: %d\n", env->sectors[sector].clipped_floors2[i]);
		i++;
	}
	ft_printf("\n");
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		*tab[i] = *tab[i - 1];
		i--;
	}
	*tab[i] = *tab[i + 1];
	i = 0;
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("floor: %d\n", env->sectors[sector].clipped_floors2[i]);
		i++;
	}
}

void	modify_neighbors(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].neighbors = (short *)ft_realloc(env->sectors[sector].neighbors, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return ;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
		i--;
	}
	env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i + 1];
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
			modify_vertices_in_sector(env, j, sector);
			modify_textures(env, j, sector);
			modify_neighbors(env, j, sector);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].floors);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].ceilings);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors1);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings1);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings2);
			modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors2);
			break;
		}
        j++;
    }
	return (0);
}

void	modify_vertices(t_env *env)
{
	double min;
	double max;

	if (!(env->vertices = (t_vertex *)ft_realloc(env->vertices, sizeof(t_vertex)
			* env->nb_vertices, sizeof(t_vertex) * (env->nb_vertices + 1))))
		return ;
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
}

int     add_vertex_in_sector(t_env *env)
{
    int             i;

	i = 1;
    if ((select_vertices(env)))
    {
        if (!(env->editor.add.sector_list = get_sectors_list(env, env->editor.add.v1, env->editor.add.v2)))
            return (printf("selected vertices aren't in the same sector or not next to each others\n"));
		modify_vertices(env);
		i = 1;
		while (i <= env->editor.add.sector_list[0])
        {
            modify_sector(env, env->editor.add.sector_list[i]);
            i++;
        }
		env->editor.add.v1 = -1;
		env->editor.add.v2 = -1;
    }
	int	j = 0;
	ft_printf("\n");
	while (j < env->sectors[0].nb_vertices + 1)
	{
		ft_printf("BEFORE OUT vertices[%d]: %d\n", j, env->sectors[0].vertices[j]);
		j++;
	}
    return (0);
}