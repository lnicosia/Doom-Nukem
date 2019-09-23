/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:41:36 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/23 11:58:17 by gaerhard         ###   ########.fr       */
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

int     enemy_hurt(t_env *env, int i)
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

void     resting_enemy(t_env *env, int i)
{
    double start;
    double time_spent;

    if (env->enemies[i].rest.start == 0)
        env->enemies[i].rest.start = SDL_GetTicks();
    start = env->enemies[i].rest.start;
    time_spent = env->time.milli_s - start;
    if ((int)time_spent % 340 > 170)
    {
        env->enemies[i].rest.start = 0;
        env->enemies[i].sprite = env->sprites[env->enemies[i].sprite].rest_sprite;
    }
}

void     pursuing_enemy(t_env *env, int i)
{
    double start;
    double time_spent;

    if (env->enemies[i].pursue.start == 0)
        env->enemies[i].pursue.start = SDL_GetTicks();
    start = env->enemies[i].pursue.start;
    time_spent = env->time.milli_s - start;
    if ((int)time_spent % 340 > 170)
    {
        env->enemies[i].pursue.start = 0;
        env->enemies[i].sprite = env->sprites[env->enemies[i].sprite].pursuit_sprite;
    }
}

int     dying_enemy(t_env *env, int i, int nb_sprites)
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

int     rand_dir(t_env *env, int i)
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

void     enemy_firing_anim(t_env *env, int i)
{
    double start;
    double time_spent;

    if (env->enemies[i].fire.start == 0)
        env->enemies[i].fire.start = SDL_GetTicks();
    start = env->enemies[i].fire.start;
    time_spent = env->time.milli_s - start;
    if ((int)time_spent % 800 > 400)
    {
        env->enemies[i].fire.start = 0;
        env->enemies[i].sprite = env->sprites[env->enemies[i].sprite].firing_sprite;
        env->enemies[i].shot = (env->enemies[i].sprite == 10) ? 1 : 0;
    }
}
/*
int     enemy_fire_delay(t_env *env, int i)
{
    double start;
    double time_spent;

    if (env->enemies[i].fire.start == 0)
        env->enemies[i].fire.start = SDL_GetTicks();
    start = env->enemies[i].fire.start;
    time_spent = env->time.milli_s - start;
    if ((int)time_spent > 1000 && env->enemies[i].seen)
    {
        env->enemies[i].fire.start = 0;
        return (env->enemies[i].damage);
    }
    if (!env->enemies[i].seen)
        env->enemies[i].fire.start = 0;
    return (0);
}*/