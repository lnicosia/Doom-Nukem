/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_vertices_contains.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:25:21 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/22 11:17:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"


int		check_list_intersections(t_env *env, t_vertex *last)
{
	t_list		*tmp;
	t_v2		intersection;
	t_vertex	*v1;
	t_vertex	*v2;

	tmp = env->editor.current_vertices;
	while (tmp->next->next)
	{
		v1 = (t_vertex*)tmp->content;
		v2 = (t_vertex*)tmp->next->content;
		intersection = get_intersection(
				new_v2(v1->x, v1->y),
				new_v2(v2->x, v2->y),
				new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
					round((env->sdl.my - env->editor.center.y) / env->editor.scale)),
				new_v2(last->x, last->y));
		if (segments_intersect(
				new_v2(v1->x, v1->y),
				new_v2(v2->x, v2->y),
				new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
					round((env->sdl.my - env->editor.center.y) / env->editor.scale)),
				new_v2(last->x, last->y)))
			ft_printf("Intersecte\n");
		tmp = tmp->next;
	}
	//ft_printf("\n");
	return (0);
}

int		check_sector_intersections(t_env *env, t_sector sector, t_vertex last)
{
	int			i;
	t_v2		intersection;
	t_vertex	v1;
	t_vertex	v2;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1 = env->vertices[sector.vertices[i]];
		v2 = env->vertices[sector.vertices[i + 1]];
		intersection = get_intersection(
				new_v2(v1.x, v1.y),
				new_v2(v2.x, v2.y),
				new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
					round((env->sdl.my - env->editor.center.y) / env->editor.scale)),
				new_v2(last.x, last.y));
		//ft_printf("Intersection = [%f][%f]\n", intersection.x, intersection.y);
		i++;
	}
	//ft_printf("\n");
	return (0);
}

int		new_wall_intersects(t_env *env)
{
	t_list		*tmp;
	t_vertex	*last;
	int			i;

	tmp = env->editor.current_vertices;
	while (tmp->next)
		tmp = tmp->next;
	last = (t_vertex*)tmp->content;
	tmp = env->editor.current_vertices;
	//ft_printf("Checking list\n");
	if (check_list_intersections(env, last))
		return (1);
	i = 0;
	while (i < env->nb_sectors)
	{
		//ft_printf("Checking sectors\n");
		if (check_sector_intersections(env, env->sectors[i], *last))
			return (1);
		i++;
	}
	return (0);
}

int		current_vertices_contains(t_env *env, int index)
{
	t_list		*tmp;
	t_vertex	*v;

	tmp = env->editor.current_vertices;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		if (v->num == index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_new_vertex_valid(t_env *env, int index)
{
	if (ft_lstlen(env->editor.current_vertices) < 3)
		return (1);
	if (current_vertices_contains(env, index))
		return (0);
	if (new_wall_intersects(env))
		return (0);
	return (1);
}
