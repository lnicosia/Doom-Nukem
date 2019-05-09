/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:30:04 by gaerhard          #+#    #+#             */
/*   Updated: 2019/05/07 16:25:03 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# define X1 env->vertices[env->sectors[env->player.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[env->player.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].y
# define FUTURE_V0X env->vertices[env->sectors[env->player.sector].vertices[0]].x
# define FUTURE_V0Y env->vertices[env->sectors[env->player.sector].vertices[0]].y
# define FUTURE_X motion.future_x
# define FUTURE_Y motion.future_y
# define FUTURE_Z motion.future_z
# define VERTICES_AMOUNT env->sectors[env->player.sector].nb_vertices
# define NEIGHBOR env->sectors[env->player.sector].neighbors[i]
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y
# define PLAYER_ZPOS env->player.pos.z

typedef struct  s_movement
{
    int         wall_v1;
    int         wall_v2;
    int         old_sector;
    double      old_z;
    double      future_x;
    double      future_y;
    double      future_z;
}               t_movement;

typedef struct  s_data
{
    t_vertex    v0;
    t_sector    sector;
}               t_data;


int					check_collision(t_env *env, double x_move, double y_move);
int     			check_inside_sector(t_env *env, t_movement motion);

#endif