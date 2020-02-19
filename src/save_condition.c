/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:25:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 10:51:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	save_condition_value(t_condition *condition, t_condition_panel *panel)
{
	if (condition->target_type == INT)
		condition->value = panel->int_value;
	else if (condition->target_type == DOUBLE)
		condition->value = panel->double_value;
	else if (condition->target_type == UINT32)
		condition->value = panel->uint32_value;
}

int		save_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	save_condition_value(&env->editor.condition_panel.condition,
	&env->editor.condition_panel);
	if (env->editor.event_panel.selected_event != -1)
		env->editor.event_panel.ok.release_action = &save_event;
	else
		env->editor.event_panel.ok.release_action = &create_event;
	if (env->editor.creating_launch_condition)
		env->editor.event_panel.event.
		launch_conditions[env->editor.condition_panel.selected_condition] =
		env->editor.condition_panel.condition;
	else if (env->editor.creating_exec_condition)
		env->editor.event_panel.event.
		exec_conditions[env->editor.condition_panel.selected_condition] =
		env->editor.condition_panel.condition;
	close_event_panel(env);
	return (0);
}

int		create_condition(void *param)
{
	t_env	*env;
	t_event	*event;

	env = (t_env*)param;
	event = &env->editor.event_panel.event;
	save_condition_value(&env->editor.condition_panel.condition,
	&env->editor.condition_panel);
	if (env->editor.creating_launch_condition)
	{
		if (!(event->launch_conditions = (t_condition*)ft_realloc(
			event->launch_conditions,
			sizeof(t_condition) * event->nb_launch_conditions,
			sizeof(t_condition) * (event->nb_launch_conditions + 1))))
			return (-1);
		event->launch_conditions[event->nb_launch_conditions] =
		env->editor.condition_panel.condition;
		event->nb_launch_conditions++;
	}
	else if (env->editor.creating_exec_condition)
	{
		if (!(event->exec_conditions = (t_condition*)ft_realloc(
			event->exec_conditions,
			sizeof(t_condition) * event->nb_exec_conditions,
			sizeof(t_condition) * (event->nb_exec_conditions + 1))))
			return (-1);
		event->exec_conditions[event->nb_exec_conditions] =
		env->editor.condition_panel.condition;
		event->nb_exec_conditions++;
	}
	if (env->editor.event_panel.selected_event != -1)
		env->editor.event_panel.ok.release_action = &save_event;
	else
		env->editor.event_panel.ok.release_action = &create_event;
	close_event_panel(env);
	return (0);
}
