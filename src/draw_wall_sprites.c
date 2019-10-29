/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/29 12:24:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_vline_sprite(int sprite, t_sector sector, t_render render,
t_env *env)
{
	int	i;
	int	coord;
	int	start;
	int	end;
	int	sprite_w;
	double	*zbuffer;
	Uint32	*pixels;
	Uint32	*sprite_pixels;
	double	yalpha;
	double	y;
	double	pos;

	i = render.current_ceiling - 1;
	zbuffer = env->zbuffer;
	pixels = env->sdl.texture_pixels;
	sprite_pixels = env->textures[env->sprites[sector.sprites[render.i]
	.sprite[sprite]].texture].str;
	sprite_w = env->textures[env->sprites[sector.sprites[render.i]
	.sprite[sprite]].texture].surface->w;
	pos = sector.sprites[render.i].pos[sprite].y;
	start = env->sprites[sector.sprites[render.i].sprite[sprite]].start[0].y;
	end = env->sprites[sector.sprites[render.i].sprite[sprite]].end[0].y;
	while (++i <= render.current_floor)
	{
		coord = render.x + env->w * i;
		if (render.z > zbuffer[coord])
			continue;
		yalpha = (i - render.no_slope_current_ceiling)
		/ render.line_height;
		y = yalpha * render.camera->v[render.sector]
		[render.i].sprite_scale[sprite].y + start
		- pos * render.texture_h / 10.0;
		if (y >= start && y < end
			&& sprite_pixels[(int)render.sprite_x
			+ sprite_w * (int)y] != 0xFFC10099)
		{
			if (!env->options.lighting && !env->playing)
				pixels[coord] = sprite_pixels[
				(int)render.sprite_x + sprite_w * (int)y];
			else
				pixels[coord] = apply_light(sprite_pixels[
				(int)render.sprite_x + sprite_w * (int)y],
				sector.light_color, sector.brightness);
			zbuffer[coord] = render.z;
		}
	}
}

void	draw_wall_sprites(t_sector sector, t_render render, t_env *env)
{
	int		i;
	int		start;
	int		end;
	double		pos;

	i = 0;
	while (i < sector.nb_sprites[render.i])
	{
		if (sector.sprites[render.i].sprite[i] != -1)
		{
			start = env->sprites[sector.sprites[render.i].sprite[i]].start[0].x;
			end = env->sprites[sector.sprites[render.i].sprite[i]].end[0].x;
			pos = sector.sprites[render.i].pos[i].x;
			render.sprite_x = render.alpha * render.camera->v[render.sector]
			[render.i].sprite_scale[i].x * render.z
			+ start
			- pos * render.texture_w / 10.0;
			if (render.sprite_x >= start
				&& render.sprite_x < end)
				draw_vline_sprite(i, sector, render, env);
		}
		i++;
	}
}
