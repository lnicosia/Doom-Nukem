/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 18:17:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render.h"

/*void	draw_vline_ceiling_color(t_vline vline, t_render render, t_env *env)
{
	int		coord;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (env->editor.select && vline.x == env->h_w && vline.start == env->h_h)
		{
			env->selected_wall1 = -1;
			env->selected_wall2 = -1;
			env->selected_ceiling = render.sector;
			env->selected_floor = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		if (env->editor.in_game && !env->editor.select && env->selected_floor == render.sector)
			pixels[coord] = blend_alpha(0xFF3D3D61, 0x1ABC9C, 128);
		else
			pixels[coord] = 0xFF3D3D61;
		zbuffer[coord] = 100000000;
		vline.start++;
	}
}*/

void	draw_ceiling(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = env->ymin[vline.x];
	vline.end = ft_min(render.current_ceiling, env->ymax[vline.x]);
	if (sector.ceiling_texture < 0)
		draw_skybox(render, CEILING, env);
	else
	{
		if (!env->options.lighting || (!sector.brightness && !sector.intensity))
			draw_vline_ceiling(sector, vline, render, env);
		else if (!sector.brightness)
			draw_vline_ceiling_color(sector, vline, render, env);
		else if (!sector.intensity)
			draw_vline_ceiling_brightness(sector, vline, render, env);
		else
			draw_vline_ceiling_both(sector, vline, render, env);
	}
}
