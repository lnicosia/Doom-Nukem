/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:00:52 by gaerhard          #+#    #+#             */
/*   Updated: 2019/12/16 18:34:18 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

double  max(double a, double b)
{
	return ((a > b) ? a : b);
}

double  min(double a, double b)
{
	return ((a < b) ? a : b);
}

int onSegment(t_v2 p, t_v2 q, t_v2 r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	   return (1);
	return (0);
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// -1 --> Clockwise 
// 1 --> Counterclockwise 
int orientation(t_v2 p, t_v2 q, t_v2 r) 
{ 
	int val;
	
	val = (q.y - p.y) * (r.x - q.x) - 
			  (q.x - p.x) * (r.y - q.y); 
	if (val == 0)
		return 0;  // colinear 
	return ((val > 0) ? -1: 1); // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
int doIntersect(t_v2 p1, t_v2 q1, t_v2 p2, t_v2 q2) 
{ 
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return 1; 
	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1))
		return 1; 
	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1))
		return 1; 
	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2))
		return 1; 
	 // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2))
		return 1; 
	return 0; // Doesn't fall in any of the above cases 
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
		return (1); // RIGHT
	if (cross_product < 0)
		return (-1);//LEFT
	return (0);//On the line segment
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
	{
		ft_printf("p1_direction %d\n", p1_direction);
		ft_printf("p2_direction %d\n", p2_direction);
		ft_printf("w1_direction %d\n", w1_direction);
		ft_printf("w2_direction %d\n", w2_direction);
		return (1); //INTERSECTS
	}
	return (0);//NO INTERSECTION
}