/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_minimap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:53:26 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 17:53:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int		min_3(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

static int		max_3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

static float	edge(t_v3 c0, t_v3 c1, t_v3 p)
{
	return ((p.x - c0.x) * (c1.y - c0.y) - (p.y - c0.y) * (c1.x - c0.x));
}

static void		compute_triangle(t_v3 v[3], t_v2 p, t_env *data)
{
	t_v3		w;
	double		norm;
	double		area;
	int			coord;
	Uint32		*pixels;

	pixels = data->sdl.texture_pixels;
	coord = (int)p.x + (int)p.y * data->w;
	area = edge(v[0], v[1], v[2]);
	w.x = edge(v[0], v[1], new_v3(p.x, p.y, 0));
	w.y = edge(v[1], v[2], new_v3(p.x, p.y, 0));
	w.z = edge(v[2], v[0], new_v3(p.x, p.y, 0));
	norm = ((v[1].x - v[0].x) * (v[2].y - v[0].y) - (v[1].y - v[0].y)
						* (v[2].x - v[0].x)) > 0 ? 1 : -1;
	if ((norm == -1 && w.x >= 0 && w.y >= 0 && w.z >= 0) ||
			(norm == 1 && w.x <= 0 && w.y <= 0 && w.z <= 0))
	{
		w.x /= area;
		w.y /= area;
		w.z /= area;
		pixels[coord] = blend_alpha(pixels[coord], 0xFF3a7499, 128);
	}
}

void		fill_triangle_minimap(t_v3 v[3], t_env *data)
{
	t_v2	max;
	t_v2	min;
	t_v2	p;

	max.x = max_3(v[0].x, v[1].x, v[2].x);
	max.x = max.x < data->minimap_pos.x + data->minimap_size.x / 2 ? max.x :
	data->minimap_pos.x + data->minimap_size.x / 2;
	max.x = max.x < data->w ? max.x : data->w;
	max.y = max_3(v[0].y, v[1].y, v[2].y);
	max.y = max.y < data->minimap_pos.y + data->minimap_size.y / 2 ? max.y :
	data->minimap_pos.y + data->minimap_size.y / 2;
	max.y = max.y < data->h ? max.y : data->h;
	min.x = min_3(v[0].x, v[1].x, v[2].x);
	min.x = min.x < 0 ? 0 : min.x;
	min.y = min_3(v[0].y, v[1].y, v[2].y);
	min.y = min.y < 0 ? 0 : min.y;
	p.y = min.y < data->minimap_pos.y - data->minimap_size.y / 2 ?
	data->minimap_pos.y - data->minimap_size.y / 2 : min.y;
	while (p.y < max.y)
	{
		p.x = min.x < data->minimap_pos.x - data->minimap_size.x / 2 ?
		data->minimap_pos.x - data->minimap_size.x / 2 : min.x;
		while (p.x < max.x)
		{
			compute_triangle(v, p, data);
			p.x++;
		}
		p.y++;
	}
}
