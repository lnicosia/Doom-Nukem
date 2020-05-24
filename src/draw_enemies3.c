/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:14:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:14:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "enemies.h"

void	update_enemies_z(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == env->sectors[env->selected_floor].num)
			env->enemies[i].pos.z =
			get_floor_at_pos(&env->sectors[env->selected_floor],
			new_v3(env->enemies[i].pos.x, env->enemies[i].pos.y, 0), env);
		i++;
	}
}

void	apply_enemy_filters(t_sprite_drawer *drawer, t_env *env)
{
	if (env->enemies[drawer->enemy->num].hit)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		blend_alpha(env->sdl.texture_pixels[drawer->x + drawer->y
		* env->w], 0xFFFF0000, enemy_hurt(env, drawer->enemy->num));
	if (!env->editor.select
		&& env->selected_enemy == drawer->enemy->num)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		blend_alpha(env->sdl.texture_pixels[drawer->x + drawer->y
		* env->w], 0x1abc9c, 128);
}

void	put_enemy_pixel(t_render_object *orender,
t_sprite_drawer *drawer, t_env *env)
{
	if (!env->options.lighting || (!drawer->sector->brightness
		&& !drawer->sector->intensity))
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		drawer->texture->str[drawer->textx + drawer->texty
		* drawer->texture->surface->w];
	else if (!drawer->sector->brightness)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_color(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->light_color, orender->intensity);
	else if (!drawer->sector->intensity)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_brightness(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->brightness);
	else
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_both(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->light_color, orender->intensity,
		orender->brightness);
	apply_enemy_filters(drawer, env);
	env->zbuffer[drawer->x + drawer->y * env->w] =
	drawer->enemy->rotated_pos.z;
}

void	get_sprite_x(t_render_object *orender, t_sprite_drawer *drawer)
{
	drawer->xalpha = (drawer->x - orender->x1) / orender->xrange;
	if (drawer->sprite->reversed[orender->index])
		drawer->xalpha = 1.0 - drawer->xalpha;
	drawer->textx =
	(1.0 - drawer->xalpha) * drawer->sprite->start[orender->index].x
	+ drawer->xalpha * drawer->sprite->end[orender->index].x;
	drawer->y = orender->ystart;
}

void	draw_vline_enemy(t_render_object *orender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->yalpha = (drawer->y - orender->y1) / orender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[orender->index].y + drawer->yalpha
	* drawer->sprite->end[orender->index].y;
	if ((drawer->enemy->rotated_pos.z < env->zbuffer[
		drawer->x + drawer->y * env->w]
		&& drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		env->enemies[drawer->enemy->num].seen = 1;
		if ((env->editor.tab && env->editor.select == 1
			&& drawer->x == env->sdl.mx && drawer->y == env->sdl.my)
			|| (!env->editor.tab && env->editor.select == 1
			&& drawer->x == env->h_w && drawer->y == env->h_h))
		{
			reset_selection(env);
			env->selected_enemy = drawer->enemy->num;
			new_tabs_position(env);
		}
		put_enemy_pixel(orender, drawer, env);
	}
}
