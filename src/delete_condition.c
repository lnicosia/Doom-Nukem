/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:41:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:11:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int		save_launch_conditions(t_env *env)
{
	if (!(env->editor.launch_conditions_save = (t_condition*)ft_memalloc(
		env->editor.event_panel.event.nb_launch_conditions
		* sizeof(t_condition))))
		return (-1);
	env->editor.nb_launch_conditions_save = env->editor.event_panel.event.
	nb_launch_conditions;
	ft_memmove(env->editor.launch_conditions_save, env->editor.event_panel.
	event.launch_conditions, env->editor.nb_launch_conditions_save
	* sizeof(t_condition));
	return (0);
}

int		save_exec_conditions(t_env *env)
{
	if (!(env->editor.exec_conditions_save = (t_condition*)ft_memalloc(
		env->editor.event_panel.event.nb_exec_conditions
		* sizeof(t_condition))))
		return (-1);
	env->editor.nb_exec_conditions_save = env->editor.event_panel.event.
	nb_exec_conditions;
	ft_memmove(env->editor.exec_conditions_save, env->editor.event_panel.
	event.exec_conditions, env->editor.nb_exec_conditions_save
	* sizeof(t_condition));
	return (0);
}

int		delete_selected_launch_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (!env->editor.launch_conditions_save
		&& save_launch_conditions(env))
		return (-1);
	env->editor.event_panel.event.launch_conditions =
	(t_condition*)ft_delindex(env->editor.event_panel.event.launch_conditions,
	sizeof(t_condition) * env->editor.event_panel.event.nb_launch_conditions,
	sizeof(t_condition),
	sizeof(t_condition) * env->editor.selected_launch_condition);
	env->editor.event_panel.event.nb_launch_conditions--;
	if (env->editor.event_panel.event.nb_launch_conditions > 0
		&& !env->editor.event_panel.event.launch_conditions)
		return (-1);
	if (env->editor.selected_launch_condition ==
		env->editor.event_panel.event.nb_launch_conditions
		&& env->editor.selected_launch_condition > 0)
		env->editor.selected_launch_condition--;
	return (0);
}

int		delete_selected_exec_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (!env->editor.exec_conditions_save
		&& save_exec_conditions(env))
		return (-1);
	env->editor.event_panel.event.exec_conditions =
	(t_condition*)ft_delindex(env->editor.event_panel.event.exec_conditions,
	sizeof(t_condition) * env->editor.event_panel.event.nb_exec_conditions,
	sizeof(t_condition),
	sizeof(t_condition) * env->editor.selected_exec_condition);
	env->editor.event_panel.event.nb_exec_conditions--;
	if (env->editor.event_panel.event.nb_exec_conditions > 0
		&& !env->editor.event_panel.event.exec_conditions)
		return (-1);
	if (env->editor.selected_exec_condition ==
		env->editor.event_panel.event.nb_exec_conditions
		&& env->editor.selected_exec_condition > 0)
		env->editor.selected_exec_condition--;
	return (0);
}

int		delete_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (update_confirmation_box(&env->confirmation_box,
		"Delete this condition?", YESNO, env))
		return (-1);
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
		env->confirmation_box.yes_action = &delete_selected_launch_condition;
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
		env->confirmation_box.yes_action = &delete_selected_exec_condition;
	env->confirmation_box.yes_target = env;
	return (0);
}
