/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vline_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:47:26 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/30 15:25:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	get_vline_data(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	int	x;
	int	texture_w;
	int	texture_h;

	(void)sector;
	x = render.xstart;
	texture_w = env->textures[render.texture].surface->w;
	texture_h = env->textures[render.texture].surface->h;
	while (x <= render.xend)
	{
		env->vline_data[x].alpha = (x - v1.x) / v1.xrange;
		env->vline_data[x].clipped_alpha = (x - v1.clipped_x1) / v1.clipped_xrange;
		env->vline_data[x].max_ceiling = env->vline_data[x].clipped_alpha * v1.ceiling_range + v1.c1;
		env->vline_data[x].current_ceiling = ft_clamp(env->vline_data[x].max_ceiling,
				env->ymin[x], env->ymax[x]);
		env->vline_data[x].max_floor = env->vline_data[x].clipped_alpha * v1.floor_range + v1.f1;
		env->vline_data[x].current_floor = ft_clamp(env->vline_data[x].max_floor,
				env->ymin[x], env->ymax[x]);
		env->vline_data[x].divider = 1 / (render.camera->v[sector.num][render.i + 1].vz
				+ env->vline_data[x].alpha * v1.zrange);
		env->vline_data[x].z = v1.zcomb * env->vline_data[x].divider;
		env->vline_data[x].z_near_z = env->vline_data[x].z * render.camera->near_z;
		env->vline_data[x].no_slope_current_floor = env->vline_data[x].clipped_alpha
			* v1.no_slope_floor_range + v1.no_slope_f1;
		env->vline_data[x].no_slope_current_ceiling = env->vline_data[x].clipped_alpha
			* v1.no_slope_ceiling_range + v1.no_slope_c1;
		env->vline_data[x].inv_line_height = 1 / (env->vline_data[x].no_slope_current_floor - env->vline_data[x].no_slope_current_ceiling);
		env->vline_data[x].ceiling_start = env->vline_data[x].max_ceiling - render.ceiling_horizon;
		env->vline_data[x].floor_start = env->vline_data[x].max_floor - render.floor_horizon;
		env->vline_data[x].wall_texel = env->vline_data[x].alpha * render.texture_scale.x
			* env->vline_data[x].z + sector.align[render.i].x;
		env->vline_data[x].falpha_divider = 1 / (render.camera->feet_y[render.sector] - env->vline_data[x].max_floor);
		env->vline_data[x].calpha_divider = 1 / (env->vline_data[x].max_ceiling - render.camera->head_y[render.sector]);
		if (!(env->vline_data[x].wall_texel != env->vline_data[x].wall_texel))
		{
			while (env->vline_data[x].wall_texel >= texture_w)
				env->vline_data[x].wall_texel -= texture_w;
			while (env->vline_data[x].wall_texel < 0)
				env->vline_data[x].wall_texel += texture_w;
		}
		if (env->vline_data[x].current_ceiling > env->ymin[x]
				|| env->vline_data[x].current_floor < env->ymax[x])
		{
			env->vline_data[x].texel.x = (v1.x0z1 + env->vline_data[x].alpha * v1.xzrange)
				* env->vline_data[x].divider;
			env->vline_data[x].texel.y = (v1.y0z1 + env->vline_data[x].alpha * v1.yzrange)
				* env->vline_data[x].divider;
			env->vline_data[x].texel_near_z.x = env->vline_data[x].texel.x * render.camera->near_z;
			env->vline_data[x].texel_near_z.y = env->vline_data[x].texel.y * render.camera->near_z;
			env->vline_data[x].camera_z.x = render.camera->pos.x * env->vline_data[x].z;
			env->vline_data[x].camera_z.y = render.camera->pos.y * env->vline_data[x].z;
			env->vline_data[x].texel_camera_range.x = env->vline_data[x].camera_z.x
				- env->vline_data[x].texel_near_z.x;
			env->vline_data[x].texel_camera_range.y = env->vline_data[x].camera_z.y
				- env->vline_data[x].texel_near_z.y;
			env->vline_data[x].zrange = env->vline_data[x].z - render.camera->near_z;
		}
		x++;
	}
}

