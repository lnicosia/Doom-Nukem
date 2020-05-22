/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:51:13 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 17:08:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "utils.h"
# include "editor.h"
# include "defines_images.h"
# include "map_parser.h"
# include "events_parser.h"

typedef struct			s_env
{
	t_resource			resource;
	t_map_parser		parser;
	t_events_parser		eparser;
	t_sdl				sdl;
	t_player			player;
	t_options			options;
	t_keys				keys;
	t_inputs			inputs;
	t_time				time;
	t_animation			jump;
	t_animation			crouch;
	t_gravity			gravity;
	t_animation			shot;
	t_animation			weapon_change;
	t_animation			player_hurt;
	t_vertex			*vertices;
	t_sector			*sectors;
	t_object			*objects;
	t_enemy				*enemies;
	t_sprite			enemy_sprites[MAX_ENEMY_SPRITES];
	t_sprite			object_sprites[MAX_OBJECT_SPRITES];
	t_texture			sprite_textures[MAX_SPRITES_TEXTURES];
	t_texture			wall_textures[MAX_WALL_TEXTURE];
	t_texture			ui_textures[MAX_UI_TEXTURES];
	t_texture			mini_skyboxes[MAX_SKYBOX * 2];
	t_weapons			weapons[NB_WEAPONS];
	t_menu				button[NB_BUTTON];
	t_render_vertex		skybox[5];
	t_sound				sound;
	t_editor			editor;
	t_camera			fixed_camera;
	t_projectile		projectile;
	t_list				*projectiles;
	t_explosion			explosion;
	t_list				*explosions;
	t_confirmation_box	confirmation_box;
	t_input_box			input_box;
	t_skybox			skyboxes[MAX_SKYBOX];
	Uint32				frame_timer;
	t_event				*global_events;
	size_t				nb_global_events;
	t_event				*wall_bullet_holes_events;
	size_t				nb_wall_bullet_holes_events;
	t_event				*floor_bullet_holes_events;
	size_t				nb_floor_bullet_holes_events;
	t_event				*ceiling_bullet_holes_events;
	size_t				nb_ceiling_bullet_holes_events;
	char				*snprintf;
	int					dialog_box;
	int					climb_sect;
	int					dialog_box_max_lines;
	size_t				dialog_box_line_size;
	char				*dialog_box_str;
	int					next_dialog;
	int					fatal_error;
	int					checking_collisions_with_player;
	int					playing;
	int					sector_is_straight;
	int					visible_sectors;
	int					skybox_computed;
	int					selected_wall1;
	int					selected_wall2;
	int					selected_floor;
	int					selected_wall_sprite_sprite;
	int					selected_wall_sprite_wall;
	int					hovered_wall_sprite_sprite;
	int					hovered_wall_sprite_wall;
	int					hovered_wall_sprite_sector;
	int					selected_floor_sprite;
	int					selected_ceiling_sprite;
	int					selected_ceiling;
	int					selected_object;
	int					selected_enemy;
	int					selected_stat;
	int					new_selection;
	int					drawing;
	double				horizon;
	int					option;
	int					menu;
	int					in_game;
	int					menu_select;
	int					menu_edit;
	int					aplicate_changes;
	int					fps;
	size_t				fps_count;
	double				*zbuffer;
	int					*sector_list;
	int					screen_sectors_size;
	int					screen_w[3];
	int					screen_h[3];
	char				*res[3];
	int					w;
	int					h;
	int					h_w;
	int					h_h;
	int					i;
	int					running;
	int					nb_explosions;
	int					nb_sectors;
	int					nb_vertices;
	int					nb_objects;
	int					nb_enemies;
	int					*ymax;
	int					*ymin;
	int					shooting;
	int					new_wall_bullet_hole;
	int					new_floor_bullet_hole;
	int					new_ceiling_bullet_hole;
	int					new_bullet_hole_sector;
	int					new_bullet_hole_wall;
	t_v2				new_bullet_hole_pos;
	t_point				minimap_pos;
	t_point				minimap_size;
	t_point				crosshair_pos;
	int					current_object;
	int					objects_start;
	int					objects_end;
	int					test_time;
	int					contains_skybox;
	Uint32				press_wall_sprite_color;
	int					press_wall_sprite_intensity;
	char				*save_file;
	t_list				*events;
	t_list				*queued_values;
	double				difficulty;
	double				sprite_time;
	int					enemies_main_sprites[MAX_ENEMIES];
	int					objects_main_sprites[MAX_OBJECTS];
	char				*event_types[MAX_TARGET_TYPES + 1];
	char				*event_links_types[MAX_TRIGGER_TYPES + 1];
	int					(*print_target_data[MAX_TARGET_TYPES + 1])
	(struct s_env *, t_event *, t_point, int size);
	int					(*print_condition_target_data[MAX_TARGET_TYPES + 1])
	(struct s_env *, t_condition *, t_point, int size);
	int					(*print_link_target_data[MAX_TRIGGER_TYPES + 1])
	(struct s_env *, t_condition *, t_point, int size);
	t_button			start_game_button;
	t_button			previous_difficulty;
	t_button			next_difficulty;
	t_button			option_menu_ig;
	t_button			exit_button;
	t_button			return_button;
	t_button			music_vol_down;
	t_button			music_vol_up;
	t_button			sounds_vol_up;
	t_button			sounds_vol_down;
	pid_t				pid;
	pid_t				c_pid;
	t_init				init;
	int					hud_start;
	int					editor_start;
	int					enemies_start;
	int					wall_sprites_start;
	int					objects_sprites_start;
}						t_env;

/*
**	  -------------
**	 ---------------
**	----FUNCTIONS----
**	 ---------------
**	  -------------
*/

