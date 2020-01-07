/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrict_portals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:02:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 12:30:32 by lnicosia         ###   ########.fr       */
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
	/*if (v1.floor_range > 0)
	{
		if (v1.neighbor_floor_range > 0)
		{
			if (ft_min(v1.neighbor_f1, v1.neighbor_f2) > ft_min(v1.f1, v1.f2))
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->floor_xend;
			else
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->neighbor_current_floor;
			if (
		}
		else
		{
				env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->floor_xend;
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
	}*/
	(void)v1;
	(void)env;
	(void)sector;
	(void)render;
	/*if (render->floor_xstart > render->xstart
			&& render->floor_xstart < render->xend)
	{
		if (render->wall_xstart > render->xstart
				&& render->wall_xstart < render->xend)
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = ft_min(render->floor_xstart, render->wall_xstart);
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->floor_xstart;
		}
	}
	else
	{
		if (render->wall_xstart > render->xstart
				&& render->wall_xstart < render->xend)
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->neighbor_current_floor;
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = render->xstart;
		}
	}
	if (render->floor_xend > render->xstart
			&& render->floor_xend < render->xend)
	{
		if (render->wall_xend > render->xstart
				&& render->wall_xend < render->xend)
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = ft_max(render->current_floor, render->neighbor_current_floor);
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->current_floor;
		}
	}
	else
	{
		if (render->wall_xend > render->xstart
				&& render->wall_xend < render->xend)
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->xstart;
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = render->xstart;
		}
	}
*/
	/*if (v1.floor_range > 0)
	{
		if (v1.neighbor_floor_range > 0)
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = ft_max(render->current_floor, render->neighbor_current_floor);
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = ft_min(render->current_floor, render->neighbor_current_floor);
		}
	}
	else
	{
		if (v1.neighbor_floor_range > 0)
		{
			env->sectors[sector.neighbors[render->i]].xmin[render->y] = ft_max(render->current_floor, render->neighbor_current_floor);
		}
		else
		{
			env->sectors[sector.neighbors[render->i]].xmax[render->y] = ft_min(render->current_floor, render->neighbor_current_floor);
		}
	}*/
	/*if (render->current_floor > render.xstart
			&& render->current_floor < render.xend)
	{
	}
	env->sectors[sector.neighbors[render->i]].xmin[render->y] = ft_min(render->current_floor, render->neighbor_current_floor);*/
}
