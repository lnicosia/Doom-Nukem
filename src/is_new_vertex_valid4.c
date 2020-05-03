/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_new_vertex_valid4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:17:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:17:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			valid_line(t_v2 v1, t_v2 v2, t_v2 v3, t_v2 v4)
{
	if ((v1.x > v3.x && v1.x < v4.x)
			|| (v1.x < v3.x && v1.x > v4.x)
			|| (v1.y < v3.y && v1.y > v4.y)
			|| (v1.y < v3.y && v1.y > v4.y)
			|| (v2.x < v3.x && v2.x > v4.x)
			|| (v2.x > v3.x && v2.x < v4.x)
			|| (v2.y < v3.y && v2.y > v4.y)
			|| (v2.y > v3.y && v2.y < v4.y))
		return (1);
	return (0);
}

int			segments_intersect_editor(t_v2 v1, t_v2 v2, t_v2 v3, t_v2 v4)
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
	if ((int)intersection.x == -2147483648
		|| (int)intersection.y == -2147483648)
	{
		if (valid_line(v1, v2, v3, v4))
			return (1);
		return (0);
	}
	if (v2.x == v3.x && v2.y == v3.y)
		return (0);
	return (1);
}
