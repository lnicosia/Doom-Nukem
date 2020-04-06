/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_sprites_both.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:54:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:52:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	get_ceiling_z(t_render *render, t_drawer *drawer, t_env *env)
{
	drawer->coord = render->x + env->w * drawer->i;
	drawer->alpha =
	(render->max_ceiling - drawer->i) / render->ceiling_height;
	drawer->divider = 1 / (render->camera->near_z + drawer->alpha
	* render->zrange);
	drawer->z = render->z_near_z * drawer->divider;
}

void	get_ceiling_texels(t_render *render, t_drawer *drawer)
{
	drawer->y = (render->texel_y_near_z + drawer->alpha
	* render->texel_y_camera_range) * drawer->divider;
	drawer->x = (render->texel_x_near_z + drawer->alpha
	* render->texel_x_camera_range) * drawer->divider;
}

void	draw_ceiling_sprite_both(int j, t_render *render,
t_drawer *drawer, t_env *env)
{
  	t_sprite	*sprite;
	Uint32*		sprite_pixels;

	sprite = &env->object_sprites[drawer->sector->ceiling_sprites.sprite[j]];
	sprite_pixels =
	(Uint32*)env->sprite_textures[sprite->texture].str;
	drawer->sprite_x = (drawer->x - drawer->sector->ceiling_sprites.pos[j].x)
	* drawer->sector->ceiling_sprites_scale[j].x + sprite->start[0].x;
	drawer->sprite_y = (drawer->y - drawer->sector->ceiling_sprites.pos[j].y)
		* drawer->sector->ceiling_sprites_scale[j].y + sprite->start[0].y;
	if (drawer->sprite_x >= sprite->start[0].x
	  	&& drawer->sprite_x < sprite->end[0].x
		&& drawer->sprite_y >= sprite->start[0].y
		&& drawer->sprite_y < sprite->end[0].y
		&& sprite_pixels[(int)drawer->sprite_x
		+ env->sprite_textures[sprite->texture].surface->w
		* (int)drawer->sprite_y] != 0xFFC10099)
	{
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
		env->sprite_textures[sprite->texture].surface->w
		* (int)drawer->sprite_y], drawer->sector->light_color,
		drawer->sector->intensity, drawer->sector->brightness);
		if (!env->editor.select && env->selected_ceiling == drawer->sector->num
			&& env->selected_ceiling_sprite == j)
			env->sdl.texture_pixels[drawer->coord] =
			blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C,
			128);
		env->zbuffer[drawer->coord] = drawer->z;
		//break;
	}
}

void	draw_ceiling_sprites_both(t_sector *sector, t_render *render,
t_env *env)
{
	int			j;
	Uint32*		sprite_pixels;
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
		get_ceiling_texels(render, &drawer);
		j = 0;
		while (j < sector->ceiling_sprites.nb_sprites)
		{
		  	//draw_ceiling_sprite_both(j, render, &drawer, env);
			drawer.sprite =
			&env->object_sprites[sector->ceiling_sprites.sprite[j]];
			sprite_pixels =
			(Uint32*)env->sprite_textures[drawer.sprite->texture].str;
			drawer.sprite_x = (drawer.x - sector->ceiling_sprites.pos[j].x)
				* sector->ceiling_sprites_scale[j].x + drawer.sprite->start[0].x;
			drawer.sprite_y = (drawer.y - sector->ceiling_sprites.pos[j].y)
				* sector->ceiling_sprites_scale[j].y + drawer.sprite->start[0].y;
			if (drawer.sprite_x >= drawer.sprite->start[0].x
			  && drawer.sprite_x < drawer.sprite->end[0].x
				&& drawer.sprite_y >= drawer.sprite->start[0].y
				&& drawer.sprite_y < drawer.sprite->end[0].y
				&& sprite_pixels[(int)drawer.sprite_x
				+ env->sprite_textures[drawer.sprite->texture].surface->w
				* (int)drawer.sprite_y] != 0xFFC10099)
			{
				if (env->editor.select && ((env->editor.tab
				&& render->x == env->sdl.mx && drawer.i == env->sdl.my)
				|| (!env->editor.tab && render->x == env->h_w
				&& drawer.i == env->h_h)))
				{
					reset_selection(env);
					env->selected_ceiling = sector->num;
					env->selected_ceiling_sprite = j;
					tabs_gestion(env);
				}
				env->sdl.texture_pixels[drawer.coord] = apply_light_both(
				sprite_pixels[(int)drawer.sprite_x +
				env->sprite_textures[drawer.sprite->texture].surface->w
				* (int)drawer.sprite_y], sector->light_color, sector->intensity,
				sector->brightness);
				if (!env->editor.select && env->selected_ceiling == sector->num
					&& env->selected_ceiling_sprite == j)
					env->sdl.texture_pixels[drawer.coord] =
					blend_alpha(env->sdl.texture_pixels[drawer.coord], 0x1ABC9C,
					128);
				env->zbuffer[drawer.coord] = drawer.z;
				//break;
			}
			j++;
		}
		drawer.i++;
	}
}
