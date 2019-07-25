/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:22:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 14:02:31 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_walls(t_env *env)
{
	t_list		*tmp;
	t_vertex	*v;
	t_point		v1;
	t_point		v2;

	tmp = env->edit.vertices;
	if (!tmp)
		return ;
	v = (t_vertex*)tmp->content;
	v1.x = v->x;
	v1.y = v->y;
	tmp = tmp->next;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		v2.x = v->x;
		v2.y = v->y;
		draw_line(v1, v2, *env, 0x008000);
		v1 = v2;
		tmp = tmp->next;
	}
	v2.x = (env->sdl.mx - env->edit.center.x) / env->edit.scale;
	v2.y = (env->sdl.my - env->edit.center.y) / env->edit.scale;
	draw_line(v1, v2, *env, 0x008000);
	return ;
}
