/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:21:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/20 16:06:45 by lnicosia         ###   ########.fr       */
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
				new_point(ft_clamp(circle.center.x - x, 0, env->w - 1), ft_clamp(circle.center.y + y, 0, env->h - 1)),
				new_point(ft_clamp(circle.center.x + x, 0, env->w - 1), ft_clamp(circle.center.y + y, 0, env->h - 1)),
				env);
		fill_hline(circle.color,
				new_point(ft_clamp(circle.center.x - x, 0, env->w - 1), ft_clamp(circle.center.y - y, 0, env->h - 1)),
				new_point(ft_clamp(circle.center.x + x, 0, env->w - 1), ft_clamp(circle.center.y - y, 0, env->h - 1)),
				env);
		fill_hline(circle.color,
				new_point(ft_clamp(circle.center.x - y, 0, env->w - 1), ft_clamp(circle.center.y - x, 0, env->h - 1)),
				new_point(ft_clamp(circle.center.x + y, 0, env->w - 1), ft_clamp(circle.center.y - x, 0, env->h - 1)),
				env);
		fill_hline(circle.color,
				new_point(ft_clamp(circle.center.x - y, 0, env->w - 1), ft_clamp(circle.center.y + x, 0, env->h - 1)),
				new_point(ft_clamp(circle.center.x + y, 0, env->w - 1), ft_clamp(circle.center.y + x, 0, env->h - 1)),
				env);
		env->sdl.texture_pixels[ft_clamp(circle.center.x + x, 0, env->w - 1) + env->w * ft_clamp(circle.center.y + y, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x - x, 0, env->w - 1) + env->w * ft_clamp(circle.center.y + y, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x + x, 0, env->w - 1) + env->w * ft_clamp(circle.center.y - y, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x - x, 0, env->w - 1) + env->w * ft_clamp(circle.center.y - y, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x + y, 0, env->w - 1) + env->w * ft_clamp(circle.center.y + x, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x - y, 0, env->w - 1) + env->w * ft_clamp(circle.center.y + x, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x + y, 0, env->w - 1) + env->w * ft_clamp(circle.center.y - x, 0, env->h - 1)] = circle.line_color;
		env->sdl.texture_pixels[ft_clamp(circle.center.x - y, 0, env->w - 1) + env->w * ft_clamp(circle.center.y - x, 0, env->h - 1)] = circle.line_color;
		if (p < 0)
			p += 4 * x++ + 6;
		else
			p += 4 * (x++ - y--) + 10;
	}
}
