/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:15:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/12 11:43:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 **	Handle player view rotations from mouse
 **	TODO Protection / return value??
 */

void	view(t_env *env)
{
	double	angle;
	double	angle_cos;
	double	angle_sin;
	short	origin_left_sect;
	short	origin_right_sect;
	short	origin_camera_sect;

	angle = env->player.angle;
	angle_cos = env->player.angle_cos;
	angle_sin = env->player.angle_sin;
	origin_camera_sect = env->player.camera_sector;
	origin_right_sect = env->player.near_left_sector;
	origin_left_sect = env->player.near_right_sector;
	env->player.angle += env->sdl.mouse_x * 0.03;
	env->player.angle_cos = cos(env->player.angle);
	env->player.angle_sin = sin(env->player.angle);
	env->player.perp_cos = cos(env->player.angle - M_PI / 2);
	env->player.perp_sin = sin(env->player.angle - M_PI / 2);
	update_camera_position(env);
	/*env->player.camera_sector = get_sector(env, new_v2(env->player.camera_x, env->player.camera_y));
	env->player.near_left_sector = get_sector(env, new_v2(env->player.near_left.x, env->player.near_left.y));
	env->player.near_right_sector = get_sector(env, new_v2(env->player.near_right.x, env->player.near_right.y));
	if (env->player.near_left_sector == -1 || env->player.near_right_sector == -1)
	{
		env->player.angle = angle;
		env->player.angle_cos = angle_cos;
		env->player.angle_sin = angle_sin;
		env->player.camera_sector = origin_camera_sect;
		env->player.near_left_sector = origin_left_sect;
		env->player.near_right_sector = origin_right_sect;
	}*/
	env->player.angle_z = ft_fclamp(env->player.angle_z + env->sdl.mouse_y * 0.05, -5, 5);
	env->player.angle_z_cos = cos(env->player.angle_z);
	env->player.angle_z_sin = sin(env->player.angle_z);
	//ft_printf("player angle = %f\n", env.player.angle);
}
