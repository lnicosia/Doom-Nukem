/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 17:07:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void		wall_loop(t_render_vertex v1, t_render_vertex v2, t_render2 render,
		t_env *env)
{
	int	x;

	x = render.xstart;
	while (x <= render.xend)
	{
		render.x = x;
		render.alpha = (x - v1.x) / v1.xrange;
		render.clipped_alpha = (x - v1.clipped_x) / v1.clipped_xrange;
		render.z = 1.0 / ((1.0 - render.alpha) / v1.vz
				+ render.alpha / v2.vz);
		render.texel.x = ((1.0 - render.alpha) * v1.xz
				+ render.alpha * v2.xz) * render.z;
		render.texel.y = ((1.0 - render.alpha) * v1.yz
				+ render.alpha * v2.yz) * render.z;
		render.max_ceiling = render.clipped_alpha * v1.ceiling_range + v1.c;
		render.current_ceiling = ft_clamp(render.max_ceiling,
				env->ymin[x], env->ymax[x]);
		render.max_floor = render.clipped_alpha * v1.floor_range + v1.f;
		render.current_floor = ft_clamp(render.max_floor,
				env->ymin[x], env->ymax[x]);
		render.no_slope_current_floor = render.clipped_alpha
			* v1.no_slope_floor_range + v1.no_slope_f;
		render.no_slope_current_ceiling = render.clipped_alpha
			* v1.no_slope_ceiling_range + v1.no_slope_c;
		render.line_height = render.no_slope_current_floor
			- render.no_slope_current_ceiling;
		render.ceiling_start = render.max_ceiling - v1.ceiling_horizon;
		render.floor_start = render.max_floor - v1.floor_horizon;
		if (render.current_ceiling > env->ymin[x])
			draw_ceiling2(render, env);
		x++;
	}
}

void		render_sector2(t_render2 render, t_env *env)
{
	int				i;
	t_sector		sector;
	t_render_vertex	v1;
	t_render_vertex	v2;
	t_render2		new;

	i = -1;
	sector = env->sectors[render.sector];
	while (++i < sector.nb_vertices && sector.v[i].draw)
	{
		v1 = sector.v[i];
		v2 = sector.v[i + 1];
		if (v1.x >= v2.x || v1.x > render.xmax || v2.x < render.xmin)
			continue;
		render.xstart = ft_max(v1.x, render.xmin);
		render.xend = ft_min(v2.x, render.xmax);
		render.light_color = sector.light_color;
		wall_loop(v1, v2, render, env);
		if (sector.neighbors[i] != -1)
		{
			new = render;
			new.xmin = render.xstart;
			new.xmax = render.xend;
			new.sector = sector.neighbors[i];
			render_sector2(new, env);
		}
	}
}
