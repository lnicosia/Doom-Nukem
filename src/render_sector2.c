/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:55:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/30 15:28:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*wall_loop2(void *param)
{
	int	y;
	int	yend;
	t_render_vertex	v1;
	t_sector		sector;
	t_render		render;
	t_env			*env;

	env = ((t_render_thread*)param)->env;
	v1 = ((t_render_thread*)param)->v1;
	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	y = ((t_render_thread*)param)->ystart - 1;
	yend = ((t_render_thread*)param)->yend;
	/*y = render.ystart - 1;
	yend = render.yend;*/
	while (++y <= yend)
	{
		render.y = y;
		render.wall_xstart = 0;
		render.wall_xend = 0;
		render.ceiling_xstart = 0;
		render.ceiling_xend = 0;
		render.floor_xstart = 0;
		render.floor_xend = 0;
		render.calpha = (y - v1.c1) / v1.ceiling_range;
		render.falpha = (y - v1.f1) / v1.floor_range;
		render.current_ceiling = render.calpha * v1.clipped_xrange + v1.clipped_x1;
		render.current_floor = render.falpha * v1.clipped_xrange + v1.clipped_x1;
		if (y >= v1.c1 && y <= v1.f1)
		{
			render.wall_xstart = render.xstart;
		}
		else if (v1.ceiling_range < 0 && y < v1.c1)
		{
			render.wall_xstart = render.current_ceiling;
			render.ceiling_xstart = ft_min(render.xstart, sector.xmin[y]);
			render.ceiling_xend = render.current_ceiling;
			if (render.neighbor)
				env->sectors[sector.neighbors[render.i]].xmin[y] = ft_max(render.current_ceiling, render.xstart);
		}
		else if (v1.floor_range > 0 && y > v1.f1)
		{
			render.wall_xstart = render.current_floor;
			render.floor_xstart = ft_min(render.xstart, sector.xmin[y]);
			render.floor_xend = render.current_floor;
			if (render.neighbor)
				env->sectors[sector.neighbors[render.i]].xmin[y] = ft_max(render.current_floor, render.xstart);
		}
		if (y >= v1.c2 && y <= v1.f2)
		{
			render.wall_xend = render.xend;
		}
		else if (v1.ceiling_range > 0 && y < v1.c2)
		{
			render.wall_xend = render.current_ceiling;
			render.ceiling_xstart = render.current_ceiling;
			render.ceiling_xend = ft_max(render.xend, sector.xmax[y]);
			if (render.neighbor)
				env->sectors[sector.neighbors[render.i]].xmax[y] = ft_min(render.current_ceiling, render.xend);
		}
		else if (v1.floor_range < 0 && y > v1.f2)
		{
			render.wall_xend = render.current_floor;
			render.floor_xstart = render.current_floor;
			render.floor_xend = ft_max(render.xend, sector.xmax[y]);
			if (render.neighbor)
				env->sectors[sector.neighbors[render.i]].xmax[y] = ft_min(render.current_floor, render.xend);
		}
		if (!env->options.test)
			draw_ceiling2(sector, render, env);
		if (!env->options.test)
			draw_floor2(sector, render, env);
		if (render.neighbor)
		{
			if ((y >= ft_min(ft_min(v1.c1, v1.c2), ft_min(v1.neighbor_c1, v1.neighbor_c2))
						&& y <= ft_max(ft_max(v1.c1, v1.c2), ft_max(v1.neighbor_c1, v1.neighbor_c2)))
					|| (y >= ft_min(ft_min(v1.f1, v1.f2), ft_min(v1.neighbor_f1, v1.neighbor_f2))
						&& y <= ft_max(ft_max(v1.f1, v1.f2), ft_max(v1.neighbor_f1, v1.neighbor_f2))))

			{
				render.neighbor_calpha = (y - v1.neighbor_c1) / v1.neighbor_ceiling_range;
				render.neighbor_falpha = (y - v1.neighbor_f1) / v1.neighbor_floor_range;
				render.neighbor_current_ceiling = render.neighbor_calpha * v1.clipped_xrange + v1.clipped_x1;
				render.neighbor_current_floor = render.neighbor_falpha * v1.clipped_xrange + v1.clipped_x1;
				//Top wall
				if (y >= ft_min(ft_min(v1.c1, v1.c2), ft_min(v1.neighbor_c1, v1.neighbor_c2))
						&& y <= ft_max(ft_max(v1.c1, v1.c2), ft_max(v1.neighbor_c1, v1.neighbor_c2)))
				{
					if (y > v1.c1 && y < v1.neighbor_c1)
					{
						render.wall_xstart = render.xstart;
					}
					else if (v1.neighbor_ceiling_range > 0 && y >= v1.neighbor_c1 && y <= v1.neighbor_c2)
					{
						if (v1.ceiling_range > 0)
							render.wall_xstart = render.neighbor_current_ceiling;
						else
							render.wall_xstart = ft_fmax(render.neighbor_current_ceiling,
									render.current_ceiling);
						if (y >= render.neighbor_ceiling_ystart && y <= render.neighbor_ceiling_yend
								&& render.wall_xend - render.wall_xstart >= 1)
							env->sectors[sector.neighbors[render.i]].xmax[y] = render.wall_xstart;
					}
					if (y > v1.c2 && y < v1.neighbor_c2)
					{
						render.wall_xend = render.xend;
					}
					else if (v1.neighbor_ceiling_range < 0 && y >= v1.neighbor_c2 && y <= v1.neighbor_c1)
					{
						if (v1.ceiling_range < 0)
							render.wall_xend = render.neighbor_current_ceiling;
						else
							render.wall_xend = ft_fmin(render.neighbor_current_ceiling,
									render.current_ceiling);
						if (y >= render.neighbor_ceiling_ystart && y <= render.neighbor_ceiling_yend
								&& render.wall_xend - render.wall_xstart >= 1)
							env->sectors[sector.neighbors[render.i]].xmin[y] = render.wall_xend;
					}
					if (y >= render.neighbor_ceiling_ystart && y <= render.neighbor_ceiling_yend
							&& render.wall_xend - render.wall_xstart >= 1)
						draw_wall2(sector, render, env);
				}
				//Bottom wall
				if (y > ft_min(ft_min(v1.f1, v1.f2), ft_min(v1.neighbor_f1, v1.neighbor_f2))
						&& y <= ft_max(ft_max(v1.f1, v1.f2), ft_max(v1.neighbor_f1, v1.neighbor_f2)))
				{
					if (y >= v1.neighbor_f1 && y <= v1.f1)
					{
						render.wall_xstart = render.xstart;
					}
					else if (v1.neighbor_floor_range < 0 && y < v1.neighbor_f1 && y > v1.neighbor_f2)
					{
						if (v1.floor_range < 0)
							render.wall_xstart = render.neighbor_current_floor;
						else
							render.wall_xstart = ft_fmax(render.neighbor_current_floor,
									render.current_floor);
						if (y > render.neighbor_floor_ystart && y < render.neighbor_floor_yend
								&& render.wall_xend - render.wall_xstart >= 1)
							env->sectors[sector.neighbors[render.i]].xmax[y] = render.wall_xstart;
					}
					if (y >= v1.neighbor_f2 && y <= v1.f2)
					{
						render.wall_xend = render.xend;
					}
					else if (v1.neighbor_floor_range > 0 && y < v1.neighbor_f2 && y > v1.neighbor_f1)
					{
						if (v1.floor_range > 0)
							render.wall_xend = render.neighbor_current_floor;
						else
							render.wall_xend = ft_fmin(render.neighbor_current_floor,
									render.current_floor);
						if (y > render.neighbor_floor_ystart && y < render.neighbor_floor_yend
								&& render.wall_xend - render.wall_xstart >= 1)
							env->sectors[sector.neighbors[render.i]].xmin[y] = render.wall_xend;
					}
					if (y > render.neighbor_floor_ystart && y < render.neighbor_floor_yend
							&& render.wall_xend - render.wall_xstart >= 1)
					{
						draw_wall2(sector, render, env);
					}
				}
			}
		}
		else
		{
			//if (!env->options.test)
			draw_wall2(sector, render, env);
		}
	}
	return (NULL);
}

