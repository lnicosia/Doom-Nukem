/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:51:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:51:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	damage_anim2(t_env *env)
{
	int j;
	int time_spent;
	int color;

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
	j = 0;
	while (j < env->w * env->h)
	{
		env->sdl.texture_pixels[j] = blend_alpha(env->sdl.texture_pixels[j],
		0xFFFF0000, color);
		j++;
	}
}

void	damage_anim(t_env *env)
{
	if (!env->player_hurt.start)
		env->player_hurt.start = SDL_GetTicks();
	if (env->time.milli_s > env->player_hurt.start + 160)
	{
		env->player_hurt.start = 0;
		env->player.hit = 0;
	}
	damage_anim2(env);
}
