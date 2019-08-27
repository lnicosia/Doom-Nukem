/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:50:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/27 11:33:34 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
int	get_existing_not_dragged_vertex(t_env *env)
{
	t_vertex	vertex;
	int			i;

	i = 0;
	while (i < env->nb_vertices)
	{
		vertex = env->vertices[i];
		if (round((env->sdl.mx - env->editor.center.x) / env->editor.scale) == vertex.x
				&& round((env->sdl.my - env->editor.center.y) / env->editor.scale) == vertex.y
				&& vertex.num != env->vertices[env->editor.selected_vertex].num)
			return (vertex.num);
		i++;
	}
	return (-1);
}

int	get_existing_vertex(t_env *env)
{
	t_vertex	vertex;
	int			i;

	i = 0;
	while (i < env->nb_vertices)
	{
		vertex = env->vertices[i];
		if (round((env->sdl.mx - env->editor.center.x) / env->editor.scale) == vertex.x
				&& round((env->sdl.my - env->editor.center.y) / env->editor.scale) == vertex.y)
			return (vertex.num);
		i++;
	}
	return (-1);
}
