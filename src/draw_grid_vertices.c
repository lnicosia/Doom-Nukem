/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:52:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 12:30:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_vertices(t_env *env)
{
	t_list	*tmp;
	t_vertex	*vertex;

	tmp = env->edit.vertices;
	while (tmp)
	{
		vertex = (t_vertex*)tmp->content;
		draw_circle(new_circle(0xFFFF0000,
					0xFFFF0000,
					new_point(env->edit.center.x + vertex->x * env->edit.scale,
						env->edit.center.y + vertex->y * env->edit.scale),
					env->edit.scale / 5.0), env);
		tmp = tmp->next;
	}
}
