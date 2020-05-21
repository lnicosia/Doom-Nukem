/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:09:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/20 12:19:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_skybox.h"

void	draw_skybox_vline(t_skybox_drawer *drawer, t_vline vline, t_env *env)
{
	vline.x = drawer->x;
	if (drawer->min < drawer->skybox->current_ceiling)
	{
		vline.start = drawer->min;
		vline.end = ft_min(drawer->skybox->current_ceiling, drawer->max);
		draw_skybox_ceiling(vline, drawer->wall_data, drawer->skybox, env);
	}
	if (drawer->skybox->current_ceiling < drawer->max)
	{
		vline.start = ft_max(drawer->min, drawer->skybox->current_ceiling);
		vline.end = ft_min(drawer->skybox->current_floor, drawer->max);
		draw_skybox_wall(vline, drawer->wall_data, drawer->skybox, env);
		if ((env->options.zbuffer)
			&& (drawer->x == (int)drawer->v1.x
			|| drawer->x == (int)env->skybox[drawer->skybox->i + 1].x))
			draw_vline_color(vline, env);
	}
	if (drawer->skybox->current_floor < drawer->max)
	{
		vline.start = ft_max(drawer->min, drawer->skybox->current_floor);
		vline.end = drawer->max;
		draw_skybox_floor(vline, drawer->wall_data, drawer->skybox, env);
	}
}

void	skybox_loop(t_render *skybox, t_skybox_data wall_data, t_render *render,
		t_env *env)
{
	t_vline			vline;
	t_skybox_drawer	drawer;

	vline.start = 0;
	vline.end = 0;
	vline.x = 0;
	vline.draw_wall = 0;
	vline.color = 0;
	drawer.v1 = env->skybox[skybox->i];
	drawer.render = render;
	drawer.skybox = skybox;
	drawer.wall_data = wall_data;
	drawer.x = render->x;
	vline.color = 0xFFFF0000;
	set_skybox_limits(&drawer, env);
	compute_skybox_vline(&drawer, env);
	draw_skybox_vline(&drawer, vline, env);
}

void	init_skybox_render(t_render *render, t_render *skybox, t_env *env)
{
	skybox->sector = render->sector;
	skybox->camera = render->camera;
	skybox->zrange = render->zrange;
	skybox->z_near_z = render->z_near_z;
	skybox->ceiling_height = render->ceiling_height;
	skybox->floor_height = render->floor_height;
	skybox->ceiling_horizon = env->player.camera.horizon;
	skybox->floor_horizon = env->player.camera.horizon;
}

void	draw_skybox(t_render *render, int mode, t_env *env)
{
	int				i;
	t_render		skybox;
	t_skybox_data	wall_data;

	i = -1;
	wall_data.mode = mode;
	wall_data.z = render->z;
	wall_data.ceiling_start = render->ceiling_start;
	wall_data.ceiling_horizon = render->ceiling_horizon;
	wall_data.i = render->i;
	wall_data.max_ceiling = render->max_ceiling;
	wall_data.max_floor = render->max_floor;
	init_skybox_render(render, &skybox, env);
	while (++i < 4)
	{
		if (!env->skybox[i].draw
				|| env->skybox[i].clipped_x1 >= env->skybox[i].clipped_x2
				|| env->skybox[i].clipped_x1 > render->x
				|| env->skybox[i].clipped_x2 < render->x)
			continue;
		skybox.texture = 2 + i;
		skybox.i = i;
		skybox.selected = 0;
		skybox_loop(&skybox, wall_data, render, env);
	}
}
