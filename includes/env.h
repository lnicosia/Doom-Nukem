/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:51:13 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/11 14:16:51 by lnicosia         ###   ########.fr       */
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
	t_sprite			*sprites;
	t_audio				sound;
	t_texture			textures[MAX_TEXTURE];
	t_weapons			weapons[NB_WEAPONS];
	t_menu				button[NB_BUTTON];
	t_editor 			editor;
	t_elevator			elevator;
	t_render_vertex		skybox[5];
	t_camera			fixed_camera;
	t_vline_data		*vline_data;
	t_teleport			teleport;
	t_hidden_sect		hidden_sect;
	t_confirmation_box	confirmation_box;
	t_input_box			input_box;
	Uint32				frame_timer;
	int					saving;
	int					playing;
	int					visible_sectors;
	int					skybox_computed;
	int					selected_wall1;
	int					selected_wall2;
	int					selected_floor;
	int					selected_wall_sprite_sprite;
	int					selected_wall_sprite_wall;
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
	char				*fps;
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
	int					nb_sectors;
	int					nb_vertices;
	int					nb_objects;
	int					nb_enemies;
	double				flag;
	int					reset;
	int					*ymax;
	int					*ymin;
	int					*xmax;
	int					*xmin;
	double				*max_ceiling;
	double				*max_floor;
	double				*current_ceiling;
	double				*current_floor;
	double				*alpha;
	double				*clipped_alpha;
	double				*z;
	double				*divider;
	double				*line_height;
	double				*no_slope_current_floor;
	double				*no_slope_current_ceiling;
	double				*ceiling_start;
	double				*floor_start;
	double				*z_near_z;
	double				*neighbor_max_ceiling;
	double				*neighbor_max_floor;
	double				*neighbor_current_ceiling;
	double				*neighbor_current_floor;
	t_v2				*texel;
	t_v2				*wall_texel;
	t_v2				*texel_near_z;
	t_v2				*camera_z;
	t_v2				*texel_camera_range;
	double				*zrange;
	int					current_object;
	int					current_enemy;
	int					objects_start;
	int					objects_end;
	int					test_time;
	double				avrg_fps;
	int				min_fps;
	int				max_fps;
	double				avrg_fps2;
	int				min_fps2;
	int				max_fps2;
	int				contains_skybox;
	double				render_swap_time;
	Uint32*				tmp_first_sprite;
	char				*save_file;
	t_list				*events;
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
int					editor(t_env *env);
void				editor_3d_keys(t_env *env);
void				wall_sprites_keys(t_env *env);
void				start_editor_menu(t_env *env);
void				draw_grid(t_env *env);
void				init_editor_data(t_env *env);
int					editor_keys(t_env *env);
int					editor_mouse(t_env *env);
int				editor_keyup(t_env *env);
int				editor_mouseup(t_env *env);
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
void				fill_new_sector(t_sector *sector, t_env *env);
void				free_current_vertices(t_env *env);
void				free_camera(t_camera *camera);
int					editor_render(t_env *env);
int					save_map(t_env *env);
void				revert_sector(t_sector *sector, t_env *env);
int					get_clockwise_order_sector(t_env *env, int index);
void				player_selection(t_env *env);
void				objects_selection(t_env *env);
void				vertices_selection(t_env *env);
void				create_portals(t_env *env, t_sector new_sector);
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
int					editor_buttonup(t_env *env);
int					delete_enemy(t_env *env, int enemy);
t_sector			rotate_vertices(t_env *env, int i, int index);
void				update_enemies_z(t_env *env);
void				update_objects_z(t_env *env);
void				selected_information_on_enemy(t_env *env);
void				selected_information_in_sector(t_env *env);
void				get_new_floor_and_ceiling(t_env *env);
void				reset_selection(t_env *env);
void				draw_input_box(t_input_box *box, t_env *env);
void				input_box_keys(t_input_box *box, t_env *env);
int				init_input_box(t_input_box *box, t_env *env);
int				input_box_mouse(t_input_box *box, t_env *env);
int				new_input_box(t_input_box *box, t_point pos,
int type, void *target);
int				set_double_stats(t_input_box *box);
int				validate_input(t_input_box *box, t_env *env);
int				del_char(t_input_box *box, int mode);
int				delete_box_selection(t_input_box *box);
char				ft_getchar(int input, int shift);
int				add_char(t_input_box *box, char c);
void				hit_player(void *param);

