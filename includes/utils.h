/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:54:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 18:51:59 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define SDL_MAIN_HANDLED
# include "SDL.h"
# include "SDL_ttf.h"
# include "fmod.h"
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# define X1 env->vertices[env->sectors[motion.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[motion.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[motion.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[motion.sector].vertices[i + 1]].y
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y
# define SNPRINTF_SIZE 1024
# define MAX_WALL_TEXTURE 15
# define MAX_TEXTURES 36
# define MAX_UI_TEXTURES 60
# define MAX_MONSTER_MINI 14
# define MAX_OBJECT_SPRITES 28
# define MAX_ENEMY_SPRITES 13
# define CONVERT_RADIANS 0.0174532925199432955
# define CONVERT_DEGREES 57.2957795130823228647
# define NB_WEAPONS 3
# define MAX_SKYBOX 3
# define MAX_ENEMIES 2
# define MAX_OBJECTS 18
# define NB_BUTTON 10
# define AMMO_HUD 26
# define ARMOR_LIFE_HUD 27
# define THREADS 4
# define MAX_W 2560
# define MAX_H 1440
# define LOST_SOUL 0
# define CYBER_DEMON 5
# define HEALTH_PACK 2
# define SHELL_AMMO 3
# define ROCKETS_AMMO 4
# define REGULAR_AMMO 5
# define ENERGY_AMMO 6
# define LAMP 7
# define MONITOR_OFF 11
# define MONITOR_ON 12
# define MONITOR_DESTROYED 16
# define GREEN_ARMOR 17
# define CANDLE 18
# define BARREL 20
# define GRID 23
# define BUTTON_OFF 24
# define BUTTON_ON 25
# define BULLET_HOLE 26
# define LOST_SOUL_OBJECT 27
# define CYBER_DEMON_OBJECT 28

typedef enum		e_target_type
{
	INT,
	DOUBLE,
	STRING,
	UINT32,
	POS
}			t_target_type;

typedef enum		e_change_sprite
{
	NEXT,
	PREVIOUS
}					t_change_sprite;

typedef enum		e_sprite_type
{
	WALL_S,
	FLOOR_S,
	CEILING_S
}					t_sprite_type;

typedef enum		e_button_action_type
{
	ON_PRESS,
	WHEN_DOWN,
	ON_RELEASE
}					t_button_action_type;

typedef enum		e_event_mod_type
{
	FIXED,
	INCR,
	FUNC
}					t_event_mod_type;

typedef enum		e_button_state
{
	UP,
	DOWN
}			t_button_state;

typedef enum		e_button_anim_state
{
	REST,
	PRESSED,
	HOVER
}			t_button_anim_state;

typedef enum		e_confirmation_box_type
{
		YESNO,
		INFO,
		ERROR,
		CONFIRM,
		WARNING
}					t_confirmation_box_type;

typedef enum		e_object_type
{
	HEAL,
	AMMO,
	ARMOR,
	DECORATION,
	WEAPON
}					t_object_type;

typedef enum		e_weapons_list
{
	SHOTGUN,
	RAYGUN,
	BAZOOKA,
	KNIFE
}					t_weapons_list;

typedef enum		e_ammo_types
{
	REGULAR,
	SHELL,
	ENERGY,
	ROCKET
}					t_ammo_types;

typedef enum		e_enemy_state
{
	RESTING,
	PURSUING,
	FIRING
}					t_enemy_state;

typedef enum		e_enemy_behavior
{
	MELEE_FIGHTER,
	MELEE_KAMIKAZE,
	RANGED_AIMBOT,
	RANGED_PROJECTILE
}					t_enemy_behavior;

typedef enum		e_enemy_type
{
	TERRESTRIAL,
	AERIAL,
	AQUATIC
}					t_enemy_type;

typedef enum		e_skybox_source
{
	CEILING,
	WALL,
	BOTTOM_WALL,
	UPPER_WALL,
	FLOOR
}					t_skybox_source;

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

typedef enum		s_ui_textures
{
	BACKGROUND
}					t_ui_textures;

typedef struct		s_state
{
	int				fall;
	int				jump;
	int				run;
	int				crouch;
	int				climb;
	int				drop;
	int				walk;
	int				fly;
}					t_state;

