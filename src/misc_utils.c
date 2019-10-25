/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:11:03 by gaerhard          #+#    #+#             */
/*   Updated: 2019/10/17 13:47:23 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void    init_sector_list(t_env *env, int curr)
{
    int i;

    i = 0;
    while (i < env->nb_sectors)
    {
        if (i == curr)
            env->sector_list[i] = 1;
        else
            env->sector_list[i] = 0;
        i++;
    }
}