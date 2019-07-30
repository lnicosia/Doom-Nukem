/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:57:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 10:45:23 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_current_vertices(t_env *env)
{
	t_list	*tmp;

	while (env->editor.current_vertices)
	{
		tmp = env->editor.current_vertices;
		env->editor.current_vertices = env->editor.current_vertices->next;
		ft_memdel(&tmp->content);
		free(tmp);
		tmp = NULL;
	}
}

int	add_vertex_to_current_sector(t_env *env, int num)
{
	t_list	*new;

	if (!(new = ft_lstnew(&env->vertices[num], sizeof(t_vertex))))
		return (ft_printf("Error when creating new vertex\n"));
	ft_lstpushback(&env->editor.current_vertices, new);
	return (0);
}

int	add_vertex(t_env *env)
{
	t_vertex	vertex;

	vertex.num = env->nb_vertices;
	vertex.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	vertex.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	if (!(env->vertices = (t_vertex*)ft_realloc(env->vertices, sizeof(t_vertex) * env->nb_vertices, sizeof(t_vertex) * (env->nb_vertices + 1))))
		return (ft_printf("Could not realloc vertices\n"));
	env->vertices[env->nb_vertices] = vertex;
	env->nb_vertices++;
	return (0);
}
