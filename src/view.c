/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:15:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/12 15:19:04 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
 **	Handle player view rotations from mouse
 **	TODO Protection / return value??
 */

void	view(t_env *env)
{
	env->player.angle += env->sdl.mouse_x * 0.01;
	env->player.dir.x = cos(env->player.angle);
	env->player.dir.y = sin(env->player.angle);
	env->player.dir.z = ft_fclamp(env->player.dir.z + env->sdl.mouse_y * 0.05, -5, 5);
	//ft_printf("player angle = %f\n", env.player.angle);
}
