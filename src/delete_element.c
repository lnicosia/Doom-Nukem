/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/26 14:25:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	modify_vertices_list_in_sectors(t_env *env, int *sectors, int size, int vertex)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < size)
		{
			if (env->sectors[i].num == sectors[j])
				break;
			j++;
		}
		if (j == size)
		{
			k = 0;
			while (k < env->sectors[i].nb_vertices)
			{
				if (env->sectors[i].vertices[k] > vertex)
					env->sectors[i].vertices[k]--;;
				k++;
			}
		}
		i++;
	}
}

void	modify_vertices_in_sectors(t_env *env, int *sectors, int size, int vertex)
{
	int			i;
	int			j;
	int			index;
	t_sector	tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		index = 0;
		while (index < env->sectors[sectors[i]].nb_vertices)
		{
			if (env->sectors[sectors[i]].vertices[index] == vertex)
				break;
			index++;
		}
		if (env->sectors[sectors[i]].nb_vertices - 1 < 3)
			delete_sector(env);
		else
		{
			j = 0;
			tmp = env->sectors[sectors[i]];
			env->sectors[sectors[i]].vertices = ft_delindex(env->sectors[sectors[i]].vertices,
					(env->sectors[sectors[i]].nb_vertices + 1) * sizeof(short),
					sizeof(short),
					index * sizeof(short));
			env->sectors[sectors[i]].nb_vertices--;
			while (j < env->sectors[sectors[i]].nb_vertices)
			{
				if (env->sectors[sectors[i]].vertices[j] > index)
					env->sectors[sectors[i]].vertices[j]--;
				j++;
			}	
			env->sectors[sectors[i]].vertices[env->sectors[sectors[i]].nb_vertices] = env->sectors[sectors[i]].vertices[0];
		}
		i++;
	}
}

void	modify_sectors(t_env *env, int vertex)
{
	int	i;
	int	j;
	//int	*list_sectors;
	//int	count;

	i = 0;
	//count = 0;
	//list_sectors = NULL;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j <= env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == vertex)
			{
				/*if (!count)
				{
					if (!(list_sectors = (int*)malloc(sizeof(int) * (count + 1))))
						return ;
				}
				else
				{
					if (!(list_sectors = (int *)ft_realloc(list_sectors, sizeof(int) * count, sizeof(int) * (count + 1))))
						return ;
				}
				list_sectors[count] = i;
				count++;*/
				env->sectors[i].vertices = ft_delindex(env->sectors[i].vertices,
						sizeof(short) * (env->sectors[i].nb_vertices + 1),
						sizeof(short),
						sizeof(short) * j);
				env->sectors[i].nb_vertices--;
			}
			if (env->sectors[i].vertices[j] >= vertex)
				env->sectors[i].vertices[j]--;
			j++;
		}
		i++;
	}
	//modify_vertices_in_sectors(env, list_sectors, count, vertex);
	//modify_vertices_list_in_sectors(env, list_sectors, count, vertex);
	//ft_memdel((void**)&list_sectors);
}

int	delete_vertex(t_env *env, int vertex)
{
	int			i;

	env->vertices = ft_delindex(env->vertices,
			sizeof(t_vertex) * env->nb_vertices,
			sizeof(t_vertex),
			sizeof(t_vertex) * vertex);
	env->nb_vertices--;
	i = 0;
	while (i < env->nb_vertices)
	{
		if (env->vertices[i].num >= vertex)
			env->vertices[i].num--;
		i++;
	}
	if (env->nb_sectors)
		modify_sectors(env, vertex);
	env->editor.selected_vertex = -1;
	return (0);
}

int	delete_object(t_env *env)
{
	env->objects = ft_delindex(env->objects,
			env->nb_objects * sizeof(t_object),
			sizeof(t_object),
			env->editor.selected_object * sizeof(t_object));
	env->nb_objects--;
	env->editor.selected_object = -1;
	return (0);
}
