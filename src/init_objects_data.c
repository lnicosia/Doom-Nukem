/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:49:51 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 12:05:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_object_data4(int i, t_env *env)
{
	if (env->objects[i].sprite == 6)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].main_sprite = ENERGY_AMMO;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = AMMO;
		env->objects[i].ammo_type = ENERGY;
		env->objects[i].quantity = 20;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite >= 7 && env->objects[i].sprite <= 10)
	{
		env->objects[i].height_ratio = 0.20;
		env->objects[i].solid = 1;
		env->objects[i].size_2d = 2;
		env->objects[i].main_sprite = LAMP;
		env->objects[i].nb_rest_state = 4;
		env->objects[i].destructible = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	init_object_data5(i, env);
}

void	init_object_data3(int i, t_env *env)
{
	if (env->objects[i].sprite == 4)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].main_sprite = ROCKETS_AMMO;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = AMMO;
		env->objects[i].ammo_type = ROCKET;
		env->objects[i].quantity = 5;
	}
	else if (env->objects[i].sprite == 5)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = REGULAR_AMMO;
		env->objects[i].explodes = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = AMMO;
		env->objects[i].ammo_type = REGULAR;
		env->objects[i].quantity = 40;
		env->objects[i].damage = 0;
	}
	init_object_data4(i, env);
}

void	init_object_data2(int i, t_env *env)
{
	if (env->objects[i].sprite == 2)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].main_sprite = HEALTH_PACK;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = HEAL;
		env->objects[i].quantity = 25;
	}
	else if (env->objects[i].sprite == 3)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].main_sprite = SHELL_AMMO;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = AMMO;
		env->objects[i].ammo_type = SHELL;
		env->objects[i].quantity = 10;
	}
	init_object_data3(i, env);
}

void	init_object_data(int i, t_env *env)
{
	env->objects[i].exists = 1;
	env->objects[i].solid = 0;
	env->objects[i].height = env->objects[i].scale;
	env->objects[i].map_hp = 1;
	env->objects[i].health = env->objects[i].map_hp;
	env->objects[i].explosion_size = 0;
	if (env->objects[i].sprite == 0)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = 0;
		env->objects[i].explodes = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = WEAPON;
		env->objects[i].ammo_type = REGULAR;
		env->objects[i].weapon = GATLING;
		env->objects[i].quantity = 200;
		env->objects[i].damage = 0;
	}
	init_object_data2(i, env);
	env->objects[i].size_2d = env->objects[i].scale
	* env->objects[i].height_ratio;
}

void	init_objects_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_objects)
	{
		init_object_data(i, env);
		i++;
	}
}
