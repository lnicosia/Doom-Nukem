/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:09:06 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/13 19:28:01 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

double     sector_height(t_env *env, t_v3 pos, int sector_dest, double eyesight)
{
    pos.z = eyesight + env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (pos.x - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (pos.y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    return (pos.z);
}

void     iter_sectors_rec(t_env *env, t_v3 pos, t_wall wall)
{
    short       i;

    i = 0;
    env->sector_list[wall.sector_dest] = 1;
    while (i < env->sectors[wall.sector_dest].nb_vertices)
    {
        if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(pos.x, pos.y)) && RNEIGHBOR >= 0 &&
            env->sector_list[RNEIGHBOR] == 0)
        {
            wall.sector_or = wall.sector_dest;
            wall.sector_dest = RNEIGHBOR;
            iter_sectors_rec(env, pos, wall);
        }
        i++;
    }
    return;
}

void     iter_sectors(t_env *env, t_v3 pos, int sector)
{
    short		i;
    t_wall      wall;
    //static int a = 0;

    i = 0;
    while (i < env->nb_sectors)
    {
        if (i == sector)
            env->sector_list[i] = 1;
        else
            env->sector_list[i] = 0;
        i++;
    }
    i = 0;
    while (i < env->sectors[sector].nb_vertices)
    {
        if ((distance_two_points(X1, Y1, pos.x, pos.y) <= 0.75 || distance_two_points(X2, Y2, pos.x, pos.y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(pos.x, pos.y))) && NEIGHBOR >= 0)
        {
            wall.sector_or = sector;
            wall.sector_dest = NEIGHBOR;
            iter_sectors_rec(env, pos, wall);
        }
        i++;
    }
    return ;
}

int        find_highest_sector(t_env *env, t_v3 pos, int sector, double eyesight)
{
    int     i;
    double  height;
    double  s_height;
    int     tmp;

    i = 0;
    iter_sectors(env, pos, sector);
    tmp = sector;
    height = sector_height(env, pos, env->player.sector, eyesight);
    while (i < env->nb_sectors)
    {
        if (env->sector_list[i])
        {
            s_height = sector_height(env, pos, i, eyesight);
            if (height < s_height)
            {
                height = s_height;
                tmp = i;
            }
        }
        i++;
    }
    return (tmp);
}