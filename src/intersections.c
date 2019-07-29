/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:13:11 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 15:01:29 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		handle_left(t_render *render, t_env *env)
{
	if (render->inter_left.x >= env->camera.far_left
			&& render->inter_left.x <= env->camera.near_left
			&& render->inter_left.y <= env->camera.far_z
			&& render->inter_left.y >= env->camera.near_z)
	{
		if (render->vx1 < render->inter_left.x && render->vx2 > render->inter_left.x)
		{
			render->vx1 = render->inter_left.x;
			render->vz1 = render->inter_left.y;
			render->v1_clipped = 1;
		}
		if (render->vx2 < render->inter_left.x && render->vx1 > render->inter_left.x)
		{
			render->vx1 = render->inter_left.x;
			render->vz1 = render->inter_left.y;
			render->v1_clipped = 1;
		}
	}
}


void		handle_right(t_render *render, t_env *env)
{
	(void)render;
	(void)env;
}


void		handle_near(t_render *render, t_env *env)
{
	(void)render;
	(void)env;
	if (render->vz1 < env->camera.near_z)
	{
		
	}
}

void		handle_far(t_render *render, t_env *env)
{
	(void)render;
	(void)env;
}
