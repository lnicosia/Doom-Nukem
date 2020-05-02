/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_vertex_valid3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:17:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:17:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int			check_list_intersections(t_env *env, t_vertex *last, int index)
{
	t_list		*tmp;
	t_vertex	*v1;
	t_vertex	*v2;

	tmp = env->editor.current_vertices;
	while (tmp && tmp->next)
	{
		v1 = (t_vertex*)tmp->content;
		v2 = (t_vertex*)tmp->next->content;
		if (v1->num != index && segments_intersect_editor(
					new_v2(v1->x, v1->y),
					new_v2(v2->x, v2->y),
					new_v2(last->x, last->y),
					new_v2(round((env->sdl.mx - env->editor.center.x)
					/ env->editor.scale), round((env->sdl.my
					- env->editor.center.y) / env->editor.scale))))
			return (custom_error("Intersects with current sector"));
		tmp = tmp->next;
	}
	return (0);
}

int			check_sector_intersections(t_env *env, t_sector sector,
t_vertex last, int index)
{
	int			i;
	t_vertex	v1;
	t_vertex	v2;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1 = env->vertices[sector.vertices[i]];
		v2 = env->vertices[sector.vertices[i + 1]];
		if (v1.num != last.num && v2.num != last.num
			&& v1.num != index && v2.num != index
			&& segments_intersect_editor(new_v2(v1.x, v1.y),
			new_v2(v2.x, v2.y),
			new_v2(round((env->sdl.mx - env->editor.center.x)
			/ env->editor.scale),
			round((env->sdl.my - env->editor.center.y)
			/ env->editor.scale)),
			new_v2(last.x, last.y)))
			return (custom_error("Intersects with existing wall(s)"));
		i++;
	}
	return (0);
}

/*
**	Returns 1 if a vertex has an intersection
**	with either the current sector or any existing one
*/

int			new_wall_intersects(t_env *env, int index)
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
