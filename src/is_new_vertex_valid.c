/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_vertex_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:54:07 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 15:43:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int		valid_line(t_v2 v1, t_v2 v2, t_v2 v3, t_v2 v4)
{
	if ((v1.x > v3.x && v1.x < v4.x)
			|| (v1.x < v3.x && v1.x > v4.x)
			|| (v1.y < v3.y && v1.y > v4.y)
			|| (v1.y < v3.y && v1.y > v4.y)
			|| (v2.x < v3.x && v2.x > v4.x)
			|| (v2.x > v3.x && v2.x < v4.x)
			|| (v2.y < v3.y && v2.y > v4.y)
			|| (v2.y > v3.y && v2.y < v4.y)
	   )
	{
		//ft_printf("{red}Invalide v1 = [%f][%f] v2 = [%f][%f] v3 = [%f][%f] v4 = [%f][%f]{reset}\n",
		//v1.y, v1.x, v2.y, v2.x, v3.y, v3.x, v4.y, v4.x);
		return (1);
	}
	//ft_printf("{green}Valide{reset}\n");
	return (0);
}

int		segments_intersect_editor(t_v2 v1, t_v2 v2, t_v2 v3, t_v2 v4)
{
	t_v2	intersection;

	//if ((v4.x == v1.x && v4.y == v1.y))
	//return (0);
	intersection = get_intersection(v1, v2, v3, v4);
	if ((intersection.x < v1.x && intersection.x < v2.x)
			|| (intersection.x > v1.x && intersection.x > v2.x)
			|| (intersection.y < v1.y && intersection.y < v2.y)
			|| (intersection.y > v1.y && intersection.y > v2.y)
			|| (intersection.x < v3.x && intersection.x < v4.x)
			|| (intersection.x > v3.x && intersection.x > v4.x)
			|| (intersection.y < v3.y && intersection.y < v4.y)
			|| (intersection.y > v3.y && intersection.y > v4.y))
		return (0);
	//ft_printf("Inter = [%f][%f]\n", intersection.y, intersection.x);
	if ((int)intersection.x == -2147483648 || (int)intersection.y == -2147483648)
	{
		//ft_printf("{cyan}Line{reset}\n");
		if (valid_line(v1, v2, v3, v4))
			return (1);
		return (0);
	}
	if (v2.x == v3.x && v2.y == v3.y)
		return (0);
	return (1);
}

