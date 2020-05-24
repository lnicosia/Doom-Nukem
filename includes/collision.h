/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:30:04 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/21 19:44:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H
# include "env.h"

typedef struct		s_wall
{
	double			x;
	double			y;
	double			norme;
	int				sector_or;
	int				sector_dest;
}					t_wall;

typedef struct		s_motion
{
	double			future_x;
	double			future_y;
	double			future_z;
	t_wall			wall;
	int				sector;
	int				lowest_ceiling;
	int				flight;
	double			size_2d;
	double			eyesight;
	t_v3			pos;
	t_v3			future;
}					t_motion;

typedef struct		s_data
{
	t_vertex		v0;
	t_sector		sector;
}					t_data;

typedef struct		s_coll
{
	t_motion		motion;
	int				vertex;
	int				sector;
}					t_coll;

typedef struct		s_ecoll
{
	t_v3			pos;
	double			radius;
	int				*enemy;
	double			*nearest_dist;
}					t_ecoll;

typedef	struct		s_coll_addr
{
	t_motion		*motion;
	int				*v;
	int				*s;
}					t_coll_addr;

typedef struct		s_projectile_collision
{
	t_v3			pos;
	t_v3			dest;
	double			nearest_dist;
	double			distance;
	double			radius;
	int				object;
}					t_projectile_collision;

t_coll				new_coll(int use, t_v3 bouelp);
t_coll_addr			new_coll_addr(t_motion *motion, int *sector, int *vertex);
t_ecoll				new_e_coll(double radius, t_v3 pos, double *near_dist,
	int *enemy);
t_coll				new_c(int sect, int vertex, t_motion motion);
int					cross_portal(t_env *env, t_motion motion, int s, int v);
t_v3				check_collision(t_env *env, t_v3 move, t_motion motion);
t_v3				check_collision_slide(t_env *env, t_v3 move,
						t_motion motion, int sect);
t_v3				collision_rec(t_env *env, t_v3 move, t_motion motion,
						int recu);
t_v3				calculate_motion_future(t_motion motion, t_v3 move);
int					check_inside_sector(t_env *env, t_motion motion);
void				objects_collision(t_env *env, t_v3 pos);
int					enemy_collision(t_env *env, t_v3 pos, t_v3 dest,
						double radius);
int					enemy_melee_hit(t_env *env, int i);
int					hitbox_collision(t_v2 v1, t_v2 v2, t_v2 p, double size);
int					find_highest_sector(t_env *env, t_motion motion);
int					diff_sign(double nb1, double nb2);
int					diff_value(int nb1, int nb2, int a, int b);
int					in_range(double nb, double val1, double val2);
t_motion			new_motion(int sector, double size_2d, double eyesight,
						t_v3 pos);
int					find_lowest_ceiling(t_env *env, t_motion motion);
int					check_ceiling(t_env *env, t_motion motion, int sector_dest);
int					check_floor(t_env *env, t_motion motion, int sector_dest);
int					check_floor_ceil(t_env *env, t_motion motion,
						int sector_dest);
int					collision_projectiles(t_env *env, t_v3 move,
						t_motion motion);
int					collision_projectiles_rec2(t_env *env, t_v3 move,
						t_motion motion, t_wall wall);
int					collision_projectiles_rec(t_env *env, t_v3 move,
						t_motion motion);
int					projectiles_ceil(t_env *env, t_motion motion,
int sector_dest);
int					projectiles_floor(t_env *env, t_motion motion,
int sector_dest);
int					projectile_player_collision(t_env *env, t_v3 pos, t_v3 dest,
						double radius);
int					projectile_object_collision(t_env *env, t_v3 pos, t_v3 dest,
						double radius);
t_v3				parallel_movement(t_env *env, t_v3 move, int sect, int i);
double				norm_vector(double x, double y);
t_v3				collisions_z_axis(t_env *env, t_motion motion, t_v3 move);
int					check_objects(t_env *env, t_v3 move, t_motion motion);
void				reset_loop(int *i, int *sector, t_motion motion);
t_v3				update_move(t_env *env, t_coll coll, t_v3 *move);
int					cross_portal(t_env *env, t_motion motion, int s, int v);
int					cross_wall(t_env *env, t_motion motion, int s, int v);
void				check_blocage(t_env *env, t_motion motion, double speed,
int index);

#endif
