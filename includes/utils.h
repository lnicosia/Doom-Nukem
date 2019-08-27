/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/27 17:13:37 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# define X1 env->vertices[env->sectors[env->player.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[env->player.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].y
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y
# define MAX_TEXTURE 38
# define CONVERT_RADIANS 0.0174532925199432955
# define CONVERT_DEGREES 57.2957795130823228647
# define MAX_SPRITES 2
# define NB_WEAPONS 2
# define NB_BUTTON 10
# define AMMO_HUD 36
# define ARMOR_LIFE_HUD 35
# define THREADS 4

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

typedef	struct		s_segment
{
	t_v2			p1;
	t_v2			p2;
}					t_segment;

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
	t_v3			boundaries[4];
	double			floor;
	double			floor_slope;
	double			ceiling;
	double			ceiling_slope;
	double			x_max;
	double			floor_min;
	double			ceiling_min;
	double			floor_max;
	double			ceiling_max;
	double			light;
	double			*wall_width;
	double			*floors;
	double			*ceilings;
	double			*clipped_floors1;
	double			*clipped_ceilings1;
	double			*clipped_floors2;
	double			*clipped_ceilings2;
	short			*vertices;
	short			*neighbors;
	short			*textures;
	short			ceiling_texture;
	short			floor_texture;
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
	int				fall;
	int				prev_sector;
	double			gravity;
	double			eyesight;
	double			angle;
	double			angle_cos;
	double			angle_sin;
	double			perp_cos;
	double			perp_sin;
	double			angle_z;
	double			angle_z_cos;
	double			angle_z_sin;
	double			speed;
	int				hit;
	double			size_2d;
	double			camera_x;
	double			camera_y;
	double			rotation_speed;
	short			sector;
	short			camera_sector;
	short			near_left_sector;
	short			near_right_sector;
	double			state;
	int				curr_weapon;
	int				life;
	int				armor;
	double			head_z;
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
	int				option;
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
	uint8_t			left_click;
	uint8_t			right_click;
	uint8_t			leftclick;
	uint8_t			option;
}					t_inputs;

/*
** Fonts
*/

typedef struct		s_fonts
{
	TTF_Font		*amazdoom70;
	TTF_Font		*amazdoom50;
	TTF_Font		*amazdoom20;
	TTF_Font		*alice30;
	TTF_Font		*alice70;
	TTF_Font		*bebasneue;
}					t_fonts;

/*
** Sound structure
*/

typedef struct		s_audio
{
	int				g_music;
	int				b_jump;
	int				b_footstep;
	int				b_music;
	int				b_weapon;
	Mix_Music		*background;
	Mix_Chunk		*footstep;
	Mix_Chunk		*jump;
}					t_audio;

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

typedef struct		s_gravity
{
	double			start;
	double			end;
	double			floor;
	double			weight;
	double			on_going;
}					t_gravity;

typedef struct		s_animation
{
	double			start;
	double			end;
	double			on_going;
	double			height;
	double			tick;
	double			nb_frame;
}					t_animation;

/*
** Weapon structure
*/

typedef struct		s_weapons
{
	int				possessed;
	int				first_sprite;
	int				nb_sprites;
	int				weapon_switch;
	int				ammo;
	double			range;
	int				no_ammo;
	int				max_ammo;
	int				damage;
	int				splash;
	Mix_Chunk		*sound;
	Mix_Chunk		*empty;
}					t_weapons;

/*
** Sprite structure with associated texture
** and 1 to 8 image cut on this texture
*/

typedef struct		s_sprite
{
	int				oriented;
	int				texture;
	t_point			start[8];
	t_point			end[8];
	t_point			size[8];
	int				reversed[8];
	double			width;
	double			height;
}					t_sprite;

/*
** Object structure
*/

typedef struct		s_object
{
	t_v3			pos;
	t_v3			translated_pos;
	t_v3			rotated_pos;
	int				left;
	int				right;
	int				top;
	int				bottom;
	int				seen;
	int				sprite;
	t_animation		death;
	double			scale;
	double			angle;
	double			light;
	int				pickable;
	int				solid;
	int				ammo;
	int				health;
	int				sector;
	int				exists;
}					t_object;

/*
** SDL data necessities
*/

typedef struct		s_sdl
{
	SDL_Event		event;
	t_fonts			fonts;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	unsigned int	*img_str;
	Uint32			*texture_pixels;
	int				mouse_x;
	int				mouse_y;
	int				mx;
	int				my;
	int				time;
	int				pitch;
}					t_sdl;

/*
**	Definition of a texture
*/

typedef struct		s_texture
{
	SDL_Surface		*surface;
	Uint32			*str;
	double			scale;
	int				xpadding;
	int				ypadding;
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
	int				show_ennemies;
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
 **	Data to manipulate menus
 */

typedef struct		s_menu
{
	int				x;
	int				y;
	int				image;
	int				index;
	int				id;
}					t_menu;

#endif
