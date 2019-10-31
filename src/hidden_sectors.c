/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_sectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:27:25 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/31 17:01:33 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    create_hidden_sector(t_env *env)
{
    env->sectors[env->editor.selected_sector].enemy_flag = env->editor
}

void    hidden_sectors(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_sectors)
    {
        if (env->sectors[i].status == 5 && !env->enemies[env->sectors[i].enemy_flag)
            activate_sector(env);
        i++;
    }
}