/*
 **	We get floor and ceiling at xstart and xend
 **	so we can not draw out of this range
 */

void	set_yrange(t_render_vertex v1, t_render *render, t_env *env)
{
	int	ymin;
	int	ymax;
	int	nymin;
	int	nymax;

	(void)env;
	render->neighbor_ceiling_ystart = ft_min(v1.c1, v1.c2);
	render->neighbor_ceiling_yend = ft_max(v1.neighbor_c1, v1.neighbor_c2);
	render->neighbor_floor_ystart = ft_min(v1.neighbor_f1, v1.neighbor_f2);
	render->neighbor_floor_yend = ft_max(v1.f1, v1.f2);
	ymin = ft_min(v1.c1, v1.c2);
	ymax = ft_max(v1.f1, v1.f2);
	nymin = ft_min(v1.neighbor_c1, v1.neighbor_c2);
	nymax = ft_max(v1.neighbor_f1, v1.neighbor_f2);
}

void	threaded_wall_loop2(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	t_render_thread		rt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = -1;
	while (++i < THREADS)
	{
		rt[i].env = env;
		rt[i].v1 = v1;
		rt[i].sector = sector;
		rt[i].render = render;
		rt[i].ystart = render.ystart + (render.yend - render.ystart)
			/ (double)THREADS * i;
		rt[i].yend = render.ystart + (render.yend - render.ystart)
			/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, &wall_loop2, &rt[i]) != 0)
			return ;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

