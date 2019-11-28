/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 18:44:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*void	draw_vline_floor_color(t_vline vline, t_render render, t_env *env)
{
	int		coord;
	Uint32	*pixels;

	(void)render;
	pixels = env->sdl.texture_pixels;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (env->editor.select && vline.x == env->h_w && vline.start == env->h_h)
		{
			env->selected_wall1 = -1;
			env->selected_wall2 = -1;
			env->selected_floor = render.sector;
			env->selected_ceiling = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		if (env->editor.in_game && !env->editor.select && env->selected_floor == render.sector)
			pixels[coord] = blend_alpha(0xFF3F3D61, 0x1ABC9C, 128);
		else
			pixels[coord] = 0xFF3D3D61;
		vline.start++;
	}
}*/

void	draw_floor(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = ft_max(0, (int)(render.current_floor));
	vline.end = env->ymax[vline.x];
	if (sector.floor_texture < 0)
		draw_skybox(render, FLOOR, env);
	else
	{
		if (!env->options.lighting || (!sector.brightness && !sector.intensity))
			draw_vline_floor(sector, vline, render, env);
		else if (!sector.brightness)
			draw_vline_floor_color(sector, vline, render, env);
		else if (!sector.intensity)
			draw_vline_floor_brightness(sector, vline, render, env);
		else
			draw_vline_floor_both(sector, vline, render, env);
	}
}
