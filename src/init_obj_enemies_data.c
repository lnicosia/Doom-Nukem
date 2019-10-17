/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_enemies_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:42:39 by gaerhard          #+#    #+#             */
/*   Updated: 2019/10/17 15:18:02 by gaerhard         ###   ########.fr       */
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
        env->enemies[i].saw_player = 0;
        if (env->enemies[i].sprite == 1 || env->enemies[i].sprite == 3 || 
            env->enemies[i].sprite == 7 || env->enemies[i].sprite == 8)
        {
            env->enemies[i].main_sprite = LOST_SOUL;
            env->enemies[i].type = AERIAL;
            env->enemies[i].behavior = MELEE;
		    env->enemies[i].size_2d = 0.75;
            env->enemies[i].eyesight = 1;
        }
        else if (env->enemies[i].sprite == 2 || env->enemies[i].sprite == 5)
        {
            env->enemies[i].eyesight = 6;
            env->enemies[i].main_sprite = CYBER_DEMON;
            env->enemies[i].firing_sprite = 10;
            env->enemies[i].type = TERRESTRIAL;
            env->enemies[i].behavior = RANGED;
            env->enemies[i].size_2d = 1.5;
        }
		env->enemies[i].seen = 0;
		env->enemies[i].dir = 0;
        env->enemies[i].sector = get_sector_no_z(env, env->enemies[i].pos);
        env->enemies[i].last_player_pos = env->enemies[i].pos;
        i++;
    }
}