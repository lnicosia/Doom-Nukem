/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:45:46 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/19 09:11:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling2(t_sector sector, t_render render, t_env *env)
{
	t_vline_data	vline_data;
	t_v2			texel;
	double			alpha;
	double			divider;
	double			z;
	t_texture		texture;
	Uint32			*pixels;
	Uint32			*texture_pixels;
	double			*zbuffer;
	int				x;
	int				xend;
	int				line;
	int				texture_w;
	int				texture_h;

	x = ft_max(render.ceiling_xstart, ft_max(render.xstart, sector.xmin[render.y])) - 1;
	xend = ft_min(render.ceiling_xend, ft_min(render.xend, sector.xmax[render.y]));
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	texture = env->textures[sector.ceiling_texture];
	texture_pixels = texture.str;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	line = render.y * env->w;
	while (++x <= xend)
	{
		vline_data = env->vline_data[x];
		alpha = (vline_data.max_ceiling - render.y) * vline_data.calpha_divider;
		divider = 1 / (render.camera->near_z + alpha * vline_data.zrange);
		z = vline_data.z_near_z * divider;
		if (z >= zbuffer[line + x])
			continue;
		zbuffer[line + x] = z;
		texel.y = (vline_data.texel_near_z.y + alpha
				* vline_data.texel_camera_range.y) * divider;
		texel.x = (vline_data.texel_near_z.x + alpha
				* vline_data.texel_camera_range.x) * divider;
		// Bon index != 0
		texel.y = texel.y * sector.ceiling_scale[0].y + sector.ceiling_align.y;
		texel.x = texel.x * sector.ceiling_scale[0].x + sector.ceiling_align.x;
		texel.x = texture_w - texel.x;
		texel.y = ft_abs((int)texel.y % texture_h);
		texel.x = ft_abs((int)texel.x % texture_w);
		pixels[line + x] = apply_light(texture_pixels[(int)texel.x
				+ texture_w * (int)texel.y], sector.light_color,
				sector.brightness);
		//pixels[line + x] = apply_light(0xFFAA2200, sector.light_color, sector.brightness);
	}
}
