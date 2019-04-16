/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/16 11:26:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <SDL.h>
# include <fcntl.h>
# include "libft.h"

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
	double			ceiling;
	short			num;
	short			*vertices;
	short			*neighbors;
	short			nb_vertices;
	short			state;
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
	int			speed;
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
	int				mouse_x;
	int				mouse_y;
	unsigned int	*img_str;
}				t_sdl;

/*
**	Contains a list of options for the game
*/

typedef struct	s_options
{
	int			contouring;
	int			render_sectors;
	int			lighting;
}				t_options;

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

void			free_all(t_env *env);
void			clear_image(t_env *env);
int				init_sdl(t_env *env);
void			draw(t_env *env);
void			render(t_env *env);
int				parsing(int fd, t_env *env);
void			check_parsing(t_env *env);
void			view(t_env *env);
void			move_player(t_env *env);
void			init_options(t_env *env);
void			options(t_env *env);

void			map_process(t_env *e);
void			map_render(t_env *e);

void			move_player(t_env *env);
void			view(t_env *env);

#endif
