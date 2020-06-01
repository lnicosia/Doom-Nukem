/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:09:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/20 12:35:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "env.h"

int						draw_hud(t_env *env);
void					draw_axes(t_env *env);
void					draw_crosshair(t_env *env);
int						draw_button_text(t_button b, char *str, t_env *env);
void					draw_hgrid(t_env *env);
void					draw_vgrid(t_env *env);
void					draw_grid(t_env *env);
int						draw_inventory(t_env *env);
int						draw_editor_tabs(t_env *env);
void					draw_grid_player(t_env *env);
void					draw_grid_start_player(t_env *env);
void					draw_grid_objects(t_env *env);
void					draw_circle(t_circle circle, t_env *env);
void					draw_circle_free(t_circle circle, t_env *env);
void					draw_grid_vertices(t_env *env);
void					draw_grid_current_sector(t_env *env);
int						draw_grid_sectors(t_env *env);
int						draw_input_box(t_input_box *box, t_env *env);
int						draw_cursor(t_input_box *box, t_point pos, char *sub,
t_env *env);
int						draw_box_selection(t_input_box *box, t_point pos,
char *str, t_env *env);
int						draw_event_panel(t_env *env);
int						draw_target_tab(t_env *env);
int						draw_action_tab(t_env *env);
int						draw_condition_panel(t_env *env);
int						draw_condition_condition_panel(t_env *env);
int						draw_condition_type_tab(t_env *env);
int						draw_condition_target_tab(t_env *env);
int						draw_condition_targets_panel(t_env *env);
int						draw_condition_event_panel(t_env *env);
int						draw_target_panel(t_env *env);
int						draw_action_panel(t_env *env);
int						draw_conditions_panel(t_env *env);
int						draw_floor_panel(t_env *env, t_target_panel *panel);
int						draw_ceiling_panel(t_env *env, t_target_panel *panel);
int						draw_wall_panel(t_env *env, t_target_panel *panel);
int						draw_sector_other_panel(t_env *env,
t_target_panel *panel);
int						draw_other_panel(t_env *env, t_target_panel *panel);
int						draw_vertex_panel(t_env *env, t_target_panel *panel);
int						draw_player_panel(t_env *env, t_target_panel *panel);
int						draw_enemy_panel(t_env *env, t_target_panel *panel);
int						draw_object_panel(t_env *env, t_target_panel *panel);
int						draw_weapon_panel(t_env *env, t_target_panel *panel);
int						draw_wall_sprite_panel(t_env *env,
t_target_panel *panel);
int						draw_action_panel(t_env *env);
int						draw_action_panel_bottom(t_env *env);
int						draw_launch_conditions_panel(t_env *env);
int						draw_exec_conditions_panel(t_env *env);
int						draw_first_phase_selection(t_env *env,
t_target_panel *panel);
int						draw_second_phase_selection(t_env *env,
t_target_panel *panel);
int						draw_third_phase_selection(t_env *env,
t_target_panel *panel);
int						draw_weapon_picker(t_env *env);
void					draw_line_3(t_env *env, t_line line);
void					draw_line(t_point c1, t_point c2, t_env *env,
Uint32 color);
void					draw_line_free(t_point c1, t_point c2, t_env *env,
Uint32 color);
void					draw_line_minimap(t_point c1, t_point c2, t_env *env,
Uint32 color);
int						draw_confirmation_box(t_confirmation_box *box,
t_env *env);
void					draw_rectangle(t_env *env, t_rectangle r, t_point pos,
		t_point size);
void					draw_rectangle_alpha(t_env *env, t_rectangle r,
t_point pos, t_point size);
int						draw_button(t_env *env, t_button b, char *str);
int						draw_dialog_box(char **str, t_env *env);
int						draw_walls(t_camera *camera, t_env *env);
int						draw_explosions(t_camera *camera, t_env *env);
int						draw_projectiles(t_camera *camera, t_env *env);
int						draw_projectile_both(t_camera *camera, t_projectile *p,
t_env *env);
int						draw_projectile_no_light(t_camera *camera,
t_projectile *p, t_env *env);
int						draw_projectile_brightness(t_camera *camera,
t_projectile *p, t_env *env);
int						draw_projectile_color(t_camera *camera,
t_projectile *p, t_env *env);
int						draw_objects(t_camera *camera, t_env *env);
int						draw_enemies(t_camera *camera, t_env *env);
int						draw_player(t_camera *camera, t_v3 pos, t_env *env);
int						draw_game(t_env *env);
void					draw_minimap_player(t_env *env);
int						draw_minimap_sector_num(t_env *env, t_sector *sector);
void					draw_objects_minimap(t_env *env);
void					draw_minimap_hud(t_env *env);
void					draw_weapon(t_env *env, int sprite);
int						print_general_tab(t_env *env);
int						print_sector_tab(t_env *env);
void					draw_selection(t_point pos, t_point size1,
t_point size2, t_env *env);
int						draw_current_line(t_input_box *box, char **str,
t_env *env);
int						draw_third_phase_selection(t_env *env,
t_target_panel *panel);

#endif
