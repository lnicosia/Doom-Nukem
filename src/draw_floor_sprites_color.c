/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_sprites_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:49:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:18:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_current_floor_sprite_color(int j, t_render *render,
t_drawer *drawer, t_env *env)
{
	Uint32		*sprite_pixels;

	sprite_pixels =
	(Uint32*)env->sprite_textures[drawer->sprite->texture].str;
	if (env->editor.select && ((env->editor.tab
	&& render->x == env->sdl.mx && drawer->i == env->sdl.my)
	|| (!env->editor.tab && render->x == env->h_w
	&& drawer->i == env->h_h)))
	{
		reset_selection(env);
		env->selected_floor = drawer->sector->num;
		env->selected_floor_sprite = j;
		tabs_gestion(env);
	}
	env->sdl.texture_pixels[drawer->coord] =
	apply_light_color(sprite_pixels[(int)drawer->sprite_x
	+ env->sprite_textures[drawer->sprite->texture].surface->w
	* (int)drawer->sprite_y], drawer->sector->light_color,
	drawer->sector->intensity);
	if (!env->editor.select && env->selected_floor == drawer->sector->num
		&& env->selected_floor_sprite == j)
		env->sdl.texture_pixels[drawer->coord] =
		blend_alpha(env->sdl.texture_pixels[drawer->coord],
		0x1abc9c, 128);
	env->zbuffer[drawer->coord] = drawer->z;
}

void	draw_floor_sprite_color(int j, t_render *render, t_drawer *drawer,
t_env *env)
{
	Uint32		*sprite_pixels;

	drawer->sprite =
	&env->object_sprites[drawer->sector->floor_sprites.sprite[j]];
	sprite_pixels =
	(Uint32*)env->sprite_textures[drawer->sprite->texture].str;
	drawer->sprite_x = (drawer->x - drawer->sector->floor_sprites.pos[j].x)
	* drawer->sector->floor_sprites_scale[j].x
	+ drawer->sprite->start[0].x;
	drawer->sprite_y = (drawer->y - drawer->sector->floor_sprites.pos[j].y)
	* drawer->sector->floor_sprites_scale[j].y
	+ drawer->sprite->start[0].y;
	if (drawer->sprite_x >= drawer->sprite->start[0].x
		&& drawer->sprite_x < drawer->sprite->end[0].x
		&& drawer->sprite_y >= drawer->sprite->start[0].y
		&& drawer->sprite_y < drawer->sprite->end[0].y
		&& sprite_pixels[(int)drawer->sprite_x
		+ env->sprite_textures[drawer->sprite->texture].surface->w
		* (int)drawer->sprite_y] != 0xFFC10099)
		draw_current_floor_sprite_color(j, render, drawer, env);
}

void	draw_floor_sprites_color(t_sector *sector, t_render *render, t_env *env)
{
	int			j;
	t_drawer	drawer;

	drawer.i = ft_max(0, (int)render->current_floor);
	drawer.end = env->ymax[render->x];
	drawer.sector = sector;
	while (drawer.i <= drawer.end)
	{
		get_floor_z(render, &drawer, env);
		if (drawer.z >= env->zbuffer[drawer.coord])
		{
			drawer.i++;
			continue;
		}
		get_texels(render, &drawer);
		j = 0;
		while (j < drawer.sector->floor_sprites.nb_sprites)
		{
			draw_floor_sprite_color(j, render, &drawer, env);
			j++;
		}
		draw_floor_bullet_holes_color(sector, &drawer, env);
		drawer.i++;
	}
}
