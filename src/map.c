/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by aherriau          #+#    #+#             */
/*   Updated: 2019/04/16 11:27:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			color;
}				t_line;

void	swap_value(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	put_pixel(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x < e->w && y >= 0 && y < e->h)
		e->sdl.img_str[x + e->w * y] = color;
}

void	draw_line_2(t_env *e, t_line line)
{
	int		step;
	float	error;
	float	round_error;
	int		y;
	int		y_step;
	int		i;

	step = abs(line.x1 - line.x0) < abs(line.y1 - line.y0);
	if (step)
	{
		swap_value(&(line.x0), &(line.y0));
		swap_value(&(line.x1), &(line.y1));
	}
	if (line.x1 < line.x0)
	{
		swap_value(&(line.x0), &(line.x1));
		swap_value(&(line.y0), &(line.y1));
	}
	error = 0.0;
	round_error = abs(line.y1 - line.y0) / (line.x1 - line.x0);
	y = line.y0;
	y_step = (line.y1 > line.y0 ? 1 : -1);
	i = line.x0;
	while (i < line.x1)
	{
		if (step)
			put_pixel(e, y, i, line.color);
		else
			put_pixel(e, i, y, line.color);
		error += round_error;
		if (error >= 0.5)
		{
			y++;
			error -= 1.0;
		}
		i++;
	}
}

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

void	draw_line_3(t_env *e, t_line line)
{
	double			length;
	double			addx;
	double			addy;
	int				i;

	t_point			ps2;

	ps2.x = line.x1 - line.x0;
	ps2.y = line.y1 - line.y0;
	length = sqrt(ps2.x * ps2.x + ps2.y * ps2.y);
	addx = ps2.x / length;
	addy = ps2.y / length;
	ps2.x = line.x0;
	ps2.y = line.y0;
	i = 0;
	while (i < length)
	{
		put_pixel(e, ps2.x, ps2.y, line.color);
		ps2.x += addx;
		ps2.y += addy;
		i++;
	}
}

void	draw_player(t_env *e)
{
	int		x;
	int		y;
	int		factor;
	int		factor2;
	t_line	line;

	factor = 2;
	factor2 = 20;
	x = (int)e->player.pos.x - factor;
	while (x < ((int)e->player.pos.x + factor))
	{
		y = (int)e->player.pos.y - factor;
		while (y < ((int)e->player.pos.y + factor))
		{
			put_pixel(e, x, y, 0xFFFF00FF);
			y++;
		}
		x++;
	}
	//ft_printf("(%f, %f)\n", e->player.dir.x, e->player.dir.y);

	line.x0 = e->player.pos.x;
	line.y0 = e->player.pos.y;
	line.x1 = cos(e->player.angle) * factor2 + line.x0;
	line.y1 = sin(e->player.angle) * factor2 + line.y0;
	line.color = 0xFFFFFFFF;
	draw_line_3(e, line);
	//ft_printf("%f\n", e->player.angle);
}

void	map_process(t_env *e)
{
	int			s;
	int			v;
	t_line		line;
	t_sector	sect;

	//ft_printf("---\n");
	s = 0;
	//while (s < 2)
	while (s < e->nb_sectors)
	{
		sect = e->sectors[s];
		v = 0;
		while (v < sect.nb_vertices)
		{
			line.x0 = e->vertices[sect.vertices[v]].x * 10;
			line.y0 = e->vertices[sect.vertices[v]].y * 10;
			if ((v + 1) == sect.nb_vertices)
			{
				line.x1 = e->vertices[sect.vertices[0]].x * 10;
				line.y1 = e->vertices[sect.vertices[0]].y * 10;
			}
			else
			{
				line.x1 = e->vertices[sect.vertices[v + 1]].x * 10;
				line.y1 = e->vertices[sect.vertices[v + 1]].y * 10;
			}
			//ft_printf("(%d, %d) -> (%d, %d)\n", line.x0, line.y0, line.x1, line.y1);

			if (sect.neighbors[v] == -1)
				line.color = 0xFFFFFFFF;
			else
				line.color = 0x990000FF;
			draw_line_3(e, line);
			v++;
		}
		s++;
	}
	draw_player(e);
}

void	map_render(t_env *e)
{
	e->sdl.texture = SDL_CreateTextureFromSurface(e->sdl.renderer, e->sdl.surface);
	SDL_RenderCopy(e->sdl.renderer, e->sdl.texture, NULL, NULL);
	SDL_RenderPresent(e->sdl.renderer);
}
