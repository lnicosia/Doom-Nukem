/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:03:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 17:17:57 by sipatry          ###   ########.fr       */
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
