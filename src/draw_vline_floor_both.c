/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_floor_both.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:52:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 18:23:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_floor_pixel_both(t_drawer *drawer, t_render *render, t_env *env)
{
  	Uint32	*texture_pixels;

	texture_pixels = (Uint32*)env->wall_textures[drawer->sector->floor_texture].
	maps[drawer->map_lvl]->pixels;
	if (drawer->text_x >= 0 && drawer->text_x < render->texture_w
	  	&& drawer->text_y >= 0 && drawer->text_y < render->texture_h)
	{
		env->sdl.texture_pixels[drawer->coord] = apply_light_both(
		texture_pixels[(int)drawer->text_x + render->texture_w
		* (int)drawer->text_y], drawer->sector->light_color,
		drawer->sector->intensity, drawer->sector->brightness);
		if (env->editor.in_game && !env->editor.select
				&& env->selected_floor == render->sector
				&& env->selected_floor_sprite == -1)
			env->sdl.texture_pixels[drawer->coord] =
			blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C, 128);
		env->zbuffer[drawer->coord] = drawer->z;
	}
}

/*
 **	Draw a vertical vline on the screen at vline.x
 */

void	draw_vline_floor_both(t_sector *sector, t_vline vline,
		t_render *render, t_env *env)
{
  	t_drawer	drawer;

	drawer.sector = sector;
	drawer.vline = vline;
	drawer.map_lvl =
	env->wall_textures[drawer.sector->floor_texture].nb_maps - 1;
	render->texture_w =
	env->wall_textures[drawer.sector->floor_texture].maps[drawer.map_lvl]->w;
	render->texture_h =
	env->wall_textures[drawer.sector->floor_texture].maps[drawer.map_lvl]->h;
	drawer.i = vline.start;
	while (drawer.i <= drawer.vline.end)
	{
	  	get_floor_z(render, &drawer, env);
		if (drawer.z >= env->zbuffer[drawer.coord] - 1)
		{
			drawer.i++;
			continue;
		}
		get_floor_texels(&drawer, render, env);
		click_on_floor(&drawer, render, env);
		put_floor_pixel_both(&drawer, render, env);
		drawer.i++;
	}
}
