/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_neighbors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:13:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 16:03:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		precompute_neighbors(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	t_sector	neighbor;
	int			nv1;
	int			nv2;

	neighbor = env->sectors[sector->neighbors[i]];
	nv1 = get_vertex_nb_in_sector(sector->vertices[i], neighbor);
	nv2 = get_vertex_nb_in_sector(sector->vertices[i + 1], neighbor);
	/*camera->v[sector->num][i].neighbor_f1 = env->h_h + (neighbor.v[nv1].clipped_vf1
			- camera->pos.z + camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_f2 = env->h_h + (neighbor.v[nv2].clipped_vf2
			- camera->pos.z + camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].neighbor_c1 = env->h_h + (neighbor.v[nv1].clipped_vc1
			- camera->pos.z + camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_c2 = env->h_h + (neighbor.v[nv2].clipped_vc2
			- camera->pos.z + camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;*/
	camera->v[sector->num][i].neighbor_f1 = env->h_h + (neighbor.floors[nv1]
			- camera->pos.z + camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_f2 = env->h_h + (neighbor.floors[nv2]
			- camera->pos.z + camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].neighbor_c1 = env->h_h + (neighbor.ceilings[nv1]
			- camera->pos.z + camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].neighbor_c2 = env->h_h + (neighbor.ceilings[nv2]
			- camera->pos.z + camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].neighbor_floor_range = camera->v[sector->num][i].neighbor_f2
		- camera->v[sector->num][i].neighbor_f1;
	camera->v[sector->num][i].neighbor_ceiling_range = camera->v[sector->num][i].neighbor_c2
		- camera->v[sector->num][i].neighbor_c1;
}
