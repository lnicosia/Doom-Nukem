/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:21:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 16:49:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling2(t_sector sector, t_render render, t_env *env)
{
	Uint32	*pixels;
	double	*zbuffer;
	double	alpha;
	double	divider;
	double	z;
	int		x;
	int		xend;
	int		line;
	int		*ymin;
	int		*ymax;

	(void)sector;
	x = ft_max(render.ceiling_xstart, ft_max(render.xstart, sector.xmin[render.y])) - 1;
	xend = ft_min(render.ceiling_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	line = render.y * env->w;
	ymin = env->ymin;
	ymax = env->ymax;
	while (++x <= xend)
	{
		alpha = (env->max_ceiling[x] - render.y) / (env->max_ceiling[x] - render.camera->head_y[render.sector]);
		divider = 1 / (render.camera->near_z + alpha * env->zrange[x]);
		z = env->z_near_z[x] * divider;
		if (z >= zbuffer[line + x])
			continue;
		//if (render.y >= ymin[x] && render.y <= ymax[x])
			pixels[line + x] = apply_light(0xFF882200, sector.light_color, sector.brightness);
			zbuffer[line + x] = z;
	}
}
