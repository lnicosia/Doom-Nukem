/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/04/23 14:31:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}    

int     check_wall(t_env *env, int i)
{
    if ((PLAYER_XPOS >= X1 && PLAYER_XPOS <= X2) || (PLAYER_XPOS >= X2 && PLAYER_XPOS <= X1))
        return (1);
    if ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1))
        return (1);
    return (0);
}

int     check_collision(t_env *env, double x_move, double y_move)
{
    short   i;
    short   tmp;
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
        if (diff_sign(start_pos, end_pos) && check_wall(env, i) && env->sectors[env->player.sector].neighbors[i] < 0)
            return (0);
        else if (diff_sign(start_pos, end_pos) && check_wall(env, i) && env->sectors[env->player.sector].neighbors[i] >= 0)
        {
            tmp = env->player.sector;
			env->player.old_sector = tmp;
            env->player.sector = env->sectors[env->player.sector].neighbors[i];
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
