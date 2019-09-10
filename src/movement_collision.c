/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/10 19:07:00 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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

t_v2     collision_rec(t_env *env, t_v2 move, t_v3 pos, t_wall wall, int recu)
{
    short       i;
    t_movement  motion;
    double      tmp;
    double      scalar;
    double      norme_mov;
    double      norme_wall;

    i = 0;
    FUTURE_X = move.x + pos.x;
    FUTURE_Y = move.y + pos.y;
    motion.old_sector = wall.sector_or;
    env->sector_list[wall.sector_dest] = 1;
    /*
    ** Permet de faire segfault pthread_join facilement sur triple piece
    **if (is_in_sector(env, env->player.sector, FUTURE_X, FUTURE_Y))
    **    return (1);
    */
    if (!check_ceiling(env, motion, wall.sector_dest) || !check_floor(env, motion, wall.sector_dest))
    {
        return (new_v2(0, 0));
    }
    while (i < env->sectors[wall.sector_dest].nb_vertices)
    {
        if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y)) && RNEIGHBOR < 0)
        {
            norme_mov = sqrt(move.x * move.x + move.y * move.y);
            norme_wall = sqrt((X2R - X1R) * (X2R - X1R) + (Y2R - Y1R) * (Y2R - Y1R));
            scalar = (X2R - X1R) / norme_wall * move.x / norme_mov + (Y2R - Y1R) / norme_mov * move.y;
            if (scalar > 0 && !recu)
            {
                tmp = move.x;
                move.x = norme_mov * (X2R - X1R) / norme_wall * ft_fclamp(scalar, 0.1, 1);
                move.y = norme_mov * (Y2R - Y1R) / norme_wall * ft_fclamp(scalar, 0.1, 1);
                return (collision_rec(env, move, pos, wall, 1));
            }
            else if (scalar < 0 && !recu)
            {
                tmp = move.x;
                move.x = norme_mov * (X2R - X1R) / norme_wall * ft_fclamp(scalar, -1, -0.1);
                move.y = norme_mov * (Y2R - Y1R) / norme_wall * ft_fclamp(scalar, -1, -0.1);
                return (collision_rec(env, move, pos, wall, 1));
            }
            return (new_v2(0, 0));
        }
        else if (hitbox_collision(new_v2(X1R, Y1R), new_v2(X2R, Y2R), new_v2(FUTURE_X, FUTURE_Y)) && RNEIGHBOR >= 0 &&
            env->sector_list[RNEIGHBOR] == 0)
        {
            wall.sector_or = wall.sector_dest;
            wall.sector_dest = RNEIGHBOR;
            return (collision_rec(env, move, pos, wall, 0));
        }
        i++;
    }
    return (move);
}

t_v2     check_collision(t_env *env, t_v2 move, t_v3 pos, int sector, int recu)
{
    short		i;
    short       j;
    t_movement  motion;
    t_wall      wall;
    double      tmp;
    double      scalar;
    double      norme_mov;
    double      norme_wall;
    static int a = 0;

    env->player.highest_sect = sector;
    FUTURE_X = pos.x + move.x;
    FUTURE_Y = pos.y + move.y;
    /*if (env->player.stuck == 1)
    {
        env->player.stuck = 0;
        if (is_in_sector_no_z(env, env->player.sector, new_v2(FUTURE_X, FUTURE_Y)))
            return (move);
        return (new_v2(0, 0));
    }*/
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
        /*
        ** If the player is inside a wall for some reason
        
        if ((distance_two_points(X1, Y1, env->player.pos.x, env->player.pos.y) <= 0.75 || distance_two_points(X2, Y2, env->player.pos.x, env->player.pos.y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(env->player.pos.x, env->player.pos.y))) && NEIGHBOR < 0)
        {
            env->player.stuck = 1;
            return (check_collision(env, move));
        }*/
        //ft_printf("move.x %f y %f\n", move.x, move.y);
        if ((distance_two_points(X1, Y1, FUTURE_X, FUTURE_Y) <= 0.75 || distance_two_points(X2, Y2, FUTURE_X, FUTURE_Y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y))) && NEIGHBOR < 0)
        {
            norme_mov = sqrt(move.x * move.x + move.y * move.y);
            norme_wall = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));
            scalar = (X2 - X1) / norme_wall * move.x / norme_mov + (Y2 - Y1) / norme_mov * move.y;
            if (scalar > 0 && !recu)
            {
                tmp = move.x;
                move.x = norme_mov * (X2 - X1) / norme_wall * ft_fclamp(scalar, 0.1, 1);
                move.y = norme_mov * (Y2 - Y1) / norme_wall * ft_fclamp(scalar, 0.1, 1);
                return (check_collision(env, move, pos, sector, 1));
            }
            else if (scalar < 0 && !recu)
            {
                tmp = move.x;
                move.x = norme_mov * (X2 - X1) / norme_wall * ft_fclamp(scalar, -1, -0.1);
                move.y = norme_mov * (Y2 - Y1) / norme_wall * ft_fclamp(scalar, -1, -0.1);
                return (check_collision(env, move, pos, sector, 1));
            }
            //ft_printf("YOU SHALL NOT PASS!! %d\n", a++);
            return (new_v2(0,0));
        }
        else if ((distance_two_points(X1, Y1, FUTURE_X, FUTURE_Y) <= 0.75 || distance_two_points(X2, Y2, FUTURE_X, FUTURE_Y) <= 0.75 || hitbox_collision(new_v2(X1, Y1), new_v2(X2, Y2), new_v2(FUTURE_X, FUTURE_Y))) && NEIGHBOR >= 0)
        {
            wall.sector_or = sector;
            wall.sector_dest = NEIGHBOR;
            move = collision_rec(env, move, pos, wall, 0);
            if (move.x != 0 || move.y != 0)
            {
                j = 0;
                while (j < env->nb_sectors)
                {
                    if (env->sector_list[j])
                    {
                        if (is_in_sector_no_z(env, j, new_v2(FUTURE_X, FUTURE_Y)))
                        {
                            /*if (!check_ceiling(env, motion, j) || !check_floor(env, motion, j))
                            {
                                env->player.stuck = 1;
                                return (check_collision(env, move));
                            }*/
                            env->player.sector = j;
                            j = env->nb_sectors;
                        }
                    }
                    j++;
                }
            }
            else
                return (new_v2(0, 0));
        }
        i++;
    }
    find_highest_sector(env, motion);
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

void        enemy_collision(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_enemies)
    {
        if (env->enemies[i].health > 0 && distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, PLAYER_XPOS, PLAYER_YPOS) < 1.75 && env->enemies[i].exists
            && env->enemies[i].pos.z >= PLAYER_ZPOS - 1 && env->enemies[i].pos.z <= env->player.eyesight + env->player.pos.z + 1)
        {
            env->player.hit = 1;
            env->player.life -= env->enemies[i].damage;
            env->enemies[i].exists = 0;
        }
        i++;
    }
}