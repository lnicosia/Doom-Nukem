/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:30:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/12/04 14:30:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "env.h"

void	draw_vertical_axes(t_env *env)
{
	int		x;
	int		y;
	int		max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	x = env->editor.center.x;
	if (x >= 400 && x < env->w)
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
}

void	draw_horizontal_axes(t_env *env)
{
	int		max;
	int		y;
	int		x;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	y = env->editor.center.y;
	if (y >= 0 && y < env->h)
	{
		x = ft_clamp(env->editor.center.x - 10, 399, env->w);
		max = ft_clamp(env->editor.center.x, 399, env->w - 1);
		while (x <= max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			x++;
		}
		x = ft_clamp(env->editor.center.x + 10, 399, env->w - 1);
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
	draw_vertical_axes(env);
	draw_horizontal_axes(env);
}
