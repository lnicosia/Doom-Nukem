/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 16:21:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		get_intersections2(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	t_v2	inter;
	t_v2	clipped_pos;

	inter = get_intersection(
			new_v2(camera->v[sector->num][i].vx, camera->v[sector->num][i].vz),
			new_v2(camera->v[sector->num][i + 1].vx,
				camera->v[sector->num][i + 1].vz),
			new_v2(camera->near_left, camera->near_z),
			new_v2(camera->near_right, camera->near_z));
	if (camera->v[sector->num][i].vz < camera->near_z)
	{
		camera->v[sector->num][i].clipped_vx1 = inter.x;
		camera->v[sector->num][i].clipped_vz1 = inter.y;
	}
	else
	{
		camera->v[sector->num][i].clipped_vx1 = camera->v[sector->num][i].vx;
		camera->v[sector->num][i].clipped_vz1 = camera->v[sector->num][i].vz;
	}
	if (camera->v[sector->num][i + 1].vz < camera->near_z)
	{
		camera->v[sector->num][i].clipped_vx2 = inter.x;
		camera->v[sector->num][i].clipped_vz2 = inter.y;
	}
	else
	{
		camera->v[sector->num][i].clipped_vx2 = camera->v[sector->num][i + 1].vx;
		camera->v[sector->num][i].clipped_vz2 = camera->v[sector->num][i + 1].vz;
	}
	clipped_pos.x = camera->v[sector->num][i].clipped_vx1 * camera->angle_sin
		+ camera->v[sector->num][i].clipped_vz1 * camera->angle_cos + camera->pos.x;
	clipped_pos.y = camera->v[sector->num][i].clipped_vz1 * camera->angle_sin
		- camera->v[sector->num][i].clipped_vx1 * camera->angle_cos + camera->pos.y;
	camera->v[sector->num][i].clipped_vf1 = get_floor_at_pos(*sector,
			new_v3(clipped_pos.x, clipped_pos.y, 0),
			env);
	camera->v[sector->num][i].clipped_vc1 = get_ceiling_at_pos(*sector,
			new_v3(clipped_pos.x, clipped_pos.y, 0),
			env);
	clipped_pos.x = camera->v[sector->num][i].clipped_vx2 * camera->angle_sin
		+ camera->v[sector->num][i].clipped_vz2 * camera->angle_cos + camera->pos.x;
	clipped_pos.y = camera->v[sector->num][i].clipped_vz2 * camera->angle_sin
		- camera->v[sector->num][i].clipped_vx2 * camera->angle_cos + camera->pos.y;
	camera->v[sector->num][i].clipped_vf2 = get_floor_at_pos(*sector,
			new_v3(clipped_pos.x, clipped_pos.y, 0),
			env);
	camera->v[sector->num][i].clipped_vc2 = get_ceiling_at_pos(*sector,
			new_v3(clipped_pos.x, clipped_pos.y, 0),
			env);
}

void		clip_wall2(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	if ((camera->v[sector->num][i].vz < camera->near_z
				&& camera->v[sector->num][i + 1].vz < camera->near_z)
			|| (camera->v[sector->num][i].vz > camera->far_z
				&& camera->v[sector->num][i + 1].vz > camera->far_z)
			|| (camera->v[sector->num][i].vx < camera->far_left
				&& camera->v[sector->num][i + 1].vx < camera->far_left)
			|| (camera->v[sector->num][i].vx > camera->far_right
				&& camera->v[sector->num][i + 1].vx > camera->far_right))
		camera->v[sector->num][i].draw = 0;
	else
		camera->v[sector->num][i].draw = 1;
	get_intersections2(i, camera, sector, env);
}

void		compute_wall(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	double	vx;
	double	vz;

	vx = env->vertices[sector->vertices[i]].x - camera->pos.x;
	vz = env->vertices[sector->vertices[i]].y - camera->pos.y;
	camera->v[sector->num][i].vx = vx * camera->angle_sin
		- vz * camera->angle_cos;
	camera->v[sector->num][i].vz = vx * camera->angle_cos
		+ vz * camera->angle_sin;
}

