/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_vertex_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:54:07 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 16:17:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int			check_current_sector2(t_env *env, int *list_sectors, int i,
int index)
{
	env->vertices[index].x = round((env->sdl.mx -
		env->editor.center.x) / env->editor.scale);
	env->vertices[index].y = round((env->sdl.my -
		env->editor.center.y) / env->editor.scale);
	check_sector_order(env);
	set_sectors_xmax(env);
	precompute_slopes(env);
	if (check_sector(env->sectors[list_sectors[i]], env))
	{
		env->vertices[index].x = env->editor.start_pos.x;
		env->vertices[index].y = env->editor.start_pos.y;
		return (1);
	}
	return (0);
}

int			check_current_sector(t_env *env, int *list_sectors, int i,
int index)
{
	int			j;
	t_vertex	last;

	j = 0;
	while (j < env->nb_sectors)
	{
		last =
		find_second_vertex(env, env->sectors[list_sectors[i]], -1, index);
		if (check_sector_intersections(
			env, env->sectors[j], last, index) == -1)
			return (1);
		last =
		find_second_vertex(env, env->sectors[list_sectors[i]], 1, index);
		if (check_sector_intersections(
			env, env->sectors[j], last, index) == -1)
			return (1);
		j++;
	}
	return (check_current_sector2(env, list_sectors, i, index));
}

int			is_new_dragged_vertex_valid(t_env *env, int index)
{
	int			*list_sectors;
	int			i;

	i = 1;
	if (!(list_sectors = get_vertex_sectors(env, index)))
		return (-1);
	while (i <= list_sectors[0])
	{
		if (check_current_sector(env, list_sectors, i, index))
		{
			ft_memdel((void**)&list_sectors);
			return (0);
		}
		i++;
	}
	ft_memdel((void**)&list_sectors);
	return (1);
}

int			new_sector_contains(t_vertex *tmp_sect, t_vertex v1, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (v1.x == tmp_sect[i].x && v1.y == tmp_sect[i].y)
			return (1);
		i++;
	}
	return (0);
}

/*
**	Returns 1 if a vertex is valid
**	(no intersection with current or existing sector,
**	not already existing in current sector)
*/

int			is_new_vertex_valid(t_env *env, int index)
{
	t_v2	vertex;
	int		ret;

	vertex.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	vertex.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	if (check_vertex_inside_sector(env, vertex) == -1)
		return (0);
	if (is_mouse_on_a_wall(env))
		return (0);
	if (!env->editor.current_vertices)
		return (1);
	if (current_vertices_contains(env, index))
		return (0);
	if (new_wall_intersects(env, index))
		return (0);
	ret = is_new_sector_convex(env, env->editor.current_vertices);
	if (ret == -1)
		return (-1);
	else if (!ret)
		return (0);
	return (1);
}
