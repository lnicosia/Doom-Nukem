/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:57:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 11:50:10 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Returns -1 if the vertex is inside a sector
** returns 1 otherwise
*/

int		check_vertex_inside_sector(t_env *env, t_v2 vertex)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (vertex.x == env->vertices[env->sectors[i].vertices[j]].x
			&& vertex.y == env->vertices[env->sectors[i].vertices[j]].y)
				return (1);
			j++;
		}
		if (is_in_sector_no_z(env, i, vertex))
			return (custom_error("Vertex is inside a sector"));
		i++;
	}
	return (1);
}

/*
**	Check if the current sector is inside another sector
*/

static int	is_inside(t_sector sector, t_env *env)
{
	int		i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (check_vertex_inside_sector(env,
			new_v2(env->vertices[sector.vertices[i]].x,
			env->vertices[sector.vertices[i]].y)) != 1)
			return (1);
		i++;
	}
	return (0);
}


int			check_duplicate_vertices(t_sector sector, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i  <sector.nb_vertices)
	{
		j =  i + 1;
		while (j < sector.nb_vertices)
		{
			if ((env->vertices[sector.vertices[i]].x ==
			env->vertices[sector.vertices[j]].x)
			&& (env->vertices[sector.vertices[i]].y ==
			env->vertices[sector.vertices[j]].y))
			{
				return (ft_printf("vertex %d is a duplicate of vertex %d",
				sector.vertices[j], sector.vertices[i]));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			is_neighbor_valid(t_sector neighbor, t_vertex v1, t_vertex v2)
{
	int			i;

	i = 0;
	while (i < neighbor.nb_vertices)
	{
		if (neighbor.vertices[i] == v2.num &&
		neighbor.vertices[i + 1] == v1.num)
			return (0);
		else if (i == neighbor.nb_vertices - 1 
		&& (neighbor.vertices[i] == v2.num &&
			neighbor.vertices[0] == v1.num))
			return (0);
		i++;
	}
	return (-1);
}

int			check_neighbor_validity(t_sector sector, t_env *env)
{
	int			i;
	t_vertex	v1;
	t_vertex	v2;
	t_sector	neighbor;

	i = 0;
	while (i < env->sectors[sector.num].nb_vertices)
	{
		if (env->sectors[sector.num].neighbors[i] != -1)
		{
			v1 = env->vertices[sector.vertices[i]];	
			v2 = env->vertices[sector.vertices[i + 1]];
			neighbor = env->sectors[env->sectors[sector.num].neighbors[i]];
			if (is_neighbor_valid(neighbor, v1, v2))
				return (-1);
		}
		i++;
	}
	return (0);
}

int			check_intersection_with_sector(t_sector sector, t_env *env,
t_vertex vt1, t_vertex vt2)
{
	int		i;
	t_v2	v1;
	t_v2	v2;
	t_v2	v3;
	t_v2	v4;

	i = 0;
	v1 = new_v2(vt1.x, vt1.y);
	v2 = new_v2(vt2.x, vt2.y);
	while (i < sector.nb_vertices)
	{
		v3 = new_v2(env->vertices[sector.vertices[i]].x,
		env->vertices[sector.vertices[i]].y);
		v4 = new_v2(env->vertices[sector.vertices[i + 1]].x,
		env->vertices[sector.vertices[i + 1]].y);
			if (segments_intersect(v1, v2, v3, v4))
			{
				if ((env->vertices[sector.vertices[i]].num == vt1.num
				&& env->vertices[sector.vertices[i + 1]].num != vt2.num)
				|| (env->vertices[sector.vertices[i]].num == vt2.num
				&& env->vertices[sector.vertices[i + 1]].num != vt1.num)
				|| (env->vertices[sector.vertices[i]].num != vt1.num
				&& env->vertices[sector.vertices[i + 1]].num == vt2.num)
				|| (env->vertices[sector.vertices[i]].num != vt2.num
				&& env->vertices[sector.vertices[i + 1]].num == vt1.num))
					i = i - 0;
				else
					return (-1);
			}
		i++;
	}
	return (0);
}

int			check_vertices(t_sector sector, t_env *env)
{
	int			i;
	int			j;
	t_vertex	v1;
	t_vertex	v2;

	i = 0;
	while (i < sector.nb_vertices)
	{
		v1 = env->vertices[sector.vertices[i]];
		v2 = env->vertices[sector.vertices[i + 1]];
		j = 0;
		while (j < env->nb_sectors)
		{
			if (check_intersection_with_sector(env->sectors[j], env, v1, v2))
				return (-1);
			j++;
		}
		i++;
	}
	if (check_neighbor_validity(sector, env))
		return(ft_printf("Sector %d has a invalid neighbor\n", sector.num));
	return (0);
}

int			check_slopes_start(t_sector sector)
{
	if (sector.start_ceiling_slope > sector.nb_vertices
	|| sector.start_ceiling_slope < 0)
		return (ft_printf("Ceiling "));
	if (sector.start_floor_slope > sector.nb_vertices
	|| sector.start_floor_slope < 0)
		return (ft_printf("Floor "));
	return (0);
}

int			distance_bewteen_ceiling_and_floor(t_sector sector)
{
	if (sector.ceiling - sector.floor > 1000)
		return (-1);
	return (0);
}

/*
**	Check sector validity
*/

static int	check_sector(t_sector sector, t_env *env)
{
	if (is_inside(sector, env))
		return (ft_printf("Sector %d is inside or contains a sector\n", sector.num));
	if (check_vertices(sector, env))
		return (ft_printf("Vertices invalid\n"));
	if (check_slopes_start(sector))
		return (ft_printf("slope direction isn't valid\n"));
	if (distance_bewteen_ceiling_and_floor(sector))
		return (ft_printf("Distance between floor and ceiling exceed 1000\n"));
	return (0);
}

int			valid_map(t_env *env)
{
	int	i;

	ft_printf("{reset}Checking map validity..{red}\n");
	i = 0;
	env->player.sector = get_sector_no_z(env, env->player.pos);
	env->player.starting_sector = get_sector_no_z(env, env->player.starting_pos);
	if (!env->nb_sectors)
		return (ft_printf("You need at least one sector to go in 3d mode{reset}\n"));
	if (!env->editor.player_exist)
		return (ft_printf("You need to place the player\n"));
	if (env->player.sector == -1 || env->player.starting_sector == -1)
		return (ft_printf("Player position is not valid{reset}\n"));
	while (i < env->nb_sectors)
	{

		if (check_sector(env->sectors[i], env))
			return (ft_printf("Sector %d was not valid\n", i));
		i++;
	}
	ft_printf("{reset}");
	return (0);
}
