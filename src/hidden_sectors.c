/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_sectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:27:25 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/05 18:07:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    create_hidden_sector(t_env *env)
{
    env->sectors[env->hidden_sect.sector].enemy_flag = env->selected_enemy;
    env->sectors[env->hidden_sect.sector].start_floor = env->sectors[env->hidden_sect.sector].floor;
    env->sectors[env->hidden_sect.sector].floor = env->sectors[env->hidden_sect.sector].ceiling;
    update_sector_slope(env, &env->sectors[env->hidden_sect.sector]);
    env->hidden_sect.create = 0;
    env->hidden_sect.sector = -1;
    env->hidden_sect.selected_enemy = -1;
}

void    activate_sector(t_env *env, int i)
{
    if (env->sectors[i].floor > env->sectors[i].start_floor)   
        env->sectors[i].floor -= 0.1;
    update_sector_slope(env, &env->sectors[i]);
    if (env->sectors[i].floor <= env->sectors[i].start_floor)
    {
        env->sectors[i].floor = env->sectors[i].start_floor;
        update_sector_slope(env, &env->sectors[i]);
        env->sectors[i].activated = 1;
    }
}

void    hidden_sectors(t_env *env)
{
    int i;
    int activate;

    i = 0;
    activate = 0;
    while (i < env->nb_sectors)
    {
        if (env->sectors[i].status == 5 && !env->sectors[i].activated
        && !env->enemies[env->sectors[i].enemy_flag].exists)
        {
            activate = 1;
            break;
        }
        i++;
    }
    if (activate)
        activate_sector(env, i);
}