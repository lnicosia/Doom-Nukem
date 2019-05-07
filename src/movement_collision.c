/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/05/07 14:52:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "collision.h"

int     in_range(double nb, double val1, double val2)
{
    double min;
    double max;

    min = (val1 <= val2) ? val1 : val2;
    max = (val1 > val2) ? val1 : val2;
    if (nb > min && nb <= max)
        return (1);
    return (0);
}

int     diff_value(int nb1, int nb2, int a, int b)
{
    if ((nb1 == a && nb2 == b) || (nb1 == b && nb2 == a))
        return (0);
    return (1);
}

int     diff_sign(double nb1, double nb2, t_env *env)
{
     if (nb1 == 0)
     {
        env->player.speed = env->player.speed;
        ft_printf("<--->\nnb1 = 0\n<--->\n");
        return (0);
     }
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0))
        return (0);
    return (1);
}

int     check_ceiling(t_env *env, t_movement motion)
{
    FUTURE_Z = 6 + env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
    if (FUTURE_Z > env->sectors[env->player.sector].ceiling + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].ceiling_slope - 1)
        return (0);
    return (1);
}

int     check_floor(t_env *env, t_movement motion)
{
    FUTURE_Z = 6 + env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
    if (env->player.pos.z + 2 < FUTURE_Z)
    {
       // ft_printf("current z pos %f\n future Z %f\n", env->player.pos.z, FUTURE_Z);
        return (0);
    }
    return (1);
}

int     check_wall(t_env *env, int i, t_movement motion)
{
    if ((PLAYER_XPOS >= X1 && PLAYER_XPOS <= X2) || (PLAYER_XPOS >= X2 && PLAYER_XPOS <= X1))
        return (1);
    if ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1))
        return (1);
    if ((FUTURE_Y >= Y1 && FUTURE_Y <= Y2) || (FUTURE_Y >= Y2 && FUTURE_Y <= Y1))
        return (1);
    if ((FUTURE_X >= X1 && FUTURE_X <= X2) || (FUTURE_X >= X2 && FUTURE_X <= X1))
        return (1);
    return (0);
}

int     check_inside_sector_bis(t_env *env, t_movement motion)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    //ft_printf("inside sector bis: %d\n", env->player.sector);
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos, env) && in_range(FUTURE_Y, Y1, Y2))
            count++;
        i++;
    }
    //ft_printf("count %d\n", count);
    if (count % 2 == 0 || !check_floor(env, motion))
        return (0);
    return (1);
}

int     check_collision_rec(t_env *env, t_movement motion, t_sector sector)
{
    short   i;
    double  start_pos;
    double  end_pos;

    i = 0;
    if (env->options.wall_lover == 1)
        return (1);
    env->player.pos.z = 6 + env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
    //ft_printf("collision rec\n");
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (PLAYER_XPOS - X1) * (Y2 - Y1) - (PLAYER_YPOS - Y1) * (X2 - X1);
        end_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (end_pos == 0)
        {
                env->player.speed = env->player.speed * 0.7;
                return (check_collision_rec(env, motion, sector));
        }
        if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, motion) && NEIGHBOR < 0 
            && diff_value(motion.wall_v1 , motion.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num,  env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
            return (0);
        else if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, motion) && NEIGHBOR >= 0
         && diff_value(motion.wall_v1, motion.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
        {
            env->player.sector = NEIGHBOR;
            motion.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            motion.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            if (!check_inside_sector_bis(env, motion) || !check_floor(env, motion))
                return (0);
            return (1);
        }
        i++;
    }
    return (0);
}

int     check_inside_sector(t_env *env, t_movement motion, t_sector sector)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    if (!check_floor(env, motion))
        return (0);
    //ft_printf("<------------------------------------------->\nchecking next sector: %d\n", env->player.sector);
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos, env) && in_range(FUTURE_Y, Y1, Y2))
        {
            //ft_printf("vertice %i-%i\n", env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i+1]].num);
            /* ft_printf("start_pos = %f\n", start_pos);
            ft_printf("end_pos = %f\n", end_pos); */
            count++;
        }
        i++;
    }
    //ft_printf("count = %d\n", count);
    if (count % 2 == 0)
    {
       // ft_printf("I'm out of the sector %d\n", env->player.sector);
        if (check_collision_rec(env, motion, sector))
            return (1);
        return (0);
    }
    else if (!check_floor(env, motion))
        return (0);
   // player_line = line_equation(env->player.pos.x, env->player.pos.y, env->player.pos.x + x_move, env->player.pos.y + y_move);
    return (1);
}

int     check_collision(t_env *env, double x_move, double y_move, t_sector sector)
{
    short   i;
    t_movement  motion;
    double  start_pos;
    double  end_pos;

    i = 0;
    if (env->options.wall_lover == 1)
        return (1);
    FUTURE_X = env->player.pos.x + x_move;
    FUTURE_Y = env->player.pos.y + y_move;
    /*
    **On parcourt tout les murs et portails du secteur actuel afin de verifier si le joueur rentre dedans
    */
    if (!check_ceiling(env, motion) || !check_floor(env, motion))
        return (0);
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        /*
        ** On prends la position de depart du joueur et sa position d'arrivee et on verifie 
        ** si il passe de l'autre coté du mur avec diff_sign.
        ** Si les signes de start_pos et end_pos sont differents c'est qu'il est passé de l'autre coté
        **
        ** On verifie aussi qu'il soit bien en train de passer dans un mur et non pas a coté (cas de secteurs concaves)
        ** avec check_wall
        **
        ** Et finalement on regarde si c'est un mur ou un portail
        */
        start_pos = (PLAYER_XPOS - X1) * (Y2 - Y1) - (PLAYER_YPOS - Y1) * (X2 - X1);
        end_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (end_pos == 0)
        {
                env->player.speed = env->player.speed * 0.7;
                return (check_collision(env, x_move * 0.7, y_move * 0.7, sector));
        }
        if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, motion) && NEIGHBOR < 0)
            return (0);
        else if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, motion) && NEIGHBOR >= 0)
        {
            motion.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            motion.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            motion.old_sector = env->player.sector;
            motion.old_z = env->player.pos.z;
            env->player.sector = NEIGHBOR;
            if (!check_inside_sector(env, motion, sector) || !check_ceiling(env, motion))
            {
                env->player.sector = motion.old_sector;
                env->player.pos.z = motion.old_z;
                return (0);
            }
            return (1);
        }
        i++;
    }
    return (1);
}