/*
**	Protection
*/

int						invalid_char(const char *location,
const char *expected, char c, t_map_parser *parser);
int						missing_data(const char *missing_data,
t_map_parser *parser);
int						extra_data(const char *missing_data,
t_map_parser *parser);
int						custom_error_with_line(const char *message,
t_map_parser *parser);
int						sector_error(const char *message, int sector,
t_map_parser *parser);

//	init bmp before parsing
int					check_resources(t_env *env);
int					init_wall_textures(t_env *env);
int					init_ui_textures(t_env *env);
int					init_ui_textures2(t_env *env);
int					init_ui_textures3(t_env *env);
int					init_ui_textures4(t_env *env);
int					init_ui_textures5(t_env *env);
int					init_ui_textures6(t_env *env);
int					init_sprites_textures(t_env *env);
int					init_skyboxes_textures(t_env *env);
int					init_skyboxes_textures1(t_env *env);
int					init_hud_textures(t_env *env);
int					init_enemies_sprites_textures(t_env *env);
int					init_objects_sprites_textures(t_env *env);
int					init_wall_sprites_textures(t_env *env);
int					init_editor_sprites(t_env *env);

//	when parsing init resources again
int					check_existing_files(t_env *env, char *name);
int					check_existing_fonts(t_env *env, char *name);
int					check_existing_sounds(t_env *env, char *name);
int					check_wall_textures(t_env *env);
int					check_wall_textures2(t_env *env);
int					check_wall_textures3(t_env *env);
int					check_textures(t_env *env);
int					check_directories(void);
int					check_sprites_textures(t_env *env);
int					check_hud_textures(t_env *env);
int					check_skyboxes(t_env *env);
int					check_skyboxes2(t_env *env);
int					check_skyboxes3(t_env *env);
int					check_skyboxes4(t_env *env);
int					check_skyboxes5(t_env *env);
int					check_skyboxes6(t_env *env);
int					check_shotgun(t_env *env);
int					check_raygun(t_env *env);
int					check_gatling(t_env *env);
int					check_gun(t_env *env);
int					check_sounds(t_env *env);
int					check_sounds6(int fd, t_env *env);
int					check_ui(t_env *env);
int					check_fonts(t_env *env);
int					check_fonts1(t_env *env);
int					check_fonts2(t_env *env);
int					check_fonts3(t_env *env);
int					check_fonts4(t_env *env);
int					check_fonts5(t_env *env);
int					check_fonts6(t_env *env);
int					check_fonts7(t_env *env);
int					check_fonts8(t_env *env);
int					check_fonts9(t_env *env);
int					check_fonts10(t_env *env);
int					check_fonts11(t_env *env);
int					new_parsed_hud_file(char *name, t_env *env);
int					new_parsed_textures(char *name, t_env *env);
int					map_parse_hud(t_env *env, t_map_parser *parser);
int					map_parse_ui(t_env *env, t_map_parser *parser);
int					map_parse_textures(t_env *env, t_map_parser *parser);
int					map_parse_sounds(t_env *env, t_map_parser *parser);
int					map_parse_sprites(t_env *env, t_map_parser *parser);
int					map_parse_skyboxes(t_env *env, t_map_parser *parser);
int					map_parse_fonts(t_env *env, t_map_parser *parser);
int					skip_file(t_map_parser *parser);
int					init_mipmap_arrays(t_env *env);

/*
** Editor functions
*/

