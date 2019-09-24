/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/24 17:16:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	Uint32		*texture_pixels;
	t_texture	texture;
	double		*zbuffer;
	int			texture_w;
	int			texture_h;
	int			x;
	int			xend;
	int			line;

	x = render.xstart - 1;
	//x = ft_max(render.xstart, env->xmin[render.y]);
	xend = render.xend;
	//xend = ft_min(render.xend, env->xmax[render.y]);
	pixels = env->sdl.texture_pixels;
	texture = env->textures[render.texture];
	texture_pixels = texture.str;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	zbuffer = env->zbuffer;
	line = render.y * env->w;
	while (++x <= xend)
	{
		if (render.y < env->ymin[x] || render.y > env->ymax[x]
				|| env->z[x] >= zbuffer[line + x])
			continue;
		if ((!render.neighbor && render.y >= env->current_ceiling[x]
				&& render.y <= env->current_floor[x])
			|| (render.neighbor
				&& ((render.y < env->neighbor_current_ceiling[x]
					&& render.y > env->current_ceiling[x])
					|| (render.y > env->neighbor_current_floor[x]
						&& render.y < env->current_floor[x]))))
		{
			pixels[line + x] = apply_light(0xFFAAAAAA, sector.light_color, sector.brightness);
			zbuffer[line + x] = env->z[x];
		}
		if (render.y < env->current_ceiling[x]
				|| render.y > env->current_floor[x])
		{
			pixels[line + x] = apply_light(0xFFAA4422, sector.light_color, sector.brightness);
			zbuffer[line + x] = env->z[x];
		}
	}
	//update_screen(env);
}
