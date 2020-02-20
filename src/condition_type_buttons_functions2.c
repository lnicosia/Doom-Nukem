/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 13:55:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

void	set_condition_panel_buttons_state(t_env *env, int type)
{
	env->editor.condition_panel.equals.state = UP;
	env->editor.condition_panel.different.state = UP;
	env->editor.condition_panel.less.state = UP;
	env->editor.condition_panel.greater.state = UP;
	env->editor.condition_panel.less_or_equals.state = UP;
	env->editor.condition_panel.greater_or_equals.state = UP;
	env->editor.condition_panel.event_ended.state = UP;
	env->editor.condition_panel.event_ended_start.state = UP;
	env->editor.condition_panel.function.state = UP;
	if (type == EQUALS)
		env->editor.condition_panel.equals.state = DOWN;
	if (type == DIFFERENT)
		env->editor.condition_panel.different.state = DOWN;
	if (type == LESS)
		env->editor.condition_panel.less.state = DOWN;
	if (type == GREATER)
		env->editor.condition_panel.greater.state = DOWN;
	if (type == LESS_OR_EQUALS)
		env->editor.condition_panel.less_or_equals.state = DOWN;
	if (type == GREATER_OR_EQUALS)
		env->editor.condition_panel.greater_or_equals.state = DOWN;
	if (type == EVENT_ENDED)
		env->editor.condition_panel.event_ended.state = DOWN;
	if (type == EVENT_ENDED_START)
		env->editor.condition_panel.event_ended_start.state = DOWN;
	if (type == FUNCTION)
		env->editor.condition_panel.function.state = DOWN;
}

int		set_greater_or_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = GREATER_OR_EQUALS;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
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
	return (0);
}
