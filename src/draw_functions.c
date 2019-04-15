/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/15 11:33:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

/*
**	Draw a vertical line on the screen at line.x
*/

void	draw_line(t_line line, t_env *env)
{
	if (env->options.contouring)
	{
		env->sdl.img_str[line.x + env->w * line.start] = 0xFF;
		env->sdl.img_str[line.x + env->w * line.end] = 0xFF;
		line.start++;
		line.end--;
	}
	while (line.start <= line.end)
	{
		env->sdl.img_str[line.x + env->w * line.start] = line.color;
		line.start++;
	}
}

/*
**	Draw the ceiling of the current wall
*/

void	draw_ceiling(t_render render, t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = render.ymin;
	line.end = render.current_ceiling;
	line.color = 0x222222FF;
	if (env->options.lighting)
		line.color = (render.light / 5) << 24
			| (render.light / 5) << 16
			| (render.light / 5) << 8
			| 255;
	//ft_printf("floor end = %d\n", line.end);
	draw_line(line, env);
}

/*
**	Draw the floor of the current wall
*/

void	draw_floor(t_render render,t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = render.current_floor;
	line.end = render.ymax;
	line.color = 0x444444FF;
	if (env->options.lighting)
		line.color = (render.light / 3) << 24
			| (render.light / 3) << 16
			| (render.light / 3) << 8
			| 255;
	//ft_printf("ceiling start = %d\n", line.start);
	draw_line(line, env);
}

/*
**	Draw the neighbor upper wall (corniche)
*/

void	draw_upper_wall(t_render render, t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = render.current_ceiling;
	line.end = render.current_neighbor_ceiling;
	line.color = 0x07C00D9FF;
	if (env->options.lighting)
		line.color = (render.light / 5) << 24
			| (render.light / 5) << 16
			| (render.light / 5) << 8
			| 255;
	//ft_printf("floor end = %d\n", line.end);
	draw_line(line, env);
}

/*
**	Draw the neighbor bottom wall (marche)
*/

void	draw_bottom_wall(t_render render,t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = render.current_neighbor_floor;
	line.end = render.current_floor;
	line.color = 0x7C00D9FF;
	if (env->options.lighting)
		line.color = (render.light / 3) << 24
			| (render.light / 3) << 16
			| (render.light / 3) << 8
			| 255;
	//ft_printf("ceiling start = %d\n", line.start);
	draw_line(line, env);
}
