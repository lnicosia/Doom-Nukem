/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:47:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/08 10:40:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int     in_range(double nb, double val1, double val2)
{
	double min;
	double max;

	min = (val1 <= val2) ? val1 : val2;
	max = (val1 > val2) ? val1 : val2;
	if (nb > min && nb <= max)
		return (1);
	return (0);
}

int     diff_value(int nb1, int nb2, int a, int b)
{
	if ((nb1 == a && nb2 == b) || (nb1 == b && nb2 == a))
		return (0);
	return (1);
}

int     diff_sign(double nb1, double nb2)
{
	if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
		return (0);
	return (1);
}

/*
**	Returns if a pos is in a certain sector
*/

int     is_in_sector(t_env *env, int sector, t_v3 pos)
{
	int     count;
	int     i;
	double  start_pos;
	double  end_pos;

	i = 0;
	count = 0;
	//ft_printf("Checking sector %d\n", sector);
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	if (pos.z < get_floor_at_pos(env->sectors[sector], new_v3(pos.x, pos.y, 0), env)
			|| pos.z > get_ceiling_at_pos(env->sectors[sector], new_v3(pos.x, pos.y, 02), env))
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		start_pos = (pos.x - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		end_pos = (env->sectors[sector].x_max + 1 - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		if (diff_sign(start_pos, end_pos) && in_range(pos.y, SECTOR_Y1, SECTOR_Y2))
			count++;
		i++;
	}
	if (count % 2 == 0)
	{
		//ft_printf("KO\n");
		return (0);
	}
	//ft_printf("OK\n");
	return (1);
}

/*
**	Returns if a pos is in a certain sector
**	without checking z
*/

int     is_in_sector_no_z(t_env *env, int sector, t_v2 pos)
{
	int     count;
	int     i;
	double  start_pos;
	double  end_pos;

	i = 0;
	count = 0;
	//ft_printf("Checking sector %d\n", sector);
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		start_pos = (pos.x - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		end_pos = (env->sectors[sector].x_max + 1 - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		if (diff_sign(start_pos, end_pos) && in_range(pos.y, SECTOR_Y1, SECTOR_Y2))
			count++;
		i++;
	}
	if (count % 2 == 0)
	{
		//ft_printf("KO\n");
		return (0);
	}
	//ft_printf("OK\n");
	return (1);
}
