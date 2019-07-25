/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:34:39 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 15:01:10 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		add_vertex(t_env *env)
{
	int new_nb;

	new_nb = env->edit.nb_vertex + 1;
	if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex) * new_nb + 1)))
		return (ft_printf("malloc of the vertices went wrong\n"));
	if (env->vertices)
		return (0);
	return (0);
}

void	draw_map(t_env *env)
{
	int	i;
//	t_point	v1;
//	t_point	v2;

	i = 0;
	env->edit.menu = 0;
/*	while(i < env->edit.nb_vertex - 1)
	{
		v1.x = env->vertex[i].x;
		v1.y = env->vertex[i].y;
		if ()
			v2.x = ;
		else
		draw_line(env->vertices[i], env->vertices[i + 1], env, 0xFFFFFF00);
		i++;
	}*/
	ft_printf("draw: %d menu: %d\n", env->drawing, env->edit.menu);
}
