/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:04:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/22 18:16:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

t_v2	get_normal(t_v2 v1, t_v2 v2)
{
	t_v2	normal;
	double	norm;

	norm = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
	normal.x = -((v2.y - v1.y) / norm);
	normal.y = ((v2.x - v1.x) / norm);
	return (normal);
}

t_v2	get_sector_normal(t_sector sector, t_env *env)
{
	t_vertex	v1;
	t_vertex	v2;

	v1 = env->vertices[sector.vertices[0]];
	v2 = env->vertices[sector.vertices[1]];
	return (get_normal(new_v2(v1.x, v1.y), new_v2(v2.x, v2.y)));
}

double	get_distance(t_sector sector, short vertex_nb, t_env *env)
{
	t_vertex	v0;
	t_vertex	v1;
	t_vertex	vmid;
	t_vertex	vi;

	v0 = env->vertices[sector.vertices[0]];
	v1 = env->vertices[sector.vertices[1]];
	vi = env->vertices[sector.vertices[vertex_nb]];
	vmid.x = (v0.x + v1.x) / 2;
	vmid.y = (v0.y + v1.y) / 2;
	return (sqrt(pow(vi.x - vmid.x, 2) + pow(vi.y - vmid.y, 2)));
}

double	get_floor(t_sector sector, t_vertex vertex)
{
	double	res;

	res = sector.floor - sector.normal.x * vertex.x - sector.normal.y * vertex.y;
	res /= sector.floor_slope;
	return (res);
}

double	get_ceiling(t_sector sector, t_vertex vertex)
{
	double	res;

	res = sector.ceiling - sector.normal.x * vertex.x - sector.normal.y * vertex.y;
	res /= sector.ceiling_slope;
	return (res);
}

void	precompute_slopes(t_env *env)
{
	int			i;
	int			j;
	double		distance;
	t_sector	sector;

	i = 0;
	while (i < env->nb_sectors)
	{
		sector = env->sectors[i];
		env->sectors[i].normal = get_sector_normal(sector, env);
		if (sector.floor_slope != 0 && sector.ceiling_slope != 0)
		{
			j = 2;
			while (j < sector.nb_vertices)
			{
				distance = get_distance(sector, j, env);
				env->vertices[sector.vertices[i]].floor = get_floor(sector, env->vertices[sector.vertices[i]]); 
				env->vertices[sector.vertices[i]].ceiling = get_ceiling(sector, env->vertices[sector.vertices[i]]); 
				j++;
			}
		}
		i++;
	}
}

