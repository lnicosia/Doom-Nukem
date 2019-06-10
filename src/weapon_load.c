/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2019/06/10 15:16:20 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    draw_weapon(t_env *env)
{
    unsigned int x;
    unsigned int y;

    x = 0;
    while (x < env->textures[1].w)
    {
        y = 0;
        while (y < env->textures[1].h)
        {
            y++;
        }
        x++;
    }
    ft_printf("width weapon = %d\n", env->textures[1].w);
    ft_printf("heigth weapon = %d\n", env->textures[1].h);
}