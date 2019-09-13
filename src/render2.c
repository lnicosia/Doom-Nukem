/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/13 15:30:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

void		get_intersections2(int i, t_sector *sector, t_env *env)
{
	t_v2	inter;
	t_v2	clipped_pos;

	inter = get_intersection(
			new_v2(sector->v[i].vx, sector->v[i].vz),
			new_v2(sector->v[i + 1].vx, sector->v[i + 1].vz),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.near_right, env->camera.near_z));
	if (sector->v[i].vz < env->camera.near_z)
	{
		sector->v[i].clipped_vx1 = inter.x;
		sector->v[i].clipped_vz1 = inter.y;
	}
	else
	{
		sector->v[i].clipped_vx1 = sector->v[i].vx;
		sector->v[i].clipped_vz1 = sector->v[i].vz;
	}
	if (sector->v[i + 1].vz < env->camera.near_z)
	{
		sector->v[i].clipped_vx2 = inter.x;
		sector->v[i].clipped_vz2 = inter.y;
	}
	else
	{
		sector->v[i].clipped_vx2 = sector->v[i + 1].vx;
		sector->v[i].clipped_vz2 = sector->v[i + 1].vz;
	}
	clipped_pos.x = sector->v[i].clipped_vx1 * env->player.angle_sin
		+ sector->v[i].clipped_vz1 * env->player.angle_cos + env->player.pos.x;
	clipped_pos.y = sector->v[i].clipped_vz1 * env->player.angle_sin
		- sector->v[i].clipped_vx1 * env->player.angle_cos + env->player.pos.y;
	sector->v[i].clipped_vf1 = get_floor_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	sector->v[i].clipped_vc1 = get_ceiling_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	clipped_pos.x = sector->v[i].clipped_vx2 * env->player.angle_sin
		+ sector->v[i].clipped_vz2 * env->player.angle_cos + env->player.pos.x;
	clipped_pos.y = sector->v[i].clipped_vz2 * env->player.angle_sin
		- sector->v[i].clipped_vx2 * env->player.angle_cos + env->player.pos.y;
	sector->v[i].clipped_vf2 = get_floor_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	sector->v[i].clipped_vc2 = get_ceiling_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
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
		sector->v[i].draw = 0;
	else
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
	sector->v[i].selected = 0;
	if (env->selected_wall1 == sector->vertices[i]
			&& env->selected_wall2 == sector->vertices[i + 1])
		sector->v[i].selected = 1;
	sector->v[i].clipped_xrange = sector->v[i].clipped_x2
		- sector->v[i].clipped_x1;
	sector->v[i].xrange = sector->v[i + 1].x
		- sector->v[i].x;
	sector->v[i].floor_range = sector->v[i].f2 - sector->v[i].f1;
	sector->v[i].ceiling_range = sector->v[i].c2 - sector->v[i].c1;
	sector->v[i].no_slope_floor_range = sector->v[i].no_slope_f2
		- sector->v[i].no_slope_f1;
	sector->v[i].no_slope_ceiling_range = sector->v[i].no_slope_c2
		- sector->v[i].no_slope_c1;
	if (sector->textures[i] == -1)
	{
		if (sector->v[i + 1].vz)
			sector->v[i].texture_scale.x = env->textures[38].surface->w
				/ sector->v[i + 1].vz;
		else
			sector->v[i].texture_scale.x = env->textures[38].surface->w
				/ sector->v[i].clipped_vz2;
		sector->v[i].texture_scale.y = env->textures[38].surface->h;
	}
	else
	{
		if (sector->v[i + 1].vz)
			sector->v[i].texture_scale.x = env->textures[sector->textures[i]].
				surface->w * (sector->wall_width[i] / 10) / sector->v[i + 1].vz;
		else
			sector->v[i].texture_scale.x = env->textures[sector->textures[i]].
				surface->w * (sector->wall_width[i] / 10)
				/ sector->v[i].clipped_vz2;
		sector->v[i].texture_scale.y = env->textures[sector->textures[i]].
			surface->h * (sector->ceiling - sector->floor) / 10;
	}
}

void		precompute_sector(t_sector *sector, t_env *env)
{
	int		i;

	i = -1;
	sector->computed++;
	while (++i < sector->nb_vertices)
		compute_wall(i, sector, env);
	sector->v[sector->nb_vertices] = sector->v[0];
	i = -1;
	while (++i < sector->nb_vertices)
		clip_wall2(i, sector, env);
	sector->v[sector->nb_vertices] = sector->v[0];
	i = -1;
	while (++i < sector->nb_vertices)
		project_wall(i, sector, env);
	sector->v[sector->nb_vertices] = sector->v[0];
	i = -1;
	while (++i < sector->nb_vertices)
	{
		if (sector->v[i].draw)
			precompute_values(i, sector, env);
		if (sector->neighbors[i] != -1
				&& sector->v[i].draw)
		{
			if (!env->sectors[sector->neighbors[i]].computed)
				precompute_sector(&env->sectors[sector->neighbors[i]], env);
			precompute_neighbors(i, sector,
					env->sectors[sector->neighbors[i]], env);
		}
		if (sector->textures[i] == -1
				&& !env->skybox_computed)
			precompute_skybox(env);
	}
	if (sector->skybox && !env->skybox_computed)
		precompute_skybox(env);
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
		if (!env->sectors[env->screen_sectors[i]].computed)
			precompute_sector(&env->sectors[env->screen_sectors[i]], env);
		i++;
	}
	i = 0;
	while (i < screen_sectors)
	{
		render.xmin = env->xmin[i];
		render.xmax = env->xmax[i];
		render.sector = env->screen_sectors[i];
		render.portal = 0;
		render_sector2(render, env);
		i++;
	}
	return (0);
}
