/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 08:48:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/25 15:58:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_wall2(t_sector sector, t_render render, t_env *env)
{
	Uint32		*pixels;
	int			x;
	int			xend;
	int			line;

	(void)sector;
	x = render.wall_xstart - 1;
	xend = render.wall_xend;
	pixels = env->sdl.texture_pixels;
	line = render.y * env->w;
	while (++x <= xend)
		pixels[line + x] = apply_light(0xFFAAAAAA, sector.light_color, sector.brightness);
}
