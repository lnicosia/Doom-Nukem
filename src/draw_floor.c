/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:52:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:16:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_floor(t_sector *sector, t_render *render, t_env *env)
{
	t_vline	vline;

	vline.x = render->x;
	vline.start = ft_max(0, (int)(render->current_floor));
	vline.end = env->ymax[vline.x];
	if (sector->floor_texture < 0)
		draw_skybox(render, FLOOR, env);
	else
	{
		if (!env->options.lighting || (!sector->brightness
			&& !sector->intensity))
			draw_vline_floor(sector, vline, render, env);
		else if (!sector->brightness)
			draw_vline_floor_color(sector, vline, render, env);
		else if (!sector->intensity)
			draw_vline_floor_brightness(sector, vline, render, env);
		else
			draw_vline_floor_both(sector, vline, render, env);
	}
}
