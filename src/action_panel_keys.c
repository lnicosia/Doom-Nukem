/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_panel_keys.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:31:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 17:32:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		action_panel_keys(t_env *env)
{
	if (env->editor.event_panel.event.target_index < MAX_REAL_TARGET_TYPES)
	{
		if (button_keys(&env->editor.event_panel.action_panel.go_to, env))
			return (-1);
		if (button_keys(&env->editor.event_panel.action_panel.add, env))
			return (-1);
		if (button_keys(&env->editor.event_panel.action_panel.value, env)
			|| button_keys(&env->editor.event_panel.action_panel.speed, env))
			return (-1);
		if (button_keys(&env->editor.event_panel.action_panel.delay, env))
			return (-1);
		if (button_keys(&env->editor.event_panel.action_panel.max_uses, env))
			return (-1);
	}
	else if (env->editor.event_panel.event.target_index == DIALOG)
	{
		if (button_keys(&env->editor.event_panel.action_panel.text, env))
			return (-1);
	}
	return (0);
}

int		action_panel_keyup(t_env *env)
{
	if (env->editor.event_panel.event.target_index < MAX_REAL_TARGET_TYPES)
	{
		if (button_keyup(&env->editor.event_panel.action_panel.go_to, env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.action_panel.add, env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.action_panel.value, env)
			|| button_keyup(&env->editor.event_panel.action_panel.speed, env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.action_panel.delay, env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.action_panel.max_uses, env))
			return (-1);
	}
	else if (env->editor.event_panel.event.target_index == DIALOG)
	{
		if (button_keyup(&env->editor.event_panel.action_panel.text, env))
			return (-1);
	}
	return (0);
}
