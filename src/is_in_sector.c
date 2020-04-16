/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:47:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/21 15:41:40 by lnicosia         ###   ########.fr       */
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

/*
** USED BY OLD INSIDE TMP SECT
**
int		in_range_not_included(double nb, double val1, double val2)
{
	double min;
	double max;

	min = (val1 <= val2) ? val1 : val2;
	max = (val1 > val2) ? val1 : val2;
	if (nb > min && nb < max)
		return (1);
	return (0);	
}
*/

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
**BOTH FUNCTIONS ARE ONLY USEFUL FOR OLD INSIDE TMP SECT
**
int		diff_sign_no_zero(double nb1, double nb2)
{
	if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0))
		return (0);
	return (1);	
}

double	find_xmax(t_vertex *tmp_sect, int size)
{
	double	xmax;
	int		i;

	i = 0;
	xmax = tmp_sect[0].x;
	while (i < size)
	{
		if (xmax < tmp_sect[i].x)
			xmax = tmp_sect[i].x;
		i++;
	}
	return (xmax);
}*/

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
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	if (pos.z < get_floor_at_pos(&env->sectors[sector], new_v3(pos.x, pos.y, 0),
	  	env) || pos.z > get_ceiling_at_pos(&env->sectors[sector],
		new_v3(pos.x, pos.y, 0), env))
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		start_pos = (pos.x - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1)
		- (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		end_pos = (env->sectors[sector].x_max + 1 - SECTOR_X1) * (SECTOR_Y2
		- SECTOR_Y1) - (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		if (diff_sign(start_pos, end_pos)
		  	&& in_range(pos.y, SECTOR_Y1, SECTOR_Y2))
			count++;
		i++;
	}
	if (count % 2 == 0)
	{
		return (0);
	}
	return (1);
}

/* OLD INSIDE TMP SECT 
**
**
int		inside_tmp_sect(t_vertex v1, t_vertex *tmp_sect, int size)
{
	int		count;
	int		i;
	double	start_pos;
	double	end_pos;
	double	xmax;

	i = 0;
	count = 0;
	xmax = find_xmax(tmp_sect, size);
	while (i < size - 1)
	{
		start_pos = (v1.x - tmp_sect[i].x) *
			(tmp_sect[i + 1].y - tmp_sect[i].y) - (v1.y - tmp_sect[i].y) *
			(tmp_sect[i + 1].x - tmp_sect[i].x);
		end_pos = (xmax + 1 - tmp_sect[i].x) *
			(tmp_sect[i + 1].y - tmp_sect[i].y) - (v1.y - tmp_sect[i].y) *
			(tmp_sect[i + 1].x - tmp_sect[i].x);
		ft_printf("start = %f, end = %f\n", start_pos, end_pos);
		if (diff_sign_no_zero(start_pos, end_pos) && in_range_not_included(v1.y,
			tmp_sect[i].y, tmp_sect[i + 1].y))
			count++;
		i++;
	}
	start_pos = (v1.x - tmp_sect[i].x) *
		(tmp_sect[0].y - tmp_sect[i].y) - (v1.y - tmp_sect[i].y) *
		(tmp_sect[0].x - tmp_sect[i].x);
	end_pos = (xmax + 1 - tmp_sect[i].x) *
		(tmp_sect[0].y - tmp_sect[i].y) - (v1.y - tmp_sect[i].y) *
		(tmp_sect[0].x - tmp_sect[i].x);
	ft_printf("start = %f, end = %f\n", start_pos, end_pos);
	if (diff_sign_no_zero(start_pos, end_pos) && in_range_not_included(v1.y,
		tmp_sect[i].y, tmp_sect[0].y))
		count++;
	ft_printf("count = %d\n", count);
	if (count % 2 == 0)
		return (0);
	return (1);
}
*/

int		inside_tmp_sect(t_vertex v1, t_vertex *tmp_sect, int size)
{
	int i;
	int j;
	int is_inside;

	i = 0;
	j = size - 1;
	is_inside = 0;
	while (i < size)
	{
		if (((tmp_sect[i].y < v1.y && tmp_sect[j].y > v1.y)
		|| (tmp_sect[j].y < v1.y && tmp_sect[i].y > v1.y))
		
		
		&& (tmp_sect[i].x < v1.x || tmp_sect[j].x < v1.x))
		{
			if (tmp_sect[i].x + ( v1.y - tmp_sect[i].y) /
				(tmp_sect[j].y - tmp_sect[i].y) *
				(tmp_sect[j].x - tmp_sect[i].x ) < v1.x)
				is_inside = (is_inside) ? 0 : 1;
		}
		j = i;
		i++;
	}
	return (is_inside);
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
	if (sector < 0 || sector >= env->nb_sectors)
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		start_pos = (pos.x - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1)
		- (pos.y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
		end_pos = (env->sectors[sector].x_max + 1 - SECTOR_X1)
		* (SECTOR_Y2 - SECTOR_Y1) - (pos.y - SECTOR_Y1)
		* (SECTOR_X2 - SECTOR_X1);
		if (diff_sign(start_pos, end_pos)
		  	&& in_range(pos.y, SECTOR_Y1, SECTOR_Y2))
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (0);
	return (1);
}
