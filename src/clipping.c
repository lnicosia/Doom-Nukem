/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:33:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/13 16:37:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

static void	get_intersections(t_render *render, t_env *env)
{
	render->inter_left = get_intersection(
			new_v2(render->vx1, render->vz1),
			new_v2(render->vx2, render->vz2),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.far_left, env->camera.far_z));
	render->inter_right = get_intersection(
			new_v2(render->vx1, render->vz1),
			new_v2(render->vx2, render->vz2),
			new_v2(env->camera.near_right, env->camera.near_z),
			new_v2(env->camera.far_right, env->camera.far_z));
	render->inter_near = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(env->camera.near_left, env->camera.near_z),
				new_v2(env->camera.near_right, env->camera.near_z));
	render->inter_far = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(env->camera.far_left, env->camera.far_z),
				new_v2(env->camera.far_right, env->camera.far_z));
}

int			check_fov(t_render *render, t_env *env)
{
	if (render->vz1 < env->camera.near_z && render->vz2 < env->camera.near_z
			&& render->vx1 > env->camera.far_left && render->vx2 > env->camera.far_right)
		return (0);
	get_intersections(render, env);
	if ((render->inter_left.x >= env->camera.far_left
			&& render->inter_left.x <= env->camera.near_left
			&& render->inter_left.y >= env->camera.near_z
			&& render->inter_left.y <= env->camera.far_z)
			|| (render->inter_right.x >= env->camera.near_right
			&& render->inter_right.x <= env->camera.far_right
			&& render->inter_right.y >= env->camera.near_z
			&& render->inter_right.y <= env->camera.far_z)
			|| (render->inter_far.x >= env->camera.far_left
			&& render->inter_far.x <= env->camera.far_right)
			|| (render->inter_near.x >= env->camera.near_left
			&& render->inter_near.x <= env->camera.near_right))
		return (1);
	return (0);
}

void		clip_walls(t_render *render, t_env *env)
{

	render->clipped = 0;
	if (render->vz1 <= env->camera.near_z || render->vz2 <= env->camera.near_z)
	{
		render->clipped = 1;
		//ft_printf("new wall: x = %f z = %f\n", vz2.x, vz2.y);
	}
	if (render->vz1 <= env->camera.near_z)
	{
		render->vx1 = render->inter_near.x;
		render->vz1 = render->inter_near.y;
	}
	if (render->vz2 <= env->camera.near_z)
	{
		render->vx2 = render->inter_near.x;
		render->vz2 = render->inter_near.y;
	}
	/*if (render->vz1 <= env->camera.near_z || render->vz2 <= env->camera.near_z)
	{
		render->clipped = 1;
		//Trouver une intersection entre le mur et le champ de vision du joueur
			vz1 = get_intersection(
					new_v2(render->vx1, render->vz1),
					new_v2(render->vx2, render->vz2),
					new_v2(env->camera.near_left, env->camera.near_z),
					new_v2(env->camera.far_left, env->camera.far_z));
			vz2 = get_intersection(
				new_v2(render->vx1, render->vz1
				new_v2(render->vx2, render->vz2),
				new_v2(env->camera.near_right, env->camera.near_z),
				new_v2(env->camera.far_right, env->camera.far_z));
		if (render->vz1 < env->camera.near_z)
		{
			if(vz1.y > env->camera.near_z)
			{
				render->vx1 = vz1.x;
				render->vz1 = vz1.y;
			}
			else
			{
				render->vx1 = vz2.x;
				render->vz1 = vz2.y;
			}
		}
		if (render->vz2 < env->camera.near_z)
		{
			if(vz1.y > env->camera.near_z)
			{
				render->vx2 = vz1.x;
				render->vz2 = vz1.y;
			}
			else
			{
				render->vx2 = vz2.x;
				render->vz2 = vz2.y;
			}
		}
	}
	else
		render->clipped = 0;*/
}
