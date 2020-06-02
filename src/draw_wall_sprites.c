/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:38:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_wall_sprite_pixel(t_drawer *drawer, int sprite, t_render *render,
t_env *env)
{
	Uint32		*sprite_pixels;

	sprite_pixels =
	env->sprite_textures[env->object_sprites[
	drawer->sector->wall_sprites[render->i].sprite[sprite]].texture].str;
	if (!env->options.lighting
		|| (!drawer->sector->brightness && !drawer->sector->intensity))
		env->sdl.texture_pixels[drawer->coord] = sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y];
	else if (!drawer->sector->brightness)
		env->sdl.texture_pixels[drawer->coord] =
		apply_light_color(sprite_pixels[(int)drawer->x + drawer->sprite_w
		* (int)drawer->y], drawer->sector->light_color,
		drawer->sector->intensity);
	else if (!drawer->sector->intensity)
		env->sdl.texture_pixels[drawer->coord] = apply_light_brightness(
		sprite_pixels[(int)drawer->x + drawer->sprite_w * (int)drawer->y],
		drawer->sector->brightness);
	else
		env->sdl.texture_pixels[drawer->coord] = apply_light_both(sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y],
		drawer->sector->light_color, drawer->sector->intensity,
		drawer->sector->brightness);
	apply_wall_sprite_filters(drawer, sprite, render, env);
	env->zbuffer[drawer->coord] = render->z;
}

int		draw_vline_sprite(int sprite, t_sector *sector, t_render *render,
t_env *env)
{
	Uint32		*sprite_pixels;
	t_drawer	drawer;

	drawer.sector = sector;
	init_drawer(&drawer, sprite, render, env);
	sprite_pixels = env->sprite_textures[env->object_sprites[
	sector->wall_sprites[render->i].sprite[sprite]].texture].str;
	while (++drawer.i <= render->current_floor)
	{
		drawer.coord = render->x + env->w * drawer.i;
		if (render->z >= env->zbuffer[drawer.coord])
			continue;
		drawer.yalpha = (drawer.i - render->no_slope_current_ceiling)
			/ render->line_height;
		drawer.y = (drawer.yalpha - drawer.pos) * render->camera->v[
		sector->num][render->i].sprite_scale[sprite].y + drawer.start;
		if (drawer.y >= drawer.start && drawer.y < drawer.end && sprite_pixels[
			(int)drawer.x + drawer.sprite_w * (int)drawer.y] != 0xFFC10099)
		{
			if (click_on_wall_sprite(&drawer, sprite, render, env))
				return (0);
			put_wall_sprite_pixel(&drawer, sprite, render, env);
		}
	}
	return (0);
}

int		draw_current_wall_sprite(int i, t_sector *sector, t_render *render,
t_env *env)
{
	t_point	start;
	t_point	end;
	double	pos;

	start = env->object_sprites[sector->wall_sprites[render->i].
	sprite[i]].start[0];
	end = env->object_sprites[sector->wall_sprites[render->i].
	sprite[i]].end[0];
	pos = (sector->wall_sprites[render->i].pos[i].x)
	/ sector->wall_width[render->i]
	* render->camera->v[sector->num][render->i].sprite_scale[i].x;
	if (render->camera->v[sector->num][render->i + 1].vz)
		pos *= render->camera->v[sector->num][render->i + 1].vz;
	else
		pos *= render->camera->v[sector->num][render->i].clipped_vz2;
	render->sprite_x = (render->alpha) * render->camera->v[sector->num]
	[render->i].sprite_scale[i].x * render->z + start.x - pos;
	if (render->sprite_x >= start.x && render->sprite_x < end.x)
	{
		if (draw_vline_sprite(i, sector, render, env))
			return (-1);
	}
	return (0);
}

int		draw_wall_sprites(t_sector *sector, t_render *render, t_env *env)
{
	int		i;

	i = 0;
	while (i < sector->wall_sprites[render->i].nb_sprites)
	{
		if (draw_current_wall_sprite(i, sector, render, env))
			return (-1);
		i++;
	}
	return (0);
}
