/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/08 13:51:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MAX_SECTORS_TO_RENDER 32
# include "utils.h"

typedef struct		s_vline
{
	int				start;
	int				end;
	int				x;
	unsigned int	color;
}					t_vline;

/*
**	Every variable needed for the rendering
*/

typedef struct		s_render
{
	t_vline			vline;
	t_v3			v1;
	t_v3			v2;
	t_v2			inter_near;
	t_v2			inter_far;
	t_v2			inter_left;
	t_v2			inter_right;
	t_v2			texel;
	double			vx1;
	double			vx2;
	double			vz1;
	double			vz2;
	double			vcy1;
	double			vcy2;
	double			vfy1;
	double			vfy2;
	double			nvcy1;
	double			nvcy2;
	double			nvfy1;
	double			nvfy2;
	double			clipped_vz1;
	double			clipped_vz2;
	double			clipped_vx1;
	double			clipped_vx2;
	double			clipped_vy1;
	double			clipped_vy2;
	double			light;
	double			z;
	double			clipped_z;
	double			dist1;
	double			dist2;
	double			floor_slope;
	double			ceiling_slope;
	double			alpha;
	double			clipped_alpha;
	double			wall_width;
	double			wall_height;
	double			horizon;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				currentx;
	double			floor1;
	double			floor2;
	int				current_floor;
	int				current_ceiling;
	int				current_neighbor_floor;
	int				current_neighbor_ceiling;
	double			max_floor;
	double			max_ceiling;
	int				max_neighbor_floor;
	int				max_neighbor_ceiling;
	double			ceiling1;
	double			ceiling2;
	int				neighbor_floor1;
	int				neighbor_floor2;
	int				neighbor_ceiling1;
	int				neighbor_ceiling2;
	int				preclip_x1;
	int				preclip_x2;
	int				preclip_floor1;
	int				preclip_floor2;
	int				preclip_ceiling1;
	int				preclip_ceiling2;
	double			x1;
	double			x2;
	int				xstart;
	int				xend;
	int				sector;
	int				v1_clipped;
	int				v2_clipped;
	short			nv1;
	short			nv2;
	int				i;
	int				texture;
	int				floor_texture;
	int				ceiling_texture;
}					t_render;

typedef struct		s_render_object
{
	double			dist;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	t_point			screen_pos;
}					t_render_object;

void				get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i);
void				get_rotated_vertices(t_render *render, t_env *env, t_sector sector, int i);
int					check_fov(t_render *render, t_env *env);
void				clip_walls(t_render *render, t_env *env);
void				project_floor_and_ceiling(t_render *render, t_env *env, t_sector sector, int i);
void				project_neighbor_floor_and_ceiling(t_render *render, t_env *env, t_sector neighbor);
void				project_floor_and_ceiling_preclip(t_render *render, t_env *env, t_sector sector, int i);
void				get_relative_heights(t_render *render, t_env *env, t_sector sector, int i);
void				get_neighbor_relative_heights(t_render *render, t_env *env, t_sector neighbor);
void				draw_vline(t_vline, t_render render, t_env *env);
void				draw_vline_color(t_vline, t_render render, t_env *env);
void				draw_ceiling(t_render render, t_env *env);
void				draw_floor(t_render render, t_env *env);
void				draw_upper_wall(t_render render, t_env *env);
void				draw_bottom_wall(t_render render, t_env *env);
t_v2				get_intersection(t_v2 p1, t_v2 p2, t_v2 p3, t_v2 p4);
t_v2				get_sector_normal(t_sector sector, t_env *env);
double				cross_product(double x0, double y0, double x1, double y1);
void				handle_left(t_render *render, t_env *env);
void				handle_right(t_render *render, t_env *env);
void				handle_far(t_render *render, t_env *env);
void				handle_near(t_render *render, t_env *env);
int					get_screen_sectors(t_env *env);

/*
**	Sprite part
*/

void				draw_sprites(t_env *env, t_render *render);
void				get_translated_object_pos(t_object *object, t_env *env);
void				get_rotated_object_pos(t_object *object, t_env *env);
void				project_object(t_render_object *orender, t_object object, t_env *env);

#endif