typedef struct		s_render_vertex
{
	t_v2			*texture_scale;
	t_v2			*sprite_scale;
	t_v2			*texture_align;
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

typedef struct		s_event_param
{
		int			num;
		int			num2;
		int			num3;
		int			sector;
		int			wall;
		int			sprite;
		int			size;
		int			enemy;
		int			object;
		int			vertex;
		int			weapon;
		double		equ_value;
		double		diff_value;
		void		*target;
		int			target_type;
}					t_event_param;

typedef struct		s_condition
{
	int				type;
	double			value;
	int				target_type;
	int				target_index;
	int				sector;
	int				wall;
	int				sprite;
	int				size;
	int				enemy;
	int				object;
	int				vertex;
	int				weapon;
	int				source_type;
	int				source_index;
	int				source_sector;
	int				source_wall;
	int				source_sprite;
	int				source_enemy;
	int				target_sector;
	int				target_wall;
	int				target_sprite;
	int				target_enemy;
	void			*target;
}					t_condition;

typedef struct		s_event
{
	void			*target;
	double			goal;
	double			start_value;
	double			start_incr;
	double			incr;
	double			speed;
	double			total;
	Uint32			start_time;
	Uint32			last_tick;
	Uint32			end_time;
	Uint32			delay;
	int				target_index;
	int				mod_type;
	int				type;
	int				target_type;
	int				happened;
	t_condition		*launch_conditions;
	size_t			nb_launch_conditions;
	t_condition		*exec_conditions;
	size_t			nb_exec_conditions;
	int				(*check_func)(struct s_event *, void *);
	t_event_param	check_param;
	int				(*exec_func)(void *, void *);
	void			*exec_param;
	int				(*update_func)(struct s_event *, void *);
	t_event_param	update_param;
	int				uses;
	int				max_uses;
}					t_event;

typedef struct		s_wall_sprites
{
	int				nb_sprites;
	int				*sprite;
	t_v2			*pos;
	t_v2			*scale;
	t_event			**press_events;
	size_t			*nb_press_events;
	t_event			**shoot_events;
	size_t			*nb_shoot_events;
}					t_wall_sprites;

typedef struct		s_bullet_hole
{
  	t_v2			pos;
	t_v2			scale;
}					t_bullet_hole;

typedef struct		s_sector
{
	t_v2			floor_normal;
	t_v2			ceiling_normal;
	double			floor;
	double			floor_slope;
	int				floor_texture;
	t_v2			*floor_scale;
	t_v2			floor_map_scale;
	t_v2			*floor_align;
	t_v2			floor_map_align;
	double			ceiling;
	double			ceiling_slope;
	int				ceiling_texture;
	t_v2			*ceiling_scale;
	t_v2			ceiling_map_scale;
	t_v2			*ceiling_align;
	t_v2			ceiling_map_align;
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
	int				*vertices;
	int				*neighbors;
	int				*portals;
	int				*textures;
	t_wall_sprites	*wall_sprites;
	t_wall_sprites	floor_sprites;
	t_wall_sprites	ceiling_sprites;
	t_list			**wall_bullet_holes;
	t_v2			*ceiling_sprites_scale;
	t_v2			*floor_sprites_scale;
	double			sprite_time;
	t_v2			*align;
	t_v2			*scale;
	double			**walls_map_lvl;
	double			*floor_map_lvl;
	double			*ceiling_map_lvl;
	int				num;
	int				nb_vertices;
	int				skybox;
	int				*selected;
	double			gravity;
	Uint32			light_color;
	int				brightness;
	int				intensity;
	size_t			nb_stand_events;
	size_t			nb_walk_in_events;
	size_t			nb_walk_out_events;
	t_event			*stand_events;
	t_event			*walk_in_events;
	t_event			*walk_out_events;
	int				start_floor_slope;
	int				start_ceiling_slope;
	int				start_slope;
}					t_sector;

typedef struct		s_vertex
{
	double			clipped_x[2];
	double			clipped_y[2];
	double			x;
	double			y;
	int				clipped[2];
	int			num;
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
	int				*rendered_sectors;
	int				*xmin;
	int				*xmax;
	int				computed;
	int				*sector_computed;
	int				size;
	int				*sectors_size;
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
	t_v3			old_pos;
	t_camera		camera;
	t_init_data		player_init_data;
	Uint32			start_move;
	int				moving;
	int				stuck;
	int				prev_sector;
	double			eyesight;
	double			speed;
	int				hit;
	double			size_2d;
	double			rotation_speed;
	int				sector;
	int				lowest_sect;
	int				highest_sect;
	int				curr_weapon;
	int				health;
	int				armor;
	int				killed;
	double			nb_shots;
	double			touched;
	double			accuracy;
	double			head_z;
	t_state			state;
	double			velocity;
	double			velocity_start;
	double			acceleration;
	double			start_pos;
	int				drop_flag;
	int				invincible;
	int				infinite_ammo;
	int				changed_sector;
	int				old_sector;
	int				in_combat;
}					t_player;

/*
** Player's keys configuration
*/

typedef struct		s_keys
{
	Sint32			forward;
	Sint32			backward;
	Sint32			backspace;
	Sint32			left;
	Sint32			right;
	Sint32			forward2;
	Sint32			backward2;
	Sint32			left2;
	Sint32			right2;
	Sint32			plus;
	Sint32			minus;
	Sint32			plus2;
	Sint32			minus2;
	Sint32			shift;
	Sint32			shift2;
	Sint32			ctrl;
	Sint32			home;
	Sint32			end;
	Sint32			space;
	Sint32			down;
	Sint32			up;
	Sint32			option;
	Sint32			enter;
	Sint32			s;
	Sint32			e;
	Sint32			del;
	Sint32			tab;
	Sint32			comma;
	Sint32			period;
	Sint32			minus1;
	Sint32			equals;
	Sint32			p;
	Sint32			a;
	Sint32			lgui;
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
	uint8_t			e;
	uint8_t			del;
	uint8_t			tab;
	uint8_t			comma;
	uint8_t			period;
	uint8_t			minus1;
	uint8_t			equals;
	uint8_t			p;
	uint8_t			home;
	uint8_t			end;
	uint8_t			a;
	uint8_t			lgui;
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
	TTF_Font		*lato10;
	TTF_Font		*lato15;
	TTF_Font		*lato20;
	TTF_Font		*lato25;
	TTF_Font		*lato30;
	TTF_Font		*lato35;
	TTF_Font		*lato40;
	TTF_Font		*lato45;
	TTF_Font		*lato50;
	TTF_Font		*lato_black10;
	TTF_Font		*lato_black15;
	TTF_Font		*lato_black20;
	TTF_Font		*lato_black25;
	TTF_Font		*lato_black30;
	TTF_Font		*lato_black35;
	TTF_Font		*lato_black40;
	TTF_Font		*lato_black45;
	TTF_Font		*lato_black50;
	TTF_Font		*lato_bold10;
	TTF_Font		*lato_bold15;
	TTF_Font		*lato_bold20;
	TTF_Font		*lato_bold25;
	TTF_Font		*lato_bold30;
	TTF_Font		*lato_bold35;
	TTF_Font		*lato_bold40;
	TTF_Font		*lato_bold45;
	TTF_Font		*lato_bold50;
}					t_fonts;

/*
** Sound structure
*/

typedef struct		s_sound
{
	double			music_vol;
	double			ambient_vol;
	FMOD_SYSTEM		*system;
	FMOD_RESULT		result;
	FMOD_CHANNEL	*music_chan;
	FMOD_CHANNEL	*player_movement_chan;
	FMOD_CHANNEL	*player_shots_chan;
	FMOD_CHANNEL	*footstep_chan;
	FMOD_SOUND		*at_dooms_gate;
	FMOD_SOUND		*mt_erebus;
	FMOD_SOUND		*footstep;
}					t_sound;

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
	double			force;
	double			collision;
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
	int				ammo_type;
	double			range;
	int				max_ammo;
	int				damage;
	int				splash;
	FMOD_SOUND		*shot;
}					t_weapons;

