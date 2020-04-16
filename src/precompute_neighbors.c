/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_neighbors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:13:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 09:54:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		precompute_neighbors(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	t_sector	*neighbor;

	neighbor = &env->sectors[sector->neighbors[i]];
	camera->v[sector->num][i].neighbor_f1 = env->h_h +
		(get_floor_at_pos(neighbor, new_v3(camera->v[sector->num][i].
		clipped_pos_x1, camera->v[sector->num][i].clipped_pos_y1, 0), env)
		- camera->pos.z + camera->v[sector->num][i].angle_z1)
		* camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_f2 = env->h_h +
		(get_floor_at_pos(neighbor, new_v3(camera->v[sector->num][i].
		clipped_pos_x2, camera->v[sector->num][i].clipped_pos_y2, 0), env)
		- camera->pos.z + camera->v[sector->num][i].angle_z2)
		* camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].neighbor_c1 = env->h_h +
		(get_ceiling_at_pos(neighbor, new_v3(camera->v[sector->num][i].
		clipped_pos_x1, camera->v[sector->num][i].clipped_pos_y1, 0), env)
		- camera->pos.z + camera->v[sector->num][i].angle_z1)
		* camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_c2 = env->h_h +
		(get_ceiling_at_pos(neighbor, new_v3(camera->v[sector->num][i].
		clipped_pos_x2, camera->v[sector->num][i].clipped_pos_y2, 0), env)
		- camera->pos.z + camera->v[sector->num][i].angle_z2)
		* camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].neighbor_floor_range =
		camera->v[sector->num][i].neighbor_f2
		- camera->v[sector->num][i].neighbor_f1;
	camera->v[sector->num][i].neighbor_ceiling_range =
		camera->v[sector->num][i].neighbor_c2
		- camera->v[sector->num][i].neighbor_c1;
}
