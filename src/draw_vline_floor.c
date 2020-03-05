/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:50:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 18:23:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"

/*
 **	Draw a vertical vline on the screen at vline.x
 */

void	draw_vline_floor(t_sector sector, t_vline vline,
		t_render render, t_env *env)
{
	int		i;
	Uint32	*pixels;
	Uint32	*texture_pixels;
	double	*zbuffer;
	int		coord;
	double	y;
	double	x;
	double	text_y;
	double	text_x;
	double	z;
	double	alpha;
	double	divider;
	size_t	map_lvl;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	map_lvl = env->wall_textures[sector.floor_texture].nb_maps - 1;
	render.texture_w = env->wall_textures[sector.floor_texture].maps[map_lvl]->w;
	render.texture_h = env->wall_textures[sector.floor_texture].maps[map_lvl]->h;
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		alpha = (i - render.max_floor) / render.floor_height;
		divider = 1 / (render.camera->near_z + alpha * render.zrange);
		z = render.z_near_z * divider;
		if (z >= zbuffer[coord] - 1)
		{
			i++;
			continue;
		}
		if (env->options.mipmapping)
			map_lvl = get_current_floor_map(sector.floor_texture, z, &render, env);
		texture_pixels = (Uint32*)env->wall_textures[sector.floor_texture].
			maps[map_lvl]->pixels;
		y = (render.texel_y_near_z + alpha * render.texel_y_camera_range)
			* divider;
		x = (render.texel_x_near_z + alpha * render.texel_x_camera_range)
			* divider;
		text_y = y * sector.floor_scale[map_lvl].y + sector.floor_align[map_lvl].y;
		text_x = x * sector.floor_scale[map_lvl].x + sector.floor_align[map_lvl].x;
		text_y = render.texture_h - text_y;
		text_x = render.texture_w - text_x;
		if (text_y >= render.texture_h || text_y < 0)
			text_y = ft_abs((int)text_y % render.texture_h);
		if (text_x >= render.texture_w || text_x < 0)
			text_x = ft_abs((int)text_x % render.texture_w);
		if ((env->editor.tab && vline.x == env->sdl.mx && i == env->sdl.my)
		|| (!env->editor.tab && vline.x == env->h_w && i == env->h_h))
		{
			if (env->editor.select)
			{
				reset_selection(env);
				env->selected_floor = render.sector;
				tabs_gestion(env);
			}
			if (env->shooting
				&& z <= env->weapons[env->player.curr_weapon].range)
			{
				env->new_floor_bullet_hole = 1;
				env->new_bullet_hole_pos =
				new_v2(x, y);
				env->new_bullet_hole_sector = sector.num;
			}
			if (env->playing)
			{
				env->hovered_wall_sprite_wall = -1;
				env->hovered_wall_sprite_sprite = -1;
				env->hovered_wall_sprite_sector = -1;
			}
		}
		if (text_x >= 0 && text_x < render.texture_w && text_y >= 0 && text_y < render.texture_h)
		{
			pixels[coord] = texture_pixels[(int)text_x + render.texture_w * (int)text_y];
			if (env->editor.in_game && !env->editor.select
					&& env->selected_floor == render.sector
					&& env->selected_floor_sprite == -1)
				pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
			zbuffer[coord] = z;
		}
		i++;
	}
}
