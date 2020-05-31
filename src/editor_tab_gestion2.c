/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tab_gestion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:46:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 15:10:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	sprite_tab_keyup(t_env *env)
{
	if ((env->selected_floor_sprite != -1 || env->selected_ceiling_sprite != -1
	|| env->selected_wall_sprite_sprite != -1)
		&& env->editor.sprite_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.next_sprite, env))
			return (-1);
		if (button_keyup(&env->editor.previous_sprite, env))
			return (-1);
		if (!env->editor.wall_sprite_selection_just_closed)
		{
			if (button_keyup(&env->editor.current_sprite_selection, env))
				return (-1);
		}
		else
			env->editor.wall_sprite_selection_just_closed = 0;
	}
	return (0);
}

int	events_tab_keyup(t_env *env)
{
	if (!env->editor.selecting_target && !env->editor.selecting_event
		&& !env->editor.selecting_condition_target
		&& button_keyup(&env->editor.new_event, env))
		return (-1);
	if (is_modify_event_button_visible(env)
		&& (button_keyup(&env->editor.modify_event, env)
		|| button_keyup(&env->editor.delete_event, env)))
		return (-1);
	if (are_event_selection_buttons_visible(env))
	{
		if (button_keyup(&env->editor.next_event, env))
			return (-1);
		if (button_keyup(&env->editor.previous_event, env))
			return (-1);
	}
	if (are_events_selection_buttons_visible(env))
	{
		if (button_keyup(&env->editor.next_events, env))
			return (-1);
		if (button_keyup(&env->editor.previous_events, env))
			return (-1);
	}
	return (0);
}

int	general_keyup3(t_env *env)
{
	if (button_keyup(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_fighting_music, env))
		return (-1);
	if (!env->editor.texture_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_texture_selection, env))
			return (-1);
	}
	else
		env->editor.texture_selection_just_closed = 0;
	if (!env->editor.object_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_object_selection, env))
			return (-1);
	}
	else
		env->editor.object_selection_just_closed = 0;
	return (0);
}

int	general_keyup2(t_env *env)
{
	if (button_keyup(&env->editor.events_tab, env))
		return (-1);
	if (env->selected_ceiling != -1 && ceiling_buttons_up(env))
		return (-1);
	if (env->editor.selected_wall != -1 && wall_buttons_up(env))
		return (-1);
	if (env->selected_floor != -1 && floor_buttons_up(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons_up(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons_up(env))
		return (-1);
	if (env->selected_floor_sprite != -1 && floor_sprite_buttons_up(env))
		return (-1);
	if (env->selected_ceiling_sprite != -1 && ceiling_sprite_buttons_up(env))
		return (-1);
	if (env->selected_wall_sprite_sprite != -1 && wall_sprite_buttons_up(env))
		return (-1);
	if (env->editor.selected_start_player != -1 && player_buttons_up(env))
		return (-1);
	return (general_keyup3(env));
}

int	general_keyup(t_env *env)
{
	if (button_keyup(&env->editor.save, env))
		return (-1);
	if (button_keyup(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keyup(&env->editor.general_tab, env))
		return (-1);
	if ((env->selected_object == -1
		|| env->objects[env->selected_object].sector != -1)
		&& button_keyup(&env->editor.sector_tab, env))
	if (button_keyup(&env->editor.change_mode, env))
		return (-1);
	if (button_keyup(&env->editor.options, env))
		return (-1);
	if (button_keyup(&env->editor.launch_game, env))
		return (-1);
	if (button_keyup(&env->editor.texture_background, env))
		return (-1);
	if (!env->editor.enemy_selection_just_closed)
	{
		if (button_keyup(&env->editor.current_enemy_selection, env))
			return (-1);
	}
	else
		env->editor.enemy_selection_just_closed = 0;
	return (general_keyup2(env));
}
