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
	if (panel.object_type)
	{
		if (env->selected_object == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select an object", ERROR, env));
	}
	else if (panel.enemy_type)
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
	if (panel.wall_type)
	{
		if (env->editor.selected_wall == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a wall", ERROR, env));
	}
	else if (panel.wall_sprite_type)
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
	return (check_event_creation3(env, panel));
}

int		check_event_creation(t_env *env)
{
	t_target_panel	panel;

	if (!env->editor.selecting_target && !env->editor.selecting_weapon
		&& !env->editor.selecting_condition_target
		&& !env->editor.selecting_condition_weapon)
		return (0);
	if (env->editor.selecting_condition_target
		|| env->editor.selecting_condition_weapon)
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
	return (check_event_creation2(env, panel));
}
