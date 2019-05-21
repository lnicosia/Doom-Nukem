/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by aherriau          #+#    #+#             */
/*   Updated: 2019/05/21 17:08:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	swap_value(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	put_pixel(t_env *env, int x, int y, unsigned int color)
{
	if (x >= env->w - 300 && x < env->w && y >= 0 && y <= 300)
	{
		/*if (color == 0xFF0000FF || (env->sdl.img_str[x + env->w * y] != 0x00FF00FF
			&& env->sdl.img_str[x + env->w * y] != 0xFFFFFFF))
		{
			if (x >= 0 && x < env->w && y >= 0 && y <= env->h)
				env->sdl.img_str[x + env->w * y] = color;
		}*/
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

void	draw_line_3(t_env *env, t_line line)
{
	double			length;
	double			addx;
	double			addy;
	int				i;

	t_v2			ps2;

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
		put_pixel(env, ps2.x, ps2.y, line.color);
		ps2.x += addx;
		ps2.y += addy;
		i++;
	}
}

void	draw_player(t_env *env)
{
	int		x;
	int		y;
	int		player_hitbox;
	t_point	p0;
	t_point	p1;
	t_v3	triangle[3];

	player_hitbox = 2;
	x = env->w - 150 - player_hitbox;
	while (x < env->w - 150 + player_hitbox + 1)
	{
		y = 150 - player_hitbox;
		while (y < 150 + player_hitbox + 1)
		{
			put_pixel(env, x, y, 0xFFFFFF00);
			y++;
		}
		x++;
	}

	triangle[2] = new_v3(
			(env->player.near_left.x - env->player.pos.x) * env->options.minimap_scale + env->w - 150,
			(env->player.near_left.y - env->player.pos.y) * env->options.minimap_scale + 150,
			0);
	triangle[1] = new_v3(
			(env->player.angle_cos * env->camera.far_z - env->player.angle_sin * env->camera.far_left) * env->options.minimap_scale + env->w - 150,
			(env->player.angle_sin * env->camera.far_z + env->player.angle_cos * env->camera.far_left) * env->options.minimap_scale + 150,
			0);
	triangle[0] = new_v3(
			(env->player.near_right.x - env->player.pos.x) * env->options.minimap_scale + env->w - 150,
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
			(env->player.angle_cos * env->camera.far_z - env->player.angle_sin * env->camera.far_right) * env->options.minimap_scale + env->w - 150,
			(env->player.angle_sin * env->camera.far_z + env->player.angle_cos * env->camera.far_right) * env->options.minimap_scale + 150,
			0);
	fill_triangle(triangle, env);
	p0.x = triangle[0].x;
	p0.y = triangle[0].y;
	p1.x = triangle[2].x;
	p1.y = triangle[2].y;
	draw_line(p0, p1, *env, 0xFFFFFF00);
	
	//ligne de near_z
	p0.x = env->player.angle_cos * env->camera.near_z * env->options.minimap_scale + env->w - 150;
	p0.y = env->player.angle_sin * env->camera.near_z * env->options.minimap_scale + 150;
	p1.x = p0.x + cos(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	p1.y = p0.y + sin(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	p0.x = p0.x - cos(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	p0.y = p0.y - sin(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	if (env->options.test)
		draw_line(p0, p1, *env, 0xFFFFFF00);

	p0.x = env->w - 150;
	p0.y = 150;
	p1.x = env->player.angle_cos * env->camera.near_z * env->options.minimap_scale + p0.x;
	p1.y = env->player.angle_sin * env->camera.near_z * env->options.minimap_scale + p0.y;
	draw_line(p0, p1, *env, 0xFFFFFFFF);
}

void	draw_minimap_hud(t_env *env)
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

void	draw_sector_num(t_env *env, t_sector sector)
{
	t_v2			pos;
	char			*num;
	unsigned int	color;
	int				i;

	color = 0xFFFFFFFF;
	if (sector.num == env->player.sector)
		color = 0x00FF00FF;
	i = 0;
	pos = new_v2(0, 0);
	while (i < sector.nb_vertices)
	{
		pos.x += env->w - 150 + (env->vertices[sector.vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
		pos.y += 150 + (env->vertices[sector.vertices[i]].y - env->player.pos.y) * env->options.minimap_scale;
		i++;
	}
	pos.x /= sector.nb_vertices;
	pos.y /= sector.nb_vertices;
	num = ft_sitoa(sector.num);
	if (pos.x > env->w - 297 && pos.x < env->w && pos.y <= 295 && pos.y >= 0)
		print_text(new_v2((int)(pos.y - 10), (int)(pos.x - 3 * ft_getlen(sector.num))), new_printable_text(
					num,
					env->sdl.fonts.bebasneue,
					color,
					20),
				env);
}

void	minimap(t_env *env)
{
	int			s;
	int			v;
	t_point		p0;
	t_point		p1;
	t_sector	sect;

	s = 0;
	draw_minimap_hud(env);
	while (s < env->nb_sectors)
	{
		sect = env->sectors[s];
		v = 0;
		if (env->player.pos.z > sect.floor_min && env->player.pos.z < sect.ceiling_max)
		{
			draw_sector_num(env, sect);
			while (v < sect.nb_vertices)
			{
				p0.x = env->w - 150 + (env->vertices[sect.vertices[v]].x - env->player.pos.x) * env->options.minimap_scale;
				p0.y = 150 + (env->vertices[sect.vertices[v]].y - env->player.pos.y) * env->options.minimap_scale;
				p1.x = env->w - 150 + (env->vertices[sect.vertices[v + 1]].x - env->player.pos.x) * env->options.minimap_scale;
				p1.y = 150 + (env->vertices[sect.vertices[v + 1]].y - env->player.pos.y) * env->options.minimap_scale;
				draw_line(p0, p1, *env, 0xFFFFFFFF);
				if (sect.num == env->player.sector)
					draw_line(p0, p1, *env, 0xFF00FF00);
				v++;
			}
		}
		s++;
	}
	draw_player(env);
}
