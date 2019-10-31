/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:54:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/31 14:48:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define SDL_MAIN_HANDLED
# include "SDL.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# define X1 env->vertices[env->sectors[motion.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[motion.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[motion.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[motion.sector].vertices[i + 1]].y
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y
# define MAX_TEXTURE 53
# define CONVERT_RADIANS 0.0174532925199432955
# define CONVERT_DEGREES 57.2957795130823228647
# define MAX_SPRITES 12
# define NB_WEAPONS 2
# define NB_BUTTON 10
# define AMMO_HUD 36
# define ARMOR_LIFE_HUD 35
# define THREADS 4
# define MAX_QUEUE 32
# define MAX_W 2560
# define MAX_H 1440

typedef enum		e_enemy_state
{
	RESTING,
	PURSUING,
	FIRING
}					t_enemy_state;

typedef enum		e_entity_sprite
{
	LOST_SOUL = 1,
	CYBER_DEMON
}					t_entity_sprite;

typedef enum		e_enemy_behavior
{
	MELEE,
	RANGED
}					t_enemy_behavior;

typedef enum		e_enemy_type
{
	TERRESTRIAL,
	AERIAL,
	AQUATIC
}					t_enemy_type;

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

typedef struct		s_circle
{
	Uint32			line_color;
	Uint32			color;
	t_point			center;
	int				radius;
}					t_circle;

typedef struct		s_elevator
{
	int				up;
	int				down;
	int				on;
	int				off;
	double				next_stop;
	int				sector;
	int				call;
	int				called_from;
	int				used;
}					t_elevator;

typedef struct		s_state
{
	int				fall;
	int				jump;
	int				run;
	int				crouch;
	int				climb;
	int				drop;
	int				walk;
}					t_state;

typedef struct		s_render_vertex
{
	t_v2			texture_scale;
	t_v2			*sprite_scale;
	double			vx;
	double			vz;
	double			clipped_vx1;
	double			clipped_vz1;
	double			clipped_vx2;
	double			clipped_vz2;
	double			clipped_vf1;
	double			clipped_vc1;
	double			clipped_vf2;
	double			clipped_vc2;
	double			clipped_x1;
	double			clipped_x2;
	double			f1;
	double			f2;
	double			c1;
	double			c2;
	double			x;
	double			y;
	double			neighbor_f1;
	double			neighbor_f2;
	double			neighbor_floor_range;
	double			neighbor_c1;
	double			neighbor_c2;
	double			neighbor_ceiling_range;
	double			scale1;
	double			scale2;
	double			angle_z1;
	double			angle_z2;
	double			no_slope_f1;
	double			no_slope_f2;
	double			no_slope_c1;
	double			no_slope_c2;
	int				draw;
	double			floor_horizon;
	double			ceiling_horizon;
	double			xrange;
	double			yrange;
	double			clipped_xrange;
	double			floor_range;
	double			ceiling_range;
	double			no_slope_floor_range;
	double			no_slope_ceiling_range;
	double			zrange;
	double			zcomb;
	double			x0z1;
	double			x1z0;
	double			xzrange;
	double			y0z1;
	double			y1z0;
	double			yzrange;
}					t_render_vertex;

typedef	struct		s_teleport
{
	int		create;
	t_v2		tmp_pos;
}			t_teleport;

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
	int				rest_sprite;
	int				curr_sprite;
	int				firing_sprite;
	int				pursuit_sprite;
	int				death_counterpart;
	int				nb_death_sprites;
}					t_sprite;

typedef struct		s_wall_sprites
{
	short			*sprite;
	t_v2			*pos;
	t_v2			*scale;
}					t_wall_sprites;

