/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 13:25:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

void	set_condition_panel_buttons_state(t_env *env, t_button *button)
{
	env->editor.condition_panel.equals.state = UP;
	env->editor.condition_panel.equals.anim_state = REST;
	env->editor.condition_panel.different.state = UP;
	env->editor.condition_panel.different.anim_state = REST;
	env->editor.condition_panel.less.state = UP;
	env->editor.condition_panel.less.anim_state = REST;
	env->editor.condition_panel.greater.state = UP;
	env->editor.condition_panel.greater.anim_state = REST;
	env->editor.condition_panel.less_or_equals.state = UP;
	env->editor.condition_panel.less_or_equals.anim_state = REST;
	env->editor.condition_panel.greater_or_equals.state = UP;
	env->editor.condition_panel.greater_or_equals.anim_state = REST;
	env->editor.condition_panel.event_ended.state = UP;
	env->editor.condition_panel.event_ended.anim_state = REST;
	env->editor.condition_panel.event_ended_start.state = UP;
	env->editor.condition_panel.event_ended_start.anim_state = REST;
	env->editor.condition_panel.function.state = UP;
	env->editor.condition_panel.function.anim_state = REST;
	button->state = DOWN;
}

int		set_greater_or_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = GREATER_OR_EQUALS;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.greater_or_equals);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_event_ended(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.event_ended);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	env->editor.selecting_event = 1;
	return (0);
}

int		set_event_ended_start(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED_START;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.event_ended_start);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	env->editor.selecting_event = 1;
	return (0);
}

int		set_function(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = FUNCTION;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.function);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}
