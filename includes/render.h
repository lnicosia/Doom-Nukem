/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 18:18:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2_H
# define RENDER2_H
# include "env.h"

typedef struct		s_vline
{
	int				start;
	int				end;
	int				x;
	int				draw_wall;
	unsigned int	color;
}					t_vline;

typedef struct	s_render
{
	t_camera	*camera;
	t_v2		texel;
	t_v2		texture_scale;
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
	double		ceiling_height;
	double		floor_height;
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
	double		falpha;
	double		calpha;
	double		neighbor_falpha;
	double		neighbor_calpha;
	double		wall_xstart;
	double		wall_xend;
	double		floor_xstart;
	double		floor_xend;
	double		ceiling_xstart;
	double		ceiling_xend;
	double		nfloor_xstart;
	double		nfloor_xend;
	double		nceiling_xstart;
	double		nceiling_xend;
	double		neighbor_ceiling_ystart;
	double		neighbor_ceiling_yend;
	double		neighbor_floor_ystart;
	double		neighbor_floor_yend;
	double		sprite_x;
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
	int			map_lvl;
	int			i;
	int			thread;
	int			texture_w;
	int			texture_h;
}				t_render;

typedef struct		s_render_projectile
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
	int			brightness;
	Uint32			light_color;
	int				intensity;
	double			xrange;
	double			yrange;
	t_point			screen_pos;
}					t_render_projectile;

typedef struct		s_render_explosion
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
	double			xrange;
	double			yrange;
	t_point			screen_pos;
}					t_render_explosion;

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
	int			brightness;
	Uint32			light_color;
	int				intensity;
	double			xrange;
	double			yrange;
	t_point			screen_pos;
}					t_render_object;

typedef struct	s_skybox_data
{
	double		z;
	double		ceiling_start;
	double		ceiling_horizon;
	double		max_ceiling;
	double		max_floor;
	int		i;
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
	int				ystart;
	int				yend;
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

typedef struct		s_explosion_thread
{
	t_env				*env;
	t_camera			camera;
	t_explosion			explosion;
	t_render_explosion	erender;
	int					xstart;
	int					xend;
}					t_explosion_thread;

typedef struct		s_projectile_thread
{
	t_env				*env;
	t_camera			camera;
	t_projectile		projectile;
	t_render_projectile	prender;
	int					xstart;
	int					xend;
}					t_projectile_thread;

typedef struct		s_enemy_thread
{
	t_env			*env;
	t_camera		camera;
	t_enemies		enemy;
	t_render_object	orender;
	int				xstart;
	int				xend;
}					t_enemy_thread;

void			select_line(t_vline vline, t_env *env);
int				render_sector(t_render render, t_env *env);
void			draw_ceiling(t_sector sector, t_render render, t_env *env);
void			draw_vline_ceiling(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_ceiling_color(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_ceiling_brightness(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_ceiling_both(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_wall(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_wall_color(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_wall_brightness(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_wall_both(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_floor(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_floor_color(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_floor_brightness(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_vline_floor_both(t_sector sector, t_vline vline,
t_render render, t_env *env);
void			draw_floor(t_sector sector, t_render render, t_env *env);
void			draw_wall(t_sector sector, t_render render, t_env *env);
void			draw_wall_no_light(t_sector sector, t_render render, t_env *env);
void			draw_wall_sprites(t_sector sector, t_render render, t_env *env);
void			draw_wall_bullet_holes(t_sector sector, t_render render,
t_env *env);
void			draw_floor_sprites(t_sector sector, t_render render, t_env *env);
void			draw_floor_sprites_no_light(t_sector sector,
t_render render, t_env *env);
void			draw_floor_sprites_color(t_sector sector,
t_render render, t_env *env);
void			draw_floor_sprites_brightness(t_sector sector,
t_render render, t_env *env);
void			draw_floor_sprites_both(t_sector sector,
t_render render, t_env *env);
void			draw_ceiling_sprites(t_sector sector, t_render render, t_env *env);
void			draw_ceiling_sprites_no_light(t_sector sector,
t_render render, t_env *env);
void			draw_ceiling_sprites_color(t_sector sector,
t_render render, t_env *env);
void			draw_ceiling_sprites_brightness(t_sector sector,
t_render render, t_env *env);
void			draw_ceiling_sprites_both(t_sector sector,
t_render render, t_env *env);
void			draw_upper_wall(t_sector sector, t_render render, t_env *env);
void			draw_bottom_wall(t_sector sector, t_render render,
		t_env *env);
void			draw_skybox(t_render render, int mode, t_env *env);
void			precompute_skybox(t_env *env);
int			get_vertex_nb_in_sector(int vertex, t_sector sector);
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
void			restrict_floor(t_render_vertex v1, t_render *render,
		t_sector sector, t_env *env);
void			restrict_ceiling(t_render_vertex v1, t_render *render,
		t_sector sector, t_env *env);
void			reset_x_restrictions(t_sector *sector, t_env *env);
void			get_vline_data(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env);
int				get_current_wall_map(int texture, double z, t_render *render,
t_env *env);
int				get_current_floor_map(int texture, double z, t_render *render,
t_env *env);
int				get_current_ceiling_map(int texture, double z, t_render *render,
t_env *env);
void			*portal_loop(void *param);
void			*select_portal_loop(void *param);

/*
**	Sprite part
*/

void				*get_enemy_relative_pos(void *param);
void				get_translated_enemy_pos(t_camera camera, t_enemies *enemy);
void				get_rotated_enemy_pos(t_camera camera, t_enemies *enemy);
void				project_enemy(t_render_object *erender, t_enemies enemy, t_env *env);

void				*get_projectile_relative_pos(t_camera camera, t_env *env);
void				get_translated_projectile_pos(t_camera camera, t_projectile *projectile);
void				get_rotated_projectile_pos(t_camera camera, t_projectile *projectile);
void				project_projectile(t_render_projectile *prender, t_projectile projectile, t_env *env);

void				*get_explosion_relative_pos(t_camera camera, t_env *env);
void				get_translated_explosion_pos(t_camera camera, t_explosion *explosion);
void				get_rotated_explosion_pos(t_camera camera, t_explosion *explosion);
void				project_explosion(t_render_explosion *erender, t_explosion explosion, t_env *env);

void				get_translated_object_pos(t_camera camera, t_object *object);
void				get_rotated_object_pos(t_camera camera, t_object *object);
void				*get_object_relative_pos(void *param);
void				project_object(t_render_object *orender, t_object object, t_env *env);
void				get_neighbor_ceil_floor(t_render *render, t_env *env, int x);
void				*raycasting(void *param);
void				*skybox_thread(void *param);
void				threaded_skybox(t_env *env, t_render render);
int					draw_object(t_camera camera, t_object *object, t_env *env, int death_sprite);

#endif
