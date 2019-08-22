/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:22:35 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/22 11:53:18 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_current_sector(t_env *env)
{
	t_list		*tmp;
	t_vertex	*v;
	t_point		v1;
	t_point		v2;

	tmp = env->editor.current_vertices;
	if (!tmp)
		return ;
	v = (t_vertex*)tmp->content;
	v1.x = env->editor.center.x + v->x * env->editor.scale;
	v1.y = env->editor.center.y + v->y * env->editor.scale;
	tmp = tmp->next;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		v2.x = env->editor.center.x + v->x * env->editor.scale;
		v2.y = env->editor.center.y + v->y * env->editor.scale;
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

void	draw_grid_sector(t_sector sector, t_env *env)
{
	int		i;
	t_point	v1;
	t_point	v2;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1.x = env->editor.center.x +
			env->vertices[sector.vertices[i]].x * env->editor.scale;
		v1.y = env->editor.center.y +
			env->vertices[sector.vertices[i]].y * env->editor.scale;
		v2.x = env->editor.center.x +
			env->vertices[sector.vertices[i + 1]].x * env->editor.scale;
		v2.y = env->editor.center.y +
			env->vertices[sector.vertices[i + 1]].y * env->editor.scale;
		draw_line(v1, v2, *env, 0xFFFFFFFF);
		i++;
	}
}

void	draw_grid_sectors(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_sectors)
	{
		draw_grid_sector(env->sectors[i], env);
		i++;
	}
}
