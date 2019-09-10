/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 18:48:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling2(t_sector sector, t_vline vline, t_render2 render,
		t_env *env)
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
	texture_w = env->textures[sector.ceiling_texture].surface->w;
	texture_h = env->textures[sector.ceiling_texture].surface->h;
	texture_pixels = env->textures[sector.ceiling_texture].str;
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		alpha = render.ceiling_start / (double)(i - render.ceiling_horizon);
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
			env->selected_ceiling = render.sector;
			env->selected_floor = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.camera_y;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.camera_x;
		y *= sector.ceiling_scale.y;
		x *= sector.ceiling_scale.x;
		if (y >= texture_h || y < 0)
			y = ft_abs((int)y % texture_h);
		if (x >= texture_w || x < 0)
			x = ft_abs((int)x % texture_w);
		x = texture_w - x;
		if (x >= 0 && x < texture_w && y >= 0 && y < texture_h)
		{
			if (!env->options.lighting)
				pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
			else
				//pixels[coord] = blend_alpha(texture_pixels[(int)x + texture_w * (int)y], render.light_color, render.brightness);
				pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], render.light_color, sector.brightness);
			if (env->editor.in_game && !env->editor.select && env->selected_ceiling == render.sector)
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
		if (vline.start >= 0 && vline.start < env->h - 1)
		{
			pixels[vline.x + env->w * vline.start] = 0xFFFF0000;
			zbuffer[vline.x + env->w * vline.start] = 100000000;
		}
		if (vline.end == (int)render.max_ceiling - 1
				&& vline.end >= 0 && vline.end < env->h)
		{
			pixels[vline.x + env->w * vline.end] = 0xFFFF0000;
			zbuffer[vline.x + env->w * vline.end] = 100000000;
		}
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling_color2(t_vline vline, t_render2 render, t_env *env)
{
	int		coord;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (env->editor.select && vline.x == env->h_w && vline.start == env->h_h)
		{
			env->selected_wall1 = -1;
			env->selected_wall2 = -1;
			env->selected_ceiling = render.sector;
			env->selected_floor = -1;
			env->selected_object = -1;
			env->selected_enemy = -1;
			env->editor.selected_wall = -1;
		}
		if (env->editor.in_game && !env->editor.select && env->selected_floor == render.sector)
			pixels[coord] = blend_alpha(vline.color, 0xFF00FF00, 128);
		else
			pixels[coord] = vline.color;
		zbuffer[coord] = 100000000;
		vline.start++;
	}
}

void	draw_ceiling2(t_sector sector, t_render2 render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = env->ymin[vline.x];
	vline.end = ft_min(render.current_ceiling, env->ymax[vline.x]);
	if (sector.skybox)
		draw_skybox2(render, env);
	else if (sector.ceiling_slope)
		draw_vline_ceiling_color2(vline, render, env);
	else
		draw_vline_ceiling2(sector, vline, render, env);
}
