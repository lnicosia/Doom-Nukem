/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/06 18:09:34 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <fcntl.h>
# include "libft.h"
# define X1 env->vertices[env->sectors[env->player.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[env->player.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].y
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_v2
{
	double			x;
	double			y;
}					t_v2;

typedef struct		s_v3
{
	double			x;
	double			y;
	double			z;
}					t_v3;

typedef struct		s_line_eq
{
	double a;
	double b;
}					t_line_eq;

typedef struct		s_line
{
	t_point			p0;
	t_point			p1;
	Uint32			color;
}					t_line;

/*
** VERTICES = PLURIEL DE VERTEX
*/

typedef struct		s_sector
{
	t_v2			normal;
	double			floor;
	double			floor_slope;
	double			ceiling;
	double			ceiling_slope;
	double			x_max;
	double			floor_min;
	double			ceiling_min;
	double			floor_max;
	double			ceiling_max;
	double			*wall_width;
	double			*floors;
	double			*ceilings;
	double			*clipped_floors1;
	double			*clipped_ceilings1;
	double			*clipped_floors2;
	double			*clipped_ceilings2;
	short			*vertices;
	short			*neighbors;
	short			num;
	short			nb_vertices;
}					t_sector;

typedef struct		s_vertex
{
	double			clipped_x[2];
	double			clipped_y[2];
	double			x;
	double			y;
	int				clipped[2];
	short			num;
}					t_vertex;

typedef struct		s_player
{
	t_v3			pos;
	t_v2			near_left;
	t_v2			near_right;
	double			gravity;
	double			eyesight;
	double			z;
	double			angle;
	double			angle_cos;
	double			angle_sin;
	double			perp_cos;
	double			perp_sin;
	double			angle_z;
	double			angle_z_cos;
	double			angle_z_sin;
	double			speed;
	double			size_2d;
	double			camera_x;
	double			camera_y;
	double			rotation_speed;
	short			sector;
	short			camera_sector;
	short			near_left_sector;
	short			near_right_sector;
	int				state;
}					t_player;

/*
 **	Camera values
 */

typedef struct		s_camera
{
	double			near_z;
	double			far_z;
	double			near_left;
	double			near_right;
	double			near_up;
	double			near_down;
	double			far_left;
	double			far_right;
	double			ratio_w;
	double			ratio_h;
	double			ratio;
	double			hfov;
	double			vfov;
	double			scale;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			hscale;
	double			vscale;
}					t_camera;

/*
 ** Player's keys configuration
 */

typedef struct		s_keys
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				forward2;
	int				backward2;
	int				left2;
	int				right2;
	int				plus;
	int				minus;
	int				shift;
	int				ctrl;
	int				space;
	int				down;
	int				up;
}					t_keys;

/*
 ** Keys inputs
 */

typedef struct		s_inputs
{
	uint8_t			forward;
	uint8_t			backward;
	uint8_t			left;
	uint8_t			right;
	uint8_t			plus;
	uint8_t			minus;
	uint8_t			shift;
	uint8_t			ctrl;
	uint8_t			space;
	uint8_t			up;
	uint8_t			down;
}					t_inputs;

/*
 ** Fonts
 */

typedef struct		s_fonts
{
	TTF_Font		*amazdoom50;
	TTF_Font		*amazdoom20;
	TTF_Font		*alice;
	TTF_Font		*bebasneue;
}					t_fonts;

/*
** Sound structure
*/

typedef struct		s_audio
{
	Mix_Music		*background;
	Mix_Chunk		*footstep;
	Mix_Chunk		*jump;
}					t_audio;

/*
 ** SDL data necessities
 */

typedef struct		s_sdl
{
	SDL_Event		event;
	t_fonts			fonts;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	unsigned int	*img_str;
	Uint32			*texture_pixels;
	SDL_Surface		*image;
	unsigned int	*image_str;
	int				mouse_x;
	int				mouse_y;
	int				time;
	int				pitch;
}					t_sdl;

/*
**	Definition of a texture
*/

typedef struct		s_texture
{
	SDL_Surface		*surface;
	unsigned int	w;
	unsigned int	h;
}					t_texture;

