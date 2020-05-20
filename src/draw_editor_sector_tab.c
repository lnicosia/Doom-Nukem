/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_editor_sector_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:02:18 by marvin            #+#    #+#             */
/*   Updated: 2020/05/20 15:55:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	check_sector_tab_transition_condition(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1
	|| env->selected_enemy != -1 || env->editor.selected_start_player != -1
	|| env->selected_ceiling != -1)
		return (-1);
	return (0);
}

int	print_sector_tab2(t_env *env)
{
	if (check_sector_tab_transition_condition(env))
		return (0);
	else if (env->selected_floor != -1)
	{
		if (print_floor_sector_tab(env))
			return (-1);
	}
	else if (env->editor.selected_wall != -1
	&& env->editor.selected_sector != -1)
	{
		if (print_wall_sector_tab(env))
			return (-1);
	}
	else if (env->selected_wall_sprite_sprite != -1)
	{
		if (print_wall_sprite_sector_tab(env))
			return (-1);
	}
	return (0);
}

int	print_sector_tab(t_env *env)
{
	if (env->selected_object != -1 || env->selected_object != -1)
	{
		if (print_object_sector_tab(env))
			return (-1);
	}
	else if (env->selected_enemy != -1)
	{
		if (print_enemy_sector_tab(env))
			return (-1);
	}
	else if (env->editor.selected_start_player != -1)
	{
		if (print_player_sector_tab(env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		if (print_ceiling_sector_tab(env))
			return (-1);
	}
	return (print_sector_tab2(env));
}
