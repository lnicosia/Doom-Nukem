/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_skybox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:17:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 18:05:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void	precompute_skybox_values(t_v2 pos, int i, t_env *env)
{
	env->skybox[i].draw = 1;
	env->skybox[i].clipped_xrange = env->skybox[i + 1].clipped_x
		- env->skybox[i].clipped_x;
	env->skybox[i].xrange = env->skybox[i + 1].x
		- env->skybox[i].x;
	env->skybox[i].floor_range = env->skybox[i + 1].f - env->skybox[i].f;
	env->skybox[i].ceiling_range = env->skybox[i + 1].c - env->skybox[i].c;
	env->skybox[i].xz = pos.x / env->skybox[i].vz;
	env->skybox[i].yz = pos.y / env->skybox[i].vz;
}

int		project_skybox(int i, t_env *env)
{
	env->skybox[i].scale = env->camera.scale / -env->skybox[i].vz;
	env->skybox[i].angle_z = env->skybox[i].clipped_vz
		* env->player.angle_z;
	env->skybox[i].f = env->h_h + (-5 +	env->skybox[i].angle_z)
		* env->skybox[i].scale;
	if (env->skybox[i].f < 0 || env->skybox[i].f >= env->h)
		return (1);
	env->skybox[i].c = env->h_h + (5 + env->skybox[i].angle_z)
		* env->skybox[i].scale;
	if (env->skybox[i].c < 0 || env->skybox[i].c >= env->h
			|| env->skybox[i].c >= env->skybox[i].f)
		return (1);
	env->skybox[i].clipped_x = env->h_w + env->skybox[i].clipped_vx
		* env->skybox[i].scale;
	if (env->skybox[i].x < 0 || env->skybox[i].x >= env->w)
		return (1);
	env->skybox[i].clipped_x = ceil(env->skybox[i].x);
	env->skybox[i].x = env->h_w + env->skybox[i].vx;
	return (0);
}

void	get_skybox_intersections(int i, t_env *env)
{
	t_v2	inter;

	inter = get_intersection(
			new_v2(env->skybox[i].vx, env->skybox[i].vz),
			new_v2(env->skybox[i + 1].vx, env->skybox[i + 1].vz),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.near_right, env->camera.near_z));
	if (env->skybox[i].vz < env->camera.near_z)
	{
		env->skybox[i].clipped_vx = inter.x;
		env->skybox[i].clipped_vz = inter.y;
	}
	else
	{
		env->skybox[i].clipped_vx = env->skybox[i].vx;
		env->skybox[i].clipped_vz = env->skybox[i].vz;
	}
}

void	clip_skybox2(int i, t_env *env)
{
	if ((env->skybox[i].vz < env->camera.near_z
				&& env->skybox[i + 1].vz < env->camera.near_z)
			|| (env->skybox[i].vz > env->camera.far_z
				&& env->skybox[i + 1].vz > env->camera.far_z)
			|| (env->skybox[i].vx < env->camera.far_left
				&& env->skybox[i + 1].vx < env->camera.far_left)
			|| (env->skybox[i].vx > env->camera.far_right
				&& env->skybox[i + 1].vx > env->camera.far_right))
	{
		env->skybox[i].draw = 0;
		return ;
	}
	env->skybox[i].draw = 1;
	get_skybox_intersections(i, env);
}

void	compute_skybox2(t_v2 pos, int i, t_env *env)
{
	env->skybox[i].vx = (pos.x - 5) * env->player.angle_sin
		- (pos.y - 5) * env->player.angle_cos;
	env->skybox[i].vz = (pos.x - 5) * env->player.angle_sin
		- (pos.y - 5) * env->player.angle_cos;
}

t_v2	set_v2(int i)
{
	t_v2	res;

	res = new_v2(0, 0);
	if (i == 1)
		res.x = 10;
	else if (i == 2)
		res = new_v2(10, 10);
	else if (i == 3)
		res.y = 10;
	return (res);
}

void	precompute_skybox(t_env *env)
{
	int	i;

	env->skybox_computed = 1;
	i = -1;
	while (++i < 4)
		compute_skybox2(set_v2(i), i, env);	
	i = -1;
	while (++i < 4)
		clip_skybox2(i ,env);
	i = -1;
	while (++i < 4)
		if (env->skybox[i].draw)
			if (project_skybox(i, env))
				env->skybox[i].draw = 0;
	i = -1;
	while (++i < 4)
	{
		env->skybox[i].draw = 0;
		if (env->skybox[i].clipped_x >= env->skybox[i + 1].clipped_x)
			precompute_skybox_values(set_v2(i), i, env);
	}
	env->skybox[4] = env->skybox[0];
}
