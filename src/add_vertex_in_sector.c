/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:43:33 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/21 17:15:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "add_vertex.h"

int		*get_sectors_list(t_env *env, int v1, int v2)
{
	ft_printf("trying to create sector list\n");
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
	i = 0;
	while (i < k)
	{
		if (i == 0)
			ft_printf("nb_");
		ft_printf("sector: %d\n", sectors[i]);
		i++;
	}
    if (k)
	    return (sectors);
    return (NULL);
}

int		select_vertices(t_env *env)
{
	if (env->editor.select_vertex_on_going)
	{
		if (env->editor.add.v1 == -1)
		{
	        env->editor.add.v1 = env->editor.selected_vertex;
			ft_printf("selecting first vertex | %d\n", env->editor.add.v1);
		}
	    else if(env->editor.selected_vertex != env->editor.add.v1 && env->editor.add.v2 == -1)
		{
	        env->editor.add.v2 = env->editor.selected_vertex;
			ft_printf("second vertex | %d\n", env->editor.add.v2);
			env->editor.select_vertex_on_going = 0;
		}
	}
	else if (env->editor.add.v1 != -1 && env->editor.add.v2 != -1)
	{
		ft_printf("v1: %d | v2: %d\n", env->editor.add.v1, env->editor.add.v2);
    	return (1);
	}
	return (0);
}

void	modify_vertices_in_sector(t_env *env, int index, int sector)
{
	int	i;

	i = 0;
	ft_printf("show sector old vertices | nb: %d\n", env->sectors[sector].nb_vertices);
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("vertex: %d\n", env->sectors[sector].vertices[i]);
		i++;
	}
	if (!(env->sectors[sector].vertices = (short *)ft_realloc(env->sectors[sector].vertices, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return ;
	env->sectors[sector].nb_vertices++;
	i = env->sectors[sector].nb_vertices - 1;
	while (i > index)
	{
		env->sectors[sector].vertices[i] = 	env->sectors[sector].vertices[i - 1];
		i--;
	}
	env->sectors[sector].vertices[i] = env->nb_vertices - 1;
	i = 0;
	ft_printf("\nshow sector new vertices | nb: %d\n", env->sectors[sector].nb_vertices);
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("vertex: %d\n", env->sectors[sector].vertices[i]);
		i++;
	}
}

void	modify_neighbors(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].neighbors = (short *)ft_realloc(env->sectors[sector].neighbors, sizeof(short)
	* env->sectors[sector].nb_vertices - 1, sizeof(short) * (env->sectors[sector].nb_vertices))))
		return ;
	i = 0;
/*	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("vertex: %d\n", env->sectors[sector].vertices[i]);
		i++;
	}*/
	i = env->sectors[sector].nb_vertices - 1;
	while (i > index)
	{
		env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
		i--;
	}
	env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i +1];
}

void	modify_textures(t_env *env, int index, int sector)
{
	int	i;

	i = 0;
	ft_printf("\nshow sector new textures | nb: %d\n", env->sectors[sector].nb_vertices - 1);
	while (i < env->sectors[sector].nb_vertices - 1)
	{
		ft_printf("texture: %d\n", env->sectors[sector].textures[i]);
		i++;
	}
	if (!(env->sectors[sector].textures = (short *)ft_realloc(env->sectors[sector].textures, sizeof(short)
	* env->sectors[sector].nb_vertices - 1, sizeof(short) * (env->sectors[sector].nb_vertices))))
		return ;
	i = env->sectors[sector].nb_vertices - 1;
	while (i > index)
	{
		env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
		i--;
	}
	env->sectors[sector].textures[i] = env->sectors[sector].textures[i + 1];
	i = 0;
	ft_printf("\nshow sector new textures | nb: %d\n", env->sectors[sector].nb_vertices);
	while (i < env->sectors[sector].nb_vertices)
	{
		ft_printf("texture: %d\n", env->sectors[sector].textures[i]);
		i++;
	}
}

int     modify_sector(t_env *env, int sector)
{
    int j;

    j = 0;
	ft_printf("modifying sectors\n");
    while (j < env->sectors[sector].nb_vertices)
    {
		ft_printf("j: %d | nb_vertices: %d\n", j, env->sectors[sector].nb_vertices);
        if (env->sectors[sector].vertices[j] == env->editor.add.v1 || env->sectors[sector].vertices[j] == env->editor.add.v2)
		{
			modify_vertices_in_sector(env, j, sector);
			modify_textures(env, j, sector);
		/*	modify_neighbors(env, j, sector);*/

			break;
		}
        j++;
    }
	return (0);
}

void	modify_vertices(t_env *env)
{
	if (!(env->vertices = (t_vertex *)ft_realloc(env->vertices, sizeof(t_vertex)
			* env->nb_vertices, sizeof(t_vertex) * (env->nb_vertices + 1))))
		return ;
	env->nb_vertices++;
	env->vertices[env->nb_vertices -1].num = env->nb_vertices - 1;
	env->vertices[env->nb_vertices -1].x =	(env->vertices[env->editor.add.v1].x - env->vertices[env->editor.add.v2].x) / 2;
	env->vertices[env->nb_vertices -1].y = 	(env->vertices[env->editor.add.v1].y - env->vertices[env->editor.add.v2].y) / 2;
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
    return (0);
}