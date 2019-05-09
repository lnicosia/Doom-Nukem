/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by aherriau          #+#    #+#             */
/*   Updated: 2019/05/09 15:32:07 by lnicosia         ###   ########.fr       */
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

void	put_pixel(t_env *env, int x, int y, int color)
{
	if (x >= env->w - 300 && x < env->w && y >= 0 && y <= 300
			&& env->sdl.img_str[x + env->w * y] != 0x00FF00FF
			&& env->sdl.img_str[x + env->w * y] != 0xFFFFFFF)
		env->sdl.img_str[x + env->w * y] = color;
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

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

void	draw_line_3(t_env *env, t_line line)
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
	int		factor2;
	t_line	line;
	t_v3	triangle[3];

	player_hitbox = 2;
	factor2 = 20;
	x = env->w - 150 - player_hitbox;
	while (x < env->w - 150 + player_hitbox + 1)
	{
		y = 150 - player_hitbox;
		while (y < 150 + player_hitbox + 1)
		{
			put_pixel(env, x, y, 0xFFFF00FF);
			y++;
		}
		x++;
	}

	line.color = 0xFFFF00FF;
	triangle[2] = new_v3(
			cos(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->camera.near_z * 1.5 * env->options.minimap_scale + env->w - 150,
			sin(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->camera.near_z * 1.5 * env->options.minimap_scale + 150,
			0);
	/*triangle[2] = new_v3(
			cos(env->player.angle) * env->camera.near_right * env->options.minimap_scale + env->w - 150,
			sin(env->player.angle) * env->camera.near_z * env->options.minimap_scale + 150,
			0);*/
	triangle[1] = new_v3(
			cos(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->w * env->options.minimap_scale + env->w - 150,
			sin(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->w * env->options.minimap_scale + 150,
			0);
	triangle[0] = new_v3(
			cos(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->camera.near_z * 1.5 * env->options.minimap_scale + env->w - 150,
			sin(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->camera.near_z * 1.5 * env->options.minimap_scale + 150,
			0);
	fill_triangle(triangle, env);
	line.x0 = triangle[2].x;
	line.y0 = triangle[2].y;
	line.x1 = triangle[1].x;
	line.y1 = triangle[1].y;
	draw_line_3(env, line);
	triangle[2] = new_v3(
			cos(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + env->w - 150,
			sin(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + 150,
			0);
	fill_triangle(triangle, env);
	line.x0 = triangle[0].x;
	line.y0 = triangle[0].y;
	line.x1 = triangle[2].x;
	line.y1 = triangle[2].y;
	draw_line_3(env, line);
	
	//ligne de near_z
	line.x0 = cos(env->player.angle) * env->camera.near_z * env->options.minimap_scale + env->w - 150;
	line.y0 = sin(env->player.angle) * env->camera.near_z * env->options.minimap_scale + 150;
	line.x1 = line.x0 + cos(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	line.y1 = line.y0 + sin(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	line.x0 = line.x0 - cos(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	line.y0 = line.y0 - sin(env->player.angle - M_PI / 2) * env->w * env->options.minimap_scale;
	if (env->options.test)
		draw_line_3(env, line);


	
	line.x0 = env->w - 150;
	line.y0 = 150;
	line.x1 = cos(env->player.angle) * env->options.minimap_scale + line.x0;
	line.y1 = sin(env->player.angle) * env->options.minimap_scale + line.y0;
	line.color = 0xFFFFFFFF;
	draw_line_3(env, line);

	
	/*line.x0 = env->w - 150 + cos(env->player.angle) * env->options.minimap_scale;
	line.y0 = 150 + sin(env->player.angle) * env->options.minimap_scale;
	line.x1 = cos(env->player.angle) + line.x0;
	line.y1 = sin(env->player.angle) + line.y0;
	triangle[0] = new_v3(line.x0, line.y0, 0);

	line.x1 = cos(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + line.x0;
	line.y1 = sin(env->player.angle - (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + line.y0;
	line.color = 0xFF0000FF;
	//draw_line_3(env, line);
	triangle[1] = new_v3(line.x1, line.y1, 0);

	line.x1 = cos(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + line.x0;
	line.y1 = sin(env->player.angle + (env->camera.hfov / 2 * M_PI / 180.0)) * env->w + line.y0;
	line.color = 0xFF0000FF;
	//draw_line_3(env, line);
	triangle[2] = new_v3(line.x1, line.y1, 0);
	fill_triangle(triangle, env);*/
	//ft_printf("%f\n", env->player.angle);
}

void	draw_minimap_hud(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 300)
	{
		x = env->w - 300;
		while (x < env->w)
		{
			if (x == env->w - 300 || y == 300)
				put_pixel(env, x, y, 0xFFFFFFFF);
			else
				put_pixel(env, x, y, 0xFF);
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
	num = ft_itoa(sector.num);
	if (pos.x > env->w - 297 && pos.y <= 295)
		print_text(new_v2(pos.y - 10, pos.x - 3 * ft_getlen(sector.num)), new_printable_text(
					num,
					"fonts/bebas_neue/BebasNeue-Regular.ttf",
					color,
					20),
				env);
	ft_strdel(&num);

}

void	minimap(t_env *env)
{
	int			s;
	int			v;
	t_line		line;
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
				line.x0 = env->w - 150 + (env->vertices[sect.vertices[v]].x - env->player.pos.x) * env->options.minimap_scale;
				line.y0 = 150 + (env->vertices[sect.vertices[v]].y - env->player.pos.y) * env->options.minimap_scale;
				if ((v + 1) == sect.nb_vertices)
				{
					line.x1 = env->w - 150 + (env->vertices[sect.vertices[0]].x - env->player.pos.x) * env->options.minimap_scale;
					line.y1 = 150 + (env->vertices[sect.vertices[0]].y - env->player.pos.y) * env->options.minimap_scale;
				}
				else
				{
					line.x1 = env->w - 150 + (env->vertices[sect.vertices[v + 1]].x - env->player.pos.x) * env->options.minimap_scale;
					line.y1 = 150 + (env->vertices[sect.vertices[v + 1]].y - env->player.pos.y) * env->options.minimap_scale;
				}
				line.color = 0xFFFFFFFF;
				if (sect.num == env->player.sector)
					line.color = 0x00FF00FF;
				draw_line_3(env, line);
				v++;
			}
		}
		s++;
	}
	draw_player(env);
}
