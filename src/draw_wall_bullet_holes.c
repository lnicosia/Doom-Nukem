/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bullet_holes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 18:49:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_vline_bullet_hole(t_bullet_hole *curr, t_sector sector,
t_render render, t_env *env)
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
	double	x;
	double	pos;

	y = 0.0;
	i = render.current_ceiling - 1;
	zbuffer = env->zbuffer;
	pixels = env->sdl.texture_pixels;
	sprite_pixels = env->sprite_textures[35].str;
	sprite_w = env->sprite_textures[35].surface->w;
	pos = curr->pos.y / (sector.ceiling - sector.floor);
	start = env->object_sprites[BULLET_HOLE].start[0].y;
	end = env->object_sprites[BULLET_HOLE].end[0].y;
	x = render.sprite_x;
	while (++i <= render.current_floor)
	{
		coord = render.x + env->w * i;
		if (render.z >= zbuffer[coord])
			continue;
		yalpha = (i - render.no_slope_current_ceiling)
		/ render.line_height;
		/*x = yalpha * render.camera->v[render.sector]
		[render.i].sprite_scale[sprite].y + start;
		if (x >= start && x < end
			&& sprite_pixels[(int)x
			+ sprite_w * (int)y] != 0xFFC10099)*/
		y = (yalpha - pos)
		* curr->scale.y
		+ start;
		if (y >= start && y < end
			&& sprite_pixels[(int)x
			+ sprite_w * (int)y] != 0xFFC10099)
		{
			if (!env->options.lighting
				|| (!sector.brightness && !sector.intensity))
				pixels[coord] = sprite_pixels[
				(int)x + sprite_w * (int)y];
			else if (!sector.brightness)
				pixels[coord] = apply_light_color(sprite_pixels[
				(int)x + sprite_w * (int)y],
				sector.light_color, sector.intensity);
			else if (!sector.intensity)
				pixels[coord] = apply_light_brightness(sprite_pixels[
				(int)x + sprite_w * (int)y],
				sector.brightness);
			else
				pixels[coord] = apply_light_both(sprite_pixels[
				(int)x + sprite_w * (int)y],
				sector.light_color, sector.intensity, sector.brightness);
			zbuffer[coord] = render.z;
		}
	}
}

void	draw_wall_bullet_holes(t_sector sector, t_render render, t_env *env)
{
	t_point			start;
	t_point			end;
	t_bullet_hole	*curr;
	t_list			*bullet_holes;
	double			pos;

	bullet_holes = sector.wall_bullet_holes[render.i];
	while (bullet_holes)
	{
	  	curr = (t_bullet_hole*)bullet_holes->content;
		start = env->object_sprites[3].start[0];
		end = env->object_sprites[3].end[0];
		pos =  curr->pos.x / sector.wall_width[render.i]
		* curr->scale.x;
		if (render.camera->v[render.sector][render.i + 1].vz)
			pos *= render.camera->v[render.sector][render.i + 1].vz;
		else
			pos *= render.camera->v[render.sector][render.i].clipped_vz2;
		render.sprite_x = (render.alpha)
		* curr->scale.x
		* render.z + start.x
		- pos;
		if (render.sprite_x >= start.x
			&& render.sprite_x < end.x)
			draw_vline_bullet_hole(curr, sector, render, env);
		bullet_holes = bullet_holes->next;
	}
}
