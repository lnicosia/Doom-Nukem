/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:00:52 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/25 09:57:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int onSegment(t_v2 p, t_v2 q, t_v2 r) 
{ 
	if (q.x <= ft_fmax(p.x, r.x) && q.x >= ft_fmin(p.x, r.x) && 
		q.y <= ft_fmax(p.y, r.y) && q.y >= ft_fmin(p.y, r.y)) 
	   return (1);
	return (0);
} 
  
int orientation(t_v2 p, t_v2 q, t_v2 r) 
{ 
	int val;
	
	val = (q.y - p.y) * (r.x - q.x) - 
			  (q.x - p.x) * (r.y - q.y); 
	if (val == 0)
		return 0;
	return ((val > 0) ? -1: 1);
} 
  
int doIntersect(t_v2 p1, t_v2 q1, t_v2 p2, t_v2 q2) 
{ 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	if (o1 != o2 && o3 != o4) 
		return 1; 
	if (o1 == 0 && onSegment(p1, p2, q1))
		return 1; 
	if (o2 == 0 && onSegment(p1, q2, q1))
		return 1; 
	if (o3 == 0 && onSegment(p2, p1, q2))
		return 1; 
	if (o4 == 0 && onSegment(p2, q1, q2))
		return 1; 
	return 0;
}

int		direction_point(t_v2 s1, t_v2 s2, t_v2 p)
{
	double	cross_product;

	s2.x -= s1.x;
	s2.y -= s1.y;
	p.x -= s1.x;
	p.y -= s1.y;
	cross_product = s2.x * p.y - s2.y * p.x;
	if (cross_product > 0)
		return (1);
	if (cross_product < 0)
		return (-1);
	return (0);
}

int		intersection_check(t_v2 w1, t_v2 w2, t_v2 p1, t_v2 p2)
{
	int p1_direction;
	int p2_direction;
	int w1_direction;
	int	w2_direction;

	p1_direction = direction_point(w1, w2, p1);
	p2_direction = direction_point(w1, w2, p2);
	w1_direction = direction_point(p1, p2, w1);
	w2_direction = direction_point(p1, p2, w2);
	if ((p1_direction == 0 || p1_direction == -1 * p2_direction) &&
		(w1_direction == 0 || w1_direction == -1 * w2_direction))
		return (1);
	return (0);
}
