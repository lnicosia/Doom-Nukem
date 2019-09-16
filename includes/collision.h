/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:30:04 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/13 19:28:51 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# define SECTOR_X1 env->vertices[env->sectors[sector].vertices[i]].x
# define SECTOR_X2 env->vertices[env->sectors[sector].vertices[i + 1]].x
# define SECTOR_Y1 env->vertices[env->sectors[sector].vertices[i]].y
# define SECTOR_Y2 env->vertices[env->sectors[sector].vertices[i + 1]].y
# define FUTURE_V0X env->vertices[env->sectors[sector_dest].vertices[0]].x
# define FUTURE_V0Y env->vertices[env->sectors[sector_dest].vertices[0]].y
# define FUTURE_X motion.future_x
# define FUTURE_Y motion.future_y
# define FUTURE_Z motion.future_z
# define VERTICES_AMOUNT env->sectors[env->player.sector].nb_vertices
# define NEIGHBOR env->sectors[sector].neighbors[i]
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y
# define PLAYER_ZPOS env->player.pos.z
# define X1R env->vertices[env->sectors[wall.sector_dest].vertices[i]].x
# define X2R env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].x
# define Y1R env->vertices[env->sectors[wall.sector_dest].vertices[i]].y
# define Y2R env->vertices[env->sectors[wall.sector_dest].vertices[i + 1]].y
# define RNEIGHBOR env->sectors[wall.sector_dest].neighbors[i]
# include "env.h"

typedef struct  s_movement
{
    double      old_z;
    double      future_x;
    double      future_y;
    double      future_z;
    int         wall_v1;
    int         wall_v2;
    int         old_sector;
}               t_movement;

typedef struct  s_wall
{
    double      x;
    double      y;
    double      norme;
    short       sector_or;
    short       sector_dest;  
}               t_wall;

typedef struct  s_data
{
    t_vertex    v0;
    t_sector    sector;
}               t_data;


t_v2				check_collision(t_env *env, t_v2 move, t_v3 pos, int sector, int recu);
int     			check_inside_sector(t_env *env, t_movement motion);
void                objects_collision(t_env *env);
void                enemy_collision(t_env *env);
int                 hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p);
int                 find_highest_sector(t_env *env, t_v3 pos, int sector, double eyesight);
int					diff_sign(double nb1, double nb2);
int					diff_value(int nb1, int nb2, int a, int b);
int					in_range(double nb, double val1, double val2);

#endif