void		precompute_values(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	int	j;
	size_t	k;

	sector->selected[i] = 0;
	if (env->selected_wall1 == sector->vertices[i]
			&& env->selected_wall2 == sector->vertices[i + 1])
		sector->selected[i] = 1;
	camera->v[sector->num][i].clipped_xrange = camera->v[sector->num][i].clipped_x2
		- camera->v[sector->num][i].clipped_x1;
	camera->v[sector->num][i].xrange = camera->v[sector->num][i + 1].x - camera->v[sector->num][i].x;
	camera->v[sector->num][i].zrange = camera->v[sector->num][i].vz - camera->v[sector->num][i + 1].vz;
	camera->v[sector->num][i].zcomb = camera->v[sector->num][i + 1].vz * camera->v[sector->num][i].vz;
	camera->v[sector->num][i].x0z1 = env->vertices[sector->vertices[i]].x
		* camera->v[sector->num][i + 1].vz;
	camera->v[sector->num][i].x1z0 = env->vertices[sector->vertices[i + 1]].x
		* camera->v[sector->num][i].vz;
	camera->v[sector->num][i].xzrange = camera->v[sector->num][i].x1z0 - camera->v[sector->num][i].x0z1;
	camera->v[sector->num][i].y0z1 = env->vertices[sector->vertices[i]].y
		* camera->v[sector->num][i + 1].vz;
	camera->v[sector->num][i].y1z0 = env->vertices[sector->vertices[i + 1]].y
		* camera->v[sector->num][i].vz;
	camera->v[sector->num][i].yzrange = camera->v[sector->num][i].y1z0 - camera->v[sector->num][i].y0z1;
	camera->v[sector->num][i].floor_range = camera->v[sector->num][i].f2 - camera->v[sector->num][i].f1;
	camera->v[sector->num][i].ceiling_range = camera->v[sector->num][i].c2 - camera->v[sector->num][i].c1;
	camera->v[sector->num][i].no_slope_floor_range = camera->v[sector->num][i].no_slope_f2
		- camera->v[sector->num][i].no_slope_f1;
	camera->v[sector->num][i].no_slope_ceiling_range = camera->v[sector->num][i].no_slope_c2
		- camera->v[sector->num][i].no_slope_c1;
	if (camera->v[sector->num][i + 1].vz)
	{
		k = 0;
		while (k < env->wall_textures[sector->textures[i]].nb_maps)
		{
			if (!env->options.test)
			camera->v[sector->num][i].texture_scale[k].x = ((env->wall_textures[sector->textures[i]].maps[k]->w / sector->scale[i].x) * sector->wall_width[i] / camera->v[sector->num][i + 1].vz);
			else
			camera->v[sector->num][i].texture_scale[k].x = (sector->scale[i].x * sector->wall_width[i] / camera->v[sector->num][i + 1].vz);
			k++;
		}
		j = 0;
		while (j < sector->nb_sprites[i])
		{
			if (sector->sprites[i].sprite[j] != -1)
				camera->v[sector->num][i].sprite_scale[j].x =
				(env->wall_sprites[sector->sprites[i].sprite[j]].size[0].x
				/ sector->sprites[i].scale[j].x) * sector->wall_width[i]
				/ camera->v[sector->num][i + 1].vz;
			j++;
		}
	}
	else
	{
		k = 0;
		while (k < env->wall_textures[sector->textures[i]].nb_maps)
		{
			if (!env->options.test)
			camera->v[sector->num][i].texture_scale[k].x = ((env->wall_textures[sector->textures[i]].maps[k]->w / sector->scale[i].x) * sector->wall_width[i] / camera->v[sector->num][i].clipped_vz2);
			else
			camera->v[sector->num][i].texture_scale[k].x = (sector->scale[i].x * sector->wall_width[i] / camera->v[sector->num][i].clipped_vz2);
			k++;
		}
		j = 0;
		while (j < sector->nb_sprites[i])
		{
			if (sector->sprites[i].sprite[j] != -1)
				camera->v[sector->num][i].sprite_scale[j].x = 
		(env->wall_sprites[sector->sprites[i].sprite[j]].size[0].x
		/ sector->sprites[i].scale[j].x) * sector->wall_width[i]
				/ camera->v[sector->num][i].clipped_vz2;
			j++;
		}
	}
	k = 0;
	while (k < env->wall_textures[sector->textures[i]].nb_maps)
	{
		if (!env->options.test)
		camera->v[sector->num][i].texture_scale[k].y = (env->wall_textures[sector->textures[i]].maps[k]->h / sector->scale[i].y) * (sector->ceiling - sector->floor);
		else
		camera->v[sector->num][i].texture_scale[k].y = (env->wall_textures[sector->textures[i]].surface->h / sector->scale[i].y) * (sector->ceiling - sector->floor);
		camera->v[sector->num][i].texture_align[k].x = (sector->align[i].x
			* env->wall_textures[sector->textures[i]].maps[k]->w) / 10.0;
		camera->v[sector->num][i].texture_align[k].y = (sector->align[i].y
			* env->wall_textures[sector->textures[i]].maps[k]->h) / 10.0;
		k++;
	}
	j = 0;
	while (j < sector->nb_sprites[i])
	{
		if (sector->sprites[i].sprite[j] != -1)
			camera->v[sector->num][i].sprite_scale[j].y =
		env->wall_sprites[sector->sprites[i].sprite[j]].size[0].y
			/ sector->sprites[i].scale[j].y * (sector->ceiling - sector->floor);
		j++;
	}
}

