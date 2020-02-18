/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_panel_keys.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:31:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:46:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		conditions_panel_keys(t_env *env)
{
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_launch_conditions > 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_exec_conditions > 0))
	{
		if (button_keys(&env->editor.event_panel.modify_condition,
			env))
			return (-1);
		if (button_keys(&env->editor.event_panel.delete_condition, env))
			return (-1);
	}
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_launch_conditions > 1)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_exec_conditions > 1))
	{
		if (button_keys(&env->editor.event_panel.previous_condition,
			env))
			return (-1);
		if (button_keys(&env->editor.event_panel.next_condition, env))
			return (-1);
	}
	if (button_keys(&env->editor.event_panel.new_condition, env))
		return (-1);
	return (0);
}

int		conditions_panel_keyup(t_env *env)
{
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_launch_conditions > 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_exec_conditions > 0))
	{
		if (button_keyup(&env->editor.event_panel.modify_condition,
			env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.delete_condition, env))
			return (-1);
	}
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_launch_conditions > 1)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& env->editor.event_panel.event.nb_exec_conditions > 1))
	{
		if (button_keyup(&env->editor.event_panel.previous_condition,
			env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.next_condition, env))
			return (-1);
	}
	if (button_keyup(&env->editor.event_panel.new_condition, env))
		return (-1);
	return (0);
}
