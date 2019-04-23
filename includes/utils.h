/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/23 15:33:59 by lnicosia         ###   ########.fr       */
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

typedef struct	s_v2
{
	double	x;
	double	y;
}				t_v2;

typedef struct	s_v3
{
	double	x;
	double	y;
	double	z;
}				t_v3;

/*
** VERTICES = PLURIEL DE VERTEX
*/

typedef struct	s_sector
{
	double			floor;
	double			floor_slope;
	double			ceiling;
	double			ceiling_slope;
	short			num;
	short			*vertices;
	short			*neighbors;
	short			nb_vertices;
	t_v2			normal;
	double			*floors;
	double			*ceilings;
}				t_sector;

typedef struct	s_vertex
{
	double			x;
	double			y;
	short			num;
}				t_vertex;

typedef struct	s_player
{
	t_v3		pos;
	double		angle;
	double		angle_cos;
	double		angle_sin;
	double		angle_z;
	short		sector;
	short		old_sector;
	double		speed;
	double		size;
}				t_player;

/*
** SDL data necessities
*/

typedef struct	s_sdl
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
	int				render;
}				t_sdl;

/*
**	Contains a list of options for the game
*/

typedef struct	s_options
{
	int			contouring;
	int			render_sectors;
	int			lighting;
	int			show_minimap;
	int			show_fps;
	int			wall_lover;
	int			color_clipping;
}				t_options;

/*
**	Contains every data need to print a text on the screen
*/

typedef struct	s_printable_text
{
	char			*str;
	char			*font;
	int				size;
	SDL_Color		color;
}				t_printable_text;

/*
**	Environment data struct
*/

typedef struct	s_env
{
	t_sdl			sdl;
	t_vertex		*vertices;
	t_sector		*sectors;
	t_player		player;
	t_options		options;
	int				w;
	int				h;
	int				running;
	int				nb_sectors;
	int				nb_vertices;
}				t_env;

void				free_all(t_env *env);
void				clear_image(t_env *env);
int					init_sdl(t_env *env);
int					init_ttf(t_env *env);
void				draw(t_env *env);
void				update_screen(t_env *env);
int					parsing(int fd, t_env *env);
void				check_parsing(t_env *env);
void				view(t_env *env);
void				move_player(t_env *env);
void				init_options(t_env *env);
void				options(t_env *env);
int					check_collision(t_env *env, double x_move, double y_move);
void				minimap(t_env *e);
void				fps(t_env *e);
void				view(t_env *env);

t_v2				new_v2(double x, double y);
t_v3				new_v3(double x, double y, double z);

t_printable_text	new_printable_text(char *text, char *font, unsigned int color, int size);
void				print_text(t_v2 pos, t_printable_text, t_env *env);
void				precompute_slopes(t_env *env);
void				draw_axes(t_env *env);
void				draw_crosshair(t_env *env);

#endif
