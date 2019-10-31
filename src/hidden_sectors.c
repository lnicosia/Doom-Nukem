/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_sectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:27:25 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/31 18:03:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    create_hidden_sector(t_env *env)
{
    env->sectors[env->hidden_sect.sector].enemy_flag = env->hidden_sect.selected_enemy;
    env->sectors[env->hidden_sect.sector].start_floor = env->sectors[env->hidden_sect.sector].floor;
    env->sectors[env->hidden_sect.sector].floor = env->sectors[env->hidden_sect.sector].ceiling;
}

void    activate_sector(t_env *env, int i)
{
    if (env->sectors[i].floor > env->sectors[i].start_floor)   
        env->sectors[i].floor -= 0.1;
    if (env->sectors[i].floor <= env->sectors[i].start_floor)
    {
        env->sectors[i].floor = env->sectors[i].start_floor;
        env->sectors[i].activated = 1;
    }
}

void    hidden_sectors(t_env *env)
{
    int i;
    int activate;

    i = 0;
    activate = 0;
    while (i < env->nb_sectors && ((env->sectors[i].status != 5) 
        || (env->sectors[i].status == 5 && env->sectors[i].activated)))
    {
        if (!env->enemies[env->sectors[i].enemy_flag].exists)
        {
            activate = 1;
            break;
        }
        i++;
    }
    if (activate)
        activate_sector(env, i);
}