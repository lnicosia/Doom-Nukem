/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:10:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/20 17:10:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
					env->sectors[i].vertices = ft_delindex(env->sectors[i].vertices,
							sizeof(short) * (env->sectors[i].nb_vertices + 1),
							sizeof(short),
							sizeof(short) * j);
					env->sectors[i].nb_vertices--;
			}
			if (env->sectors[i].vertices[j] > vertex)
				env->sectors[i].vertices[j]--;
			j++;
		}
		env->sectors[i].vertices[env->sectors[i].nb_vertices] = env->sectors[i].vertices[0];
		i++;
	}
	return (0);
}

int		delete_vertex(t_env *env, int vertex)
{
	int			i;

	env->vertices = ft_delindex(env->vertices,
			sizeof(t_vertex) * env->nb_vertices,
			sizeof(t_vertex),
			sizeof(t_vertex) * vertex);
	env->nb_vertices--;
	i = vertex;
	while (i < env->nb_vertices)
	{
		env->vertices[i].num--;
		i++;
	}
	if (env->nb_sectors)
		if (modify_sectors(env, vertex))
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
			if (delete_vertex(env, i))
				return (-1);
			i--;
		}
		i++;
	}
	return (0);
}
