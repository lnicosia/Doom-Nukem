/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:51:13 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/28 14:43:15 by gaerhard         ###   ########.fr       */
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
	t_sdl			sdl;
	t_player		player;
	t_options		options;
	t_keys			keys;
	t_inputs		inputs;
	t_camera		camera;
	t_time			time;
	t_animation		jump;
	t_animation		crouch;
	t_gravity		gravity;
	t_animation		player_hurt;
	t_animation		shot;
	t_animation		weapon_change;
	t_vertex		*vertices;
	t_sector		*sectors;
	t_object		*objects;
	t_sprite		*sprites;
	t_audio			sound;
	t_texture		textures[MAX_TEXTURE];
	t_v2			*screen_pos;
	t_weapons		weapons[NB_WEAPONS];
	t_menu			button[NB_BUTTON];
	t_editor 		editor;
	int				drawing;
	double			horizon;
	int				option;
	int				menu_start;
	int				menu_select;
	int				menu_edit;
	int				aplicate_changes;
	char			*fps;
	double			*depth_array;
	int				*xmin;
	int				*xmax;
	int				*screen_sectors;
	int				*sector_list;
	int				screen_sectors_size;
	short			*rendered_sectors;
	int				screen_w[3];
	int				screen_h[3];
	char			*res[3];
	int				w;
	int				h;
	int				h_w;
	int				h_h;
	int				i;
	int				running;
	int				nb_sectors;
	int				nb_vertices;
	int				nb_objects;
	double			flag;
	int				reset;
	int				count;
	int				*ymax;
	int				*ymin;
	int				current_object;
	int				objects_start;
	int				objects_end;
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
void				start_editor_menu(t_env *env);
void				draw_grid(t_env *env);
void				init_editor_data(t_env *env);
int					editor_keys(t_env *env);
void				hline(t_env *env, int y);
void				vline(t_env *env, int x);
void				draw_hgrid(t_env *env);
void				draw_vgrid(t_env *env);
int					add_vertex(t_env *env);
int					add_ennemy(t_env *env);
int					add_vertex_to_current_sector(t_env *env, int num);
void				draw_circle(t_circle circle, t_env *env);
t_circle			new_circle(Uint32 line_color, Uint32 color, t_point center, int radius);
void				draw_grid_vertices(t_env *env);
void				print_vertex(t_env *env, int num);
void				print_vertices(t_env *env);
void				print_sectors(t_env *env);
void				draw_grid_current_sector(t_env *env);
void				draw_grid_sectors(t_env *env);
int					get_existing_vertex(t_env *env);
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
int					editor_render(t_env *env);
int					save_map(char *file, t_env *env);
void				revert_sector(t_sector *sector, t_env *env);
void				editor_options(t_env *env);
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

/*
 * ** Main functions
 * */

int					init_game(int ac, char **av);
int					doom(t_env *env);
void				free_all(t_env *env);
int					crash(char *str, t_env *env);

/*
 * ** Init functions
 * */

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
void				init_camera(t_env *env);
void				init_player(t_env *env);
void				set_camera(t_env *env);
int					valid_map(t_env *env);

/*
 * **	Parser functions
 * */

int					parse_bmp(char *file, int index, t_env *env);
int					parse_map(char *file, t_env *env);
char				*skip_number(char *line);
char				*skip_spaces(char *line);

/*
 * ** Screen utils
 * */

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
void				fill_triangle(t_v3 v[3], t_env *env);
unsigned int		blend_alpha(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int		blend_add(unsigned int src,
				unsigned int dest, uint8_t alpha);
unsigned int		blend_mul(unsigned int src, unsigned int dest);
void				draw_line_3(t_env *env, t_line line);
void				draw_line(t_point c1, t_point c2, t_env env, Uint32 color);
void				draw_line_minimap(t_point c1, t_point c2, t_env env, Uint32 color);
Uint32				apply_light(Uint32 color, double light);
void				free_all_sdl_relative(t_env *env);
void				free_screen_sectors(t_env *env);

/*
 * ** Main pipeline functions
 * */

int					draw_walls(t_env *env);
void				draw_sprites(t_env *env);
int					draw_game(t_env *env);
void				check_parsing(t_env *env);
void				options(t_env *env);
void				minimap(t_env *e);
void				view(t_env *env);
void				reset_clipped(t_env *env);

void				draw_weapon(t_env *env, int sprite);
void				weapon_animation(t_env *env, int sprite);
void				weapon_change(t_env *env);
void				print_ammo(t_env *env);
void    			hitscan_shot(t_env *env);

void				draw_hud(t_env *env);
void				precompute_slopes(t_env *env);
double				get_floor_at_pos(t_sector sector, t_v2 pos, t_env *env);
double				get_ceiling_at_pos(t_sector sector, t_v2 pos, t_env *env);
t_v2				get_sector_normal(t_sector sector, t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);
void				update_inputs(t_env *env);
void				move_player(t_env *env);
void				update_camera_position(t_env *env);
int					get_sector(t_env *env, t_v3 p, short origin);
int					get_sector_global(t_env *env, t_v3 p);
int					get_sector_no_z(t_env *env, t_v3 p);
void				set_sectors_xmax(t_env *env);
void				keys(t_env *env);
void				update_player_z(t_env *env);
void				update_floor(t_env *env);
void				update_sector_slope(t_env *env, t_sector *sector);
void				game_time(t_env *env);
void				gravity(t_env *env);
void				animations(t_env *env);
void				fall(t_env *env);
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

/*
** enemies functions
*/

void	enemy_pursuit(t_env *env);
void	damage_anim(t_env *env);
int		dying_enemy(t_env *env, int i);

#endif
