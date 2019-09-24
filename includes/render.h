/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/24 12:15:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2_H
# define RENDER2_H
# include "env.h"
# include "render.h"

typedef struct		s_vline
{
	int				start;
	int				end;
	int				x;
	unsigned int	color;
}					t_vline;

typedef struct	s_render
{
	t_camera	*camera;
	t_v2		texel;
	double		alpha;
	double		clipped_alpha;
	double		z;
	double		max_floor;
	double		current_floor;
	double		no_slope_current_floor;
	double		floor_start;
	double		floor_horizon;
	double		max_ceiling;
	double		current_ceiling;
	double		no_slope_current_ceiling;
	double		ceiling_start;
	double		ceiling_horizon;
	double		line_height;
	double		neighbor_max_ceiling;
	double		neighbor_current_ceiling;
	double		neighbor_max_floor;
	double		neighbor_current_floor;
	double		divider;
	double		z_near_z;
	double		texel_x_near_z;
	double		texel_y_near_z;
	double		camera_x_z;
	double		camera_y_z;
	double		texel_x_camera_range;
	double		texel_y_camera_range;
	double		zrange;
	int			neighbor;
	int			nv1;
	int			nv2;
	int			sector;
	int			selected;
	int			xmin;
	int			xmax;
	int			xstart;
	int			xend;
	int			ystart;
	int			yend;
	int			x;
	int			y;
	int			texture;
	int			i;
}				t_render;

typedef struct		s_render_object
{
	t_camera		camera;
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

typedef struct	s_skybox_data
{
	double		z;
	double		ceiling_start;
	double		ceiling_horizon;
	int			mode;
}				t_skybox_data;

typedef struct	s_render_thread
{
	t_render_vertex	v1;
	t_sector		sector;
	t_render		render;
	t_env			*env;
	int				xstart;
	int				xend;
}				t_render_thread;

typedef struct	s_precompute_thread
{
	int			start;
	int			end;
	t_env		*env;
	t_camera	*camera;
}				t_precompute_thread;

typedef struct		s_object_thread
{
	t_env			*env;
	t_camera		camera;
	t_object		object;
	t_render_object	orender;
	int				xstart;
	int				xend;
}					t_object_thread;

typedef struct		s_enemy_thread
{
	t_env			*env;
	t_camera		camera;
	t_enemies		enemy;
	t_render_object	orender;
	int				xstart;
	int				xend;
}					t_enemy_thread;

void			render_sector(t_render render, t_env *env);
void			render_sector2(t_render render, t_env *env);
void			draw_ceiling(t_sector sector, t_render render, t_env *env);
void			draw_floor(t_sector sector, t_render render, t_env *env);
void			draw_wall(t_sector sector, t_render render, t_env *env);
void			draw_wall2(t_sector sector, t_render render, t_env *env);
void			draw_ceiling2(t_sector sector, t_render render, t_env *env);
void			draw_floor2(t_sector sector, t_render render, t_env *env);
void			draw_upper_wall(t_sector sector, t_render render, t_env *env);
void			draw_bottom_wall(t_sector sector, t_render render,
		t_env *env);
void			draw_skybox(t_render render, int mode, t_env *env);
void			precompute_skybox(t_env *env);
short			get_vertex_nb_in_sector(short vertex, t_sector sector);
void			precompute_neighbors(int i, t_camera *camera, t_sector *sector,
		t_env *env);
void			draw_skybox_ceiling(t_vline vline, t_skybox_data wall_data,
		t_render render, t_env *env);
void			draw_skybox_wall(t_vline vline, t_skybox_data wall_data,
		t_render render, t_env *env);
void			draw_skybox_floor(t_vline vline, t_skybox_data wall_data,
		t_render render, t_env *env);
void			draw_vline_color(t_vline vline, t_env *env);
int				get_screen_sectors(t_camera *camera, t_env *env);

/*
**	Sprite part
*/

void				*get_enemy_relative_pos(void *param);
void				get_translated_enemy_pos(t_camera camera, t_enemies *enemy);
void				get_rotated_enemy_pos(t_camera camera, t_enemies *enemy);
void				project_enemy(t_render_object *erender, t_enemies enemy, t_env *env);

void				get_translated_object_pos(t_camera camera, t_object *object);
void				get_rotated_object_pos(t_camera camera, t_object *object);
void				*get_object_relative_pos(void *param);
void				project_object(t_render_object *orender, t_object object, t_env *env);
void				get_neighbor_ceil_floor(t_render *render, t_env *env, int x);
void				*raycasting(void *param);
void				threaded_raycasting(t_env *env, t_render render);
void				*skybox_thread(void *param);
void				threaded_skybox(t_env *env, t_render render);
void				draw_object(t_camera camera, t_object *object, t_env *env);

#endif
