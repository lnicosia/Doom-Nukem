#include "env.h"

void	weapon_animation2(t_env *env, int nb)
{
	if (env->weapons[nb].ammo)
	{
		if (env->time.milli_s > env->shot.start + env->weapons[nb].frame_speed
		  	&& ((env->time.milli_s - env->shot.start)
			/ env->weapons[nb].frame_speed < env->weapons[nb].nb_sprites))
			draw_weapon(env, env->weapons[nb].first_sprite + (int)((env->time.
			milli_s - env->shot.start) / env->weapons[nb].frame_speed));
		else
			draw_weapon(env, env->weapons[nb].first_sprite);
	}
	else
	{
		draw_weapon(env, env->weapons[nb].first_sprite);
	}
	if ((int)((env->time.milli_s - env->shot.start)) >= env->weapons[nb].
	  	nb_sprites * env->weapons[nb].frame_speed)
	{
		env->shot.start = 0;
		env->shot.on_going = 0;
	}
}

int		weapon_animation(t_env *env, int nb)
{
	if (env->shot.start == 0)
	{
		env->shot.on_going = 1;
		env->shot.start = SDL_GetTicks();
		if (env->weapons[nb].ammo > 0 || env->player.infinite_ammo)
		{
			if (shot(env))
				return (-1);
			play_sound(env, &env->sound.player_shots_chan,
			env->weapons[nb].shot, env->sound.ambient_vol);
			if (!env->player.infinite_ammo)
				env->weapons[nb].ammo-=0;
		}
	}
	weapon_animation2(env, nb);
	return (0);
}

void    weapon_change(t_env *env)
{
	int time_spent;

	if (env->weapon_change.start == 0)
	{
		env->weapon_change.start = SDL_GetTicks();
		env->weapon_change.on_going = 1;
	}
	time_spent = env->time.milli_s - env->weapon_change.start;
	if (time_spent > 70 && time_spent / 70 <= 4)
		env->weapons[0].weapon_switch  = 75 * (int)(time_spent / 70);
	if (time_spent > 4 * 70)
	{
		env->player.curr_weapon = env->player.next_weapon;
		env->weapons[0].weapon_switch = 0;
		env->weapon_change.start = 0;
		env->weapon_change.on_going = 0;
	}
}