typedef struct		s_projectile_stats
{
	int				damage;
	double			size_2d;
	double			speed;
	double			height;

}					t_projectile_stats;

typedef struct		s_projectile_data
{
	t_v3			pos;
	double			scale;
	double			angle;
	int				sprite;
}					t_projectile_data;

/*
** Projectile structure
*/

typedef	struct		s_projectile
{
	t_v3			pos;
	t_v3			translated_pos;
	t_v3			rotated_pos;
	t_v3			dest;
	int				left;
	int				right;
	int				top;
	int				bottom;
	double			scale;
	double			angle;
	double			size_2d;
	int			brightness;
	Uint32			light_color;
	int				intensity;
	int				sector;
	int				exists;
	double			speed;
	int				sprite;
	int				damage;
}					t_projectile;

typedef	struct		s_explosion_data
{
	t_v3			pos;
	double			radius;
	int				sprite;
	int				damage;
}					t_explosion_data;

/*
** Explosion structure
*/

typedef	struct		s_explosion
{
	t_v3			pos;
	t_v3			rotated_pos;
	t_v3			translated_pos;
	t_animation		explosion_anim;
	double			radius;
	int				centered_sprite;
	int				damage;
	int				sprite;
	int			damage_burst;
	int				left;
	int				right;
	int				top;
	int				bottom;
	double			scale;
}					t_explosion;

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
	int				seen;
	int				bottom;
	int				sprite;
	int				main_sprite;
	int				destructible;
	int				explodes;
	double			explosion_size;
	double			scale;
	double			angle;
	double			height;
	double			size_2d;
	double			height_ratio;
	int				brightness;
	Uint32			light_color;
	int				type;
	int				quantity;
	int				ammo_type;
	int				weapon;
	int				intensity;
	int				pickable;
	int				solid;
	int				ammo;
	int				damage;
	int				map_hp;
	int				health;
	int				sector;
	int				exists;
	int				num;
	int				nb_rest_state;
	t_animation		rest;
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
	int				firing_type;
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
	int				nb_rest_state;
	int				nb_pursuit_state;
	int				nb_firing_state;
	int				seen;
	int				saw_player;
	double			height_on_floor;
	double			scale;
	double			angle;
	double			size_2d;
	double			height_ratio;
	double			width_ratio;
	double			eyesight;
	int				brightness;
	Uint32			light_color;
	int				intensity;
	int				map_hp;
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
	Uint32			time;
	int				pitch;
}					t_sdl;

