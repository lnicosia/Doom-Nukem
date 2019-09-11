/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/11 14:01:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER2_H
# define RENDER2_H
# include "env.h"

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

void			render_sector2(t_render2 render, t_env *env);
void			draw_ceiling2(t_sector sector, t_render2 render,
		t_env *env);
void			draw_floor2(t_sector sector, t_render2 render,
		t_env *env);
void			draw_wall(t_sector sector, t_render2 render,
		t_env *env);
void			draw_skybox2(t_render2 render, t_env *env);
void			precompute_skybox(t_env *env);

#endif
