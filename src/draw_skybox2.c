/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:53:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/30 17:13:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	skybox_loop2(t_render skybox, t_skybox_data wall_data,
		t_render render, t_env *env)
{
	t_render_vertex	v1;
	int				y;

	v1 = env->skybox[skybox.i];
	y = render.y;
	if ((!wall_data.mode && env->selected_ceiling == render.sector)
			|| (wall_data.mode && env->sectors[render.sector].selected[render.i]))
		skybox.selected = 1;
}

void	draw_skybox2(t_render render, int mode, t_env *env)
{
	int				i;
	t_render		skybox;
	t_skybox_data	wall_data;

	i = -1;
	wall_data.mode = mode;
	while (++i < 4)
	{
		if (!env->skybox[i].draw
				|| env->skybox[i].clipped_x1 >= env->skybox[i].clipped_x2)
			continue;
		skybox.i = i;
		skybox.texture = 40 + i;
		skybox.sector = render.sector;
		skybox.selected = 0;
		skybox_loop2(skybox, wall_data, render, env);
	}
}
