/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/04/29 17:02:12 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}

t_line_eq  line_equation(double x1, double y1, double x2, double y2)
{
    t_line_eq  line_eq;

    line_eq.a = (y2 - y1) / (x2 - x1);
    line_eq.b = y1 - line_eq.a * x1;
    return (line_eq);
}

int     check_collision(t_env *env, double x_move, double y_move)
{
    t_line_eq  player_line;
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        start_pos = (PLAYER_XPOS + x_move - X1) * (Y2 - Y1) - (PLAYER_YPOS + y_move - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (PLAYER_YPOS + y_move - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos) && ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1)))
        {
            ft_printf("vertice %i-%i\n", env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i+1]].num);
            ft_printf("start_pos = %f\n", start_pos);
            ft_printf("end_pos = %f\n", end_pos);
            count++;
        }
        i++;
    }
    ft_printf("count = %d\n", count);
    if (count % 2 == 0)
        ft_printf("I'm out of the sector %d\n", env->player.sector);
    player_line = line_equation(env->player.pos.x, env->player.pos.y, env->player.pos.x + x_move, env->player.pos.y + y_move);
   // ft_printf("player movement line:  y = %.19fx + %.19f\n", player_line.a, player_line.b);
    return (1);
}
