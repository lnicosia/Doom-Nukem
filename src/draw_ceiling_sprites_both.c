/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_sprites_both.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:22:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_current_ceiling_sprite_both(int j, t_render *render,
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
		env->selected_ceiling = drawer->sector->num;
		env->selected_ceiling_sprite = j;
		tabs_gestion(env);
	}
	env->sdl.texture_pixels[drawer->coord] = apply_light_both(
	sprite_pixels[(int)drawer->sprite_x +
	env->sprite_textures[drawer->sprite->texture].surface->w
	* (int)drawer->sprite_y], drawer->sector->light_color,
	drawer->sector->intensity, drawer->sector->brightness);
	if (!env->editor.select && env->selected_ceiling == drawer->sector->num
		&& env->selected_ceiling_sprite == j)
		env->sdl.texture_pixels[drawer->coord] =
		blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C,
		128);
	env->zbuffer[drawer->coord] = drawer->z;
}

void	draw_ceiling_sprite_both(int j, t_render *render,
t_drawer *drawer, t_env *env)
{
	Uint32		*sprite_pixels;

	drawer->sprite =
	&env->object_sprites[drawer->sector->ceiling_sprites.sprite[j]];
	sprite_pixels =
	(Uint32*)env->sprite_textures[drawer->sprite->texture].str;
	drawer->sprite_x = (drawer->x - drawer->sector->ceiling_sprites.pos[j].x)
	* drawer->sector->ceiling_sprites_scale[j].x + drawer->sprite->start[0].x;
	drawer->sprite_y = (drawer->y - drawer->sector->ceiling_sprites.pos[j].y)
	* drawer->sector->ceiling_sprites_scale[j].y + drawer->sprite->start[0].y;
	if (drawer->sprite_x >= drawer->sprite->start[0].x
		&& drawer->sprite_x < drawer->sprite->end[0].x
		&& drawer->sprite_y >= drawer->sprite->start[0].y
		&& drawer->sprite_y < drawer->sprite->end[0].y
		&& sprite_pixels[(int)drawer->sprite_x
		+ env->sprite_textures[drawer->sprite->texture].surface->w
		* (int)drawer->sprite_y] != 0xFFC10099)
		draw_current_ceiling_sprite_both(j, render, drawer, env);
}

void	draw_ceiling_sprites_both(t_sector *sector, t_render *render,
t_env *env)
{
	int			j;
	t_drawer	drawer;

	drawer.i = env->ymin[render->x];
	drawer.end = ft_min(render->current_ceiling, env->ymax[render->x]);
	drawer.sector = sector;
	while (drawer.i <= drawer.end)
	{
		get_ceiling_z(render, &drawer, env);
		if (drawer.z >= env->zbuffer[drawer.coord])
		{
			drawer.i++;
			continue;
		}
		get_texels(render, &drawer);
		j = 0;
		while (j < sector->ceiling_sprites.nb_sprites)
		{
			draw_ceiling_sprite_both(j, render, &drawer, env);
			j++;
		}
		draw_ceiling_bullet_holes_both(sector, &drawer, env);
		drawer.i++;
	}
}