int						light_option(void *param);
int						zbuffer_option(void *param);
int						fps_option(void *param);
int						quit_options(void *param);
int						mipmapping_option(void *param);
int						editor(t_env *env);
int						editor_2d(t_env *env);
void					zoom(t_env *env);
int						print_events_tab(t_env *env);
int						print_event_selection(t_env *env, size_t nb);
void					wall_sprites_keys(t_env *env, t_v2 *pos, t_v2 *scale);
void					wall_sprites_keyup(t_env *env, t_v2 *pos, t_v2 *scale);
void					editor_wall_sprites_keyup(t_env *env);
int						general_keyup(t_env *env);
void					start_editor_menu(t_env *env);
int						editor_options1(t_env *env, t_point center,
t_point size);
int						editor_keys(t_env *env);
int						editor_keys6(t_env *env);
int						save_map_keys(t_env *env);
int						editor_3d_keys(t_env *env);
int						check_move_player_conditions(t_env *env);
int						editor_options_keys(t_env *env);
int						editor_mouse(t_env *env);
int						editor_keyup(t_env *env);
int						editor_keyup6(t_env *env);
int						select_sector(t_env *env);
int						space_pressed(t_env *env);
int						vertex_creation_possible(t_env *env);
int						editor_left_click_up(t_env *env);
int						new_vertex(t_env *env, int clicked_vertex);
int						existing_vertex(t_env *env, int clicked_vertex);
int						editor_3d_keyup(t_env *env);
int						selection_tabs_keyup(t_env *env);
int						editor_options_keyup(t_env *env);
int						editor_mouseup(t_env *env);
int						change_mode(void *target);
int						save_button(void *target);
void					hline(t_env *env, int y);
void					vline(t_env *env, int x);
int						add_vertex(t_env *env);
int						add_enemy(t_env *env);
int						add_vertex_to_current_sector(t_env *env, int num);
t_circle				new_circle(Uint32 line_color, Uint32 color,
t_point center, int radius);
void					print_vertex(t_env *env, int num);
void					print_vertices(t_env *env);
void					print_sectors(t_env *env);
TTF_Font				*get_correct_font(int size, t_env *env);
int						get_existing_vertex(t_env *env);
int						get_existing_not_dragged_vertex(t_env *env);
void					add_player(t_env *env);
int 					editor_hud(t_env *env);
int						editor_options_hud(t_env *env);
void					editor_options_rectangles(t_env *env);
int						editor_options_buttons(t_env *env);
int						editor_options_ceil_floor(t_env *env);
int						editor_options_textures(t_env *env);
int						get_clockwise_order(t_env *env);
void					revert_sector_order(t_env *env);
int						add_sector(t_env *env);
int						add_object(t_env *env);
int						fill_new_sector(t_sector *sector, t_env *env);
int						fill_sector_first_vertex(t_sector *sector, t_env *env);
int						fill_sector_last_vertex(t_sector *sector, t_env *env);
int						editor_render(t_env *env);
int						save_map(void *param);
int						revert_sector(t_sector *sector, t_env *env);
int						get_clockwise_order_sector(t_env *env, int index);
void					player_selection(t_env *env);
void					starting_player_selection(t_env *env);
void					objects_selection(t_env *env);
int						vertices_selection(t_env *env);
void					create_portals(t_env *env, t_sector new_sector);
int						check_vertex_inside_sector(t_env *env, t_v2 vertex);
int						is_new_vertex_valid(t_env *env, int index);
int						new_wall_intersects(t_env *env, int index);
t_vertex				find_second_vertex(t_env *env, t_sector sector,
int new_index, int index);
int						check_sector_intersections(t_env *env, t_sector sector,
t_vertex last, int index);
int						check_list_intersections(t_env *env, t_vertex *last,
int index);
int						is_new_sector_convex(t_env *env, t_list *tmp);
int						del_last_vertex(t_env *env);
int						delete_vertex(void *param);
int						update_sector(t_sector *sector, int vertex);
int						delete_sector(void *param);
int						delete_object(void *param);
int						delete_enemy(void *param);
int						current_vertices_contains(t_env *env, int vertex);
int						is_vertex_used(t_env *env, int vertex);
int						is_vertex_going_to_be_used(t_env *env, int sector,
int vertex);
int						is_vertex_used_by_others(t_env *env, int vertex,
int sector);
int						delete_invalid_sectors(t_env *env);
int						delete_invalid_vertices(t_env *env);
int						*get_vertex_sectors(t_env *env, int index);
int						is_new_dragged_vertex_valid(t_env *env, int index);
void					clear_portals(t_env *env);
int						delete_action(t_env *env);
int						editor_button_up(t_env *env);
t_sector				rotate_vertices(t_env *env, int i, int index);
void					update_enemies_z(t_env *env);
void					update_objects_z(t_env *env);
int						update_entities_sectors(t_env *env);
void					selected_information_on_enemy(t_env *env);
int						selected_information_in_sector(t_env *env);
void					get_new_floor_and_ceiling(t_env *env);
void					reset_selection(t_env *env);
void					reset_hover(t_env *env);
int						split_box_text(t_input_box *box, t_env *env);
char					*get_current_box_line(t_input_box *box, char *str);
void					get_selection_boundaries(size_t *start, size_t *end,
char *str, t_input_box *box);
int						find_input_box_max_char(t_input_box *box);
int						input_box_keys(t_input_box *box, t_env *env);
int						input_box_keys5(t_input_box *box, t_env *env);
int						input_box_mouse(t_input_box *box, t_point pos,
char *str, t_env *env);
int						new_input_box(t_input_box *box, t_point pos,
							int type, void *target);
int						new_input_var(t_input_box *box, t_point pos,
							int type, void *target);
int						set_double_stats(t_input_box *box);
int						validate_input(t_input_box *box, t_env *env);
int						del_char(t_input_box *box, int mode);
int						delete_box_selection(t_input_box *box);
char					ft_getchar(int input, int shift);
int						add_char(t_input_box *box, char c);
int						apply_texture(t_sector *sector, t_env *env, int i);
int						add_vertex_in_sector(t_env *env);
int						realloc_sector_arrays(t_env *env, int sector, int j);
int						split_sector(t_env *env);
int						update_current_wall(t_env *env, int i,
t_sector *sector);
int						check_pos_vertices(t_env *env);
int						update_neighbors(t_env *env, int index, int num,
t_sector *sector);
void					update_vertices(int index, t_sector *sector);
void					update_textures(int index, t_sector *sector);
int						update_double_tab(int index, double size,
double **tab);
int						update_int_tab(int index, int size, int **tab);
int						update_t_v2_tab(int index, int size, t_v2 **tab);
int						update_t_list_tab(int index, int size, t_list ***tab);
int						update_t_wall_sprite_tab(int index, int size,
t_wall_sprites **tab);
int						texture_tab(t_env *env, int nb_slots);
void					enemy_tab(t_env *env, int nb_slots);
void					object_tab(t_env *env, int nb_slots);
void					sprite_selection(t_env *env, int nb_slots);
int						is_mouse_on_a_wall(t_env *env);
int						editor_mode_button(t_env *env);
int						editor_options_button(t_env *env);
int						editor_save_button(t_env *env);
int						editor_launch_game(t_env *env);
int						launch_game(void *target);
int						going_in_2d_mode(t_env *env);
int						going_in_3d_mode(t_env *env);
int						print_vertex_informations(t_env *env);
int						print_global_events_tab(t_env *env);
int						print_enemy_events_tab(t_env *env);
int						print_object_events_tab(t_env *env);
int						print_sector_events_tab(t_env *env);
int						print_event(t_env *env, t_event *event);
int						print_event_action(t_env *env, t_event *event);
char					*get_condition_type_str(t_condition *condition);
int						print_event_launch_condition(t_env *env,
t_condition *condition);
int						print_event_exec_condition(t_env *env,
t_condition *condition);
int						print_wall_sprite_sector_tab(t_env *env);
int						print_wall_sprite_events_tab(t_env *env);
int						print_sector_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_wall_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_wall_sprite_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_floor_sprite_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_ceiling_sprite_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_vertex_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_weapon_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_enemy_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_object_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_event_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_nothing_target(t_env *env, t_event *event,
t_point pos, int size);
int						print_sector_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_wall_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_wall_sprite_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_floor_sprite_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_ceiling_sprite_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_vertex_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_weapon_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_enemy_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_object_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_event_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_nothing_condition_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_global_link_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_sector_link_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_enemy_link_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_object_link_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						print_wall_sprite_link_target(t_env *env,
t_condition *condition, t_point pos, int size);
int						is_events_tab_visible(t_env *env);
int						are_event_selection_buttons_visible(t_env *env);
int						are_events_selection_buttons_visible(t_env *env);
int						is_modify_event_button_visible(t_env *env);
int						are_launch_condition_selection_buttons_visible(
	t_env *env);
