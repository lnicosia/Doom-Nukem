/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 13:28:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling(t_sector sector, t_vline vline, t_render render,
		t_env *env)
{
	int		i;
	Uint32	*pixels;
	Uint32	*texture_pixels;
	double	*zbuffer;
	int		coord;
	double	y;
	double	x;
	double	z;
	double	alpha;
	double	divider;
	int		map_lvl;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	map_lvl = env->wall_textures[sector.ceiling_texture].nb_maps - 1;
	if (!env->options.show_minimap)
	{
		render.texture_w = env->wall_textures[sector.ceiling_texture].maps[map_lvl]->w;
		render.texture_h = env->wall_textures[sector.ceiling_texture].maps[map_lvl]->h;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		alpha = (render.max_ceiling - i) / render.ceiling_height;
		divider = 1 / (render.camera->near_z + alpha * render.zrange);
		z = render.z_near_z * divider;
		if (env->options.show_minimap)
			map_lvl = get_current_ceiling_map(sector.ceiling_texture, z, &render, env);
		texture_pixels = env->wall_textures[sector.ceiling_texture].
		maps[map_lvl]->pixels;
		if (z >= zbuffer[coord])
		{
			i++;
			continue;
		}
		if (env->editor.select && vline.x == env->h_w && i == env->h_h)
		{
			reset_selection(env);
			env->selected_ceiling = render.sector;
		}
		y = (render.texel_y_near_z + alpha * render.texel_y_camera_range)
			* divider;
		x = (render.texel_x_near_z + alpha * render.texel_x_camera_range)
			* divider;
		y = y * sector.ceiling_scale[map_lvl].y + sector.ceiling_align.y;
		x = x * sector.ceiling_scale[map_lvl].x + sector.ceiling_align.x;
		x = render.texture_w - x;
		if (y >= render.texture_h || y < 0)
			y = ft_abs((int)y % render.texture_h);
		if (x >= render.texture_w || x < 0)
			x = ft_abs((int)x % render.texture_w);
		if (x >= 0 && x < render.texture_w && y >= 0 && y < render.texture_h)
		{
			if (!env->options.lighting && !env->playing)
				pixels[coord] = texture_pixels[(int)x + render.texture_w * (int)y];
			else
				pixels[coord] = apply_light(texture_pixels[(int)x + render.texture_w * (int)y], sector.light_color, sector.brightness);
			if (env->editor.in_game && !env->editor.select
				&& env->selected_ceiling == render.sector
				&& env->selected_ceiling_sprite == -1)
				pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
			zbuffer[coord] = z;
			if (env->options.zbuffer || env->options.contouring)
				if (i == (int)(render.max_ceiling) || i == vline.start)
					pixels[vline.x + env->w * i] = 0xFFFF0000;
		}
		//pixels[coord] = apply_light(0xFAA2200, sector.light_color, sector.brightness);
		i++;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling_color(t_vline vline, t_render render, t_env *env)
{
	int		coord;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
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
			pixels[coord] = blend_alpha(0xFF3D3D61, 0x1ABC9C, 128);
		else
			pixels[coord] = 0xFF3D3D61;
		zbuffer[coord] = 100000000;
		vline.start++;
	}
}

void	draw_ceiling(t_sector sector, t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = env->ymin[vline.x];
	vline.end = ft_min(render.current_ceiling, env->ymax[vline.x]);
	/*if (sector.skybox)
		draw_skybox(render, 0, env);
	else
		draw_vline_ceiling(sector, vline, render, env);*/
	if (sector.ceiling_texture < 0)
	{
		//env->selected_skybox = abs(sector.ceiling_texture) - 1;
		draw_skybox(render, 0, env);
	}
	else
		draw_vline_ceiling(sector, vline, render, env);
}
