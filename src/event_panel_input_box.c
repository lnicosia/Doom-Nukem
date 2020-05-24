/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_input_box.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:22:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/12 15:36:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int	set_event_value(void *param)
{
	t_env	*env;
	void	*target;

	env = (t_env*)param;
	target = NULL;
	if (env->editor.event_panel.event.type == INT)
		target = &env->editor.event_panel.action_panel.int_value;
	else if (env->editor.event_panel.event.type == DOUBLE)
		target = &env->editor.event_panel.action_panel.double_value;
	else if (env->editor.event_panel.event.type == UINT32)
		target = &env->editor.event_panel.action_panel.uint32_value;
	if (new_event_panel_value_box(&env->input_box,
		env->editor.event_panel.event.type, target, env))
		return (-1);
	return (0);
}

int	set_event_speed(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_value_box(&env->input_box,
		DOUBLE, &env->editor.event_panel.event.speed, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.speed.pos;
	env->input_box.size = env->editor.event_panel.action_panel.speed.size_up;
	return (0);
}

int	set_event_delay(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_box(&env->input_box,
		INT, &env->editor.event_panel.action_panel.delay_value, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.delay.pos;
	env->input_box.size = env->editor.event_panel.action_panel.delay.size_up;
	return (0);
}

int	set_event_max_uses(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (new_event_panel_box(&env->input_box,
		INT, &env->editor.event_panel.event.max_uses, env))
		return (-1);
	env->input_box.pos = env->editor.event_panel.action_panel.max_uses.pos;
	env->input_box.size = env->editor.event_panel.action_panel.max_uses.size_up;
	return (0);
}
