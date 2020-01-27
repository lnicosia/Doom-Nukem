/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:51:13 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/27 14:57:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "utils.h"
# include "editor.h"
# define OX1 env->vertices[env->sectors[sector].vertices[i]].x
# define OX2 env->vertices[env->sectors[sector].vertices[i + 1]].x
# define OY1 env->vertices[env->sectors[sector].vertices[i]].y
# define OY2 env->vertices[env->sectors[sector].vertices[i + 1]].y

typedef struct		s_env
{
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
	t_enemies			*enemies;
	t_sprite			*enemy_sprites;
	t_sprite			*object_sprites;
	t_sprite			*wall_sprites;
	t_texture			sprite_textures[MAX_TEXTURES];
	t_texture			wall_textures[MAX_WALL_TEXTURE];
	t_texture			ui_textures[MAX_UI_TEXTURES];
	t_texture			mini_enemies_textures[MAX_MONSTER_MINI];
	t_weapons			weapons[NB_WEAPONS];
	t_menu				button[NB_BUTTON];
	t_render_vertex		skybox[5];
	t_audio				sound;
	t_editor 			editor;
	t_camera			fixed_camera;
	t_projectile		projectile;
	t_list				*projectiles;
	t_explosion			explosion;
	t_list				*explosions;
	t_vline_data		*vline_data;
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
	int					saving;
	int					playing;
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
	int					menu_start;
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
	int					first_frame;
	int					*ymax;
	int					*ymin;
	t_point				minimap_pos;
	t_point				minimap_size;
	t_point				crosshair_pos;
	int					current_object;
	int					objects_start;
	int					objects_end;
	int					test_time;
	int					contains_skybox;
	Uint32*				tmp_first_sprite;
	Uint32				press_wall_sprite_color;
	int					press_wall_sprite_intensity;
	char				*save_file;
	t_list				*events;
	t_list				*queued_values;
	int					enemy_main_sprite[MAX_ENEMIES];
	int					object_main_sprite[MAX_OBJECTS];
}					t_env;

/*
 * **	  -------------
 * **	 ---------------
 * **	----FUNCTIONS----
 * **	 ---------------
 * **	  -------------
 * */


/*
 * ** Editor functions
 * */

int					init_editor(int ac, char **av);
int					init_editor_hud(t_env *env);
void				init_editor_data(t_env *env);
void				init_editor_tab_buttons(t_env *env);
void				init_floor_buttons(t_env *env);
void				init_ceilling_buttons(t_env *env);
void				init_wall_buttons(t_env *env);
void				init_floor_general_env(t_env *env);
void				init_floor_sector_env(t_env *env);
void				init_floor_sprite_env(t_env *env);
void				init_floor_general_buttons(t_env *env);
void				init_floor_sector_buttons(t_env *env);
void				init_floor_sprite_buttons(t_env *env);
void				init_wall_general_env(t_env *env);
void				init_wall_sector_env(t_env *env);
void				init_wall_sprite_env(t_env *env);
void				init_wall_general_buttons(t_env *env);
void				init_wall_sector_buttons(t_env *env);
void				init_wall_sprite_buttons(t_env *env);
void				init_ceilling_general_env(t_env *env);
void				init_ceilling_sector_env(t_env *env);
void				init_ceilling_sprite_env(t_env *env);
void				init_ceilling_general_buttons(t_env *env);
void				init_ceilling_sector_buttons(t_env *env);
void				init_ceilling_sprite_buttons(t_env *env);
void				init_add_buttons(t_env *env);
void				init_add_enemy_buttons(t_env *env);
void				init_add_object_buttons(t_env *env);
void				init_sector_general_env(t_env *env);
void				init_sector_sector_env(t_env *env);
void				init_sector_general_buttons(t_env *env);
void				init_sector_sector_buttons(t_env *env);
void				init_player_general_env(t_env *env);
void				init_player_sector_env(t_env *env);
void				init_player_sprite_env(t_env *env);
void				init_player_general_buttons(t_env *env);
void				init_player_sector_buttons(t_env *env);
void				init_player_sprite_buttons(t_env *env);
void				init_enemy_general_env(t_env *env);
void				init_enemy_sector_env(t_env *env);
void				init_enemy_sprite_env(t_env *env);
void				init_enemy_general_buttons(t_env *env);
void				init_enemy_sector_buttons(t_env *env);
void				init_enemy_sprite_buttons(t_env *env);
void				init_object_general_env(t_env *env);
void				init_object_sector_env(t_env *env);
void				init_object_sprite_env(t_env *env);
void				init_object_general_buttons(t_env *env);
void				init_object_sector_buttons(t_env *env);
void				init_object_sprite_buttons(t_env *env);

