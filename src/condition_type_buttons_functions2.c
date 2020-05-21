/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 18:08:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

int		set_greater_or_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = GREATER_OR_EQUALS;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	env->editor.selecting_event = 0;
	return (0);
}

int		set_event_ended(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	env->editor.selecting_event = 1;
	if (update_confirmation_box(&env->confirmation_box, "Select an event",
		CONFIRM, env))
		return (-1);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_event_ended_start(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED_START;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	env->editor.selecting_event = 1;
	if (update_confirmation_box(&env->confirmation_box, "Select an event",
		CONFIRM, env))
		return (-1);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_function(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = FUNCTION;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	env->editor.selecting_event = 0;
	return (0);
}
