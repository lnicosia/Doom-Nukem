/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:45:52 by gaerhard          #+#    #+#             */
/*   Updated: 2019/07/29 15:47:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    armor_life_hud(t_env *env)
{
	int x;
	int y;
	int window_h;
	int window_w;

	x = 0;
	window_w = (int)(env->w)/*  - env->textures[ARMOR_LIFE_HUD].surface->w */;
	window_w = 0;
	window_h = (env->h - env->textures[ARMOR_LIFE_HUD].surface->h);
	while (x < env->textures[ARMOR_LIFE_HUD].surface->w && window_w + x < env->w)
	{
		y = 0;
		while (y < env->textures[ARMOR_LIFE_HUD].surface->h  && (window_h + y) < env->h)
		{
			if (env->textures[ARMOR_LIFE_HUD].str[x + env->textures[ARMOR_LIFE_HUD].surface->w * y] != 0xFFC10099)
				env->sdl.texture_pixels[(window_w + x) + env->w * (window_h + y)] = 
					env->textures[ARMOR_LIFE_HUD].str[x + env->textures[ARMOR_LIFE_HUD].surface->w * y];
			y++;
		}
		x++;
	}
}

void    ammo_hud(t_env *env)
{
	int x;
	int y;
	int window_h;
	int window_w;

	x = 0;
	window_w = (int)(env->w) - env->textures[AMMO_HUD].surface->w;
	window_h = (env->h - env->textures[AMMO_HUD].surface->h);
	while (x < env->textures[AMMO_HUD].surface->w)
	{
		y = 0;
		while (y < env->textures[AMMO_HUD].surface->h  && (window_h + y) < env->h)
		{
			if (env->textures[AMMO_HUD].str[x + env->textures[AMMO_HUD].surface->w * y] != 0xFFC10099)
				env->sdl.texture_pixels[(window_w + x) + env->w * (window_h + y)] = 
					env->textures[AMMO_HUD].str[x + env->textures[AMMO_HUD].surface->w * y];
			y++;
		}
		x++;
	}
}

void    draw_hud(t_env *env)
{
	char *str;

	str = ft_sitoa(env->player.life);
	armor_life_hud(env);
	ammo_hud(env);
	print_text(new_point(830, 300), new_printable_text(str, env->sdl.fonts.amazdoom50, 0xA1A1A100, 0), env);
	str = ft_sitoa(env->player.armor);
	print_text(new_point(830, 80), new_printable_text(str, env->sdl.fonts.amazdoom50, 0xA1A1A100, 0), env);
	print_ammo(env);
}
