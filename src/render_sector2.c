/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:35:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:35:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_floor_and_ceiling(t_sector *sector, t_render *render,
t_env *env)
{
	if (render->current_ceiling > env->ymin[render->x])
	{
		render->ceiling_height = render->max_ceiling
		- render->camera->head_y[sector->num];
		if (sector->ceiling_sprites.nb_sprites > 0)
			draw_ceiling_sprites(sector, render, env);
		draw_ceiling(sector, render, env);
	}
	if (render->current_floor < env->ymax[render->x])
	{
		render->floor_height = render->camera->feet_y[sector->num]
		- render->max_floor;
		if (sector->floor_sprites.nb_sprites > 0)
			draw_floor_sprites(sector, render, env);
		draw_floor(sector, render, env);
	}
}

void	precompute_texels(t_render *render)
{
	render->texel.x = (render->v1->x0z1 + render->alpha
	* render->v1->xzrange) * render->divider;
	render->texel.y = (render->v1->y0z1 + render->alpha
	* render->v1->yzrange) * render->divider;
	render->texel_x_near_z = render->texel.x * render->camera->near_z;
	render->texel_y_near_z = render->texel.y * render->camera->near_z;
	render->camera_x_z = render->camera->pos.x * render->z;
	render->camera_y_z = render->camera->pos.y * render->z;
	render->texel_x_camera_range = render->camera_x_z
		- render->texel_x_near_z;
	render->texel_y_camera_range = render->camera_y_z
		- render->texel_y_near_z;
	render->zrange = render->z - render->camera->near_z;
}

void	set_new_screen_limits(t_render *render, t_env *env)
{
	env->ymin[render->x] = ft_clamp(ft_max(render->neighbor_current_ceiling,
	render->current_ceiling), env->ymin[render->x], env->ymax[render->x]);
	env->ymax[render->x] = ft_clamp(ft_min(render->neighbor_current_floor,
	render->current_floor), env->ymin[render->x], env->ymax[render->x]);
}

void	draw_bottom_and_upper_walls(t_sector *sector, t_render *render,
t_env *env)
{
	render->neighbor_max_ceiling = render->clipped_alpha
		* render->v1->neighbor_ceiling_range + render->v1->neighbor_c1;
	render->neighbor_max_floor = render->clipped_alpha
		* render->v1->neighbor_floor_range + render->v1->neighbor_f1;
	render->neighbor_current_ceiling = ft_clamp(
	render->neighbor_max_ceiling, env->ymin[render->x], env->ymax[render->x]);
	render->neighbor_current_floor = ft_clamp(
		render->neighbor_max_floor, env->ymin[render->x], env->ymax[render->x]);
	if (render->neighbor_current_ceiling > render->current_ceiling)
	{
		if (sector->textures[render->i] < 0)
			draw_skybox(render, UPPER_WALL, env);
		else
			draw_upper_wall(sector, render, env);
	}
	if (render->neighbor_current_floor < render->current_floor)
	{
		if (sector->textures[render->i] < 0)
			draw_skybox(render, BOTTOM_WALL, env);
		else
			draw_bottom_wall(sector, render, env);
	}
	set_new_screen_limits(render, env);
}

void	compute_vline_data(t_sector *sector, t_render *render,
t_env *env)
{
	render->alpha = (render->x - render->v1->x) / render->v1->xrange;
	render->clipped_alpha =
	(render->x - render->v1->clipped_x1) / render->v1->clipped_xrange;
	render->divider = 1 / (render->camera->v[sector->num][render->i + 1].vz
				+ render->alpha * render->v1->zrange);
	render->z = render->v1->zcomb * render->divider;
	render->z_near_z = render->z * render->camera->near_z;
	render->max_ceiling =
	render->clipped_alpha * render->v1->ceiling_range + render->v1->c1;
	render->current_ceiling = ft_clamp(render->max_ceiling,
			env->ymin[render->x], env->ymax[render->x]);
	render->max_floor =
	render->clipped_alpha * render->v1->floor_range + render->v1->f1;
	render->current_floor = ft_clamp(render->max_floor,
			env->ymin[render->x], env->ymax[render->x]);
	render->no_slope_current_floor = render->clipped_alpha
		* render->v1->no_slope_floor_range + render->v1->no_slope_f1;
	render->no_slope_current_ceiling = render->clipped_alpha
		* render->v1->no_slope_ceiling_range + render->v1->no_slope_c1;
	render->line_height = (render->no_slope_current_floor
		- render->no_slope_current_ceiling);
	render->ceiling_start = render->max_ceiling - render->ceiling_horizon;
	render->floor_start = render->max_floor - render->floor_horizon;
}
