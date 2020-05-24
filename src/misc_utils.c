/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:11:03 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 17:29:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

void	init_sector_list(t_env *env, int curr)
{
	int	i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (i == curr)
			env->sector_list[i] = 1;
		else
			env->sector_list[i] = 0;
		i++;
	}
}

double	distance_two_points_3d(t_v3 p1, t_v3 p2)
{
	double	distance;
	double	square_x;
	double	square_y;
	double	square_z;

	square_x = (p2.x - p1.x) * (p2.x - p1.x);
	square_y = (p2.y - p1.y) * (p2.y - p1.y);
	square_z = (p2.z - p1.z) * (p2.z - p1.z);
	distance = sqrt(square_x + square_y + square_z);
	return (distance);
}
