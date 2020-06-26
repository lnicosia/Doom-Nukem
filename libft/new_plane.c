/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:45:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 18:43:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_plane	get_equation(t_v3 v1, t_v3 v2)
{
	t_plane	plane;

	plane.norm.x = v1.y * v2.z - v2.y * v1.z;
	plane.norm.y = v2.x * v1.z - v1.x * v2.z;
	plane.norm.z = v1.x * v2.y - v1.y * v2.x;
	return (plane);
}

int				is_collinear(t_v3 v1, t_v3 v2)
{
	double	rx;
	double	ry;
	double	rz;

	rx = v1.x / v2.x;
	ry = v1.y / v2.y;
	rz = v1.z / v2.z;
	if (rx == ry && rx == rz)
		return (1);
	return (0);
}

t_plane			new_plane(t_v3 p1, t_v3 p2, t_v3 p3)
{
	t_plane	plane;
	t_v3	p1p2;
	t_v3	p1p3;

	p1p2 = new_v3(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
	p1p3 = new_v3(p3.x - p1.x, p3.y - p1.y, p3.z - p1.z);
	plane = get_equation(p1p2, p1p3);
	plane.d = (-plane.norm.x * p1.x - plane.norm.y * p1.y
	- plane.norm.z * p1.z);
	return (plane);
}
