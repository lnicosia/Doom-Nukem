/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/03 12:15:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline(t_vline vline, t_render render, t_env *env)
{
	int			i;
	double		yalpha;
	double		y;
	double		x;
	Uint32		*pixels;
	double		*zbuffer;
	Uint32		*texture_pixels;
	t_texture	texture;
	int			texture_w;

	texture = env->textures[render.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	texture_w = texture.surface->w;
	x = (render.alpha * (texture_w * render.wall_width / render.vz2)) * render.z;
	while (x >= texture_w)
		x -= texture_w;
	while (x < 0)
		x += texture_w;
	x = ft_fclamp(x, 0, texture_w);
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h
					&& render.z <= zbuffer[vline.x + env->w * vline.start])
			{
				pixels[vline.x + env->w * vline.start] = 0xFF222222;
				zbuffer[vline.x + env->w * vline.start] = render.z;
			}
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h
					&& render.z <= zbuffer[vline.x + env->w * vline.end])
			{
				pixels[vline.x + env->w * vline.end] = 0xFF222222;
				zbuffer[vline.x + env->w * vline.end] = render.z;
			}
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && i >= 0 && i <= 300) || !env->options.show_minimap)
		{
			yalpha = (1 - (i - render.max_ceiling) / (double)(render.max_floor - render.max_ceiling));
			y = yalpha * texture.surface->h * render.wall_height;
			while (y >= texture.surface->h)
				y -= texture.surface->h;
			while (y < 0)
				y += texture.surface->h;
			if (vline.x >= 0 && vline.x < env->w && i >= 0 && i < env->h
					&& x >= 0 && x < texture_w && y >= 0 && y < texture.surface->h
					&& render.z <= zbuffer[vline.x + env->w * i])
			{
				if (!env->options.lighting)
					pixels[vline.x + env->w * i] = texture_pixels[(int)x + texture_w * (int)y];
				else
					pixels[vline.x + env->w * i] = apply_light(texture_pixels[(int)x + texture_w * (int)y], render.light);
				zbuffer[vline.x + env->w * i] = render.z;
				/*if (env->options.lighting)
					pixels[vline.x + env->w * i] = apply_light(0xFF888888, render.light);*/
			}
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
	int	coord;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h
					&& render.z <= zbuffer[vline.x + env->w * vline.start])
			{
				pixels[vline.x + env->w * vline.start] = 0xFF222222;
				zbuffer[vline.x + env->w * vline.start] = render.z;
			}
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h
					&& render.z <= zbuffer[vline.x + env->w * vline.end])
			{
				pixels[vline.x + env->w * vline.end] = 0xFF222222;
				zbuffer[vline.x + env->w * vline.end] = render.z;
			}
		}
		vline.start++;
		vline.end--;
	}
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h
					&& render.z <= zbuffer[coord])
			{
				pixels[coord] = vline.color;
				zbuffer[coord] = render.z;
				/*if (env->options.lighting)
					pixels[coord] = apply_light(0xFF888888, render.light);*/
			}
		}
		vline.start++;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_ceiling(t_vline vline, t_render render, t_env *env)
{
	int		i;
	double	y;
	double	x;
	double	alpha;
	double	dist;
	double	startdist;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h)
				pixels[vline.x + env->w * vline.start] = 0xFF222222;
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h)
				pixels[vline.x + env->w * vline.end] = 0xFF222222;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start + 1;
	startdist = (env->h / 2.0) / (double)(i - (render.max_floor + render.max_ceiling) / 2.0);
	startdist = (env->h / 2.0) / (double)(i - render.ceiling_horizon);
	while (i <= vline.end)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && i >= 0 && i <= 300) || !env->options.show_minimap)
		{
			//dist = (env->h / 2.0) / (double)(i - (render.max_floor + render.max_ceiling) / 2.0);
			dist = (env->h / 2.0) / (double)(i - render.ceiling_horizon);
			//dist = (env->h) / (double)(2.0 * i - env->h);
			//dist = env->h / (double)(2 * i - env->h);
			//alpha = dist / startdist;
			alpha = dist / render.distceiling;
			//alpha = (i - render.max_floor) / (double)(env->h - render.max_floor);
			//alpha = (double)(env->h - render.max_floor) / (double)(i - render.max_floor);
			//ft_printf("alpha = %f\n", alpha);
			y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
			//y = alpha * render.texel.y + (1.0 - alpha) * env->screen_pos[render.currentx].y;
			//y = ((1.0 - alpha) * env->player.pos.y / render.vz1 + alpha * render.texel.y / render.vz2) / ((1.0 - alpha) / render.vz1 + alpha / render.vz2);
			double	v0;
			v0 = 2.0;
			//y = ((1.0 - alpha) * env->player.pos.y / v0 + alpha * render.texel.y / render.distwall) / ((1.0 - alpha) / v0 + alpha / render.distwall);
			//ft_printf("y = %f\n", y);
			x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
			//x = alpha * render.texel.x + (1.0 - alpha) * env->screen_pos[render.currentx].x;
			//x = ((1.0 - alpha) * env->player.pos.x / render.vz1 + alpha * render.texel.x / render.vz2) / ((1.0 - alpha) / render.vz1 + alpha / render.vz2);
			//x = ((1.0 - alpha) * env->player.pos.x / v0 + alpha * render.texel.x / render.distwall) / ((1.0 - alpha) / v0 + alpha / render.distwall);
			y *= env->textures[render.ceiling_texture].surface->h / 5.0;
			x *= env->textures[render.ceiling_texture].surface->w / 5.0;
			while (y >= env->textures[render.ceiling_texture].surface->h)
				y -= env->textures[render.ceiling_texture].surface->h;
			while (y < 0)
				y += env->textures[render.ceiling_texture].surface->h;
			while (x >= env->textures[render.ceiling_texture].surface->w)
				x -= env->textures[render.ceiling_texture].surface->w;
			while (x < 0)
				x += env->textures[render.ceiling_texture].surface->w;
			if (vline.x >= 0 && vline.x < env->w && i >= 0 && i < env->h
					&& x >= 0 && x < env->textures[render.ceiling_texture].surface->w && y >= 0 && y < env->textures[render.ceiling_texture].surface->h)
			{
				if (!env->options.lighting)
					pixels[vline.x + env->w * i] = env->textures[render.ceiling_texture].str[(int)x + env->textures[render.ceiling_texture].surface->w * (int)y];
				else
					pixels[vline.x + env->w * i] = apply_light(env->textures[render.ceiling_texture].str[(int)x + env->textures[render.ceiling_texture].surface->w * (int)y], render.light);
			}
		}
		i++;
		//vline.start++;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_floor(t_vline vline, t_render render, t_env *env)
{
	int		i;
	double	y;
	double	x;
	double	alpha;
	double	dist;
	double	startdist;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	if (env->options.contouring)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.start >= 0 && vline.start <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.start >= 0 && vline.start < env->h)
				pixels[vline.x + env->w * vline.start] = 0xFF222222;
		}
		if (!(vline.x >= env->w - 300 && vline.x < env->w && vline.end >= 0 && vline.end <= 300) || !env->options.show_minimap)
		{
			if (vline.x >= 0 && vline.x < env->w && vline.end >= 0 && vline.end < env->h)
				pixels[vline.x + env->w * vline.end] = 0xFF222222;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start + 1;
	startdist = (env->h / 2.0) / (double)(i - (render.max_floor + render.max_ceiling) / 2.0);
	startdist = (env->h / 2.0) / (double)(i - render.floor_horizon);
	while (i <= vline.end)
	{
		if (!(vline.x >= env->w - 300 && vline.x < env->w && i >= 0 && i <= 300) || !env->options.show_minimap)
		{
			//dist = (env->h / 2.0) / (double)(i - (render.max_floor + render.max_ceiling) / 2.0);
			dist = (env->h / 2.0) / (double)(i - render.floor_horizon);
			//dist = (env->h) / (double)(2.0 * i - env->h);
			//dist = env->h / (double)(2 * i - env->h);
			//alpha = dist / startdist;
			alpha = dist / render.distfloor;
			//alpha = (i - render.max_floor) / (double)(env->h - render.max_floor);
			//alpha = (double)(env->h - render.max_floor) / (double)(i - render.max_floor);
			//ft_printf("alpha = %f\n", alpha);
			y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
			//y = alpha * render.texel.y + (1.0 - alpha) * env->screen_pos[render.currentx].y;
			//y = ((1.0 - alpha) * env->player.pos.y / render.vz1 + alpha * render.texel.y / render.vz2) / ((1.0 - alpha) / render.vz1 + alpha / render.vz2);
			double	v0;
			v0 = 2.0;
			//y = ((1.0 - alpha) * env->player.pos.y / v0 + alpha * render.texel.y / render.distwall) / ((1.0 - alpha) / v0 + alpha / render.distwall);
			//ft_printf("y = %f\n", y);
			x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
			//x = alpha * render.texel.x + (1.0 - alpha) * env->screen_pos[render.currentx].x;
			//x = ((1.0 - alpha) * env->player.pos.x / render.vz1 + alpha * render.texel.x / render.vz2) / ((1.0 - alpha) / render.vz1 + alpha / render.vz2);
			//x = ((1.0 - alpha) * env->player.pos.x / v0 + alpha * render.texel.x / render.distwall) / ((1.0 - alpha) / v0 + alpha / render.distwall);
			y *= env->textures[render.floor_texture].surface->h / 5.0;
			x *= env->textures[render.floor_texture].surface->w / 5.0;
			while (y >= env->textures[render.floor_texture].surface->h)
				y -= env->textures[render.floor_texture].surface->h;
			while (y < 0)
				y += env->textures[render.floor_texture].surface->h;
			while (x >= env->textures[render.floor_texture].surface->w)
				x -= env->textures[render.floor_texture].surface->w;
			while (x < 0)
				x += env->textures[render.floor_texture].surface->w;
			if (vline.x >= 0 && vline.x < env->w && i >= 0 && i < env->h
					&& x >= 0 && x < env->textures[render.floor_texture].surface->w && y >= 0 && y < env->textures[render.floor_texture].surface->h)
			{
				if (!env->options.lighting)
					pixels[vline.x + env->w * i] = env->textures[render.floor_texture].str[(int)x + env->textures[render.floor_texture].surface->w * (int)y];
				else
					pixels[vline.x + env->w * i] = apply_light(env->textures[render.floor_texture].str[(int)x + env->textures[render.floor_texture].surface->w * (int)y], render.light);
			}
		}
		i++;
		//vline.start++;
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
	//draw_vline_ceiling(vline, render, env);
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
	//draw_vline_floor(vline, render, env);
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
