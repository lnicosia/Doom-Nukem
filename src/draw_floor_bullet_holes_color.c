/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_bullet_holes_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:48:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:36:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_current_floor_bullet_hole_color(t_drawer *drawer, t_env *env)
{
	Uint32		*sprite_pixels;

	sprite_pixels =
	(Uint32*)env->sprite_textures[drawer->sprite->texture].str;
	env->sdl.texture_pixels[drawer->coord] = apply_light_color(
	sprite_pixels[(int)drawer->sprite_x +
	env->sprite_textures[drawer->sprite->texture].surface->w
	* (int)drawer->sprite_y], drawer->sector->light_color,
	drawer->sector->intensity);
	env->zbuffer[drawer->coord] = drawer->z;
}

void	draw_floor_bullet_hole_color(t_bullet_hole *curr, t_drawer *drawer,
t_env *env)
{
	Uint32		*sprite_pixels;

	drawer->sprite =
	&env->object_sprites[BULLET_HOLE];
	sprite_pixels =
	(Uint32*)env->sprite_textures[drawer->sprite->texture].str;
	drawer->sprite_x = (drawer->x - curr->pos.x)
	* curr->scale.x + drawer->sprite->start[0].x;
	drawer->sprite_y = (drawer->y - curr->pos.y)
	* curr->scale.y + drawer->sprite->start[0].y;
	if (drawer->sprite_x >= drawer->sprite->start[0].x
		&& drawer->sprite_x < drawer->sprite->end[0].x
		&& drawer->sprite_y >= drawer->sprite->start[0].y
		&& drawer->sprite_y < drawer->sprite->end[0].y
		&& sprite_pixels[(int)drawer->sprite_x
		+ env->sprite_textures[drawer->sprite->texture].surface->w
		* (int)drawer->sprite_y] != 0xFFC10099)
		draw_current_floor_bullet_hole_color(drawer, env);
}

void	draw_floor_bullet_holes_color(t_sector *sector, t_drawer *drawer,
t_env *env)
{
	t_bullet_hole	*curr;
	t_list			*bullet_holes;

	bullet_holes = sector->floor_bullet_holes;
	while (bullet_holes)
	{
		curr = (t_bullet_hole*)bullet_holes->content;
		draw_floor_bullet_hole_color(curr, drawer, env);
		bullet_holes = bullet_holes->next;
	}
}
