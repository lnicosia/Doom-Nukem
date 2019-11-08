/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:37:03 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/08 10:43:18 by lnicosia         ###   ########.fr       */
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
	double		x;
	Uint32		*pixels;
	Uint32		*texture_pixels;
	double		*zbuffer;
	int			coord;

	pixels = env->sdl.texture_pixels;
	texture_pixels = env->textures[render.texture].str;
	zbuffer = env->zbuffer;
	yalpha = 0;
	coord = 0;
	x = 0;
	y = 0;
	x = render.alpha
		* render.camera->v[render.sector][render.i].texture_scale.x * render.z
		+ sector.align[render.i].x;
	if (x != x)
		return ;
	while (x >= render.texture_w)
		x -= render.texture_w;
	while (x < 0)
		x += render.texture_w;
	x = ft_fclamp(x, 0, render.texture_w);
	i = vline.start;
	while (i < vline.end)
	{
		coord = vline.x + env->w * i;
		if (render.z > zbuffer[coord])
		{
			i++;
			continue;
		}
		if (env->editor.select && vline.x == env->h_w && i == env->h_h)
		{
			reset_selection(env);
			env->editor.selected_sector = sector.num;
			env->editor.selected_wall = render.i;
			env->selected_wall1 = env->sectors[render.sector].vertices[render.i];
			env->selected_wall2 = env->sectors[render.sector].vertices[render.i + 1];
		}
		yalpha = (i - render.no_slope_current_ceiling) / render.line_height;
		y = yalpha * render.camera->v[render.sector][render.i].texture_scale.y
			+ sector.align[render.i].y;
		while (y >= render.texture_h)
			y -= render.texture_h;
		while (y < 0)
			y += render.texture_h;
		if (!env->options.lighting && !env->playing)
			pixels[coord] = texture_pixels[(int)x + render.texture_w * (int)y];
		else
			pixels[coord] = apply_light(texture_pixels[(int)x + render.texture_w * (int)y], sector.light_color, sector.brightness);
		if (env->editor.in_game && sector.selected[render.i] && !env->editor.select)
			pixels[coord] = blend_alpha(pixels[coord], 0xFF00FF00, 128);
		zbuffer[coord] = render.z;
		if (env->options.zbuffer || env->options.contouring)
			if (i == (int)(render.max_ceiling)
					|| i == (int)(render.neighbor_max_ceiling)
					|| i == (int)(render.max_floor)
					|| i == (int)(render.neighbor_max_floor))
				pixels[coord] = 0xFFFF0000;
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
	if (sector.neighbors[render.i] == -1 && sector.textures[render.i] != -1)
		vline.draw_wall = 1;
	else
		vline.draw_wall = 0;
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
	vline.draw_wall = 1;
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
	vline.draw_wall = 1;
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
