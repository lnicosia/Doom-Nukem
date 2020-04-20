#include "env.h"

void	init_object_data9(int i, t_env *env)
{
	if (env->objects[i].sprite == 23)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = GRID;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;	
	}
	else if (env->objects[i].sprite == 24)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = BUTTON_OFF;
		env->objects[i].health = 0;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].explodes = 0;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;	
	}
	init_object_data10(i, env);
}

void	init_object_data8(int i, t_env *env)
{
	if (env->objects[i].sprite == 21)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].main_sprite = BARREL;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].explodes = 1;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 50;	
	}
	else if (env->objects[i].sprite == 22)
	{
		env->objects[i].height_ratio = 0.6;
		env->objects[i].solid = 0;
		env->objects[i].main_sprite = -1;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].explodes = 1;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 50;	
	}
	init_object_data9(i, env);
}

void	init_object_data7(int i, t_env *env)
{
	if (env->objects[i].sprite == 18 || env->objects[i].sprite == 19)
	{
		env->objects[i].height_ratio = 1;
		env->objects[i].main_sprite = CANDLE;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 1;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite == 20)
	{
		env->objects[i].height_ratio = 0.6;
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
	init_object_data8(i, env);
}

void	init_object_data6(int i, t_env *env)
{
	if (env->objects[i].sprite == 16)
	{
		env->objects[i].height_ratio = 1;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = MONITOR_ON;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite == 17)
	{
		env->objects[i].height_ratio = 2;
		env->objects[i].main_sprite = GREEN_ARMOR;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 0;
		env->objects[i].type = ARMOR;
		env->objects[i].quantity = 50;
		env->objects[i].damage = 0;
	}
	init_object_data7(i, env);
}

void	init_object_data5(int i, t_env *env)
{
	if (env->objects[i].sprite == 11)
	{
		env->objects[i].height_ratio = 1;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = MONITOR_OFF;
		env->objects[i].health = 40;
		env->objects[i].nb_rest_state = 1;
		env->objects[i].destructible = 1;
		env->objects[i].type = DECORATION;
		env->objects[i].damage = 0;
	}
	else if (env->objects[i].sprite >= 12 && env->objects[i].sprite <= 15)
	{
		env->objects[i].height_ratio = 1;
		env->objects[i].solid = 1;
		env->objects[i].main_sprite = MONITOR_ON;
		env->objects[i].nb_rest_state = 4;
		env->objects[i].destructible = 1;
		env->objects[i].type = DECORATION;
	}
	init_object_data6(i, env);
}
