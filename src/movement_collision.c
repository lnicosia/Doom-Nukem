/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/26 14:34:38 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int     check_ceiling(t_env *env, t_movement motion, int sector_dest)
{
    double curr_z;

    //FUTURE_Z = motion.eyesight + env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    curr_z = motion.pos.z + motion.eyesight;
    if (curr_z > env->sectors[sector_dest].ceiling + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].ceiling_slope - 1)
        return (0);
    return (1);
}

int     check_floor(t_env *env, t_movement motion, int sector_dest)
{
    FUTURE_Z = env->sectors[sector_dest].floor + (env->sectors[sector_dest].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[sector_dest].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[sector_dest].floor_slope;
    if (FUTURE_Z > motion.pos.z + 2)
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

int     hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p, double size)
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
    c = v1.x * v1.x + v1.y * v1.y - size * size;
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

t_v2     collision_rec(t_env *env, t_v2 move, t_movement motion, int recu)
{
    short       i;
    t_wall      wall;
    double      scalar;
    double      norme_mov;
    double      norme_wall;

    i = 0;
    wall = motion.wall;
    FUTURE_X = move.x + motion.pos.x;
    FUTURE_Y = move.y + motion.pos.y;
    env->sector_list[wall.sector_dest] = 1;
    norme_mov = sqrt(move.x * move.x + move.y * move.y);
    if ((!check_ceiling(env, motion, wall.sector_dest) || !check_floor(env, motion, wall.sector_dest)) && !recu)
    {
        scalar = wall.x / wall.norme * move.x / norme_mov + wall.y / wall.norme * move.y / norme_mov;
        if (scalar != 0 && !recu)
        {
            move.x = norme_mov * wall.x / wall.norme * scalar;
            move.y = norme_mov * wall.y / wall.norme * scalar;
            return (collision_rec(env, move, motion, 1));
        }
        return (new_v2(0, 0));
    }
    while (i < env->sectors[wall.sector_dest].nb_vertices)
    {
        if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y), motion.size_2d) && RNEIGHBOR < 0)
        {
            norme_wall = sqrt((X2R - X1R) * (X2R - X1R) + (Y2R - Y1R) * (Y2R - Y1R));
            scalar = (X2R - X1R) / norme_wall * move.x / norme_mov + (Y2R - Y1R) / norme_wall * move.y / norme_mov;
            if (scalar != 0 && !recu)
            {
                move.x = norme_mov * (X2R - X1R) / norme_wall * scalar;
                move.y = norme_mov * (Y2R - Y1R) / norme_wall * scalar;
                return (collision_rec(env, move, motion, 1));
            }
            return (new_v2(0, 0));
        }
        i++;
    }
    i = 0;
    while (i < env->sectors[wall.sector_dest].nb_vertices)
    {
        if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y), motion.size_2d) && RNEIGHBOR >= 0 &&
            env->sector_list[RNEIGHBOR] == 0)
        {
            if ((!check_ceiling(env, motion, wall.sector_dest) || !check_floor(env, motion, RNEIGHBOR)))
                return (new_v2(0, 0));
            motion.wall.sector_or = wall.sector_dest;
            motion.wall.sector_dest = RNEIGHBOR;
            return (collision_rec(env, move, motion, 0));
        }
        i++;
    }
    return (move);
}

t_v2     check_collision(t_env *env, t_v2 move, t_movement motion, int rec)
{
    short		i;
    double      scalar;
    double      norme_mov;
    double      norme_wall;
    //static int a = 0;

    //env->player.highest_sect = motion.sector;
    if (env->options.test)
        return (move);
    FUTURE_X = motion.pos.x + move.x;
    FUTURE_Y = motion.pos.y + move.y;
    i = 0;
    while (i < env->nb_sectors)
    {
        if (i == motion.sector)
            env->sector_list[i] = 1;
        else
            env->sector_list[i] = 0;
        i++;
    }
    i = 0;
    if (motion.sector == -1)
    {
        ft_printf("l153\n");
        return (new_v2(0,0));
    }
    while (i < env->sectors[motion.sector].nb_vertices)
    {
        if ((hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y), motion.size_2d)) && NEIGHBOR < 0)
        {
            norme_mov = sqrt(move.x * move.x + move.y * move.y);
            norme_wall = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
            scalar = (X2 - X1) / norme_wall * move.x / norme_mov + (Y2 - Y1) / norme_wall * move.y / norme_mov;
            if (scalar != 0 && !rec)
            {
                move.x = norme_mov * (X2 - X1) / norme_wall * scalar;
                move.y = norme_mov * (Y2 - Y1) / norme_wall * scalar;
                return (check_collision(env, move, motion, 1));
            }
            return (new_v2(0,0));
        }
        i++;
    }
    i = 0;
    while (i < env->sectors[motion.sector].nb_vertices)
    {
        if ((hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y), motion.size_2d)) && NEIGHBOR >= 0)
        {
            motion.wall.sector_or = motion.sector;
            motion.wall.sector_dest = NEIGHBOR;
            motion.wall.norme = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
            motion.wall.x = (X2 - X1);
            motion.wall.y = (Y2 - Y1);
            move = collision_rec(env, move, motion, 0);
            if (move.x == 0 && move.y == 0)
                return (new_v2(0, 0));
        }
        i++;
    }
    return (move);
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
        }
        i++;
    }
}