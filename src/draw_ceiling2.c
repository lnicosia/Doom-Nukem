/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 10:21:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/25 15:58:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling2(t_sector sector, t_render render, t_env *env)
{
	Uint32	*pixels;
	int		x;
	int		xend;
	int		line;

	(void)sector;
	x = render.ceiling_xstart - 1;
	xend = render.ceiling_xend;
	pixels = env->sdl.texture_pixels;
	line = render.y * env->w;
	while (++x <= xend)
		pixels[line + x] = apply_light(0xFF882200, sector.light_color, sector.brightness);
}
