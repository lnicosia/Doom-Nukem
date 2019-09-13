/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/13 18:01:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void		*wall_loop(void *param)
{
	t_render_vertex	v1;
	t_sector		sector;
	t_render2		render;
	t_env			*env;
	int				x;
	int				xend;

	v1 = ((t_render_thread2*)param)->v1;
	sector = ((t_render_thread2*)param)->sector;
	render = ((t_render_thread2*)param)->render;
	env = ((t_render_thread2*)param)->env;
	x = ((t_render_thread2*)param)->xstart;
	xend = ((t_render_thread2*)param)->xend;
	while (x <= xend)
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
		if (sector.neighbors[render.i] != -1)
		{
			render.neighbor_max_ceiling = render.clipped_alpha
				* v1.neighbor_ceiling_range + v1.neighbor_c1;
			render.neighbor_max_floor = render.clipped_alpha
				* v1.neighbor_floor_range + v1.neighbor_f1;
			render.neighbor_current_ceiling = ft_clamp(
					render.neighbor_max_ceiling, env->ymin[x], env->ymax[x]);
			render.neighbor_current_floor = ft_clamp(
					render.neighbor_max_floor, env->ymin[x], env->ymax[x]);
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
		{
			if (sector.textures[render.i] == -1)
				draw_skybox2(render, 1, env);
			else
				draw_wall(sector, render, env);
		}
		//update_screen(env);
		//SDL_Delay(50);
		x++;
	}
	return (NULL);
}

void		threaded_wall_loop(t_render_vertex v1, t_sector sector,
		t_render2 render, t_env *env)
{
	t_render_thread2	rt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		rt[i].v1 = v1;
		rt[i].sector = sector;
		rt[i].render = render;
		rt[i].env = env;
		rt[i].xstart = render.xstart + (render.xend - render.xstart)
			/ (double)THREADS * i;
		rt[i].xend = render.xstart + (render.xend - render.xstart)
			/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, wall_loop, &rt[i]) != 0)
			return ;
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	if (env->inputs.shift)
	{
		update_screen(env);
		SDL_Delay(500);
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
	while (++i < sector.nb_vertices)
	{
		if (!sector.v[i].draw)
			continue;
		v1 = sector.v[i];
		if (v1.clipped_x1 >= v1.clipped_x2 || v1.clipped_x1 > render.xmax
				|| v1.clipped_x2 < render.xmin)
			continue;
		render.xstart = ft_max(v1.clipped_x1, render.xmin);
		render.xend = ft_min(v1.clipped_x2, render.xmax);
		render.ceiling_horizon = sector.v[i].ceiling_horizon;
		render.floor_horizon = sector.v[i].floor_horizon;
		/*if (sector.textures[i].texture == -1)
			render.texture = -1;
		else*/
			render.texture = sector.textures[i];
		render.i = i;
		threaded_wall_loop(v1, sector, render, env);
		if (sector.neighbors[i] != -1)
		{
			new = render;
			new.xmin = render.xstart;
			new.sector = sector.neighbors[i];
			new.portal = 1;
			new.xmax = render.xend;
			render_sector2(new, env);
		}
	}
}