/*
 **	Contains a list of options for the game
 */

typedef struct		s_options
{
	double			minimap_scale;
	int				contouring;
	int				render_sectors;
	int				lighting;
	int				show_minimap;
	int				show_fps;
	int				wall_lover;
	int				color_clipping;
	int				wall_color;
	int				test;
	int				clipping;
}					t_options;

/*
 **	Contains every data need to print a text on the screen
 */

typedef struct		s_printable_text
{
	char			*str;
	TTF_Font		*font;
	SDL_Color		color;
	int				size;
}					t_printable_text;

/*
 **	Contains every data needed for an animation on the screen
 */

typedef struct		s_time
{
	double			start;
	double			end;
	double			minuts;
	double			tenth_s;
	double			milli_s;
}					t_time;

typedef struct		s_animation
{
	double			start;
	double			end;
	double			floor;
	double			weight;
	double			on_going;
}					t_animation;

/*
 **	Environment data struct
 */

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
	t_animation		squat;
	t_animation		gravity;
	t_vertex		*vertices;
	t_sector		*sectors;
	t_texture		textures[1];
	t_audio			sound;
	double			*depth_array;
	int				*xmin;
	int				*xmax;
	int				*screen_sectors;
	short			*rendered_sectors;
	int				w;
	int				h;
	int				running;
	int				nb_sectors;
	int				nb_vertices;
	int				flag;
}					t_env;

/*
 **	  -------------
 **	 ---------------
 **	----FUNCTIONS----
 **	 ---------------
 **	  -------------
 */

/*
 ** Main functions
 */

int					doom(int ac, char **av);
void				free_all(t_env *env);
int					crash(char *str, t_env *env);

/*
 ** Init functions
 */

void				init_animations(t_env *env);
void				init_pointers(t_env *env);
int					init_sdl(t_env *env);
int					init_ttf(t_env *env);
void				init_options(t_env *env);
void				init_keys(t_env *env);
void				init_inputs(t_env *env);
void				init_camera(t_env *env);
void				set_camera(t_env *env);
int					parsing(int fd, t_env *env);
int					valid_map(t_env *env);

/*
 ** Screen utils
 */

void				clear_image(t_env *env);
void				update_screen(t_env *env);
t_printable_text	new_printable_text(
		char *text,
		TTF_Font *font,
		unsigned int color,
		int size);
void				print_text(t_point pos, t_printable_text text, t_env *env);
void				apply_surface(SDL_Surface *surface, t_point pos, t_point size, t_env *env);
void				fps(t_env *e);
void				print_debug(t_env *env);
void				fill_triangle(t_v3 v[3], t_env *env);
unsigned int		blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha);
unsigned int		blend_add(unsigned int src, unsigned int dest, uint8_t alpha);
unsigned int		blend_mul(unsigned int src, unsigned int dest);
void				draw_line_3(t_env *env, t_line line);
void				draw_line(t_point c1, t_point c2, t_env env, Uint32 color);
Uint32				apply_light(Uint32 color, uint8_t light);

/*
 ** Main pipeline functions
 */

int					draw(t_env *env);
void				check_parsing(t_env *env);
void				options(t_env *env);
void				minimap(t_env *e);
void				view(t_env *env);
void				reset_clipped(t_env *env);

t_point				new_point(int x, int y);
t_v2				new_v2(double x, double y);
t_v3				new_v3(double x, double y, double z);

void				precompute_slopes(t_env *env);
double				get_clipped_floor(int num, t_sector sector, t_vertex vertex, t_env *env);
double				get_clipped_ceiling(int num, t_sector sector, t_vertex vertex, t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);
void				update_inputs(t_env *env);
void				move_player(t_env *env);
void				update_camera_position(t_env *env);
int					get_sector(t_env *env, t_v2 p);
int					parse_bmp(char *file, t_env *env);
void				keys(t_env *env);
void				update_player_z(t_env *env);
void				update_floor(t_env *env);
void				update_sector_slope(t_env *env, short sector_nb);
void				time(t_env *env);
void				gravity(t_env *env);
void				animations(t_env *env);
void				fall(t_env *env);
void				jump(t_env *env);

#endif
