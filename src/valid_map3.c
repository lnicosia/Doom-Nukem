#include "env.h"

int			check_inside_sector(t_sector sector, int sect, t_env *env)
{
	int			i;
	int			j;
	t_sector	sector2;;
	t_v2		vertex;
	
	i = 0;
	sector2 = env->sectors[sect];
	while (i < sector2.nb_vertices)
	{
		j = 0;
		vertex = new_v2(env->vertices[sector2.vertices[i]].x,
		env->vertices[sector2.vertices[i]].y);
		while (j < sector.nb_vertices)
		{
			if (vertex.x == env->vertices[sector.vertices[j]].x
			&& vertex.y == env->vertices[sector.vertices[j]].y)
				break;
			j++;
		}
		if (j == sector.nb_vertices
		&& is_in_sector_no_z(env, sector.num, vertex))
			return (-1);
		i++;
	}
	return (0);
}

int			is_inside(t_sector sector, t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != sector.num)
		{
			if (check_inside_sector(sector, i, env))
				return (-1);
			if (check_sectors_inside(sector, i, env))
				return (-1);
		}
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
