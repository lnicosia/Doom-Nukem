/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darw_inventory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 11:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

void	draw_current_weapon(int i, int hud_start, int weapon_size, t_env *env)
{
	int		height;
	int		rectangle_size;

	height = weapon_size / (env->weapons[i].sprite.size[0].x /
	(double)env->weapons[i].sprite.size[0].y);
	rectangle_size = (env->w - env->sprite_textures[AMMO_HUD].surface->w
	- hud_start) / NB_WEAPONS;
	if (env->weapons[i].possessed)
		apply_sprite(env->weapons[i].sprite, new_point(
		env->h - env->sprite_textures[ARMOR_LIFE_HUD].surface->h / 2
		- height / 2, hud_start + (weapon_size + weapon_size /
		(NB_WEAPONS + 1)) * i + weapon_size / (NB_WEAPONS + 1)),
		new_point(weapon_size, height), env);
	else
		apply_sprite_grey(env->weapons[i].sprite, new_point(
		env->h - env->sprite_textures[ARMOR_LIFE_HUD].surface->h / 2
		- height / 2, hud_start + (weapon_size + weapon_size /
		(NB_WEAPONS + 1)) * i + weapon_size / (NB_WEAPONS + 1)),
		new_point(weapon_size, height), env);
	if (env->player.curr_weapon == i)
		draw_rectangle(env, new_rectangle(0, 0xFFFFFF00, 0, 2),
		new_point(hud_start + rectangle_size * i, env->h -
		env->sprite_textures[ARMOR_LIFE_HUD].surface->h),
		new_point(rectangle_size,
		env->sprite_textures[ARMOR_LIFE_HUD].surface->h));
}

int		draw_inventory(t_env *env)
{
	int	i;
	int	hud_start;
	int	weapon_size;

	hud_start = env->sprite_textures[ARMOR_LIFE_HUD].surface->w;
	weapon_size = (env->w - env->sprite_textures[AMMO_HUD].surface->w
	- hud_start) / (NB_WEAPONS + 1);
	i = 0;
	while (i < NB_WEAPONS)
	{
		draw_current_weapon(i, hud_start, weapon_size, env);
		i++;
	}
	return (0);
}
