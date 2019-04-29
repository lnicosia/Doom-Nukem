/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:04:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/25 16:47:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

t_v2	get_sector_normal(t_sector sector, t_env *env)
{
	t_vertex	v1;
	t_vertex	v2;
	t_v2	normal;
	double	norm;

	v1 = env->vertices[sector.vertices[0]];
	v2 = env->vertices[sector.vertices[1]];
	norm = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
	normal.x = -((v2.y - v1.y) / norm);
	normal.y = -((v2.x - v1.x) / norm);
	return (normal);
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

double	get_floor(t_sector sector, t_vertex vertex, t_env *env)
{
	double		res;
	t_vertex	v0;

	v0 = env->vertices[sector.vertices[0]];
	res = sector.normal.x * (vertex.x - v0.x) - sector.normal.y * (vertex.y - v0.y);
	res = res * sector.floor_slope + sector.floor;
	return (res);
}

double	get_ceiling(t_sector sector, t_vertex vertex, t_env *env)
{
	double	res;
	t_vertex	v0;

	v0 = env->vertices[sector.vertices[0]];
	res = sector.normal.x * (vertex.x - v0.x) - sector.normal.y * (vertex.y - v0.y);
	res = res * sector.ceiling_slope + sector.ceiling;
	return (res);
}

void	check_slopes(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		ft_printf("sector %d normal = [%f,%f]\n", i, env->sectors[i].normal.x, env->sectors[i].normal.y);
		ft_printf("floor = %f\nceiling = %f\n", env->sectors[i].floor, env->sectors[i].ceiling);
		ft_printf("floor_slope = %f\nceiling_slope = %f\n", env->sectors[i].floor_slope, env->sectors[i].ceiling_slope);
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			printf("vertex %d floor = %f ceiling = %f\n", j, env->sectors[i].floors[j], env->sectors[i].ceilings[j]);
			j++;
		}
		i++;
	}
}

void	precompute_slopes(t_env *env)
{
	int			i;
	int			j;
	t_sector	sector;
	t_vertex	v0;

	ft_printf("Computing map slopes..\n");
	i = 0;
	while (i < env->nb_sectors)
	{
		env->sectors[i].normal = get_sector_normal(env->sectors[i], env);
		sector = env->sectors[i];
		j = 0;
		while (j < sector.nb_vertices)
		{
			if (sector.floor_slope != 0)
				env->sectors[i].floors[j] = get_floor(sector, env->vertices[sector.vertices[j]], env); 
			else
				env->sectors[i].floors[j] = sector.floor;
			if (sector.ceiling_slope != 0)
				env->sectors[i].ceilings[j] = get_ceiling(sector, env->vertices[sector.vertices[j]], env); 
			else
				env->sectors[i].ceilings[j] = sector.ceiling;
			j++;
		}
		env->sectors[i].floors[j] = env->sectors[i].floors[0];
		env->sectors[i].ceilings[j] = env->sectors[i].ceilings[0];
		i++;
	}
	sector = env->sectors[env->player.sector];
	v0 = env->vertices[sector.vertices[0]];
	env->player.pos.z = 6 + sector.floor + (sector.normal.x * (env->player.pos.x - v0.x) - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
	//check_slopes(env);
}