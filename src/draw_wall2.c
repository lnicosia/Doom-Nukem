/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 18:08:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	t_vline_data	vline_data;
	t_texture		texture;
	Uint32			*pixels;
	Uint32			*texture_pixels;
	double			*zbuffer;
	double			z;
	double			yalpha;
	double			texel_y;
	int				x;
	int				xend;
	int				line;
	int				texture_w;
	int				texture_h;

	x = ft_max(render.wall_xstart, ft_max(render.xstart,
				sector.xmin[render.y])) - 1;
	xend = ft_min(render.wall_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	texture = env->textures[render.texture];
	texture_pixels = texture.str;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	line = render.y * env->w;
	while (++x <= xend)
	{
		vline_data = env->vline_data[x];
		z = vline_data.z;
		if (z >= zbuffer[line + x])
			continue;
		zbuffer[line + x] = z;
		yalpha = (render.y - vline_data.no_slope_current_ceiling) / vline_data.line_height;
		texel_y = yalpha * render.texture_scale.y + sector.align[render.i].y;
		while (texel_y >= texture_h)
			texel_y -= texture_h;
		while (texel_y < 0)
			texel_y += texture_h;
		pixels[line + x] = apply_light(texture_pixels[(int)vline_data.wall_texel
				+ texture_w * (int)texel_y], sector.light_color,
				sector.brightness);
	}
}