int					editor(t_env *env);
void				wall_sprites_keys(t_env *env, t_v2 *pos, t_v2 *scale);
void				start_editor_menu(t_env *env);
void				draw_grid(t_env *env);
void				init_editor_data(t_env *env);
int					editor_keys(t_env *env);
int					editor_3d_keys(t_env *env);
int					editor_mouse(t_env *env);
int					editor_keyup(t_env *env);
int					editor_3d_keyup(t_env *env);
int					editor_mouseup(t_env *env);
void				hline(t_env *env, int y);
void				vline(t_env *env, int x);
void				draw_hgrid(t_env *env);
void				draw_vgrid(t_env *env);
int					add_vertex(t_env *env);
int					add_enemy(t_env *env);
int					add_vertex_to_current_sector(t_env *env, int num);
void				draw_circle(t_circle circle, t_env *env);
void				draw_circle_free(t_circle circle, t_env *env);
t_circle			new_circle(Uint32 line_color, Uint32 color, t_point center, int radius);
void				draw_grid_vertices(t_env *env);
void				print_vertex(t_env *env, int num);
void				print_vertices(t_env *env);
void				print_sectors(t_env *env);
void				draw_grid_current_sector(t_env *env);
void				draw_grid_sectors(t_env *env);
int					get_existing_vertex(t_env *env);
int					get_existing_not_dragged_vertex(t_env *env);
void				add_player(t_env *env);
void				draw_grid_player(t_env *env);
void				draw_grid_objects(t_env *env);
void				editor_hud(t_env *env);
int					get_clockwise_order(t_env *env);
void				revert_sector_order(t_env *env);
int					add_sector(t_env *env);
int					add_object(t_env *env);
int					fill_new_sector(t_sector *sector, t_env *env);
int					editor_render(t_env *env);
int					save_map(t_env *env);
void				revert_sector(t_sector *sector, t_env *env);
int					get_clockwise_order_sector(t_env *env, int index);
void				player_selection(t_env *env);
void				objects_selection(t_env *env);
void				vertices_selection(t_env *env);
void				create_portals(t_env *env, t_sector new_sector);
int					check_vertex_inside_sector(t_env *env, t_v2 vertex);
int					is_new_vertex_valid(t_env *env, int index);
void				del_last_vertex(t_env *env);
int					delete_vertex(t_env *env, int vertex);
int					delete_sector(t_env *env, int sector);
int					delete_object(t_env *env, int object);
int					current_vertices_contains(t_env *env, int vertex);
int					is_vertex_used(t_env *env, int vertex);
int					is_vertex_used_by_others(t_env *env, int vertex, int sector);
int					delete_invalid_sectors(t_env *env);
int					delete_invalid_vertices(t_env *env);
int					*get_vertex_sectors(t_env *env, int index);
int					is_new_dragged_vertex_valid(t_env *env, int index);
void				clear_portals(t_env *env);
int					delete_action(t_env *env);
int					editor_button_up(t_env *env);
int					delete_enemy(t_env *env, int enemy);
t_sector			rotate_vertices(t_env *env, int i, int index);
void				update_enemies_z(t_env *env);
void				update_objects_z(t_env *env);
void				selected_information_on_enemy(t_env *env);
int					selected_information_in_sector(t_env *env);
void				get_new_floor_and_ceiling(t_env *env);
void				reset_selection(t_env *env);
void				draw_input_box(t_input_box *box, t_env *env);
void				input_box_keys(t_input_box *box, t_env *env);
int					init_input_box(t_input_box *box, t_env *env);
int					input_box_mouse(t_input_box *box, t_env *env);
int					new_input_box(t_input_box *box, t_point pos,
						int type, void *target);
