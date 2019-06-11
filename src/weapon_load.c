/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2019/06/10 18:06:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    draw_weapon(t_env *env)
{
    int x;
    int y;
    int window_w;
    int window_h;

    x = 0;
    window_w = (int)(env->w - env->textures[6].surface->w) / 1.5;
    window_h = (env->h - env->textures[6].surface->h);
    while (x < env->textures[6].surface->w)
    {
        y = 0;
        while (y < env->textures[6].surface->h)
        {
            if (env->textures[6].str[x + env->textures[6].surface->w * y] != 0xFFF202AF)
                env->sdl.texture_pixels[(window_w + x) + env->w * (window_h + y)] = env->textures[6].str[x + env->textures[6].surface->w * y];
            y++;
        }
        x++;
    }
    ft_printf("width weapon = %d\n", env->textures[6].surface->w);
    ft_printf("heigth weapon = %d\n", env->textures[6].surface->h);
}