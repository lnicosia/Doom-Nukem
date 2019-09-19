/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:15:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:36:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Handle player view rotations from mouse
**	TODO Protection / return value??
*/

void	view(t_env *env)
{
	env->player.camera.angle += env->sdl.mouse_x * env->player.rotation_speed;
	env->player.camera.angle_cos = cos(env->player.camera.angle);
	env->player.camera.angle_sin = sin(env->player.camera.angle);
	env->player.camera.perp_cos = cos(env->player.camera.angle - M_PI / 2);
	env->player.camera.perp_sin = sin(env->player.camera.angle - M_PI / 2);
	update_camera_position(&env->player.camera);
	env->player.camera.angle_z = ft_fclamp(env->player.camera.angle_z + env->sdl.mouse_y * 0.005, -5, 5);
	env->player.camera.angle_z_cos = cos(env->player.camera.angle_z);
	env->player.camera.angle_z_sin = sin(env->player.camera.angle_z);
	env->player.camera.horizon = env->h_h - env->player.camera.angle_z * env->player.camera.scale;
}
