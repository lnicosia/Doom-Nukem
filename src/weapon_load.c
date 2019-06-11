/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2019/06/11 15:48:56 by gaerhard         ###   ########.fr       */
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
    //ft_printf("status = %d\n", sprite);
    window_w = (int)(env->w - env->textures[sprite].surface->w) / 1.5;
    window_h = (env->h - env->textures[sprite].surface->h);
    while (x < env->textures[sprite].surface->w)
    {
        y = 0;
        while (y < env->textures[sprite].surface->h)
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

void    weapon_animation(t_env *env, int sprite)
{
    if (env->time.milli_s > env->shot.start + 1200 || env->shot.start == 0)
		{
            env->shot.on_going = 1;
			env->shot.start = SDL_GetTicks();
			Mix_PlayChannel(2, env->sound.shotgun, 0);
		}
    if (env->time.milli_s > env->shot.start + 70 && (sprite + (env->time.milli_s - env->shot.start) / 70 <= 15))
        draw_weapon(env, sprite + (env->time.milli_s - env->shot.start) / 70);
    else
        draw_weapon(env, sprite);
    if (sprite + (env->time.milli_s - env->shot.start) / 70 > 15)
        env->shot.on_going = 0;
}