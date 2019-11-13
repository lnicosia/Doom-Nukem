/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/12 16:33:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		*wall_loop(void *param)
{
	t_render_vertex	v1;
	t_sector		sector;
	t_render		render;
	t_env			*env;
	int				x;
	int				xend;

	v1 = ((t_render_thread*)param)->v1;
	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	while (x <= xend)
	{
		render.x = x;
		render.alpha = (x - v1.x) / v1.xrange;
		render.clipped_alpha = (x - v1.clipped_x1) / v1.clipped_xrange;
		render.divider = 1 / (render.camera->v[sector.num][render.i + 1].vz
					+ render.alpha * v1.zrange);
		render.z = v1.zcomb * render.divider;
		render.z_near_z = render.z * render.camera->near_z;
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
		if (render.current_ceiling > env->ymin[x]
				|| render.current_floor < env->ymax[x])
		{
			render.texel.x = (v1.x0z1 + render.alpha * v1.xzrange)
				* render.divider;
			render.texel.y = (v1.y0z1 + render.alpha * v1.yzrange)
				* render.divider;
			render.texel_x_near_z = render.texel.x * render.camera->near_z;
			render.texel_y_near_z = render.texel.y * render.camera->near_z;
			render.camera_x_z = render.camera->pos.x * render.z;
			render.camera_y_z = render.camera->pos.y * render.z;
			render.texel_x_camera_range = render.camera_x_z
				- render.texel_x_near_z;
			render.texel_y_camera_range = render.camera_y_z
				- render.texel_y_near_z;
			render.zrange = render.z - render.camera->near_z;
		}
		if (render.current_ceiling > env->ymin[x])
			draw_ceiling(sector, render, env);
		if (render.current_floor < env->ymax[x])
			draw_floor(sector, render, env);
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
				draw_upper_wall(sector, render, env);
			if (render.neighbor_current_floor < render.current_floor)
				draw_bottom_wall(sector, render, env);
			env->ymin[x] = ft_clamp(ft_max(render.neighbor_current_ceiling,
						render.current_ceiling), env->ymin[x], env->ymax[x]);
			env->ymax[x] = ft_clamp(ft_min(render.neighbor_current_floor,
						render.current_floor), env->ymin[x], env->ymax[x]);
		}
		else
		{
			if (sector.textures[render.i] == -1)
				draw_skybox(render, 1, env);
			else
				draw_wall(sector, render, env);
		}
		draw_wall_sprites(sector, render, env);
		x++;
	}
	return (NULL);
}

void		threaded_wall_loop(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	t_render_thread	rt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		render.thread = i;
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
	/*t_render_thread	rt;
	rt.v1 = v1;
	rt.sector = sector;
	rt.render = render;
	rt.env = env;
	rt.xstart = render.xstart;
	rt.xend = render.xend;
	wall_loop(&rt);*/
}

void		render_sector(t_render render, t_env *env)
{
	int				i;
	t_sector		sector;
	t_render_vertex	v1;
	t_render		new;

	i = -1;
	if (render.camera->rendered_sectors[render.sector])
		return ;
	render.camera->rendered_sectors[render.sector]++;
	sector = env->sectors[render.sector];
	//ft_printf("rendering sector %d\n", sector.num);
	while (++i < sector.nb_vertices)
	{
		if (!render.camera->v[sector.num][i].draw)
			continue;
		v1 = render.camera->v[sector.num][i];
		//ft_printf("wall %d x1 = %f x2 = %f\n", i, v1.clipped_x1, v1.clipped_x2);
		if (v1.clipped_x1 >= v1.clipped_x2 || v1.clipped_x1 > render.xmax
				|| v1.clipped_x2 < render.xmin)
			continue;
		//ft_printf("cc\n");
		render.xstart = ft_max(v1.clipped_x1, render.xmin);
		render.xend = ft_min(v1.clipped_x2, render.xmax);
		render.ceiling_horizon = v1.ceiling_horizon;
		render.floor_horizon = v1.floor_horizon;
		render.texture = sector.textures[i];
		if (render.texture == -1)
		{
			render.texture_w = env->textures[32].surface->w;
			render.texture_h = env->textures[32].surface->h;
		}
		else
		{
			render.texture_w = env->wall_textures[render.texture].surface->w;
			render.texture_h = env->wall_textures[render.texture].surface->h;
		}
		render.i = i;
		threaded_wall_loop(v1, sector, render, env);
		if (sector.neighbors[i] != -1)
		{
			new = render;
			new.xmin = render.xstart;
			new.sector = sector.neighbors[i];
			new.xmax = render.xend;
			render_sector(new, env);
		}
	}
	//ft_printf("sector %d ok\n", sector.num);
	render.camera->rendered_sectors[render.sector]--;
}
