/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:11:04 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:11:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_gatling_weapon(t_env *env)
{
	env->weapons[4].name = "Gatling";
	env->weapons[4].possessed = 0;
	env->weapons[4].first_sprite = env->hud_start + 28;
	env->weapons[4].nb_sprites = 6;
	env->weapons[4].ammo_type = REGULAR;
	env->weapons[4].ammo = 200;
	env->weapons[4].damage = 10;
	env->weapons[4].max_ammo = 200;
	env->weapons[4].splash = 0;
	env->weapons[4].range = 50;
	env->weapons[4].frame_speed = 20;
	env->weapons[4].hole_scale = 0.4;
	env->weapons[4].sprite = env->object_sprites[MINIGUN];
}
