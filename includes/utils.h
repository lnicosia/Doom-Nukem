/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/09 18:39:20 by sipatry          ###   ########.fr       */
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
}				t_sector;

typedef struct	s_vertex
{
	double			x;
	double			y;
	short			num;
}				t_vertex;

typedef struct	s_player
{
	t_v2		pos;
	double		angle;
	short		sector;
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
	unsigned int	*img_str;
}				t_sdl;

typedef struct	s_env
{
	t_sdl			sdl;
	t_vertex		*vertices;
	t_sector		*sector;
	t_player		player;
	int				w;
	int				h;
	int				running;
	int				nb_sectors;
	int				nb_vertices;
}				t_env;

void			free_all(t_env *env);
void			clear_image(t_env *env);
int				init_sdl(t_env *env);
void			init_map(t_env *env);

#endif
