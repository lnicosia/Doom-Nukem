/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:36:03 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/30 14:03:30 by sipatry          ###   ########.fr       */
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
				break;
			}
			j++;
		}
		i++;
	}
}

void		vertices_selection(t_env *env)
{
	int	click_vertex;
	int	i;

	i = 0;
	click_vertex = -1;
	if (!env->inputs.left_click && env->editor.selected_vertex != -1)
	{
		if ((click_vertex = get_existing_not_dragged_vertex(env)) != -1 || !(is_new_dragged_vertex_valid(env, env->editor.selected_vertex)) || (click_vertex != -1 && (click_vertex != env->vertices[env->editor.selected_vertex].num)))
		{
			env->vertices[env->editor.selected_vertex].x = env->editor.start_pos.x;
			env->vertices[env->editor.selected_vertex].y = env->editor.start_pos.y;
		}
		else
		{
			env->vertices[env->editor.selected_vertex].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
			env->vertices[env->editor.selected_vertex].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
			check_sector_order(env);
			clear_portals(env);
			while (i < env->nb_sectors)
			{
				create_portals(env, env->sectors[i]);
				int j = 0;
				ft_printf("sector[%d]: ", i);
				while (j <= env->sectors[i].nb_vertices)
				{
					ft_printf("%d | ", env->sectors[i].neighbors[j]);
					j++;
				}
				i++;
				ft_printf("\n");
			}
			ft_printf("\n");
		}
		env->editor.selected_vertex = -1;
	}
}
