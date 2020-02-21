/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_main_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:24:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/21 11:42:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_objects_main_sprites(t_env *env)
{
	env->objects_main_sprites[0] = MINIGUN;
	env->objects_main_sprites[1] = HEALTH_PACK;
	env->objects_main_sprites[2] = SHELL_AMMO;
	env->objects_main_sprites[3] = ROCKETS_AMMO;
	env->objects_main_sprites[4] = REGULAR_AMMO;
	env->objects_main_sprites[5] = ENERGY_AMMO;
	env->objects_main_sprites[6] = LAMP;
	env->objects_main_sprites[7] = MONITOR_OFF;
	env->objects_main_sprites[8] = MONITOR_ON;
	env->objects_main_sprites[9] = MONITOR_DESTROYED;
	env->objects_main_sprites[10] = GREEN_ARMOR;
	env->objects_main_sprites[11] = CANDLE;
	env->objects_main_sprites[12] = BARREL;
	env->objects_main_sprites[13] = GRID;
	env->objects_main_sprites[14] = BUTTON_OFF;
	env->objects_main_sprites[15] = BUTTON_ON;
	env->objects_main_sprites[16] = BULLET_HOLE;
	env->objects_main_sprites[17] = LOST_SOUL_OBJECT;
	env->objects_main_sprites[18] = CYBER_DEMON_OBJECT;
}
