/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_enemies_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:49:51 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 12:00:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		init_enemies_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].hit = 0;
		env->enemies[i].state = 0;
		env->enemies[i].shot = 0;
		env->enemies[i].exists = 1;
		env->enemies[i].saw_player = 0;
		if (env->enemies[i].sprite >= 0 && env->enemies[i].sprite < 5)
		{
			env->enemies[i].height_ratio = 2;
			env->enemies[i].width_ratio = 0.5;
			env->enemies[i].main_sprite = LOST_SOUL;
			env->enemies[i].type = AERIAL;
			env->enemies[i].behavior = MELEE_KAMIKAZE;
			env->enemies[i].size_2d = env->enemies[i].scale * env->enemies[i].width_ratio;
			env->enemies[i].eyesight = env->enemies[i].size_2d * env->enemies[i].height_ratio;
			env->enemies[i].nb_rest_state = 2;
			env->enemies[i].nb_pursuit_state = 2;
			env->enemies[i].nb_firing_state = 0;
			env->enemies[i].height_on_floor = 5;
		}
		else if (env->enemies[i].sprite >= 5 && env->enemies[i].sprite < 13)
		{
			env->enemies[i].height_ratio = 2.5;
			env->enemies[i].width_ratio = 0.375;
			env->enemies[i].main_sprite = CYBER_DEMON;
			env->enemies[i].firing_sprite = 10;
			env->enemies[i].type = TERRESTRIAL;
			env->enemies[i].behavior = RANGED_PROJECTILE;
			env->enemies[i].size_2d =  env->enemies[i].scale * env->enemies[i].width_ratio;
			env->enemies[i].eyesight = env->enemies[i].size_2d * env->enemies[i].height_ratio;
			env->enemies[i].nb_rest_state = 4;
			env->enemies[i].nb_pursuit_state = 4;
			env->enemies[i].nb_firing_state = 3;
			env->enemies[i].height_on_floor = 0;
		}
		env->enemies[i].seen = 0;
		env->enemies[i].dir = 0;
		env->enemies[i].sector = get_sector_no_z(env, env->enemies[i].pos);
		env->enemies[i].last_player_pos = env->enemies[i].pos;
		i++;
	}
}

void		init_objects_data(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].exists = 1;
		env->objects[i].size_2d = env->objects[i].scale;
		env->objects[i].health = 1;
		env->objects[i].explosion_size = 0;
		env->objects[i].height = env->objects[i].height_ratio * env->objects[i].scale;
		if (env->objects[i].sprite == 0)
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = 0;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = WEAPON;
			env->objects[i].ammo_type = ENERGY;
			env->objects[i].weapon = RAYGUN;
			env->objects[i].quantity = 15;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 2) // health pack
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = HEALTH_PACK;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = HEAL;
			env->objects[i].quantity = 25;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 3) // shotgun ammo
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = SHELL_AMMO;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = AMMO;
			env->objects[i].ammo_type = SHELL;
			env->objects[i].quantity = 10;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 4) // rocket ammo
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = ROCKETS_AMMO;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = AMMO;
			env->objects[i].ammo_type = ROCKET;
			env->objects[i].quantity = 5;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 5) // regular ammo
		{
			env->objects[i].height_ratio = 0.5;
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
		if (env->objects[i].sprite == 6) // energy cell pack
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = ENERGY_AMMO;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = AMMO;
			env->objects[i].ammo_type = ENERGY;
			env->objects[i].quantity = 20;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite >= 7 && env->objects[i].sprite <= 10) // lamp
		{
			env->objects[i].height_ratio = 4;
			env->objects[i].solid = 1;
			env->objects[i].size_2d = 2;
			env->objects[i].height = 4.5;
			env->objects[i].main_sprite = LAMP;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 4;
			env->objects[i].destructible = 0;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 11)
		{
			env->objects[i].height_ratio = 1;
			env->objects[i].solid = 1;
			env->objects[i].main_sprite = MONITOR_OFF;
			env->objects[i].health = 40;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 1;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite >= 12 && env->objects[i].sprite <= 15) // monitor
		{
			env->objects[i].height_ratio = 1;
			env->objects[i].solid = 1;
			env->objects[i].main_sprite = MONITOR_ON;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 4;
			env->objects[i].destructible = 1;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 16)
		{
			env->objects[i].height_ratio = 1;
			env->objects[i].solid = 1;
			env->objects[i].main_sprite = MONITOR_ON;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 17) // green armor
		{
			env->objects[i].height_ratio = 0.5;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = GREEN_ARMOR;
			env->objects[i].explodes = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].type = ARMOR;
			env->objects[i].quantity = 50;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 18 || env->objects[i].sprite == 19) // candle
		{
			env->objects[i].height_ratio = 1;
			env->objects[i].main_sprite = CANDLE;
			env->objects[i].explodes = 0;
			env->objects[i].solid = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 1;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 0;
		}
		if (env->objects[i].sprite == 20) // barrel
		{
			env->objects[i].height_ratio = 1.75;
			env->objects[i].solid = 1;
			env->objects[i].main_sprite = BARREL;
			env->objects[i].health = 20;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 1;
			env->objects[i].explodes = 1;
			env->objects[i].explosion_size = env->objects[i].scale;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 50;
		}
		if (env->objects[i].sprite == 21) // barrel exploding
		{
			env->objects[i].height_ratio = 1.75;
			env->objects[i].solid = 0;
			env->objects[i].main_sprite = BARREL;
			env->objects[i].health = 0;
			env->objects[i].nb_rest_state = 1;
			env->objects[i].destructible = 0;
			env->objects[i].explodes = 1;
			env->objects[i].type = DECORATION;
			env->objects[i].damage = 50;	
		}
		i++;
	}
}
