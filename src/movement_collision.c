/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/08/30 13:19:19 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*void    move_alongside_wall(t_env *env, double x_move, double y_move, int i)
{
    float xd;
    float yd;
    t_movement motion;
    
    xd = X2 - X1;
    yd = Y2 - Y1;
    x_move = xd * (x_move*xd + yd*y_move) / (xd*xd + yd*yd);
    y_move = yd * (x_move*xd + yd*y_move) / (xd*xd + yd*yd);
    FUTURE_X = PLAYER_XPOS + x_move;
    FUTURE_Y = PLAYER_YPOS + y_move;
    motion.old_sector = env->player.sector;
    if (check_inside_sector(env, motion))
    {
        PLAYER_XPOS = FUTURE_X;
        PLAYER_YPOS = FUTURE_Y;
    }
} */
/*
int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}*/

double     sector_height(t_env *env, t_movement motion, int sector_dest)
{
    FUTURE_Z = env->player.eyesight + env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    return (FUTURE_Z);
}

void        find_highest_sector(t_env *env, t_movement motion)
{
    int     i;
    double  height;
    double  s_height;
    int     tmp;

    i = 0;
    tmp = env->player.sector;
    height = sector_height(env, motion, env->player.sector);
    while (i < env->nb_sectors)
    {
        if (env->sector_list[i])
        {
            s_height = sector_height(env, motion, i);
            if (height < s_height)
            {
                height = s_height;
                tmp = i;
            }
        }
        i++;
    }
    //ft_printf("mov_collision.c l71\n");
    env->player.highest_sect = tmp;
}

int     check_ceiling(t_env *env, t_movement motion, int sector_dest)
{
    FUTURE_Z = env->player.eyesight + env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    if (FUTURE_Z > env->sectors[sector_dest].ceiling + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].ceiling_slope - 1)
        return (0);
    return (1);
}

int     check_floor(t_env *env, t_movement motion, int sector_dest)
{
    FUTURE_Z = env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    if (FUTURE_Z > env->player.pos.z + 2)
		return (0);
    return (1);
}

double     distance_two_points(double x1, double y1, double x2, double y2)
{
    double  d;
    double  x_sub;
    double  y_sub;

    x_sub = x2 - x1;
    y_sub = y2 - y1;
    d = sqrt(x_sub * x_sub + y_sub * y_sub);
    return (d);
}

int     hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p)
{
    double a;
    double b;
    double c;
    double delta;
    double sqrt_delta;
    double t1;
    double t2;

    v1.x -= p.x;
    v1.y -= p.y;
    v2.x -= p.x;
    v2.y -= p.y;
    c = v1.x * v1.x + v1.y * v1.y - 0.5625;
    b = 2 * (v1.x * (v2.x - v1.x) + v1.y *(v2.y - v1.y));
    a = (v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y);
    delta = b * b - 4 * a * c;
    if (delta <= 0)
        return (0);
    sqrt_delta = sqrt(delta);
    t1 = (-b + sqrt_delta) / (2 * a);
    t2 = (-b - sqrt_delta) / (2 * a);
    if((0 < t1 && t1 < 1) || (0 < t2 && t2 < 1))
        return (1);
    return 0;
}

int     collision_rec(t_env *env, double dest_x, double dest_y, t_wall wall)
{
    short       i;
    t_movement  motion;

    i = 0;
    FUTURE_X = dest_x;
    FUTURE_Y = dest_y;
    motion.old_sector = wall.sector_or;
    env->sector_list[wall.sector_dest] = 1;
    /*
    ** Permet de faire segfault pthread_join facilement sur triple piece
    **if (is_in_sector(env, env->player.sector, FUTURE_X, FUTURE_Y))
    **    return (1);
    */
    if (!check_ceiling(env, motion, wall.sector_dest) || !check_floor(env, motion, wall.sector_dest))
    {
        //ft_printf("cheh you're stuck\n");
        return (0);
    }
    while (i < env->sectors[wall.sector_dest].nb_vertices)
    {
        if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y)) && RNEIGHBOR < 0)
            return (0);
        else if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y)) && RNEIGHBOR >= 0 &&
            env->sector_list[RNEIGHBOR] == 0)
        {
            wall.sector_or = wall.sector_dest;
            wall.sector_dest = RNEIGHBOR;
            return (collision_rec(env, FUTURE_X, FUTURE_Y, wall));
        }
        i++;
    }
    return (1);
}

