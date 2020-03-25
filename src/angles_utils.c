/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:03:31 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 16:23:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Get the first 3 vertices of a sector that are not on the same line
*/

int		get_sector_first_angles(t_sector *sector, t_env *env)
{
	t_point	v[3];
	int		i;

	i = 0;
	v[0] = new_point(0, 0);
	v[1] = new_point(0, 0);
	v[2] = new_point(0, 0);
	while (i < sector->nb_vertices)
	{
		v[0].x = env->vertices[sector->vertices[i]].x;
		v[0].y = env->vertices[sector->vertices[i]].y;
		v[1].x = env->vertices[sector->vertices[i + 1]].x;
		v[1].y = env->vertices[sector->vertices[i + 1]].y;
		v[2].x = env->vertices[sector->vertices[i + 2]].x;
		v[2].y = env->vertices[sector->vertices[i + 2]].y;
		if (get_angle(v))
			return (i);
		i++;
	}
	return (0);
}

int		get_angle(t_point p[3])
{
	return ((p[1].x - p[0].x) * (p[2].y - p[1].y)
		- (p[1].y - p[0].y) * (p[2].x - p[1].x));
}

int		count_sector_angles(t_sector *sector, t_env *env)
{
	int		i;
	int		count;
	t_point	v[3];

	i = -1;
	count = 0;
	while (++i < sector->nb_vertices - 1)
	{
		v[0].x = env->vertices[sector->vertices[i]].x;
		v[0].y = env->vertices[sector->vertices[i]].y;
		v[1].x = env->vertices[sector->vertices[i + 1]].x;
		v[1].y = env->vertices[sector->vertices[i + 1]].y;
		v[2].x = env->vertices[sector->vertices[i + 2]].x;
		v[2].y = env->vertices[sector->vertices[i + 2]].y;
		if (get_angle(v))
			count++;
	}
	v[0].x = env->vertices[sector->vertices[i]].x;
	v[0].y = env->vertices[sector->vertices[i]].y;
	v[1].x = env->vertices[sector->vertices[0]].x;
	v[1].y = env->vertices[sector->vertices[0]].y;
	v[2].x = env->vertices[sector->vertices[1]].x;
	v[2].y = env->vertices[sector->vertices[1]].y;
	if (get_angle(v))
		count++;
	return (count);
}
