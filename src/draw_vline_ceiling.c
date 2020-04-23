/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:56 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/10 16:50:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_ceiling_pixel_no_light(t_drawer *drawer, t_render *render,
t_env *env)
{
  	Uint32		*texture_pixels;

	texture_pixels = env->wall_textures[drawer->sector->ceiling_texture].
	maps[drawer->map_lvl]->pixels;
	if (drawer->text_x >= 0 && drawer->text_x < render->texture_w
	  	&& drawer->text_y >= 0 && drawer->text_y < render->texture_h)
	{
		env->sdl.texture_pixels[drawer->coord] = texture_pixels[
		(int)drawer->text_x + render->texture_w * (int)drawer->text_y];
		if (env->editor.in_game && !env->editor.select
			&& env->selected_ceiling == render->sector->num
			&& env->selected_ceiling_sprite == -1)
			env->sdl.texture_pixels[drawer->coord] =
			blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C, 128);
		env->zbuffer[drawer->coord] = drawer->z;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling(t_sector *sector, t_vline vline, t_render *render,
		t_env *env)
{
	t_drawer	drawer;

	drawer.sector = sector;
	drawer.vline = vline;
	drawer.map_lvl =
	env->wall_textures[drawer.sector->ceiling_texture].nb_maps - 1;
	render->texture_w =
	env->wall_textures[drawer.sector->ceiling_texture].maps[drawer.map_lvl]->w;
	render->texture_h =
	env->wall_textures[drawer.sector->ceiling_texture].maps[drawer.map_lvl]->h;
	drawer.i = vline.start;
	while (drawer.i <= vline.end)
	{
	  	get_ceiling_z(render, &drawer, env);
		if (drawer.z >= env->zbuffer[drawer.coord] - 1)
		{
			drawer.i++;
			continue;
		}
		get_ceiling_texels(&drawer, render, env);
		click_on_ceiling(&drawer, render, env);
		put_ceiling_pixel_no_light(&drawer, render, env);
		drawer.i++;
	}
}
