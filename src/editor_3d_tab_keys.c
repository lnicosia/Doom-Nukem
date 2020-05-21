/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_tab_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:14:45 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/14 16:41:03 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int		general_tab_keys(t_env *env)
{
	if (env->editor.events_tab.state != DOWN)
		return (0);
	if (!env->editor.selecting_target && !env->editor.selecting_event
		&& !env->editor.selecting_condition_target
		&& button_keys(&env->editor.new_event, env))
		return (-1);
	if (is_modify_event_button_visible(env))
	{
		if (button_keys(&env->editor.modify_event, env))
			return (-1);
		if (button_keys(&env->editor.delete_event, env))
			return (-1);
	}
	if (are_event_selection_buttons_visible(env))
	{
		if (button_keys(&env->editor.next_event, env)
		|| button_keys(&env->editor.previous_event, env))
			return (-1);
	}
	if (are_events_selection_buttons_visible(env)
		&& (button_keys(&env->editor.next_events, env)
		|| button_keys(&env->editor.previous_events, env)))
		return (-1);
	return (0);
}

int		general_keys(t_env *env)
{
	if (button_keys(&env->editor.save, env))
		return (-1);
	if (button_keys(&env->editor.sprite_tab, env))
		return (-1);
	else if (button_keys(&env->editor.general_tab, env))
		return (-1);
	else if (button_keys(&env->editor.sector_tab, env))
		return (-1);
	if (button_keys(&env->editor.change_mode, env))
		return (-1);
	if (button_keys(&env->editor.options, env))
		return (-1);
	if (button_keys(&env->editor.launch_game, env))
		return (-1);
	if (button_keys(&env->editor.current_texture_selection, env))
		return (-1);
	if (button_keys(&env->editor.current_enemy_selection, env))
		return (-1);
	if (button_keys(&env->editor.current_object_selection, env))
		return (-1);
	if (button_keys(&env->editor.texture_background, env))
		return (-1);
	if (button_keys(&env->editor.events_tab, env))
		return (-1);
	if (button_keys(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keys(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_fighting_music, env))
		return (-1);
	return (0);
}

int		selection_button_keys2(t_env *env)
{
	if (env->selected_floor_sprite != -1 && floor_sprite_buttons(env))
		return (-1);
	if (env->selected_ceiling_sprite != -1 && ceiling_sprite_buttons(env))
		return (-1);
	if (env->selected_wall_sprite_sprite != -1 && wall_sprite_buttons(env))
		return (-1);
	if (env->editor.selected_start_player != -1 && player_buttons(env))
		return (-1);
	return (0);
}

int		selection_button_keys(t_env *env)
{
	if (env->selected_ceiling != -1 && ceiling_buttons(env))
		return (-1);
	if (env->selected_floor != -1 && floor_buttons(env))
		return (-1);
	if (env->editor.selected_wall != -1 && wall_buttons(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons(env))
		return (-1);
	if ((env->selected_floor_sprite != -1 || env->selected_ceiling_sprite != -1
		|| env->selected_wall_sprite_sprite != -1)
		&& env->editor.sprite_tab.state == DOWN)
	{
		if (button_keys(&env->editor.next_sprite, env)
		|| button_keys(&env->editor.previous_sprite, env)
		|| button_keys(&env->editor.current_sprite_selection, env))
			return (-1);
	}
	return (selection_button_keys2(env));
}

int		editor_3d_tab_keys(t_env *env)
{
	if (general_keys(env))
		return (-1);
	if (general_tab_keys(env))
		return (-1);
	if (selection_button_keys(env))
		return (-1);
	if (selection_tab_button_keys(env))
		return (-1);
	if (env->editor.creating_event && !env->confirmation_box.state)
	{
		if (event_panel_keys(env))
			return (-1);
	}
	return (0);
}
