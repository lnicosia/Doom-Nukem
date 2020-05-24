/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_projectile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:36:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:36:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_vline_projectile_both(t_render_projectile *prender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->yalpha = (drawer->y - prender->y1) / prender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[prender->index].y + drawer->yalpha
	* drawer->sprite->end[prender->index].y;
	if ((drawer->projectile->rotated_pos.z < env->zbuffer[drawer->x
		+ drawer->y * env->w] && drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_both(drawer->texture->str[drawer->textx + drawer->texty
		* drawer->texture->surface->w], prender->light_color,
		prender->intensity, prender->brightness);
		env->zbuffer[drawer->x + drawer->y * env->w] =
		drawer->projectile->rotated_pos.z;
	}
}

void	draw_vline_projectile_brightness(t_render_projectile *prender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->yalpha = (drawer->y - prender->y1) / prender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[prender->index].y + drawer->yalpha
	* drawer->sprite->end[prender->index].y;
	if ((drawer->projectile->rotated_pos.z < env->zbuffer[drawer->x
		+ drawer->y * env->w] && drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_brightness(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w], prender->brightness);
		env->zbuffer[drawer->x + drawer->y * env->w] =
		drawer->projectile->rotated_pos.z;
	}
}

void	draw_vline_projectile_color(t_render_projectile *prender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->yalpha = (drawer->y - prender->y1) / prender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[prender->index].y + drawer->yalpha
	* drawer->sprite->end[prender->index].y;
	if ((drawer->projectile->rotated_pos.z < env->zbuffer[drawer->x
		+ drawer->y * env->w] && drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_color(drawer->texture->str[drawer->textx + drawer->texty
		* drawer->texture->surface->w], prender->light_color,
		prender->intensity);
		env->zbuffer[drawer->x + drawer->y * env->w] =
		drawer->projectile->rotated_pos.z;
	}
}

void	draw_vline_projectile_no_light(t_render_projectile *prender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->yalpha = (drawer->y - prender->y1) / prender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[prender->index].y + drawer->yalpha
	* drawer->sprite->end[prender->index].y;
	if ((drawer->projectile->rotated_pos.z < env->zbuffer[drawer->x
		+ drawer->y * env->w] && drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		drawer->texture->str[drawer->textx + drawer->texty
		* drawer->texture->surface->w];
		env->zbuffer[drawer->x + drawer->y * env->w] =
		drawer->projectile->rotated_pos.z;
	}
}

void	get_projectile_x(t_render_projectile *prender, t_sprite_drawer *drawer)
{
	drawer->xalpha = (drawer->x - prender->x1) / prender->xrange;
	if (drawer->sprite->reversed[prender->index])
		drawer->xalpha = 1.0 - drawer->xalpha;
	drawer->textx = (1.0 - drawer->xalpha)
	* drawer->sprite->start[prender->index].x + drawer->xalpha
	* drawer->sprite->end[prender->index].x;
	drawer->y = prender->ystart;
}
