/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 09:47:24 by lnicosia         ###   ########.fr       */
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
	pos = sector.sprites[render.i].pos[sprite].y / 100;
	start = env->sprites[sector.sprites[render.i].sprite[sprite]].start[0].y;
	end = env->sprites[sector.sprites[render.i].sprite[sprite]].end[0].y;
	while (++i <= render.current_floor)
	{
		coord = render.x + env->w * i;
		if (render.z > zbuffer[coord])
			continue;
		yalpha = (i - render.no_slope_current_ceiling)
		/ render.line_height - pos;
		y = yalpha * render.camera->v[render.sector]
		[render.i].sprite_scale[sprite].y + start;
		if (y >= start && y < end
			&& sprite_pixels[(int)render.sprite_x
			+ sprite_w * (int)y] != 0xFFC10099)
		{
			if (env->editor.select && render.x == env->h_w && i == env->h_h)
			{
				reset_selection(env);
				env->selected_wall_sprite_wall = render.i;
				env->selected_wall_sprite_sprite = sprite;
				env->editor.selected_sector = sector.num;

			}
			if (!env->options.lighting && !env->playing)
				pixels[coord] = sprite_pixels[
				(int)render.sprite_x + sprite_w * (int)y];
			else
				pixels[coord] = apply_light(sprite_pixels[
				(int)render.sprite_x + sprite_w * (int)y],
				sector.light_color, sector.brightness);
			if (env->editor.in_game && !env->editor.select
				&& env->editor.selected_sector == sector.num
				&& env->selected_wall_sprite_wall == render.i
				&& env->selected_wall_sprite_sprite == sprite)
				pixels[coord] = blend_alpha(pixels[coord], 0xFF00FF00, 128);
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
			// render.camera->v[sector.num][render.i].xrange;
			//  / (render.camera->v[render.sector][render.i].sprite_scale[i].x * render.z);
			/*if (render.camera->v[sector.num][render.i + 1].vz)
				pos = pos / render.camera->v[sector.num][render.i + 1].vz * sector.wall_width[render.i];
			else
				pos = pos / render.camera->v[sector.num][render.i].clipped_vz2 * sector.wall_width[render.i];*/
			render.sprite_x = (render.alpha) * render.camera->v[render.sector]
			[render.i].sprite_scale[i].x * render.z
			+ start
			- pos;
			if (render.sprite_x >= start
				&& render.sprite_x < end)
				draw_vline_sprite(i, sector, render, env);
		}
		i++;
	}
}
