/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_type_buttons_functions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:23:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 12:08:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

int		set_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = EQUALS;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.equals);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_different(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = DIFFERENT;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.different);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_less(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = LESS;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.less);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_greater(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = GREATER;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.greater);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}

int		set_less_or_equals(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.type = LESS_OR_EQUALS;
	set_condition_panel_buttons_state(env,
	&env->editor.condition_panel.less_or_equals);
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = DOWN;
	return (0);
}
