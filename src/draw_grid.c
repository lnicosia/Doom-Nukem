/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 17:25:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		add_current_vertex(t_env *env)
{
	/*t_list		*tmp;
	t_vertex	vertex;
	int			i;

	ft_lstpushback(&env->edit.current_vertices, new);*/
	(void)env;
	return (0);
}

int		add_vertex(t_env *env)
{
	t_list		*new;
	t_vertex	vertex;

	vertex.num = env->edit.nb_vertex;
	vertex.x = round((env->sdl.mx - env->edit.center.x) / env->edit.scale);
	vertex.y = round((env->sdl.my - env->edit.center.y) / env->edit.scale);
	if (!(new = ft_lstnew(&vertex, sizeof(t_vertex))))
		return (ft_printf("Error when creating new vertex\n"));
	ft_lstpushback(&env->edit.vertices, new);
	env->edit.nb_vertex++;
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
	if (x >= 0 && x < env->w)
	{
		y = ft_clamp(env->edit.center.y - 10, 0, env->h);
		max = ft_clamp(env->edit.center.y, 0, env->h);
		while (y <= max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			y++;
		}
		y = ft_clamp(env->edit.center.y + 10, 0, env->h);
		while (y > max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			y--;
		}
	}
	y = env->edit.center.y;
	if (y >= 0 && y < env->h)
	{
		x = ft_clamp(env->edit.center.x - 10, 0, env->w);
		max = ft_clamp(env->edit.center.x, -1, env->w - 1);
		while (x <= max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			x++;
		}
		x = ft_clamp(env->edit.center.x + 10, -1, env->w - 1);
		while (x > max)
		{
			pixels[x + y * env->w] = 0xFFFF0000;
			x--;
		}
	}
}

void	draw_grid(t_env *env)
{
	draw_hgrid(env);
	draw_vgrid(env);
	draw_center(env);
}
