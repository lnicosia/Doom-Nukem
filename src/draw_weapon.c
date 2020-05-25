/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:40:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:40:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_weapon_pixel(t_drawer *drawer, int window_w, int window_h,
t_env *env)
{
	if (!env->options.lighting
		|| (!drawer->sector->brightness && !drawer->sector->intensity))
		env->sdl.texture_pixels[(window_w + (int)drawer->x) + env->w
		* (window_h + (int)drawer->y)] = drawer->texture_pixels[(int)drawer->x
		+ drawer->texture_w * (int)drawer->y];
	else if (!drawer->sector->brightness)
		env->sdl.texture_pixels[(window_w + (int)drawer->x) + env->w
		* (window_h + (int)drawer->y)] = apply_light_color(drawer->
		texture_pixels[(int)drawer->x + drawer->texture_w * (int)drawer->y],
		drawer->sector->light_color, drawer->sector->intensity);
	else if (!drawer->sector->intensity)
		env->sdl.texture_pixels[(window_w + (int)drawer->x) + env->w
		* (window_h + (int)drawer->y)] = apply_light_brightness(drawer->
		texture_pixels[(int)drawer->x + drawer->texture_w * (int)drawer->y],
		drawer->sector->brightness);
	else
		env->sdl.texture_pixels[(window_w + (int)drawer->x) + env->w
		* (window_h + (int)drawer->y)] = apply_light_both(drawer->
		texture_pixels[(int)drawer->x + drawer->texture_w * (int)drawer->y],
		drawer->sector->light_color, drawer->sector->intensity,
		drawer->sector->brightness);
}

void	draw_weapon(t_env *env, int sprite)
{
	int			window_w;
	int			window_h;
	t_drawer	drawer;

	drawer.texture_pixels = env->sprite_textures[sprite].str;
	drawer.texture_w = env->sprite_textures[sprite].surface->w;
	drawer.texture_h = env->sprite_textures[sprite].surface->h;
	window_w = (int)(env->w - drawer.texture_w) / 1.5;
	if (env->player.curr_weapon == ROCKET_LAUNCHER)
		window_w = env->h_w - drawer.texture_w / 2;
	window_h = (env->h - drawer.texture_h) + env->weapons[0].weapon_switch;
	drawer.sector = &env->sectors[env->player.sector];
	drawer.y = 0;
	while (drawer.y < drawer.texture_h)
	{
		drawer.x = 0;
		while (drawer.x < drawer.texture_w && (window_h + drawer.y) < env->h)
		{
			if (drawer.texture_pixels[(int)drawer.x + drawer.texture_w
				* (int)drawer.y] != 0xFFC10099)
				put_weapon_pixel(&drawer, window_w, window_h, env);
			drawer.x++;
		}
		drawer.y++;
	}
}
