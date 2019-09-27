/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:21:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 18:23:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_floor2(t_sector sector, t_render render, t_env *env)
{
	t_vline_data	vline_data;
	t_texture		texture;
	t_v2			texel;
	Uint32			*pixels;
	Uint32			*texture_pixels;
	double			*zbuffer;
	double			alpha;
	double			divider;
	double			z;
	int				x;
	int				xend;
	int				line;
	int				texture_w;
	int				texture_h;

	x = ft_max(render.floor_xstart, ft_max(render.xstart, sector.xmin[render.y])) - 1;
	xend = ft_min(render.floor_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	texture = env->textures[sector.floor_texture];
	texture_pixels = texture.str;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	line = render.y * env->w;
	while (++x <= xend)
	{
		vline_data = env->vline_data[x];
		alpha = (render.y - vline_data.max_floor) / (render.camera->feet_y[render.sector] - vline_data.max_floor);
		divider = 1 / (render.camera->near_z + alpha * vline_data.zrange);
		z = vline_data.z_near_z * divider;
		if (z >= zbuffer[line + x])
			continue;
		zbuffer[line + x] = z;
		texel.y = (vline_data.texel_near_z.y + alpha
				* vline_data.texel_camera_range.y) * divider;
		texel.x = (vline_data.texel_near_z.x + alpha
				* vline_data.texel_camera_range.x) * divider;
		texel.y = texel.y * sector.floor_scale.y + sector.floor_align.y;
		texel.x = texel.x * sector.floor_scale.x + sector.floor_align.x;
		texel.y = texture_h - texel.y;
		texel.x = texture_w - texel.x;
		if (texel.y >= texture_h || texel.y < 0)
			texel.y = ft_abs((int)texel.y % texture_h);
		if (texel.x >= texture_w || texel.x < 0)
			texel.x = ft_abs((int)texel.x % texture_w);
		//pixels[line + x] = apply_light(0xFFAA4422, sector.light_color, sector.brightness);
		pixels[line + x] = apply_light(texture_pixels[(int)texel.x
				+ texture_w * (int)texel.y], sector.light_color,
				sector.brightness);
	}
}
