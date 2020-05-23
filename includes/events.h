/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:39:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 15:39:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "env.h"

/*
**	Event functions
*/

int						update_event(t_event *event);
int						pop_events(t_env *env);
int						double_event(t_event *curr);
int						int_event(t_event *curr);
int						uint32_event(t_event *curr);
t_event					new_fixed_event(int type, void *target, double goal,
double speed);
t_event					new_func_event(int (*func)(void *, void *),
void *param);
t_event					new_incr_event(int type, void *target, double incr,
double speed);
int						start_event(t_event **events, size_t *size,
t_env *env);
int						start_event_free(t_event **events, size_t *size,
t_env *env);
int						check_launch_conditions(t_event *event,
t_condition *tab, size_t nb, t_env *env);
int						check_exec_conditions(t_event *event, t_condition *tab,
size_t nb, t_env *env);
t_event_param			new_event_param(int num, double equ_value,
double diff_value);
t_event_param			empty_event_param(void);

int						update_sector_event(t_event *event, void *penv);
int						update_player_pos_event(t_event *event, void *penv);
int						update_player_z_event(t_event *event, void *penv);
int						update_wall_texture_event(t_event *event, void *penv);
int						update_floor_texture_event(t_event *event, void *penv);
int						update_ceiling_texture_event(t_event *event,
void *penv);
int						update_sector_entities_light_event(t_event *event,
void *penv);
int						update_object_sector_event(t_event *event, void *penv);
int						update_enemy_sector_event(t_event *event, void *penv);
int						update_object_sprite_event(t_event *event, void *penv);
int						update_enemy_sprite_event(t_event *event, void *penv);
int						update_wall_sprite_event(t_event *event, void *penv);
int						update_floor_sprite_event(t_event *event, void *penv);
int						update_ceiling_sprite_event(t_event *event,
void *penv);
int						update_vertex_event(t_event *event, void *penv);
int						update_floor_sprite_event(t_event *event, void *penv);
int						update_ceiling_sprite_event(t_event *event, void *penv);
int						delete_itself_event(t_event *event, void *penv);
int						update_gravity_event(t_event *event, void *penv);

/*
**	Event panel
*/

int						event_panel_keys(t_env *env);
int						event_panel_keyup(t_env *env);
int						condition_panel_keys(t_env *env);
int						condition_panel_keyup(t_env *env);
int						condition_target_keys(t_env *env);
int						condition_target_keyup(t_env *env);
int						target_panel_keys(t_env *env, t_target_panel *panel);
int						first_phase_keys(t_env *env, t_target_panel *panel);
int						first_phase_keyup(t_env *env, t_target_panel *panel);
int						second_phase_keys(t_env *env, t_target_panel *panel);
int						second_phase_keyup(t_env *env, t_target_panel *panel);
int						third_phase_keys(t_env *env, t_target_panel *panel);
int						third_phase_keyup(t_env *env, t_target_panel *panel);
int						action_panel_keys(t_env *env);
int						conditions_panel_keys(t_env *env);
int						conditions_panel_keyup(t_env *env);
int						target_tab_func(void *param);
int						action_tab_func(void *param);
int						launch_conditions_tab_func(void *param);
int						exec_conditions_tab_func(void *param);
int						select_sector_other(void *param);
int						select_other(void *param);
int						select_wall(void *param);
int						select_floor(void *param);
int						select_vertex(void *param);
int						select_player(void *param);
int						select_ceiling(void *param);
int						select_object(void *param);
int						select_enemy(void *param);
int						select_weapon(void *param);
int						select_wall_sprite(void *param);
int						set_int_button(void *param);
int						choose_target(void *param);
int						action_pane_keys(t_env *env);
int						launch_conditions_panel_keys(t_env *env);
int						exec_conditions_panel_keys(t_env *env);
int						target_panel_keyup(t_env *env, t_target_panel *panel);
int						action_panel_keyup(t_env *env);
int						launch_conditions_panel_keyup(t_env *env);
int						exec_conditions_panel_keyup(t_env *env);
t_button				new_red_panel_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_blue_panel_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_yellow_panel_button(int type,
int (*action)(void *), void *param, t_env *env);
t_button				new_green_panel_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_orange_panel_button(int type,
int (*action)(void *), void *param, t_env *env);
t_button				new_dark_panel_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_purple_panel_button(int type,
int (*action)(void *), void *param, t_env *env);
t_button				new_turquoise_panel_button(int type,
int (*action)(void *), void *param, t_env *env);
t_button				new_small_panel_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_condition_panel_button(int type,
int (*action)(void *), void *param, t_env *env);
void					update_event_panel_buttons_pos(t_env *env);
void					update_target_panel_buttons_pos(t_env *env);
void					update_action_panel_buttons_pos(t_env *env);
void					update_conditions_panel_buttons_pos(t_env *env);
void					update_exec_conditions_panel_buttons_pos(t_env *env);
void					update_condition_panel_buttons_pos(t_env *env);
void					update_condition_target_buttons_pos(t_env *env);
int						get_target_selection_phase(t_target_panel *panel);
int						previous_target_selection_phase(void *param);
int						set_new_event_target(t_env *env);
int						select_floor_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_floor_target2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector);
int						select_ceiling_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_ceiling_target2(t_env *env,
t_event_panel *panel, t_target_panel *target_panel, int sector);
int						select_wall_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_enemy_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_object_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_wall_sprite_target(t_env *env,
t_event_panel *panel, t_target_panel *target_panel);
int						select_weapon_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_vertex_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_sector_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_player_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_other_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel);
int						select_sector_other_target(t_env *env,
t_event_panel *panel, t_target_panel *target_panel);
int						set_floor_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector);
int						set_ceiling_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector);
int						set_floor_panel_buttons_state(t_target_panel *panel,
int index);
int						set_ceiling_panel_buttons_state(t_target_panel *panel,
int index);
int						set_sector_other_panel_buttons_state(
	t_target_panel *panel, int index);
