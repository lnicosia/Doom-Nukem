/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/24 18:07:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	put_wall(int coord, t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	double		*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	pixels[coord] = apply_light(0xFFAAAAAA, sector.light_color, sector.brightness);
			//pixels[line + x] = 0xFFAAAAAA;
	zbuffer[coord] = env->z[render.x];
}

void	put_floor(int coord, t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	double		*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	pixels[coord] = apply_light(0xFFAA4422, sector.light_color, sector.brightness);
	//pixels[line + x] = 0xFFAA4422;
	zbuffer[coord] = env->z[render.x];
}

void	put_ceiling(int coord, t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	double		*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	pixels[coord] = apply_light(0xFF882200, sector.light_color, sector.brightness);
	//pixels[line + x] = 0xFFAA4422;
	zbuffer[coord] = env->z[render.x];
}

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	Uint32		*texture_pixels;
	t_texture	texture;
	Uint32		*pixels;
	double		*zbuffer;
	int			texture_w;
	int			texture_h;
	int			x;
	int			xend;
	int			line;
	int			set_min;
	int			set_max;

	(void)sector;
	set_min = 0;
	set_max = 0;
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
		render.x = x;
		if ((!render.neighbor && render.y >= env->current_ceiling[x]
				&& render.y <= env->current_floor[x])
			|| (render.neighbor
				&& ((render.y < env->neighbor_current_ceiling[x]
					&& render.y > env->current_ceiling[x])
					|| (render.y > env->neighbor_current_floor[x]
						&& render.y < env->current_floor[x]))))
			put_wall(line + x, sector, render, env);
		if (render.y > env->current_floor[x])
			put_floor(line + x, sector, render, env);
		if (render.y < env->current_ceiling[x])
			put_ceiling(line + x, sector, render, env);
	}
	//update_screen(env);
}
