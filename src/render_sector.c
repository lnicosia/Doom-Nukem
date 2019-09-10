/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 15:35:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

void		render_sector2(t_render2 render, t_env *env)
{
	int				i;
	t_sector		sector;
	t_render_vertex	v1;
	t_render_vertex	v2;
	
	i = -1;
	sector = env->sectors[render.sector];
	while (++i < sector.nb_vertices && sector.v[i].draw)
	{
		v1 = sector.v[i];
		v2 = sector.v[i + 1];
		if (v1.x >= v2.x || v1.x > render.xmax || v2.x < render.xmin)
			continue;
		render.xstart = ft_max(v1.x, render.xmin);
		render.xend = ft_min(v2.x, render.xmax);
	}
}
