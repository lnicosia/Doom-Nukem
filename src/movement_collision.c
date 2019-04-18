/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/04/17 16:30:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
**  equation de la premiere droite: a1 * x1 + b1
**  equation de la deuxieme droite: a2 * x2 + b2
*/

#ifndef ABS
#define ABS(x) (x > 0) ? x : -x
#endif // !ABS

int             check_collision(t_env *env, double x_move, double y_move)
{
    short i;
    double a1;
    double a2;
    double b1;
    double b2;
    double common_x;

    //x_move = ABS(x_move);
    a1 = y_move / x_move;
    ft_printf("x_move = %f\n", x_move);
    ft_printf("y_move = %f\n", y_move);
    b1 = env->player.pos.y - (a1 * env->player.pos.x);
    i = 0;
    ft_printf("<------------------>\n");
/*     ft_printf("coeff directeur = %f\n", y_move / x_move);
    ft_printf("y axis movement = %f\n", y_move);
    ft_printf("x axis movement = %f\n", x_move);
    ft_printf("player X = %f, player Y = %f\n", env->player.pos.x, env->player.pos.y);*/
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        a2 = (Y2 - Y1) / (X2 - X1);
        b2 = Y1 - a2 * X1;

        /* ft_printf("wall: x1 =  %f    y1= %f\n", env->vertices[env->sectors[env->player.sector].vertices[i]].x,
            env->vertices[env->sectors[env->player.sector].vertices[i]].y);
        ft_printf("wall: x2 =  %f    y2= %f\n\n", env->vertices[env->sectors[env->player.sector].vertices[i + 1]].x,
            env->vertices[env->sectors[env->player.sector].vertices[i + 1]].y);
        ft_printf("coeff directeur droite deplacement = %f\n", a1); */
        ft_printf("equation droite joueur = %f x + %f\n", a1, b1);
        ft_printf("equation droite mur%d = %f x + %f\n", env->vertices[env->sectors[env->player.sector].vertices[i]].num, a2, b2);
        if (a1 == a2 && (env->player.pos.x >= X1 
            && env->player.pos.x <= X2)
            && (env->player.pos.y >= Y1
            && env->player.pos.y <= Y2))
            return (0);
        
        common_x = (b2 - b1) / (a1 - a2);
        
        if (common_x >= env->player.pos.x && common_x <= env->player.pos.x + x_move &&
            common_x >= X1 &&
            common_x <= X2)
            return (0);
        /* ft_printf("vertice nb %d\n", env->vertices[env->sectors[env->player.sector].vertices[i]].num); */
        i++;
    }
    return (1);
    //a2 =  / 
}