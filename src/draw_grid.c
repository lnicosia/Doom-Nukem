/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:17:20 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 14:14:22 by sipatry          ###   ########.fr       */
/*   Created: 2019/07/23 14:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/26 10:03:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_center(t_env *env)
{
	int		x;
	int		y;
	int		max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	x = env->editor.center.x;
	if (x >= 200 && x < env->w)
	{
		y = ft_clamp(env->editor.center.y - 10, 0, env->h - 1);
		max = ft_clamp(env->editor.center.y, 0, env->h - 1);
		while (y <= max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			y++;
		}
		y = ft_clamp(env->editor.center.y + 10, 0, env->h - 1);
		while (y > max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			y--;
		}
	}
	y = env->editor.center.y;
	if (y >= 0 && y < env->h)
	{
		x = ft_clamp(env->editor.center.x - 10, 199, env->w);
		max = ft_clamp(env->editor.center.x, 199, env->w - 1);
		while (x <= max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			x++;
		}
		x = ft_clamp(env->editor.center.x + 10, 199, env->w - 1);
		while (x > max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			x--;
		}
	}
}

void	draw_grid(t_env *env)
{
	draw_hgrid(env);
	draw_vgrid(env);
	draw_center(env);
}
