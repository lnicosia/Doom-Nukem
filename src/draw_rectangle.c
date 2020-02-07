/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:02:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 14:11:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Create a new rectangle with the given parameters
*/

t_rectangle	new_rectangle(Uint32 inside_color, Uint32 line_color,
		int filled, int line_size)
{
	t_rectangle	new;

	new.inside_color = inside_color;
	new.line_color = line_color;
	new.filled = filled;
	new.line_size = line_size;
	if (line_size < 0)
		new.line_size = 0;
	return (new);
}

/*
**	Draw the given rectangle at the given position
*/

void		draw_rectangle(t_env *env, t_rectangle r, t_point pos, t_point size)
{
	int	x;
	int	y;

	y = ft_max(-1, pos.y - 1);
	while (++y <= pos.y + size.y && y < env->h)
	{
		x = ft_max(-1, pos.x - 1);
		while (++x <= pos.x + size.x && x < env->w)
		{
			if (y < pos.y + r.line_size
					|| y > pos.y + size.y - r.line_size
					|| x < pos.x + r.line_size
					|| x > pos.x + size.x - r.line_size)
				env->sdl.texture_pixels[x + y * env->w] = r.line_color;
			else if (r.filled)
				env->sdl.texture_pixels[x + y * env->w] = r.inside_color;
		}
	}
}

/*
**	Draw the given rectangle at the given position
*/

void		draw_rectangle_alpha(t_env *env, t_rectangle r, t_point pos,
t_point size)
{
	int		x;
	int		y;
	Uint32	*pixels;
	int		coord;

	pixels = env->sdl.texture_pixels;
	y = ft_max(-1, pos.y - 1);
	while (++y <= pos.y + size.y && y < env->h)
	{
		x = ft_max(-1, pos.x - 1);
		while (++x <= pos.x + size.x && x < env->w)
		{
			coord = x + y * env->w;
			if (y < pos.y + r.line_size
					|| y > pos.y + size.y - r.line_size
					|| x < pos.x + r.line_size
					|| x > pos.x + size.x - r.line_size)
				pixels[coord] =
				blend_alpha(r.line_color, pixels[coord], 20);
			else if (r.filled)
				env->sdl.texture_pixels[coord] =
				blend_alpha(r.inside_color, pixels[coord], 20);
		}
	}
}
