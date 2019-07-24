/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 17:58:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		add_vertex(t_env *env)
{
	t_list		*new;
	t_vertex	vertex;

	vertex.num = env->edit.nb_vertex;
	if (!(new = ft_lstnew(&vertex, sizeof(t_vertex))))
		return (ft_printf("Error when creating new vertex\n"));
	ft_lstpushback(&env->edit.vertices, new);

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

void	draw_grid_walls(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->edit.nb_vertex)
	{
		
	}
}

void	draw_map(t_env *env)
{
	draw_hgrid(env);
	draw_vgrid(env);
	draw_center(env);
	draw_grid_walls(env);
}
