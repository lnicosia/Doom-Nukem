/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:55:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/25 17:59:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	wall_loop2(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	int	y;
	int	yend;

	(void)v1;
	(void)sector;
	(void)render;
	(void)env;
	y = render.ystart - 1;
	yend = render.yend;
	while (++y <= yend)
	{
		render.y = y;
		//ft_printf("i = %d y = %d\n", render.i, y);
		//ft_printf("ceiling = %f floor = %f\n", render.current_ceiling, render.current_floor);
		/*if (y < ft_min(v1.c1, v1.c2)
				|| y > ft_max(v1.f1, v1.f2))
			continue;*/
		render.wall_xstart = 0;
		render.wall_xend = 0;
		render.ceiling_xstart = 0;
		render.ceiling_xend = 0;
		render.floor_xstart = 0;
		render.floor_xend = 0;
		render.calpha = (y - v1.c1) / v1.ceiling_range;
		render.falpha = (y - v1.f1) / v1.floor_range;
		//render.current_ceiling = ft_clamp(render.calpha * v1.clipped_xrange + v1.clipped_x1, render.xstart, render.xend);
		render.current_ceiling = render.calpha * v1.clipped_xrange + v1.clipped_x1;
		//render.current_floor = ft_clamp(render.falpha * v1.clipped_xrange + v1.clipped_x1, render.xstart, render.xend);
		render.current_floor = render.falpha * v1.clipped_xrange + v1.clipped_x1;
		//ft_printf("y = %d c1 = %f c2 = %f\nx1 = %f x2 = %f\nwall_xstart = %d\n",
			//	y, v1.c1, v1.c2, v1.clipped_x1, v1.clipped_x2, render.wall_xstart);
		if (y >= v1.c1 && y <= v1.f1)
		{
			render.wall_xstart = render.xstart;
		}
		else if (v1.ceiling_range < 0 && y < v1.c1)
		{
			render.wall_xstart = render.current_ceiling;
			render.ceiling_xstart = render.xstart;
			render.ceiling_xend = render.current_ceiling;
		}
		else if (v1.floor_range > 0 && y > v1.f1)
		{
			render.wall_xstart = render.current_floor;
			render.floor_xstart = render.xstart;
			render.floor_xend = render.current_floor;
		}
		if (y >= v1.c2 && y <= v1.f2)
		{
			render.wall_xend = render.xend;
		}
		else if (v1.ceiling_range > 0 && y < v1.c2)
		{
			render.wall_xend = render.current_ceiling;
			render.ceiling_xstart = render.current_ceiling;
			render.ceiling_xend = render.xend;
		}
		else if (v1.floor_range < 0 && y > v1.f2)
		{
			render.wall_xend = render.current_floor;
			render.floor_xstart = render.current_floor;
			render.floor_xend = render.xend;
		}
		render.wall_xstart = ft_max(render.wall_xstart, render.xstart);
		render.wall_xend = ft_min(render.wall_xend, render.xend);
		render.ceiling_xstart = ft_max(render.ceiling_xstart, render.xstart);
		render.ceiling_xend = ft_min(render.ceiling_xend, render.xend);
		render.floor_xstart = ft_max(render.floor_xstart, render.xstart);
		render.floor_xend = ft_min(render.floor_xend, render.xend);
		if (render.neighbor)
		{
			render.neighbor_calpha = (y - v1.neighbor_c1) / v1.neighbor_ceiling_range;
			render.neighbor_falpha = (y - v1.neighbor_f1) / v1.neighbor_floor_range;
			render.neighbor_current_ceiling = render.neighbor_calpha * v1.clipped_xrange + v1.clipped_x1;
			render.neighbor_current_floor = render.neighbor_falpha * v1.clipped_xrange + v1.clipped_x1;
			/*if ((y >= v1.neighbor_c1 && y <= v1.c1) || (y >= v1.f1 && y <= v1.neighbor_f1))
			{
				render.wall_xstart = render.xstart;
			}
			else if ((v1.neighbor_ceiling_range < 0 && y < v1.c1 && y > v1.neighbor_c1))
			{
				render.wall_xstart = render.neighbor_current_ceiling;
				render.wall_xstart = render.xstart;
				render.wall_xend = render.neighbor_current_ceiling;
			}
			else if ((v1.neighbor_floor_range > 0 && y > v1.neighbor_f1 && y < v1.neighbor_f1))
			{
				render.wall_xstart = render.neighbor_current_floor;
				render.wall_xstart = render.xstart;
				render.wall_xend = render.neighbor_current_floor;
			}
			if ((y >= v1.neighbor_c2 && y <= v1.c2) || (y >= v1.f2 && y <= v1.neighbor_f2))
			{
				render.wall_xend = render.xend;
			}
			else if ((v1.neighbor_ceiling_range > 0 && y < v1.neighbor_c2 && y > v1.neighbor_c2))
			{
				render.wall_xend = render.neighbor_current_ceiling;
				render.wall_xstart = render.neighbor_current_ceiling;
				render.wall_xend = render.xend;
			}
			else if ((v1.neighbor_floor_range < 0 && y > v1.neighbor_f2 && y < v1.neighbor_f2))
			{
				render.wall_xend = render.neighbor_current_floor;
				render.wall_xstart = render.neighbor_current_floor;
				render.wall_xend = render.xend;
			}*/
			if (v1.neighbor_ceiling_range < 0)// && (y > v1.c1 || y > v1.neighbor_c1))
			{
				render.wall_xend = ft_min(render.neighbor_current_ceiling, render.xend);
			}
			else
			{
				render.wall_xstart = ft_max(render.neighbor_current_ceiling, render.xstart);
			}
			draw_wall2(sector, render, env);
			if (v1.neighbor_floor_range > 0)// && (y > v1.c1 || y > v1.neighbor_c1))
			{
				render.wall_xend = ft_min(render.neighbor_current_floor, render.xend);
			}
			else
			{
				render.wall_xstart = ft_max(render.neighbor_current_floor, render.xstart);
			}
			draw_wall2(sector, render, env);
		}
		//ft_printf("xstart = %d\n", render.xstart);
		//ft_printf("xend = %d\n", render.xend);
		//render.alpha = (y - v1.y) / v1.yrange;
		//render.clipped_alpha = (y - v1.clipped_y1) / v1.clipped_yrange;
		draw_floor2(sector, render, env);
		draw_ceiling2(sector, render, env);
		if (!render.neighbor)
		{
			if (!env->options.test)
				draw_wall2(sector, render, env);
		}
		//update_screen(env);
	}
}

