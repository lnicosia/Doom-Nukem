/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:03:54 by gaerhard          #+#    #+#             */
/*   Updated: 2019/07/29 14:37:27 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}
/*
static int     check_wall(t_env *env, int i, t_object enemy, int sector)
{
    if ((enemy.pos.x >= OX1 && enemy.pos.x <= OX2) || (enemy.pos.x >= OX2 && enemy.pos.x <= OX1))
        return (1);
    if ((enemy.pos.y >= OY1 && enemy.pos.y <= OY2) || (enemy.pos.y >= OY2 && enemy.pos.y <= OY1))
        return (1);
    if ((env->player.pos.y >= OY1 && env->player.pos.y <= OY2) || (env->player.pos.y >= OY2 && env->player.pos.y <= OY1))
        return (1);
    if ((env->player.pos.x >= OX1 && env->player.pos.x <= OX2) || (env->player.pos.x >= OX2 && env->player.pos.x <= OX1))
        return (1);
    return (0);
}*/

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
        ft_fclamp(a_origin, a_dest, a_origin);
    }
    else
    {
        a_origin += 10;
        ft_fclamp(a_origin, a_origin, a_dest);
    }
    return (a_origin);
}

int    enemy_view(t_env *env, int nb, int sector)
{
    t_object    enemy;
    int         i;
    double      start_pos;
    double      end_pos;
    static int  a = 0;

    ft_printf("test sector %d\n", sector);
    i = 0;
    enemy = env->objects[nb];
    while (i < env->sectors[sector].nb_vertices)
    {
        start_pos = (enemy.pos.x - OX1) * (OY2 - OY1) - (enemy.pos.y - OY1) * (OX2 - OX1);
        end_pos = (env->player.pos.x - OX1) * (OY2 - OY1) - (env->player.pos.y - OY1) * (OX2 - OX1);
        if (diff_sign(start_pos, end_pos) && /*check_wall(env, i, enemy, sector) &&*/ env->sectors[sector].neighbors[i] < 0)
            return (0);
        else if (diff_sign(start_pos, end_pos) /*&& check_wall(env, i, enemy, sector)*/ && env->sectors[sector].neighbors[i] >= 0 &&
            env->sector_list[env->sectors[sector].neighbors[i]] == 0 && end_pos != 0)
        {
            env->sector_list[env->sectors[sector].neighbors[i]] = 1;
            return (enemy_view(env, nb, env->sectors[sector].neighbors[i]));
        }
        i++;
    }
    ft_printf("he saw me %d\n", a++);
    return (1);
}


bool onLine(line l1, Point p) {   //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
      return true;
   
   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;     //colinear
   else if(val < 0)
      return 2;    //anti-clockwise direction
      return 1;    //clockwise direction
}

int isIntersect(line l1, line l2) {
   //four direction for two lines and points of other line
   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);
   
   if(dir1 != dir2 && dir3 != dir4)
      return true; //they are intersecting

   if(dir1==0 && onLine(l1, l2.p1)) //when p2 of line2 are on the line1
      return true;

   if(dir2==0 && onLine(l1, l2.p2)) //when p1 of line2 are on the line1
      return true;

   if(dir3==0 && onLine(l2, l1.p1)) //when p2 of line1 are on the line2
      return true;

   if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return true;
         
   return false;
}

void    enemy_pursuit(t_env *env)
{
    int     i;
    int     j;
    t_v3    direction;
    //t_v2    p;
    double  tmp_z;
    //static int a = 0;

    i = 0;
    while (i < env->nb_objects)
    {
        j = 0;
        while (j < env->nb_sectors)
        {
            if (j == env->objects[i].sector)
                env->sector_list[j] = 1;
            else
                env->sector_list[j] = 0;
            j++;
        }
        if (env->objects[i].sprite == 1 && enemy_view(env, i, env->objects[i].sector))
        {
            tmp_z = env->player.pos.z;
            env->player.pos.z = env->player.eyesight;
            direction = sprite_movement(0.4, env->objects[i].pos, env->player.pos);
            env->player.pos.z = tmp_z;

            /* env->objects[i].pos.x += direction.x;
            env->objects[i].pos.y += direction.y;
            env->objects[i].pos.z += direction.z;
            p.x = env->objects[i].pos.x;
            p.y = env->objects[i].pos.y;
            env->objects[i].sector = get_sector(env, p, env->objects[i].sector); */

            //env->objects[i].angle = -env->player.angle * CONVERT_DEGREES;
            /*ft_printf("angle player %f\n", env->player.angle* CONVERT_DEGREES);
            ft_printf("enemy %f\n", env->objects[i].angle);
            env->objects[i].angle = sprite_rotate(env->objects[i].angle, -env->player.angle * CONVERT_DEGREES);*/
        }
        i++;
    }
}