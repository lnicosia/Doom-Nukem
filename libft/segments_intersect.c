/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segments_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:38:03 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/22 12:12:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checks if two segments given by 4 points intersect
*/

int		segments_intersect(t_v2 v1, t_v2 v2, t_v2 v3, t_v2 v4)
{
	t_v2	intersection;

	intersection = get_intersection(v1, v2, v3, v4);
	if ((intersection.x < v1.x && intersection.x < v2.x)
			|| (intersection.x > v1.x && intersection.x > v2.x)
			|| (intersection.y < v1.y && intersection.y < v2.y)
			|| (intersection.y > v1.y && intersection.y > v2.y)
			|| (intersection.x < v3.x && intersection.x < v4.x)
			|| (intersection.x > v3.x && intersection.x > v4.x)
			|| (intersection.y < v3.y && intersection.y < v4.y)
			|| (intersection.y > v3.y && intersection.y > v4.y))
		return (0);
	return (1);
}
