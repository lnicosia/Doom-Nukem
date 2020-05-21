/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:30:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 10:54:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int		modify_condition2(t_env *env)
{
	env->editor.event_panel.ok.release_action = &save_condition;
	env->editor.event_panel.target_tab.state = DOWN;
	set_condition_panel_buttons_state(env,
	env->editor.condition_panel.condition.type);
	if (env->editor.condition_panel.condition.target_type == INT)
		env->editor.condition_panel.int_value =
		env->editor.condition_panel.condition.value;
	else if (env->editor.condition_panel.condition.target_type == DOUBLE)
		env->editor.condition_panel.double_value =
		env->editor.condition_panel.condition.value;
	else if (env->editor.condition_panel.condition.target_type == UINT32)
		env->editor.condition_panel.uint32_value =
		env->editor.condition_panel.condition.value;
	return (0);
}

int		modify_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_condition = 1;
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		env->editor.creating_launch_condition = 1;
		env->editor.condition_panel.condition =
		env->editor.event_panel.event.
		launch_conditions[env->editor.selected_launch_condition];
		env->editor.condition_panel.selected_condition =
		env->editor.selected_launch_condition;
	}
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		env->editor.creating_exec_condition = 1;
		env->editor.condition_panel.condition =
		env->editor.event_panel.event.
		exec_conditions[env->editor.selected_exec_condition];
		env->editor.condition_panel.selected_condition =
		env->editor.selected_exec_condition;
	}
	return (modify_condition2(env));
}
