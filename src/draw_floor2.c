/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:21:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 11:36:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_floor2(t_sector sector, t_render render, t_env *env)
{
	Uint32	*pixels;
	int		x;
	int		xend;
	int		line;
	int		*ymin;
	int		*ymax;

	(void)sector;
	x = ft_max(render.floor_xstart, ft_max(render.xstart, sector.xmin[render.y])) - 1;
	xend = ft_min(render.floor_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	line = render.y * env->w;
	ymin = env->ymin;
	ymax = env->ymax;
	while (++x <= xend)
	{
		//if (render.y >= ymin[x] && render.y <= ymax[x])
			pixels[line + x] = apply_light(0xFFAA4422, sector.light_color, sector.brightness);
	}
}
