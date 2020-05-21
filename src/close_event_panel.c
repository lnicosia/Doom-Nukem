/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_event_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:09:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:09:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	close_condition_panel(t_env *env)
{
	if (env->editor.creating_launch_condition)
		env->editor.event_panel.launch_conditions_tab.state = DOWN;
	else
		env->editor.event_panel.exec_conditions_tab.state = DOWN;
	env->editor.creating_condition = 0;
	env->editor.creating_launch_condition = 0;
	env->editor.creating_exec_condition = 0;
	env->editor.selecting_condition_target = 0;
	env->editor.selecting_event = 0;
}

int		close_event_panel(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	if (env->editor.creating_condition)
	{
		close_condition_panel(env);
	}
	else
	{
		env->editor.creating_event = 0;
		env->editor.selecting_target = 0;
		env->editor.event_panel.selected_event = -1;
	}
	return (0);
}
