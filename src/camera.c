/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera->c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:15:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:42:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
 **	Update camera position (save some computings)
 */

void	update_camera_position(t_camera *camera)
{
	camera->near_pos.x = camera->pos.x + camera->angle_cos * camera->near_z;
	camera->near_pos.y = camera->pos.y + camera->angle_sin * camera->near_z;
	camera->near_left_pos.x = camera->pos.x + (camera->angle_cos * camera->near_z - camera->angle_sin * camera->near_left);
	camera->near_left_pos.y = camera->pos.y + (camera->angle_sin * camera->near_z + camera->angle_cos * camera->near_left);
	camera->near_right_pos.x = camera->pos.x + (camera->angle_cos * camera->near_z - camera->angle_sin * camera->near_right);
	camera->near_right_pos.y = camera->pos.y + (camera->angle_sin * camera->near_z + camera->angle_cos * camera->near_right);
}

void	set_camera(t_camera *camera, t_env *env)
{
	camera->vfov = (180.0 / M_PI) * atan(tan((CONVERT_RADIANS * camera->hfov / 2)) / camera->ratio) * 2;
	//camera->hfov = (180.0 / M_PI) * atan(tan(((M_PI / 180.0) * camera->fov / 2)) * camera->ratio) * 2;
	//ft_printf("hfov = %f, vfov = %f\n", camera->hfov, camera->vfov);
	camera->near_left = -tan(CONVERT_RADIANS * camera->hfov / 2) * camera->near_z;
	camera->near_right = tan(CONVERT_RADIANS * camera->hfov / 2) * camera->near_z;
	camera->range = camera->near_right - camera->near_left;
	camera->near_up = -tan(CONVERT_RADIANS * camera->vfov / 2) * camera->near_z;
	camera->near_down = tan(CONVERT_RADIANS * camera->vfov / 2) * camera->near_z;
	camera->far_left = -tan(CONVERT_RADIANS * camera->hfov / 2) * camera->far_z;
	camera->far_right = tan(CONVERT_RADIANS * camera->hfov / 2) * camera->far_z;
	//ft_printf("near left = %f near right = %f\n", camera->near_left, camera->near_right);
	camera->x1 = (camera->near_left / camera->near_z);
	camera->x2 = (camera->near_right / camera->near_z);
	camera->y1 = (camera->near_up / camera->near_z);
	camera->y2 = (camera->near_down / camera->near_z);
	//ft_printf("x1 = %f x2 = %f\n", camera->x1, camera->x2);
	camera->hscale = env->h_w / camera->x2;
	camera->vscale = env->h_h / camera->y2;
	camera->scale = camera->vscale;
	/*ft_printf("near_z = %f\nnear_left = %f near_right = %f\nfar_left = %f far_right = %f\n",
			camera->near_z,
			camera->near_left,
			camera->near_right,
			camera->far_left,
			camera->far_right);
	ft_printf("camera->x1 = %f camera->x2 = %f\n", camera->x1, camera->x2);
	ft_printf("near_up = %f near_down = %f\n", camera->near_up, camera->near_down);
	ft_printf("camera->y1 = %f camera->y2 = %f\n", camera->y1, camera->y2);
	ft_printf("hscale = %f\n", camera->hscale);
	ft_printf("vscale = %f\n", camera->vscale);
	ft_printf("final scale = %f\n", camera->scale);*/
}

void	init_camera(t_camera *camera, t_env *env)
{
	camera->hfov = 90;
	camera->near_z = 0.1;
	camera->far_z = 1000;
	camera->ratio_w = 16;
	camera->ratio_h = 9;
	camera->ratio = camera->ratio_w / camera->ratio_h;
	set_camera(camera, env);
}
