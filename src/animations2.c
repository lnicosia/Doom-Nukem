/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:29:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:29:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		enemy_hurt(t_env *env, int i)
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
		env->objects[i].sprite = env->object_sprites[env->objects[i].sprite].
		rest_sprite;
	}
}

int		explosion_animation(t_env *env, t_explosion *explosion, int nb_sprites)
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

int		object_destruction(t_env *env, int i, int nb_sprites)
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
