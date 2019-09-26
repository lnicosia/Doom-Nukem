/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_enemies_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:42:39 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/26 14:37:34 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void        init_enemies_data(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_enemies)
    {
        env->enemies[i].hit = 0;
		env->enemies[i].state = 0;
        env->enemies[i].shot = 0;
        env->enemies[i].exists = 1;
        if (env->enemies[i].sprite == 1 || env->enemies[i].sprite == 3 || 
            env->enemies[i].sprite == 7 || env->enemies[i].sprite == 8)
        {
            env->enemies[i].main_sprite = LOST_SOUL;
            env->enemies[i].flying = 1;
            env->enemies[i].ranged = 0;
		    env->enemies[i].size_2d = 0.5;
            env->enemies[i].eyesight = 1;
        }
        else if (env->enemies[i].sprite == 2 || env->enemies[i].sprite == 5)
        {
            env->enemies[i].eyesight = 6;
            env->enemies[i].main_sprite = CYBER_DEMON;
            env->enemies[i].firing_sprite = 10;
            env->enemies[i].flying = 0;
            env->enemies[i].ranged = 1;
            env->enemies[i].size_2d = 1.5;
        }
		env->enemies[i].seen = 0;
		env->enemies[i].dir = 0;
        env->enemies[i].sector = get_sector_no_z(env, env->enemies[i].pos);
        i++;
    }
}