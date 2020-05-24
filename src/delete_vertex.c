/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:10:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 15:59:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

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
				if (update_sector(&env->sectors[i], j))
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

int		delete_vertex2(int vertex, t_env *env)
{
	int	i;

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
	if (update_entities_sectors(env))
		return (-1);
	env->editor.selected_vertex = -1;
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
	return (delete_vertex2(vertex, env));
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
