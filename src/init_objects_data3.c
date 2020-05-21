/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_data3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:05:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:05:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_object_data14(int i, t_env *env)
{
	if (env->objects[i].sprite == 33)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].main_sprite = DOOM_GUY;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = DECORATION;
	}
	else if (env->objects[i].sprite == 34)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].main_sprite = 34;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
}

void	init_object_data13(int i, t_env *env)
{
	if (env->objects[i].sprite == 31)
	{
		env->objects[i].height_ratio = 2.5;
		env->objects[i].main_sprite = SHOTGUN_SPRITE;
		env->objects[i].health = 1;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = WEAPON;
		env->objects[i].weapon = SHOTGUN;
		env->objects[i].ammo_type = SHELL;
		env->objects[i].quantity = 15;
	}
	else if (env->objects[i].sprite == 32)
	{
		env->objects[i].height_ratio = 2.5;
		env->objects[i].main_sprite = RAYGUN_SPRITE;
		env->objects[i].health = 1;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = WEAPON;
		env->objects[i].weapon = RAYGUN;
		env->objects[i].ammo_type = ENERGY;
		env->objects[i].quantity = 30;
	}
	init_object_data14(i, env);
}

void	init_object_data12(int i, t_env *env)
{
	if (env->objects[i].sprite == 29)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = DOOM_GUY_FACE;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite == 30)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = CAMERA_SPRITE;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	init_object_data13(i, env);
}

void	init_object_data11(int i, t_env *env)
{
	if (env->objects[i].sprite == 27)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = LOST_SOUL_OBJECT;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite == 28)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = CYBER_DEMON_OBJECT;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	init_object_data12(i, env);
}

void	init_object_data10(int i, t_env *env)
{
	if (env->objects[i].sprite == 25)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = BUTTON_ON;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite == 26)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = BULLET_HOLE;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	init_object_data11(i, env);
}
