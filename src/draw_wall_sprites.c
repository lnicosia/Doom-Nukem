/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 13:49:10 by lnicosia         ###   ########.fr       */
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
	sprite_pixels = env->sprite_textures[env->wall_sprites[sector.sprites[render.i]
	.sprite[sprite]].texture].str;
	sprite_w = env->sprite_textures[env->wall_sprites[sector.sprites[render.i]
	.sprite[sprite]].texture].surface->w;
	pos = sector.sprites[render.i].pos[sprite].y / (sector.ceiling - sector.floor);
	start = env->wall_sprites[sector.sprites[render.i].sprite[sprite]].start[0].y;
	end = env->wall_sprites[sector.sprites[render.i].sprite[sprite]].end[0].y;
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
		y = (yalpha - pos) * render.camera->v[render.sector]
		[render.i].sprite_scale[sprite].y + start;
		if (y >= start && y < end
			&& sprite_pixels[(int)x
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
				(int)x + sprite_w * (int)y];
			else
				pixels[coord] = apply_light(sprite_pixels[
				(int)x + sprite_w * (int)y],
				sector.light_color, sector.brightness);
			if (!env->editor.select
				&& env->editor.selected_sector == sector.num
				&& env->selected_wall_sprite_wall == render.i
				&& env->selected_wall_sprite_sprite == sprite)
				pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
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
	double		z1;
	double		z2;

	i = 0;
	while (i < sector.nb_sprites[render.i])
	{
		if (sector.sprites[render.i].sprite[i] != -1)
		{
			start = env->wall_sprites[sector.sprites[render.i].sprite[i]].start[0];
			end = env->wall_sprites[sector.sprites[render.i].sprite[i]].end[0];
			pos = (sector.sprites[render.i].pos[i].x);// / sector.wall_width[render.i];
			z1 = (start.x - env->vertices[sector.vertices[render.i]].x)
			* render.camera->angle_sin -
			(start.y - env->vertices[sector.vertices[render.i]].y)
			* render.camera->angle_cos;
			z2 = (start.x - env->vertices[sector.vertices[render.i]].x)
			* render.camera->angle_cos +
			(start.y - env->vertices[sector.vertices[render.i]].y)
			* render.camera->angle_sin;
			//pos = (render.x - z1) / (z2 - z1);
			/// env->wall_sprites[sector.sprites[render.i].sprite[i]].size[0].x;
			/*if (render.camera->v[sector.num][render.i + 1].vz)
				pos = pos / render.camera->v[sector.num][render.i + 1].vz;
			else
				pos = pos / render.camera->v[sector.num][render.i].clipped_vz2;*/
			/*if (z)
				pos = pos / z;
			else
				pos = pos / render.camera->v[sector.num][render.i].clipped_vz2;*/
			//pos /= render.z;
			//pos *= sector.wall_width[render.i];
			/*z1 = env->h_w + render.camera->v[sector.num][render.i].vx *
			render.camera->scale / -render.camera->v[sector.num][render.i].vz;
			pos = (z1);*/
			//pos /= render.camera->v[sector.num][render.i].xrange;
			//pos /= z2;
			//pos /= render.camera->v[render.sector][render.i].sprite_scale[i].x;
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
