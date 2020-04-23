/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tabs_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:14:02 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 18:47:29 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	new_tabs_position2(t_env *env)
{
	if (env->editor.selected_wall != -1 || env->selected_enemy != -1
		|| env->selected_object != -1 || env->selected_floor != -1
		|| env->selected_ceiling != -1
		|| env->editor.selected_start_player != -1)
	{
		env->editor.events_tab.pos.x = 258;
		env->editor.general_tab.pos.x = 20;
		env->editor.sector_tab.pos.x = 139;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if(env->editor.in_game && env->editor.tab
	&& (env->selected_wall_sprite_sprite != -1
	|| env->selected_ceiling_sprite != -1
	|| env->selected_floor_sprite != -1))
	{
		env->editor.events_tab.pos.x = 258;
		env->editor.sprite_tab.pos.x = 20;
		env->editor.sector_tab.pos.x = 139;
		env->editor.general_tab.pos.x = -1000;
	}
}

void	new_tabs_position(t_env *env)
{
	if (env->editor.selected_sector == -1
	&& env->selected_floor == -1 && env->selected_ceiling == -1
	&& env->editor.selected_vertex == -1)
	{
		env->editor.events_tab.pos.x = 20;
		env->editor.general_tab.pos.x = -1000;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if (!env->editor.in_game && (env->editor.selected_sector != -1
	|| env->editor.selected_vertex != -1))
	{
		env->editor.events_tab.pos.x = 139;
		env->editor.general_tab.pos.x = 20;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	new_tabs_position2(env);
}
