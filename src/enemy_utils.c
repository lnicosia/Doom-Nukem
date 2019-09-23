/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:03:54 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/23 18:32:12 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*static int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}*/
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

    //ft_printf("%f\n", speed);
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

double  min_val(double nb1, double nb2)
{
    if (nb1 <= nb2)
        return (nb1);
    else
        return (nb2);
}

double  max_val(double nb1, double nb2)
{
    if (nb1 >= nb2)
        return (nb1);
    else
        return (nb2);
}

int onLine(t_segment l1, t_v2 p)
{
    //check whether p is on the line or not
    if(p.x <= max_val(l1.p1.x, l1.p2.x) && p.x <= min_val(l1.p1.x, l1.p2.x) &&
        (p.y <= max_val(l1.p1.y, l1.p2.y) && p.y <= min_val(l1.p1.y, l1.p2.y)))
      return (1);
   return (0);
}

int direction(t_v2 a, t_v2 b, t_v2 c)
{
    int val;

    val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0)
        return (0);     //colinear
    else if (val < 0)
        return (2);    //anti-clockwise direction
    return (1);    //clockwise direction
}

int intersect(t_segment l1, t_segment l2) {
   //four direction for two lines and points of other line
   int dir1;
   int dir2;
   int dir3;
   int dir4;
//   static int a=0;
   
   dir1 = direction(l1.p1, l1.p2, l2.p1);
   dir2 = direction(l1.p1, l1.p2, l2.p2);
   dir3 = direction(l2.p1, l2.p2, l1.p1);
   dir4 = direction(l2.p1, l2.p2, l1.p2);
   if (dir1 != dir2 && dir3 != dir4)
      return (1); //they are intersecting
   if (dir1 == 0 && onLine(l1, l2.p1)) //when p2 of line2 are on the line1
      return (1);
   if (dir2 == 0 && onLine(l1, l2.p2)) //when p1 of line2 are on the line1
      return (1);
   if(dir3 == 0 && onLine(l2, l1.p1)) //when p2 of line1 are on the line2
        return (1);
   if(dir4 == 0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return (1);
    //ft_printf("hello?%d\n", a++);
   return (0);
}

int    enemy_view(t_env *env, int nb, int sector)
{
    t_enemies    enemy;
    int         i;
    t_segment   line_1;
    t_segment   line_2;
    //double      start_pos;
    //double      end_pos;
    //static int  a = 0;

    //ft_printf("test sector %d\n", sector);
    i = 0;
    enemy = env->enemies[nb];
    if (sector == env->player.sector)
        return (1);
    while (i < env->sectors[sector].nb_vertices)
    {
        line_1.p1.x = OX1;
        line_1.p1.y = OY1;
        line_1.p2.x = OX2;
        line_1.p2.y = OY2;
        line_2.p1.x = enemy.pos.x;
        line_2.p1.y = enemy.pos.y;
        line_2.p2.x = env->player.pos.x;
        line_2.p2.y = env->player.pos.y;
        if (intersect(line_1, line_2) && env->sectors[sector].neighbors[i] < 0)
        {
            //ft_printf("collision%d\n", a++);
            return (0);}
        else if (intersect(line_1, line_2) && env->sectors[sector].neighbors[i] >= 0 &&
            env->sector_list[env->sectors[sector].neighbors[i]] == 0)
        {
            //ft_printf("sector testes = %d\n", env->sectors[sector].neighbors[i]);
            env->sector_list[env->sectors[sector].neighbors[i]] = 1;
            return (enemy_view(env, nb, env->sectors[sector].neighbors[i]));
        }
        /*start_pos = (enemy.pos.x - OX1) * (OY2 - OY1) - (enemy.pos.y - OY1) * (OX2 - OX1);
        end_pos = (env->player.pos.x - OX1) * (OY2 - OY1) - (env->player.pos.y - OY1) * (OX2 - OX1);
        if (diff_sign(start_pos, end_pos) && check_wall(env, i, enemy, sector) && env->sectors[sector].neighbors[i] < 0)
            return (0);
        else if (diff_sign(start_pos, end_pos) && check_wall(env, i, enemy, sector) && env->sectors[sector].neighbors[i] >= 0 &&
            env->sector_list[env->sectors[sector].neighbors[i]] == 0 && end_pos != 0)
        {
            env->sector_list[env->sectors[sector].neighbors[i]] = 1;
            return (enemy_view(env, nb, env->sectors[sector].neighbors[i]));
        }*/
        i++;
    }
    /*if (sector != env->player.sector)
        return (0);*/
    return (1);
}

void    enemy_pursuit(t_env *env)
{
    int     i;
    int     j;
    double  distance;
    t_v3    direction;
    t_v2    move;
    double  tmp_z;
    //static int a = 0;

    i = 0;
    while (i < env->nb_enemies)
    {
        j = 0;
        while (j < env->nb_sectors)
        {
            if (j == env->enemies[i].sector)
                env->sector_list[j] = 1;
            else
                env->sector_list[j] = 0;
            j++;
        }
        env->enemies[i].state = RESTING;
        distance = distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
        if (env->enemies[i].exists && env->enemies[i].health > 0 && 
            distance <= 50 && (distance >= 30 || !env->enemies[i].ranged) && env->enemies[i].seen)
        {
            env->enemies[i].state = PURSUING;
            tmp_z = env->player.pos.z;
            env->player.pos.z = env->player.eyesight;
            direction = sprite_movement((double)env->enemies[i].speed / 200, env->enemies[i].pos, env->player.pos);
          /*  direction.x = 0;
            direction.y = 0;
            direction.z = 0;*/
            env->player.pos.z = tmp_z;
            if (move.x == 0 && move.y == 0)
            {
                env->enemies[i].dir = rand_dir(env, i);
                if (env->enemies[i].dir == 0)
                {
                    move.x = -direction.y;
                    move.y = direction.x;
                }
                else if (env->enemies[i].dir == 1)
                {
                    move.x = direction.y;
                    move.y = -direction.x;
                }
                move = check_collision(env, move, new_movement(env->enemies[i].sector, env->enemies[i].size_2d, env->enemies[i].eyesight, env->enemies[i].pos), 1);
            }

            env->enemies[i].pos.x += direction.x;
            env->enemies[i].pos.y += direction.y;
            env->enemies[i].pos.z += direction.z;
            env->enemies[i].sector = get_sector(env, env->enemies[i].pos, env->enemies[i].sector);


            env->enemies[i].angle = (env->player.camera.angle * CONVERT_DEGREES) + 180;
        }
        if (env->enemies[i].ranged && distance <= 31 && env->enemies[i].seen)
        {
            env->enemies[i].state = FIRING;
            env->player.life -= (env->enemies[i].shot) ? env->enemies[i].damage : 0;
            env->enemies[i].shot = 0;
        }
        i++;
    }
}
