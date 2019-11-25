/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:25:43 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/25 16:50:44 by sipatry          ###   ########.fr       */
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

void	draw_grid_sector(t_sector sector, Uint32 color, t_env *env)
{
	int		i;
	t_point	v1;
	t_point	v2;
	Uint32	c;

	i = 0;
	/*ft_printf("\nsector: %d | nb_certices: %d\n", sector.num, sector.nb_vertices);
	while (i < sector.nb_vertices)
	{
		ft_printf("vertex[%d]: %d | x: %f | y: %f\n", i, sector.vertices[i],
		env->vertices[sector.vertices[i]].x, env->vertices[sector.vertices[i]].y);
		i++;
	}*/
	i = 0;
	ft_printf("\n");
	while (i < sector.nb_vertices)
	{
		int	j = 0;
		while (j < sector.nb_vertices + 1)
		{
			ft_printf("vertices[%d]: %d\n", j, sector.vertices[j]);
			j++;
		}
		ft_printf("\n");
	/*	ft_printf("v1.x: %f v1.y: %f | ", env->vertices[sector.vertices[i]].x,
		env->vertices[sector.vertices[i]].y);
		ft_printf("v2.x: %f v2.y: %f\n", env->vertices[sector.vertices[i + 1]].x,
		env->vertices[sector.vertices[i + 1]].y);*/
		v1.x = env->editor.center.x +
			env->vertices[sector.vertices[i]].x * env->editor.scale;
		v1.y = env->editor.center.y +
			env->vertices[sector.vertices[i]].y * env->editor.scale;
		v2.x = env->editor.center.x +
			env->vertices[sector.vertices[i + 1]].x * env->editor.scale;
		v2.y = env->editor.center.y +
			env->vertices[sector.vertices[i + 1]].y * env->editor.scale;
		if (sector.neighbors[i] == -1)
			c = color;
		else
			c = 0xFFFF0000;
		//draw_line(v1, v2, *env, c);
		i++;
	}
}

void	draw_grid_sectors(t_env *env)
{
	int	i;

	i = 0;
	if (!env->editor.player_exist && env->nb_sectors == 1)
		add_player(env);
	while (i < env->nb_sectors)
	{
		if (i == env->editor.selected_sector)
			draw_grid_sector(env->sectors[i], 0xFF00FF00, env);
		else
			draw_grid_sector(env->sectors[i], 0xFFFFFFFF, env);
		i++;
	}
}
