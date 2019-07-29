/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 17:09:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_player(t_env *env)
{
	t_circle	circle;

	circle.color = 0xFFFF0000;
	circle.line_color = 0xFFFF0000;
	circle.radius = env->edit.scale / 3.5;
	if (env->edit.drag)
	{
		circle.center.x = env->sdl.mx;
		circle.center.y = env->sdl.my;
	}
	else
	{
		circle.center.x = env->edit.player.x;
		circle.center.y = env->edit.player.y;
	}
	draw_circle(circle, env);
}

void	add_player(t_env *env)
{
	ft_printf("added player\n");
	env->edit.player.x = env->sdl.mx;
	env->edit.player.y = env->sdl.my;
	env->edit.player.z = 0;
	env->edit.player.angle = 0;
}
