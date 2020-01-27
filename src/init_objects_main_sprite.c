/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_main_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:24:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/27 18:35:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_objects_main_sprite(t_env *env)
{
	env->object_main_sprite[0] = HEALTH_PACK;
	env->object_main_sprite[1] = SHELL_AMMO;
	env->object_main_sprite[2] = ROCKETS_AMMO;
	env->object_main_sprite[3] = REGULAR_AMMO;
	env->object_main_sprite[4] = ENERGY_AMMO;
	env->object_main_sprite[5] = LAMP;
	env->object_main_sprite[6] = MONITOR_OFF;
	env->object_main_sprite[7] = MONITOR_ON;
	env->object_main_sprite[9] = GREEN_ARMOR;
	env->object_main_sprite[10] = CANDLE;
	env->object_main_sprite[11] = BARREL;
	env->object_main_sprite[12] = GRID;
	env->object_main_sprite[13] = BUTTON_OFF;
	env->object_main_sprite[14] = BUTTON_ON;
	env->object_main_sprite[15] = BULLET_HOLE;
}
