/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_event_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:18:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:18:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	set_action_type_buttons_state(t_env *env)
{
	if (env->editor.event_panel.event.mod_type == FIXED)
	{
		env->editor.event_panel.action_panel.go_to.state = DOWN;
		env->editor.event_panel.action_panel.add.state = UP;
	}
	else if (env->editor.event_panel.event.mod_type == INCR)
	{
		env->editor.event_panel.action_panel.go_to.state = UP;
		env->editor.event_panel.action_panel.add.state = DOWN;
	}
}

int		target_tab_func(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

void	set_modified_event(t_env *env, t_event *event)
{
	env->editor.event_panel.action_panel.delay_value = event->delay;
	if (event->type == INT)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.int_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.int_value = event->start_incr;
	}
	else if (event->type == DOUBLE)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.double_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.double_value =
			event->start_incr;
	}
	else if (event->type == UINT32)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.uint32_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.uint32_value =
			event->start_incr;
	}
}
