/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/12 13:20:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_floor2(t_sector sector, t_vline vline, t_render2 render, t_env *env)
{
	int		i;
	double	y;
	double	x;
	double	alpha;
	Uint32	*pixels;
	Uint32	*texture_pixels;
	double	*zbuffer;
	int		coord;
	int		texture_w;
	int		texture_h;
	double	z;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	texture_w = env->textures[sector.floor_texture].surface->w;
	texture_h = env->textures[sector.floor_texture].surface->h;
	texture_pixels = env->textures[sector.floor_texture].str;
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		alpha = render.floor_start / (double)(i - render.floor_horizon);
		z = alpha * render.z;
		if (z >= zbuffer[coord])
		{
			i++;
			continue;
		}
		if (env->editor.select && vline.x == env->h_w && i == env->h_h)
		{
			env->selected_wall1 = -1;
			env->selected_wall2 = -1;
			env->selected_floor = render.sector;
			env->selected_ceiling = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		//y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.camera_y;
		/*y = ((1.0 - alpha) * env->player.camera_y / env->camera.near_z + alpha * render.texel.y / render.z)
		  / ((1.0 - alpha) / env->camera.near_z + alpha / render.z);*/
		//x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.camera_x;
		/*x = ((1.0 - alpha) * env->player.camera_x / env->camera.near_z + alpha * render.texel.y / render.z)
		  / ((1.0 - alpha) / env->camera.near_z + alpha / render.z);*/
		y *= sector.floor_scale.y;
		x *= sector.floor_scale.x;
		if (y >= texture_h || y < 0)
			y = ft_abs((int)y % texture_h);
		if (x >= texture_w || x < 0)
			x = ft_abs((int)x % texture_w);
		y = texture_h - y;
		x = texture_w - x;
		if (x >= 0 && x < texture_w && y >= 0 && y < texture_h)
		{
			if (!env->options.lighting && !env->sectors[render.sector].floor_slope)
				pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
			else if (!env->sectors[render.sector].floor_slope)
				//pixels[coord] = blend_alpha(texture_pixels[(int)x + texture_w * (int)y], render.light_color, render.brightness);
				pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], sector.light_color, sector.brightness);
			else
				pixels[coord] = vline.color;
			if (env->editor.in_game && !env->editor.select && env->selected_floor == render.sector)
				pixels[coord] = blend_alpha(pixels[coord], 0xFF00FF00, 128);
			zbuffer[coord] = z;
			/*if (i == (int)render.floor_horizon)
			  pixels[coord] = 0xFF00FF00;*/
			/*if (i == (int)render.ceiling_horizon)
			  pixels[coord] = 0xFFFF0000;*/
		}
		i++;
	}
	if (env->options.zbuffer || env->options.contouring)
	{
		if (vline.start == (int)render.max_floor + 1
				&& vline.start >= 0 && vline.start < env->h)
		{
			pixels[vline.x + env->w * vline.start] = 0xFFFF0000;
			zbuffer[vline.x + env->w * vline.start] = 100000000;
		}
		if (vline.end < env->h - 1 && vline.end >= 0)
		{
			pixels[vline.x + env->w * vline.end] = 0xFFFF0000;
			zbuffer[vline.x + env->w * vline.end] = 100000000;
		}
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_floor_color2(t_vline vline, t_render2 render, t_env *env)
{
	int		coord;
	Uint32	*pixels;
	double	*zbuffer;

	(void)render;
	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (env->editor.select && vline.x == env->h_w && vline.start == env->h_h)
		{
			env->selected_wall1 = -1;
			env->selected_wall2 = -1;
			env->selected_floor = render.sector;
			env->selected_ceiling = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		if (env->editor.in_game && !env->editor.select && env->selected_floor == render.sector)
			pixels[coord] = blend_alpha(0xFF3F3D61, 0xFF00FF00, 128);
		else
			pixels[coord] = 0xFF3D3D61;
		zbuffer[coord] = 100000000;
		vline.start++;
	}
}

void	draw_floor2(t_sector sector, t_render2 render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = ft_max(0, render.current_floor);
	vline.end = env->ymax[vline.x];
	if (sector.floor_slope)
		draw_vline_floor_color2(vline, render, env);
	else
		draw_vline_floor2(sector, vline, render, env);
}
