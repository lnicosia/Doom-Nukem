/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_panel_keys.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:28:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:17:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		condition_condition_keys(t_env *env)
{
	if (button_keys(&env->editor.condition_panel.equals, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.different, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.less, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.greater, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.less_or_equals, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.greater_or_equals, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.event_ended, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.event_ended_start, env))
		return (-1);
	if (button_keys(&env->editor.condition_panel.function, env))
		return (-1);
	return (0);
}

int		condition_condition_keyup(t_env *env)
{
	if (button_keyup(&env->editor.condition_panel.equals, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.different, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.less, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.greater, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.less_or_equals, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.greater_or_equals, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.event_ended, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.event_ended_start, env))
		return (-1);
	if (button_keyup(&env->editor.condition_panel.function, env))
		return (-1);
	return (0);
}

int		condition_panel_keys(t_env *env)
{
	if (env->editor.event_panel.target_tab.state == DOWN)
		return (condition_condition_keys(env));
	else if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (target_panel_keys(env, &env->editor.condition_panel.target_panel))
			return (-1);
	}
	if (env->editor.selecting_event)
	{
		if (button_keys(&env->editor.select_event, env))
			return (-1);
	}
	return (0);
}

int		condition_panel_keyup(t_env *env)
{
	if (env->editor.event_panel.target_tab.state == DOWN)
		return (condition_condition_keyup(env));
	else if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (target_panel_keyup(env, &env->editor.condition_panel.target_panel))
			return (-1);
	}
	if (env->editor.selecting_event)
	{
		if (button_keyup(&env->editor.select_event, env))
			return (-1);
	}
	return (0);
}
