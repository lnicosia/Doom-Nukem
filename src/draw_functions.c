/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 13:16:52 by lnicosia         ###   ########.fr       */
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
	Uint32		*texture_pixels;
	double		*zbuffer;
	t_texture	texture;
	int			texture_w;
	int			texture_h;
	int			start_coord;
	int			end_coord;
	int			coord;

	texture = env->textures[render.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	texture_w = texture.surface->w;
	texture_h = texture.surface->h;
	x = render.alpha * render.projected_texture_w * render.z;
	if (x != x)
		return ;
	while (x >= texture_w)
		x -= texture_w;
	while (x < 0)
		x += texture_w;
	x = ft_fclamp(x, 0, texture_w);
	if (env->options.contouring)
	{
		start_coord = vline.x + env->w * vline.start;
		end_coord = vline.x + env->w * vline.end;
		if (render.z <= zbuffer[start_coord])
		{
			pixels[start_coord] = 0xFF222222;
			zbuffer[start_coord] = render.z;
		}
		if (render.z <= zbuffer[end_coord])
		{
			pixels[end_coord] = 0xFF222222;
			zbuffer[end_coord] = render.z;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		coord = vline.x + env->w * i;
		yalpha = 1 - (i - render.max_ceiling) / render.line_height;
		y = yalpha * render.projected_texture_h;
		while (y >= texture_h)
			y -= texture_h;
		while (y < 0)
			y += texture_h;
		if (render.z <= zbuffer[coord])
		{
			if (!env->options.lighting)
				pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
			else
				pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], render.light);
			zbuffer[coord] = render.z;
		}
		/*if (i == (int)render.horizon)
			pixels[coord] = 0xFF00FF00;*/
		i++;
	}
}

/*
**	Draw a vertical vline on the screen at vline.x
*/

void	draw_vline_color(t_vline vline, t_render render, t_env *env)
{
	int		start_coord;
	int		end_coord;
	int		coord;
	Uint32	*pixels;
	double	*zbuffer;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	if (env->options.contouring)
	{
		start_coord = vline.x + env->w * vline.start;
		end_coord = vline.x + env->w * vline.end;
		if (render.z <= zbuffer[start_coord])
		{
			pixels[start_coord] = 0xFF222222;
			zbuffer[start_coord] = render.z;
		}
		if (render.z <= zbuffer[end_coord])
		{
			pixels[end_coord] = 0xFF222222;
			zbuffer[end_coord] = render.z;
		}
		vline.start++;
		vline.end--;
	}
	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		if (render.z <= zbuffer[coord])
		{
			pixels[coord] = vline.color;
			zbuffer[coord] = render.z;
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
	Uint32	*pixels;
	Uint32	*texture_pixels;
	double	*zbuffer;
	int		start_coord;
	int		end_coord;
	int		coord;
	int		texture_w;
	int		texture_h;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	texture_w = env->textures[render.ceiling_texture].surface->w;
	texture_h = env->textures[render.ceiling_texture].surface->h;
	texture_pixels = env->textures[render.ceiling_texture].str;
	if (env->options.contouring)
	{
		start_coord = vline.x + env->w * vline.start;
		end_coord = vline.x + env->w * vline.end;
		if (render.z <= zbuffer[start_coord])
		{
			pixels[start_coord] = 0xFF222222;
			zbuffer[start_coord] = render.z;
		}
		if (render.z <= zbuffer[end_coord])
		{
			pixels[end_coord] = 0xFF222222;
			zbuffer[end_coord] = render.z;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		alpha = render.ceiling_horizon / (double)(i - render.horizon);
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
		y *= render.ceiling_yscale;
		x *= render.ceiling_xscale;
		if (y >= texture_h || y < 0)
			y = ft_abs((int)y % texture_h);
		if (x >= texture_w || x < 0)
			x = ft_abs((int)x % texture_w);
		if (x >= 0 && x < texture_w && y >= 0 && y < texture_h)
		{
			coord = vline.x + env->w * i;
			if (!env->options.lighting)
				pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
			else
				pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], render.light);
			zbuffer[coord] = render.z;
		}
		i++;
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
	Uint32	*pixels;
	Uint32	*texture_pixels;
	double	*zbuffer;
	int		start_coord;
	int		end_coord;
	int		coord;
	int		texture_w;
	int		texture_h;

	pixels = env->sdl.texture_pixels;
	zbuffer = env->depth_array;
	texture_w = env->textures[render.floor_texture].surface->w;
	texture_h = env->textures[render.floor_texture].surface->h;
	texture_pixels = env->textures[render.floor_texture].str;
	if (env->options.contouring)
	{
		start_coord = vline.x + env->w * vline.start;
		end_coord = vline.x + env->w * vline.end;
		if (render.z <= zbuffer[start_coord])
		{
			pixels[start_coord] = 0xFF222222;
			zbuffer[start_coord] = render.z;
		}
		if (render.z <= zbuffer[end_coord])
		{
			pixels[end_coord] = 0xFF222222;
			zbuffer[end_coord] = render.z;
		}
		vline.start++;
		vline.end--;
	}
	i = vline.start;
	while (i <= vline.end)
	{
		alpha = render.floor_horizon / (double)(i - render.horizon);
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
		y *= render.floor_yscale;
		x *= render.floor_xscale;
		if (y >= texture_h || y < 0)
			y = ft_abs((int)y % texture_h);
		if (x >= texture_w || x < 0)
			x = ft_abs((int)x % texture_w);
		if (x >= 0 && x < texture_w && y >= 0 && y < texture_h)
		{
			coord = vline.x + env->w * i;
			if (!env->options.lighting)
				pixels[coord] = texture_pixels[(int)x + texture_w * (int)y];
			else
				pixels[coord] = apply_light(texture_pixels[(int)x + texture_w * (int)y], render.light);
			zbuffer[coord] = render.z;
		}
		i++;
	}
}

/*
**	Draw the ceiling of the current wall
*/

void	draw_ceiling(t_render render, t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = env->ymin[vline.x];
	vline.end = render.current_ceiling;
	vline.color = 0xFF222222;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	if (env->sectors[render.sector].ceiling_slope)
		draw_vline_color(vline, render, env);
	else
		draw_vline_ceiling(vline, render, env);
}

/*
**	Draw the floor of the current wall
*/

void	draw_floor(t_render render,t_env *env)
{
	t_vline	vline;

	vline.x = render.currentx;
	vline.start = render.current_floor;
	vline.end = env->ymax[vline.x];
	vline.color = 0xFF0B6484;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	if (!env->sectors[render.sector].floor_slope)
		draw_vline_floor(vline, render, env);
	else
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
	vline.color = 0xFF444444;
	if (env->options.lighting)
		vline.color = apply_light(vline.color, render.light);
	//ft_printf("ceiling start = %d\n", vline.start);
	if (env->options.contouring && (render.currentx == render.x1 || render.currentx == render.x2))
		vline.color = 0xFF222222;
	draw_vline(vline, render, env);
}
