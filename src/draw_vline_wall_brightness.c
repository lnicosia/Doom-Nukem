/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_wall_brightness.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:42:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 15:39:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
 **	Draw a vertical vline on the screen at vline.x
 */

void	draw_vline_wall_brightness(t_sector sector, t_vline vline,
t_render render, t_env *env)
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
	if (env->options.show_minimap)
	{
		//ft_printf("{cyan}[WALL]{reset}\n");
		render.map_lvl = get_current_wall_map(render.texture, render.z, &render, env);
	}
	texture_pixels = env->wall_textures[render.texture].maps[render.map_lvl]->pixels;
	zbuffer = env->zbuffer;
	yalpha = 0;
	coord = 0;
	x = 0;
	y = 0;
	/*y = render.alpha
		* render.camera->v[render.sector][render.i].texture_scale.x * render.z
		+ sector.align[render.i].x;
	if (y != y)
		return ;
	while (y >= render.texture_h)
		y -= render.texture_h;
	while (y < 0)
		y += render.texture_h;
	y = ft_fclamp(y, 0, render.texture_h);*/
	x = render.alpha
		* render.camera->v[render.sector][render.i]
		.texture_scale[render.map_lvl].x * render.z
		- render.camera->v[render.sector][render.i]
		.texture_align[render.map_lvl].x;
	if (x != x)
		return ;
	/*while (x >= render.texture_w)
		x -= render.texture_w;
	while (x < 0)
		x += render.texture_w;*/
	if (x >= render.texture_w || x < 0)
		x = ft_abs((int)x % render.texture_w);
	x = ft_fclamp(x, 0, render.texture_w);
	i = vline.start;
	//ft_printf("map lvl = %d\n", render.map_lvl);
	//ft_printf("texture_w = %d\n", render.texture_w);
	//ft_printf("texture_h = %d\n", render.texture_h);
	//ft_printf("first pixel = 0x%X\n", texture_pixels[0]);
	//ft_printf("x = %d\n", (int)x);
	while (i < vline.end)
	{
		coord = vline.x + env->w * i;
		if (render.z >= zbuffer[coord])
		{
			i++;
			continue;
		}
		if ((env->editor.tab && vline.x == env->sdl.mx && i == env->sdl.my)
		|| (!env->editor.tab && vline.x == env->h_w && i == env->h_h))
		{
			if (env->editor.select)
			{
				reset_selection(env);
				env->editor.selected_sector = sector.num;
				env->editor.selected_wall = render.i;
				env->selected_wall1
				= env->sectors[render.sector].vertices[render.i];
				env->selected_wall2
				= env->sectors[render.sector].vertices[render.i + 1];
				env->editor.general_tab.state = DOWN;
				env->editor.general_tab.anim_state = PRESSED;
				new_tabs_position(env);
				check_event_creation(env);
			}
			if (env->playing)
			{
				env->hovered_wall_sprite_wall = -1;
				env->hovered_wall_sprite_sprite = -1;
				env->hovered_wall_sprite_sector = -1;
			}
		}
		yalpha = (i - render.no_slope_current_ceiling) / render.line_height;
		/*x = yalpha * render.camera->v[render.sector][render.i].texture_scale.y
			+ sector.align[render.i].y;
		while (x >= render.texture_w)
			x -= render.texture_w;
		while (x < 0)
			x += render.texture_w;*/
		y = yalpha * render.camera->v[render.sector][render.i]
		.texture_scale[render.map_lvl].y
		- render.camera->v[render.sector][render.i]
		.texture_align[render.map_lvl].y;
		/*while (y >= render.texture_h)
			y -= render.texture_h;
		while (y < 0)
			y += render.texture_h;*/
		if (y >= render.texture_h || y < 0)
			y = ft_abs((int)y % render.texture_h);
		//ft_printf("y = %d\n", (int)y);
			pixels[coord] = apply_light_brightness(texture_pixels[(int)x
			+ render.texture_w * (int)y], sector.brightness);
		if (env->editor.in_game && sector.selected[render.i] && !env->editor.select)
			pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
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
