/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 13:50:33 by lnicosia         ###   ########.fr       */
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
	return (0);
}

int		set_event_ended(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.event_ended);
	return (0);
}

int		set_event_ended_start(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EVENT_ENDED_START;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.event_ended_start);
	return (0);
}

int		set_function(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = FUNCTION;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.function);
	return (0);
}
