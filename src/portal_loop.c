/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:23:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	colorize_portal(t_render *render, t_env *env)
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

void	render_vline(t_sector *sector, t_render *render, t_env *env)
{
	render->alpha = (render->x - render->v1->x) / render->v1->xrange;
	render->clipped_alpha = (render->x - render->v1->clipped_x1)
	/ render->v1->clipped_xrange;
	render->divider = 1 / (render->camera->v[sector->num][render->i + 1].vz
		+ render->alpha * render->v1->zrange);
	render->z = render->v1->zcomb * render->divider;
	render->z_near_z = render->z * render->camera->near_z;
	render->max_ceiling = render->clipped_alpha * render->v1->ceiling_range
	+ render->v1->c1;
	render->current_ceiling = ft_clamp(render->max_ceiling,
			env->ymin[render->x], env->ymax[render->x]);
	render->max_floor = render->clipped_alpha * render->v1->floor_range
	+ render->v1->f1;
	render->current_floor = ft_clamp(render->max_floor,
			env->ymin[render->x], env->ymax[render->x]);
	render->no_slope_current_floor = render->clipped_alpha
		* render->v1->no_slope_floor_range + render->v1->no_slope_f1;
	render->no_slope_current_ceiling = render->clipped_alpha
		* render->v1->no_slope_ceiling_range + render->v1->no_slope_c1;
	render->line_height = (render->no_slope_current_floor
			- render->no_slope_current_ceiling);
}

void	*portal_loop(void *param)
{
	t_sector		*sector;
	t_render		render;
	t_env			*env;
	int				x;
	int				xend;

	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	while (x <= xend)
	{
		render.x = x;
		render_vline(sector, &render, env);
		colorize_portal(&render, env);
		x++;
	}
	return (NULL);
}

void	check_mouse(t_render *render, t_env *env)
{
	int		start;
	int		end;

	start = (int)render->current_ceiling;
	end = (int)render->current_floor;
	while (start <= end)
	{
		if ((env->editor.tab && render->x == env->sdl.mx
			&& start == env->sdl.my)
			|| (!env->editor.tab && render->x == env->h_w
			&& start == env->h_h))
		{
			reset_selection(env);
			env->editor.selected_sector = render->sector->num;
			env->editor.selected_wall = render->i;
			env->selected_wall1 =
			env->sectors[render->sector->num].vertices[render->i];
			env->selected_wall2 =
			env->sectors[render->sector->num].vertices[render->i + 1];
			tabs_gestion(env);
		}
		start++;
	}
}

void	*select_portal_loop(void *param)
{
	t_sector		*sector;
	t_render		render;
	t_env			*env;
	int				x;
	int				xend;

	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	while (x <= xend)
	{
		render.x = x;
		render_vline(sector, &render, env);
		check_mouse(&render, env);
		x++;
	}
	return (NULL);
}
