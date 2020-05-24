/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:40:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"

void	reset_clipped(t_env *env)
{
	int			i;
	int			j;
	int			max;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		max = env->sectors[i].nb_vertices;
		while (j <= max)
		{
			env->sectors[i].clipped_floors1[j] = env->sectors[i].floors[j];
			env->sectors[i].clipped_ceilings1[j] = env->sectors[i].ceilings[j];
			env->sectors[i].clipped_floors2[j] = env->sectors[i].floors[j];
			env->sectors[i].clipped_ceilings2[j] = env->sectors[i].ceilings[j];
			j++;
		}
		i++;
	}
}

int		get_vertex_nb_in_sector(int vertex, t_sector *sector)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < sector->nb_vertices)
	{
		if (sector->vertices[i] == vertex)
			res = i;
		i++;
	}
	return (res);
}

void	reset_render_utils2(int ymin, int ymax, t_camera *camera, t_env *env)
{
	int	i;

	i = 0;
	while (i < camera->size)
	{
		camera->sector_computed[i] = 0;
		i++;
	}
	i = 0;
	while (i < env->w)
	{
		env->ymin[i] = ymin;
		env->ymax[i] = ymax;
		i++;
	}
}

void	reset_render_utils(t_camera *camera, t_env *env)
{
	int	i;
	int	max;
	int	ymin;
	int	ymax;

	camera->computed = 0;
	max = env->screen_sectors_size;
	ymin = ft_max(env->h_h + camera->y1 * env->player.camera.scale, 0);
	ymax = ft_min(env->h_h + camera->y2 * env->player.camera.scale,
			env->h - 1);
	env->skybox_computed = 0;
	i = 0;
	while (i < max)
	{
		camera->xmax[i] = -1;
		camera->screen_sectors[i] = -1;
		camera->rendered_sectors[i] = 0;
		i++;
	}
	reset_render_utils2(ymin, ymax, camera, env);
}

void	reset_screen_limits(t_render *render, t_env *env)
{
	int	j;

	j = 0;
	while (j < env->w)
	{
		env->ymax[j] = render->tmp_max[j];
		env->ymin[j] = render->tmp_min[j];
		j++;
	}
}
