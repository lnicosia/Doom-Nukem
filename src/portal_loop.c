/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 14:48:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void    colorize_portal(t_render *render, t_env *env)
{
	int		coord;
	int		start;
	int		end;
	Uint32	*pixels;
	
	pixels = env->sdl.texture_pixels;
	start = (int)render->current_ceiling;
	end = (int)render->current_floor;
	while (start < end)
	{
		coord = render->x + env->w * start;
		pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
		start++;
	}
}

void            *portal_loop(void *param)
{
	t_render_vertex	v1;
	t_sector		*sector;
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
		render.divider = 1 / (render.camera->v[sector->num][render.i + 1].vz
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
		render.line_height = (render.no_slope_current_floor
				- render.no_slope_current_ceiling);
		colorize_portal(&render, env);
		x++;
	}
	return (NULL);
}

void    check_mouse(t_render render, t_env *env)
{
	int		start;
	int		end;
	
	start = (int)render.current_ceiling;
	end = (int)render.current_floor;
	while (start <= end)
	{
		if ((env->editor.tab && render.x == env->sdl.mx && start == env->sdl.my)
			|| (!env->editor.tab && render.x == env->h_w && start == env->h_h))
		{
			reset_selection(env);
			env->editor.selected_sector = render.sector;
			env->editor.selected_wall = render.i;
			env->selected_wall1 =
			env->sectors[render.sector].vertices[render.i];
			env->selected_wall2 =
			env->sectors[render.sector].vertices[render.i + 1];
			tabs_gestion(env);
		}
		start++;
	}
}

void            *select_portal_loop(void *param)
{
	t_render_vertex	v1;
	t_sector		*sector;
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
		render.divider = 1 / (render.camera->v[sector->num][render.i + 1].vz
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
		render.line_height = (render.no_slope_current_floor
				- render.no_slope_current_ceiling);
		check_mouse(render, env);
		x++;
	}
	return (NULL);
}
