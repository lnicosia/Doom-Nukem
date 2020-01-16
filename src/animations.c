/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:41:36 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/15 11:45:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	damage_anim(t_env *env)
{
	int j;
	int time_spent;
	int color;
	
	if (!env->player_hurt.start)
		env->player_hurt.start = SDL_GetTicks();
	if (env->time.milli_s > env->player_hurt.start + 160)
	{
		env->player_hurt.start = 0;
		env->player.hit = 0;
	}
	j = 0;
	color = 0;
	time_spent = env->time.milli_s - env->player_hurt.start;
	if (time_spent > 0 && time_spent <= 30)
		color = 40;
	else if (time_spent > 30 && time_spent <= 50)
		color = 50;
	else if (time_spent > 50 && time_spent <= 110)
		color = 75;
	else if (time_spent > 110 && time_spent <= 130)
		color = 50;
	else if (time_spent > 130 && time_spent <= 160)
		color = 40;
	while (j < env->w * env->h)
	{
		env->sdl.texture_pixels[j] = blend_alpha(env->sdl.texture_pixels[j], 0xFFFF0000, color);
		j++;
	}
}

int	 enemy_hurt(t_env *env, int i)
{
	int time_spent;
	int color;

	if (!env->enemies[i].hurt.start)
		env->enemies[i].hurt.start = SDL_GetTicks();
	if (env->time.milli_s > env->enemies[i].hurt.start + 160)
	{
		env->enemies[i].hurt.start = 0;
		env->enemies[i].hit = 0;
	}
	time_spent = env->time.milli_s - env->player_hurt.start;
	color = 40;
	if (time_spent > 0 && time_spent <= 30)
		color = 40;
	else if (time_spent > 30 && time_spent <= 50)
		color = 50;
	else if (time_spent > 50 && time_spent <= 110)
		color = 75;
	else if (time_spent > 110 && time_spent <= 130)
		color = 50;
	else if (time_spent > 130 && time_spent <= 160)
		color = 40;
	//ft_printf("color %d\n", color);
	return (color);
}

void	object_anim_loop(t_env *env, int i)
{
	double	start;
	double	time_spent;
	int		tick;

	if (env->objects[i].rest.start == 0)
		env->objects[i].rest.start = SDL_GetTicks();
	start = env->objects[i].rest.start;
	time_spent = env->time.milli_s - start;
	tick = env->objects[i].nb_rest_state * 340;
	if ((int)time_spent % tick > 170)
	{
		env->objects[i].rest.start = 0;
		env->objects[i].sprite = env->object_sprites[env->objects[i].sprite].rest_sprite;
	}
}

int	 explosion_animation(t_env *env, t_explosion *explosion, int nb_sprites)
{
	double start;
	double time_spent;

	if (explosion->explosion_anim.start == 0)
		explosion->explosion_anim.start = SDL_GetTicks();
	start = explosion->explosion_anim.start;
	time_spent = env->time.milli_s - start;
	if ((int)time_spent >= 75 && (int)time_spent / 75 < nb_sprites)
		return ((int)(time_spent / 75));
	else if ((int)time_spent < 75)
		return (0);
	if (time_spent > nb_sprites * 75)
		explosion->explosion_anim.start = 0;
	return (-1);
}

int	 object_destruction(t_env *env, int i, int nb_sprites)
{
	double start;
	double time_spent;

	if (env->objects[i].death.start == 0)
		env->objects[i].death.start = SDL_GetTicks();
	start = env->objects[i].death.start;
	time_spent = env->time.milli_s - start;
	env->objects[i].solid = 0;
	if ((int)time_spent >= 70 && (int)time_spent / 70 < nb_sprites)
		return ((int)(time_spent / 70));
	else if ((int)time_spent < 70)
		return (0);
	if (time_spent > nb_sprites * 70)
	{
		env->objects[i].death.start = 0;
		if (env->objects[i].explodes == 1)
			env->objects[i].exists = 0;
	}
	return (-1);
}

void	resting_enemy(t_env *env, int i)
{
	double	start;
	double	time_spent;
	int		tick;

	if (env->enemies[i].rest.start == 0)
		env->enemies[i].rest.start = SDL_GetTicks();
	start = env->enemies[i].rest.start;
	time_spent = env->time.milli_s - start;
	tick = env->enemies[i].nb_rest_state * 340;
	if ((int)time_spent % tick > 170)
	{
		env->enemies[i].rest.start = 0;
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].rest_sprite;
	}
}

void	 pursuing_enemy(t_env *env, int i)
{
	double	start;
	double	time_spent;
	int		tick;

	if (env->enemies[i].pursue.start == 0)
		env->enemies[i].pursue.start = SDL_GetTicks();
	start = env->enemies[i].pursue.start;
	time_spent = env->time.milli_s - start;
	tick = 340 * env->enemies[i].nb_pursuit_state;
	if ((int)time_spent % tick > 170)
	{
		env->enemies[i].pursue.start = 0;
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].pursuit_sprite;
	}
}

int	 dying_enemy(t_env *env, int i, int nb_sprites)
{
	double start;
	double time_spent;

	if (env->enemies[i].death.start == 0)
		env->enemies[i].death.start = SDL_GetTicks();
	start = env->enemies[i].death.start;
	time_spent = env->time.milli_s - start;
	if ((int)time_spent >= 70 && (int)time_spent / 70 < nb_sprites)
		return ((int)(time_spent / 70));
	else if ((int)time_spent < 70)
		return (0);
	if (time_spent > nb_sprites * 70)
	{
		env->enemies[i].death.start = 0;
		env->enemies[i].exists = 0;
	}
	return (-1);
}

int	 rand_dir(t_env *env, int i)
{
	double start;
	double time_spent;

	if (env->enemies[i].rand_dir.start == 0)
		env->enemies[i].rand_dir.start = SDL_GetTicks();
	start = env->enemies[i].rand_dir.start;
	time_spent = env->time.milli_s - start;
	if ((int)time_spent > 250)
	{
		env->enemies[i].rand_dir.start = 0;
		return ((int)env->time.milli_s % 2 == 0);
	}
	return (env->enemies[i].dir);
}

void	 enemy_firing_anim(t_env *env, int i)
{
	double	start;
	double	time_spent;
	int		tick;

	if (env->enemies[i].fire.start == 0)
		env->enemies[i].fire.start = SDL_GetTicks();
	start = env->enemies[i].fire.start;
	time_spent = env->time.milli_s - start;
	tick = 200 * env->enemies[i].nb_firing_state;
	if ((int)time_spent % tick > 200)
	{
		env->enemies[i].fire.start = 0;
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].firing_sprite;
		env->enemies[i].shot = (env->enemies[i].sprite == env->enemies[i].firing_sprite) ? 1 : 0;
	}
}