/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:21:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 16:03:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_circle	new_circle(Uint32 line_color, Uint32 color, t_point center, int radius)
{
	t_circle	new;

	new.line_color = line_color;
	new.color = color;
	new.center = center;
	new.radius = radius;
	return (new);
}

void		fill_hline(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.x <= p2.x)
	{
		env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.x++;
	}
}

void		fill_vline(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.y <= p2.y)
	{
		env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.y++;
	}
}

void		draw_circle(t_circle circle, t_env *env)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	y = circle.radius;
	p = 3 - 2 * circle.radius;
	while (x <= y)
	{
		fill_hline(circle.color,
				new_point(circle.center.x - x, circle.center.y + y),
				new_point(circle.center.x + x, circle.center.y + y),
				env);
		fill_hline(circle.color,
				new_point(circle.center.x - x, circle.center.y - y),
				new_point(circle.center.x + x, circle.center.y - y),
				env);
		fill_hline(circle.color,
				new_point(circle.center.x - y, circle.center.y - x),
				new_point(circle.center.x + y, circle.center.y - x),
				env);
		fill_hline(circle.color,
				new_point(circle.center.x - y, circle.center.y + x),
				new_point(circle.center.x + y, circle.center.y + x),
				env);
		env->sdl.texture_pixels[circle.center.x + x + env->w * (circle.center.y + y)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x - x + env->w * (circle.center.y + y)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x + x + env->w * (circle.center.y - y)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x - x + env->w * (circle.center.y - y)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x + y + env->w * (circle.center.y + x)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x - y + env->w * (circle.center.y + x)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x + y + env->w * (circle.center.y - x)] = circle.line_color;
		env->sdl.texture_pixels[circle.center.x - y + env->w * (circle.center.y - x)] = circle.line_color;
		if (p < 0)
			p += 4 * x++ + 6;
		else
			p += 4 * (x++ - y--) + 10;
	}
}