/*void	*get_vline_data_loop(void *param)
{
	int				x;
	int				xend;
	int				texture_w;
	int				texture_h;
	t_render_vertex	v1;
	t_render		render;
	t_sector		sector;
	t_env			*env;

	env = ((t_render_thread*)param)->env;
	render = ((t_render_thread*)param)->render;
	sector = ((t_render_thread*)param)->sector;
	v1 = ((t_render_thread*)param)->v1;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	x = render.xstart;
	texture_w = env->textures[render.texture].surface->w;
	texture_h = env->textures[render.texture].surface->h;
	while (x <= xend)
	{
		env->vline_data[x].alpha = (x - v1.x) / v1.xrange;
		env->vline_data[x].clipped_alpha = (x - v1.clipped_x1) / v1.clipped_xrange;
		env->vline_data[x].max_ceiling = env->vline_data[x].clipped_alpha * v1.ceiling_range + v1.c1;
		env->vline_data[x].current_ceiling = ft_clamp(env->vline_data[x].max_ceiling,
				env->ymin[x], env->ymax[x]);
		env->vline_data[x].max_floor = env->vline_data[x].clipped_alpha * v1.floor_range + v1.f1;
		env->vline_data[x].current_floor = ft_clamp(env->vline_data[x].max_floor,
				env->ymin[x], env->ymax[x]);
		env->vline_data[x].divider = 1 / (render.camera->v[sector.num][render.i + 1].vz
				+ env->vline_data[x].alpha * v1.zrange);
		env->vline_data[x].z = v1.zcomb * env->vline_data[x].divider;
		env->vline_data[x].z_near_z = env->vline_data[x].z * render.camera->near_z;
		env->vline_data[x].no_slope_current_floor = env->vline_data[x].clipped_alpha
			* v1.no_slope_floor_range + v1.no_slope_f1;
		env->vline_data[x].no_slope_current_ceiling = env->vline_data[x].clipped_alpha
			* v1.no_slope_ceiling_range + v1.no_slope_c1;
		env->vline_data[x].inv_line_height = 1 / (env->vline_data[x].no_slope_current_floor - env->vline_data[x].no_slope_current_ceiling);
		env->vline_data[x].ceiling_start = env->vline_data[x].max_ceiling - render.ceiling_horizon;
		env->vline_data[x].floor_start = env->vline_data[x].max_floor - render.floor_horizon;
		env->vline_data[x].wall_texel = env->vline_data[x].alpha * render.texture_scale.x
			* env->vline_data[x].z + sector.align[render.i].x;
		env->vline_data[x].falpha_divider = 1 / (render.camera->feet_y[render.sector] - env->vline_data[x].max_floor);
		env->vline_data[x].calpha_divider = 1 / (env->vline_data[x].max_ceiling - render.camera->head_y[render.sector]);
		if (!(env->vline_data[x].wall_texel != env->vline_data[x].wall_texel))
		{
			while (env->vline_data[x].wall_texel >= texture_w)
				env->vline_data[x].wall_texel -= texture_w;
			while (env->vline_data[x].wall_texel < 0)
				env->vline_data[x].wall_texel += texture_w;
		}
		if (env->vline_data[x].current_ceiling > env->ymin[x]
				|| env->vline_data[x].current_floor < env->ymax[x])
		{
			env->vline_data[x].texel.x = (v1.x0z1 + env->vline_data[x].alpha * v1.xzrange)
				* env->vline_data[x].divider;
			env->vline_data[x].texel.y = (v1.y0z1 + env->vline_data[x].alpha * v1.yzrange)
				* env->vline_data[x].divider;
			env->vline_data[x].texel_near_z.x = env->vline_data[x].texel.x * render.camera->near_z;
			env->vline_data[x].texel_near_z.y = env->vline_data[x].texel.y * render.camera->near_z;
			env->vline_data[x].camera_z.x = render.camera->pos.x * env->vline_data[x].z;
			env->vline_data[x].camera_z.y = render.camera->pos.y * env->vline_data[x].z;
			env->vline_data[x].texel_camera_range.x = env->vline_data[x].camera_z.x
				- env->vline_data[x].texel_near_z.x;
			env->vline_data[x].texel_camera_range.y = env->vline_data[x].camera_z.y
				- env->vline_data[x].texel_near_z.y;
			env->vline_data[x].zrange = env->vline_data[x].z - render.camera->near_z;
		}
		x++;
	}
	return (NULL);
}

void	get_vline_data(t_render_vertex v1, t_sector sector,
		t_render render, t_env *env)
{
	t_render_thread		rt[1];
	pthread_t			threads[1];
	int					i;

	i = -1;
	while (++i < 1)
	{
		rt[i].v1 = v1;
		rt[i].env = env;
		rt[i].render = render;
		rt[i].sector = sector;
		rt[i].xstart = render.xstart + (render.xend - render.xstart)
			/ (double)1 * i;
		rt[i].xend = render.xstart + (render.xend - render.xstart)
			/ (double)1 * (i + 1);
		if (pthread_create(&threads[i], NULL, &get_vline_data_loop, &rt[i]) != 0)
			return ;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}*/