int					new_input_var(t_input_box *box, t_point pos,
						int type, void *target);
int					set_double_stats(t_input_box *box);
int					validate_input(t_input_box *box, t_env *env);
int					del_char(t_input_box *box, int mode);
int					delete_box_selection(t_input_box *box);
char				ft_getchar(int input, int shift);
int					add_char(t_input_box *box, char c);
int					apply_texture(int texture, t_sector *sector, t_env *env);
int					add_vertex_in_sector(t_env *env);
void				split_sector(t_env *env);
int					check_pos_vertices(t_env *env);
void				update_neighbors(t_env *env, int index, int num, t_sector *sector);
void				update_vertices(int index, t_sector *sector);
void				update_textures(int index, t_sector *sector);
void				update_double_tab(int index, double size, double **tab);
void				update_int_tab(int index, int size, int **tab);
void				selection_tab(t_env *env, int nb_slots);
void				enemy_tab(t_env *env, int nb_slots);
int					is_mouse_on_a_wall(t_env *env);
void				editor_mode_button(t_env *env);
void				editor_save_button(t_env *env);
void				editor_launch_game(t_env *env);
void				going_in_2D_mode(t_env *env);
void				going_in_3D_mode(t_env *env);
void				print_vertex_informations(t_env *env);
void				print_object_informations(t_env *env);
void				print_sector_informations(t_env *env);
void				print_enemy_informations(t_env *env);
void				print_floor_general_tab(t_env *env);
void				print_ceiling_general_tab(t_env *env);
void				print_player_general_tab(t_env *env);
void				print_wall_general_tab(t_env *env);
void				print_sector_general_tab(t_env *env);
void				print_enemy_general_tab(t_env *env);
void				print_object_general_tab(t_env *env);
void				print_floor_sector_tab(t_env *env);
void				print_ceiling_sector_tab(t_env *env);
void				print_player_sector_tab(t_env *env);
void				print_wall_sector_tab(t_env *env);
void				print_enemy_sector_tab(t_env *env);
void				print_object_sector_tab(t_env *env);
void				print_floor_sprite_tab(t_env *env);
void				print_ceiling_sprite_tab(t_env *env);
void				print_wall_sprite_tab(t_env *env);
void				nothing(void *target);
void				save_texture(void *target);
void				save_enemy(void *target);
void				add_enemy_button(void *target);
void				add_object_button(void *target);
void				general_tab(void *target);
void				sector_tab(void *target);
void				sprite_tab(void *target);
void				change_sprite(void *target);
void				change_var(void *target);
void				wall_buttons(t_env *env);
void				ceiling_buttons(t_env *env);
void				floor_buttons(t_env *env);
void				sector_buttons(t_env *env);
void				player_buttons(t_env *env);
void				enemy_buttons(t_env *env);
void				floor_sprite_buttons(t_env *env);
void				ceiling_sprite_buttons(t_env *env);
void				wall_sprite_buttons(t_env *env);
void				wall_buttons_up(t_env *env);
void				ceiling_buttons_up(t_env *env);
void				floor_buttons_up(t_env *env);
void				sector_buttons_up(t_env *env);
void				player_buttons_up(t_env *env);
void				enemy_buttons_up(t_env *env);
void				floor_sprite_buttons_up(t_env *env);
void				ceiling_sprite_buttons_up(t_env *env);
void				wall_sprite_buttons_up(t_env *env);

