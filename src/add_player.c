/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 10:44:22 by lnicosia         ###   ########.fr       */
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
		circle.center.x = (env->player.pos.x * env->editor.scale) + env->editor.center.x;
		circle.center.y = (env->player.pos.y * env->editor.scale) + env->editor.center.y;
	}
	if (circle.center.x - scale >= 0 && circle.center.x + scale < env->w
			&& circle.center.y - scale >= 0 && circle.center.y + scale < env->h)
		draw_circle(circle, env);
}

void	add_player(t_env *env)
{
	env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	env->player.pos.z = 0;
	env->player.angle = 0;
	env->player.sector = get_sector_global(env,
			new_v3(env->player.pos.x, env->player.pos.y, env->player.pos.z));
}
