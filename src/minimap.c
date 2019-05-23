/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by aherriau          #+#    #+#             */
/*   Updated: 2019/05/22 11:58:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap_value(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	put_pixel(t_env *env, int x, int y, unsigned int color)
{
	if (x >= env->w - 300 && x < env->w && y >= 0 && y <= 300)
	{
		if (color == 0xFFFF0000 || (env->sdl.texture_pixels[x + env->w * y] != 0xFF00FF00
			&& env->sdl.texture_pixels[x + env->w * y] != 0xFFFFFFF))
		{
			if (x >= 0 && x < env->w && y >= 0 && y <= env->h)
				env->sdl.texture_pixels[x + env->w * y] = color;
		}
	}
}

void	draw_line_2(t_env *env, t_line line)
{
	int		step;
	float	error;
	float	round_error;
	int		y;
	int		y_step;
	int		i;

	step = abs(line.p1.x - line.p0.x) < abs(line.p1.y - line.p0.y);
	if (step)
	{
		swap_value(&(line.p0.x), &(line.p0.y));
		swap_value(&(line.p1.x), &(line.p1.y));
	}
	if (line.p1.x < line.p0.x)
	{
		swap_value(&(line.p0.x), &(line.p1.x));
		swap_value(&(line.p0.y), &(line.p1.y));
	}
	error = 0.0;
	round_error = abs(line.p1.y - line.p0.y) / (line.p1.x - line.p0.x);
	y = line.p0.y;
	y_step = (line.p1.y > line.p0.y ? 1 : -1);
	i = line.p0.x;
	while (i < line.p1.x)
	{
		if (step)
			put_pixel(env, y, i, line.color);
		else
			put_pixel(env, i, y, line.color);
		error += round_error;
		if (error >= 0.5)
		{
			y++;
			error -= 1.0;
		}
		i++;
	}
}

void		draw_line_3(t_env *env, t_line line)
{
	double			length;
	double			addx;
	double			addy;
	int				i;

	t_v2			ps2;

	ps2.x = line.p1.x - line.p0.x;
	ps2.y = line.p1.y - line.p0.y;
	length = sqrt(ps2.x * ps2.x + ps2.y * ps2.y);
	addx = ps2.x / length;
	addy = ps2.y / length;
	ps2.x = line.p0.x;
	ps2.y = line.p0.y;
	i = 0;
	while (i < length)
	{
		put_pixel(env, ps2.x, ps2.y, line.color);
		ps2.x += addx;
		ps2.y += addy;
		i++;
	}
}

static void	draw_player(t_env *env)
{
	int		x;
	int		y;
	t_point	p0;
	t_point	p1;
	t_point	start;
	t_v3	triangle[3];

	start = new_point(env->w - 150, 150);
	x = env->w - 152;
	while (x < env->w - 147)
	{
		y = 148;
		while (y < 153)
		{
			put_pixel(env, x, y, 0xFFFFFF00);
			y++;
		}
		x++;
	}

	triangle[2] = new_v3(
			(env->player.near_left.x - env->player.pos.x) * env->options.minimap_scale + start.x,
			(env->player.near_left.y - env->player.pos.y) * env->options.minimap_scale + 150,
			0);
	triangle[1] = new_v3(
			(env->player.angle_cos * env->camera.far_z - env->player.angle_sin * env->camera.far_left) * env->options.minimap_scale + start.x,
			(env->player.angle_sin * env->camera.far_z + env->player.angle_cos * env->camera.far_left) * env->options.minimap_scale + 150,
			0);
	triangle[0] = new_v3(
			(env->player.near_right.x - env->player.pos.x) * env->options.minimap_scale + start.x,
			(env->player.near_right.y - env->player.pos.y) * env->options.minimap_scale + 150,
			0);
	fill_triangle(triangle, env);
	p0.x = triangle[2].x;
	p0.y = triangle[2].y;
	p1.x = triangle[1].x;
	p1.y = triangle[1].y;
	draw_line(p0, p1, *env, 0xFFFFFF00);
	if (!env->options.test)
	{
		p1.x = triangle[0].x;
		p1.y = triangle[0].y;
		draw_line(p0, p1, *env, 0xFFFFFF00);
	}
	triangle[2] = new_v3(
			(env->player.angle_cos * env->camera.far_z - env->player.angle_sin * env->camera.far_right) * env->options.minimap_scale + start.x,
			(env->player.angle_sin * env->camera.far_z + env->player.angle_cos * env->camera.far_right) * env->options.minimap_scale + 150,
			0);
	fill_triangle(triangle, env);
	p0.x = triangle[0].x;
	p0.y = triangle[0].y;
	p1.x = triangle[2].x;
	p1.y = triangle[2].y;
	draw_line(p0, p1, *env, 0xFFFFFF00);
	
	//ligne de near_z
	p0.x = env->player.angle_cos * env->camera.near_z * env->options.minimap_scale + start.x;
	p0.y = env->player.angle_sin * env->camera.near_z * env->options.minimap_scale + 150;
	p1.x = p0.x + env->player.perp_cos * env->w * env->options.minimap_scale;
	p1.y = p0.y + env->player.perp_sin * env->w * env->options.minimap_scale;
	p0.x = p0.x - env->player.perp_cos * env->w * env->options.minimap_scale;
	p0.y = p0.y - env->player.perp_sin * env->w * env->options.minimap_scale;
	if (env->options.test)
		draw_line(p0, p1, *env, 0xFFFFFF00);

	p0.x = start.x;
	p0.y = 150;
	p1.x = env->player.angle_cos * env->camera.near_z * env->options.minimap_scale + p0.x;
	p1.y = env->player.angle_sin * env->camera.near_z * env->options.minimap_scale + p0.y;
	draw_line(p0, p1, *env, 0xFFFFFFFF);
}

static void	draw_minimap_hud(t_env *env)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = env->w;
	while (y <= 300)
	{
		x = max - 300;
		while (x < max)
		{
			if (x == max - 300 || y == 300)
				put_pixel(env, x, y, 0xFFFFFFFF);
			else
				put_pixel(env, x, y, 0);
			x++;
		}
		y++;
	}
}

static void	draw_sector_num(t_env *env, t_sector sector)
{
	t_point			pos;
	char			*num;
	unsigned int	color;
	int				i;
	t_point			start;

	if (sector.num == env->player.sector)
		color = 0x00FF00FF;
	else
		color = 0xFFFFFFFF;
	start = new_point(env->w - 150, 150);
	i = 0;
	pos = new_point(0, 0);
	while (i < sector.nb_vertices)
	{
		pos.x += start.x + (env->vertices[sector.vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
		pos.y += start.y + (env->vertices[sector.vertices[i]].y - env->player.pos.y) * env->options.minimap_scale;
		i++;
	}
	pos.x /= sector.nb_vertices;
	pos.y /= sector.nb_vertices;
	num = ft_sitoa(sector.num);
	if (pos.x > env->w - 297 && pos.x < env->w && pos.y <= 295 && pos.y >= 0)
		print_text(new_point((pos.y - 10), (pos.x - 3 * ft_getlen(sector.num))), new_printable_text(
					num,
					env->sdl.fonts.bebasneue,
					color,
					20),
				env);
}

void		minimap(t_env *env)
{
	int			s;
	int			v;
	t_line		line;
	t_point		start;
	t_sector	sect;

	s = 0;
	draw_minimap_hud(env);
	start.x = env->w - 150;
	start.y = 150;
	while (s < env->nb_sectors)
	{
		sect = env->sectors[s];
		v = 0;
		if (env->player.pos.z > sect.floor_min
				&& env->player.pos.z < sect.ceiling_max)
		{
			if (s == env->player.sector)
				line.color = 0xFF00FF00;
			else
				line.color = 0xFFFFFFFF;
			draw_sector_num(env, sect);
			while (v < sect.nb_vertices)
			{
				line.p0.x = start.x + (env->vertices[sect.vertices[v]].x - env->player.pos.x) * env->options.minimap_scale;
				line.p0.y = start.y + (env->vertices[sect.vertices[v]].y - env->player.pos.y) * env->options.minimap_scale;
				line.p1.x = start.x + (env->vertices[sect.vertices[v + 1]].x - env->player.pos.x) * env->options.minimap_scale;
				line.p1.y = start.y + (env->vertices[sect.vertices[v + 1]].y - env->player.pos.y) * env->options.minimap_scale;
				draw_line(line.p0, line.p1, *env, line.color);
				v++;
			}
		}
		s++;
	}
	draw_player(env);
}
