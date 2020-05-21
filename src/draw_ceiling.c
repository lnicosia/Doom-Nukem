/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:56:56 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:08:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling(t_sector *sector, t_render *render, t_env *env)
{
	t_vline	vline;

	vline.x = render->x;
	vline.start = env->ymin[vline.x];
	vline.end = ft_min(render->current_ceiling, env->ymax[vline.x]);
	vline.color = 0;
	vline.draw_wall = 0;
	if (sector->ceiling_texture < 0)
		draw_skybox(render, CEILING, env);
	else
	{
		if (!env->options.lighting || (!sector->brightness
			&& !sector->intensity))
			draw_vline_ceiling(sector, vline, render, env);
		else if (!sector->brightness)
			draw_vline_ceiling_color(sector, vline, render, env);
		else if (!sector->intensity)
			draw_vline_ceiling_brightness(sector, vline, render, env);
		else
			draw_vline_ceiling_both(sector, vline, render, env);
	}
}
