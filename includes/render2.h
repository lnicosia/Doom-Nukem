/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/16 16:04:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2_H
# define RENDER2_H
# include "env.h"
# include "render.h"

typedef struct	s_render2
{
	t_v2		texel;
	double		alpha;
	double		clipped_alpha;
	double		z;
	double		clipped_z;
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
	int			nv1;
	int			nv2;
	int			sector;
	int			selected;
	int			xmin;
	int			xmax;
	int			xstart;
	int			xend;
	int			x;
	int			texture;
	int			i;
}				t_render2;

typedef struct	s_skybox_data
{
	double		z;
	double		ceiling_start;
	double		ceiling_horizon;
	int			mode;
}				t_skybox_data;

typedef struct	s_render_thread2
{
	t_render_vertex	v1;
	t_sector		sector;
	t_render2		render;
	t_env			*env;
	int				xstart;
	int				xend;
}				t_render_thread2;

typedef struct	s_precompute_thread
{
	int			start;
	int			end;
	t_env		*env;
}				t_precompute_thread;

void			render_sector2(t_render2 render, t_env *env);
void			draw_ceiling2(t_sector sector, t_render2 render, t_env *env);
void			draw_floor2(t_sector sector, t_render2 render, t_env *env);
void			draw_wall(t_sector sector, t_render2 render, t_env *env);
void			draw_upper_wall2(t_sector sector, t_render2 render, t_env *env);
void			draw_bottom_wall2(t_sector sector, t_render2 render,
		t_env *env);
void			draw_skybox2(t_render2 render, int mode, t_env *env);
void			precompute_skybox(t_env *env);
short			get_vertex_nb_in_sector(short vertex, t_sector sector);
void			precompute_neighbors(int i, t_sector *sector, t_sector neighbor,
		t_env *env);
void			draw_skybox_ceiling(t_vline vline, t_skybox_data wall_data,
		t_render2 render, t_env *env);
void			draw_skybox_wall(t_vline vline, t_skybox_data wall_data,
		t_render2 render, t_env *env);
void			draw_skybox_floor(t_vline vline, t_skybox_data wall_data,
		t_render2 render, t_env *env);
void			draw_vline_color2(t_vline vline, t_env *env);

#endif