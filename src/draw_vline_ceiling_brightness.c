/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_ceiling_brightness.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:25:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:46:32 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling_brightness(t_sector sector, t_vline vline,
t_render render, t_env *env)
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
	render.texture_w = env->wall_textures[sector.ceiling_texture].maps[map_lvl]->w;
	render.texture_h = env->wall_textures[sector.ceiling_texture].maps[map_lvl]->h;
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		alpha = (render.max_ceiling - i) / render.ceiling_height;
		divider = 1 / (render.camera->near_z + alpha * render.zrange);
		z = render.z_near_z * divider;
		if (z >= zbuffer[coord] - 1)
		{
			i++;
			continue;
		}
		if (env->options.mipmapping)
			map_lvl = get_current_ceiling_map(sector.ceiling_texture, z, &render, env);
		texture_pixels = env->wall_textures[sector.ceiling_texture].
		maps[map_lvl]->pixels;
		if ((env->editor.tab && vline.x == env->sdl.mx && i == env->sdl.my)
		|| (!env->editor.tab && vline.x == env->h_w && i == env->h_h))
		{
			if (env->editor.select)
			{
				reset_selection(env);
				env->selected_ceiling = render.sector;
				tabs_gestion(env);
			}
			if (env->playing)
			{
				env->hovered_wall_sprite_wall = -1;
				env->hovered_wall_sprite_sprite = -1;
				env->hovered_wall_sprite_sector = -1;
			}
		}
		y = (render.texel_y_near_z + alpha * render.texel_y_camera_range)
			* divider;
		x = (render.texel_x_near_z + alpha * render.texel_x_camera_range)
			* divider;
		y = y * sector.ceiling_scale[map_lvl].y + sector.ceiling_align[map_lvl].y;
		x = x * sector.ceiling_scale[map_lvl].x + sector.ceiling_align[map_lvl].x;
		x = render.texture_w - x;
		if (y >= render.texture_h || y < 0)
			y = ft_abs((int)y % render.texture_h);
		if (x >= render.texture_w || x < 0)
			x = ft_abs((int)x % render.texture_w);
		if (x >= 0 && x < render.texture_w && y >= 0 && y < render.texture_h)
		{
			pixels[coord] = apply_light_brightness(texture_pixels[(int)x + render.texture_w * (int)y], sector.brightness);
			if (env->editor.in_game && !env->editor.select
				&& env->selected_ceiling == render.sector
				&& env->selected_ceiling_sprite == -1)
				pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
			zbuffer[coord] = z;
		}
		i++;
	}
}
