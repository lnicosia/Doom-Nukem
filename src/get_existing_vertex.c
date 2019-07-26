/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:50:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/26 12:57:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	get_existing_vertex(t_env *env)
{
	t_list		*tmp;
	t_vertex	*vertex;

	tmp = env->editor.vertices;
	while (tmp)
	{
		vertex = (t_vertex*)tmp->content;
		if (round((env->sdl.mx - env->editor.center.x) / env->editor.scale) == vertex->x
				&& round((env->sdl.my - env->editor.center.y) / env->editor.scale) == vertex->y)
		{
			//ft_printf("Click on vertex %d ([%f][%f])\n", vertex->num, vertex->y, vertex->x);
			return (vertex->num);
		}
		tmp = tmp->next;
	}
	return (-1);
}
