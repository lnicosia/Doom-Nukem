/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_conditions_panel_keys.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:31:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/14 20:13:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		launch_conditions_panel_keys(t_env *env)
{
	if (env->editor.event_panel.event.nb_launch_conditions > 0)
	{
		if (button_keys(&env->editor.event_panel.modify_launch_condition,
			env))
			return (-1);
		if (button_keys(&env->editor.event_panel.delete_launch_condition, env))
			return (-1);
	}
	if (env->editor.event_panel.event.nb_launch_conditions > 1)
	{
		if (button_keys(&env->editor.event_panel.previous_launch_condition,
			env))
			return (-1);
		if (button_keys(&env->editor.event_panel.next_launch_condition, env))
			return (-1);
	}
	if (button_keys(&env->editor.event_panel.new_launch_condition, env))
		return (-1);
	return (0);
}

int		launch_conditions_panel_keyup(t_env *env)
{
	if (env->editor.event_panel.event.nb_launch_conditions > 0)
	{
		if (button_keyup(&env->editor.event_panel.modify_launch_condition,
			env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.delete_launch_condition, env))
			return (-1);
	}
	if (env->editor.event_panel.event.nb_launch_conditions > 1)
	{
		if (button_keyup(&env->editor.event_panel.previous_launch_condition,
			env))
			return (-1);
		if (button_keyup(&env->editor.event_panel.next_launch_condition, env))
			return (-1);
	}
	if (button_keyup(&env->editor.event_panel.new_launch_condition, env))
		return (-1);
	return (0);
}
