/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/21 18:12:05 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	modify_vertices_in_sectors(t_env *env, int	*sectors, int size)
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
			if (env->sectors[sectors[i]].vertices[index] == env->editor.select_vertex)
				break;
			index++;
		}
		if (env->sectors[sectors[i]].nb_vertices - 1 < 3)
			delete_sector(env);
		else
		{
			tmp = env->sectors[sectors[i]];
			env->sectors[sectors[i]].vertices = ft_delindex(env->sectors[sectors[i]].vertices,
					(env->sectors[sectors[i]].nb_vertices + 1) * sizeof(short),
					sizeof(short),
					index * sizeof(short));
			env->sectors[sectors[i]].nb_vertices--;
			while (j < env->sectors[sectors[i]].nb_vertices)
			{
				if (env->sectors[sectors[i]].vertices[j] > env->editor.select_vertex)
					env->sectors[sectors[i]].vertices[j]--;
				j++;
			}	
			env->sectors[sectors[i]].vertices[env->sectors[sectors[i]].nb_vertices] = env->sectors[sectors[i]].vertices[0];
		}
		i++;
	}
}

void	calc_sectors(t_env *env)
{
	int	i;
	int	j;
	int	*list_sectors;
	int	count;

	i = 0;
	count = 0;
	list_sectors = NULL;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{	
			if (env->sectors[i].vertices[j] == env->editor.select_vertex)
			{
				if (!count)
				{
					if(!(list_sectors = (int*)malloc(sizeof(int) * (count + 1))))
						return ;
				}
				else
				{
					if(!(list_sectors = (int *)ft_realloc(list_sectors, sizeof(int) * count, sizeof(int) * (count + 1))))
						return ;
				}
				list_sectors[count] = i;
				count++;
			}
			j++;
		}
		i++;
	}
	modify_vertices_in_sectors(env, list_sectors, count);
}

int	delete_vertex(t_env *env)
{
	t_vertex	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	(void)env;
	if (!(tmp = (t_vertex*)malloc(sizeof(t_vertex) * env->nb_vertices)))
		return (ft_printf("Deleting: failed copying vertices\n"));
	if (!env->editor.drag_vertex && !env->inputs.left_click
			&& env->sdl.mx <= 200 && env->flag)
	{
		env->flag = 0;
		tmp = env->vertices;
		env->vertices = ft_delindex(env->vertices,
				sizeof(t_vertex) * env->nb_vertices,
				sizeof(t_vertex),
				env->editor.select_vertex * sizeof(t_vertex));
		env->nb_vertices--;
		i = 0;
		while (i < env->nb_vertices)
		{
			if (env->vertices[i].num > env->editor.select_vertex)
				env->vertices[i].num--;
			i++;
		}
		if (env->nb_sectors)
			calc_sectors(env);
		env->editor.select_vertex = -1;
	}
	i = 0;
	return (0);
}

int	delete_object(t_env *env)
{
	t_object	*tmp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!(tmp = (t_object*)malloc(sizeof(t_object) * env->nb_objects)))
		return (ft_printf("Deleting: failed copying objects\n"));
	env->flag = 0;
	tmp = env->objects;
	env->objects = ft_delindex(env->objects,
			env->nb_objects * sizeof(t_object),
			sizeof(t_object),
			env->editor.select_object * sizeof(t_object));
	env->nb_objects--;
	if (!env->nb_objects && env->editor.objects == 1)
		env->editor.objects = 0;
	env->editor.select_object = -1;
	return (0);
}
