/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tabs_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:14:02 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/10 16:06:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Places editor tabs correctly
*/

int		general_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return(0);
}

int		sector_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		sprite_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.events_tab.state = UP;
	env->editor.events_tab.anim_state = REST;
	return (0);
}

int		events_tab(void *target)
{
	t_env *env;

	env = (t_env *)target;
	env->editor.general_tab.state = UP;
	env->editor.general_tab.anim_state = REST;
	env->editor.sector_tab.state = UP;
	env->editor.sector_tab.anim_state = REST;
	env->editor.sprite_tab.state = UP;
	env->editor.sprite_tab.anim_state = REST;
	return (0);
}

int		check_event_creation(t_env *env)
{
	t_target_panel	panel;

	if (env->editor.selecting_target == 0)
		return (0);
	panel = env->editor.event_panel.target_panel;
	if (panel.floor_type)
	{
		if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a floor", ERROR, env));
	}
	env->editor.creating_event = 1;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = DOWN;
	set_new_event_target(env);
	return (0);
}

void	new_tabs_position(t_env *env)
{
	if (env->editor.selected_sector == -1
		&& env->selected_floor == -1 && env->selected_ceiling == -1)
	{
		env->editor.events_tab.pos.x = 20;
		env->editor.general_tab.pos.x = -1000;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if (!env->editor.in_game && env->editor.selected_sector != -1)
	{
		env->editor.events_tab.pos.x = 139;
		env->editor.general_tab.pos.x = 20;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if (env->editor.selected_wall != -1 || env->selected_enemy != -1
		|| env->selected_object != -1 || env->selected_floor != -1
		|| env->selected_ceiling != -1 || env->editor.selected_player != -1)
	{
		env->editor.events_tab.pos.x = 258;
		env->editor.general_tab.pos.x = 20;
		env->editor.sector_tab.pos.x = 139;
		env->editor.sprite_tab.pos.x = -1000;
	}
}
