/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:42:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:42:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fill_img(t_point c, t_env *data, Uint32 color)
{
	if (c.x >= 400 && c.x < data->w && c.y >= 0 && c.y < data->h
			&& data->sdl.texture_pixels[c.x + c.y * data->w] != 0xFF00FF00
			&& data->sdl.texture_pixels[c.x + c.y * data->w] != 0xFFFFFF00)
		data->sdl.texture_pixels[c.x + c.y * data->w] = color;
}

void	draw_line_low(t_point c1, t_point c2, t_env *data, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	e;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	yi = dy < 0 ? -1 : 1;
	dy = ft_abs(dy);
	e = 2 * dy - dx;
	while (c1.x <= c2.x)
	{
		fill_img(c1, data, color);
		c1.y = e > 0 ? c1.y + yi : c1.y;
		e = e > 0 ? e - 2 * dx : e;
		e += 2 * dy;
		c1.x++;
	}
}

void	draw_line_high(t_point c1, t_point c2, t_env *data, Uint32 color)
{
	int	dx;
	int	dy;
	int	xi;
	int	e;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	xi = dx < 0 ? -1 : 1;
	dx = ft_abs(dx);
	e = 2 * dx - dy;
	while (c1.y <= c2.y)
	{
		fill_img(c1, data, color);
		c1.x = e > 0 ? c1.x + xi : c1.x;
		e = e > 0 ? e - 2 * dy : e;
		e += 2 * dx;
		c1.y++;
	}
}

void	draw_line(t_point c1, t_point c2, t_env *data, Uint32 color)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
		if (c1.x > c2.x)
			draw_line_low(c2, c1, data, color);
		else
			draw_line_low(c1, c2, data, color);
	else
	{
		if (c1.y > c2.y)
			draw_line_high(c2, c1, data, color);
		else
			draw_line_high(c1, c2, data, color);
	}
}
