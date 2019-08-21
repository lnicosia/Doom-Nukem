/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:36:03 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/21 13:38:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	check_sector_order(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->editor.selected_vertex == env->sectors[i].vertices[j])
			{
				env->editor.reverted = get_clockwise_order_sector(env, i) ? 0 : 1;
				revert_sector(&env->sectors[i], env);
			}
			j++;
		}
		i++;
	}
}

void		vertices_selection(t_env *env)
{
	if (!env->inputs.left_click && env->editor.selected_vertex != -1)
	{
		env->vertices[env->editor.selected_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
		env->vertices[env->editor.selected_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
		check_sector_order(env);
		env->editor.selected_vertex = -1;
	}
}