/*
**	Computes every data need for each line of the wall
**	but only once for each wall
*/

void	get_wall_heights(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	int	x;

	x = render.xstart;
	while (x <= render.xend)
	{
		env->alpha[x] = (x - v1.x) / v1.xrange;
		env->clipped_alpha[x] = (x - v1.clipped_x1) / v1.clipped_xrange;
		env->divider[x] = 1 / (render.camera->v[sector.num][render.i + 1].vz
				+ env->alpha[x] * v1.zrange);
		env->z[x] = v1.zcomb * env->divider[x];
		env->z_near_z[x] = env->z[x] * render.camera->near_z;
		env->max_ceiling[x] = env->clipped_alpha[x] * v1.ceiling_range + v1.c1;
		env->current_ceiling[x] = ft_clamp(env->max_ceiling[x],
				env->ymin[x], env->ymax[x]);
		env->max_floor[x] = env->clipped_alpha[x] * v1.floor_range + v1.f1;
		env->current_floor[x] = ft_clamp(env->max_floor[x],
				env->ymin[x], env->ymax[x]);
		env->no_slope_current_floor[x] = env->clipped_alpha[x]
			* v1.no_slope_floor_range + v1.no_slope_f1;
		env->no_slope_current_ceiling[x] = env->clipped_alpha[x]
			* v1.no_slope_ceiling_range + v1.no_slope_c1;
		env->line_height[x] = env->no_slope_current_floor[x]
			- env->no_slope_current_ceiling[x];
		env->ceiling_start[x] = env->max_ceiling[x] - render.ceiling_horizon;
		env->floor_start[x] = env->max_floor[x] - render.floor_horizon;
		if (env->current_ceiling[x] > env->ymin[x]
				|| env->current_floor[x] < env->ymax[x])
		{
			env->texel[x].x = (v1.x0z1 + env->alpha[x] * v1.xzrange)
				* env->divider[x];
			env->texel[x].y = (v1.y0z1 + env->alpha[x] * v1.yzrange)
				* env->divider[x];
			env->texel_near_z[x].x = env->texel[x].x * render.camera->near_z;
			env->texel_near_z[x].y = env->texel[x].y * render.camera->near_z;
			env->camera_z[x].x = render.camera->pos.x * env->z[x];
			env->camera_z[x].y = render.camera->pos.y * env->z[x];
			env->texel_camera_range[x].x = env->camera_z[x].x
				- env->texel_near_z[x].x;
			env->texel_camera_range[x].y = env->camera_z[x].y
				- env->texel_near_z[x].y;
			env->zrange[x] = env->z[x] - render.camera->near_z;
		}
		if (render.neighbor)
		{
			env->neighbor_max_ceiling[x] = env->clipped_alpha[x]
				* v1.neighbor_ceiling_range + v1.neighbor_c1;
			env->neighbor_max_floor[x] = env->clipped_alpha[x]
				* v1.neighbor_floor_range + v1.neighbor_f1;
			env->neighbor_current_ceiling[x] = ft_clamp(
					env->neighbor_max_ceiling[x], env->ymin[x], env->ymax[x]);
			env->neighbor_current_floor[x] = ft_clamp(
					env->neighbor_max_floor[x], env->ymin[x], env->ymax[x]);
		}
		x++;
	}
}

