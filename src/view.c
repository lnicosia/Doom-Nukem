/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:15:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/10 14:57:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 **	Handle player view rotations from mouse
 **	TODO Protection / return value??
 */

void	view(t_env *env)
{
	env->player.angle += env->sdl.mouse_x * 0.03;
	env->player.angle_cos = cos(env->player.angle);
	env->player.angle_sin = sin(env->player.angle);
	update_camera_position(env);
	env->player.camera_sector = get_camera_sector(env);
	env->player.angle_z = ft_fclamp(env->player.angle_z + env->sdl.mouse_y * 0.05, -5, 5);
	//ft_printf("player angle = %f\n", env.player.angle);
}