int						are_exec_condition_selection_buttons_visible(
	t_env *env);
int						check_sector_exec_conditions(t_env *env, int sector);
int						check_sector_launch_conditions(t_env *env, int sector);
t_button_param			*new_button_param(t_env *env, int i);
void					new_tabs_position(t_env *env);
int						check_event_creation(t_env *env);
int						new_condition_target(t_env *env);
int						new_event_target(t_env *env);
void					tabs_gestion(t_env *env);
int						change_target_texture(t_env *env);
void					editor_show_tab(t_env *env);
int						general_keyup(t_env *env);
int						sprite_tab_keyup(t_env *env);
int						events_tab_keyup(t_env *env);
int						editor_3d_tabs_keyup(t_env *env);
void					editor_options_tab_keyup(t_env *env);
void					editor_wall_sprites_keyup(t_env *env);
void					change_ceiling_floor_height(t_env *env);
int						reduce_ceiling_texture_scale(t_env *env);
int						reduce_floor_texture_scale(t_env *env);
int						reduce_wall_texture_scale(t_env *env);
int						increase_ceiling_texture_scale(t_env *env);
int						increase_floor_texture_scale(t_env *env);
int						increase_wall_texture_scale(t_env *env);
int						increase_walls_texture_scale(t_env *env);
int						reduce_walls_texture_scale(t_env *env);
int						check_entities_height(t_env *env);
int						left_walls_texture_align(t_env *env);
int						right_walls_texture_align(t_env *env);
int						increase_wall_texture_number(t_env *env,
t_sector *sector);
int						decrease_wall_texture_number(t_env *env,
t_sector *sector);
int						increase_slope(t_env *env);
int						decrease_slope(t_env *env);
int						increase_slope_keyup(t_env *env);
int						decrease_slope_keyup(t_env *env);
int						change_floor_slope_start(t_env *env);
int						change_ceiling_slope_start(t_env *env);
int						increase_floor_slope_start(t_env *env);
int						decrease_floor_slope_start(t_env *env);
int						increase_ceiling_slope_start(t_env *env);
int						decrease_ceiling_slope_start(t_env *env);
int						change_slope_start(t_env *env);
int						editor_3d_tab_keys(t_env *env);
int						selection_tab_button_keys(t_env *env);
int						wall_edit_keys(t_env *env);
int						wall_edit_keyup(t_env *env);
void					editor_wall_sprites_keys(t_env *env);
int						change_textures_scales(t_env *env);
int						change_walls_texture_scale(t_env *env);
int						change_slopes(t_env *env);
int						change_slopes_keyup(t_env *env);
int						change_texture_alignement(t_env *env);
int						change_textures_scales(t_env *env);
int						change_walls_texture(t_env *env);
int						check_height_at_pos(t_env *env, t_sector *sector,
t_v3 pos, int target_height);
int						next_ambiance_music(void *target);
int						previous_ambiance_music(void *target);
int						next_fighting_music(void *target);
int						previous_fighting_music(void *target);
int						check_all_angles(t_v2 *p, int res, int i,
int straight);
int						update_existing_events(t_env *env,
t_event_target target);
int						update_sector_existing_events(t_env *env,
t_event_target target);
int						update_vertex_existing_events(t_env *env,
t_event_target target);
int						update_enemy_existing_events(t_env *env,
t_event_target target);
int						update_object_existing_events(t_env *env,
t_event_target target);
int						check_enemies_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger);
int						check_enemy_death_events_targets(t_env *env,
t_enemy *enemy, t_event_target target, t_event_trigger *trigger);
int						check_enemy_collision_events_targets(t_env *env,
t_enemy *enemy, t_event_target target, t_event_trigger *trigger);
int						check_global_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger);
int						check_sectors_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger);
int						check_walk_out_events_targets(t_env *env,
t_sector *sector, t_event_target target, t_event_trigger *trigger);
int						check_walk_in_events_targets(t_env *env,
t_sector *sector, t_event_target target, t_event_trigger *trigger);
int						check_stand_events_targets(t_env *env,
t_sector *sector, t_event_target target, t_event_trigger *trigger);
int						check_event_targets(t_env *env,
t_event *event, t_event_target target, t_event_trigger *trigger);
int						check_event_conditions_targets(t_env *env,
t_event *event, t_event_target target, t_event_trigger *trigger);
int						check_condition_targets(t_env *env,
t_condition *condition, t_event_target target, t_event_trigger *trigger);
int						events_to_delete_contains(t_env *env,
t_event_trigger *trigger);
int						delete_events_to_delete_list(void *param);
int						delete_selected_sector(void *param);
int						delete_selected_vertex(void *param);
int						delete_linked_events(t_env *env);
int						delete_events_to_delete_list(void *param);
int						delete_wall_sprite(void *param);
int						delete_floor_sprite(void *param);
int						delete_ceiling_sprite(void *param);
int						editor_left_click_up(t_env *env);
int						is_point_in_rectangle(t_point point, t_point pos,
t_point size);
int						is_mouse_on_texture_selection_tab(t_env *env);
int						is_mouse_on_object_selection_tab(t_env *env);
int						is_mouse_on_enemy_selection_tab(t_env *env);
int						is_mouse_on_wall_sprite_selection_tab(t_env *env);
int						is_mouse_on_any_selection_tab(t_env *env);
int						change_texture_alignement_keyup(t_env *env);
int						change_walls_texture_keyup(t_env *env);
int						change_textures_scales_keyup(t_env *env);
int						slopes_keyup(t_env *env);