int		check_list_intersections(t_env *env, t_vertex *last, int index)
{
	t_list		*tmp;
	t_vertex	*v1;
	t_vertex	*v2;

	tmp = env->editor.current_vertices;
	while (tmp && tmp->next)// && tmp->next->next)
	{
		v1 = (t_vertex*)tmp->content;
		v2 = (t_vertex*)tmp->next->content;
		//ft_printf("|v1 = %d [%d][%d]| ", v1->num, (int)v1->y, (int)v1->x);
		//ft_printf("|v2 = %d [%d][%d]| ", v2->num, (int)v2->y, (int)v2->x);
		//ft_printf("|last = %d [%d][%d]| ", last->num, (int)last->y, (int)last->x);
		//ft_printf("|current = %d|\n", index);
		if (v1->num != index && segments_intersect_editor(
					new_v2(v1->x, v1->y),
					new_v2(v2->x, v2->y),
					new_v2(last->x, last->y),
					new_v2(round((env->sdl.mx - env->editor.center.x) /
					env->editor.scale), round((env->sdl.my
					- env->editor.center.y) / env->editor.scale))))
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
				&& segments_intersect_editor(
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

/*
 **	Returns 1 if a vertex has an intersection
 **	with either the current sector or any existing one
 **	
 */

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

int		get_vertex_in_sector(t_env *env, int sector)
{
	int	i;
	int	ret;

	i = 0;
	while (i < env->sectors[sector].nb_vertices)
	{
		if (env->sectors[sector].vertices[i] == env->editor.selected_vertex)
			break;
		i++;
	}
	ret = env->sectors[sector].vertices[i];
	return (ret);
}

t_vertex	find_second_vertex(t_env *env, t_sector sector, int new_index, int index)
{
	int	i;
	t_vertex	res;
	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == index)
			break;
		else
			i++;
	}
	if (i == 0)
		res = env->vertices[sector.vertices[sector.nb_vertices - 1]];
	else
		res = env->vertices[sector.vertices[i + new_index]];
	return (res);
}

int		check_all_angles(t_v2 *p, int res, int i, int straight)
{	
	if(((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
			- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) > 0)
			{
				if (!res)
					res += straight;
				res++;
			}
	else if (((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
	- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) < 0)
	{
		if (!res)
			res -= straight;
		res--;
	}
	else if (((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
	- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) == 0 && res)
		res += res > 0 ? 1 : -1;
	return (res);
}

/*
**	PROTECTION
*/

int		is_new_sector_convex(t_env *env, t_list *tmp)
{
	int		len;
	int		i;
	t_v2	*p;
	int		res;
	int		straight;
	
	i = 0;
	res = 0;
	straight = 0;
	len = ft_lstlen(env->editor.current_vertices);
	tmp = env->editor.current_vertices;
	if (len > 2)
	{
		len += 3;
		if (!(p = (t_v2*)ft_memalloc(sizeof(t_v2) * (len))))
			return (-1);
		p[len - 3].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
		p[len - 3].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
		while (tmp)
		{
			p[i].x = ((t_vertex*)tmp->content)->x;
			p[i].y = ((t_vertex*)tmp->content)->y;
			tmp = tmp->next;
			i++;
		}
		p[len - 2] = p[0];
		p[len - 1] = p[1];
		i = 0;
		while (i < len - 2)
		{
			res = check_all_angles(p, res, i, straight);
			if (!res)
				straight++;
			else
				straight = 0;
			i++;
		}
		free(p);
		if (res != -(len - 2) && res != len - 2 && res)
			return (0);
	}
	return (1);
}

int		is_new_dragged_vertex_valid(t_env *env, int index)
{
	int			*list_sectors;
	int			i;
	int			j;
	t_vertex	last;

	i = 1;
	list_sectors = get_vertex_sectors(env, index);
	while (i <= list_sectors[0])
	{
		j = 0;
		while (j < env->nb_sectors)
		{
			last = find_second_vertex(env, env->sectors[list_sectors[i]], -1, index);
			if (check_sector_intersections(env, env->sectors[j], last, index) == -1)
				return (0);
			last = find_second_vertex(env, env->sectors[list_sectors[i]], 1, index);
			if (check_sector_intersections(env, env->sectors[j], last, index) == -1)
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int		new_sector_contains(t_vertex *tmp_sect, t_vertex v1, int size)
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
** Returns 1 if there's no exisiting vertex in the new sector
*/

int		is_sector_empty(t_env *env, t_v2 last_vertex)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	size = 1;
	tmp = env->editor.current_vertices;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (size <= 2)
		return (1);
	tmp = env->editor.current_vertices;
	if (!(env->tmp_sector = (t_vertex *)malloc(sizeof(t_vertex) * size)))
		return (0);
	while (tmp)
	{
		env->tmp_sector[i].x = ((t_vertex*)tmp->content)->x;
		env->tmp_sector[i].y = ((t_vertex*)tmp->content)->y;
		tmp = tmp->next;
		i++;
	}
	env->tmp_sector[i].x = last_vertex.x;
	env->tmp_sector[i].y = last_vertex.y;
	i = 0;
	while (i < env->nb_vertices)
	{
		if (!new_sector_contains(env->tmp_sector, env->vertices[i], size) &&
			inside_tmp_sect(env->vertices[i], env->tmp_sector, size))
		{	
			free(env->tmp_sector);
			return (0);
		}
		i++;
	}
	free(env->tmp_sector);
	return (1);
}

/*
**	Returns 1 if a vertex is valid
**	(no intersection with current or existing sector,
**	not already existing in current sector)
*/

int		is_new_vertex_valid(t_env *env, int index)
{
	t_v2	vertex;
	int		ret;

	vertex.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	vertex.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	if (check_vertex_inside_sector(env, vertex) != 1)
		return (0);
	if (!env->editor.current_vertices)
		return (1);
	if (!is_sector_empty(env, vertex))
		return (0);
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
