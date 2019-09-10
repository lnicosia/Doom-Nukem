/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 10:52:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		get_intersections2(int i, t_sector *sector, t_env *env)
{
	t_v2	inter;

	inter = get_intersection(
			new_v2(sector->vx[i], sector->vz[i]),
			new_v2(sector->vx[i + 1], sector->vz[i + 1]),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.near_right, env->camera.near_z));
	if (sector->vz[i] < env->camera.near_z)
	{
		sector->clipped_vx[i] = inter.x;
		sector->clipped_vz[i] = inter.y;
	}
	else
	{
		sector->clipped_vx[i] = sector->vx[i];
		sector->clipped_vz[i] = sector->vz[i];
	}
	sector->clipped_vf[i] = get_floor_at_pos(*sector,
			new_v2(sector->clipped_vx[i], sector->clipped_vz[i]), env);
	sector->clipped_vc[i] = get_ceiling_at_pos(*sector,
			new_v2(sector->clipped_vx[i], sector->clipped_vz[i]), env);
}

void		clip_walls2(int i, t_sector *sector, t_env *env)
{
	if ((sector->vz[i] < env->camera.near_z && sector->vz[i + 1]
				< env->camera.near_z)
			|| (sector->vz[i] > env->camera.far_z && sector->vz[i + 1]
				> env->camera.far_z)
			|| (sector->vx[i] < env->camera.far_left && sector->vx[i + 1]
				< env->camera.far_left)
			|| (sector->vx[i] > env->camera.far_right && sector->vx[i + 1]
				> env->camera.far_right))
		sector->draw[i] = 0;
	sector->draw[i] = 1;
	get_intersections2(i, sector, env);
}

void		compute_walls(int i, t_sector *sector, t_env *env)
{
	double	vx;
	double	vz;

	vx = env->vertices[sector->vertices[i]].x - env->player.pos.x;
	vz = env->vertices[sector->vertices[i]].y - env->player.pos.y;
	sector->vx[i] = vx * env->player.angle_sin - vz * env->player.angle_cos;
	sector->vz[i] = vx * env->player.angle_cos + vz * env->player.angle_sin;
}

void		precompute_sectors(t_sector *sector, t_env *env)
{
	int		i;

	i = 0;
	while (i < sector->nb_vertices)
	{
		compute_walls(i, sector, env);
		clip_walls2(i, sector, env);
		if (sector->draw[i])
			project_walls(i, sector, env);
		i++;
	}
	i = 0;
	while (i < sector->nb_vertices)
	{
		clip_walls2(i, sector, env);
		if (sector->draw[i])
			project_walls(i, sector, env);
		i++;
	}
	sector->clipped_vx[sector->nb_vertices] = sector->clipped_vx[0];
	sector->clipped_vz[sector->nb_vertices] = sector->clipped_vz[0];
	sector->clipped_vf[sector->nb_vertices] = sector->clipped_vf[0];
	sector->clipped_vc[sector->nb_vertices] = sector->clipped_vc[0];
	sector->computed = 1;
}

int			draw_walls2(t_env *env)
{
	int		i;
	int		screen_sectors;

	reset_render_utils(env);
	screen_sectors = get_screen_sectors(env);
	i = 0;
	while (i < screen_sectors)
	{
		if (!env->sectors[i].computed)
			precompute_sectors(&env->sectors[i], env);
		i++;
	}
	return (0);
}
