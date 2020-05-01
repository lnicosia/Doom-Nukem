/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:57:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "enemies.h"

int		editor_keys5(t_env *env)
{
	if (env->editor.events_tab.state == DOWN)
	{
		if (!env->editor.selecting_target && !env->editor.selecting_event
			&& !env->editor.selecting_condition_target
			&& button_keys(&env->editor.new_event, env))
			return (-1);
		if (is_modify_event_button_visible(env)
			&& (button_keys(&env->editor.modify_event, env)
			|| button_keys(&env->editor.delete_event, env)))
			return (-1);
		if (are_event_selection_buttons_visible(env))
		{
			if (button_keys(&env->editor.next_event, env))
				return (-1);
			if (button_keys(&env->editor.previous_event, env))
				return (-1);
		}
		if (are_events_selection_buttons_visible(env)
			&& (button_keys(&env->editor.next_events, env)
			|| button_keys(&env->editor.previous_events, env)))
			return (-1);
	}
	return (editor_keys6(env));
}

int		editor_keys4(t_env *env)
{
	if (button_keys(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keys(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (env->editor.selected_sector != -1 && sector_buttons(env))
		return (-1);
	if (env->editor.selected_start_player != -1 && player_buttons(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons(env))
		return (-1);
	if (button_keys(&env->editor.events_tab, env))
		return (-1);
	return (editor_keys5(env));
}

int		editor_keys3(t_env *env)
{
	if (button_keys(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keys(&env->editor.sector_tab, env))
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
	if (button_keys(&env->editor.enemy_background, env))
		return (-1);
	if (button_keys(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_fighting_music, env))
		return (-1);
	return (editor_keys4(env));
}

int		editor_keys2(t_env *env)
{
	int		ret;

	if (env->inputs.left && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x -= 3;
	if (env->inputs.right && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x += 3;
	if (env->inputs.forward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y -= 3;
	if (env->inputs.backward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y += 3;
	if (env->inputs.s && env->inputs.ctrl)
	{
		if ((ret = save_map_keys(env)) != 1)
			return (ret);
	}
	if (button_keys(&env->editor.add_enemy, env))
		return (-1);
	if (button_keys(&env->editor.add_object, env))
		return (-1);
	if (button_keys(&env->editor.save, env))
		return (-1);
	if (button_keys(&env->editor.general_tab, env))
		return (-1);
	return (editor_keys3(env));
}

int		editor_keys(t_env *env)
{
	if (env->inputs.backspace && !env->confirmation_box.state)
	{
		if (del_last_vertex(env))
			return (-1);
		env->inputs.backspace = 0;
	}
	player_selection(env);
	starting_player_selection(env);
	enemy_drag(env);
	objects_selection(env);
	vertices_selection(env);
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
	if (env->inputs.right_click)
	{
		env->editor.center.x += env->sdl.mouse_x;
		env->editor.center.y += env->sdl.mouse_y;
	}
	return (editor_keys2(env));
}