void		get_rendered_neighbors(t_camera *camera, t_sector sector, t_env *env)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.neighbors[i] != -1 && !camera->sector_computed[sector.neighbors[i]])
		{
			camera->sector_computed[sector.neighbors[i]] = 1;
			env->visible_sectors++;
			get_rendered_neighbors(camera, env->sectors[sector.neighbors[i]], env);
		}
		i++;
	}
}

void		get_rendered_sectors_list(int screen_sectors, t_camera *camera,
		t_env *env)
{
	int			i;
	t_sector	sector;

	i = 0;
	while (i < screen_sectors)
	{
		sector = env->sectors[camera->screen_sectors[i]];
		if (!camera->sector_computed[sector.num])
		{
			camera->sector_computed[sector.num] = 1;
			env->visible_sectors++;
			get_rendered_neighbors(camera, sector, env);
		}
		i++;
	}
}

void		precompute_sector(t_camera *camera, t_sector *sector, t_env *env)
{
	int		i;

	//ft_printf("precomputing sector %d\n", sector->num);
	i = -1;
	camera->sector_computed[sector->num] = 1;
	camera->feet_y[sector->num] = env->h_h + (get_floor_at_pos(*sector,
				new_v3(camera->pos.x, camera->pos.y, 0), env)
			- camera->pos.z + camera->near_z * camera->angle_z)
		* camera->scale / -camera->near_z;
	camera->head_y[sector->num] = env->h_h + (get_ceiling_at_pos(*sector,
				new_v3(camera->pos.x, camera->pos.y,0 ), env)
			- camera->pos.z + camera->near_z * camera->angle_z)
		* camera->scale / -camera->near_z;
	while (++i < sector->nb_vertices)
		compute_wall(i, camera, sector, env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = -1;
	while (++i < sector->nb_vertices)
		clip_wall2(i, camera, sector, env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = -1;
	while (++i < sector->nb_vertices)
		project_wall(i, camera, sector, env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = -1;
	while (++i < sector->nb_vertices)
	{
		if (camera->v[sector->num][i].draw)
			precompute_values(i, camera, sector, env);
		if (sector->neighbors[i] != -1
				&& camera->v[sector->num][i].draw)
			precompute_neighbors(i, camera, sector, env);
		if (sector->textures[i] < 0
				&& !env->skybox_computed)
			precompute_skybox(env);
	}
	if (env->contains_skybox && !env->skybox_computed)
		precompute_skybox(env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
}

void		*precompute_sectors_loop(void *param)
{
	int		i;
	int		end;
	t_env	*env;
	t_camera *camera;

	i = ((t_precompute_thread*)param)->start - 1;
	end = ((t_precompute_thread*)param)->end;
	env = ((t_precompute_thread*)param)->env;
	camera = ((t_precompute_thread*)param)->camera;
	while (++i < end)
		precompute_sector(camera, &env->sectors[i], env);
	return (NULL);
}

void		precompute_sectors(t_camera *camera, t_env *env)
{
	t_precompute_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		pt[i].env = env;
		pt[i].camera = camera;
		pt[i].start = env->visible_sectors / (double)THREADS * i;
		pt[i].end = env->visible_sectors / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, precompute_sectors_loop, &pt[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

int			render_walls(t_camera *camera, t_env *env)
{
	int			i;
	int			screen_sectors;
	t_render	render;

	camera->computed = 1;
	env->visible_sectors = 0;
	reset_render_utils(camera, env);
	screen_sectors = get_screen_sectors(camera, env);
	get_rendered_sectors_list(screen_sectors, camera, env);
	precompute_sectors(camera, env);
	i = 0;
	while (i < screen_sectors)
	{
		render.xmin = camera->xmin[i];
		render.xmax = camera->xmax[i];
		render.sector = camera->screen_sectors[i];
		render.camera = camera;
		render.ystart = 0;
		render.yend = env->h - 1;
		render_sector(render, env);
		i++;
	}
	return (0);
}

int		draw_walls(t_camera *camera, t_env *env)
{
	return (render_walls(camera, env));
}
