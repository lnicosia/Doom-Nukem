/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:21:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/25 11:43:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fill_hline(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.x <= p2.x)
	{
		env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.x++;
	}
}

void	fill_vline(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.y <= p2.y)
	{
		env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.y++;
	}
}

void	draw_circle(Uint32 line_color, Uint32 color, t_point center, int radius, t_env *env)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	y = radius;
	p = 3 - 2 * radius;
	while (x <= y)
	{
		fill_hline(color,
				new_point(center.x - x, center.y + y),
				new_point(center.x + x, center.y + y),
				env);
		fill_hline(color,
				new_point(center.x - x, center.y - y),
				new_point(center.x + x, center.y - y),
				env);
		fill_hline(color,
				new_point(center.x - y, center.y - x),
				new_point(center.x + y, center.y - x),
				env);
		fill_hline(color,
				new_point(center.x - y, center.y + x),
				new_point(center.x + y, center.y + x),
				env);
		env->sdl.texture_pixels[center.x + x + env->w * (center.y + y)] = line_color;
		env->sdl.texture_pixels[center.x - x + env->w * (center.y + y)] = line_color;
		env->sdl.texture_pixels[center.x + x + env->w * (center.y - y)] = line_color;
		env->sdl.texture_pixels[center.x - x + env->w * (center.y - y)] = line_color;
		env->sdl.texture_pixels[center.x + y + env->w * (center.y + x)] = line_color;
		env->sdl.texture_pixels[center.x - y + env->w * (center.y + x)] = line_color;
		env->sdl.texture_pixels[center.x + y + env->w * (center.y - x)] = line_color;
		env->sdl.texture_pixels[center.x - y + env->w * (center.y - x)] = line_color;
		if (p < 0)
			p += 4 * x++ + 6;
		else
			p += 4 * (x++ - y--) + 10;
	}
}