typedef struct		s_sector
{
	t_v2			normal;
	double			floor;
	double			floor_slope;
	short			floor_texture;
	t_v2			floor_scale;
	t_v2			floor_align;
	double			ceiling;
	double			ceiling_slope;
	short			ceiling_texture;
	t_v2			ceiling_scale;
	t_v2			ceiling_align;
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
	int				*xmin;
	int				*xmax;
	short			*vertices;
	short			*neighbors;
	short			*textures;
	t_wall_sprites	*sprites;
	double			sprite_time;
	t_v2			*align;
	t_v2			*scale;
	t_v2			tp;
	short			*selected;
	short			num;
	short			nb_vertices;
	short			*nb_sprites;
	int				skybox;
	int				statue;
	int				brightness;
	int				*levels;
	Uint32			light_color;
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

/*
**	Camera values
*/

typedef struct		s_camera
{
	t_v3			pos;
	t_v2			near_left_pos;
	t_v2			near_right_pos;
	t_v2			near_pos;
	t_render_vertex	**v;
	double			near_z;
	double			far_z;
	double			near_left;
	double			near_right;
	double			range;
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
	double			angle;
	double			angle_cos;
	double			angle_sin;
	double			perp_cos;
	double			perp_sin;
	double			angle_z;
	double			angle_z_cos;
	double			angle_z_sin;
	double			horizon;
	double			*feet_y;
	double			*head_y;
	int				*screen_sectors;
	int				*screen_pos;
	short			*rendered_sectors;
	int				*xmin;
	int				*xmax;
	int				computed;
	int				*sector_computed;
	int				size;
}					t_camera;

typedef struct		s_vline_data
{
	double			alpha;
	double			clipped_alpha;
	double			divider;
	double			z;
	double			current_ceiling;
	double			current_floor;
	double			max_ceiling;
	double			max_floor;
	double			z_near_z;
	double			no_slope_current_floor;
	double			no_slope_current_ceiling;
	double			inv_line_height;
	double			ceiling_start;
	double			floor_start;
	double			wall_texel;
	double			zrange;
	double			falpha_divider;
	double			calpha_divider;
	t_v2			texel;
	t_v2			texel_near_z;
	t_v2			camera_z;
	t_v2			texel_camera_range;
}					t_vline_data;

typedef	struct		s_init_data
{
	t_v3			pos;
	t_camera		camera;
	int				sector;
	double			angle;
	int				health;	
	int				main_sprite;
}					t_init_data;

typedef struct		s_player
{
	t_v3			pos;
	t_v2			old_pos;
	t_camera		camera;
	t_init_data		player_init_data;
	int				stuck;
	int				prev_sector;
	double			gravity;
	double			eyesight;
	double			speed;
	int				hit;
	double			size_2d;
	double			rotation_speed;
	short			sector;
	int				lowest_sect;
	int				highest_sect;
	int				curr_weapon;
	int				health;
	int				armor;
	int				killed;
	double			nb_shots;
	double			touched;
	int				accuracy;
	double			head_z;
	t_state			state;
	double			velocity;
	double			velocity_start;
	double			acceleration;
	double			start_pos;
	int				drop_flag;
}					t_player;

/*
** Player's keys configuration
*/

typedef struct		s_keys
{
	int				forward;
	int				backward;
	int				backspace;
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
	int				enter;
	int				s;
	int				del;
	int				tab;
	int				comma;
	int				period;
	int				minus1;
	int				equals;
	int				p;
}					t_keys;

/*
** Keys inputs
*/

typedef struct		s_inputs
{
	uint8_t			forward;
	uint8_t			backward;
	uint8_t			backspace;
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
	uint8_t			option;
	uint8_t			enter;
	uint8_t			s;
	uint8_t			del;
	uint8_t			tab;
	uint8_t			comma;
	uint8_t			period;
	uint8_t			minus1;
	uint8_t			equals;
	uint8_t			p;
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
	TTF_Font		*montserrat20;
	TTF_Font		*playfair_display20;
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
	double			tick;
	double			scroll_tick;
	double			tick2;
	double			tick3;
	double			tick4;
	double			start;
	double			end;
	double			minuts;
	double			tenth_s;
	double			milli_s;
	double			last_fall;
	double			last_jump;
	double			last_climb;
	double			last_crouch;
	double			last_drop;
	double			d_time;
}					t_time;

typedef struct		s_gravity
{
	double			velocity;
	double			acceleration;	
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
** Object structure
*/

typedef struct		s_object
{
	t_v3			pos;
	t_v3			translated_pos;
	t_v3			rotated_pos;
	t_init_data		object_init_data;
	int				left;
	int				right;
	int				top;
	int				bottom;
	int				sprite;
	double			scale;
	double			angle;
	short			brightness;
	Uint32			light_color;
	int				pickable;
	int				solid;
	int				ammo;
	int				health;
	int				sector;
	int				exists;
	int				num;
	t_animation		death;
}					t_object;

typedef struct		s_enemies
{
	t_v3			pos;
	t_v3			last_player_pos;
	t_v3			translated_pos;
	t_v3			rotated_pos;
	t_v2			far_left;
	t_v2			far_right;
	t_v2			left_arm;
	t_v2			right_arm;
	t_init_data		enemies_init_data;
	int				type;
	int				behavior;
	int				speed;
	int				shot;
	int				hit;
	int				left;
	int				right;
	int				top;
	int				bottom;
	int				sprite;
	int				main_sprite;
	int				death_sprite;
	int				firing_sprite;
	int				seen;
	int				saw_player;
	double			scale;
	double			angle;
	double			size_2d;
	double			eyesight;
	short			brightness;
	Uint32			light_color;
	int				health;
	int				damage;
	int				exists;
	int				sector;
	int				num;
	int				state;
	int				dir;
	t_animation		rand_dir;
	t_animation		death;
	t_animation		hurt;
	t_animation		rest;
	t_animation		pursue;
	t_animation		fire;
}					t_enemies;

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
	int				zbuffer;
	int				p;
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

/*
**	Data for rectangle
*/

typedef struct		s_rectangle
{
	Uint32			line_color;
	Uint32			inside_color;
	int				filled;
	int				line_size;
}					t_rectangle;

/*
**	Data for button
*/

typedef struct		s_button
{
	t_rectangle		up;
	t_rectangle		pressed;
	t_rectangle		down;
	t_point			pos;
	t_point			size;
	int				state;
}					t_button;

/*
**	Data for confirmation box
*/

typedef struct		s_confirmation_box
{
	t_button		yes;
	t_button		no;
	TTF_Font		*font;
	t_point			size;
	int				state;
	char			*str;
	int				yes_pressed;
	int				no_pressed;
}					t_confirmation_box;

#endif
