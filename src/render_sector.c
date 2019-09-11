/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/11 18:28:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void		get_neighbor_ceiling_and_floor(t_sector sector, t_render2 *render,
		t_env *env)
{
	t_sector	neighbor;
	int			nv1;
	int			nv2;

	neighbor = env->sectors[sector.neighbors[render->i]];
	nv1 = get_vertex_nb_in_sector(sector.vertices[render->i],
			neighbor);
	nv2 = get_vertex_nb_in_sector(sector.vertices[render->i + 1],
			neighbor);
	//ft_printf("nv1 = %d nv2 = %d\n", nv1, nv2);
	render->neighbor_current_ceiling = render->clipped_alpha
		* neighbor.v[nv1].ceiling_range + neighbor.v[nv1].c1;
	/*render->neighbor_current_ceiling = render->clipped_alpha
		* (neighbor.v[nv2].c1 - neighbor.v[nv2].c1) + neighbor.v[nv1].c1;*/
	render->neighbor_current_floor = render->clipped_alpha
		* neighbor.v[nv1].floor_range + neighbor.v[nv1].f1;
	/*render->neighbor_current_floor = render->clipped_alpha
		* (neighbor.v[nv2].f1 - neighbor.v[nv2].f1) + neighbor.v[nv1].f1;*/
}

void		wall_loop(t_render_vertex v1, t_sector sector, t_render2 render,
		t_env *env)
{
	int	x;

	x = render.xstart;
	while (x <= render.xend)
	{
		//ft_printf("x = %d\n", x);
		render.x = x;
		render.alpha = (x - v1.x) / v1.xrange;
		render.clipped_alpha = (x - v1.clipped_x1) / v1.clipped_xrange;
		render.z = 1.0 / ((1.0 - render.alpha) / v1.vz
				+ render.alpha / sector.v[render.i + 1].vz);
		render.clipped_z = 1.0 / ((1.0 - render.clipped_alpha)
				/ v1.clipped_vz1 + render.clipped_alpha / v1.clipped_vz2);
		render.texel.x = ((1.0 - render.alpha) * v1.xz
				+ render.alpha * sector.v[render.i + 1].xz) * render.z;
		render.texel.y = ((1.0 - render.alpha) * v1.yz
				+ render.alpha * sector.v[render.i + 1].yz) * render.z;
		render.max_ceiling = render.clipped_alpha * v1.ceiling_range + v1.c1;
		render.current_ceiling = ft_clamp(render.max_ceiling,
				env->ymin[x], env->ymax[x]);
		render.max_floor = render.clipped_alpha * v1.floor_range + v1.f1;
		render.current_floor = ft_clamp(render.max_floor,
				env->ymin[x], env->ymax[x]);
		render.no_slope_current_floor = render.clipped_alpha
			* v1.no_slope_floor_range + v1.no_slope_f1;
		render.no_slope_current_ceiling = render.clipped_alpha
			* v1.no_slope_ceiling_range + v1.no_slope_c1;
		render.line_height = render.no_slope_current_floor
			- render.no_slope_current_ceiling;
		render.ceiling_start = render.max_ceiling - render.ceiling_horizon;
		render.floor_start = render.max_floor - render.floor_horizon;
		if (render.current_ceiling > env->ymin[x])
			draw_ceiling2(sector, render, env);
		if (render.current_floor < env->ymax[x])
			draw_floor2(sector, render, env);
		if (sector.neighbors[render.i] >= 0)
		{
			get_neighbor_ceiling_and_floor(sector,
					&render, env);
			if (render.neighbor_current_ceiling > render.current_ceiling)
				draw_upper_wall2(sector, render, env);
			if (render.neighbor_current_floor < render.current_floor)
				draw_bottom_wall2(sector, render, env);
			env->ymin[x] = ft_clamp(ft_max(render.neighbor_current_ceiling,
						render.current_ceiling), env->ymin[x], env->ymax[x]);
			env->ymax[x] = ft_clamp(ft_min(render.neighbor_current_floor,
						render.current_floor), env->ymin[x], env->ymax[x]);
		}
		else
			draw_wall(sector, render, env);
		//update_screen(env);
		//SDL_Delay(50);
		x++;
	}
}

void		render_sector2(t_render2 render, t_env *env)
{
	int				i;
	t_sector		sector;
	t_render_vertex	v1;
	t_render2		new;

	i = -1;
	sector = env->sectors[render.sector];
	//ft_printf("rendering sector %d\n", sector.num);
	while (++i < sector.nb_vertices)
	{
		if (!sector.v[i].draw)
			continue;
		//ft_printf("rendering wall %d\n", i);
		v1 = sector.v[i];
		//ft_printf("min = %d max = %d\n", render.xmin, render.xmax);
		//ft_printf("v1.x = %f v2.x = %f\n", v1.clipped_x, v2.clipped_x);
		if (v1.clipped_x1 >= v1.clipped_x2 || v1.clipped_x1 > render.xmax
				|| v1.clipped_x2 < render.xmin)
			continue;
		//ft_printf("wall is valid\n");
		render.xstart = ft_max(v1.clipped_x1, render.xmin);
		render.xend = ft_min(v1.clipped_x2, render.xmax);
		//ft_printf("start = %d end = %d\n", render.xstart, render.xend);
		render.ceiling_horizon = sector.v[i].ceiling_horizon;
		render.floor_horizon = sector.v[i].floor_horizon;
		render.texture = sector.textures[i];
		render.i = i;
		wall_loop(v1, sector, render, env);
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
