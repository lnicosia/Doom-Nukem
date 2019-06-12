/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2019/06/12 18:58:29 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    draw_weapon(t_env *env, int sprite)
{
    int x;
    int y;
    int window_w;
    int window_h;

    x = 0;
    window_w = (int)(env->w - env->textures[sprite].surface->w) / 1.5;
    window_h = (env->h - env->textures[sprite].surface->h) + env->weapons[0].weapon_switch;
    while (x < env->textures[sprite].surface->w)
    {
        y = 0;
        while (y < env->textures[sprite].surface->h  && (window_h + y) < env->h)
        {
            if (env->textures[sprite].str[x + env->textures[sprite].surface->w * y] != 0xFFC10099)
                env->sdl.texture_pixels[(window_w + x) + env->w * (window_h + y)] = 
                    env->textures[sprite].str[x + env->textures[sprite].surface->w * y];
            y++;
        }
        x++;
    }
    //update_screen(env);
}

void    weapon_animation(t_env *env, int nb)
{
    if (env->shot.start == 0)
		{
            env->shot.on_going = 1;
			env->shot.start = SDL_GetTicks();
			Mix_PlayChannel(2, env->weapons[nb].sound, 0);
		}
    if (env->time.milli_s > env->shot.start + 70 && ((env->time.milli_s - env->shot.start) / 70 < env->weapons[nb].nb_sprites))
        draw_weapon(env, env->weapons[nb].first_sprite + (int)((env->time.milli_s - env->shot.start) / 70));
    else
        draw_weapon(env, env->weapons[nb].first_sprite);
    if ((int)((env->time.milli_s - env->shot.start)) >= env->weapons[nb].nb_sprites * 70)
    {
        env->shot.start = 0;
        env->shot.on_going = 0;
    }
}

void    weapon_down(t_env *env)
{
    int time_spent;

    if (env->weapon_down.start == 0)
    {
        env->weapon_down.start = SDL_GetTicks();
        env->weapon_down.on_going = 1;
    }
    time_spent = env->time.milli_s - env->weapon_down.start;
    if (time_spent > 70 && time_spent / 70 <= 4)
        env->weapons[0].weapon_switch  = 75 * (int)(time_spent / 70);
    if (time_spent > 4 * 70)
    {
        if (env->sdl.event.wheel.y > 0)
		    env->player.curr_weapon = (env->player.curr_weapon >= NB_WEAPONS - 1 ? 0 : env->player.curr_weapon + 1);
	    else if (env->sdl.event.wheel.y < 0)
	        env->player.curr_weapon = (env->player.curr_weapon <= 0 ? NB_WEAPONS - 1 : env->player.curr_weapon - 1);
        env->weapons[0].weapon_switch = 0;
        env->weapon_down.start = 0;
        env->weapon_down.on_going = 0;
        env->weapon_up.start = SDL_GetTicks();
        env->weapon_up.on_going = 0;
    }
}

void    weapon_up(t_env *env)
{
    int time_spent;

    time_spent = env->time.milli_s - env->weapon_up.start;
    if (time_spent > 70 && time_spent / 70 <= 4)
        env->weapons[0].weapon_switch /= 1;
    if (time_spent > 4 * 70)
    {
        env->weapons[0].weapon_switch = 0;
        env->weapon_up.start = 0;
        env->weapon_up.on_going = 0;
    }
}