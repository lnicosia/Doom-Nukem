/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 17:58:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

void		get_intersections2(int i, t_sector *sector, t_env *env)
{
	t_v2	inter;

	inter = get_intersection(
			new_v2(sector->v[i].vx, sector->v[i].vz),
			new_v2(sector->v[i + 1].vx, sector->v[i + 1].vz),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.near_right, env->camera.near_z));
	if (sector->v[i].vz < env->camera.near_z)
	{
		sector->v[i].clipped_vx = inter.x;
		sector->v[i].clipped_vz = inter.y;
	}
	else
	{
		sector->v[i].clipped_vx = sector->v[i].vx;
		sector->v[i].clipped_vz = sector->v[i].vz;
	}
	sector->v[i].clipped_vf = get_floor_at_pos(*sector,
			new_v2(sector->v[i].clipped_vx, sector->v[i].clipped_vz),
			env);
	sector->v[i].clipped_vc = get_ceiling_at_pos(*sector,
			new_v2(sector->v[i].clipped_vx, sector->v[i].clipped_vz),
			env);
}

void		clip_wall2(int i, t_sector *sector, t_env *env)
{
	if ((sector->v[i].vz < env->camera.near_z
				&& sector->v[i + 1].vz < env->camera.near_z)
			|| (sector->v[i].vz > env->camera.far_z
				&& sector->v[i + 1].vz > env->camera.far_z)
			|| (sector->v[i].vx < env->camera.far_left
				&& sector->v[i + 1].vx < env->camera.far_left)
			|| (sector->v[i].vx > env->camera.far_right
				&& sector->v[i + 1].vx > env->camera.far_right))
	{
		sector->v[i].draw = 0;
		return ;
	}
	sector->v[i].draw = 1;
	get_intersections2(i, sector, env);
}

void		compute_wall(int i, t_sector *sector, t_env *env)
{
	double	vx;
	double	vz;

	vx = env->vertices[sector->vertices[i]].x - env->player.pos.x;
	vz = env->vertices[sector->vertices[i]].y - env->player.pos.y;
	sector->v[i].vx = vx * env->player.angle_sin
		- vz * env->player.angle_cos;
	sector->v[i].vz = vx * env->player.angle_cos
		+ vz * env->player.angle_sin;
}

void		precompute_values(int i, t_sector *sector, t_env *env)
{
	sector->selected = 0;
	if (env->selected_wall1 == sector->vertices[i]
			&& env->selected_wall2 == sector->vertices[i + 1])
		sector->selected = 1;
	sector->v[i].draw = 1;
	sector->v[i].floor_horizon = env->player.horizon;
	sector->v[i].ceiling_horizon = env->player.horizon;
	sector->v[i].clipped_xrange = sector->v[i + 1].clipped_x
		- sector->v[i].clipped_x;
	sector->v[i].xrange = sector->v[i + 1].x
		- sector->v[i].x;
	sector->v[i].floor_range = sector->v[i + 1].f - sector->v[i].f;
	sector->v[i].ceiling_range = sector->v[i + 1].c - sector->v[i].c;
	sector->v[i].no_slope_floor_range = sector->v[i + 1].no_slope_f
		- sector->v[i].no_slope_f;
	sector->v[i].no_slope_ceiling_range = sector->v[i + 1].no_slope_c
		- sector->v[i].no_slope_c;
	sector->v[i].xz = env->vertices[sector->vertices[i]].x
		/ sector->v[i].vz;
	sector->v[i].yz = env->vertices[sector->vertices[i]].y
		/ sector->v[i].vz;
}

void		precompute_sector(t_sector *sector, t_env *env)
{
	int		i;

	i = -1;
	sector->computed = 1;
	while (++i < sector->nb_vertices)
		compute_wall(i, sector, env);
	i = -1;
	while (++i < sector->nb_vertices)
		clip_wall2(i, sector, env);
	i = -1;
	while (++i < sector->nb_vertices)
	{
		if (sector->v[i].draw)
			if (project_wall(i, sector, env))
				sector->v[i].draw = 0;
	}
	i = -1;
	while (++i < sector->nb_vertices)
	{
		sector->v[i].draw = 0;
		if (sector->v[i].clipped_x >= sector->v[i + 1].clipped_x)
			continue;
		precompute_values(i, sector, env);
		if (sector->neighbors[i] != -1
				&& !env->sectors[sector->neighbors[i]].computed)
			precompute_sector(&env->sectors[sector->neighbors[i]], env);
	}
	sector->v[sector->nb_vertices] = sector->v[0];
}

int			draw_walls2(t_env *env)
{
	int			i;
	int			screen_sectors;
	t_render2	render;

	reset_render_utils(env);
	screen_sectors = get_screen_sectors(env);
	i = 0;
	while (i < screen_sectors)
	{
		if (!env->sectors[i].computed)
			precompute_sector(&env->sectors[i], env);
		if (env->sectors[i].skybox && !env->skybox_computed)
			precompute_skybox(env);
		i++;
	}
	i = 0;
	while (i < screen_sectors)
	{
		render.sector = env->screen_sectors[i];
		render.xmin = env->xmin[i];
		render.xmax = env->xmax[i];
		render_sector2(render, env);
		i++;
	}
	return (0);
}