/*
**	Definition of a texture
*/

typedef struct		s_texture
{
	SDL_Surface		*surface;
	SDL_Surface		**maps;
	Uint32			*str;
	double			scale;
	int				xpadding;
	int				ypadding;
	unsigned int	w;
	unsigned int	h;
	size_t			nb_maps;
}					t_texture;

typedef struct s_skybox
{
	char		*name;
	t_texture	textures[6];
}				t_skybox;

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
	int				l;
	int				o;
	int				animations;
	int				gamma_filter;
	int				mipmapping;
	int				mouse;
	int				max_floor_sprites;
	int				max_wall_sprites;
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
	t_rectangle		hover;
	t_rectangle		pressed;
	t_rectangle		down;
	SDL_Surface		*img_up;
	SDL_Surface		*img_hover;
	SDL_Surface		*img_pressed;
	SDL_Surface		*img_down;
	Uint32			up_text_color;
	Uint32			hover_text_color;
	Uint32			pressed_text_color;
	Uint32			down_text_color;
	t_point			pos;
	t_point			size_up;
	t_point			size_pressed;
	t_point			size_down;
	t_point			size_hover;
	char			*str;
	TTF_Font		*font;
	int				state;
	int				draw;
	int				anim_state;
	int				(*down_action)(void *);
	int				(*release_action)(void *);
	int				(*press_action)(void *);
	void			*param;
	void			*release_param;
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
	int				type;
	int				state;
	char			*str;
	int				yes_pressed;
	int				no_pressed;
	void			(*yes_action)(void *);
	void			*yes_target;
	void			(*no_action)(void *);
	void			*no_target;
}					t_confirmation_box;

/*
**	Data for input box
**	str = string content. User has to strdup and strdel it correctly
**	type = INT, DOUBLE, STRING
*/

typedef struct		s_input_box
{
	TTF_Font		*font;
	t_point			size;
	t_point			pos;
	int				state;
	int				type;
	int				caps;
	int				period;
	int				selecting;
	int				cursor_state;
	int				add_period;
	int				accept_inputs;
	size_t			cursor;
	size_t			float_count;
	size_t			int_count;
	size_t			period_index;
	size_t			minus;
	size_t			select_start;
	size_t			select_end;
	char			*str;
	char			*error_message;
	Uint32			del_timer;
	Uint32			del_delay;
	Uint32			cursor_timer;
	Uint32			cursor_delay;
	Uint32			move_cursor_timer;
	Uint32			move_cursor_delay;
	Uint32			input_timer;
	Uint32			input_delay;
	Uint32			same_touch_timer;
	char			**str_target;
	int				*int_target;
	double			*double_target;
	void			*target;
	int				(*check)(void *);
	int				(*update)(void *);
}					t_input_box;
  
#endif
