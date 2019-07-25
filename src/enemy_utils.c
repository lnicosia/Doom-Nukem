/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:03:54 by gaerhard          #+#    #+#             */
/*   Updated: 2019/07/25 17:38:37 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Function needs to be moved to another file
*/

t_v3    sprite_movement(double speed, t_v3 origin, t_v3 destination)
{
    t_v3    direction;
    double  distance;

    direction.x = destination.x - origin.x;
    direction.y = destination.y - origin.y;
    direction.z = destination.z - origin.z;
    if (direction.x == 0 && direction.y == 0 && direction.z == 0)
        return (direction);
    distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
    direction.x = direction.x * speed / distance;
    direction.y = direction.y * speed / distance;
    direction.z = direction.y * speed / distance;
    return (direction);
}

double    sprite_rotate(double a_origin, double a_dest)
{
    if (a_origin < a_dest)
    {
        a_origin -= 10;
        ft_clamp(a_origin, a_origin, a_dest);
    }
    else
    {
        a_origin += 10;
        ft_clamp(a_origin, a_origin, a_dest);
    }
    return (a_origin);
}

void    enemy_pursuit(t_env *env)
{
    int     i;
    t_v3    direction;
    double  tmp_z;
    //static int a = 0;

    i = 0;
    while (i < env->nb_objects)
    {
        if (env->objects[i].sprite == 1 && env->objects[i].seen)
        {
            tmp_z = env->player.pos.z;
            env->player.pos.z = env->player.eyesight;
            direction = sprite_movement(0.4, env->objects[i].pos, env->player.pos);
            env->player.pos.z = tmp_z;
            env->objects[i].pos.x += direction.x;
            env->objects[i].pos.y += direction.y;
            env->objects[i].pos.z += direction.z;

            /* env->objects[i].angle = -env->player.angle * CONVERT_DEGREES * 0;
            ft_printf("angle player %f\n", env->player.angle* CONVERT_DEGREES);
            ft_printf("enemy %f\n", env->objects[i].angle); */
            //env->objects[i].angle = sprite_rotate(env->objects[i].angle, -env->player.angle * CONVERT_DEGREES - 180);
        }
        i++;
    }
}