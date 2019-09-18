/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:14:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "render.h"

short	get_vertex_nb_in_sector(short vertex, t_sector sector)
{
	short	i;
	short	res;

	i = 0;
	res = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == vertex)
			res = i;
		i++;
	}
	return (res);
}
void		reset_render_utils(t_env *env)
{
	int	i;
	int	max;
	int	ymin;
	int	ymax;

	max = env->screen_sectors_size;
	ymin = ft_max(env->h_h + env->player.camera.y1 * env->player.camera.scale, 0);
	ymax = ft_min(env->h_h + env->player.camera.y2 * env->player.camera.scale,
			env->h - 1);
	env->skybox_computed = 0;
	i = 0;
	while (i < max)
	{
		env->xmin[i] = -1;
		env->xmax[i] = -1;
		env->screen_sectors[i] = -1;
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		env->rendered_sectors[i] = 0;
		env->sectors[i].computed = 0;
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
