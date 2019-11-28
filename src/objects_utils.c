/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:57:30 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/28 18:50:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"


void    objects_collision(t_env *env, t_v3 pos)
{
    int i;
	int j;

    i = 0;
    while (i < env->nb_objects)
    {
        if (env->objects[i].exists && distance_two_points(env->objects[i].pos.x, env->objects[i].pos.y, pos.x, pos.y) < 1.75 &&
            pos.z <= env->objects[i].height + env->objects[i].pos.z && pos.z >= env->objects[i].pos.z)
        {
            if (env->objects[i].sprite == 0 && env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
            {
                env->weapons[env->player.curr_weapon].ammo += 10;
                env->objects[i].exists = 0;
                if (env->weapons[env->player.curr_weapon].ammo >= env->weapons[env->player.curr_weapon].max_ammo)
                    env->weapons[env->player.curr_weapon].ammo = env->weapons[env->player.curr_weapon].max_ammo;
            }
			if (env->objects[i].type == HEAL && env->player.health < 100)
			{
				env->player.health += env->objects[i].quantity;
				env->player.health = (env->player.health > 100) ? 100 : env->player.health;
				env->objects[i].exists = 0;
			}
			if (env->objects[i].type == AMMO)
			{
				j = 0;
				while (j < NB_WEAPONS)
				{
					if (env->weapons[j].ammo_type == env->objects[i].ammo_type && env->weapons[j].possessed && env->weapons[j].ammo < env->weapons[j].max_ammo)
					{
						env->weapons[j].ammo += env->objects[i].quantity;
						env->weapons[j].ammo = (env->weapons[j].ammo > env->weapons[j].max_ammo) ? 
							env->weapons[j].max_ammo : env->weapons[j].ammo;
						env->objects[i].exists = 0;
					}
					j++;
				}
			}
        }
        i++;
    }
}