/*
**	Input boxes checkers and updaters
*/

int						check_floor_slope_input_box(void *penv);
int						check_floor_height_input_box(void *penv);
int						check_ceiling_slope_input_box(void *penv);
int						check_ceiling_height_input_box(void *penv);
int						check_texture_input_box(void *penv);
int						check_sprite_input_box(void *penv);
int						check_sprite_scale_input_box(void *penv);
int						check_entities_sprite_scale_input_box(void *penv);
int						check_texture_scale_input_box(void *penv);
int						check_damage_input_box(void *penv);
int						check_light_data_input_box(void *penv);
int						check_gravity_input_box(void *penv);
int						check_true_false_input_box(void *penv);
int						check_portal_input_box(void *penv);
int						check_health_input_box(void *target);
int						check_speed_input_box(void *target);
int						check_angle_input_box(void *target);
int						update_sector_input_box(void *penv);
int						update_floor_sprite_scale_input_box(void *penv);
int						update_ceiling_sprite_scale_input_box(void *penv);
int						update_sector_entities_light_input_box(void *penv);
int						update_object_input_box(void *penv);
int						update_enemy_input_box(void *penv);

/*
**	Keys and keyup checkers and updaters
*/

int						height_check(t_env *env);
int						check_sprite_pos(t_v2 *pos);
int						check_texture_scale(t_env *env, t_v2 *scale);

/*
**	Editor buttons functions
*/

int						nothing(void *target);
int						save_texture(void *target);
int						save_enemy(void *target);
int						save_object(void *target);
int						save_sprite(void *target);
int						add_enemy_button(void *target);
int						add_sprite(void *target);
int						add_object_button(void *target);
int						general_tab(void *target);
int						sector_tab(void *target);
int						sprite_tab(void *target);
int						update_wall_texture_button(void *penv);
int						update_ceiling_texture_button(void *penv);
int						update_floor_texture_button(void *penv);
int						save_texture(void *target);
int						save_enemy(void *target);
int						add_enemy_button(void *target);
int						add_object_button(void *target);
int						events_tab(void *target);
int						open_texture_selection(void *param);
void					enemy_selection(t_env *env);
int						open_enemy_selection(void *param);
int						open_object_selection(void *param);
int						open_wall_sprite_selection(void *param);
int						update_ceiling_sprite_arrays(t_env *env);
int						update_floor_sprite_arrays(t_env *env);
int						update_wall_sprite_arrays(t_env *env);
int						change_var(void *target);
int						change_floor_sprite_scale(void *penv);
int						change_ceiling_sprite_scale(void *penv);
int						change_wall_sprite_scale(void *penv);
int						change_color(void *penv);
int						change_brightness_or_intensity(void *penv);
int						change_gravity(void *penv);
int						change_sprite(void *target);
int						change_enemy_scale(void *target);
int						change_texture_scale(void *target);
int						change_enemy_damage(void *target);
int						change_object_damage(void *target);
int						change_object_scale(void *target);
int						change_ceiling_texture_scale(void *target);
int						change_floor_texture_scale(void *target);
int						change_ceiling_texture_align(void *target);
int						change_floor_texture_align(void *target);
int						change_floor_height(void *target);
int						change_floor_slope(void *target);
int						change_ceiling_height(void *target);
int						change_ceiling_slope(void *target);
int						change_health(void *target);
int						change_speed(void *target);
int						change_angle(void *target);
int						next_selected_wall(void	*target);
int						change_slope_direction(void	*target);
int						get_main_sprite(int sprite, t_env *env);
void					change_ceiling_floor_height_keyup(t_env *env);
void					check_height_protections(t_env *env, t_sector *sector);
void					check_slopes_protections(t_env *env, t_sector *sector);
int						get_main_enemy_sprite(int sprite, t_env *env);
int						parse_ambient_music(t_env *env, t_map_parser *parser);
int						parse_fight_music(t_env *env, t_map_parser *parser);

/*
**	prints and draw buttons for informations on a selected element
*/

int						print_floor_general_tab(t_env *env);
int						print_ceiling_general_tab(t_env *env);
int						print_player_general_tab(t_env *env);
int						print_wall_general_tab(t_env *env);
int						print_vertices_general_tab(t_env *env);
int						print_sector_general_tab(t_env *env);
int						print_enemy_general_tab(t_env *env);
int						print_object_general_tab(t_env *env);
int						print_floor_sector_tab(t_env *env);
int						print_ceiling_sector_tab(t_env *env);
int						print_player_sector_tab(t_env *env);
int						print_wall_sector_tab(t_env *env);
int						print_enemy_sector_tab(t_env *env);
int						print_object_sector_tab(t_env *env);
int						print_floor_sprite_tab(t_env *env);
int						print_ceiling_sprite_tab(t_env *env);
int						print_wall_sprite_tab(t_env *env);

/*
**	buttons for selections
*/

