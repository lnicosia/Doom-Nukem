/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/08 12:23:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <SDL.h>
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

typedef struct	s_sector
{
	double			floor;
	double			ceiling;
	short			num;
	t_v2			*walls;
	short			*neighbors;
	short			nbwalls;
}				t_sector;

typedef struct	s_wall
{
	double			x;
	double			y;
	short			num;
	short			next_wall;
	short			next_sector;
}				t_wall;

typedef struct	s_player
{
	t_v2		pos;
	t_v2		dir;
	t_v2		plane;
	t_sector	sector;
}				t_player;

typedef struct	s_map
{
	t_sector	*sectors;
	short		*walls;
}				t_map;

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
	t_map			map;
	int				w;
	int				h;
	int				running;
}				t_env;

void			free_all(t_env *env);
void			clear_image(t_env *env);
int				init_sdl(t_env *env);
void			init_map(t_env *env);

#endif
