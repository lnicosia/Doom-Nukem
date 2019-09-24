/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/24 12:21:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	(void)sector;
	(void)render;
	(void)env;
	Uint32	*pixels;
	int		x;
	int		xend;
	int		line;
	Uint32	color;
	Uint8	value;

	x = render.xstart - 1;
	xend = render.xend;
	pixels = env->sdl.texture_pixels;
	line = render.y * env->w;
	while (++x <= xend)
	{
		/*if (render.y < env->ymin[x] || render.y > env->ymax[x])
			continue;*/
		value = ft_clamp(5 * 0xFF / env->z[x], 0, 0xFF);
		color = 0xFF << 24
			| value << 16
			| value << 8
			| value;
		if (!render.neighbor && render.y >= env->current_ceiling[x]
				&& render.y <= env->current_floor[x])
		{
			env->sdl.texture_pixels[line + x] = ft_clamp(color, 0xFF000000, 0xFFFFFFFF);
		}
		/*if (render.neighbor
				&& ((env->current_ceiling[x] < env->neighbor_current_ceiling[x])
					|| env->current_floor[x] > env->neighbor_current_floor[x]))
			env->sdl.texture_pixels[line + x] = ft_clamp(color, 0xFF000000, 0xFFFFFFFF);*/
		/*else// if (render.y < env->current_ceiling[x])
		{
			env->sdl.texture_pixels[line + x] = 0xFFAA4422;
		}
			//env->sdl.texture_pixels[line + x] = 0xFFAAAAAA;*/
	}
}