/*
** Main functions
*/

int					init_game(int ac, char **av);
int					doom(t_env *env);
int					crash(char *str, t_env *env);
void				reset_render_utils(t_camera *camera, t_env *env);

/*
** Init functions
*/

int					init_screen_size(t_env *env);
void				set_screen_size(t_env *env);
void    			init_weapons(t_env *env);
int     			init_sound(t_env *env);
void				init_animations(t_env *env);
void				init_pointers(t_env *env);
int					init_sdl(t_env *env);
int					set_sdl(t_env *env);
int					init_ttf(t_env *env);
int					init_textures(t_env *env);
int					init_ui_textures(t_env *env);
int					init_skybox(t_env *env);
int					init_wallpapers_and_buttons(t_env *env);
int					init_enemy_sprites(t_env *env);
int					init_object_sprites(t_env *env);
int					init_wall_sprites(t_env *env);
int					init_screen_pos(t_env *env);
void				init_options(t_env *env);
void				init_keys(t_env *env);
void				init_inputs(t_env *env);
int					init_camera(t_camera *camera, t_env *env);
int					init_camera_arrays(t_camera *camera, t_env *env);
void				init_player(t_env *env);
void				init_enemies_data(t_env *env);
void				init_objects_data(t_env *env);
void				init_objects_main_sprite(t_env *env);
void				init_sector_list(t_env *env, int curr);
void				set_camera(t_camera *camera, t_env *env);
int					valid_map(t_env *env);
int					generate_mipmaps(t_env *env);
int					set_camera_map_array(t_camera *camera, int i,
int j, t_env *env);
int					set_camera_sprites_array(t_camera *camera, int i,
int j, t_env *env);
int					set_sector_wall_map_array(t_sector *sector,
t_texture texture, int i, t_env *env);
int					set_sector_floor_map_array(t_sector *sector,
t_texture texture,t_env *env);
int					set_sector_ceiling_map_array(t_sector *sector,
t_texture texture, t_env *env);
t_projectile_data	new_projectile_data(t_v3 pos, double angle, double scale, int sprite);
t_projectile_stats	new_projectile_stats(double size_2d, int damage, double speed, double height);
t_explosion_data	new_explosion_data(t_v3 pos, double radius, int damage, int sprite);
void				init_events_map(t_env *env);

/*
**	Parser functions
*/

int					parse_bmp(char *file, int index, t_env *env);
int					parse_bmp_wall_textures(char *file, int index, t_env *env);
int					parse_bmp_ui_textures(char *file, int index, t_env *env);
int					parse_bmp_mini_enemies_textures(char *file, int index, t_env *env);
int					parse_bmp_skybox_textures(char *file, int index, int num_sky, t_env *env);
int					parse_map(char *file, t_env *env);
char				*skip_number(char *line);
char				*skip_hexa(char *line);
char				*skip_spaces(char *line);

/*
** Screen utils
*/

void				clear_image(t_env *env);
void				update_screen(t_env *env);
void				update_screen_zbuffer(t_env *env);
t_printable_text	new_printable_text(
				char *text,
						TTF_Font *font,
								unsigned int color,
										int size);
int					print_text(t_point pos,
				t_printable_text text, t_env *env);
void				apply_surface(SDL_Surface *surface,
				t_point pos, t_point size, t_env *env);
