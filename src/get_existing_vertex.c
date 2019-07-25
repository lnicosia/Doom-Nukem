/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:50:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 13:55:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	get_existing_vertex(t_env *env)
{
	t_list		*tmp;
	t_vertex	*vertex;

	tmp = env->edit.vertices;
	while (tmp)
	{
		vertex = (t_vertex*)tmp->content;
		if (round((env->sdl.mx - env->edit.center.x) / env->edit.scale) == vertex->x
				&& round((env->sdl.my - env->edit.center.y) / env->edit.scale) == vertex->y)
		{
			ft_printf("Click on vertex %d ([%f][%f])\n", vertex->num, vertex->y, vertex->x);
			return (vertex->num);
		}
		tmp = tmp->next;
	}
	return (-1);
}
