/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/22 19:25:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline(t_vline vline, t_render render, t_env *env)
{
	int		i;
	double	yalpha;
	double	y;
	double	x;

	x = (render.alpha * (env->sdl.image->w / render.vz2)) / ((1 - render.alpha) * (1 / render.vz1) + render.alpha * (1 / render.vz2));
	x = ft_fclamp(x, 0, env->sdl.image->w);
	//ft_printf("x = %f\n", x);
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h)
				env->sdl.texture_pixels[vline.x + env->w * vline.start] = 0xFF222222;
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h)
				env->sdl.texture_pixels[vline.x + env->w * vline.end] = 0xFF222222;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && i >= 0 && i <= 300) || !env->options.show_minimap)
		{
			yalpha = (i - render.max_ceiling) / (double)(render.max_floor - render.max_ceiling);
			//y = (yalpha * (env->sdl.image->h / render.vz2)) / ((1 - yalpha) * (1 / render.vz1) + yalpha * (1 / render.vz2));
			y = yalpha * env->sdl.image->h;
			y = ft_fclamp(y, 0, env->sdl.image->h);
			//y = ((i - env->h + render.max_floor - render.max_ceiling) * env->sdl.image->h) / (double)(render.max_floor - render.max_ceiling);
			//ft_printf("yalpha = %f\n", yalpha);
			if (vline.x >= 0 && vline.x < env->w && i >= 0 && i < env->h
					&& x >= 0 && x < env->sdl.image->w && y >= 0 && y < env->sdl.image->h)
				env->sdl.texture_pixels[vline.x + env->w * i] = apply_light(env->sdl.image_str[(int)x + env->sdl.image->w * (int)y], render.light);
		}
		i++;
		//vline.start++;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_color(t_vline vline, t_render render, t_env *env)
{
	(void)render;
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h)
				env->sdl.texture_pixels[vline.x + env->w * vline.start] = 0xFF222222;
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h)
				env->sdl.texture_pixels[vline.x + env->w * vline.end] = 0xFF222222;
		}
		vline.start++;
		vline.end--;
	}
	while (vline.start <= vline.end)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h)
				env->sdl.texture_pixels[vline.x + env->w * vline.start] = vline.color;
		}
		vline.start++;
	}
}

/*
**	Draw the ceiling of the current wall
*/

void	draw_ceiling(t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = render.ymin;
	vline.end = render.current_ceiling;
	vline.color = 0xFF222222;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	//ft_printf("floor end = %d\n", vline.end);
	draw_vline_color(vline, render, env);
}

/*
**	Draw the floor of the current wall
*/

void	draw_floor(t_render render,t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = render.current_floor;
	vline.end = render.ymax;
	vline.color = 0xFF444444;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	//ft_printf("ceiling start = %d\n", vline.start);
	draw_vline_color(vline, render, env);
}

/*
**	Draw the neighbor upper wall (corniche)
*/

void	draw_upper_wall(t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = render.current_ceiling;
	vline.end = render.current_neighbor_ceiling;
	vline.color = 0xFF7C00D9;
	vline.color = 0xFF222222;
	vline.color = 0xFF0B6484;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	//ft_printf("floor end = %d\n", vline.end);
	if (env->options.contouring && (render.currentx == render.x1 || render.currentx == render.x2))
			vline.color = 0xFF222222;
	draw_vline(vline, render, env);
}

/*
**	Draw the neighbor bottom wall (marche)
*/

void	draw_bottom_wall(t_render render,t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = render.current_neighbor_floor;
	vline.end = render.current_floor;
	vline.color = 0xFF7C00D9;
	vline.color = 0xFF444444;
	//vline.color = 0xFF0B6484;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	//ft_printf("ceiling start = %d\n", vline.start);
	if (env->options.contouring && (render.currentx == render.x1 || render.currentx == render.x2))
			vline.color = 0xFF222222;
	draw_vline(vline, render, env);
}
