/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:45:36 by sipatry          ###   ########.fr       */
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
	double	x;
	double	pos;

	y = 0.0;
	i = render.current_ceiling - 1;
	zbuffer = env->zbuffer;
	pixels = env->sdl.texture_pixels;
	sprite_pixels = env->sprite_textures[env->object_sprites[sector.wall_sprites[render.i]
		.sprite[sprite]].texture].str;
	sprite_w = env->sprite_textures[env->object_sprites[sector.wall_sprites[render.i]
		.sprite[sprite]].texture].surface->w;
	pos = sector.wall_sprites[render.i].pos[sprite].y / (sector.ceiling - sector.floor);
	start = env->object_sprites[sector.wall_sprites[render.i].sprite[sprite]].start[0].y;
	end = env->object_sprites[sector.wall_sprites[render.i].sprite[sprite]].end[0].y;
	x = render.sprite_x;
	while (++i <= render.current_floor)
	{
		coord = render.x + env->w * i;
		if (render.z >= zbuffer[coord])
			continue;
		yalpha = (i - render.no_slope_current_ceiling)
			/ render.line_height;
		/*x = yalpha * render.camera->v[rend	er.sector]
		  [render.i].sprite_scale[sprite].y + start;
		  if (x >= start && x < end
		  && sprite_pixels[(int)x
		  + sprite_w * (int)y] != 0xFFC10099)*/
		y = (yalpha - pos) * render.camera->v[render.sector]
			[render.i].sprite_scale[sprite].y + start;
		if (y >= start && y < end
				&& sprite_pixels[(int)x
				+ sprite_w * (int)y] != 0xFFC10099)
		{
			if (((env->editor.tab
				&& render.x == env->sdl.mx && i == env->sdl.my)
				|| (!env->editor.tab && render.x == env->h_w
				&& i == env->h_h)))
			{
				if (env->editor.select)
				{
					reset_selection(env);
					if (env->editor.selected_events == 2)
						env->editor.selected_events = 1;
					env->selected_wall_sprite_wall = render.i;
					env->selected_wall_sprite_sprite = sprite;
					env->editor.selected_sector = sector.num;
					tabs_gestion(env);
				}
				if (env->playing
						&& sector.wall_sprites[render.i].nb_press_events[sprite])
				{
					if (render.z < 10)
					{
						env->hovered_wall_sprite_wall = render.i;
						env->hovered_wall_sprite_sprite = sprite;
						env->hovered_wall_sprite_sector = sector.num;
					}
					else
					{
						env->hovered_wall_sprite_wall = -1;
						env->hovered_wall_sprite_sprite = -1;
						env->hovered_wall_sprite_sector = -1;
					}
				}
			}
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
			if (!env->editor.select
					&& env->editor.selected_sector == sector.num
					&& env->selected_wall_sprite_wall == render.i
					&& env->selected_wall_sprite_sprite == sprite)
				pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
			else if (env->playing && env->hovered_wall_sprite_wall == render.i
					&& env->hovered_wall_sprite_sprite == sprite)
				pixels[coord] = blend_alpha(pixels[coord],
						env->press_wall_sprite_color,
						env->press_wall_sprite_intensity);
			zbuffer[coord] = render.z;
		}
	}
}

void	draw_wall_sprites(t_sector sector, t_render render, t_env *env)
{
	int		i;
	t_point		start;
	t_point		end;
	double		pos;

	i = 0;
	while (i < sector.wall_sprites[render.i].nb_sprites)
	{
		if (sector.wall_sprites[render.i].sprite[i] != -1)
		{
			start = env->object_sprites[sector.wall_sprites[render.i].sprite[i]].start[0];
			end = env->object_sprites[sector.wall_sprites[render.i].sprite[i]].end[0];
			pos = (sector.wall_sprites[render.i].pos[i].x)
				/ sector.wall_width[render.i]
				* render.camera->v[render.sector][render.i].sprite_scale[i].x;
			if (render.camera->v[render.sector][render.i + 1].vz)
				pos *= render.camera->v[render.sector][render.i + 1].vz;
			else
				pos *= render.camera->v[render.sector][render.i].clipped_vz2;
			render.sprite_x = (render.alpha)
				* render.camera->v[render.sector][render.i].sprite_scale[i].x
				* render.z + start.x
				- pos;
			if (render.sprite_x >= start.x
					&& render.sprite_x < end.x)
				draw_vline_sprite(i, sector, render, env);
		}
		i++;
	}
}