int						wall_buttons(t_env *env);
int						wall_general_tab_keys(t_env *env);
int						ceiling_buttons(t_env *env);
int						floor_buttons(t_env *env);
int						sector_buttons(t_env *env);
int						player_buttons(t_env *env);
int						enemy_buttons(t_env *env);
int						object_buttons(t_env *env);
int						floor_sprite_buttons(t_env *env);
int						ceiling_sprite_buttons(t_env *env);
int						wall_sprite_buttons(t_env *env);
int						wall_buttons_up(t_env *env);
int						wall_general_tab_keyup(t_env *env);
int						ceiling_buttons_up(t_env *env);
int						floor_buttons_up(t_env *env);
int						sector_buttons_up(t_env *env);
int						player_buttons_up(t_env *env);
int						enemy_buttons_up(t_env *env);
int						object_buttons_up(t_env *env);
int						floor_sprite_buttons_up(t_env *env);
int						ceiling_sprite_buttons_up(t_env *env);
int						wall_sprite_buttons_up(t_env *env);

/*
** Main functions
*/

int						doom(t_env *env);
int						doom_poll_event(t_env *env);
int						crash(char *str, t_env *env);
int						first_frame(t_env *env);
int						launch_events(t_env *env);
void					reset_render_utils(t_camera *camera, t_env *env);

void					set_camera(t_camera *camera, t_env *env);
int						valid_map(t_env *env);
int						is_sector_concave(t_sector sector, t_env *env);
int						check_intersection_with_sector(t_sector sector,
t_env *env, t_vertex v1, t_vertex v2);
int						check_neighbor_validity(t_sector sector, t_env *env);
int						check_duplicate_vertices(t_sector sector, t_env *env);
int						is_inside(t_sector sector, t_env *env);
int						check_sectors_inside(t_sector sector, int sect,
t_env *env);
int						segments_intersect_editor(t_v2 v1, t_v2 v2, t_v2 v3,
t_v2 v4);
int						check_vertex_inside_sector(t_env *env, t_v2 vertex);
int						generate_mipmaps(t_env *env);
int						generate_maps_for_texture(t_texture *texture);
int						set_camera_map_array(t_camera *camera, int i,
int j, t_env *env);
int						set_camera_sprites_array(t_camera *camera, int i,
int j, t_env *env);
int						set_sector_wall_map_array(t_sector *sector,
t_texture *texture, int i, t_env *env);
int						set_sector_floor_map_array(t_sector *sector,
t_texture *texture, t_env *env);
int						set_sector_ceiling_map_array(t_sector *sector,
t_texture *texture, t_env *env);
t_projectile_data		new_projectile_data(t_v3 pos, double angle,
double scale, int sprite);
t_projectile_data_2		new_projectile_data_2(double angle_z, double radius);
t_projectile_stats		new_projectile_stats(double size_2d, int damage,
double speed, double height);
t_explosion_data		new_explosion_data(t_v3 pos, double radius, int damage,
int sprite);
int						start_game_button(t_env *env);
int						next_difficulty_button(t_env *env);
int						prev_difficulty_button(t_env *env);
int						music_vol_up_button(t_env *env);
int						music_vol_down_button(t_env *env);
int						sounds_vol_up_button(t_env *env);
int						sounds_vol_down_button(t_env *env);
int						option_menu_ig_button(t_env *env);
int						exit_button(t_env *env);
int						return_button(t_env *env);
int						hitscan_enemies(t_env *env, int i);
int						hitscan_objects(t_env *env, int i);
int						damage_done(t_env *env, double rotated_pos_w);
int						is_player_alive(t_env *env);
int						draw_weapons(t_env *env);
/*
** Screen utils
*/

void					clear_image(t_env *env);
int						update_screen(t_env *env);
int						update_screen_zbuffer(t_env *env);
t_printable_text		new_printable_text(char *text, TTF_Font *font,
unsigned int color, int size);
int						print_text(t_point pos,
				t_printable_text text, t_env *env);
void					apply_surface(SDL_Surface *surface,
				t_point pos, t_point size, t_env *env);
void					apply_image(t_texture texture,
				t_point pos, t_point size, t_env *env);
void					apply_image_selected(t_texture texture,
				t_point pos, t_point size, t_env *env);
void					apply_sprite(t_sprite sprite,
				t_point pos, t_point size, t_env *env);
void					apply_sprite_selected(t_sprite sprite,
				t_point pos, t_point size, t_env *env);
