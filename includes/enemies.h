/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:09:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 11:57:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMIES_H
# define ENEMIES_H
# include "collision.h"

/*
** enemies functions
*/

void					draw_grid_enemies(t_env *env);
void					enemy_drag(t_env *env);
int						enemy_ai(t_env *env);
t_v3					random_move(t_env *env, int nb, t_motion motion,
t_v3 move);
void					update_enemy_angle(t_env *env, int nb);
void					damage_anim(t_env *env);
int						enemy_hurt(t_env *env, int i);
void					resting_enemy(t_env *env, int i);
void					pursuing_enemy(t_env *env, int i);
int						dying_enemy(t_env *env, int i, int nb_sprites);
int						rand_dir(t_env *env, int index);
void					enemy_firing_anim(t_env *env, int i);
int						draw_enemy(t_camera *camera, t_enemy *enemy,
t_env *env, int death_sprite);
double					enemy_sight(t_env *env, int i, int shot_flag);
int						check_segment_in_sector(t_env *env, t_v2 enemy,
	t_v2 player, int sector);
void					enemy_far_left_right(t_env *env, int nb);
void					update_enemy_pos(t_env *env, int nb, t_v3 move);
int						damage_player(t_env *env, int damage);
double					enemy_angle_z(t_env *env, int i);
int						direction_of_point(t_v2 a, t_v2 b, t_v2 p);
void					relative_pos(int direction, int *left, int *right);
int						check_sect(t_env *env, int *sect, int *vertex,
	t_segment enemy_player);
t_segment				new_segment(t_v2 p1, t_v2 p2);
t_segment				new_wall_segment(t_env *env, int sector, int vertex);
int						enemy_collision_event(t_env *env, int i);
int						enemy_collision_player(t_env *env, int i);
int						enemy_is_seeing_player(t_env *env, int i);

#endif
