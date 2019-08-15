/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:15:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/15 16:14:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
 **	Handle player view rotations from mouse
 **	TODO Protection / return value??
 */

void	view(t_env *env)
{
	double	angle;
	double	angle_cos;
	double	angle_sin;

	angle = env->player.angle;
	angle_cos = env->player.angle_cos;
	angle_sin = env->player.angle_sin;
	env->player.angle += env->sdl.mouse_x * env->player.rotation_speed;
	env->player.angle_cos = cos(env->player.angle);
	env->player.angle_sin = sin(env->player.angle);
	env->player.perp_cos = cos(env->player.angle - M_PI / 2);
	env->player.perp_sin = sin(env->player.angle - M_PI / 2);
	update_camera_position(env);
	env->player.angle_z = ft_fclamp(env->player.angle_z + env->sdl.mouse_y * 0.005, -5, 5);
	env->player.angle_z_cos = cos(env->player.angle_z);
	env->player.angle_z_sin = sin(env->player.angle_z);
}
