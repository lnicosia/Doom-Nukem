/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:34:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/06 21:34:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	project_wall2(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	camera->v[sector->num][i].clipped_x2 = env->h_w +
	camera->v[sector->num][i].clipped_vx2 * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].no_slope_f1 = env->h_h +
	(sector->floor - camera->pos.z + camera->v[sector->num][i].angle_z1)
	* camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].no_slope_f2 = env->h_h +
	(sector->floor - camera->pos.z + camera->v[sector->num][i].angle_z2)
	* camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].no_slope_c1 = env->h_h +
	(sector->ceiling - camera->pos.z + camera->v[sector->num][i].angle_z1)
	* camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].no_slope_c2 = env->h_h +
	(sector->ceiling - camera->pos.z + camera->v[sector->num][i].angle_z2)
	* camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].x = env->h_w + camera->v[sector->num][i].vx
	* camera->scale / -camera->v[sector->num][i].vz;
	camera->v[sector->num][i].floor_horizon = env->h_h + (sector->floor_slope
	* (sector->floor_max + camera->pos.z) + camera->v[sector->num][i].angle_z1)
	* camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].ceiling_horizon = env->h_h +
	(sector->ceiling_slope * (sector->ceiling_max + camera->pos.z) +
	camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].floor_horizon = camera->horizon;
	camera->v[sector->num][i].ceiling_horizon = camera->horizon;
}

int		project_wall(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	camera->v[sector->num][i].scale1 = camera->scale /
	-camera->v[sector->num][i].clipped_vz1;
	camera->v[sector->num][i].scale2 = camera->scale /
	-camera->v[sector->num][i].clipped_vz2;
	camera->v[sector->num][i].angle_z1 = camera->v[sector->num][i].clipped_vz1
		* camera->angle_z;
	camera->v[sector->num][i].angle_z2 = camera->v[sector->num][i].clipped_vz2
		* camera->angle_z;
	camera->v[sector->num][i].f1 = env->h_h +
	(camera->v[sector->num][i].clipped_vf1 - camera->pos.z
	+ camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].f2 = env->h_h
	+ (camera->v[sector->num][i].clipped_vf2 - camera->pos.z
	+ camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].c1 = env->h_h +
	(camera->v[sector->num][i].clipped_vc1 - camera->pos.z
	+ camera->v[sector->num][i].angle_z1) * camera->v[sector->num][i].scale1;
	camera->v[sector->num][i].c2 = env->h_h
	+ (camera->v[sector->num][i].clipped_vc2 - camera->pos.z
	+ camera->v[sector->num][i].angle_z2) * camera->v[sector->num][i].scale2;
	camera->v[sector->num][i].clipped_x1 = env->h_w +
	camera->v[sector->num][i].clipped_vx1 * camera->v[sector->num][i].scale1;
	project_wall2(i, camera, sector, env);
	return (0);
}
