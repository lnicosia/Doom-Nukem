/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/05/02 19:26:39 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int     check_wall(t_env *env, int i, double future_x, double future_y)
{
    if ((PLAYER_XPOS >= X1 && PLAYER_XPOS <= X2) || (PLAYER_XPOS >= X2 && PLAYER_XPOS <= X1))
        return (1);
    if ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1))
        return (1);
    if ((future_y >= Y1 && future_y <= Y2) || (future_y >= Y2 && future_y <= Y1))
        return (1);
    if ((future_x >= X1 && future_x <= X2) || (future_x >= X2 && future_x <= X1))
        return (1);
    return (0);
}

int     check_inside_sector_bis(t_env *env, double x, double y)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    ft_printf("inside sector bis: %d\n", env->player.sector);
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        start_pos = (x - X1) * (Y2 - Y1) - (y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos, env) && in_range(y, Y1, Y2))
        {
            count++;
        }
        i++;
    }
    ft_printf("count %d\n", count);
    if (count % 2 == 0)
        return (0);
    //player_line = line_equation(env->player.pos.x, env->player.pos.y, env->player.pos.x + x_move, env->player.pos.y + y_move);
    return (1);
}

int     check_collision_rec(t_env *env, double future_x, double future_y)
{
    short   i;
    double  start_pos;
    double  end_pos;

    i = 0;
    if (env->options.wall_lover == 1)
        return (1);
    ft_printf("collision rec\n");
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        start_pos = (PLAYER_XPOS - X1) * (Y2 - Y1) - (PLAYER_YPOS - Y1) * (X2 - X1);
        end_pos = (future_x - X1) * (Y2 - Y1) - (future_y - Y1) * (X2 - X1);
        if (end_pos == 0)
        {
                env->player.speed = env->player.speed * 0.7;
                return (check_collision_rec(env, future_x * 0.7, future_y * 0.7));
        }
        if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, future_x, future_y) && env->sectors[env->player.sector].neighbors[i] < 0 
            && diff_value(env->player.wall_v1 , env->player.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num,  env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
            return (0);
        else if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, future_x, future_y) && env->sectors[env->player.sector].neighbors[i] >= 0
         && diff_value(env->player.wall_v1, env->player.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
        {
            env->player.sector = env->sectors[env->player.sector].neighbors[i];
            env->player.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            env->player.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            if (!check_inside_sector_bis(env, future_x, future_y))
                return (0);
            return (1);
        }
        i++;
    }
    return (1);
}

t_line_eq  line_equation(double x1, double y1, double x2, double y2)
{
    t_line_eq  line_eq;

    line_eq.a = (y2 - y1) / (x2 - x1);
    line_eq.b = y1 - line_eq.a * x1;
    return (line_eq);
}

int     check_inside_sector(t_env *env, double x, double y)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    ft_printf("<------------------------------------------->\nchecking next sector: %d\n", env->player.sector);
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        start_pos = (x - X1) * (Y2 - Y1) - (y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos, env) && in_range(y, Y1, Y2))
        {
            //ft_printf("vertice %i-%i\n", env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i+1]].num);
            /* ft_printf("start_pos = %f\n", start_pos);
            ft_printf("end_pos = %f\n", end_pos); */
            count++;
        }
        i++;
    }
    ft_printf("count = %d\n", count);
    if (count % 2 == 0)
    {
        ft_printf("I'm out of the sector %d\n", env->player.sector);
        if (env->options.test)
        {
            if (check_collision_rec(env, x, y))
                return (1);
        }
        return (0);
    }
   // player_line = line_equation(env->player.pos.x, env->player.pos.y, env->player.pos.x + x_move, env->player.pos.y + y_move);
    return (1);
}

int     check_collision(t_env *env, double x_move, double y_move)
{
    short   i;
    double  future_x;
    double  future_y;
    double  start_pos;
    double  end_pos;

    i = 0;
    if (env->options.wall_lover == 1)
        return (1);
    future_x = env->player.pos.x + x_move;
    future_y = env->player.pos.y + y_move;
    /*
    **On parcourt tout les murs et portails du secteur actuel afin de verifier si le joueur rentre dedans
    */
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
        end_pos = (future_x - X1) * (Y2 - Y1) - (future_y - Y1) * (X2 - X1);
        if (end_pos == 0)
        {
                env->player.speed = env->player.speed * 0.7;
                return (check_collision(env, x_move * 0.7, y_move * 0.7));
        }
        if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, future_x, future_y) && env->sectors[env->player.sector].neighbors[i] < 0)
            return (0);
        else if (diff_sign(start_pos, end_pos, env) && check_wall(env, i, future_x, future_y) && env->sectors[env->player.sector].neighbors[i] >= 0)
        {
            env->player.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            env->player.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            env->player.old_sector = env->player.sector;
            env->player.sector = env->sectors[env->player.sector].neighbors[i];
            if (!check_inside_sector(env, future_x, future_y))
            {
                env->player.sector = env->player.old_sector;
                return (0);
            }
            return (1);
        }
        i++;
        /*
        ** Pour proteger les angles entre un mur et un portail il faudrait vérifier que le point d'arrivée du joueur
        ** est bien a l'interieur du secteur relié a ce portail
        */
    }
    return (1);
}