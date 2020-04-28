#include "env.h"
#include "valid_map.h"

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

void	compare_current_vertex(t_sector_comparer *comparer)
{
	if (comparer->start_v2 + 1 < comparer->sect2.nb_vertices)
		comparer->j = comparer->start_v2 + 1;
	else
		comparer->j = 0;
	while ((comparer->j > comparer->start_v2
	  	&& comparer->j < comparer->sect2.nb_vertices)
		|| (comparer->j < comparer->start_v2))
	{
		if (comparer->sect1.vertices[comparer->start_v1] ==
		  	comparer->sect2.vertices[comparer->j])
		{
			comparer->start_v2 = comparer->j;
			comparer->i++;
			break;
		}
		if (comparer->j < comparer->sect2.nb_vertices)
			comparer->j++;
		else
			comparer->j = 0;
	}
}

/*
**	Check if the current sector is inside another sector
*/

int			compare_sectors(int start_v1, int start_v2, t_sector sect1,
t_sector sect2)
{
  	t_sector_comparer	comparer;

	comparer.i = 0;
	comparer.j = 0;
	comparer.start_v1 = start_v1;
	comparer.start_v2 = start_v2;
	comparer.sect1 = sect1;
	comparer.sect2 = sect2;
	while (comparer.start_v1 < comparer.sect1.nb_vertices)
	{
		if (comparer.sect1.vertices[comparer.start_v1] ==
		  	comparer.sect2.vertices[comparer.start_v2])
			comparer.i++;
		else
	  		compare_current_vertex(&comparer);
		if (comparer.start_v2 < comparer.sect2.nb_vertices)
			comparer.start_v2++;
		else
			comparer.start_v2 = 0;
		comparer.start_v1++;
	}
	if (comparer.i == comparer.sect1.nb_vertices)
		return (-1);
	return (0);
}

int			check_portals(t_sector sect1, t_sector sect2)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < sect1.nb_vertices)
	{
		j = 0;
		while (j < sect2.nb_vertices)
		{
			if (sect1.vertices[i] == sect2.vertices[j])
			{
				k = 0;
				while (k < sect2.nb_vertices)
				{
					if (sect1.vertices[i + 1] == sect2.vertices[k]
					&& sect1.neighbors[i] == -1)
						return (-1);					
					k++;
				}
			}
			j++;
		}
	}
	return (0);
}

int			check_sectors_inside(t_sector sector, int sect, t_env *env)
{
	int			i;
	int			j;
	t_sector	sector2;

	i = 0;
	j = 0;
	sector2 = env->sectors[sect];
	while (i < sector.nb_vertices)
	{
		j = 0;
		while (j < sector2.nb_vertices)
		{
			if (sector.vertices[i] == sector2.vertices[j])
				break;
			j++;
		}
		if (sector.vertices[i] == sector2.vertices[j])
			break;
		i++;
	}
	if (compare_sectors(i, j, sector, sector2))
		return (-1);
	if (check_portals(sector, sector2))
		return(-1);
	return (0);
}
