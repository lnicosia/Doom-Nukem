/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/11 17:53:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	put_pixel(t_env *env, int x, int y, unsigned int color)
{
	Uint32		*pixels;
	t_point		size;

	size.x = env->minimap_size.x / 2;
	size.y = env->minimap_size.y / 2;
	pixels = env->sdl.texture_pixels;
	if (x >= 0 && x < env->w && y >= 0 && y < env->h
		&& x >= env->minimap_pos.x - size.x
		&& x <= env->minimap_pos.x + size.x
		&& y >= env->minimap_pos.y - size.y
		&& y <= env->minimap_pos.y + size.y)
	{
		if (color == 0xFFFF0000 || (pixels[x + env->w * y] != 0xFF00FF00
			&& pixels[x + env->w * y] != 0xFFFFFFF))
		{
			if (x >= 0 && x < env->w && y >= 0 && y <= env->h)
				pixels[x + env->w * y] = color;
		}
	}
}

static void	draw_player(t_env *env)
{
	int		x;
	int		y;
	t_point	p0;
	t_point	p1;
	t_v3	triangle[3];

	x = env->minimap_pos.x - 2;
	while (x < env->minimap_pos.x + 3)
	{
		y = env->minimap_pos.y - 2;
		while (y < env->minimap_pos.y + 3)
		{
			put_pixel(env, x, y, 0xFFFFFF00);
			y++;
		}
		x++;
	}
	triangle[2] = new_v3(
			(env->player.camera.near_left_pos.x - env->player.pos.x) * env->options.minimap_scale + env->minimap_pos.x,
			(env->player.camera.near_left_pos.y - env->player.pos.y) * env->options.minimap_scale + env->minimap_pos.y,
			0);
	triangle[1] = new_v3(
			(env->player.camera.angle_cos * env->player.camera.far_z - env->player.camera.angle_sin * env->player.camera.far_left) * env->options.minimap_scale + env->minimap_pos.x,
			(env->player.camera.angle_sin * env->player.camera.far_z + env->player.camera.angle_cos * env->player.camera.far_left) * env->options.minimap_scale + env->minimap_pos.y,
			0);
	triangle[0] = new_v3(
			(env->player.camera.near_right_pos.x - env->player.pos.x) * env->options.minimap_scale + env->minimap_pos.x,
			(env->player.camera.near_right_pos.y - env->player.pos.y) * env->options.minimap_scale + env->minimap_pos.y,
			0);
	fill_triangle_minimap(triangle, env);
	p0.x = triangle[2].x;
	p0.y = triangle[2].y;
	p1.x = triangle[1].x;
	p1.y = triangle[1].y;
	draw_line_minimap(p0, p1, *env, 0xFFFFFF00);
	if (!env->options.test)
	{
		p1.x = triangle[0].x;
		p1.y = triangle[0].y;
		draw_line_minimap(p0, p1, *env, 0xFF00FF00);
	}
	triangle[2] = new_v3(
			(env->player.camera.angle_cos * env->player.camera.far_z - env->player.camera.angle_sin * env->player.camera.far_right) * env->options.minimap_scale + env->minimap_pos.x,
			(env->player.camera.angle_sin * env->player.camera.far_z + env->player.camera.angle_cos * env->player.camera.far_right) * env->options.minimap_scale + env->minimap_pos.y,
			0);
	fill_triangle_minimap(triangle, env);
	p0.x = triangle[0].x;
	p0.y = triangle[0].y;
	p1.x = triangle[2].x;
	p1.y = triangle[2].y;
	draw_line_minimap(p0, p1, *env, 0xFFFFFF00);
	
	//ligne de near_z
	p0.x = env->player.camera.angle_cos * env->player.camera.near_z * env->options.minimap_scale + env->minimap_pos.x;
	p0.y = env->player.camera.angle_sin * env->player.camera.near_z * env->options.minimap_scale + env->minimap_pos.y;
	p1.x = p0.x + env->player.camera.perp_cos * env->w * env->options.minimap_scale;
	p1.y = p0.y + env->player.camera.perp_sin * env->w * env->options.minimap_scale;
	p0.x = p0.x - env->player.camera.perp_cos * env->w * env->options.minimap_scale;
	p0.y = p0.y - env->player.camera.perp_sin * env->w * env->options.minimap_scale;
	if (env->options.test)
		draw_line_minimap(p0, p1, *env, 0xFFFFFF00);

	p0.x = env->minimap_pos.x;
	p0.y = env->minimap_pos.y;
	p1.x = env->player.camera.angle_cos * env->player.camera.near_z * env->options.minimap_scale + p0.x;
	p1.y = env->player.camera.angle_sin * env->player.camera.near_z * env->options.minimap_scale + p0.y;
	draw_line_minimap(p0, p1, *env, 0xFFFFFFFF);
}

static void	draw_minimap_hud(t_env *env)
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;

	y = env->minimap_pos.y - env->minimap_size.y / 2;
	y_max = env->minimap_pos.y + env->minimap_size.y / 2;
	x_max = env->minimap_pos.x + env->minimap_size.x / 2;
	while (y <= y_max)
	{
		x = env->minimap_pos.x - env->minimap_size.x / 2;
		while (x <= x_max)
		{
			if (x == env->minimap_pos.x
				- env->minimap_size.x / 2
				|| x == env->minimap_pos.x
				+ env->minimap_size.x / 2
				|| y == env->minimap_pos.y
				- env->minimap_size.y / 2
				|| y == env->minimap_pos.y
				+ env->minimap_size.y / 2)
				put_pixel(env, x, y, 0xFFFFFFFF);
			else if (x >= 0 && x < env->w && y >= 0 && y < env->h)
				env->sdl.texture_pixels[x + y * env->w] = 
				blend_alpha(env->sdl.texture_pixels[x
				+ y * env->w], 0, 128);
			x++;
		}
		y++;
	}
}

