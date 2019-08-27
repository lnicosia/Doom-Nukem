/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:41:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/22 10:41:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	cross_product(double x0, double y0, double x1, double y1)
{
	return (x0 * y1 - x1 * y0);
}

/*
**	Return the intersection between 2 lines given by 4 points
*/

t_v2	get_intersection(t_v2 p1, t_v2 p2, t_v2 p3, t_v2 p4)
{
	t_v2	res;

	res.x = cross_product(cross_product(p1.x, p1.y, p2.x, p2.y),
			(p1.x) - (p2.x),
			cross_product(p3.x, p3.y, p4.x, p4.y), (p3.x) - (p4.x))
		/ cross_product((p1.x) - (p2.x), (p1.y) - (p2.y),
				(p3.x) - (p4.x), (p3.y) - (p4.y));
	res.y = cross_product(cross_product(p1.x, p1.y, p2.x, p2.y),
			(p1.y) - (p2.y),
			cross_product(p3.x, p3.y, p4.x, p4.y), (p3.y) - (p4.y))
		/ cross_product((p1.x) - (p2.x), (p1.y) - (p2.y),
				(p3.x) - (p4.x), (p3.y) - (p4.y));
	return (res);
}
