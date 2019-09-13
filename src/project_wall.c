/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:46:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/13 16:29:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		project_wall(int i, t_sector *sector, t_env *env)
{
	sector->v[i].scale1 = env->camera.scale / -sector->v[i].clipped_vz1;
	sector->v[i].scale2 = env->camera.scale / -sector->v[i].clipped_vz2;
	sector->v[i].angle_z1 = sector->v[i].clipped_vz1
		* env->player.angle_z;
	sector->v[i].angle_z2 = sector->v[i].clipped_vz2
		* env->player.angle_z;
	sector->v[i].f1 = env->h_h + (sector->v[i].clipped_vf1 - env->player.head_z
			+ sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].f2 = env->h_h + (sector->v[i].clipped_vf2 - env->player.head_z
			+ sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].c1 = env->h_h + (sector->v[i].clipped_vc1 - env->player.head_z
			+ sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].c2 = env->h_h + (sector->v[i].clipped_vc2 - env->player.head_z
			+ sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].clipped_x1 = env->h_w + sector->v[i].clipped_vx1
		* sector->v[i].scale1;
	sector->v[i].clipped_x2 = env->h_w + sector->v[i].clipped_vx2
		* sector->v[i].scale2;
	//sector->v[i].clipped_x1 = ceil(sector->v[i].clipped_x1);
	sector->v[i].no_slope_f1 = env->h_h + (sector->floor - env->player.head_z
			+ sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].no_slope_f2 = env->h_h + (sector->floor - env->player.head_z
			+ sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].no_slope_c1 = env->h_h + (sector->ceiling - env->player.head_z
			+ sector->v[i].angle_z1) * sector->v[i].scale1;
	sector->v[i].no_slope_c2 = env->h_h + (sector->ceiling - env->player.head_z
			+ sector->v[i].angle_z2) * sector->v[i].scale2;
	sector->v[i].x = env->h_w + sector->v[i].vx
		* env->camera.scale / -sector->v[i].vz;
	//sector->v[i].x = ceil(sector->v[i].x);
	sector->v[i].floor_horizon = env->h_h + (sector->floor_slope
			* (sector->floor_max + env->player.head_z) + sector->v[i].angle_z1)
		* sector->v[i].scale1;
	sector->v[i].ceiling_horizon = env->h_h + (sector->ceiling_slope
			* (sector->ceiling_max + env->player.head_z) + sector->v[i].angle_z1)
		* sector->v[i].scale1;
	sector->v[i].xz = env->vertices[sector->vertices[i]].x
		/ sector->v[i].vz;
	sector->v[i].yz = env->vertices[sector->vertices[i]].y
		/ sector->v[i].vz;
	return (0);
}
