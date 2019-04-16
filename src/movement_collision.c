/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/04/15 19:42:48 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
**  equation de la premiere droite: a1 * x1 + b1
**  equation de la deuxieme droite: a2 * x2 + b2
*/

int             check_collision(t_env *env, double x_move, double y_move)
{
    short i;
    double a1;
    double a2;
    double b1;
    double b2;
    double common_x;

    a1 = y_move / x_move;
    b1 = env->player.pos.y - (a1 * env->player.pos.x);
    i = 0;
    ft_printf("<------------------>\n");
    //ft_printf("current sector = %d\n", env->player.sector);
    //ft_printf("amount of vertices in current sector = %d\n", env->sector[env->player.sector].nb_vertices);
    while (i < env->sector[env->player.sector].nb_vertices)
    {
        a2 = (env->vertices[env->sector[env->player.sector].vertices[i + 1]].y
            - env->vertices[env->sector[env->player.sector].vertices[i]].y)
            / (env->vertices[env->sector[env->player.sector].vertices[i + 1]].x
            - env->vertices[env->sector[env->player.sector].vertices[i]].x); 
        b2 = (env->vertices[env->sector[env->player.sector].vertices[i]].y
        - (a2 * env->vertices[env->sector[env->player.sector].vertices[i]].x));
       /*  ft_printf("wall: x1 =  %f    y1= %f\n", env->vertices[env->sector[env->player.sector].vertices[i]].x,
            env->vertices[env->sector[env->player.sector].vertices[i]].y);
        ft_printf("wall: x2 =  %f    y2= %f\n\n", env->vertices[env->sector[env->player.sector].vertices[i + 1]].x,
            env->vertices[env->sector[env->player.sector].vertices[i + 1]].y); */
        ft_printf("%f\n", a2);
        if (a1 == a2)
            return (0);
        common_x = (b2 - b1) / (a1 - a2);
        if (common_x >= env->player.pos.x && common_x <= x_move &&
            common_x >= env->vertices[env->sector[env->player.sector].vertices[i]].x &&
            common_x <= env->vertices[env->sector[env->player.sector].vertices[i + 1]].x)
            return (0);
        //ft_printf("vertice nb %d\n", env->vertices[env->sector[env->player.sector].vertices[i]].num);

        i++;
    }
    return (1);
    //a2 =  / 
}