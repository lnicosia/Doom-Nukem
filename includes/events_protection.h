/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_protection.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:46:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 15:46:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_PROTECTION_H
# define EVENTS_PROTECTION_H
# include "events.h"

/*
**	Event protection functions
*/

int						check_x_collision_event(t_event *event, void *penv);
int						check_y_collision_event(t_event *event, void *penv);
int						check_z_collision_event(t_event *event, void *penv);
int						check_sector_event(t_event *event, void *penv);
int						check_floor_slope_event(t_event *event, void *penv);
int						check_ceiling_slope_event(t_event *event, void *penv);
int						check_floor_event(t_event *event, void *penv);
int						check_ceiling_event(t_event *event, void *penv);
int						check_texture_event(t_event *event, void *penv);
int						check_sprite_event(t_event *event, void *penv);
int						check_scale_event(t_event *event, void *penv);
int						check_speed_event(t_event *event, void *penv);
int						check_align_event(t_event *event, void *penv);
int						check_color_event(t_event *event, void *penv);
int						check_brightness_event(t_event *event, void *penv);
int						check_int_overflow_event(t_event *event, void *penv);
int						check_double_overflow_event(t_event *event,
void *penv);
int						check_gravity_event(t_event *event, void *penv);
int						check_portal_event(t_event *event, void *penv);
int						check_true_false_event(t_event *event, void *penv);
int						check_vertex_x_event(t_event *event, void *penv);
int						check_vertex_y_event(t_event *event, void *penv);
int						is_sector_convex(t_env *env, t_sector *sector);
int						update_sectors_slope(int vertex, t_env *env);

#endif
