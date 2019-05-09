/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:15:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/08 17:00:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_camera(t_env *env)
{
	env->camera.vfov = (180.0 / M_PI) * atan(tan(((M_PI / 180.0) * env->camera.hfov / 2)) / ((double)env->w / (double)env->h)) * 2;
	//env->camera.hfov = (180.0 / M_PI) * atan(tan(((M_PI / 180.0) * env->cameravfov / 2)) * ((double)env->w / (double)env->h)) * 2;
	//	ft_printf("hfov = %f, vfov = %f\n", env->camera.hfov, env->camera.vfov);
	env->camera.near_left = -tan(env->camera.hfov / 2);
	env->camera.near_right = tan(env->camera.hfov / 2);
	env->camera.far_left = -tan(env->camera.hfov / 2) * env->camera.far_z;
	env->camera.far_right = tan(env->camera.hfov / 2) * env->camera.far_z;
	ft_printf("near_left = %f near_right = %f\nfar_left = %f far_right = %f\n",
			env->camera.near_left,
			env->camera.near_right,
			env->camera.far_left,
			env->camera.far_right);
}

void	init_camera(t_env *env)
{
	env->camera.hfov = 90;
	env->camera.near_z = 1;
	env->camera.far_z = 1000;
	set_camera(env);
}
