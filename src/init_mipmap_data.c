/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mipmap_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 16:48:11 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 20:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int     init_wall_map_array(t_env *env)
{
    int i;
    int j;

    i = 0;
    while (i < env->nb_sectors)
    {
        j = 0;
        while(j < env->sectors[i].nb_vertices)
        {
            if (set_sector_wall_map_array(&env->sectors[i],
		        &env->wall_textures[env->sectors[i].textures[j]],
		        j, env))
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
    ft_printf("Initializing sectors mipmap arrays..\n");
    if (init_wall_map_array(env))
        return (-1);
    if (init_floor_map_array(env))
        return (-1);
    if (init_ceiling_map_array(env))
        return (-1);
    return (0);
}
