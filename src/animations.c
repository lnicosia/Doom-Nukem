/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:41:36 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/02 16:48:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    damage_anim(t_env *env)
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

int     dying_enemy(t_env *env, int i)
{
    double start;
    double time_spent;

    if (env->enemies[i].death.start == 0)
        env->enemies[i].death.start = SDL_GetTicks();
    start = env->enemies[i].death.start;
    time_spent = env->time.milli_s - start;
    if ((int)time_spent >= 70 && (int)time_spent / 70 < 6)
        return ((int)(time_spent / 70));
    else if ((int)time_spent < 70)
        return (0);
    if (time_spent >= 6 * 70)
    {
        start = 0;
        env->enemies[i].exists = 0;
    }
    return (-1);
}