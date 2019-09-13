/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:18:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/13 11:10:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_wall(t_sector sector, t_vline vline, t_render2 render, t_env *env)
{
	int			i;
	double		yalpha;
	double		y;
	double		x;
	Uint32		*pixels;
	Uint32		*texture_pixels;
	double		*zbuffer;
	t_texture	texture;
	int			texture_w;
	int			texture_h;
	int			start_coord;
	int			end_coord;
	int			coord;

	texture = env->textures[render.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	x = render.alpha * sector.v[render.i].texture_scale.x * render.z;
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
		yalpha = (i - render.max_ceiling) / render.line_height;
		y = yalpha * sector.v[render.i].texture_scale.y;
		while (y >= texture_h)
			y -= texture_h;
		while (y < 0)
			y += texture_h;
		if (!env->options.lighting)
			pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
		else
			//pixels[coord] = blend_alpha(texture_pixels[(int)x + texture_w * (int)y], render.light_color, render.brightness);
			pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], sector.light_color, sector.brightness);
		//ft_printf("light = %d\n", render.light);
		if (env->editor.in_game && sector.v[render.i].selected && !env->editor.select)
			pixels[coord] = blend_alpha(pixels[coord], 0xFF00FF00, 128);
		zbuffer[coord] = render.z;
		//ft_printf("light = %d\n", (int)(255 * render.light));
		/*if (i == (int)render.floor_horizon)
		  pixels[coord] = 0xFF00FF00;*/
		/*if (i == (int)render.floor_horizon1)
		  pixels[coord] = 0xFF0000FF;
		  if (i == (int)render.floor_horizon2)
		  pixels[coord] = 0xFFFF0000;*/
		/*if (i == (int)render.ceiling_horizon)
		  pixels[coord] = 0xFFFF0000;*/
		i++;
	}
	if (env->options.zbuffer || env->options.contouring)
	{
		if (vline.start == (int)render.max_ceiling)
		{
			start_coord = vline.x + env->w * vline.start;
			pixels[start_coord] = 0xFFFF0000;
			zbuffer[start_coord] = 100000000;
		}
		if (vline.end == (int)render.max_floor)
		{
			end_coord = vline.x + env->w * vline.end;
			pixels[end_coord] = 0xFFFF0000;
			zbuffer[end_coord] = 100000000;
		}
	}
}

void		draw_wall(t_sector sector, t_render2 render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = render.current_ceiling;
	vline.end = render.current_floor;
	draw_vline_wall(sector, vline, render, env);
}

void		draw_upper_wall2(t_sector sector, t_render2 render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = render.current_ceiling;
	vline.end = render.neighbor_current_ceiling;
	draw_vline_wall(sector, vline, render, env);
}

void		draw_bottom_wall2(t_sector sector, t_render2 render, t_env *env)
{
	t_vline	vline;

	vline.x = render.x;
	vline.start = render.neighbor_current_floor;
	vline.end = render.current_floor;
	draw_vline_wall(sector, vline, render, env);
}
