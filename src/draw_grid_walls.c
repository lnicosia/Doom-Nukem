/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:22:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 15:58:35 by sipatry          ###   ########.fr       */
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
	v1.x = env->edit.center.x + v->x * env->edit.scale;
	v1.y = env->edit.center.y + v->y * env->edit.scale;
	tmp = tmp->next;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		v2.x = env->edit.center.x + v->x * env->edit.scale;
		v2.y = env->edit.center.y + v->y * env->edit.scale;
		draw_line(v1, v2, *env, 0xFFFFFF00);
		v1 = v2;
		tmp = tmp->next;
	}
	if (env->drawing)
	{
		v2.x = env->sdl.mx;
		v2.y = env->sdl.my;
		draw_line(v1, v2, *env, 0xFFFFFF00);
	}
	return ;
}
