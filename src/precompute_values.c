/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:28:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:28:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	precompute_mipmaps(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	size_t	k;

	k = 0;
	while (k < env->wall_textures[sector->textures[i]].nb_maps)
	{
		camera->v[sector->num][i].texture_scale[k].y =
		(env->wall_textures[sector->textures[i]].maps[k]->h
		/ sector->scale[i].y) * (sector->ceiling - sector->floor);
		camera->v[sector->num][i].texture_align[k].x = (sector->align[i].x
			* env->wall_textures[sector->textures[i]].maps[k]->w) / 10.0;
		camera->v[sector->num][i].texture_align[k].y = (sector->align[i].y
			* env->wall_textures[sector->textures[i]].maps[k]->h) / 10.0;
		k++;
	}
}

void	precompute_wall_sprites(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	int		j;

	j = 0;
	while (j < sector->wall_sprites[i].nb_sprites)
	{
		if (sector->wall_sprites[i].sprite[j] != -1)
			camera->v[sector->num][i].sprite_scale[j].y =
		env->object_sprites[sector->wall_sprites[i].sprite[j]].size[0].y
			/ sector->wall_sprites[i].scale[j].y
			* (sector->ceiling - sector->floor);
		j++;
	}
}

void	precompute_bullet_holes_y(int i, t_sector *sector,
		t_env *env)
{
	t_list			*wall_bullet_holes;
	t_bullet_hole	*curr;

	wall_bullet_holes = sector->wall_bullet_holes[i];
	while (wall_bullet_holes)
	{
		curr = (t_bullet_hole*)wall_bullet_holes->content;
		curr->scale.y =
			env->object_sprites[BULLET_HOLE].size[0].x
			/ curr->map_scale.y
			* (sector->ceiling - sector->floor);
		wall_bullet_holes = wall_bullet_holes->next;
	}
}

void	precompute_values2(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	camera->v[sector->num][i].y1z0 =
	env->vertices[sector->vertices[i + 1]].y
		* camera->v[sector->num][i].vz;
	camera->v[sector->num][i].yzrange =
	camera->v[sector->num][i].y1z0 - camera->v[sector->num][i].y0z1;
	camera->v[sector->num][i].floor_range =
	camera->v[sector->num][i].f2 - camera->v[sector->num][i].f1;
	camera->v[sector->num][i].ceiling_range =
	camera->v[sector->num][i].c2 - camera->v[sector->num][i].c1;
	camera->v[sector->num][i].no_slope_floor_range =
	camera->v[sector->num][i].no_slope_f2
		- camera->v[sector->num][i].no_slope_f1;
	camera->v[sector->num][i].no_slope_ceiling_range =
	camera->v[sector->num][i].no_slope_c2 -
	camera->v[sector->num][i].no_slope_c1;
	if (camera->v[sector->num][i + 1].vz)
		precompute_visible_vertex(i, camera, sector, env);
	else
		precompute_clipped_vertex(i, camera, sector, env);
	precompute_mipmaps(i, camera, sector, env);
	precompute_wall_sprites(i, camera, sector, env);
	precompute_bullet_holes_y(i, sector, env);
}

void	precompute_values(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	sector->selected[i] = 0;
	if (env->selected_wall1 == sector->vertices[i]
			&& env->selected_wall2 == sector->vertices[i + 1])
		sector->selected[i] = 1;
	camera->v[sector->num][i].clipped_xrange =
	camera->v[sector->num][i].clipped_x2
		- camera->v[sector->num][i].clipped_x1;
	camera->v[sector->num][i].xrange =
	camera->v[sector->num][i + 1].x - camera->v[sector->num][i].x;
	camera->v[sector->num][i].zrange =
	camera->v[sector->num][i].vz - camera->v[sector->num][i + 1].vz;
	camera->v[sector->num][i].zcomb =
	camera->v[sector->num][i + 1].vz * camera->v[sector->num][i].vz;
	camera->v[sector->num][i].x0z1 =
	env->vertices[sector->vertices[i]].x
		* camera->v[sector->num][i + 1].vz;
	camera->v[sector->num][i].x1z0 =
	env->vertices[sector->vertices[i + 1]].x
		* camera->v[sector->num][i].vz;
	camera->v[sector->num][i].xzrange =
	camera->v[sector->num][i].x1z0 - camera->v[sector->num][i].x0z1;
	camera->v[sector->num][i].y0z1 =
	env->vertices[sector->vertices[i]].y
		* camera->v[sector->num][i + 1].vz;
	precompute_values2(i, camera, sector, env);
}