/*
** Main functions
*/

int					init_game(int ac, char **av);
int					doom(t_env *env);
void				free_all(t_env *env);
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
int					init_wallpapers_and_buttons(t_env *env);
int					init_sprites(t_env *env);
int					init_screen_pos(t_env *env);
void				init_options(t_env *env);
void				init_keys(t_env *env);
void				init_inputs(t_env *env);
int					init_camera(t_camera *camera, t_env *env);
int					init_camera_arrays(t_camera *camera, t_env *env);
void				init_player(t_env *env);
void				init_enemies_data(t_env *env);
void				init_sector_list(t_env *env, int curr);
void				set_camera(t_camera *camera, t_env *env);
int					valid_map(t_env *env);

/*
**	Parser functions
*/

int					parse_bmp(char *file, int index, t_env *env);
int					parse_map(char *file, t_env *env);
char				*skip_number(char *line);
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
void				print_text(t_point pos,
				t_printable_text text, t_env *env);
void				apply_surface(SDL_Surface *surface,
				t_point pos, t_point size, t_env *env);
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
Uint32				apply_light(Uint32 src, Uint32 color, short brightness);
void				free_all_sdl_relative(t_env *env);
void				free_screen_sectors(t_env *env);
int				update_confirmation_box(t_confirmation_box *box, char *str, t_env *env);
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
void *target, t_env *env);
t_button			new_rectangle_button(int type, void (*action)(void *),
void *target, t_env *env);
void				draw_button(t_env *env, t_button b);

/*
 * ** Main pipeline functions
 * */

void				update_event(t_event *event);
void				pop_events(t_env *env);
t_event				new_event(int type, void *target, double goal,
Uint32 duration);
void				start_event(t_event *events, size_t size,
t_env *env);
int					draw_walls(t_camera *camera, t_env *env);
void				draw_objects(t_camera camera, t_env *env);
void				draw_enemies(t_camera camera, t_env *env);
int					draw_players(t_camera camera, t_env *env);
int					draw_game(t_env *env);
void				check_parsing(t_env *env);
void				keyup(t_env *env);
void				confirmation_box_keys(t_confirmation_box *box, t_env *env);
void				confirmation_box_keyup(t_confirmation_box *box, t_env *env);
void				minimap(t_env *e);
void				view(t_env *env);
void				reset_clipped(t_env *env);

void				draw_weapon(t_env *env, int sprite);
void				weapon_animation(t_env *env, int sprite);
void				weapon_change(t_env *env);
void				print_ammo(t_env *env);
void    			shot(t_env *env);
int					hitscan(t_env *env, int i);

void				draw_hud(t_env *env);
void				precompute_slopes(t_env *env);
double				get_floor_at_pos(t_sector sector, t_v3 pos, t_env *env);
double				get_ceiling_at_pos(t_sector sector, t_v3 pos, t_env *env);
t_v2				get_sector_normal(t_sector sector, t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);
void				update_inputs(t_env *env);
void				move_player(t_env *env);
void				update_camera_position(t_camera *camera);
int					get_sector(t_env *env, t_v3 p, short origin);
int					get_sector_global(t_env *env, t_v3 p);
int					get_sector_no_z(t_env *env, t_v3 p);
int					get_sector_no_z_origin(t_env *env, t_v3 p, int origin);
void				set_sectors_xmax(t_env *env);
void				keys(t_env *env);
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
int					is_in_sector(t_env *env, short sector, t_v3 pos);
int					is_in_sector_no_z(t_env *env, short sector, t_v2 pos);
double     			distance_two_points(double x1, double y1, double x2, double y2);
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
int				is_mouse_on_button(t_button b, t_point mouse);
t_point				get_button_current_size(t_button b);

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

#endif
