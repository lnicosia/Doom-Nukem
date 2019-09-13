/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_neighbors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:13:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/12 13:37:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void		precompute_neighbors(int i, t_sector *sector, t_sector neighbor,
		t_env *env)
{
	int	nv1;
	int	nv2;

	nv1 = get_vertex_nb_in_sector(sector->vertices[i], neighbor);
	nv2 = get_vertex_nb_in_sector(sector->vertices[i + 1], neighbor);
	/*sector->v[i].neighbor_f1 = env->h_h + (neighbor.v[nv1].clipped_vf1
			- env->player.head_z + sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].neighbor_f2 = env->h_h + (neighbor.v[nv2].clipped_vf2
			- env->player.head_z + sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].neighbor_c1 = env->h_h + (neighbor.v[nv1].clipped_vc1
			- env->player.head_z + sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].neighbor_c2 = env->h_h + (neighbor.v[nv2].clipped_vc2
			- env->player.head_z + sector->v[i].angle_z2) * sector->v[i].scale2;*/
	sector->v[i].neighbor_f1 = env->h_h + (neighbor.floors[nv1]
			- env->player.head_z + sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].neighbor_f2 = env->h_h + (neighbor.floors[nv2]
			- env->player.head_z + sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].neighbor_c1 = env->h_h + (neighbor.ceilings[nv1]
			- env->player.head_z + sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].neighbor_c2 = env->h_h + (neighbor.ceilings[nv2]
			- env->player.head_z + sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].neighbor_floor_range = sector->v[i].neighbor_f2
		- sector->v[i].neighbor_f1;
	sector->v[i].neighbor_ceiling_range = sector->v[i].neighbor_c2
		- sector->v[i].neighbor_c1;
}
