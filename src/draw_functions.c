/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/12 12:11:06 by lnicosia         ###   ########.fr       */
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
		yalpha = (1 - (i - render.max_ceiling) / render.line_height);
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
	double	*zbuffer;
	int		start_coord;
	int		end_coord;
	int		coord;

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
	i = vline.start;
	while (i <= vline.end)
	{
		alpha = (render.ceiling_horizon) / (double)(i - render.horizon);
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
		y *= env->textures[render.ceiling_texture].surface->h / 5.0;
		x *= env->textures[render.ceiling_texture].surface->w / 5.0;
		if (y >= env->textures[render.ceiling_texture].surface->h || y < 0)
			y = ft_abs((int)y % env->textures[render.ceiling_texture].surface->h);
		if (x >= env->textures[render.ceiling_texture].surface->w || x < 0)
			x = ft_abs((int)x % env->textures[render.ceiling_texture].surface->w);
		if (x >= 0 && x < env->textures[render.ceiling_texture].surface->w && y >= 0 && y < env->textures[render.ceiling_texture].surface->h)
		{
			coord = vline.x + env->w * i;
			if (!env->options.lighting)
				pixels[coord] = env->textures[render.ceiling_texture].str[(int)x + env->textures[render.ceiling_texture].surface->w * (int)y];
			else
				pixels[coord] = apply_light(env->textures[render.ceiling_texture].str[(int)x + env->textures[render.ceiling_texture].surface->w * (int)y], render.light);
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
	double	*zbuffer;
	int		start_coord;
	int		end_coord;
	int		coord;

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
	i = vline.start;
	while (i <= vline.end)
	{
		if (i == render.horizon || render.max_floor == render.horizon)
			return;
		alpha = (render.floor_horizon) / (double)((i - render.horizon));
		y = alpha * render.texel.y + (1.0 - alpha) * env->player.pos.y;
		x = alpha * render.texel.x + (1.0 - alpha) * env->player.pos.x;
		y *= env->textures[render.floor_texture].surface->h / 5.0;
		x *= env->textures[render.floor_texture].surface->w / 5.0;
		if (y >= env->textures[render.floor_texture].surface->h || y < 0)
			y = ft_abs((int)y % env->textures[render.floor_texture].surface->h);
		if (x >= env->textures[render.floor_texture].surface->w || x < 0)
			x = ft_abs((int)x % env->textures[render.floor_texture].surface->w);
		if (x >= 0 && x < env->textures[render.floor_texture].surface->w && y >= 0 && y < env->textures[render.floor_texture].surface->h)
		{
			coord = vline.x + env->w * i;
			if (!env->options.lighting)
				pixels[coord] = env->textures[render.floor_texture].str[(int)x + env->textures[render.floor_texture].surface->w * (int)y];
			else
				pixels[coord] = apply_light(env->textures[render.floor_texture].str[(int)x + env->textures[render.floor_texture].surface->w * (int)y], render.light);
			zbuffer[coord] = render.z;
		}
		//		}
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
	vline.start = render.ymin;
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
	vline.end = render.ymax;
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
