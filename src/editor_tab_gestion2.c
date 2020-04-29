/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tab_gestion2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:46:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:57:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		sprite_tab_keyup(t_env *env)
{
	if ((env->selected_floor_sprite != -1 || env->selected_ceiling_sprite != -1
	|| env->selected_wall_sprite_sprite != -1)
		&& env->editor.sprite_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.next_sprite, env))
			return (-1);
		if (button_keyup(&env->editor.previous_sprite, env))
			return (-1);
		if (button_keyup(&env->editor.current_sprite_selection, env))
			return (-1);
	}
	return (0);
}

int		events_tab_keyup(t_env *env)
{
	if (!env->editor.selecting_target && !env->editor.selecting_event
		&& !env->editor.selecting_condition_target
		&& button_keyup(&env->editor.new_event, env))
		return (-1);
	if (is_modify_event_button_visible(env)
		&& (button_keyup(&env->editor.modify_event, env))
		|| button_keyup(&env->editor.delete_event, env))
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
