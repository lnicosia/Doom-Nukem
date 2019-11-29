/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:37:03 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/28 18:46:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_vline_color(t_vline vline, t_env *env)
{
	int		coord;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		pixels[coord] = vline.color;
		vline.start++;
	}
}

void		draw_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.current_ceiling);
	vline.end = (int)(render.current_floor);
	vline.color = 0xFFFF0000;
	if (sector.neighbors[render.i] == -1 && sector.textures[render.i] != -1)
		vline.draw_wall = 1;
	else
		vline.draw_wall = 0;
	if (!env->options.lighting || (!sector.brightness && !sector.intensity))
		draw_vline_wall(sector, vline, render, env);
	else if (!sector.brightness)
		draw_vline_wall_color(sector, vline, render, env);
	else if (!sector.intensity)
		draw_vline_wall_brightness(sector, vline, render, env);
	else
		draw_vline_wall_both(sector, vline, render, env);
}

void		draw_upper_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.current_ceiling);
	vline.end = (int)(render.neighbor_current_ceiling);
	vline.draw_wall = 1;
	vline.color = 0xFFFF0000;
	if (!env->options.lighting || (!sector.brightness && !sector.intensity))
		draw_vline_wall(sector, vline, render, env);
	else if (!sector.brightness)
		draw_vline_wall_color(sector, vline, render, env);
	else if (!sector.intensity)
		draw_vline_wall_brightness(sector, vline, render, env);
	else
		draw_vline_wall_both(sector, vline, render, env);
}

void		draw_bottom_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.neighbor_current_floor);
	vline.end = (int)(render.current_floor);
	vline.draw_wall = 1;
	vline.color = 0xFFFF0000;
	if (!env->options.lighting || (!sector.brightness && !sector.intensity))
		draw_vline_wall(sector, vline, render, env);
	else if (!sector.brightness)
		draw_vline_wall_color(sector, vline, render, env);
	else if (!sector.intensity)
		draw_vline_wall_brightness(sector, vline, render, env);
	else
		draw_vline_wall_both(sector, vline, render, env);
}
