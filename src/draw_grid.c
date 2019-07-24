/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 16:24:05 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	hline(t_env *env, int y)
{
	int x;

	x = 0;
	while (x < env->w)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0xFF888888;
		x++;
	}
}

void	vline(t_env *env, int x)
{
	int y;

	y = 0;
	while (y < env->h)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0xFF888888;
		y++;
	}
}

void	draw_hgrid(t_env *env)
{
	int	i;

	i = env->edit.center.y;
	while (i < env->h)
	{
		hline(env, i);
		i += env->edit.scale;
	}
	i = env->edit.center.y - env->edit.scale;
	while (i >= 0)
	{
		hline(env, i);
		i -= env->edit.scale;
	}
}

void	draw_vgrid(t_env *env)
{
	int	i;

	i = env->edit.center.x;
	while (i < env->w)
	{
		vline(env, i);
		i += env->edit.scale;
	}
	i = env->edit.center.x - env->edit.scale;
	while (i >= 0)
	{
		vline(env, i);
		i -= env->edit.scale;
	}
}

int		add_vertex(t_env *env)
{
	int new_nb;

	new_nb = 20;
	if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex) * new_nb)))
		return (ft_printf("malloc of the vertices went wrong\n"));
	return (0);
}

void	draw_center(t_env *env)
{
	int		x;
	int		y;
	int		max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	x = env->edit.center.x;
	y = env->edit.center.y - 10;
	max = env->edit.center.y;
	while (y <= max)
	{
		pixels[x + y * env->w] = 0xFFFF0000;
		y++;
	}
	y = env->edit.center.y + 10;
	while (y > max)
	{
		pixels[x + y * env->w] = 0xFFFF0000;
		y--;
	}
	y = env->edit.center.y;
	x = env->edit.center.x - 10;
	max = env->edit.center.x;
	while (x <= max)
	{
		pixels[x + y * env->w] = 0xFFFF0000;
		x++;
	}
	x = env->edit.center.x + 10;
	while (x > max)
	{
		pixels[x + y * env->w] = 0xFFFF0000;
		x--;
	}
}

void	draw_map(t_env *env)
{
	draw_hgrid(env);
	draw_vgrid(env);
	draw_center(env);
}
