/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 18:36:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_player(t_env *env)
{
	t_circle	circle;
	double		scale;

	circle.color = 0xFFFF0000;
	circle.line_color = 0xFFFF0000;
	circle.radius = env->editor.scale;
	scale = env->editor.scale / 2;
	if (env->editor.drag)
	{
		circle.center.x = env->sdl.mx;
		circle.center.y = env->sdl.my;
	}
	else
	{
		circle.center.x = env->editor.player.x;
		circle.center.y = env->editor.player.y;
	}
	if (circle.center.x - scale >= 0 && circle.center.x + scale < env->w
			&& circle.center.y - scale >= 0 && circle.center.y + scale < env->h)
		draw_circle(circle, env);
}

void	add_player(t_env *env)
{
	env->editor.player.x = env->sdl.mx;
	env->editor.player.y = env->sdl.my;
	env->editor.player.z = 0;
	env->editor.player.angle = 0;
}
