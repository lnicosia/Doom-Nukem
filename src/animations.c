/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:41:36 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/28 16:24:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].
		rest_sprite;
	}
}

void	pursuing_enemy(t_env *env, int i)
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
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].
		pursuit_sprite;
	}
}

int		dying_enemy(t_env *env, int i, int nb_sprites)
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

int		rand_dir(t_env *env, int i)
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

void	enemy_firing_anim(t_env *env, int i)
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
		env->enemies[i].sprite = env->enemy_sprites[env->enemies[i].sprite].
		firing_sprite;
		env->enemies[i].shot = (env->enemies[i].sprite == env->enemies[i].
		firing_sprite) ? 1 : 0;
	}
}
