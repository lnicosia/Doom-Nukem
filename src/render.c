/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:23:27 by lnicosia         ###   ########.fr       */
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
			new_v2(env->player.camera.near_left, env->player.camera.near_z),
			new_v2(env->player.camera.near_right, env->player.camera.near_z));
	if (sector->v[i].vz < env->player.camera.near_z)
	{
		sector->v[i].clipped_vx1 = inter.x;
		sector->v[i].clipped_vz1 = inter.y;
	}
	else
	{
		sector->v[i].clipped_vx1 = sector->v[i].vx;
		sector->v[i].clipped_vz1 = sector->v[i].vz;
	}
	if (sector->v[i + 1].vz < env->player.camera.near_z)
	{
		sector->v[i].clipped_vx2 = inter.x;
		sector->v[i].clipped_vz2 = inter.y;
	}
	else
	{
		sector->v[i].clipped_vx2 = sector->v[i + 1].vx;
		sector->v[i].clipped_vz2 = sector->v[i + 1].vz;
	}
	clipped_pos.x = sector->v[i].clipped_vx1 * env->player.camera.angle_sin
		+ sector->v[i].clipped_vz1 * env->player.camera.angle_cos + env->player.pos.x;
	clipped_pos.y = sector->v[i].clipped_vz1 * env->player.camera.angle_sin
		- sector->v[i].clipped_vx1 * env->player.camera.angle_cos + env->player.pos.y;
	sector->v[i].clipped_vf1 = get_floor_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	sector->v[i].clipped_vc1 = get_ceiling_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	clipped_pos.x = sector->v[i].clipped_vx2 * env->player.camera.angle_sin
		+ sector->v[i].clipped_vz2 * env->player.camera.angle_cos + env->player.pos.x;
	clipped_pos.y = sector->v[i].clipped_vz2 * env->player.camera.angle_sin
		- sector->v[i].clipped_vx2 * env->player.camera.angle_cos + env->player.pos.y;
	sector->v[i].clipped_vf2 = get_floor_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
	sector->v[i].clipped_vc2 = get_ceiling_at_pos(*sector,
			new_v2(clipped_pos.x, clipped_pos.y),
			env);
}

void		clip_wall2(int i, t_sector *sector, t_env *env)
{
	if ((sector->v[i].vz < env->player.camera.near_z
				&& sector->v[i + 1].vz < env->player.camera.near_z)
			|| (sector->v[i].vz > env->player.camera.far_z
				&& sector->v[i + 1].vz > env->player.camera.far_z)
			|| (sector->v[i].vx < env->player.camera.far_left
				&& sector->v[i + 1].vx < env->player.camera.far_left)
			|| (sector->v[i].vx > env->player.camera.far_right
				&& sector->v[i + 1].vx > env->player.camera.far_right))
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
	sector->v[i].vx = vx * env->player.camera.angle_sin
		- vz * env->player.camera.angle_cos;
	sector->v[i].vz = vx * env->player.camera.angle_cos
		+ vz * env->player.camera.angle_sin;
}

void		precompute_values(int i, t_sector *sector, t_env *env)
{
	sector->v[i].selected = 0;
	if (env->selected_wall1 == sector->vertices[i]
			&& env->selected_wall2 == sector->vertices[i + 1])
		sector->v[i].selected = 1;
	sector->v[i].clipped_xrange = sector->v[i].clipped_x2
		- sector->v[i].clipped_x1;
	sector->v[i].xrange = sector->v[i + 1].x - sector->v[i].x;
	sector->v[i].zrange = sector->v[i].vz - sector->v[i + 1].vz;
	sector->v[i].zcomb = sector->v[i + 1].vz * sector->v[i].vz;
	sector->v[i].x0z1 = env->vertices[sector->vertices[i]].x
		* sector->v[i + 1].vz;
	sector->v[i].x1z0 = env->vertices[sector->vertices[i + 1]].x
		* sector->v[i].vz;
	sector->v[i].xzrange = sector->v[i].x1z0 - sector->v[i].x0z1;
	sector->v[i].y0z1 = env->vertices[sector->vertices[i]].y
		* sector->v[i + 1].vz;
	sector->v[i].y1z0 = env->vertices[sector->vertices[i + 1]].y
		* sector->v[i].vz;
	sector->v[i].yzrange = sector->v[i].y1z0 - sector->v[i].y0z1;
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

void		get_rendered_neighbors(t_sector sector, t_env *env)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.neighbors[i] != -1 && !env->sectors[sector.neighbors[i]].computed)
		{
			env->sectors[sector.neighbors[i]].computed = 1;
			env->visible_sectors++;
			get_rendered_neighbors(env->sectors[sector.neighbors[i]], env);
		}
		i++;
	}
}

void		get_rendered_sectors_list(int screen_sectors, t_env *env)
{
	int			i;
	t_sector	sector;

	i = 0;
	while (i < screen_sectors)
	{
		sector = env->sectors[env->screen_sectors[i]];
		if (!sector.computed)
		{
			env->sectors[env->screen_sectors[i]].computed = 1;
			env->visible_sectors++;
		}
		get_rendered_neighbors(sector, env);
		i++;
	}
}

void		precompute_sector(t_sector *sector, t_env *env)
{
	int		i;

	i = -1;
	sector->computed++;
	sector->feet_y = env->h_h + (get_floor_at_pos(*sector,
				new_v2(env->player.pos.x, env->player.pos.y), env)
			- env->player.head_z + env->player.camera.near_z * env->player.camera.angle_z)
		* env->player.camera.scale / -env->player.camera.near_z;
	sector->head_y = env->h_h + (get_ceiling_at_pos(*sector,
				new_v2(env->player.pos.x, env->player.pos.y), env)
			- env->player.head_z + env->player.camera.near_z * env->player.camera.angle_z)
		* env->player.camera.scale / -env->player.camera.near_z;
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
			precompute_neighbors(i, sector,
					env->sectors[sector->neighbors[i]], env);
		if (sector->textures[i] == -1
				&& !env->skybox_computed)
			precompute_skybox(env);
	}
	if (sector->skybox && !env->skybox_computed)
		precompute_skybox(env);
	sector->v[sector->nb_vertices] = sector->v[0];
}

void		*precompute_sectors_loop(void *param)
{
	int		i;
	int		end;
	t_env	*env;

	i = ((t_precompute_thread*)param)->start - 1;
	end = ((t_precompute_thread*)param)->end;
	env = ((t_precompute_thread*)param)->env;
	while (++i < end)
	{
		precompute_sector(&env->sectors[i], env);
	}
	return (NULL);
}

void		precompute_sectors(t_env *env)
{
	t_precompute_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		pt[i].env = env;
		pt[i].start = env->visible_sectors / (double)THREADS * i;
		pt[i].end = env->visible_sectors / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, precompute_sectors_loop, &pt[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

int			draw_walls2(t_env *env)
{
	int			i;
	int			screen_sectors;
	t_render2	render;

	env->visible_sectors = 0;
	reset_render_utils(env);
	screen_sectors = get_screen_sectors(env);
	get_rendered_sectors_list(screen_sectors, env);
	precompute_sectors(env);
	i = 0;
	while (i < screen_sectors)
	{
		render.xmin = env->xmin[i];
		render.xmax = env->xmax[i];
		render.sector = env->screen_sectors[i];
		render_sector2(render, env);
		i++;
	}
	return (0);
}
