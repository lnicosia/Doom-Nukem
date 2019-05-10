/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:33:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/09 19:01:34 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

int		is_in_fov(double x, double z, t_env *env)
{
	(void)x;
	(void)env;
	if (z > env->camera.near_z)
		return (1);
	return (0);
}

void	clip_walls(t_render*render, t_env *env)
{
	//t_v2	vz1;
	t_v2	vz2;

	render->clipped = 0;
	if (render->vz1 <= env->camera.near_z || render->vz2 <= env->camera.near_z)
	{
		vz2 = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(-100000, env->camera.near_z),
				new_v2(100000, env->camera.near_z));
		render->clipped = 1;
	}
	if (render->vz1 <= env->camera.near_z)
	{
		render->vx1 = vz2.x;
		render->vz1 = vz2.y;
	}
	if (render->vz2 <= env->camera.near_z)
	{
		render->vx2 = vz2.x;
		render->vz2 = vz2.y;
	}
	/*if (render->vz1 <= 0 || render->vz2 <= 0)
	{
		render->clipped = 1;
		//Trouver une intersection entre le mur et le champ de vision du joueur
			vz1 = get_intersection(
					new_v2(render->vx1, render->vz1),
					new_v2(render->vx2, render->vz2),
					new_v2(env->camera.near_left, env->camera.near_z),
					new_v2(env->camera.far_left, env->camera.far_z));
			vz2 = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(env->camera.near_right, env->camera.near_z),
				new_v2(env->camera.far_right, env->camera.far_z));
		if (render->vz1 < env->camera.near_z)
		{
			if(new_vz1.y > 0)
			{
				render->vx1 = new_vz1.x;
				render->vz1 = new_vz1.y;
			}
			else
			{
				render->vx1 = new_vz2.x;
				render->vz1 = new_vz2.y;
			}
		}
		if (render->vz2 < env->camera.near_z)
		{
			if(new_vz1.y > 0)
			{
				render->vx2 = new_vz1.x;
				render->vz2 = new_vz1.y;
			}
			else
			{
				render->vx2 = new_vz2.x;
				render->vz2 = new_vz2.y;
			}
		}
	}
	else
		render->clipped = 0;*/
}