static void	draw_sector_num(t_env *env, t_sector sector)
{
	t_point			pos;
	t_point			text_size;
	char			*num;
	unsigned int	color;
	int				i;

	if (sector.num == env->player.sector)
		color = 0x00FF00FF;
	else
		color = 0xFFFFFFFF;
	i = 0;
	pos = new_point(0, 0);
	num = ft_sitoa(sector.num);
	TTF_SizeText(env->sdl.fonts.lato20, num, &text_size.x, &text_size.y); 
	while (i < sector.nb_vertices)
	{
		pos.x += env->minimap_pos.x + (env->vertices[sector.vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
		pos.y += env->minimap_pos.y + (env->vertices[sector.vertices[i]].y - env->player.pos.y) * env->options.minimap_scale;
		i++;
	}
	pos.x /= sector.nb_vertices;
	pos.y /= sector.nb_vertices;
	if (pos.x - text_size.x >= env->minimap_pos.x - env->minimap_size.x / 2 - 3
		&& pos.x < env->minimap_pos.x + env->minimap_size.x / 2 - 3
		&& pos.y - text_size.y >= env->minimap_pos.y - env->minimap_size.y / 2 - 3
		&& pos.y< env->minimap_pos.y + env->minimap_size.y / 2 - 3)
	{
		print_text(new_point(pos.y - text_size.y / 2, pos.x - text_size.x / 2), new_printable_text(num, env->sdl.fonts.lato20, color, 20), env);
	}
		
}

void		draw_sprites_minimap(t_env *env)
{
	int			i;
	int			x;
	int			y;
	t_object	object;
	t_point		pos;
	Uint32		*pixels;

	pixels = env->sdl.texture_pixels;
	i = -1;
	while (++i < env->nb_objects)
	{
		object = env->objects[i];
		if (!object.exists)
		{
			i++;
			continue;
		}
		pos.x = env->minimap_pos.x + (object.pos.x - env->player.pos.x) * env->options.minimap_scale;
		x = pos.x - 2;
		while (x < pos.x + 2)
		{
			pos.y = env->minimap_pos.y + (object.pos.y - env->player.pos.y) * env->options.minimap_scale;
			y = pos.y - 2;
			while (y < pos.y + 2)
			{
				if (x > env->w - 300 && x < env->w && y >= 0 && y < 300)
					pixels[x + y * env->w] = 0xFFFF0000;
				y++;
			}
			x++;
		}
	}
}

void		minimap(t_env *env)
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
		if (env->player.head_z > sect.floor_min
				&& env->player.head_z < sect.ceiling_max)
		{
			if (s == env->player.sector)
				line.color = 0xFF00FF00;
			else
				line.color = 0xFFFFFFFF;
			draw_sector_num(env, sect);
			while (v < sect.nb_vertices)
			{
				line.p0.x = env->minimap_pos.x + (env->vertices[sect.vertices[v]].x - env->player.pos.x) * env->options.minimap_scale;
				line.p0.y = env->minimap_pos.y + (env->vertices[sect.vertices[v]].y - env->player.pos.y) * env->options.minimap_scale;
				line.p1.x = env->minimap_pos.x + (env->vertices[sect.vertices[v + 1]].x - env->player.pos.x) * env->options.minimap_scale;
				line.p1.y = env->minimap_pos.y + (env->vertices[sect.vertices[v + 1]].y - env->player.pos.y) * env->options.minimap_scale;
				draw_line_minimap(line.p0, line.p1, *env, line.color);
				v++;
			}
		}
		s++;
	}
	draw_sprites_minimap(env);
	draw_player(env);
	/*int i = 0;
	t_point	enemy_start;
	t_point enemy_end;
	while (i < env->nb_enemies)
	{
		enemy_env->minimap_pos.x = env->w - 150 + (env->enemies[i].pos.x - env->player.pos.x) * env->options.minimap_scale;
		enemy_env->minimap_pos.y = 150 + (env->enemies[i].pos.y - env->player.pos.y) * env->options.minimap_scale;
		enemy_end.x = enemy_env->minimap_pos.x + 500*cos(env->enemies[i].angle * CONVERT_RADIANS);
		enemy_end.y = enemy_env->minimap_pos.y + 500*sin(env->enemies[i].angle * CONVERT_RADIANS);
		draw_line_minimap(enemy_start, enemy_end, *env, 0xFFAA8844);
		enemy_end.x = enemy_env->minimap_pos.x + 500*cos(env->enemies[i].angle * CONVERT_RADIANS - 24.5);
		enemy_end.y = enemy_env->minimap_pos.y + 500*sin(env->enemies[i].angle * CONVERT_RADIANS - 24.5);
		draw_line_minimap(enemy_start, enemy_end, *env, 0xFFAA8844);
		enemy_end.x = enemy_env->minimap_pos.x + 500*cos(env->enemies[i].angle * CONVERT_RADIANS + 24.5);
		enemy_end.y = enemy_env->minimap_pos.y + 500*sin(env->enemies[i].angle * CONVERT_RADIANS + 24.5);
		draw_line_minimap(enemy_start, enemy_end, *env, 0xFFAA8844);
		draw_circle_free(new_circle(0xFFFF0000, 0xFFFF0000, enemy_start, 2), env);
		i++;
	}*/
}
