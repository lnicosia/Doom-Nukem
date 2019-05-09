/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:18:51 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/07 17:54:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		min_3(int a, int b, int c)
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

int		max_3(int a, int b, int c)
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

float	edge(t_v3 c0, t_v3 c1, t_v3 p)
{
	return ((p.x - c0.x) * (c1.y - c0.y) - (p.y - c0.y) * (c1.x - c0.x));
}

void	compute_triangle(t_v3 v[3], t_v2 p, t_env *data)
{
	t_v3	w;
	double		norm;
	double		area;

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
		if (data->sdl.img_str[(int)p.x + (int)p.y * data->w] == 0xFF)
			data->sdl.img_str[(int)p.x + (int)p.y * data->w] = 0x3a7499FF;
		/*data->sdl.img_str[(int)p.x + (int)p.y * data->w] = 
			blend_alpha(data->sdl.img_str[(int)p.x + (int)p.y * data->w], 0x3a7499FF, 128);*/
	}
}

void	fill_triangle(t_v3 v[3], t_env *data)
{
	t_v2	max;
	t_v2	min;
	t_v2	p;

	max.x = max_3(v[0].x, v[1].x, v[2].x);
	max.x = max.x < data->w ? max.x : data->w;
	max.y = max_3(v[0].y, v[1].y, v[2].y);
	max.y = max.y < 300 ? max.y : 300;
	min.x = min_3(v[0].x, v[1].x, v[2].x);
	min.y = min_3(v[0].y, v[1].y, v[2].y);
	p.y = min.y < 0 ? 0 : min.y;
	while (p.y < max.y)
	{
		p.x = min.x < data->w - 300 ? data->w - 300 : min.x;
		while (p.x < max.x)
		{
			compute_triangle(v, p, data);
			p.x++;
		}
		p.y++;
	}
}