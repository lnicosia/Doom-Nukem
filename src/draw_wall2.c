/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 16:34:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	double		*zbuffer;
	int			x;
	int			xend;
	int			line;
	int			*ymin;
	int			*ymax;

	(void)sector;
	x = ft_max(render.wall_xstart, ft_max(render.xstart, sector.xmin[render.y])) - 1;
	xend = ft_min(render.wall_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	line = render.y * env->w;
	ymin = env->ymin;
	ymax = env->ymax;
	while (++x <= xend)
	{
		if (env->z[x] >= zbuffer[line + x])
			continue;
		//if (render.y >= ymin[x] && render.y <= ymax[x])
			pixels[line + x] = apply_light(0xFFAAAAAA, sector.light_color, sector.brightness);
			zbuffer[line + x] = env->z[x];
	}
}
