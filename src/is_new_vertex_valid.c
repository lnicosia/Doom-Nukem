/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_vertices_contains.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:25:21 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/26 15:37:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"


int		check_list_intersections(t_env *env, t_vertex *last, int index)
{
	t_list		*tmp;
	t_vertex	*v1;
	t_vertex	*v2;

	tmp = env->editor.current_vertices;
	while (tmp && tmp->next && tmp->next->next)
	{
		v1 = (t_vertex*)tmp->content;
		v2 = (t_vertex*)tmp->next->content;
		//ft_printf("|v1 = %d [%d][%d]| ", v1->num, (int)v1->y, (int)v1->x);
		//ft_printf("|v2 = %d [%d][%d]| ", v2->num, (int)v2->y, (int)v2->x);
		//ft_printf("|last = %d [%d][%d]| ", last->num, (int)last->y, (int)last->x);
		//ft_printf("|current = %d|\n", index);
		if (v1->num != last->num && v2->num != last->num
				&& v1->num != index && v2->num != index
				&& segments_intersect(
					new_v2(v1->x, v1->y),
					new_v2(v2->x, v2->y),
					new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
						round((env->sdl.my - env->editor.center.y) / env->editor.scale)),
					new_v2(last->x, last->y)))
			return (custom_error("Intersects with current sector"));
		tmp = tmp->next;
	}
	return (0);
}

int		check_sector_intersections(t_env *env, t_sector sector, t_vertex last, int index)
{
	int			i;
	t_vertex	v1;
	t_vertex	v2;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1 = env->vertices[sector.vertices[i]];
		v2 = env->vertices[sector.vertices[i + 1]];
		//ft_printf("|v1 = %d [%d][%d]| ", v1.num, (int)v1.y, (int)v1.x);
		//ft_printf("|v2 = %d [%d][%d]| ", v2.num, (int)v2.y, (int)v2.x);
		//ft_printf("|last = %d [%d][%d]| ", last.num, (int)last.y, (int)last.x);
		//ft_printf("|current = %d|\n", index);
		if (v1.num != last.num && v2.num != last.num
				&& v1.num != index && v2.num != index
				&& segments_intersect(
					new_v2(v1.x, v1.y),
					new_v2(v2.x, v2.y),
					new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
						round((env->sdl.my - env->editor.center.y) / env->editor.scale)),
					new_v2(last.x, last.y)))
			return (custom_error("Intersects with existing wall(s)"));
		i++;
	}
	return (0);
}

int		new_wall_intersects(t_env *env, int index)
{
	t_list		*tmp;
	t_vertex	*last;
	int			i;

	tmp = env->editor.current_vertices;
	while (tmp->next)
		tmp = tmp->next;
	last = (t_vertex*)tmp->content;
	tmp = env->editor.current_vertices;
	if (check_list_intersections(env, last, index))
		return (1);
	i = 0;
	while (i < env->nb_sectors)
	{
		if (check_sector_intersections(env, env->sectors[i], *last, index))
			return (1);
		i++;
	}
	return (0);
}

int		is_new_vertex_valid(t_env *env, int index)
{
	if (!env->editor.current_vertices)
		return (1);
	if (index != env->editor.start_vertex
			&& current_vertices_contains(env, index))
		return (0);
	if (new_wall_intersects(env, index))
		return (0);
	return (1);
}
