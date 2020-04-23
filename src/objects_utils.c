/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:57:30 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/06 10:54:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	pick_weapon_up(t_env *env, int i)
{
	int j;

	j = 0;
	while (j < NB_WEAPONS)
	{
		if (env->weapons[j].ammo_type == env->objects[i].ammo_type
		  	&& env->weapons[j].possessed
			&& env->weapons[j].ammo < env->weapons[j].max_ammo)
		{
			env->weapons[j].ammo += env->objects[i].quantity;
			env->weapons[j].ammo =
			(env->weapons[j].ammo > env->weapons[j].max_ammo) ?
			env->weapons[j].max_ammo : env->weapons[j].ammo;
			env->objects[i].exists = 0;
		}
		j++;
	}
}

void	object_collision2(t_env *env, int i)
{
	if (env->objects[i].type == ARMOR && env->player.armor < 100)
	{
		env->player.armor += env->objects[i].quantity;
		env->objects[i].exists = 0;
		env->player.armor = (env->player.armor > 100) ? 100 : env->player.armor;
	}
	if (env->objects[i].type == WEAPON)
	{
		if (!env->weapons[env->objects[i].weapon].possessed)
		{
			env->weapons[env->objects[i].weapon].possessed = 1;
			env->objects[i].exists = 0;
		}
		else
		{
		  	pick_weapon_up(env, i);
		}	
	}
}

void	pick_ammo_up(t_env *env, int i)
{
  	int	j;

	j = 0;
	while (j < NB_WEAPONS)
	{
		if (env->weapons[j].ammo_type == env->objects[i].ammo_type
		  	&& env->weapons[j].possessed
			&& env->weapons[j].ammo < env->weapons[j].max_ammo)
		{
			env->weapons[j].ammo += env->objects[i].quantity;
			env->weapons[j].ammo =
			(env->weapons[j].ammo > env->weapons[j].max_ammo) ?
			env->weapons[j].max_ammo : env->weapons[j].ammo;
			env->objects[i].exists = 0;
		}
		j++;
	}
}

void	object_collision(t_env *env, int i)
{
	if (env->objects[i].type == HEAL && env->player.health < 100)
	{
		env->player.health += env->objects[i].quantity;
		env->player.health =
		(env->player.health > 100) ? 100 : env->player.health;
		env->objects[i].exists = 0;
	}
	if (env->objects[i].type == AMMO)
	{
	  	pick_ammo_up(env, i);
	}
	object_collision2(env, i);
}

void    objects_collision(t_env *env, t_v3 pos)
{
    int i;

    i = 0;
    while (i < env->nb_objects)
    {
		if (env->objects[i].exists
	  		&& distance_two_points_2d(env->objects[i].pos.x,
			env->objects[i].pos.y, pos.x, pos.y) < env->objects[i].size_2d
			&& pos.z <= env->objects[i].height + env->objects[i].pos.z
			&& pos.z >= env->objects[i].pos.z)
		{
		  	object_collision(env, i);
		}
        i++;
    }
}
