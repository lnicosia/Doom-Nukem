/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:59:37 by gaerhard          #+#    #+#             */
/*   Updated: 2019/07/17 17:20:23 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Weapon switch is only in the first weapon because it's common to every weapon
*/

void    init_weapons(t_env *env)
{
	env->weapons[0].possessed = 1;
    env->weapons[0].weapon_switch = 0;
    env->weapons[0].first_sprite = 6;
    env->weapons[0].nb_sprites = 15;
    env->weapons[0].ammo = 20;
    env->weapons[0].no_ammo = 0;
    env->weapons[0].max_ammo = 20;
	env->weapons[1].possessed = 1;
    env->weapons[1].first_sprite = 21;
    env->weapons[1].nb_sprites = 7;
    env->weapons[1].ammo = 40;
    env->weapons[1].max_ammo = 40;
    env->weapons[1].no_ammo = 0;
}
