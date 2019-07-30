/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:52:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 15:47:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_vertices(t_env *env)
{
	int			i;
	t_vertex	vertex;
	t_point		center;
	double		scale;
	Uint32		color;

	i = 0;
	while (i < env->nb_vertices)
	{
		vertex = env->vertices[i];
		center = new_point(env->editor.center.x + vertex.x * env->editor.scale,
				env->editor.center.y + vertex.y * env->editor.scale);
		if (env->sdl.mx > center.x - env->editor.scale / 5.0
				&& env->sdl.mx < center.x + env->editor.scale / 5.0
				&& env->sdl.my > center.y - env->editor.scale / 5.0
				&& env->sdl.my < center.y + env->editor.scale / 5.0)
		{
			scale = env->editor.scale / 3.5;
			color = 0xFF00FF00;
		}
		else
		{
			scale = env->editor.scale / 5.0;
			color = 0xFFFF0000;
		}
		if (center.x - scale >= 0 && center.x + scale < env->w
				&& center.y - scale >= 0 && center.y + scale < env->h)
			draw_circle(new_circle(color,
						color,
						center,
						scale), env);
		i++;
	}
}
