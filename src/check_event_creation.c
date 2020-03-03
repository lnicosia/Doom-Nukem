/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:36:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 10:40:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		new_condition_target(t_env *env)
{
	env->editor.creating_event = 1;
	env->editor.creating_condition = 1;
	env->editor.selecting_condition_target = 0;
	env->editor.condition_panel.target_tab.anim_state = REST;
	env->editor.condition_panel.target_tab.state = UP;
	set_new_condition_target(env);
	if (env->editor.condition_panel.condition.target)
		set_condition_buttons_state(env);
	return (0);
}

int		new_event_target(t_env *env)
{
	env->editor.creating_event = 1;
	env->editor.selecting_target = 0;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	set_new_event_target(env);
	env->editor.event_panel.action_panel.double_value = 0;
	env->editor.event_panel.action_panel.int_value = 0;
	env->editor.event_panel.action_panel.uint32_value = 0;
	if (env->editor.event_panel.event.target_index != -1)
		set_buttons_state(env);
	return (0);
}

int		check_event_creation4(t_env *env)
{
	if (env->editor.in_game)
	{
		env->editor.tab = 1;
		SDL_SetRelativeMouseMode(0);
	}
	if (env->editor.selecting_target || env->editor.selecting_weapon)
		return (new_event_target(env));
	else if (env->editor.selecting_condition_target
		|| env->editor.selecting_condition_weapon)
		return (new_condition_target(env));
	return (0);
}

int		check_event_creation3(t_env *env, t_target_panel panel)
{
	if (panel.enemy_type)
	{
		if (env->selected_enemy == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select an enemy", ERROR, env));
	}
	else if (panel.vertex_type)
	{
		if (env->editor.selected_vertex == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a vertex", ERROR, env));
	}
	else if (panel.sector_other_type)
	{
		if (env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a sector", ERROR, env));
	}
	return (check_event_creation4(env));
}

int		check_event_creation2(t_env *env, t_target_panel panel)
{
	if (panel.wall_sprite_type)
	{
		if (env->selected_wall_sprite_wall == -1
			&& env->selected_floor_sprite == -1
			&& env->selected_ceiling_sprite == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a wall sprite", ERROR, env));
	}
	else if (panel.weapon_type)
	{
		if (env->editor.selected_weapon == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a weapon", ERROR, env));
	}
	else if (panel.object_type)
	{
		if (env->selected_object == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select an object", ERROR, env));
	}
	return (check_event_creation3(env, panel));
}

int		check_event_creation(t_env *env)
{
	t_target_panel	panel;

	if (!env->editor.selecting_target && !env->editor.selecting_weapon
		&& !env->editor.selecting_condition_target
		&& !env->editor.selecting_condition_weapon)
		return (0);
	if (env->editor.selecting_condition_target)
		panel = env->editor.condition_panel.target_panel;
	else
		panel = env->editor.event_panel.target_panel;
	if (panel.floor_type)
	{
		if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a floor", ERROR, env));
	}
	else if (panel.ceiling_type)
	{
		if (env->selected_ceiling == -1 && env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a ceiling", ERROR, env));
	}
	else if (panel.wall_type)
	{
		if (env->editor.selected_wall == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a wall", ERROR, env));
	}
	return (check_event_creation2(env, panel));
}