void				print_press_text(t_env *env);
void				fps(t_env *e);
void				print_debug(t_env *env);
void				fill_triangle_minimap(t_v3 v[3], t_env *env);
void				fill_triangle(t_v3 v[3], Uint32 color, t_env *env);
unsigned int		blend_alpha(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int		blend_add(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int		blend_mul(unsigned int src, unsigned int dest);
void				draw_line_3(t_env *env, t_line line);
void				draw_line(t_point c1, t_point c2, t_env env, Uint32 color);
void				draw_line_free(t_point c1, t_point c2, t_env env, Uint32 color);
void				draw_line_minimap(t_point c1, t_point c2, t_env env, Uint32 color);
Uint32				apply_light(Uint32 src, Uint32 color, int intensity,
int brightness);
Uint32				apply_light_both(Uint32 src, Uint32 color, int intensity,
int brightness);
Uint32				apply_light_color(Uint32 src, Uint32 color, int intensity);
Uint32				apply_light_brightness(Uint32 src, int brightness);
int				update_confirmation_box(t_confirmation_box *box, char *str,
int type, t_env *env);
int				draw_confirmation_box(t_confirmation_box box, t_env *env);
t_rectangle			new_rectangle(Uint32 inside_color, Uint32 line_color,
		int filled, int line_size);
void				draw_rectangle(t_env *env, t_rectangle r, t_point pos,
		t_point size);
t_button			new_button(t_rectangle up, t_rectangle pressed,
t_rectangle down, t_rectangle hover);
t_button			new_button_img(t_texture *up, t_texture *pressed,
t_texture *down, t_texture *hover);
t_button			new_image_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_hud_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_hud_pos_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_background_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_tab_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_rectangle_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_next_button(int type, void (*action)(void *),
void *param, t_env *env);
t_button			new_previous_button(int type, void (*action)(void *),
void *param, t_env *env);
void				draw_button(t_env *env, t_button b);

/*
 * ** Main pipeline functions
 * */

int					draw_walls(t_camera *camera, t_env *env);
void				draw_explosions(t_camera camera, t_env *env);
int					draw_projectiles(t_camera camera, t_env *env);
int					draw_projectile_both(t_camera camera, t_projectile *p,
t_env *env);
int					draw_projectile_no_light(t_camera camera, t_projectile *p,
t_env *env);
int					draw_projectile_brightness(t_camera camera, t_projectile *p,
t_env *env);
int					draw_projectile_color(t_camera camera, t_projectile *p,
t_env *env);
int					get_sprite_direction_projectile(t_projectile projectile);
int					draw_objects(t_camera camera, t_env *env);
int					draw_enemies(t_camera camera, t_env *env);
int					draw_players(t_camera camera, t_env *env);
int					draw_game(t_env *env);
void				check_parsing(t_env *env);
int					keyup(t_env *env);
void				confirmation_box_keys(t_confirmation_box *box, t_env *env);
void				confirmation_box_keyup(t_confirmation_box *box, t_env *env);
void				minimap(t_env *e);
void				view(t_env *env);
void				reset_clipped(t_env *env);
t_v3				sprite_movement(t_env *env, double speed, t_v3 origin, t_v3 destination);

void				draw_weapon(t_env *env, int sprite);
void				weapon_animation(t_env *env, int sprite);
void				weapon_change(t_env *env);
int					is_next_weapon_possessed(t_env *env);
void				print_ammo(t_env *env);
void    			shot(t_env *env);
int					create_projectile(t_env *env, t_projectile_data data,t_projectile_stats stats, double angle_z);
int					create_explosion(t_env *env, t_explosion_data data, int centered_sprite);
int					explosion_collision_player(t_env *env);
int					explosion_collision_objects(t_env *env);
int					explosion_collision_enemies(t_env *env);
int					projectiles_movement(t_env *env);
int					hitscan(t_env *env, int i);
int					aoe_damage(double distance, double radius, int damage);
int					doIntersect(t_v2 p1, t_v2 q1, t_v2 p2, t_v2 q2);
int					intersection_check(t_v2 w1, t_v2 w2, t_v2 p1, t_v2 p2);

void				draw_hud(t_env *env);
void				precompute_slopes(t_env *env);
double				get_floor_at_pos(t_sector sector, t_v3 pos, t_env *env);
double				get_ceiling_at_pos(t_sector sector, t_v3 pos, t_env *env);
t_v2				get_sector_normal(t_sector sector, t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);
void				update_inputs(t_env *env);
void				move_player(t_env *env);
void				update_player_pos(t_env *env);
void				update_camera_position(t_camera *camera);
int					get_sector(t_env *env, t_v3 p, int origin);
int					get_sector_global(t_env *env, t_v3 p);
int					get_sector_no_z(t_env *env, t_v3 p);
int					get_sector_no_z_origin(t_env *env, t_v3 p, int origin);
void				set_sector_xmax(t_env *env, t_sector *sector);
void				set_sectors_xmax(t_env *env);
int					keys(t_env *env);
void				update_player_z(t_env *env);
void				update_enemy_z(t_env *env, int i);
void				update_floor(t_env *env);
void				update_sector_slope(t_env *env, t_sector *sector);
void				game_time(t_env *env);
void				gravity(t_env *env);
void				animations(t_env *env);
void				fall(t_env *env);
void				drop(t_env *env);
void				jump(t_env *env);
void				crouch(t_env *env);
int					open_options(t_env *env);
void				add_image(t_env *env, int i, int x, int y);
void				start_game_menu(t_env *env);
void				add_button(t_env *env, int text, int x, int y, int ref_but);
int					button_leftclick(t_env *env, int nb);
void				select_menu(t_env *env);
int					is_in_sector(t_env *env, int sector, t_v3 pos);
int					is_in_sector_no_z(t_env *env, int sector, t_v2 pos);
double     			distance_two_points_2d(double x1, double y1, double x2, double y2);
double				distance_two_points_3d(t_v3 p1, t_v3 p2);
void				interactions(t_env *env);
void				activate_elevator(t_env *env);
void				create_elevator(t_env *env);
int					create_levels(t_env *env, int nb_floors);
int					get_nb_floors(t_env *env, t_sector *sector);
void				climb(t_env *env);
double				apply_climb(double vel);
double				apply_drop(double vel);
int					project_wall(int i, t_camera *camera, t_sector *sector, t_env *env);
void				update_sprites_state(t_env *env);
void				death(t_env *env);
void				respawn(void *param);
void				print_results(t_env *env);
void				activate_teleport(t_env *env);
void				create_teleport(t_env *env);
int					check_player_z(t_env *env);
void				hidden_sectors(t_env *env);
void				create_hidden_sector(t_env *env);
void				activate_sector(t_env *env, int i);
void				button_keys(t_button *b, t_env *env);
void				button_keyup(t_button *b, t_env *env);
void				draw_button_text(t_button b, t_env *env);
int					is_mouse_on_button(t_button b, t_point mouse);
t_point				get_button_current_size(t_button b);
int					editor_start_game(t_env *env);
int					init_raygun(t_env *env);
int					init_shotgun(t_env *env);
int					add_ceiling_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int					add_floor_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int					add_wall_bullet_hole(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
int					shift_ceiling_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int					shift_floor_bullet_hole(t_sector *sector,
t_projectile *projectile, t_env *env);
int					shift_wall_bullet_hole(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
t_v2				get_ceiling_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, t_env *env);
t_v2				get_floor_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, t_env *env);
t_v2				get_wall_bullet_hole_pos(t_sector *sector,
t_projectile *projectile, int i, t_env *env);
int					delete_wall_bullet_hole(void *param, void *env);
int					delete_floor_bullet_hole(void *param, void *env);
int					delete_ceiling_bullet_hole(void *param, void *env);
int					modify_wall_sprite(void *param, void *env);
int					modify_floor_sprite(void *param, void *env);
int					modify_ceiling_sprite(void *param, void *env);
void				shift_ceiling_bullet_hole_events(int sector, int sprite,
t_env *env);
void				shift_floor_bullet_hole_events(int sector, int sprite,
t_env *env);
void				shift_wall_bullet_hole_events(int sector, int wall, 
int sprite, t_env *env);

/*
** enemies functions
*/

void	draw_grid_enemies(t_env *env);
void	enemy_selection(t_env *env);
void	enemy_ai(t_env *env);
void	damage_anim(t_env *env);
int		enemy_hurt(t_env *env, int i);
void    resting_enemy(t_env *env, int i);
void	pursuing_enemy(t_env *env, int i);
int		dying_enemy(t_env *env, int i, int nb_sprites);
int     rand_dir(t_env *env, int index);
void	enemy_firing_anim(t_env *env, int i);
int		draw_enemy(t_camera camera, t_enemies *enemy, t_env *env, int death_sprite);

/*
** objects functions
*/

void	object_anim_loop(t_env *env, int i);
int		object_destruction(t_env *env, int i, int nb_sprites);
int	 	explosion_animation(t_env *env, t_explosion *explosion, int nb_sprites);

/*
**	Event functions
*/
int					update_event(t_event *event);
int					pop_events(t_env *env);
t_event				new_fixed_event(int type, void *target, double goal,
double speed);
t_event				new_func_event(int (*func)(void *, void *),
void *param);
t_event				new_incr_event(int type, void *target, double incr,
double speed);
int					start_event(t_event **events, size_t *size,
t_env *env);
int					start_event_free(t_event **events, size_t *size,
t_env *env);
int					check_launch_conditions(t_event *event, t_condition *tab,
size_t nb);
int					check_exec_conditions(t_event *event, t_condition *tab,
size_t nb);
t_event_param		new_event_param(int num, double equ_value, 
double diff_value);
t_event_param		empty_event_param(void);

int					update_sector_event(t_event *event, void *penv);
int					update_player_pos_event(t_event *event, void *penv);
int					update_player_z_event(t_event *event, void *penv);
int					update_wall_texture_event(t_event *event, void *penv);
int					update_floor_texture_event(t_event *event, void *penv);
int					update_ceiling_texture_event(t_event *event, void *penv);
int					update_sector_entities_event(t_event *event, void *penv);
int					update_object_sector_event(t_event *event, void *penv);
int					update_enemy_sector_event(t_event *event, void *penv);
int					update_vertex_event(t_event *event, void *penv);
int					delete_itself_event(t_event *event, void *penv);

/*
**	Event protection functions
*/

int					check_x_collision_event(t_event *event, void *penv);
int					check_y_collision_event(t_event *event, void *penv);
int					check_z_collision_event(t_event *event, void *penv);
int					check_sector_event(t_event *event, void *penv);
int					check_floor_slope_event(t_event *event, void *penv);
int					check_ceiling_slope_event(t_event *event, void *penv);
int					check_floor_event(t_event *event, void *penv);
int					check_ceiling_event(t_event *event, void *penv);
int					check_texture_event(t_event *event, void *penv);
int					check_sprite_event(t_event *event, void *penv);
int					check_scale_event(t_event *event, void *penv);
int					check_align_event(t_event *event, void *penv);
int					check_color_event(t_event *event, void *penv);
int					check_brightness_event(t_event *event, void *penv);
int					check_int_overflow_event(t_event *event, void *penv);
int					check_double_overflow_event(t_event *event, void *penv);
int					check_gravity_event(t_event *event, void *penv);
int					check_portal_event(t_event *event, void *penv);
int					check_true_false_event(t_event *event, void *penv);
int					check_vertex_x_event(t_event *event, void *penv);
int					check_vertex_y_event(t_event *event, void *penv);

/*
**	Free functions
*/

void				free_current_vertices(t_env *env);
void				free_camera(t_camera *camera, t_env *env);
void				free_all(t_env *env);
void				free_all_sdl_relative(t_env *env);
void				free_screen_sectors(t_env *env);
void				free_sector(t_sector *sector);
void				free_event(t_event *event);
void				free_events(t_event *event, size_t size);

#endif
