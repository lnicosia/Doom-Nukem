/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_keyup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:51:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:51:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		event_panel_keyup2(t_env *env)
{
	if (env->editor.event_panel.target_tab.state == DOWN)
	{
		if (target_panel_keyup(env, &env->editor.event_panel.target_panel))
			return (-1);
	}
	if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (action_panel_keyup(env))
			return (-1);
	}
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN
		|| env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (conditions_panel_keyup(env))
			return (-1);
	}
	return (0);
}

int		event_panel_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.target_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.ok, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.cancel, env))
		return (-1);
	if (env->editor.creating_condition)
		return (condition_panel_keyup(env));
	if (button_keyup(&env->editor.event_panel.launch_conditions_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.exec_conditions_tab, env))
		return (-1);
	return (event_panel_keyup2(env));
}