int						set_player_panel_buttons_state(t_target_panel *panel,
int index);
int						set_vertex_panel_buttons_state(t_target_panel *panel,
int index);
int						set_wall_panel_buttons_state(t_target_panel *panel,
int index);
int						set_wall_sprite_panel_buttons_state(
	t_target_panel *panel, int index);
int						set_object_panel_buttons_state(t_target_panel *panel,
int index);
int						set_enemy_panel_buttons_state(t_target_panel *panel,
int index);
int						set_weapon_panel_buttons_state(t_target_panel *panel,
int index);
int						set_other_panel_buttons_state(t_target_panel *panel,
int index);
void					set_buttons_state(t_env *env);
int						set_event_value(void *param);
int						set_event_speed(void *param);
int						set_event_delay(void *param);
int						set_event_max_uses(void *param);
int						create_event(void *param);
int						check_event_validity(t_env *env, t_event event);
int						save_event(void *param);
int						modify_event(void *param);
void					set_action_type_buttons_state(t_env *env);
void					set_modified_event(t_env *env, t_event *event);
int						delete_event(void *param);
int						delete_selected_event(void *param);
int						delete_selected_event1(t_env *env,
t_event_trigger trigger);
int						save_condition(void *param);
void					save_condition_value(t_condition *condition,
t_condition_panel *panel);
int						check_condition_validity(t_env *env,
t_condition condition);
int						create_condition(void *param);
int						modify_condition(void *param);
int						new_global_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_press_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_shoot_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_stand_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_walk_in_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_walk_out_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_death_event(t_env *env, t_event_trigger trigger,
t_event event);
int						new_enemy_collision_event(t_env *env,
t_event_trigger trigger, t_event event);
int						new_object_collision_event(t_env *env,
t_event_trigger trigger, t_event event);
int						delete_condition(void *param);
int						set_equals(void *param);
int						set_less(void *param);
int						set_different(void *param);
int						set_greater(void *param);
int						set_greater_or_equals(void *param);
int						set_less_or_equals(void *param);
int						set_event_ended(void *param);
int						set_event_ended_start(void *param);
int						set_function(void *param);
void					set_condition_panel_buttons_state(t_env *env,
int type);
void					set_condition_panel_buttons_pos(t_button *button,
double side, double tier, t_env *env);
int						set_new_condition_target(t_env *env);
int						select_floor_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_floor_condition_target2(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel, int sector);
int						select_ceiling_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_ceiling_condition_target2(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel, int sector);
int						select_wall_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_enemy_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_object_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_wall_sprite_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_weapon_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_vertex_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_sector_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_player_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_sector_other_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						select_other_condition_target(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel);
int						set_condition_floor_sprite(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel, int sector);
int						set_condition_ceiling_sprite(t_env *env,
t_condition_panel *panel, t_target_panel *target_panel, int sector);
void					set_condition_buttons_state(t_env *env);
t_event					*get_event_array(t_env *env, t_event_trigger trigger);
int						close_event_panel(void *param);
void					reset_target_selection(t_target_panel *panel);
int						new_event_panel_value_box(t_input_box *box,
int type, void *target, t_env *env);
int						new_event_panel_box(t_input_box *box,
int type, void *target, t_env *env);
int						new_event_panel_dialog_box(t_input_box *box,
int type, void *target, t_env *env);
int						close_event_panel(void *param);
int						weapon_picker_keys(t_env *env);
int						weapon_picker_keyup(t_env *env);
int						is_mouse_on_weapon_picker(t_env *env);

#endif