SDL_Surface				*get_closest_mipmap(t_texture texture, t_point size);
int						print_press_text(t_env *env);
int						fps(t_env *e);
int						print_debug(t_env *env);
void					fill_triangle_minimap(t_v3 v[3], t_env *env);
void					fill_triangle(t_v3 v[3], Uint32 color, t_env *env);
float					edge(t_v3 c0, t_v3 c1, t_v3 p);
unsigned int			blend_alpha(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int			blend_add(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int			blend_mul(unsigned int src, unsigned int dest);
Uint32					apply_light(Uint32 src, Uint32 color, int intensity,
int brightness);
Uint32					apply_light_both(Uint32 src, Uint32 color,
int intensity, int brightness);
Uint32					apply_light_color(Uint32 src, Uint32 color,
int intensity);
Uint32					apply_light_brightness(Uint32 src, int brightness);
int						update_confirmation_box(t_confirmation_box *box,
char *str, int type, t_env *env);
int						no_pressed(void *param);
int						yes_pressed(void *param);
t_rectangle				new_rectangle(Uint32 inside_color, Uint32 line_color,
		int filled, int line_size);
t_button				new_button(t_rectangle up, t_rectangle pressed,
t_rectangle down, t_rectangle hover);
t_button				new_button_img(t_texture *up, t_texture *pressed,
t_texture *down, t_texture *hover);
t_button				new_image_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_hud_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_hud_pos_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_background_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_tab_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_rectangle_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_next_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_previous_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_previous_button_2(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_minus_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_add_button(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_next_arrow(int type, int (*action)(void *),
void *param, t_env *env);
t_button				new_previous_arrow(int type, int (*action)(void *),
void *param, t_env *env);
void					set_button_up_image(t_button *b, t_env *env,
SDL_Surface *surface);
void					set_button_down_image(t_button *b, t_env *env,
SDL_Surface *surface);
void					set_button_pressed_image(t_button *b, t_env *env,
SDL_Surface *surface);
void					set_button_hover_image(t_button *b, t_env *env,
SDL_Surface *surface);
void					set_button_up_rectangle(t_button *b, t_env *env,
t_rectangle rectangle);
void					set_button_down_rectangle(t_button *b, t_env *env,
t_rectangle rectangle);
void					set_button_pressed_rectangle(t_button *b, t_env *env,
t_rectangle rectangle);
void					set_button_hover_rectangle(t_button *b, t_env *env,
t_rectangle rectangle);
int						find_dialog_box_max_char(t_env *env);
int						dialog_event(void *param, void *penv);
int						find_dialog_box_max_char(t_env *env);

/*
** Main pipeline functions
*/

int						get_sprite_direction_projectile(
	t_projectile *projectile);
void					check_parsing(t_env *env);
int						keyup(t_env *env);
int						confirmation_box_keys(t_confirmation_box *box,
t_env *env);
int						confirmation_box_keyup(t_confirmation_box *box,
t_env *env);
int						editor_minimap(t_env *e);
void					game_minimap(t_env *env);
int						get_angle(t_point p[3]);
int						get_sector_first_angles(t_sector *sector, t_env *env);
int						count_sector_angles(t_sector *sector, t_env *env);
void					view(t_env *env);
void					reset_clipped(t_env *env);
t_v3					sprite_movement(t_env *env, double speed, t_v3 origin,
t_v3 destination);
int						weapon_animation(t_env *env, int sprite);
void					weapon_change(t_env *env);
int						next_possessed_weapon(t_env *env);
int						print_ammo(t_env *env);
int						shot(t_env *env);
void					wall_hack(t_env *env);
int						create_projectile(t_env *env, t_projectile_data data,
t_projectile_stats stats, t_projectile_data_2 data2);
int						create_explosion(t_env *env, t_explosion_data data,
int centered_sprite);
int						explosion_collision_player(t_env *env);
int						explosion_collision_objects(t_env *env);
int						explosion_collision_enemies(t_env *env);
void					activate_explosions(t_env *env);
int						projectiles_movement(t_env *env);
void					projectile_hits_nothing(t_v3 move,
t_projectile *projectile, t_list **tmp, t_env *env);
int						projectile_hits_floor(t_projectile *projectile,
t_env *env);
int						projectile_hits_ceiling(t_projectile *projectile,
t_env *env);
int						projectile_hits_player(t_projectile *projectile,
t_list **tmp, t_env *env);
int						projectile_hits_object(t_projectile *projectile,
t_list **tmp, t_env *env);
int						projectile_hits_enemy(int nb, t_projectile *projectile,
t_list **tmp, t_env *env);
int						projectile_hits_wall(int collision,
t_projectile *projectile, t_env *env);
int						hitscan(t_env *env, int i);
int						aoe_damage(double distance, double radius, int damage);
int						do_intersect(t_v2 p1, t_v2 q1, t_v2 p2, t_v2 q2);
int						intersection_check(t_v2 w1, t_v2 w2, t_v2 p1, t_v2 p2);
int						diff_value(int nb1, int nb2, int a, int b);
int						diff_sign(double nb1, double nb2);
int						in_range(double nb, double val1, double val2);
int						pos_changed_sector(t_env *env, t_sector *sector,
t_point data, t_v3 pos);
int						player_changed_sector(t_env *env, t_sector *sector,
t_point data, t_v3 pos);
void					precompute_slopes(t_env *env);
double					get_floor_at_pos(t_sector *sector, t_v3 pos,
t_env *env);
double					get_ceiling_at_pos(t_sector *sector, t_v3 pos,
t_env *env);
t_v2					get_sector_normal(t_sector *sector, t_env *env,
int start_slope);
void					update_inputs(t_env *env);
int						move_player(t_env *env);
void					update_player_pos(t_env *env);
void					update_camera_position(t_camera *camera);
int						get_sector(t_env *env, t_v3 p, int origin);
int						get_sector_global(t_env *env, t_v3 p);
int						get_sector_no_z(t_env *env, t_v3 p);
int						get_sector_no_z_origin(t_env *env, t_v3 p, int origin);
void					set_sector_xmax(t_env *env, t_sector *sector);
void					set_sectors_xmax(t_env *env);
int						keys(t_env *env);
void					update_player_z(t_env *env);
void					update_start_player_z(t_env *env);
void					update_enemy_z(t_env *env, int i);
void					update_enemy_light(t_env *env, int i);
void					update_enemy(t_env *env, int i);
void					update_object_z(t_env *env, int i);
void					update_object_light(t_env *env, int i);
void					update_object(t_env *env, int i);
void					update_sector_entities_light(t_env *env, int sector);
void					update_sector_entities_z(t_env *env, int sector);
void					update_sector_enemies_z(t_env *env, int sector);
void					update_floor(t_env *env);
void					update_sector_slope(t_env *env, t_sector *sector);
void					game_time(t_env *env);
void					gravity(t_env *env);
void					animations(t_env *env);
void					fall(t_env *env);
void					init_fall(t_env *env);
void					reset_state(t_env *env);
void					drop(t_env *env);
void					jump(t_env *env);
void					crouch(t_env *env);
void					add_image(t_env *env, int i, int x, int y);
int						start_game_menu(t_env *env);
int						start_game(void *param);
int						next_difficulty(void *param);
int						previous_difficulty(void *param);
int						open_options(void *param);
int						exit_button_func(void *param);
int						option_menu_ig(t_env *env);
int						music_volume_up(void *param);
int						music_volume_down(void *param);
int						sounds_volume_up(void *param);
int						sounds_volume_down(void *param);
int						return_button_func(void *param);
void					add_button(t_env *env, int text, int x, int y,
int ref_but);
int						button_leftclick(t_env *env, int nb);
void					select_menu(t_env *env);
int						inside_tmp_sect(t_vertex v1, t_vertex *tmp_sect,
int size);
int						is_in_sector(t_env *env, int sector, t_v3 pos);
int						is_in_sector_no_z(t_env *env, int sector, t_v2 pos);
double					distance_two_points_2d(double x1, double y1, double x2,
double y2);
double					distance_two_points_3d(t_v3 p1, t_v3 p2);
void					interactions(t_env *env);
void					activate_elevator(t_env *env);
void					create_elevator(t_env *env);
int						create_levels(t_env *env, int nb_floors);
int						get_nb_floors(t_env *env, t_sector *sector);
void					climb(t_env *env);
double					apply_climb(double vel);
double					apply_drop(double vel);
int						project_wall(int i, t_camera *camera, t_sector *sector,
t_env *env);
void					update_sprites_state(t_env *env);
int						death(t_env *env);
int						stop_game(void *param);
int						respawn(void *param);
int						print_results(t_env *env);
int						check_player_z(t_env *env);
void					hidden_sectors(t_env *env);
void					create_hidden_sector(t_env *env);
void					activate_sector(t_env *env, int i);
int						button_keys(t_button *b, t_env *env);
int						button_keyup(t_button *b, t_env *env);
int						is_mouse_on_button(t_button b, t_point mouse);
int						is_mouse_on_event_panel(t_env *env);
t_point					get_button_current_size(t_button b);
int						editor_start_game(t_env *env);
int						add_ceiling_projectile_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int						add_floor_projectile_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int						add_wall_projectile_bullet_hole(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
int						add_ceiling_hitscan_bullet_hole(t_sector *sector,
t_env *env);
int						add_floor_hitscan_bullet_hole(t_sector *sector,
t_env *env);
int						add_wall_hitscan_bullet_hole(t_sector *sector, int i,
t_env *env);
int						shift_ceiling_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int						shift_floor_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int						shift_wall_bullet_hole(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
t_v2					get_ceiling_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, t_env *env);
t_v2					get_floor_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, t_env *env);
t_v2					get_wall_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
int						delete_wall_bullet_hole(void *param, void *env);
int						delete_floor_bullet_hole(void *param, void *env);
int						delete_ceiling_bullet_hole(void *param, void *env);
int						modify_wall_sprite(void *param, void *env);
int						modify_floor_sprite(void *param, void *env);
int						modify_ceiling_sprite(void *param, void *env);
void					shift_ceiling_bullet_hole_events(int sector,
int sprite, t_env *env);
void					shift_floor_bullet_hole_events(int sector, int sprite,
t_env *env);
void					shift_wall_bullet_hole_events(int sector, int wall,
int sprite, t_env *env);
int						projectile_on_wall_sprite(t_v2 pos, t_sector *sector,
		int wall, t_env *env);
int						play_sound(t_env *env, FMOD_CHANNEL **chan,
						FMOD_SOUND *sound, float vol);
int						play_music(t_env *env, FMOD_CHANNEL **chan,
						FMOD_SOUND *sound, float vol);
int						player_hit_sound(t_env *env);
int						enemy_hit_sound(int enemy, t_env *env);
int						player_combat_state(t_env *env);
int						next_event(void *param);
int						previous_event(void *param);
int						next_launch_condition(void *param);
int						previous_launch_condition(void *param);
int						next_exec_condition(void *param);
int						previous_exec_condition(void *param);
void					set_trigger(t_env *env, t_event_trigger *trigger);
int						precompute_floor_sprite_scales(int sector, int sprite,
t_env *env);
int						precompute_ceiling_sprite_scales(int sector,
int sprite, t_env *env);
int						menu_keys(t_env *env);
int						menu_keyup(t_env *env);
int						option_menu_ig_keyup(t_env *env);
int						option_menu_ig_keys(t_env *env);
size_t					get_decimal_len(double nb);
size_t					get_double_len(double nb);
int						win(void *param, void *penv);
int						event_target_exists(t_event *event, t_env *env);
int						event_target_exists0(t_event *event, t_env *env);
int						event_target_exists1(t_event *event, t_env *env);
int						event_target_exists2(t_event *event, t_env *env);
int						event_target_exists3(t_event *event, t_env *env);
int						event_target_exists4(t_event *event, t_env *env);
int						event_target_exists5(t_event *event, t_env *env);
int						event_target_exists6(t_event *event, t_env *env);
int						condition_target_exists(t_condition *condition,
t_env *env);
int						check_sector_order(t_env *env);
int						check_sector(t_sector sector, t_env *env);
int						dialog_event(void *param, void *penv);
int						set_new_string_input_box(t_input_box *box,
void *target);
void					set_enemy_height_on_floor(t_enemy *enemy);

/*
** objects functions
*/

void					object_anim_loop(t_env *env, int i);
int						object_destruction(t_env *env, int i, int nb_sprites);
int						explosion_animation(t_env *env, t_explosion *explosion,
int nb_sprites);

#endif
