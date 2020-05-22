/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:39:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 21:09:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "env.h"

/*
** Init functions
*/

int						init_game(int ac, char **av);
int						init_game6(t_env *env);
void					init_weapon_picker(t_env *env);
int						init_screen_size(t_env *env);
void					set_screen_size(t_env *env);
void					init_weapons(t_env *env);
void					init_gatling_weapon(t_env *env);
int						init_audio(t_env *env);
void					init_animations(t_env *env);
void					init_pointers(t_env *env);
int						init_sdl(t_env *env);
int						set_sdl(t_env *env);
int						init_ttf(t_env *env);
int						init_ttf6(t_env *env);
int						init_textures(t_env *env);
int						init_mini_skyboxes_selection(t_env *env);
int						init_mini_skyboxes_selection2(t_env *env);
int						init_ui_textures(t_env *env);
int						init_skyboxes_textures(t_env *env);
int						init_skybox(t_env *env);
int						init_wallpapers_and_buttons(t_env *env);
int						init_sector_data(t_env *env, char *line,
t_map_parser *parser);
int						init_enemy_sprites(t_env *env);
void					init_lost_soul_sprite(t_env *env);
void					init_lost_soul_rest(t_env *env);
void					init_lost_soul_pursuit(t_env *env);
void					init_lost_soul_pursuit_two(t_env *env);
void					init_lost_soul_death(t_env *env);
void					init_cyber_demon_pursuit(t_env *env);
t_button				init_button(int type, int (*action)(void *),
void *param, t_env *env);
void					init_cyber_demon_pursuit_two(t_env *env);
void					init_cyber_demon_pursuit_three(t_env *env);
void					init_cyber_demon_pursuit_four(t_env *env);
void					init_cyber_demon_firing_anim(t_env *env);
int						init_raygun(t_env *env);
int						init_shotgun(t_env *env);
int						init_gun(t_env *env);
int						init_gatling(t_env *env);
void					init_events_selection_buttons(t_env *env);
void					init_events_creation_buttons(t_env *env);
void					init_cyber_demon_firing_anim_two(t_env *env);
void					init_cyber_demon_firing_anim_three(t_env *env);
void					init_cyber_demon_death(t_env *env);
int						init_vertices(t_env *env, t_map_parser *parser);
int						init_sectors(t_env *env, t_map_parser *parser);
void					init_events_map(t_env *env);
void					init_condition(t_condition *condition);
void					init_trigger(t_event_trigger *trigger);
void					init_target(t_event_target *target);
void					save_init_data(t_env *env);
int						init_object_sprites(t_env *env);
void					init_minigun(t_env *env);
void					init_rocket(t_env *env);
void					init_health_pack(t_env *env);
void					init_ammo(t_env *env);
void					init_lamp(t_env *env);
void					init_barrel(t_env *env);
void					init_monitor(t_env *env);
int						init_input_box(t_input_box *box, t_env *env);
void					init_candle(t_env *env);
void					init_camera_sprite(t_env *env);
void					init_armor_green(t_env *env);
void					init_explosion(t_env *env);
void					init_grid_sprite(t_env *env);
void					init_button_sprite(t_env *env);
void					init_bullet_hole(t_env *env);
void					init_object_lost_soul(t_env *env);
void					init_object_cyber_demon(t_env *env);
void					init_shotgun_sprite(t_env *env);
void					init_raygun_sprite(t_env *env);
void					init_doom_guy(t_env *env);
void					init_doom_guy_face(t_env *env);
int						init_new_sector_arrays(t_sector *sector);
void					init_hd_sprite(t_env *env);
int						init_wall_sprites(t_env *env);
int						init_screen_pos(t_env *env);
void					init_options(t_env *env);
void					init_keys(t_env *env);
void					init_inputs(t_env *env);
void					set_enemies_hp(t_env *env);
void					init_editor_data(t_env *env);
int						init_camera(t_camera *camera, t_env *env);
int						init_camera_arrays(t_camera *camera, t_env *env);
void					init_player(t_env *env);
void					init_enemies_data(t_env *env);
void					init_objects_data(t_env *env);
void					init_object_data5(int i, t_env *env);
void					init_object_data10(int i, t_env *env);
void					init_objects_main_sprites(t_env *env);
void					init_sector_list(t_env *env, int curr);
void					init_event_types(t_env *env);
void					init_event_links_types(t_env *env);
void					init_print_target_data(t_env *env);
void					init_print_target_data6(t_env *env);
void					init_print_condition_target_data(t_env *env);
void					init_print_condition_target_data6(t_env *env);
void					init_print_link_target_data(t_env *env);
int						init_editor(int ac, char **av);
int						init_editor_hud(t_env *env);
int						init_enemy_selection_button(t_env *env);
int						init_object_selection_button(t_env *env);
int						init_array_texture_buttons(t_env *env);
void					init_editor_options_buttons(t_env *env);
void					init_quit_options_button(t_env *env);
void					init_editor_data(t_env *env);
void					init_selection_data(t_env *env);
void					init_editor_tab_buttons(t_env *env);
void					init_player_buttons(t_env *env);
void					init_floor_buttons(t_env *env);
void					init_ceiling_buttons(t_env *env);
void					init_wall_buttons(t_env *env);
void					init_wall_sprite_buttons(t_env *env);
void					init_floor_general_env(t_env *env);
void					init_floor_sector_env(t_env *env);
void					init_floor_sprite_env(t_env *env);
void					init_floor_general_buttons(t_env *env);
void					init_floor_sector_buttons(t_env *env);
void					init_floor_sprite_buttons(t_env *env);
void					init_wall_general_env(t_env *env);
void					init_vertices_general_env(t_env *env);
void					init_wall_sector_env(t_env *env);
void					init_wall_sprite_sector_env(t_env *env);
void					init_wall_sprite_env(t_env *env);
void					init_wall_general_buttons(t_env *env);
void					init_vertices_general_buttons(t_env *env);
void					init_wall_sector_buttons(t_env *env);
void					init_wall_sprite_sector_buttons(t_env *env);
void					init_wall_sprite_buttons(t_env *env);
void					init_ceiling_general_env(t_env *env);
void					init_ceiling_sector_env(t_env *env);
void					init_ceiling_sprite_env(t_env *env);
void					init_ceiling_general_buttons(t_env *env);
void					init_ceiling_sector_buttons(t_env *env);
void					init_ceiling_sprite_buttons(t_env *env);
void					init_add_buttons(t_env *env);
void					init_change_slope_direction_buttons(t_env *env);
void					init_add_enemy_buttons(t_env *env);
void					init_add_object_buttons(t_env *env);
void					init_sector_general_env(t_env *env);
void					init_sector_sector_env(t_env *env);
void					init_sector_general_buttons(t_env *env);
void					init_sector_sector_buttons(t_env *env);
void					init_player_general_env(t_env *env);
void					init_player_sector_env(t_env *env);
void					init_player_sprite_env(t_env *env);
void					init_player_general_buttons(t_env *env);
void					init_player_sector_buttons(t_env *env);
void					init_player_sprite_buttons(t_env *env);
void					init_enemy_general_env(t_env *env);
void					init_enemy_sector_env(t_env *env);
void					init_enemy_sprite_env(t_env *env);
void					init_enemy_general_buttons(t_env *env);
void					init_enemy_sector_buttons(t_env *env);
void					init_enemy_sprite_buttons(t_env *env);
void					init_object_general_env(t_env *env);
void					init_object_sector_env(t_env *env);
void					init_object_sprite_env(t_env *env);
void					init_object_general_buttons(t_env *env);
void					init_object_sector_buttons(t_env *env);
void					init_object_sprite_buttons(t_env *env);
void					init_selection_tabs(t_env *env);
int						init_array_sprite_buttons(t_env *env);
int						init_skybox_selection_buttons(t_env *env);
void					init_event_panel_buttons(t_env *env);
void					init_target_panel_buttons(t_env *env);
void					init_action_panel_buttons(t_env *env);
void					init_conditions_tabs_buttons(t_env *env);
void					init_exec_conditions_panel_buttons(t_env *env);
void					init_condition_panel_buttons(t_env *env);
void					init_condition_event_buttons(t_env *env);
void					init_condition_target_buttons(t_env *env);
void					init_condition_event_buttons(t_env *env);
int						init_objects(t_env *env, t_map_parser *parser);
int						init_enemies(t_env *env, t_map_parser *parser);

#endif
