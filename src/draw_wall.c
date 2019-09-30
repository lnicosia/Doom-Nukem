/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:18:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/30 13:27:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_wall(t_sector sector, t_vline vline, t_render render, t_env *env)
{
	int			i;
	double		yalpha;
	double		y;
	double		sprite_y;
	double		x;
	double		sprite_x;
	Uint32		*pixels;
	Uint32		*texture_pixels;
	Uint32		*sprite_pixels;
	double		*zbuffer;
	t_texture	texture;
	int			texture_w;
	int			texture_h;
	int			sprite_w;
	int			coord;
	int			draw_sprite;
	t_sprite	sprite;

	sprite_x = 0;
	sprite_w = 0;
	if (sector.sprites[render.i].sprite != -1)
	{
		sprite = env->sprites[sector.sprites[render.i].sprite];
		sprite_pixels = env->textures[sprite.texture].str;
		sprite_w = env->textures[sprite.texture].surface->w;
		draw_sprite = 1;
	}
	else
	{
		(void)sprite;
		draw_sprite = 0;
	}
	texture = env->textures[render.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->zbuffer;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	x = render.alpha
		* render.camera->v[render.sector][render.i].texture_scale.x * render.z
			+ sector.align[render.i].x;
	if (draw_sprite)
		sprite_x = render.alpha
			* render.camera->v[render.sector][render.i].sprite_scale.x * render.z
					+ sector.sprites[render.i].pos.x;
	if (x != x)
		return ;
	while (x >= texture_w)
		x -= texture_w;
	while (x < 0)
		x += texture_w;
	x = ft_fclamp(x, 0, texture_w);
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		if (render.z >= zbuffer[coord])
		{
			i++;
			continue;
		}
		if (env->editor.select && vline.x == env->h_w && i == env->h_h)
		{
			if (env->editor.in_game)
			{
				env->editor.selected_sector = env->sectors[render.sector].num;
				env->editor.selected_wall = render.i;
			}
			env->selected_wall1 = env->sectors[render.sector].vertices[render.i];
			env->selected_wall2 = env->sectors[render.sector].vertices[render.i + 1];
			env->selected_floor = -1;
			env->selected_ceiling = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
		}
		yalpha = (i - render.no_slope_current_ceiling) / render.line_height;
		y = yalpha * render.camera->v[render.sector][render.i].texture_scale.y
			+ sector.align[render.i].y;
		if (draw_sprite)
			sprite_y = yalpha
				* render.camera->v[render.sector][render.i].sprite_scale.y
					+ sector.sprites[render.i].pos.y;
		while (y >= texture_h)
			y -= texture_h;
		while (y < 0)
			y += texture_h;
		if (!env->options.lighting)
			pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
		else
			pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], sector.light_color, sector.brightness);
		if (env->editor.in_game && sector.selected[render.i] && !env->editor.select)
			pixels[coord] = blend_alpha(pixels[coord], 0xFF00FF00, 128);
		zbuffer[coord] = render.z;
		if (env->options.zbuffer || env->options.contouring)
			if (i == (int)(render.max_ceiling)
					|| i == (int)(render.neighbor_max_ceiling)
					|| i == (int)(render.max_floor)
					|| i == (int)(render.neighbor_max_floor))
				pixels[coord] = 0xFFFF0000;
		if (draw_sprite && sprite_x >= sprite.start[0].x
				&& sprite_y >= sprite.start[0].y
				&& sprite_x < sprite.end[0].x
				&& sprite_y < sprite.end[0].y
				&& sprite_pixels[(int)sprite_x + sprite_w * (int)sprite_y]
				!= 0xFFC10099)
		{
			pixels[coord] = sprite_pixels[(int)sprite_x
				+ sprite_w * (int)sprite_y];
		}
		//pixels[coord] = apply_light(0xFFAAAAAA, sector.light_color, sector.brightness);
		i++;
	}
}

void	draw_vline_color(t_vline vline, t_env *env)
{
	int		coord;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		pixels[coord] = vline.color;
		vline.start++;
	}
}

void		draw_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.current_ceiling);
	vline.end = (int)(render.current_floor);
	vline.color = 0xFFFF0000;
	draw_vline_wall(sector, vline, render, env);
	if ((env->options.zbuffer || env->options.contouring)
			&& (vline.x == (int)(render.camera->v[render.sector][render.i].x)
				|| vline.x == (int)(render.camera->v[render.sector][render.i + 1].x)))
		draw_vline_color(vline, env);
}

void		draw_upper_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.current_ceiling);
	vline.end = (int)(render.neighbor_current_ceiling);
	vline.color = 0xFFFF0000;
	draw_vline_wall(sector, vline, render, env);
	if ((env->options.zbuffer || env->options.contouring)
			&& (vline.x == (int)(render.camera->v[render.sector][render.i].x)
				|| vline.x == (int)(render.camera->v[render.sector][render.i + 1].x)))
		draw_vline_color(vline, env);
}

void		draw_bottom_wall(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = (int)(render.neighbor_current_floor);
	vline.end = (int)(render.current_floor);
	vline.color = 0xFFFF0000;
	draw_vline_wall(sector, vline, render, env);
	if ((env->options.zbuffer || env->options.contouring)
			&& (vline.x == (int)(render.camera->v[render.sector][render.i].x)
				|| vline.x == (int)(render.camera->v[render.sector][render.i + 1].x)))
		draw_vline_color(vline, env);
	if (env->options.zbuffer || env->options.contouring)
	{
		if (vline.start == (int)(render.neighbor_max_floor)
				&& render.z < env->sdl.texture_pixels[env->w * (vline.start)
				+ vline.x])
			env->sdl.texture_pixels[env->w * (vline.start)
				+ vline.x] = 0xFFFF0000;
		if (vline.end == (int)(render.max_floor)
				&& render.z < env->sdl.texture_pixels[env->w * (vline.end)
				+ vline.x])
			env->sdl.texture_pixels[env->w * (vline.end)
				+ vline.x] = 0xFFFF0000;
	}
}
