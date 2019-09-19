/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 13:27:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	clear_image(t_env *env)
{
	int		y;
	int		x;
	int		y_env;
	int		xmax;
	int		ymax;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	y = 0;
	xmax = env->w;
	ymax = env->h;
	while (y < ymax)
	{
		x = 0;
		y_env = y * xmax;
		while (x < xmax)
		{
			//env->sdl.img_str[x + y * env->w] = 0xFF;
			pixels[x + y_env] = 0xFF000000;
			zbuffer[x + y_env] = 999999999;
			x++;
		}
		y++;
	}
}
