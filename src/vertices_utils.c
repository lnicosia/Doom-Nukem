/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:35:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/04 17:22:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
 **	Returns 0 if the given vertex does not belong to any sector
 */

int		*get_vertex_sectors(t_env *env, int index)
{
	int	*sectors;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	if (!(sectors= (int *)ft_memalloc(sizeof(int) * 2)))
		return (0);
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == index)
			{
				if (!(sectors = (int *)ft_realloc(sectors,sizeof(int) * k,
					sizeof(int) * (k + 1))))
					return (0);
				sectors[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	sectors[0] = k - 1;
	return (sectors);
}

int		is_vertex_used_by_others(t_env *env, int vertex, int sector)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != sector)
		{
			j = 0;
			while (j < env->sectors[i].nb_vertices)
			{
				if (env->sectors[i].vertices[j] == vertex)
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
**	Returns 0 if the given vertex does not belong to any sector
*/

int		is_vertex_used(t_env *env, int vertex)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	Returns 0 if the given vertex will not belong to any sector
**	after the given sector is deleted
*/

int		is_vertex_going_to_be_used(t_env *env, int sector, int vertex)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != sector)
		{
			j = 0;
			while (j < env->sectors[i].nb_vertices)
			{
				if (env->sectors[i].vertices[j] == vertex)
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
**	Returns 0 if the given vertex does not belong to the current sector
*/

int		current_vertices_contains(t_env *env, int vertex)
{
	t_list		*tmp;
	t_vertex	*v;

	tmp = env->editor.current_vertices;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		if (v->num == vertex)
		{
			if (vertex == env->editor.start_vertex)
			{
				if (ft_lstlen(env->editor.current_vertices) < 3)
					return (1);
			}
			else
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