void	render_sector2(t_render render, t_env *env)
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
	while (++i < sector.nb_vertices)
	{
		if (!render.camera->v[sector.num][i].draw)
			continue;
		v1 = render.camera->v[sector.num][i];
		if (v1.clipped_x1 >= v1.clipped_x2 || v1.clipped_x1 > render.xmax
				|| v1.clipped_x2 < render.xmin)
			continue;
		render.i = i;
		render.neighbor = 0;
		render.xstart = ft_max(v1.clipped_x1, render.xmin);
		render.xend = ft_min(v1.clipped_x2, render.xmax);
		if (sector.neighbors[i] != -1)
		{
			set_yrange(v1, &render, env);
			render.neighbor = 1;
		}
		//set_yrange(v1, &render, env);
		/*render.ystart = 0;
		  render.yend = env->h - 1;*/
		render.texture_scale = render.camera->v[render.sector]
			[render.i].texture_scale;
		render.ceiling_horizon = v1.ceiling_horizon;
		render.floor_horizon = v1.floor_horizon;
		render.texture = sector.textures[i];
		//get_wall_heights(v1, sector, render, env);
		get_vline_data(v1, sector, render, env);
		threaded_wall_loop2(v1, sector, render, env);
		if (env->options.contouring)
		{
			draw_line_free(new_point(render.xstart, render.ystart),
					new_point(render.xstart, render.yend), *env, 0xFFFF0000);
			draw_line_free(new_point(render.xend, render.ystart),
					new_point(render.xend, render.yend), *env, 0xFFFF0000);
			draw_line_free(new_point(render.xstart, render.ystart),
					new_point(render.xend, render.ystart), *env, 0xFFFF0000);
			draw_line_free(new_point(render.xstart, render.yend),
					new_point(render.xend, render.yend), *env, 0xFFFF0000);
		}
		if (render.neighbor)
		{
			new = render;
			new.ystart = ft_max(ft_min(ft_min(v1.c1, v1.c2), render.neighbor_ceiling_ystart), render.ystart);
			//new.yend = ft_min(ft_min(ft_min(v1.f1, v1.f2), ft_max(v1.neighbor_f1, v1.neighbor_f2)), render.yend);
			new.ystart = ft_min(v1.c1, v1.c2);
			if (ft_min(v1.neighbor_c1, v1.neighbor_c2) > ft_min(v1.c1, v1.c2))
				new.ystart = ft_min(v1.neighbor_c1, v1.neighbor_c2);
			else
				new.ystart = ft_min(v1.c1, v1.c2);
			new.yend = ft_max(v1.f1, v1.f2);
			if (ft_max(v1.neighbor_f1, v1.neighbor_f2) < ft_max(v1.f1, v1.f2))
				new.yend = ft_max(v1.neighbor_f1, v1.neighbor_f2);
			else
				new.yend = ft_max(v1.f1, v1.f2);
			new.ystart = ft_max(new.ystart, render.ystart);
			new.yend = ft_min(new.yend, render.yend);
			new.xmin = render.xstart;
			new.xmax = render.xend;
			new.sector = sector.neighbors[i];
			if (env->options.show_fps)
				render_sector2(new, env);
		}
	}
	reset_x_restrictions(&env->sectors[render.sector], env);
	render.camera->rendered_sectors[render.sector]--;
}
