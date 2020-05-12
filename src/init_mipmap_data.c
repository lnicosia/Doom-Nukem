/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mipmap_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:48:11 by marvin            #+#    #+#             */
/*   Updated: 2020/05/12 11:50:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int     init_wall_map_array(t_env *env)
{
    int i;
    int j;
    int k;

    k = 0;
    i = 0;
    while (i < env->nb_sectors)
    {
        j = 0;
        ft_printf("i: %d\n", i);
        while(j < env->sectors[i].nb_vertices)
        {
            ft_printf("j: %d\n", j);
            if (set_sector_wall_map_array(&env->sectors[i],
		        &env->wall_textures[env->sectors[i].textures[j]],
		        i, env))
		        return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int     init_ceiling_map_array(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_sectors)
    {
        if (set_sector_ceiling_map_array(&env->sectors[i],
	    	&env->wall_textures[env->sectors[i].
		    ceiling_texture], env))
		    return (-1);
        i++;
    }
    return (0);
}

int     init_floor_map_array(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_sectors)
    {
        if (set_sector_floor_map_array(&env->sectors[i],
		    &env->wall_textures[env->sectors[i].floor_texture],
		    env))
	        return (-1);
        i++;
    }
    return (0);
}

int     init_mipmap_arrays(t_env *env)
{
    ft_printf("calculs post mipmap..\n");
    if (init_wall_map_array(env))
        return (-1);
    if (init_floor_map_array(env))
        return (-1);
    if (init_ceiling_map_array(env))
        return (-1);
    return (0);
}