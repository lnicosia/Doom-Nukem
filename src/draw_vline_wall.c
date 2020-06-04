/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:43:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:13:20 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_wall_pixel_no_light(t_drawer *drawer, t_render *render, t_env *env)
{
	Uint32		*texture_pixels;

	texture_pixels =
	env->wall_textures[render->texture].maps[render->map_lvl]->pixels;
	env->sdl.texture_pixels[drawer->coord] =
	texture_pixels[(int)drawer->x + render->texture_w * (int)drawer->y];
	if (env->editor.in_game && drawer->sector->selected[render->i]
		&& !env->editor.select && !env->editor.select_portal)
		env->sdl.texture_pixels[drawer->coord] =
		blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C, 128);
	env->zbuffer[drawer->coord] = render->z;
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_wall(t_sector *sector, t_vline vline,
		t_render *render, t_env *env)
{
	t_drawer	drawer;

	drawer.sector = sector;
	drawer.vline = vline;
	if (get_wall_x(&drawer, render, env))
		return ;
	while (drawer.i < drawer.vline.end)
	{
		drawer.coord = drawer.vline.x + env->w * drawer.i;
		if (render->z >= env->zbuffer[drawer.coord])
		{
			drawer.i++;
			continue;
		}
		click_on_wall(&drawer, render, env);
		if (get_wall_y(&drawer, render))
			return ;
		put_wall_pixel_no_light(&drawer, render, env);
		drawer.i++;
	}
}
