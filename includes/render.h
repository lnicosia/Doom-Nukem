/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/05 13:21:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MAX_SECTORS_TO_RENDER 32
# include "env.h"

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
	t_v2			player_texel;
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
	double			angle_z1;
	double			angle_z2;
	double			preclip_angle_z1;
	double			preclip_angle_z2;
	double			scale1;
	double			scale2;
	int				xmin;
	int				xmax;
	int				currentx;
	int				selected;
	double			floor1;
	double			floor2;
	double			current_floor;
	double			current_ceiling;
	double			current_neighbor_floor;
	double			current_neighbor_ceiling;
	double			max_floor;
	double			max_ceiling;
	double			max_neighbor_floor;
	double			max_neighbor_ceiling;
	double			ceiling1;
	double			ceiling2;
	double			neighbor_floor1;
	double			neighbor_floor2;
	double			neighbor_ceiling1;
	double			neighbor_ceiling2;
	double			preclip_x1;
	double			preclip_x2;
	double			preclip_floor1;
	double			preclip_floor2;
	double			preclip_ceiling1;
	double			preclip_ceiling2;
	double			x1;
	double			x2;
	double			xrange;
	double			preclip_xrange;
	int				xstart;
	int				xend;
	int				sector;
	double			v1_clipped;
	double			v2_clipped;
	short			nv1;
	short			nv2;
	int				i;
	int				texture;
	int				floor_texture;
	int				ceiling_texture;
	short			brightness;
	Uint32			light_color;
	double			x1z1;
	double			x2z2;
	double			y1z1;
	double			y2z2;
	double			ceil_range;
	double			floor_range;
	double			neighbor_ceil_range;
	double			neighbor_floor_range;
	double			line_height;
	double			projected_texture_w;
	double			projected_texture_h;
	double			ceiling_start;
	double			floor_start;
	double			horizon;
	double			floor_horizon;
	double			floor_horizon1;
	double			floor_horizon2;
	double			floor_horizon_range;
	double			ceiling_horizon;
	double			ceiling_horizon1;
	double			ceiling_horizon2;
	double			ceiling_horizon_range;
	double			ceiling_yscale;
	double			ceiling_xscale;
	double			floor_yscale;
	double			floor_xscale;
}					t_render;

typedef struct		s_render_object
{
	double			dist;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				xstart;
	int				ystart;
	int				xend;
	int				yend;
	int				index;
	short			brightness;
	Uint32			light_color;
	double			xrange;
	double			yrange;
	t_point			screen_pos;
}					t_render_object;

typedef struct		s_render_thread
{
	t_render		render;
	t_env			*env;
	int				xstart;
	int				xend;
}					t_render_thread;

typedef struct		s_object_thread
{
	t_env			*env;
	t_object		object;
	t_render_object	orender;
	int				xstart;
	int				xend;
}					t_object_thread;

typedef struct		s_enemy_thread
{
	t_env			*env;
	t_enemies		enemy;
	t_render_object	orender;
	int				xstart;
	int				xend;
}					t_enemy_thread;

void				get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i);
void				get_rotated_vertices(t_render *render, t_env *env, int i);
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

void				*get_enemy_relative_pos(void *param);
void				get_translated_enemy_pos(t_env *env, t_enemies *enemy);
void				get_rotated_enemy_pos(t_env *env, t_enemies *enemy);
void				project_enemy(t_render_object *erender, t_enemies enemy, t_env *env);

void				get_translated_object_pos(t_env *env, t_object *object);
void				get_rotated_object_pos(t_env *env, t_object *object);
void				*get_object_relative_pos(void *param);
void				project_object(t_render_object *orender, t_object object, t_env *env);
void				get_neighbor_ceil_floor(t_render *render, t_env *env, int x);
void				*raycasting(void *param);
void				threaded_raycasting(t_env *env, t_render render);

#endif
