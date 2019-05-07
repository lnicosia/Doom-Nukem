/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/07 12:27:06 by lnicosia         ###   ########.fr       */
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
	double			far_z;
	double			near_z;
	double			near_side;
	double			far_side;
	int				clipped;
	double			dist1;
	double			dist2;
	double			floor_slope;
	double			ceiling_slope;
	short			nv1;
	short			nv2;
}					t_render;

void				get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i);
void				get_rotated_vertices(t_render *render, t_env *env);
void				project_floor_and_ceiling(t_render *render, t_env *env, t_sector sector, int i);
void				project_neighbor_floor_and_ceiling(t_render *render, t_env *env, t_sector sector);
void				draw_line(t_line, t_env *env);
void				draw_ceiling(t_render render, t_env *env);
void				draw_floor(t_render render, t_env *env);
void				draw_upper_wall(t_render render, t_env *env);
void				draw_bottom_wall(t_render render, t_env *env);
t_v2				get_intersection(t_v2 p1, t_v2 p2, t_v2 p3, t_v2 p4);
t_v2				get_sector_normal(t_sector sector, t_env *env);
double				cross_product(double x0, double y0, double x1, double y1);

#endif
