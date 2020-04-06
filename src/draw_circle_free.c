/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_circle_free.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/19 15:29:22 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/19 15:35:39 by lnicosia		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void		fill_hline_free(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.x <= p2.x)
	{
		if (p1.x >= 0 && p1.x < env->w && p1.y >= 0 && p1.y < env->h)
		env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.x++;
	}
}

void		fill_vline_free(Uint32 color, t_point p1, t_point p2, t_env *env)
{
	while (p1.y <= p2.y)
	{
		if (p1.x >= 0 && p1.x < env->w && p1.y >= 0 && p1.y < env->h)
			env->sdl.texture_pixels[p1.x + p1.y * env->w] = color;
		p1.y++;
	}
}

void		draw_outline_free2(t_circle circle, int x, int y, t_env *env)
{
	if (circle.center.x - y >= 0 && circle.center.x - y < env->w
			&& circle.center.y + x >= 0 && circle.center.y + x < env->h)
	env->sdl.texture_pixels[circle.center.x - y + env->w
	* (circle.center.y + x)] = circle.line_color;
	if (circle.center.x + y >= 0 && circle.center.x + y < env->w
			&& circle.center.y - x >= 0 && circle.center.y - x < env->h)
	env->sdl.texture_pixels[circle.center.x + y + env->w
	* (circle.center.y - x)] = circle.line_color;
	if (circle.center.x - y >= 0 && circle.center.x - y < env->w
			&& circle.center.y - x >= 0 && circle.center.y - x < env->h)
	env->sdl.texture_pixels[circle.center.x - y + env->w
	* (circle.center.y - x)] = circle.line_color;
}

void		draw_outline_free(t_circle circle, int x, int y, t_env *env)
{
	if (circle.center.x + x >= 0 && circle.center.x + x < env->w
			&& circle.center.y + y >= 0 && circle.center.y + y < env->h)
	env->sdl.texture_pixels[circle.center.x + x + env->w
	* (circle.center.y + y)] = circle.line_color;
	if (circle.center.x - x >= 0 && circle.center.x - x < env->w
			&& circle.center.y + y >= 0 && circle.center.y + y < env->h)
	env->sdl.texture_pixels[circle.center.x - x + env->w
	* (circle.center.y + y)] = circle.line_color;
	if (circle.center.x + x >= 0 && circle.center.x + x < env->w
			&& circle.center.y - y >= 0 && circle.center.y - y < env->h)
	env->sdl.texture_pixels[circle.center.x + x + env->w
	* (circle.center.y - y)] = circle.line_color;
	if (circle.center.x - x >= 0 && circle.center.x - x < env->w
			&& circle.center.y - y >= 0 && circle.center.y - y < env->h)
	env->sdl.texture_pixels[circle.center.x - x + env->w
	* (circle.center.y - y)] = circle.line_color;
	if (circle.center.x + y >= 0 && circle.center.x + y < env->w
			&& circle.center.y + x >= 0 && circle.center.y + x < env->h)
	env->sdl.texture_pixels[circle.center.x + y + env->w
	* (circle.center.y + x)] = circle.line_color;
	draw_outline_free2(circle, x, y, env);
}

void		draw_circle_free(t_circle circle, t_env *env)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	y = circle.radius;
	p = 3 - 2 * circle.radius;
	while (x <= y)
	{
		fill_hline_free(circle.color, new_point(circle.center.x - x,
		circle.center.y + y), new_point(circle.center.x + x,
		circle.center.y + y), env);
		fill_hline_free(circle.color, new_point(circle.center.x - x,
		circle.center.y - y), new_point(circle.center.x + x,
		circle.center.y - y), env);
		fill_hline_free(circle.color, new_point(circle.center.x - y,
		circle.center.y - x), new_point(circle.center.x + y,
		circle.center.y - x), env);
		fill_hline_free(circle.color, new_point(circle.center.x - y,
		circle.center.y + x), new_point(circle.center.x + y,
		circle.center.y + x), env);
		draw_outline_free(circle, x, y, env);
		p += p < 0 ? 4 * x++ + 6 : 4 * (x++ - y--) + 10;
	}
}
