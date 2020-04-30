/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_sector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:24:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:24:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	precompute_sector2(t_camera *camera, t_sector *sector, t_env *env)
{
	int		i;

	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = -1;
	while (++i < sector->nb_vertices)
		project_wall(i, camera, sector, env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = 0;
	while (i < sector->nb_vertices)
	{
		if (camera->v[sector->num][i].draw)
			precompute_values(i, camera, sector, env);
		if (sector->neighbors[i] != -1
				&& camera->v[sector->num][i].draw)
			precompute_neighbors(i, camera, sector, env);
		if (sector->textures[i] < 0
				&& !env->skybox_computed)
			precompute_skybox(env);
		i++;
	}
	if (env->contains_skybox && !env->skybox_computed)
		precompute_skybox(env);
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
}

void	precompute_sector(t_camera *camera, t_sector *sector, t_env *env)
{
	int		i;

	camera->sector_computed[sector->num] = 1;
	camera->feet_y[sector->num] = env->h_h + (get_floor_at_pos(sector,
		new_v3(camera->pos.x, camera->pos.y, 0), env)
		- camera->pos.z + camera->near_z * camera->angle_z)
		* camera->scale / -camera->near_z;
	camera->head_y[sector->num] = env->h_h + (get_ceiling_at_pos(sector,
		new_v3(camera->pos.x, camera->pos.y, 0), env)
		- camera->pos.z + camera->near_z * camera->angle_z)
		* camera->scale / -camera->near_z;
	i = 0;
	while (i < sector->nb_vertices)
	{
		compute_wall(i, camera, sector, env);
		i++;
	}
	camera->v[sector->num][sector->nb_vertices] = camera->v[sector->num][0];
	i = 0;
	while (i < sector->nb_vertices)
	{
		clip_wall(i, camera, sector, env);
		i++;
	}
	precompute_sector2(camera, sector, env);
}
