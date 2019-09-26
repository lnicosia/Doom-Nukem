/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrict_portals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:02:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/26 17:37:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		restrict_ceiling(t_render_vertex v1, t_render *render,
		t_sector sector, t_env *env)
{
	if (v1.ceiling_range > 0)
	{
		if (v1.neighbor_ceiling_range > 0)
		{
			if (ft_max(v1.neighbor_c1, v1.neighbor_c2) < ft_max(v1.c1, v1.c2))
				env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->ceiling_xstart;
			else
				env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->neighbor_current_ceiling;
		}
		else
		{
				//env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->ceiling_xend;
				//env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->neighbor_current_ceiling;
		}
	}
	else
	{
		if (v1.neighbor_ceiling_range > 0)
		{
		}
		else
		{
			if (ft_max(v1.neighbor_c1, v1.neighbor_c2) < ft_max(v1.c1, v1.c2))
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->ceiling_xend;
			else
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->neighbor_current_ceiling;
		}
	}
}

void		restrict_floor(t_render_vertex v1, t_render *render,
		t_sector sector, t_env *env)
{
	if (v1.floor_range > 0)
	{
		if (v1.neighbor_floor_range > 0)
		{
			if (ft_min(v1.neighbor_f1, v1.neighbor_f2) > ft_min(v1.f1, v1.f2))
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->floor_xend;
			else
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->neighbor_current_floor;
		}
		else
		{
		}
	}
	else
	{
		if (v1.neighbor_floor_range > 0)
		{
		}
		else
		{
			if (ft_min(v1.neighbor_f1, v1.neighbor_f2) > ft_min(v1.f1, v1.f2))
				env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->floor_xstart;
			else
				env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->neighbor_current_floor;
		}
	}
}
