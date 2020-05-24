/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:17:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:17:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw_grid_walls.h"

void	put_pixel(t_env *env, int x, int y, unsigned int color)
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

void	draw_minimap_hud(t_env *env)
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
			if (x == env->minimap_pos.x - env->minimap_size.x / 2
				|| x == env->minimap_pos.x + env->minimap_size.x / 2
				|| y == env->minimap_pos.y - env->minimap_size.y / 2
				|| y == env->minimap_pos.y + env->minimap_size.y / 2)
				put_pixel(env, x, y, 0xFFFFFFFF);
			else if (x >= 0 && x < env->w && y >= 0 && y < env->h)
				env->sdl.texture_pixels[x + y * env->w] =
				blend_alpha(env->sdl.texture_pixels[x + y * env->w], 0, 128);
			x++;
		}
		y++;
	}
}

void	get_last_wall_angle(int i, t_grid_wall_drawer *drawer, t_env *env)
{
	drawer->v[0].x = env->minimap_pos.x + (env->vertices[drawer->sector->
	vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
	drawer->v[0].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[i]].y - env->player.pos.y)
	* env->options.minimap_scale;
	drawer->v[1].x = env->minimap_pos.x
	+ (env->vertices[drawer->sector->vertices[0]].x - env->player.pos.x)
	* env->options.minimap_scale;
	drawer->v[1].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[0]].y - env->player.pos.y)
	* env->options.minimap_scale;
	drawer->v[2].x = env->minimap_pos.x
	+ (env->vertices[drawer->sector->vertices[1]].x - env->player.pos.x)
	* env->options.minimap_scale;
	drawer->v[2].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[1]].y - env->player.pos.y)
	* env->options.minimap_scale;
	if (get_angle(drawer->v))
	{
		drawer->center.x += drawer->v[1].x;
		drawer->center.y += drawer->v[1].y;
		drawer->nb_angles++;
	}
	drawer->center.x /= drawer->nb_angles;
	drawer->center.y /= drawer->nb_angles;
}

void	get_current_wall_angle(int i, t_grid_wall_drawer *drawer, t_env *env)
{
	drawer->v[0].x = env->minimap_pos.x
	+ (env->vertices[drawer->sector->vertices[i]].x - env->player.pos.x)
	* env->options.minimap_scale;
	drawer->v[0].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[i]].y - env->player.pos.y)
	* env->options.minimap_scale;
	drawer->v[1].x = env->minimap_pos.x
	+ (env->vertices[drawer->sector->vertices[i + 1]].x - env->player.pos.x)
	* env->options.minimap_scale;
	drawer->v[1].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[i + 1]].y - env->player.pos.y)
	* env->options.minimap_scale;
	drawer->v[2].x = env->minimap_pos.x
	+ (env->vertices[drawer->sector->vertices[i + 2]].x - env->player.pos.x)
	* env->options.minimap_scale;
	drawer->v[2].y = env->minimap_pos.y
	+ (env->vertices[drawer->sector->vertices[i + 2]].y - env->player.pos.y)
	* env->options.minimap_scale;
	if (get_angle(drawer->v))
	{
		drawer->center.x += drawer->v[1].x;
		drawer->center.y += drawer->v[1].y;
		drawer->nb_angles++;
	}
}

int		print_minimap_sector_num(t_grid_wall_drawer *drawer, t_env *env)
{
	t_point	text_size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", drawer->sector->num);
	if (TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &text_size.x,
	&text_size.y))
		return (-1);
	if (drawer->center.x - text_size.x >= env->minimap_pos.x
		- env->minimap_size.x / 2 - 3
		&& drawer->center.x < env->minimap_pos.x + env->minimap_size.x / 2 - 3
		&& drawer->center.y - text_size.y >= env->minimap_pos.y
		- env->minimap_size.y / 2 - 3
		&& drawer->center.y < env->minimap_pos.y + env->minimap_size.y / 2 - 3)
	{
		if (print_text(new_point(drawer->center.y - text_size.y / 2,
		drawer->center.x - text_size.x / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato20,
		drawer->color, 20), env))
			return (-1);
	}
	return (0);
}
