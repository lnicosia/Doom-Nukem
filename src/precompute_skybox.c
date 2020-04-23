/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_skybox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:17:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 18:40:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		project_skybox(int i, t_env *env)
{
	env->skybox[i].scale1 = env->player.camera.scale
	/ -env->skybox[i].clipped_vz1;
	env->skybox[i].scale2 = env->player.camera.scale
	/ -env->skybox[i].clipped_vz2;
	env->skybox[i].angle_z1 = env->skybox[i].clipped_vz1
		* env->player.camera.angle_z;
	env->skybox[i].angle_z2 = env->skybox[i].clipped_vz2
		* env->player.camera.angle_z;
	env->skybox[i].f1 = env->h_h + (-5 + env->skybox[i].angle_z1)
		* env->skybox[i].scale1;
	env->skybox[i].f2 = env->h_h + (-5 + env->skybox[i].angle_z2)
		* env->skybox[i].scale2;
	env->skybox[i].c1 = env->h_h + (5 + env->skybox[i].angle_z1)
		* env->skybox[i].scale1;
	env->skybox[i].c2 = env->h_h + (5 + env->skybox[i].angle_z2)
		* env->skybox[i].scale2;
	env->skybox[i].clipped_x1 = env->h_w + env->skybox[i].clipped_vx1
		* env->skybox[i].scale1;
	env->skybox[i].clipped_x2 = env->h_w + env->skybox[i].clipped_vx2
		* env->skybox[i].scale2;
	env->skybox[i].clipped_x1 = ceil(env->skybox[i].clipped_x1);
	env->skybox[i].x = env->h_w + env->skybox[i].vx * env->player.camera.scale
		/ -env->skybox[i].vz;
	return (0);
}

void	get_skybox_intersections2(t_v2 inter, int i, t_env *env)
{
	if (env->skybox[i + 1].vz < env->player.camera.near_z)
	{
		env->skybox[i].clipped_vx2 = inter.x;
		env->skybox[i].clipped_vz2 = inter.y;
	}
	else
	{
		env->skybox[i].clipped_vx2 = env->skybox[i + 1].vx;
		env->skybox[i].clipped_vz2 = env->skybox[i + 1].vz;
	}
}

void	get_skybox_intersections(int i, t_env *env)
{
	t_v2	inter;

	inter = get_intersection(
			new_v2(env->skybox[i].vx, env->skybox[i].vz),
			new_v2(env->skybox[i + 1].vx, env->skybox[i + 1].vz),
			new_v2(env->player.camera.near_left, env->player.camera.near_z),
			new_v2(env->player.camera.near_right, env->player.camera.near_z));
	if (env->skybox[i].vz < env->player.camera.near_z)
	{
		env->skybox[i].clipped_vx1 = inter.x;
		env->skybox[i].clipped_vz1 = inter.y;
	}
	else
	{
		env->skybox[i].clipped_vx1 = env->skybox[i].vx;
		env->skybox[i].clipped_vz1 = env->skybox[i].vz;
	}
	get_skybox_intersections2(inter, i, env);
}

void	clip_skybox2(int i, t_env *env)
{
	if ((env->skybox[i].vz < env->player.camera.near_z
				&& env->skybox[i + 1].vz < env->player.camera.near_z)
			|| (env->skybox[i].vz > env->player.camera.far_z
				&& env->skybox[i + 1].vz > env->player.camera.far_z)
			|| (env->skybox[i].vx < env->player.camera.far_left
				&& env->skybox[i + 1].vx < env->player.camera.far_left)
			|| (env->skybox[i].vx > env->player.camera.far_right
				&& env->skybox[i + 1].vx > env->player.camera.far_right))
		env->skybox[i].draw = 0;
	else
		env->skybox[i].draw = 1;
	get_skybox_intersections(i, env);
}

void	compute_skybox2(t_v2 pos, int i, t_env *env)
{
	env->skybox[i].vx = (pos.x - 5) * env->player.camera.angle_sin
		- (pos.y - 5) * env->player.camera.angle_cos;
	env->skybox[i].vz = (pos.x - 5) * env->player.camera.angle_cos
		+ (pos.y - 5) * env->player.camera.angle_sin;
}

void	precompute_skybox(t_env *env)
{
	int	i;

	env->skybox_computed++;
	i = -1;
	while (++i < 4)
		compute_skybox2(set_v2(i), i, env);	
	env->skybox[4] = env->skybox[0];
	i = -1;
	while (++i < 4)
		clip_skybox2(i ,env);
	env->skybox[4] = env->skybox[0];
	i = -1;
	while (++i < 4)
		project_skybox(i, env);
	env->skybox[4] = env->skybox[0];
	i = -1;
	while (++i < 4)
	{
		if (env->skybox[i].draw)
			precompute_skybox_values(i, env);
	}
	env->skybox[4] = env->skybox[0];
}
