/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:45:31 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/03 15:10:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    update_enemy_light(t_env *env, int i)
{
	env->enemies[i].sector = get_sector_no_z_origin(env, env->enemies[i].pos,
	env->enemies[i].sector);
	if (env->enemies[i].sector != -1)
	{
		env->enemies[i].brightness =
			env->sectors[env->enemies[i].sector].brightness;
		env->enemies[i].light_color =
			env->sectors[env->enemies[i].sector].light_color;
		env->enemies[i].intensity =
			env->sectors[env->enemies[i].sector].intensity;
	}
	else
	{
		env->enemies[i].brightness = 0;
		env->enemies[i].light_color = 0;
		env->enemies[i].intensity = 0;
	}
}

void    update_object_light(t_env *env, int i)
{
	env->objects[i].sector = get_sector_no_z_origin(env, env->objects[i].pos,
	env->objects[i].sector);
	if (env->objects[i].sector != -1)
	{
		env->objects[i].brightness =
			env->sectors[env->objects[i].sector].brightness;
		env->objects[i].light_color =
			env->sectors[env->objects[i].sector].light_color;
		env->objects[i].intensity =
			env->sectors[env->objects[i].sector].intensity;
	}
	else
	{
		env->objects[i].brightness = 0;
		env->objects[i].light_color = 0;
		env->objects[i].intensity = 0;
	}
}
