/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:09:18 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/11 15:32:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"
#include "render2.h"

void	skybox_loop(t_render_vertex v1, t_render_vertex v2, t_render2 render,
		t_env *env)
{
	t_render2	skybox;
	t_vline		vline;
	int			x;

	x = render.x;
	skybox.alpha = (x - v1.x) / v1.xrange;
	skybox.clipped_alpha = (x - v1.clipped_x1) / v1.clipped_xrange;
	skybox.z = 1.0 / ((1.0 - skybox.alpha) / v1.vz
			+ skybox.alpha / v2.vz);
	skybox.clipped_z = 1.0 / ((1.0 - skybox.clipped_alpha)
			/ v1.clipped_vz1 + skybox.clipped_alpha / v1.clipped_vz2);
	skybox.texel.x = ((1.0 - skybox.alpha) * v1.xz
			+ skybox.alpha * v2.xz) * skybox.z;
	skybox.texel.y = ((1.0 - skybox.alpha) * v1.yz
			+ skybox.alpha * v2.yz) * skybox.z;
	skybox.max_ceiling = skybox.clipped_alpha * v1.ceiling_range + v1.c1;
	skybox.current_ceiling = ft_clamp(skybox.max_ceiling,
			env->ymin[x], env->ymax[x]);
	skybox.max_floor = skybox.clipped_alpha * v1.floor_range + v1.f1;
	skybox.current_floor = ft_clamp(skybox.max_floor,
			env->ymin[x], env->ymax[x]);
	skybox.line_height = skybox.max_floor - skybox.max_ceiling;
	skybox.ceiling_start = skybox.max_ceiling - v1.ceiling_horizon;
	skybox.floor_start = skybox.max_floor - v1.floor_horizon;
	vline.x = x;
	if (env->ymin[x] < render.current_ceiling)
	{
		vline.start = env->ymin[x];
		vline.end = ft_min(skybox.current_ceiling, render.current_ceiling);
		//draw_skybox_ceiling(vline, skybox, env);
	}
	if (skybox.current_ceiling < render.current_ceiling)
	{
		vline.start = skybox.current_ceiling;
		vline.end = ft_min(skybox.current_floor, render.current_ceiling);
		//draw_skybox_wall(vline, skybox, env);
	}
	/*if (skybox.current_floor < render.current_ceiling)
	{
		vline.start = env->ymin[x];
		vline.end = ft_min(skybox.current_ceiling, render.current_ceiling);
		draw_skybox_floor(vline, skybox, env);
	}*/
}

void	draw_skybox2(t_render2 render, t_env *env)
{
	int				i;
	t_render_vertex	v1;
	t_render_vertex	v2;

	i = -1;
	while (++i < 4 && env->skybox[i].draw)
	{
		v1 = env->skybox[i];
		v2 = env->skybox[i + 1];
		if (v1.x >= v2.x || render.x < v1.x || render.x > v2.x)
			continue;
		skybox_loop(v1, v2, render, env);
	}
}
