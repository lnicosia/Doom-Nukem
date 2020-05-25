/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bullet_holes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:36:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	put_wall_bullet_hole_pixel(t_drawer *drawer, t_render *render,
t_env *env)
{
	Uint32		*sprite_pixels;

	sprite_pixels = env->sprite_textures[8].str;
	if (!env->options.lighting
		|| (!drawer->sector->brightness && !drawer->sector->intensity))
		env->sdl.texture_pixels[drawer->coord] = sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y];
	else if (!drawer->sector->brightness)
		env->sdl.texture_pixels[drawer->coord] =
		apply_light_color(sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y],
		drawer->sector->light_color, drawer->sector->intensity);
	else if (!drawer->sector->intensity)
		env->sdl.texture_pixels[drawer->coord] =
		apply_light_brightness(sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y],
		drawer->sector->brightness);
	else
		env->sdl.texture_pixels[drawer->coord] =
		apply_light_both(sprite_pixels[
		(int)drawer->x + drawer->sprite_w * (int)drawer->y],
		drawer->sector->light_color, drawer->sector->intensity,
		drawer->sector->brightness);
	env->zbuffer[drawer->coord] = render->z;
}

void	draw_vline_bullet_hole(t_bullet_hole *curr, t_sector *sector,
t_render *render, t_env *env)
{
	t_drawer	drawer;
	Uint32		*sprite_pixels;

	sprite_pixels = env->sprite_textures[8].str;
	drawer.sector = sector;
	drawer.i = render->current_ceiling - 1;
	drawer.sprite_w = env->sprite_textures[8].surface->w;
	drawer.pos = curr->pos.y / (sector->ceiling - sector->floor);
	drawer.start = env->object_sprites[BULLET_HOLE].start[0].y;
	drawer.end = env->object_sprites[BULLET_HOLE].end[0].y;
	drawer.x = render->sprite_x;
	while (++drawer.i <= render->current_floor)
	{
		drawer.coord = render->x + env->w * drawer.i;
		if (render->z >= env->zbuffer[drawer.coord])
			continue;
		drawer.yalpha = (drawer.i - render->no_slope_current_ceiling)
		/ render->line_height;
		drawer.y = (drawer.yalpha - drawer.pos) * curr->scale.y + drawer.start;
		if (drawer.y >= drawer.start && drawer.y < drawer.end
			&& sprite_pixels[(int)drawer.x
			+ drawer.sprite_w * (int)drawer.y] != 0xFFC10099)
			put_wall_bullet_hole_pixel(&drawer, render, env);
	}
}

void	draw_wall_bullet_holes(t_sector *sector, t_render *render, t_env *env)
{
	t_point			start;
	t_point			end;
	t_bullet_hole	*curr;
	t_list			*bullet_holes;
	double			pos;

	bullet_holes = sector->wall_bullet_holes[render->i];
	while (bullet_holes)
	{
		curr = (t_bullet_hole*)bullet_holes->content;
		start = env->object_sprites[BULLET_HOLE].start[0];
		end = env->object_sprites[BULLET_HOLE].end[0];
		pos = curr->pos.x / sector->wall_width[render->i]
		* curr->scale.x;
		if (render->camera->v[sector->num][render->i + 1].vz)
			pos *= render->camera->v[sector->num][render->i + 1].vz;
		else
			pos *= render->camera->v[sector->num][render->i].clipped_vz2;
		render->sprite_x = (render->alpha) * curr->scale.x
		* render->z + start.x - pos;
		if (render->sprite_x >= start.x && render->sprite_x < end.x)
			draw_vline_bullet_hole(curr, sector, render, env);
		bullet_holes = bullet_holes->next;
	}
}
