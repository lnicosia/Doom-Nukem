/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_data4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:05:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:05:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_object_data15(int i, t_env *env)
{
	if (env->objects[i].sprite == 35)
	{
		env->objects[i].height_ratio = 2.5;
		env->objects[i].main_sprite = GUN_SPRITE;
		env->objects[i].health = 1;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = WEAPON;
		env->objects[i].weapon = GUN;
		env->objects[i].ammo_type = REGULAR;
		env->objects[i].quantity = 15;
	}
}
