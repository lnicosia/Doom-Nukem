/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_general_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 12:39:18 by marvin            #+#    #+#             */
/*   Updated: 2020/05/16 13:01:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	transition_condition_check(t_env *env)
{
	if ((env->editor.selected_sector != -1 && !env->editor.in_game)
	|| env->selected_object != -1 || env->selected_object != -1
	|| env->selected_ceiling != -1 || env->selected_floor != -1)
		return (-1);
	return (0);
}

int	print_general_tab2(t_env *env)
{
	if (transition_condition_check(env))
		return (0);
	else if (env->editor.selected_start_player != -1)
	{
		if (print_player_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_wall != -1
		&& env->editor.selected_sector != -1)
	{
		if (print_wall_general_tab(env))
			return (-1);
	}
	else if (env->selected_enemy != -1)
	{
		if (print_enemy_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_vertex != -1)
	{
		if (print_vertices_general_tab(env))
			return (-1);
	}
	return (0);
}

int	print_general_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
	{
		if (print_object_general_tab(env))
			return (-1);
	}
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
	{
		if (print_sector_general_tab(env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		if (print_ceiling_general_tab(env))
			return (-1);
	}
	else if (env->selected_floor != -1)
	{
		if (print_floor_general_tab(env))
			return (-1);
	}
	return (print_general_tab2(env));
}