int     check_collision(t_env *env, double x_move, double y_move)
{
    short		i;
    short       j;
    t_movement  motion;
    t_wall      wall;
    //static int a = 0;

    env->player.highest_sect = env->player.sector;
    FUTURE_X = env->player.pos.x + x_move;
    FUTURE_Y = env->player.pos.y + y_move;
    if (env->player.stuck == 1)
    {
        env->player.stuck = 0;
        if (is_in_sector_no_z(env, env->player.sector, new_v2(FUTURE_X, FUTURE_Y)))
            return (1);
        return (0);
    }
    i = 0;
    while (i < env->nb_sectors)
    {
        if (i == env->player.sector)
            env->sector_list[i] = 1;
        else
            env->sector_list[i] = 0;
        i++;
    }
    i = 0;
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        /*
        ** If the player is inside a wall for some reason
        */
        if ((distance_two_points(X1, Y1, env->player.pos.x, env->player.pos.y) <= 0.75 || distance_two_points(X2, Y2, env->player.pos.x, env->player.pos.y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(env->player.pos.x, env->player.pos.y))) && NEIGHBOR < 0)
        {
            env->player.stuck = 1;
            return (check_collision(env, x_move, y_move));
        }
        if ((distance_two_points(X1, Y1, FUTURE_X, FUTURE_Y) <= 0.75 || distance_two_points(X2, Y2, FUTURE_X, FUTURE_Y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y))) && NEIGHBOR < 0)
            return (0);
        else if ((distance_two_points(X1, Y1, FUTURE_X, FUTURE_Y) <= 0.75 || distance_two_points(X2, Y2, FUTURE_X, FUTURE_Y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y))) && NEIGHBOR >= 0)
        {
            wall.sector_or = env->player.sector;
            wall.sector_dest = NEIGHBOR;
            if (collision_rec(env, FUTURE_X, FUTURE_Y, wall))
            {
                j = 0;
                while (j < env->nb_sectors)
                {
                    if (env->sector_list[j])
                    {
                        if (is_in_sector_no_z(env, j, new_v2(FUTURE_X, FUTURE_Y)))
                        {
                            if (!check_ceiling(env, motion, j) || !check_floor(env, motion, j))
                            {
                                env->player.stuck = 1;
                                return (check_collision(env, x_move, y_move));
                            }
                            env->player.sector = j;
                            j = env->nb_sectors;
                        }
                    }
                    j++;
                }
            }
            else
                return (0);
        }
        i++;
    }
    find_highest_sector(env, motion);
    return (1);
}

void    objects_collision(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_objects)
    {
        if (env->objects[i].exists && distance_two_points(env->objects[i].pos.x, env->objects[i].pos.y, PLAYER_XPOS, PLAYER_YPOS) < 1.75
            /* && (ft_abs(env->player.pos.z - env->objects[i].pos.z) <= 2 || ft_abs(env->player.head_z - env->objects[i].pos.z) <= 2) */)
        {
            if (env->objects[i].sprite == 0 && env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
            {
                env->weapons[env->player.curr_weapon].ammo += 10;
                    env->objects[i].exists = 0;
                if (env->weapons[env->player.curr_weapon].ammo >= env->weapons[env->player.curr_weapon].max_ammo)
                    env->weapons[env->player.curr_weapon].ammo = env->weapons[env->player.curr_weapon].max_ammo;
            }
            else if (env->objects[i].sprite == 1)
            {
                env->player.hit = 1;
                env->player.life -= 15;
                env->objects[i].exists = 0;
            }
        }
        i++;
    }
}
