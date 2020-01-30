/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_main_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:24:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/30 11:01:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_objects_main_sprites(t_env *env)
{
	env->objects_main_sprites[0] = HEALTH_PACK;
	env->objects_main_sprites[1] = SHELL_AMMO;
	env->objects_main_sprites[2] = ROCKETS_AMMO;
	env->objects_main_sprites[3] = REGULAR_AMMO;
	env->objects_main_sprites[4] = ENERGY_AMMO;
	env->objects_main_sprites[5] = LAMP;
	env->objects_main_sprites[6] = MONITOR_OFF;
	env->objects_main_sprites[7] = MONITOR_ON;
	env->objects_main_sprites[8] = MONITOR_DESTROYED;
	env->objects_main_sprites[9] = GREEN_ARMOR;
	env->objects_main_sprites[10] = CANDLE;
	env->objects_main_sprites[11] = BARREL;
	env->objects_main_sprites[12] = GRID;
	env->objects_main_sprites[13] = BUTTON_OFF;
	env->objects_main_sprites[14] = BUTTON_ON;
	env->objects_main_sprites[15] = BULLET_HOLE;
	env->objects_main_sprites[16] = LOST_SOUL_OBJECT;
	env->objects_main_sprites[17] = CYBER_DEMON_OBJECT;
}
