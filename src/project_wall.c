/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:46:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 17:23:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		project_wall(int i, t_sector *sector, t_env *env)
{
	sector->v[i].scale = env->camera.scale / -sector->v[i].vz;
	sector->v[i].angle_z = sector->v[i].clipped_vz
		* env->player.angle_z;
	sector->v[i].f = env->h_h + (sector->v[i].clipped_vf +
			sector->v[i].angle_z) * sector->v[i].scale;
	if (sector->v[i].f < 0 || sector->v[i].f >= env->h)
		return (1);
	sector->v[i].c = env->h_h + (sector->v[i].clipped_vc +
			sector->v[i].angle_z) * sector->v[i].scale;
	if (sector->v[i].c < 0 || sector->v[i].c >= env->h
			|| sector->v[i].c >= sector->v[i].f)
		return (1);
	sector->v[i].clipped_x = env->h_w + sector->v[i].clipped_vx
		* sector->v[i].scale;
	if (sector->v[i].x < 0 || sector->v[i].x >= env->w)
		return (1);
	sector->v[i].clipped_x = ceil(sector->v[i].x);
	sector->v[i].no_slope_f = env->h_h + (sector->floor
			- env->player.head_z + sector->v[i].angle_z)
		* sector->v[i].scale;
	sector->v[i].no_slope_c = env->h_h + (sector->ceiling
			- env->player.head_z + sector->v[i].angle_z)
		* sector->v[i].scale;
	sector->v[i].x = env->h_w + sector->v[i].vx;
	return (0);
}
