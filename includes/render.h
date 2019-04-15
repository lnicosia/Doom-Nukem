/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/15 11:29:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MAX_SECTORS_TO_RENDER 32
# define HFOV	0.73
# define VFOV	0.2
# include "utils.h"

typedef struct		s_line
{
	int				start;
	int				end;
	int				x;
	unsigned int	color;
}					t_line;

/*
**	Every variable needed for the rendering
*/

typedef struct		s_render
{
	t_line			line;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	t_v2			v1;
	t_v2			v2;
	double			vx1;
	double			vx2;
	double			vz1;
	double			vz2;
	int				currentx;
	int				floor1;
	int				floor2;
	int				current_floor;
	int				current_ceiling;
	int				current_neighbor_floor;
	int				current_neighbor_ceiling;
	int				ceiling1;
	int				ceiling2;
	int				neighbor_floor1;
	int				neighbor_floor2;
	int				neighbor_ceiling1;
	int				neighbor_ceiling2;
	int				x1;
	int				x2;
	int				xstart;
	int				xend;
	int				sector;
	int				father;
	int				light;
}					t_render;

void				get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i);
void				get_rotated_vertices(t_render *render, t_env *env);
void				get_floor_and_ceiling_screen_coordinates(t_render *render, t_env *env, t_sector sector);
void				get_neighbor_floor_and_ceiling_screen_coordinates(t_render *render, t_env *env, t_sector sector);
void				draw_line(t_line, t_env *env);
void				draw_ceiling(t_render render, t_env *env);
void				draw_floor(t_render render, t_env *env);
void				draw_upper_wall(t_render render, t_env *env);
void				draw_bottom_wall(t_render render, t_env *env);

#endif
