/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_rectangle.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/02 15:03:32 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/25 16:38:45 by gaerhard		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

/*
**	Create a new rectangle with the given parameters
*/

t_rectangle	new_rectangle(Uint32 inside_color, Uint32 line_color,
		int filled, int line_size)
{
	t_rectangle	new;

	new.inside_color = inside_color;
	new.line_color = line_color;
	new.filled = filled;
	new.line_size = line_size;
	if (line_size < 0)
		new.line_size = 0;
	return (new);
}

/*
**	Draw the given rectangle at the given position
*/

void		draw_rectangle(t_env *env, t_rectangle r, t_point pos, t_point size)
{
	int	x;
	int	y;

	if (pos.x < 0 || pos.y < 0 || pos.x >= env->w || pos.y >= env->h
			|| size.x <= 0 || size.y <= 0)
		return ;
	y = pos.y - 1;
	while (++y <= pos.y + size.y && y < env->h)
	{
		x = pos.x - 1;
		while (++x <= pos.x + size.x && x < env->w)
		{
			if (y < pos.y + r.line_size
					|| y > pos.y + size.y - r.line_size
					|| x < pos.x + r.line_size
					|| x > pos.x + size.x - r.line_size)
				env->sdl.texture_pixels[x + y * env->w] = r.line_color;
			else if (r.filled)
				env->sdl.texture_pixels[x + y * env->w] = r.inside_color;
		}
	}
}
