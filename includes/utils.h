/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/03 16:53:20 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <fcntl.h>
# include "libft.h"
# define X1 env->vertices[env->sectors[env->player.sector].vertices[i]].x
# define X2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].x
# define Y1 env->vertices[env->sectors[env->player.sector].vertices[i]].y
# define Y2 env->vertices[env->sectors[env->player.sector].vertices[i + 1]].y
# define PLAYER_XPOS env->player.pos.x
# define PLAYER_YPOS env->player.pos.y

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

/*
** VERTICES = PLURIEL DE VERTEX
*/

typedef struct		s_sector
{
	double			floor;
	double			floor_slope;
	double			ceiling;
	double			ceiling_slope;
	short			num;
	double			x_max;
	short			*vertices;
	short			*neighbors;
	short			nb_vertices;
	t_v2			normal;
	double			*floors;
	double			*ceilings;
}					t_sector;

typedef struct		s_vertex
{
	double			x;
	double			y;
	short			num;
}					t_vertex;

typedef struct		s_player
{
	t_v3			pos;
	double			angle;
	double			angle_cos;
	double			angle_sin;
	double			angle_z;
	short			sector;
	double			speed;
	double			size;
}					t_player;

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
}					t_inputs;

/*
** SDL data necessities
*/

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	TTF_Font		*font;
	int				mouse_x;
	int				mouse_y;
	unsigned int	*img_str;
	int				time;
}					t_sdl;

/*
**	Contains a list of options for the game
*/

typedef struct		s_options
{
	int				contouring;
	int				render_sectors;
	int				lighting;
	int				show_minimap;
	int				show_fps;
	int				wall_lover;
	int				color_clipping;
	int				wall_color;
	int				test;
}					t_options;

/*
**	Contains every data need to print a text on the screen
*/

typedef struct		s_printable_text
{
	char			*str;
	char			*font;
	int				size;
	SDL_Color		color;
}					t_printable_text;

/*
**	Environment data struct
*/

typedef struct		s_env
{
	t_sdl			sdl;
	t_vertex		*vertices;
	t_sector		*sectors;
	t_player		player;
	t_options		options;
	t_keys			keys;
	t_inputs		inputs;
	int				w;
	int				h;
	int				running;
	int				nb_sectors;
	int				nb_vertices;
}					t_env;

/*
** Main functions
*/

int					doom(int ac, char **av);
void				free_all(t_env *env);
int					crash(char *str, t_env *env);

/*
** Init functions
*/

void				init_pointers(t_env *env);
int					init_sdl(t_env *env);
int					init_ttf(t_env *env);
void				init_options(t_env *env);
void				init_keys(t_env *env);
void				init_inputs(t_env *env);
int					parsing(int fd, t_env *env);
int					valid_map(t_env *env);

/*
** Screen utils
*/

void				clear_image(t_env *env);
void				update_screen(t_env *env);
t_printable_text	new_printable_text(
		char *text,
		char *font,
		unsigned int color,
		int size);
void				print_text(t_v2 pos, t_printable_text text, t_env *env);
void				fps(t_env *e);

/*
** Main pipeline functions
*/

int					draw(t_env *env);
void				check_parsing(t_env *env);
void				options(t_env *env);
void				minimap(t_env *e);
void				view(t_env *env);

t_v2				new_v2(double x, double y);
t_v3				new_v3(double x, double y, double z);

void				precompute_slopes(t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);
void				keys(t_env *env);
void				move_player(t_env *env);

#endif