/*
**	We get floor and ceiling at xstart and xend
**	so we can not draw out of this range
*/

void	set_yrange(t_render_vertex v1, t_render *render, t_env *env)
{
	/*int	x;
	int	min;
	int	max;

	min = env->h - 1;
	max = 0;
	x = render->xstart;
	while (x <= render->xend)
	{
		env->ymin[x] = ft_clamp(ft_max(env->neighbor_current_ceiling[x],
					env->current_ceiling[x]), env->ymin[x], env->ymax[x]);
		if (min > env->ymin[x])
			min = env->ymin[x];
		env->ymax[x] = ft_clamp(ft_min(env->neighbor_current_floor[x],
					env->current_floor[x]), env->ymin[x], env->ymax[x]);
		if (max < env->ymax[x])
			max = env->ymax[x];
		x++;
	}
	render->ystart = min;
	render->yend = max;*/
	int	ymin;
	int	ymax;
	int	nymin;
	int	nymax;

	ymin = ft_min(v1.c1, v1.c2);
	ymax = ft_max(v1.f1, v1.f2);
	nymin = ft_min(v1.neighbor_c1, v1.neighbor_c2);
	nymax = ft_max(v1.neighbor_f1, v1.neighbor_f2);
	render->ystart = ft_max(ft_max(ymin, nymin), 0);
	render->yend = ft_min(ft_min(ymax, nymax), env->h - 1);
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
		if (sector.neighbors[i] != -1)
			render.neighbor = 1;
		render.xstart = ft_max(v1.clipped_x1, render.xmin);
		render.xend = ft_min(v1.clipped_x2, render.xmax);
		//set_yrange(v1, &render, env);
		/*render.ystart = 0;
		render.yend = env->h - 1;*/
		//get_wall_heights(v1, sector, render, env);
		render.ceiling_horizon = v1.ceiling_horizon;
		render.floor_horizon = v1.floor_horizon;
		render.texture = sector.textures[i];
		wall_loop2(v1, sector, render, env);
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
			new.xmin = render.xstart;
			new.xmax = render.xend;
			new.sector = sector.neighbors[i];
			set_yrange(v1, &new, env);
			render_sector2(new, env);
		}
	}
	render.camera->rendered_sectors[render.sector]--;
}
